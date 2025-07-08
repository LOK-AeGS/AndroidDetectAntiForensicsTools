

#ifndef _VSERVICE_SERVICE_H_
#define _VSERVICE_SERVICE_H_

#include <linux/version.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/wait.h>
#include <linux/err.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 38)
#include <asm/atomic.h>
#else
#include <linux/atomic.h>
#endif

#include <vservices/transport.h>
#include <vservices/session.h>
#include <vservices/types.h>

struct vs_mbuf;


struct vs_service_driver {
	const char *protocol;
	bool is_server;
	bool rx_atomic, tx_atomic;

	int (*probe)(struct vs_service_device *service);
	int (*remove)(struct vs_service_device *service);

	int (*receive)(struct vs_service_device *service,
		struct vs_mbuf *mbuf);
	void (*notify)(struct vs_service_device *service, u32 flags);

	void (*start)(struct vs_service_device *service);
	void (*reset)(struct vs_service_device *service);

	int (*tx_ready)(struct vs_service_device *service);

	unsigned in_quota_min;
	unsigned in_quota_best;
	unsigned out_quota_min;
	unsigned out_quota_best;
	unsigned in_notify_count;
	unsigned out_notify_count;

	struct device_driver driver;
};

#define to_vs_service_driver(d) \
	container_of(d, struct vs_service_driver, driver)


extern struct bus_type vs_client_bus_type;
extern struct bus_type vs_server_bus_type;


struct vs_service_stats {
	unsigned long	over_quota_time;

	atomic_t        sent_mbufs;
	atomic_t        sent_bytes;
	atomic_t	send_failures;
	atomic_t        recv_mbufs;
	atomic_t        recv_bytes;
	atomic_t	recv_failures;
	atomic_t        nr_over_quota;
	atomic_t        nr_tx_ready;
	atomic_t        over_quota_time_total;
	atomic_t        over_quota_time_avg;
};


struct vs_service_device {
	vs_service_id_t id;
	char *name;
	char *sysfs_name;
	char *protocol;
	bool is_server;

	struct vs_service_device *owner;
	unsigned lock_subclass;

	struct mutex ready_lock;
	unsigned readiness;
	int disable_count;
	bool driver_probed;

	struct workqueue_struct *work_queue;

	struct tasklet_struct rx_tasklet;
	struct work_struct rx_work;

	spinlock_t rx_lock;
	struct list_head rx_queue;
	bool tx_ready, tx_batching;

	spinlock_t state_spinlock;
	struct mutex state_mutex;

	struct work_struct reset_work;
	bool pending_reset;
	struct delayed_work ready_work;
	struct delayed_work cooloff_work;
	struct work_struct cleanup_work;

	unsigned long last_reset;
	unsigned long last_reset_request;
	unsigned long last_ready;
	unsigned long reset_delay;

	atomic_t is_over_quota;
	wait_queue_head_t quota_wq;

	unsigned notify_send_bits;
	unsigned notify_send_offset;
	unsigned notify_recv_bits;
	unsigned notify_recv_offset;
	unsigned send_quota;
	unsigned recv_quota;

	unsigned in_quota_set;
	unsigned out_quota_set;

	void *transport_priv;

	struct device dev;
	struct vs_service_stats stats;

#ifdef CONFIG_VSERVICES_LOCK_DEBUG
	bool state_spinlock_used;
	bool state_mutex_used;
#endif
};

#define to_vs_service_device(d) container_of(d, struct vs_service_device, dev)


static inline struct vs_session_device *
vs_service_get_session(struct vs_service_device *service)
{
	return to_vs_session_device(service->dev.parent);
}


static inline int
vs_service_send(struct vs_service_device *service, struct vs_mbuf *mbuf)
{
	struct vs_session_device *session = vs_service_get_session(service);
	const struct vs_transport_vtable *vt = session->transport->vt;
	const unsigned long flags =
		service->tx_batching ?  VS_TRANSPORT_SEND_FLAGS_MORE : 0;
	size_t msg_size = vt->mbuf_size(mbuf);
	int err;

	err = vt->send(session->transport, service, mbuf, flags);
	if (!err) {
		atomic_inc(&service->stats.sent_mbufs);
		atomic_add(msg_size, &service->stats.sent_bytes);
	} else {
		atomic_inc(&service->stats.send_failures);
	}

	return err;
}


static inline struct vs_mbuf *
vs_service_alloc_mbuf(struct vs_service_device *service, size_t size,
		gfp_t flags)
{
	struct vs_session_device *session = vs_service_get_session(service);
	struct vs_mbuf *mbuf;

	mbuf = session->transport->vt->alloc_mbuf(session->transport,
			service, size, flags);
	if (IS_ERR(mbuf) && PTR_ERR(mbuf) == -ENOBUFS) {
		
		if (atomic_cmpxchg(&service->is_over_quota, 0, 1) == 0) {
			service->stats.over_quota_time = jiffies;
			atomic_inc(&service->stats.nr_over_quota);
		}
	}

	
	if (WARN_ON_ONCE(!mbuf))
		return ERR_PTR(-ENOMEM);

	return mbuf;
}


static inline void
vs_service_free_mbuf(struct vs_service_device *service, struct vs_mbuf *mbuf)
{
	struct vs_session_device *session = vs_service_get_session(service);

	session->transport->vt->free_mbuf(session->transport, service, mbuf);
}


static inline int
vs_service_notify(struct vs_service_device *service, u32 flags)
{
	struct vs_session_device *session = vs_service_get_session(service);

	return session->transport->vt->notify(session->transport,
			service, flags);
}


