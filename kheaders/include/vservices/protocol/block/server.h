


#if !defined(VSERVICES_SERVER_BLOCK)
#define VSERVICES_SERVER_BLOCK

struct vs_service_device;
struct vs_server_block_state;

struct vs_server_block {

	
	bool rx_atomic;

	
	bool tx_atomic;

	
	u32 in_quota_best;
	u32 out_quota_best;
    
	struct vs_server_block_state *(*alloc) (struct vs_service_device *
						service);
	void (*release) (struct vs_server_block_state * _state);

	struct vs_service_driver *driver;



	 vs_server_response_type_t(*open) (struct vs_server_block_state *
					   _state);

	 vs_server_response_type_t(*reopen) (struct vs_server_block_state *
					     _state);

	 vs_server_response_type_t(*close) (struct vs_server_block_state *
					    _state);

	void (*closed) (struct vs_server_block_state * _state);


	int (*tx_ready) (struct vs_server_block_state * _state);

	struct {
		int (*req_read) (struct vs_server_block_state * _state,
				 uint32_t _opaque, uint64_t sector_index,
				 uint32_t num_sects, bool nodelay, bool flush);

		int (*req_write) (struct vs_server_block_state * _state,
				  uint32_t _opaque, uint64_t sector_index,
				  uint32_t num_sects, bool nodelay, bool flush,
				  bool commit, struct vs_pbuf data,
				  struct vs_mbuf * _mbuf);

	} io;
};

struct vs_server_block_state {
	vservice_block_state_t state;
	bool readonly;
	uint32_t sector_size;
	uint32_t segment_size;
	uint64_t device_sectors;
	bool flushable;
	bool committable;
	struct {
		uint32_t sector_size;
		uint32_t segment_size;
	} io;
	struct vs_service_device *service;
	bool released;
};


extern int vs_server_block_open_complete(struct vs_server_block_state *_state,
					 vs_server_response_type_t resp);

extern int vs_server_block_close_complete(struct vs_server_block_state *_state,
					  vs_server_response_type_t resp);

extern int vs_server_block_reopen_complete(struct vs_server_block_state *_state,
					   vs_server_response_type_t resp);

    

extern struct vs_mbuf *vs_server_block_io_alloc_ack_read(struct
							 vs_server_block_state
							 *_state,
							 struct vs_pbuf *data,
							 gfp_t flags);
extern int vs_server_block_io_free_ack_read(struct vs_server_block_state
					    *_state, struct vs_pbuf *data,
					    struct vs_mbuf *_mbuf);
extern int vs_server_block_io_send_ack_read(struct vs_server_block_state
					    *_state, uint32_t _opaque,
					    struct vs_pbuf data,
					    struct vs_mbuf *_mbuf);
extern int vs_server_block_io_send_nack_read(struct vs_server_block_state
					     *_state, uint32_t _opaque,
					     vservice_block_block_io_error_t
					     err, gfp_t flags);
    
extern int vs_server_block_io_getbufs_req_write(struct vs_server_block_state
						*_state, struct vs_pbuf *data,
						struct vs_mbuf *_mbuf);
extern int vs_server_block_io_free_req_write(struct vs_server_block_state
					     *_state, struct vs_pbuf *data,
					     struct vs_mbuf *_mbuf);
extern int vs_server_block_io_send_ack_write(struct vs_server_block_state
					     *_state, uint32_t _opaque,
					     gfp_t flags);
extern int vs_server_block_io_send_nack_write(struct vs_server_block_state
					      *_state, uint32_t _opaque,
					      vservice_block_block_io_error_t
					      err, gfp_t flags);

static inline bool vs_server_block_io_send_ack_read_is_pending(struct
							       vs_server_block_state
							       *_state)
{
	return !bitmap_empty(_state->state.io.read_bitmask,
			     VSERVICE_BLOCK_IO_READ_MAX_PENDING);
}

static inline bool vs_server_block_io_send_ack_write_is_pending(struct
								vs_server_block_state
								*_state)
{
	return !bitmap_empty(_state->state.io.write_bitmask,
			     VSERVICE_BLOCK_IO_WRITE_MAX_PENDING);
}



struct module;

extern int __vservice_block_server_register(struct vs_server_block *server,
					    const char *name,
					    struct module *owner);

static inline int vservice_block_server_register(struct vs_server_block *server,
						 const char *name)
{
#ifdef MODULE
	extern struct module __this_module;
	struct module *this_module = &__this_module;
#else
	struct module *this_module = NULL;
#endif

	return __vservice_block_server_register(server, name, this_module);
}

extern int vservice_block_server_unregister(struct vs_server_block *server);
#endif				
