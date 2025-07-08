

#ifndef _VSERVICES_TRANSPORT_H_
#define _VSERVICES_TRANSPORT_H_

#include <linux/types.h>

#include <vservices/types.h>

struct vs_transport;
struct vs_mbuf;
struct vs_service_device;


struct vs_transport_vtable {
	
	struct vs_mbuf *(*alloc_mbuf)(struct vs_transport *transport,
			struct vs_service_device *service, size_t size,
			gfp_t gfp_flags);
	void (*free_mbuf)(struct vs_transport *transport,
			struct vs_service_device *service,
			struct vs_mbuf *mbuf);
	size_t (*mbuf_size)(struct vs_mbuf *mbuf);
	size_t (*max_mbuf_size)(struct vs_transport *transport);

	
	int (*send)(struct vs_transport *transport,
			struct vs_service_device *service,
			struct vs_mbuf *mbuf, unsigned long flags);
	int (*flush)(struct vs_transport *transport,
			struct vs_service_device *service);
	int (*notify)(struct vs_transport *transport,
			struct vs_service_device *service,
			unsigned long bits);

	
	void (*reset)(struct vs_transport *transport);
	void (*ready)(struct vs_transport *transport);

	
	int (*service_add)(struct vs_transport *transport,
			struct vs_service_device *service);
	void (*service_remove)(struct vs_transport *transport,
			struct vs_service_device *service);

	int (*service_start)(struct vs_transport *transport,
			struct vs_service_device *service);
	int (*service_reset)(struct vs_transport *transport,
			struct vs_service_device *service);

	ssize_t (*service_send_avail)(struct vs_transport *transport,
			struct vs_service_device *service);

	
	void (*get_notify_bits)(struct vs_transport *transport,
			unsigned *send_notify_bits, unsigned *recv_notify_bits);
	void (*get_quota_limits)(struct vs_transport *transport,
			unsigned *send_quota, unsigned *recv_quota);
};


#define VS_TRANSPORT_SEND_FLAGS_MORE		0x1


struct vs_transport {
	const char *type;
	const struct vs_transport_vtable *vt;
	struct vs_notify_info *notify_info;
	int notify_info_size;
};


struct vs_mbuf {
	void *data;
	size_t size;
	bool is_recv;
	void *priv;
	struct list_head queue;
};

#endif 