static inline bool
vs_service_has_atomic_rx(struct vs_service_device *service)
{
	if (WARN_ON(!service->dev.driver))
		return false;

	return to_vs_service_driver(service->dev.driver)->rx_atomic;
}


static inline size_t
vs_service_max_mbuf_size(struct vs_service_device *service)
{
	struct vs_session_device *session = vs_service_get_session(service);

	return session->transport->vt->max_mbuf_size(session->transport);
}


static inline ssize_t
vs_service_send_mbufs_available(struct vs_service_device *service)
{
	struct vs_session_device *session = vs_service_get_session(service);

	return session->transport->vt->service_send_avail(session->transport,
			service);
}


static inline bool
vs_service_has_atomic_tx(struct vs_service_device *service)
{
	if (WARN_ON(!service->dev.driver))
		return false;

	return to_vs_service_driver(service->dev.driver)->tx_atomic;
}


static inline void
vs_service_state_lock(struct vs_service_device *service)
__acquires(service)
{
#ifdef CONFIG_VSERVICES_LOCK_DEBUG
	WARN_ON_ONCE(vs_service_has_atomic_tx(service));
#endif

	mutex_lock_nested(&service->state_mutex, service->lock_subclass);

#ifdef CONFIG_VSERVICES_LOCK_DEBUG
	if (WARN_ON_ONCE(service->state_spinlock_used))
		dev_err(&service->dev, "Service is using both the state spinlock and mutex - Fix your driver\n");
	service->state_mutex_used = true;
#endif

	if (vs_service_has_atomic_rx(service))
		tasklet_disable(&service->rx_tasklet);

	__acquire(service);
}


static inline void
vs_service_state_unlock(struct vs_service_device *service)
__releases(service)
{
	__release(service);

	mutex_unlock(&service->state_mutex);

	if (vs_service_has_atomic_rx(service)) {
		tasklet_enable(&service->rx_tasklet);

		
		if (!list_empty(&service->rx_queue))
			tasklet_schedule(&service->rx_tasklet);
	}
}


static inline void
vs_service_state_lock_bh(struct vs_service_device *service)
__acquires(service)
__acquires(&service->state_spinlock)
{
#ifdef CONFIG_VSERVICES_LOCK_DEBUG
	WARN_ON_ONCE(!vs_service_has_atomic_rx(service));
	WARN_ON_ONCE(!vs_service_has_atomic_tx(service));
#endif

#ifdef CONFIG_SMP
	
	tasklet_disable(&service->rx_tasklet);
#endif

	spin_lock_bh(&service->state_spinlock);

#ifdef CONFIG_VSERVICES_LOCK_DEBUG
	if (WARN_ON_ONCE(service->state_mutex_used))
		dev_err(&service->dev, "Service is using both the state spinlock and mutex - Fix your driver\n");
	service->state_spinlock_used = true;
#endif

	__acquire(service);
}


static inline void
vs_service_state_unlock_bh(struct vs_service_device *service)
__releases(service)
__releases(&service->state_spinlock)
{
	__release(service);

	spin_unlock_bh(&service->state_spinlock);

#ifdef CONFIG_SMP
	tasklet_enable(&service->rx_tasklet);
#endif
}


#define vs_state_lock(state) vs_service_state_lock((state)->service)
#define vs_state_unlock(state) vs_service_state_unlock((state)->service)
#define vs_state_lock_bh(state) vs_service_state_lock_bh((state)->service)
#define vs_state_unlock_bh(state) vs_service_state_unlock_bh((state)->service)


#define __vs_state_lock_safe(_state, _lock, _unlock) ({ \
	bool __ok = true;						\
	typeof(_state) __state = (_state);				\
	struct vs_service_device *__service = __state->service;		\
	mutex_lock_nested(&__service->ready_lock,			\
			__service->lock_subclass);			\
	__ok = !READ_ONCE(__state->released);				\
	if (__ok) {							\
		_lock(__state);						\
		__ok = !READ_ONCE(__state->released);			\
		if (!__ok)						\
			_unlock(__state);				\
	}								\
	mutex_unlock(&__service->ready_lock);				\
	__ok;								\
})
#define vs_state_lock_safe(_state) \
	__vs_state_lock_safe((_state), vs_state_lock, vs_state_unlock)
#define vs_state_lock_safe_bh(_state) \
	__vs_state_lock_safe((_state), vs_state_lock_bh, vs_state_unlock_bh)


static inline struct vs_service_device *
vs_get_service(struct vs_service_device *service)
{
	if (service)
		get_device(&service->dev);
	return service;
}


static inline void
vs_put_service(struct vs_service_device *service)
{
	put_device(&service->dev);
}

extern int vs_service_reset(struct vs_service_device *service,
		struct vs_service_device *caller);
extern void vs_service_reset_nosync(struct vs_service_device *service);


static inline void
vs_service_send_batch_start(struct vs_service_device *service, bool flush)
{
	if (flush && service->tx_batching) {
		struct vs_session_device *session =
			vs_service_get_session(service);
		const struct vs_transport_vtable *vt = session->transport->vt;
		if (vt->flush)
			vt->flush(session->transport, service);
	} else {
		service->tx_batching = true;
	}
}


static inline void
vs_service_send_batch_end(struct vs_service_device *service, bool flush)
{
	service->tx_batching = false;
	if (flush) {
		struct vs_session_device *session =
			vs_service_get_session(service);
		const struct vs_transport_vtable *vt = session->transport->vt;
		if (vt->flush)
			vt->flush(session->transport, service);
	}
}


#endif 
