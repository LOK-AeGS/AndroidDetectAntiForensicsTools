


#if !defined(__VSERVICES_CLIENT_BLOCK__)
#define __VSERVICES_CLIENT_BLOCK__

struct vs_service_device;
struct vs_client_block_state;

struct vs_client_block {

	
	bool rx_atomic;

	
	bool tx_atomic;
    
	struct vs_client_block_state *(*alloc) (struct vs_service_device *
						service);
	void (*release) (struct vs_client_block_state * _state);

	struct vs_service_driver *driver;



	void (*opened) (struct vs_client_block_state * _state);

	void (*reopened) (struct vs_client_block_state * _state);

	void (*closed) (struct vs_client_block_state * _state);


	int (*tx_ready) (struct vs_client_block_state * _state);

	struct {
		int (*ack_read) (struct vs_client_block_state * _state,
				 void *_opaque, struct vs_pbuf data,
				 struct vs_mbuf * _mbuf);
		int (*nack_read) (struct vs_client_block_state * _state,
				  void *_opaque,
				  vservice_block_block_io_error_t err);

		int (*ack_write) (struct vs_client_block_state * _state,
				  void *_opaque);
		int (*nack_write) (struct vs_client_block_state * _state,
				   void *_opaque,
				   vservice_block_block_io_error_t err);

	} io;
};

struct vs_client_block_state {
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

extern int vs_client_block_reopen(struct vs_client_block_state *_state);

extern int vs_client_block_close(struct vs_client_block_state *_state);

    

extern int vs_client_block_io_getbufs_ack_read(struct vs_client_block_state
					       *_state, struct vs_pbuf *data,
					       struct vs_mbuf *_mbuf);
extern int vs_client_block_io_free_ack_read(struct vs_client_block_state
					    *_state, struct vs_pbuf *data,
					    struct vs_mbuf *_mbuf);
extern int vs_client_block_io_req_read(struct vs_client_block_state *_state,
				       void *_opaque, uint64_t sector_index,
				       uint32_t num_sects, bool nodelay,
				       bool flush, gfp_t flags);

	
extern struct vs_mbuf *vs_client_block_io_alloc_req_write(struct
							  vs_client_block_state
							  *_state,
							  struct vs_pbuf *data,
							  gfp_t flags);
extern int vs_client_block_io_free_req_write(struct vs_client_block_state
					     *_state, struct vs_pbuf *data,
					     struct vs_mbuf *_mbuf);
extern int vs_client_block_io_req_write(struct vs_client_block_state *_state,
					void *_opaque, uint64_t sector_index,
					uint32_t num_sects, bool nodelay,
					bool flush, bool commit,
					struct vs_pbuf data,
					struct vs_mbuf *_mbuf);


static inline bool vs_client_block_io_req_read_can_send(struct
							vs_client_block_state
							*_state)
{
	return !bitmap_full(_state->state.io.read_bitmask,
			    VSERVICE_BLOCK_IO_READ_MAX_PENDING);
}

static inline bool vs_client_block_io_req_read_is_pending(struct
							  vs_client_block_state
							  *_state)
{
	return !bitmap_empty(_state->state.io.read_bitmask,
			     VSERVICE_BLOCK_IO_READ_MAX_PENDING);
}

static inline bool vs_client_block_io_req_write_can_send(struct
							 vs_client_block_state
							 *_state)
{
	return !bitmap_full(_state->state.io.write_bitmask,
			    VSERVICE_BLOCK_IO_WRITE_MAX_PENDING);
}

static inline bool vs_client_block_io_req_write_is_pending(struct
							   vs_client_block_state
							   *_state)
{
	return !bitmap_empty(_state->state.io.write_bitmask,
			     VSERVICE_BLOCK_IO_WRITE_MAX_PENDING);
}



struct module;

extern int __vservice_block_client_register(struct vs_client_block *client,
					    const char *name,
					    struct module *owner);

static inline int vservice_block_client_register(struct vs_client_block *client,
						 const char *name)
{
#ifdef MODULE
	extern struct module __this_module;
	struct module *this_module = &__this_module;
#else
	struct module *this_module = NULL;
#endif

	return __vservice_block_client_register(client, name, this_module);
}

extern int vservice_block_client_unregister(struct vs_client_block *client);

#endif				
