/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KTHREAD_H
#define _LINUX_KTHREAD_H

#include <linux/err.h>
#include <linux/sched.h>

__printf(4, 5)
struct task_struct *kthread_create_on_node(int (*threadfn)(void *data),
					   void *data,
					   int node,
					   const char namefmt[], ...);


#define kthread_create(threadfn, data, namefmt, arg...) \
	kthread_create_on_node(threadfn, data, NUMA_NO_NODE, namefmt, ##arg)


struct task_struct *kthread_create_on_cpu(int (*threadfn)(void *data),
					  void *data,
					  unsigned int cpu,
					  const char *namefmt);


#define kthread_run(threadfn, data, namefmt, ...)			   \
({									   \
	struct task_struct *__k						   \
		= kthread_create(threadfn, data, namefmt, ## __VA_ARGS__); \
	if (!IS_ERR(__k))						   \
		wake_up_process(__k);					   \
	__k;								   \
})

void free_kthread_struct(struct task_struct *k);
void kthread_bind(struct task_struct *k, unsigned int cpu);
void kthread_bind_mask(struct task_struct *k, const struct cpumask *mask);
int kthread_stop(struct task_struct *k);
bool kthread_should_stop(void);
bool kthread_should_park(void);
bool kthread_freezable_should_stop(bool *was_frozen);
void *kthread_data(struct task_struct *k);
void *kthread_probe_data(struct task_struct *k);
int kthread_park(struct task_struct *k);
void kthread_unpark(struct task_struct *k);
void kthread_parkme(void);

int kthreadd(void *unused);
extern struct task_struct *kthreadd_task;
extern int tsk_fork_get_node(struct task_struct *tsk);


struct kthread_work;
typedef void (*kthread_work_func_t)(struct kthread_work *work);
void kthread_delayed_work_timer_fn(struct timer_list *t);

enum {
	KTW_FREEZABLE		= 1 << 0,	
};

struct kthread_worker {
	unsigned int		flags;
	spinlock_t		lock;
	struct list_head	work_list;
	struct list_head	delayed_work_list;
	struct task_struct	*task;
	struct kthread_work	*current_work;
};

struct kthread_work {
	struct list_head	node;
	kthread_work_func_t	func;
	struct kthread_worker	*worker;
	
	int			canceling;
};

struct kthread_delayed_work {
	struct kthread_work work;
	struct timer_list timer;
};

#define KTHREAD_WORKER_INIT(worker)	{				\
	.lock = __SPIN_LOCK_UNLOCKED((worker).lock),			\
	.work_list = LIST_HEAD_INIT((worker).work_list),		\
	.delayed_work_list = LIST_HEAD_INIT((worker).delayed_work_list),\
	}

#define KTHREAD_WORK_INIT(work, fn)	{				\
	.node = LIST_HEAD_INIT((work).node),				\
	.func = (fn),							\
	}

#define KTHREAD_DELAYED_WORK_INIT(dwork, fn) {				\
	.work = KTHREAD_WORK_INIT((dwork).work, (fn)),			\
	.timer = __TIMER_INITIALIZER(kthread_delayed_work_timer_fn,\
				     TIMER_IRQSAFE),			\
	}

#define DEFINE_KTHREAD_WORKER(worker)					\
	struct kthread_worker worker = KTHREAD_WORKER_INIT(worker)

#define DEFINE_KTHREAD_WORK(work, fn)					\
	struct kthread_work work = KTHREAD_WORK_INIT(work, fn)

#define DEFINE_KTHREAD_DELAYED_WORK(dwork, fn)				\
	struct kthread_delayed_work dwork =				\
		KTHREAD_DELAYED_WORK_INIT(dwork, fn)


#ifdef CONFIG_LOCKDEP
# define KTHREAD_WORKER_INIT_ONSTACK(worker)				\
	({ kthread_init_worker(&worker); worker; })
# define DEFINE_KTHREAD_WORKER_ONSTACK(worker)				\
	struct kthread_worker worker = KTHREAD_WORKER_INIT_ONSTACK(worker)
#else
# define DEFINE_KTHREAD_WORKER_ONSTACK(worker) DEFINE_KTHREAD_WORKER(worker)
#endif

extern void __kthread_init_worker(struct kthread_worker *worker,
			const char *name, struct lock_class_key *key);

#define kthread_init_worker(worker)					\
	do {								\
		static struct lock_class_key __key;			\
		__kthread_init_worker((worker), "("#worker")->lock", &__key); \
	} while (0)

#define kthread_init_work(work, fn)					\
	do {								\
		memset((work), 0, sizeof(struct kthread_work));		\
		INIT_LIST_HEAD(&(work)->node);				\
		(work)->func = (fn);					\
	} while (0)

#define kthread_init_delayed_work(dwork, fn)				\
	do {								\
		kthread_init_work(&(dwork)->work, (fn));		\
		__init_timer(&(dwork)->timer,				\
			     kthread_delayed_work_timer_fn,		\
			     TIMER_IRQSAFE);				\
	} while (0)

int kthread_worker_fn(void *worker_ptr);

__printf(2, 3)
struct kthread_worker *
kthread_create_worker(unsigned int flags, const char namefmt[], ...);

__printf(3, 4) struct kthread_worker *
kthread_create_worker_on_cpu(int cpu, unsigned int flags,
			     const char namefmt[], ...);

bool kthread_queue_work(struct kthread_worker *worker,
			struct kthread_work *work);

bool kthread_queue_delayed_work(struct kthread_worker *worker,
				struct kthread_delayed_work *dwork,
				unsigned long delay);

bool kthread_mod_delayed_work(struct kthread_worker *worker,
			      struct kthread_delayed_work *dwork,
			      unsigned long delay);

void kthread_flush_work(struct kthread_work *work);
void kthread_flush_worker(struct kthread_worker *worker);

bool kthread_cancel_work_sync(struct kthread_work *work);
bool kthread_cancel_delayed_work_sync(struct kthread_delayed_work *work);

void kthread_destroy_worker(struct kthread_worker *worker);

struct cgroup_subsys_state;

#ifdef CONFIG_BLK_CGROUP
void kthread_associate_blkcg(struct cgroup_subsys_state *css);
struct cgroup_subsys_state *kthread_blkcg(void);
#else
static inline void kthread_associate_blkcg(struct cgroup_subsys_state *css) { }
static inline struct cgroup_subsys_state *kthread_blkcg(void)
{
	return NULL;
}
#endif
#endif 
