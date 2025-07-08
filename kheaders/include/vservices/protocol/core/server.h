


#if !defined(VSERVICES_SERVER_CORE)
#define VSERVICES_SERVER_CORE

struct vs_service_device;
struct vs_server_core_state;

struct vs_server_core {

	
	bool rx_atomic;

	
	bool tx_atomic;

	
	u32 in_quota_best;
	u32 out_quota_best;
    
	struct vs_server_core_state *(*alloc) (struct vs_service_device *
					       service);
	void (*release) (struct vs_server_core_state * _state);

	struct vs_service_driver *driver;

	
	void (*start) (struct vs_server_core_state * _state);
	void (*reset) (struct vs_server_core_state * _state);
    
	int (*tx_ready) (struct vs_server_core_state * _state);

	struct {
		int (*state_change) (struct vs_server_core_state * _state,
				     vservice_core_statenum_t old,
				     vservice_core_statenum_t new);

		int (*req_connect) (struct vs_server_core_state * _state);

		int (*req_disconnect) (struct vs_server_core_state * _state);

		int (*msg_service_reset) (struct vs_server_core_state * _state,
					  uint32_t service_id);

	} core;
};

struct vs_server_core_state {
	vservice_core_protocol_state_t state;
	struct vs_service_device *service;
	bool released;
};



    

extern int vs_server_core_core_send_ack_connect(struct vs_server_core_state
						*_state, gfp_t flags);
extern int vs_server_core_core_send_nack_connect(struct vs_server_core_state
						 *_state, gfp_t flags);
    
extern int vs_server_core_core_send_ack_disconnect(struct vs_server_core_state
						   *_state, gfp_t flags);
extern int vs_server_core_core_send_nack_disconnect(struct vs_server_core_state
						    *_state, gfp_t flags);
    
extern int vs_server_core_core_send_startup(struct vs_server_core_state *_state,
					    uint32_t core_in_quota,
					    uint32_t core_out_quota,
					    gfp_t flags);

	    
extern int vs_server_core_core_send_shutdown(struct vs_server_core_state
					     *_state, gfp_t flags);

	    
extern struct vs_mbuf *vs_server_core_core_alloc_service_created(struct
								 vs_server_core_state
								 *_state,
								 struct
								 vs_string
								 *service_name,
								 struct
								 vs_string
								 *protocol_name,
								 gfp_t flags);
extern int vs_server_core_core_free_service_created(struct vs_server_core_state
						    *_state,
						    struct vs_string
						    *service_name,
						    struct vs_string
						    *protocol_name,
						    struct vs_mbuf *_mbuf);
extern int vs_server_core_core_send_service_created(struct vs_server_core_state
						    *_state,
						    uint32_t service_id,
						    struct vs_string
						    service_name,
						    struct vs_string
						    protocol_name,
						    struct vs_mbuf *_mbuf);

	    
extern int vs_server_core_core_send_service_removed(struct vs_server_core_state
						    *_state,
						    uint32_t service_id,
						    gfp_t flags);

	    
extern int vs_server_core_core_send_server_ready(struct vs_server_core_state
						 *_state, uint32_t service_id,
						 uint32_t in_quota,
						 uint32_t out_quota,
						 uint32_t in_bit_offset,
						 uint32_t in_num_bits,
						 uint32_t out_bit_offset,
						 uint32_t out_num_bits,
						 gfp_t flags);

	    
extern int vs_server_core_core_send_service_reset(struct vs_server_core_state
						  *_state, uint32_t service_id,
						  gfp_t flags);



struct module;

extern int __vservice_core_server_register(struct vs_server_core *server,
					   const char *name,
					   struct module *owner);

static inline int vservice_core_server_register(struct vs_server_core *server,
						const char *name)
{
#ifdef MODULE
	extern struct module __this_module;
	struct module *this_module = &__this_module;
#else
	struct module *this_module = NULL;
#endif

	return __vservice_core_server_register(server, name, this_module);
}

extern int vservice_core_server_unregister(struct vs_server_core *server);
#endif				
