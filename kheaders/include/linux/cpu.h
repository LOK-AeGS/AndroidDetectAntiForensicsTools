/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _LINUX_CPU_H_
#define _LINUX_CPU_H_

#include <linux/node.h>
#include <linux/compiler.h>
#include <linux/cpumask.h>
#include <linux/cpuhotplug.h>

struct device;
struct device_node;
struct attribute_group;

struct cpu {
	int node_id;		
	int hotpluggable;	
	struct device dev;
};

extern void boot_cpu_init(void);
extern void boot_cpu_hotplug_init(void);
extern void cpu_init(void);
extern void trap_init(void);

extern int register_cpu(struct cpu *cpu, int num);
extern struct device *get_cpu_device(unsigned cpu);
extern bool cpu_is_hotpluggable(unsigned cpu);
extern bool arch_match_cpu_phys_id(int cpu, u64 phys_id);
extern bool arch_find_n_match_cpu_physical_id(struct device_node *cpun,
					      int cpu, unsigned int *thread);

extern int cpu_add_dev_attr(struct device_attribute *attr);
extern void cpu_remove_dev_attr(struct device_attribute *attr);

extern int cpu_add_dev_attr_group(struct attribute_group *attrs);
extern void cpu_remove_dev_attr_group(struct attribute_group *attrs);

extern ssize_t cpu_show_meltdown(struct device *dev,
				 struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_spectre_v1(struct device *dev,
				   struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_spectre_v2(struct device *dev,
				   struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_spec_store_bypass(struct device *dev,
					  struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_l1tf(struct device *dev,
			     struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_mds(struct device *dev,
			    struct device_attribute *attr, char *buf);
extern ssize_t cpu_show_tsx_async_abort(struct device *dev,
					struct device_attribute *attr,
					char *buf);
extern ssize_t cpu_show_itlb_multihit(struct device *dev,
				      struct device_attribute *attr, char *buf);

extern __printf(4, 5)
struct device *cpu_device_create(struct device *parent, void *drvdata,
				 const struct attribute_group **groups,
				 const char *fmt, ...);
#ifdef CONFIG_HOTPLUG_CPU
extern void unregister_cpu(struct cpu *cpu);
extern ssize_t arch_cpu_probe(const char *, size_t);
extern ssize_t arch_cpu_release(const char *, size_t);
#endif


#define CPU_ONLINE		0x0002 
#define CPU_UP_PREPARE		0x0003 
#define CPU_DEAD		0x0007 
#define CPU_DEAD_FROZEN		0x0008 
#define CPU_POST_DEAD		0x0009 
#define CPU_BROKEN		0x000B 

#ifdef CONFIG_SMP
extern bool cpuhp_tasks_frozen;
int cpu_up(unsigned int cpu);
void notify_cpu_starting(unsigned int cpu);
extern void cpu_maps_update_begin(void);
extern void cpu_maps_update_done(void);

#else	
#define cpuhp_tasks_frozen	0

static inline void cpu_maps_update_begin(void)
{
}

static inline void cpu_maps_update_done(void)
{
}

#endif 
extern struct bus_type cpu_subsys;

#ifdef CONFIG_HOTPLUG_CPU
extern void cpus_write_lock(void);
extern void cpus_write_unlock(void);
extern void cpus_read_lock(void);
extern void cpus_read_unlock(void);
extern int  cpus_read_trylock(void);
extern void lockdep_assert_cpus_held(void);
extern void cpu_hotplug_disable(void);
extern void cpu_hotplug_enable(void);
void clear_tasks_mm_cpumask(int cpu);
int cpu_down(unsigned int cpu);

#else 

static inline void cpus_write_lock(void) { }
static inline void cpus_write_unlock(void) { }
static inline void cpus_read_lock(void) { }
static inline void cpus_read_unlock(void) { }
static inline int  cpus_read_trylock(void) { return true; }
static inline void lockdep_assert_cpus_held(void) { }
static inline void cpu_hotplug_disable(void) { }
static inline void cpu_hotplug_enable(void) { }
#endif	


static inline void cpu_hotplug_begin(void) { cpus_write_lock(); }
static inline void cpu_hotplug_done(void) { cpus_write_unlock(); }
static inline void get_online_cpus(void) { cpus_read_lock(); }
static inline void put_online_cpus(void) { cpus_read_unlock(); }

#ifdef CONFIG_PM_SLEEP_SMP
extern int freeze_secondary_cpus(int primary);
static inline int disable_nonboot_cpus(void)
{
	return freeze_secondary_cpus(0);
}
extern void enable_nonboot_cpus(void);
#else 
static inline int disable_nonboot_cpus(void) { return 0; }
static inline void enable_nonboot_cpus(void) {}
#endif 

void cpu_startup_entry(enum cpuhp_state state);

void cpu_idle_poll_ctrl(bool enable);


#define __cpuidle	__attribute__((__section__(".cpuidle.text")))

bool cpu_in_idle(unsigned long pc);

void arch_cpu_idle(void);
void arch_cpu_idle_prepare(void);
void arch_cpu_idle_enter(void);
void arch_cpu_idle_exit(void);
void arch_cpu_idle_dead(void);

int cpu_report_state(int cpu);
int cpu_check_up_prepare(int cpu);
void cpu_set_state_online(int cpu);
void play_idle(unsigned long duration_ms);

#ifdef CONFIG_HOTPLUG_CPU
bool cpu_wait_death(unsigned int cpu, int seconds);
bool cpu_report_death(void);
void cpuhp_report_idle_dead(void);
#else
static inline void cpuhp_report_idle_dead(void) { }
#endif 

enum cpuhp_smt_control {
	CPU_SMT_ENABLED,
	CPU_SMT_DISABLED,
	CPU_SMT_FORCE_DISABLED,
	CPU_SMT_NOT_SUPPORTED,
};

#if defined(CONFIG_SMP) && defined(CONFIG_HOTPLUG_SMT)
extern enum cpuhp_smt_control cpu_smt_control;
extern void cpu_smt_disable(bool force);
extern void cpu_smt_check_topology(void);
extern int cpuhp_smt_enable(void);
extern int cpuhp_smt_disable(enum cpuhp_smt_control ctrlval);
#else
# define cpu_smt_control		(CPU_SMT_ENABLED)
static inline void cpu_smt_disable(bool force) { }
static inline void cpu_smt_check_topology(void) { }
static inline int cpuhp_smt_enable(void) { return 0; }
static inline int cpuhp_smt_disable(enum cpuhp_smt_control ctrlval) { return 0; }
#endif

#define IDLE_START 1
#define IDLE_END 2

void idle_notifier_register(struct notifier_block *n);
void idle_notifier_unregister(struct notifier_block *n);
void idle_notifier_call_chain(unsigned long val);

extern bool cpu_mitigations_off(void);
extern bool cpu_mitigations_auto_nosmt(void);

#endif 
