


#if !defined(VSERVICES_SERVER_SERIAL)
#define VSERVICES_SERVER_SERIAL

struct vs_service_device;
struct vs_server_serial_state;

struct vs_server_serial {

	
	bool rx_atomic;

	
	bool tx_atomic;

	
	u32 in_quota_best;
	u32 out_quota_best;
    
	struct vs_server_serial_state *(*alloc) (struct vs_service_device *
						 service);
	void (*release) (struct vs_server_serial_state * _state);

	struct vs_service_driver *driver;



	 vs_server_response_type_t(*open) (struct vs_server_serial_state *
					   _state);

	 vs_server_response_type_t(*reopen) (struct vs_server_serial_state *
					     _state);

	 vs_server_response_type_t(*close) (struct vs_server_serial_state *
					    _state);

	void (*closed) (struct vs_server_serial_state * _state);


	int (*tx_ready) (struct vs_server_serial_state * _state);

	struct {
		int (*msg_msg) (struct vs_server_serial_state * _state,
				struct vs_pbuf b, struct vs_mbuf * _mbuf);

	} serial;
};

struct vs_server_serial_state {
	vservice_serial_protocol_state_t state;
	uint32_t packet_size;
	struct {
		uint32_t packet_size;
	} serial;
	struct vs_service_device *service;
	bool released;
};


extern int vs_server_serial_open_complete(struct vs_server_serial_state *_state,
					  vs_server_response_type_t resp);

extern int vs_server_serial_close_complete(struct vs_server_serial_state
					   *_state,
					   vs_server_response_type_t resp);

extern int vs_server_serial_reopen_complete(struct vs_server_serial_state
					    *_state,
					    vs_server_response_type_t resp);

    

extern struct vs_mbuf *vs_server_serial_serial_alloc_msg(struct
							 vs_server_serial_state
							 *_state,
							 struct vs_pbuf *b,
							 gfp_t flags);
extern int vs_server_serial_serial_getbufs_msg(struct vs_server_serial_state
					       *_state, struct vs_pbuf *b,
					       struct vs_mbuf *_mbuf);
extern int vs_server_serial_serial_free_msg(struct vs_server_serial_state
					    *_state, struct vs_pbuf *b,
					    struct vs_mbuf *_mbuf);
extern int vs_server_serial_serial_send_msg(struct vs_server_serial_state
					    *_state, struct vs_pbuf b,
					    struct vs_mbuf *_mbuf);



struct module;

extern int __vservice_serial_server_register(struct vs_server_serial *server,
					     const char *name,
					     struct module *owner);

static inline int vservice_serial_server_register(struct vs_server_serial
						  *server, const char *name)
{
#ifdef MODULE
	extern struct module __this_module;
	struct module *this_module = &__this_module;
#else
	struct module *this_module = NULL;
#endif

	return __vservice_serial_server_register(server, name, this_module);
}

extern int vservice_serial_server_unregister(struct vs_server_serial *server);
#endif				
