


#if !defined(__VSERVICES_CLIENT_SERIAL__)
#define __VSERVICES_CLIENT_SERIAL__

struct vs_service_device;
struct vs_client_serial_state;

struct vs_client_serial {

	
	bool rx_atomic;

	
	bool tx_atomic;
    
	struct vs_client_serial_state *(*alloc) (struct vs_service_device *
						 service);
	void (*release) (struct vs_client_serial_state * _state);

	struct vs_service_driver *driver;



	void (*opened) (struct vs_client_serial_state * _state);

	void (*reopened) (struct vs_client_serial_state * _state);

	void (*closed) (struct vs_client_serial_state * _state);


	int (*tx_ready) (struct vs_client_serial_state * _state);

	struct {
		int (*msg_msg) (struct vs_client_serial_state * _state,
				struct vs_pbuf b, struct vs_mbuf * _mbuf);

	} serial;
};

struct vs_client_serial_state {
	vservice_serial_protocol_state_t state;
	uint32_t packet_size;
	struct {
		uint32_t packet_size;
	} serial;
	struct vs_service_device *service;
	bool released;
};

extern int vs_client_serial_reopen(struct vs_client_serial_state *_state);

extern int vs_client_serial_close(struct vs_client_serial_state *_state);

    

extern struct vs_mbuf *vs_client_serial_serial_alloc_msg(struct
							 vs_client_serial_state
							 *_state,
							 struct vs_pbuf *b,
							 gfp_t flags);
extern int vs_client_serial_serial_getbufs_msg(struct vs_client_serial_state
					       *_state, struct vs_pbuf *b,
					       struct vs_mbuf *_mbuf);
extern int vs_client_serial_serial_free_msg(struct vs_client_serial_state
					    *_state, struct vs_pbuf *b,
					    struct vs_mbuf *_mbuf);
extern int vs_client_serial_serial_send_msg(struct vs_client_serial_state
					    *_state, struct vs_pbuf b,
					    struct vs_mbuf *_mbuf);



struct module;

extern int __vservice_serial_client_register(struct vs_client_serial *client,
					     const char *name,
					     struct module *owner);

static inline int vservice_serial_client_register(struct vs_client_serial
						  *client, const char *name)
{
#ifdef MODULE
	extern struct module __this_module;
	struct module *this_module = &__this_module;
#else
	struct module *this_module = NULL;
#endif

	return __vservice_serial_client_register(client, name, this_module);
}

extern int vservice_serial_client_unregister(struct vs_client_serial *client);

#endif				
