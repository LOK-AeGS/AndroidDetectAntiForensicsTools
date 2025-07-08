

#ifndef _VSERVICES_SESSION_H_
#define _VSERVICES_SESSION_H_

#include <linux/types.h>
#include <linux/device.h>
#include <linux/spinlock.h>
#include <linux/completion.h>
#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/idr.h>

#include <vservices/types.h>

struct vs_service_device;
struct vs_mbuf;

struct notifier_block;


enum vs_notify_event_t {
	VS_SESSION_NOTIFY_ADD,
	VS_SESSION_NOTIFY_REMOVE,
};


struct vs_session_device {
	char *name;
	bool is_server;
	struct vs_transport *transport;
	int session_num;

	struct mutex session_lock;

	
	struct idr service_idr;
	struct mutex service_idr_lock;
	struct vs_service_device *core_service;

	struct work_struct activation_work;
	atomic_t activation_state;

	struct work_struct fatal_error_work;

	unsigned long debug_mask;

	struct list_head list;
	struct kobject *sysfs_entry;

	struct device dev;
};

#define to_vs_session_device(d) \
	container_of(d, struct vs_session_device, dev)

extern struct vs_session_device *
vs_session_register(struct vs_transport *transport, struct device *parent,
		bool server, const char *transport_name);
extern void vs_session_start(struct vs_session_device *session);
extern void vs_session_unregister(struct vs_session_device *session);

extern int vs_session_handle_message(struct vs_session_device *session,
		struct vs_mbuf *mbuf, vs_service_id_t service_id);

extern void vs_session_quota_available(struct vs_session_device *session,
		vs_service_id_t service_id, unsigned count,
		bool send_tx_ready);

extern void vs_session_handle_notify(struct vs_session_device *session,
		unsigned long flags, vs_service_id_t service_id);

extern void vs_session_handle_reset(struct vs_session_device *session);
extern void vs_session_handle_activate(struct vs_session_device *session);

extern struct vs_service_device *
vs_server_create_service(struct vs_session_device *session,
		struct vs_service_device *parent, const char *name,
		const char *protocol, const void *plat_data);
extern int vs_server_destroy_service(struct vs_service_device *service,
		struct vs_service_device *parent);

extern void vs_session_register_notify(struct notifier_block *nb);
extern void vs_session_unregister_notify(struct notifier_block *nb);

extern int vs_session_unbind_driver(struct vs_service_device *service);

extern void vs_session_for_each_service(struct vs_session_device *session,
		void (*func)(struct vs_service_device *, void *), void *data);

extern struct mutex vs_session_lock;
extern int vs_session_for_each_locked(
		int (*fn)(struct vs_session_device *session, void *data),
		void *data);

static inline int vs_session_for_each(
		int (*fn)(struct vs_session_device *session, void *data),
		void *data)
{
	int r;
	mutex_lock(&vs_session_lock);
	r = vs_session_for_each_locked(fn, data);
	mutex_unlock(&vs_session_lock);
	return r;
}

#endif 
