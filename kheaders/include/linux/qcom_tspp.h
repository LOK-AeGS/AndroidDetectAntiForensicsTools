/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _MSM_TSPP_H_
#define _MSM_TSPP_H_

struct tspp_data_descriptor {
	void *virt_base;   
	phys_addr_t phys_base; 
	dma_addr_t dma_base; 
	u32 size;          
	int id;            
	void *user;        
};

enum tspp_key_parity {
	TSPP_KEY_PARITY_EVEN,
	TSPP_KEY_PARITY_ODD
};

struct tspp_key {
	enum tspp_key_parity parity;
	int lsb;
	int msb;
};

enum tspp_source {
	TSPP_SOURCE_TSIF0,
	TSPP_SOURCE_TSIF1,
	TSPP_SOURCE_MEM,
	TSPP_SOURCE_NONE = -1
};

enum tspp_mode {
	TSPP_MODE_DISABLED,
	TSPP_MODE_PES,
	TSPP_MODE_RAW,
	TSPP_MODE_RAW_NO_SUFFIX
};

enum tspp_tsif_mode {
	TSPP_TSIF_MODE_LOOPBACK, 
	TSPP_TSIF_MODE_1,        
	TSPP_TSIF_MODE_2         
};

struct tspp_filter {
	int pid;
	int mask;
	enum tspp_mode mode;
	unsigned int priority;	
	int decrypt;
	enum tspp_source source;
};

struct tspp_select_source {
	enum tspp_source source;
	enum tspp_tsif_mode mode;
	int clk_inverse;
	int data_inverse;
	int sync_inverse;
	int enable_inverse;
};

enum tsif_tts_source {
	TSIF_TTS_TCR = 0,	
	TSIF_TTS_LPASS_TIMER	
};

struct tspp_ion_dma_buf_info {
	struct dma_buf *dbuf;
	struct dma_buf_attachment *attach;
	struct sg_table *table;
	bool smmu_map;
	void *va;
};

typedef void (tspp_notifier)(int channel_id, void *user);
typedef void* (tspp_allocator)(int channel_id, u32 size,
	      phys_addr_t *phys_base, dma_addr_t *dma_base, void *user);
typedef void (tspp_memfree)(int channel_id, u32 size,
	void *virt_base, phys_addr_t phys_base, void *user);


int tspp_open_stream(u32 dev, u32 channel_id,
			struct tspp_select_source *source);
int tspp_close_stream(u32 dev, u32 channel_id);
int tspp_open_channel(u32 dev, u32 channel_id);
int tspp_close_channel(u32 dev, u32 channel_id);
int tspp_get_ref_clk_counter(u32 dev,
	enum tspp_source source, u32 *tcr_counter);
int tspp_add_filter(u32 dev, u32 channel_id, struct tspp_filter *filter);
int tspp_remove_filter(u32 dev, u32 channel_id,	struct tspp_filter *filter);
int tspp_set_key(u32 dev, u32 channel_id, struct tspp_key *key);
int tspp_register_notification(u32 dev, u32 channel_id, tspp_notifier *notify,
	void *data, u32 timer_ms);
int tspp_unregister_notification(u32 dev, u32 channel_id);
const struct tspp_data_descriptor *tspp_get_buffer(u32 dev, u32 channel_id);
int tspp_release_buffer(u32 dev, u32 channel_id, u32 descriptor_id);
int tspp_allocate_buffers(u32 dev, u32 channel_id, u32 count,
	u32 size, u32 int_freq, tspp_allocator *alloc,
	tspp_memfree *memfree, void *user);

int tspp_get_tts_source(u32 dev, int *tts_source);
int tspp_get_lpass_time_counter(u32 dev, enum tspp_source source,
			u64 *lpass_time_counter);

int tspp_attach_ion_dma_buff(u32 dev,
	struct tspp_ion_dma_buf_info *ion_dma_buf);

int tspp_detach_ion_dma_buff(u32 dev,
	struct tspp_ion_dma_buf_info *ion_dma_buf);
void *tspp_allocate_dma_buffer(u32 dev, int size, phys_addr_t *paddr);
int tspp_free_dma_buffer(u32 dev, int size, void *vaddr, dma_addr_t paddr);
#endif 
