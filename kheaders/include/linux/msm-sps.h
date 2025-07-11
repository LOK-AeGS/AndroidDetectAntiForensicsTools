/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _SPS_H_
#define _SPS_H_

#include <linux/types.h>	

#if defined(CONFIG_PHYS_ADDR_T_64BIT) || defined(CONFIG_ARM_LPAE)


#define SPS_GET_UPPER_ADDR(addr) ((addr & 0xF00000000ULL) >> 32)


#define DESC_FULL_ADDR(flags, addr) ((((phys_addr_t)flags & 0xF) << 32) | addr)


#define DESC_FLAG_WORD(flags, addr) (((addr & 0xF00000000ULL) >> 32) | flags)

#else

#define SPS_GET_UPPER_ADDR(addr) (0)
#define DESC_FULL_ADDR(flags, addr) (addr)
#define DESC_FLAG_WORD(flags, addr) (flags)

#endif


#define DESC_UPPER_ADDR(flags) ((flags & 0xF))


#define SPS_GET_LOWER_ADDR(addr) ((u32)(addr & 0xFFFFFFFF))


#define SPS_DEV_HANDLE_MEM       (~0x0ul>>1)




#define SPS_DEV_HANDLE_INVALID   0


#define SPS_IRQ_INVALID          0


#define SPS_ADDR_INVALID      (0xDEADBEEF)


#define SPS_CLASS_INVALID     (0xDEADBEEF)


#define SPS_CONFIG_DEFAULT       0


#define SPS_DMA_THRESHOLD_DEFAULT   0


#define SPS_IOVEC_FLAG_INT  0x8000  
#define SPS_IOVEC_FLAG_EOT  0x4000  
#define SPS_IOVEC_FLAG_EOB  0x2000  
#define SPS_IOVEC_FLAG_NWD  0x1000  
#define SPS_IOVEC_FLAG_CMD  0x0800  
#define SPS_IOVEC_FLAG_LOCK  0x0400  
#define SPS_IOVEC_FLAG_UNLOCK  0x0200  
#define SPS_IOVEC_FLAG_IMME 0x0100  
#define SPS_IOVEC_FLAG_NO_SUBMIT 0x0020  
#define SPS_IOVEC_FLAG_DEFAULT   0x0010  


#define SPS_IOVEC_MAX_SIZE   (32 * 1024 - 1)  




#define SPS_BAM_OPT_ENABLE_AT_BOOT  1UL

#define SPS_BAM_OPT_IRQ_DISABLED    (1UL << 1)

#define SPS_BAM_OPT_BAMDMA          (1UL << 2)

#define SPS_BAM_OPT_IRQ_WAKEUP      (1UL << 3)

#define SPS_BAM_NO_EXT_P_RST        (1UL << 4)

#define SPS_BAM_NO_LOCAL_CLK_GATING (1UL << 5)

#define SPS_BAM_CANCEL_WB           (1UL << 6)

#define SPS_BAM_SMMU_EN             (1UL << 9)

#define SPS_BAM_RES_CONFIRM         (1UL << 7)

#define SPS_BAM_HOLD_MEM            (1UL << 8)

#define SPS_BAM_CACHED_WP           (1UL << 10)




#define SPS_BAM_MGR_DEVICE_REMOTE   1UL

#define SPS_BAM_MGR_MULTI_EE        (1UL << 1)

#define SPS_BAM_MGR_PIPE_NO_ALLOC   (1UL << 2)

#define SPS_BAM_MGR_PIPE_NO_CONFIG  (1UL << 3)

#define SPS_BAM_MGR_PIPE_NO_CTRL    (1UL << 4)

#define SPS_BAM_MGR_NONE            \
	(SPS_BAM_MGR_DEVICE_REMOTE | SPS_BAM_MGR_PIPE_NO_ALLOC | \
	 SPS_BAM_MGR_PIPE_NO_CONFIG | SPS_BAM_MGR_PIPE_NO_CTRL)
#define SPS_BAM_MGR_LOCAL           0
#define SPS_BAM_MGR_LOCAL_SHARED    SPS_BAM_MGR_MULTI_EE
#define SPS_BAM_MGR_REMOTE_SHARED   \
	(SPS_BAM_MGR_DEVICE_REMOTE | SPS_BAM_MGR_MULTI_EE | \
	 SPS_BAM_MGR_PIPE_NO_ALLOC)
#define SPS_BAM_MGR_ACCESS_MASK     SPS_BAM_MGR_NONE


#define SPS_BAM_NUM_EES             4
#define SPS_BAM_SEC_DO_NOT_CONFIG   0
#define SPS_BAM_SEC_DO_CONFIG       0x0A434553


#define SPS_BAM_PIPE(n)             (1UL << (n))


enum sps_mode {
	SPS_MODE_SRC = 0,  
	SPS_MODE_DEST,	   
};



enum sps_option {
	
	SPS_O_DESC_DONE = 0x00000001,  
	SPS_O_INACTIVE  = 0x00000002,  
	SPS_O_WAKEUP    = 0x00000004,  
	SPS_O_OUT_OF_DESC = 0x00000008,
	SPS_O_ERROR     = 0x00000010,  
	SPS_O_EOT       = 0x00000020,  
	SPS_O_RST_ERROR = 0x00000040,  
	SPS_O_HRESP_ERROR = 0x00000080,

	
	SPS_O_STREAMING = 0x00010000,  
	
	SPS_O_IRQ_MTI   = 0x00020000,
	
	SPS_O_WRITE_NWD   = 0x00040000,
       
	SPS_O_LATE_EOT   = 0x00080000,

	
	
	SPS_O_NO_DISABLE      = 0x00800000,
	
	SPS_O_POLL      = 0x01000000,
	
	SPS_O_NO_Q      = 0x02000000,
	SPS_O_FLOWOFF   = 0x04000000,  
	
	SPS_O_WAKEUP_IS_ONESHOT = 0x08000000,
	
	SPS_O_ACK_TRANSFERS = 0x10000000,
	
	SPS_O_AUTO_ENABLE = 0x20000000,
	
	SPS_O_NO_EP_SYNC = 0x40000000,
	
	SPS_O_HYBRID = 0x80000000,
};


enum sps_dma_priority {
	SPS_DMA_PRI_DEFAULT = 0,
	SPS_DMA_PRI_LOW,
	SPS_DMA_PRI_MED,
	SPS_DMA_PRI_HIGH,
};


enum sps_owner {
	SPS_OWNER_LOCAL = 0x1,	
	SPS_OWNER_REMOTE = 0x2,	
};


enum sps_event {
	SPS_EVENT_INVALID = 0,

	SPS_EVENT_EOT,		
	SPS_EVENT_DESC_DONE,	
	SPS_EVENT_OUT_OF_DESC,	
	SPS_EVENT_WAKEUP,	
	SPS_EVENT_FLOWOFF,	
	SPS_EVENT_INACTIVE,	
	SPS_EVENT_ERROR,	
	SPS_EVENT_RST_ERROR,    
	SPS_EVENT_HRESP_ERROR,  
	SPS_EVENT_MAX,
};


enum sps_trigger {
	
	SPS_TRIGGER_CALLBACK = 0,
	
	SPS_TRIGGER_WAIT,
};


enum sps_flow_off {
	SPS_FLOWOFF_FORCED = 0,	
	
	SPS_FLOWOFF_GRACEFUL,
};


enum sps_mem {
	SPS_MEM_LOCAL = 0,  
	SPS_MEM_UC,	    
};


enum sps_timer_op {
	SPS_TIMER_OP_CONFIG = 0,
	SPS_TIMER_OP_RESET,


	SPS_TIMER_OP_READ,
};


enum sps_timer_mode {
	SPS_TIMER_MODE_ONESHOT = 0,

};


enum sps_callback_case {
	SPS_CALLBACK_BAM_ERROR_IRQ = 1,     
	SPS_CALLBACK_BAM_HRESP_ERR_IRQ,	    
	SPS_CALLBACK_BAM_TIMER_IRQ,	    
	SPS_CALLBACK_BAM_RES_REQ,	    
	SPS_CALLBACK_BAM_RES_REL,	    
	SPS_CALLBACK_BAM_POLL,	            
};


enum sps_command_type {
	SPS_WRITE_COMMAND = 0,
	SPS_READ_COMMAND,
};


struct msm_sps_platform_data {
	u32 bamdma_restricted_pipes;
};


struct sps_iovec {
	u32 addr;
	u32 size:16;
	u32 flags:16;
};


struct sps_command_element {
	u32 addr:24;
	u32 command:8;
	u32 data;
	u32 mask;
	u32 reserved;
};


struct sps_bam_pipe_sec_config_props {
	u32 pipe_mask;
	u32 vmid;
};

struct sps_bam_sec_config_props {
	
	struct sps_bam_pipe_sec_config_props ees[SPS_BAM_NUM_EES];
};


struct sps_bam_props {

	

	u32 options;
	phys_addr_t phys_addr;
	void __iomem *virt_addr;
	u32 virt_size;
	u32 irq;
	u32 num_pipes;
	u32 summing_threshold;

	

	u32 periph_class;
	u32 periph_dev_id;
	phys_addr_t periph_phys_addr;
	void *periph_virt_addr;
	u32 periph_virt_size;

	

	u32 event_threshold;
	u32 desc_size;
	u32 data_size;
	u32 desc_mem_id;
	u32 data_mem_id;

	
	void (*callback)(enum sps_callback_case, void *user);
	void *user;

	

	u32 manage;
	u32 restricted_pipes;
	u32 ee;

	
	u32 ipc_loglevel;

	

	u32 irq_gen_addr;

	

	u32 sec_config;
	struct sps_bam_sec_config_props *p_sec_config_props;

	

	bool constrained_logging;
	u32 logging_number;
};


struct sps_mem_buffer {
	void *base;
	phys_addr_t phys_base;
	unsigned long iova;
	u32 size;
	u32 min_size;
};


struct sps_connect {
	unsigned long source;
	unsigned long source_iova;
	u32 src_pipe_index;
	unsigned long destination;
	unsigned long dest_iova;
	u32 dest_pipe_index;

	enum sps_mode mode;

	u32 config;

	enum sps_option options;

	struct sps_mem_buffer desc;
	struct sps_mem_buffer data;

	u32 event_thresh;

	u32 lock_group;

	

	u32 irq_gen_addr;
	u32 irq_gen_data;

	u32 sps_reserved;

};


struct sps_satellite {
	
	phys_addr_t dev;
	u32 pipe_index;

	
	u32 config;
	enum sps_option options;

};


struct sps_alloc_dma_chan {
	unsigned long dev;

	

	u32 threshold;
	enum sps_dma_priority priority;

	
	u32 src_owner;
	u32 dest_owner;

};


struct sps_dma_chan {
	unsigned long dev;
	u32 dest_pipe_index;
	u32 src_pipe_index;
};


struct sps_event_notify {
	void *user;

	enum sps_event event_id;

	

	union {
		
		struct {
			u32 mask;
		} irq;

		

		struct {
			struct sps_iovec iovec;
			void *user;
		} transfer;

		

		struct {
			u32 status;
		} err;

	} data;
};


struct sps_register_event {
	enum sps_option options;
	enum sps_trigger mode;
	struct completion *xfer_done;
	void (*callback)(struct sps_event_notify *notify);
	void *user;
};


struct sps_transfer {
	phys_addr_t iovec_phys;
	struct sps_iovec *iovec;
	u32 iovec_count;
	void *user;
};


struct sps_timer_ctrl {
	enum sps_timer_op op;

	
	enum sps_timer_mode mode;
	u32 timeout_msec;
};


struct sps_timer_result {
	u32 current_timer;
};



struct sps_pipe;	

#ifdef CONFIG_SPS

int sps_register_bam_device(const struct sps_bam_props *bam_props,
			    unsigned long *dev_handle);


int sps_deregister_bam_device(unsigned long dev_handle);


struct sps_pipe *sps_alloc_endpoint(void);


int sps_free_endpoint(struct sps_pipe *h);


int sps_get_config(struct sps_pipe *h, struct sps_connect *config);


int sps_alloc_mem(struct sps_pipe *h, enum sps_mem mem,
		  struct sps_mem_buffer *mem_buffer);


int sps_free_mem(struct sps_pipe *h, struct sps_mem_buffer *mem_buffer);


int sps_connect(struct sps_pipe *h, struct sps_connect *connect);


int sps_disconnect(struct sps_pipe *h);


int sps_register_event(struct sps_pipe *h, struct sps_register_event *reg);


int sps_transfer_one(struct sps_pipe *h, phys_addr_t addr, u32 size,
		     void *user, u32 flags);


int sps_get_event(struct sps_pipe *h, struct sps_event_notify *event);


int sps_get_iovec(struct sps_pipe *h, struct sps_iovec *iovec);


int sps_flow_on(struct sps_pipe *h);


int sps_flow_off(struct sps_pipe *h, enum sps_flow_off mode);


int sps_transfer(struct sps_pipe *h, struct sps_transfer *transfer);


int sps_is_pipe_empty(struct sps_pipe *h, u32 *empty);


int sps_device_reset(unsigned long dev);


int sps_set_config(struct sps_pipe *h, struct sps_connect *config);


int sps_set_owner(struct sps_pipe *h, enum sps_owner owner,
		  struct sps_satellite *connect);

#ifdef CONFIG_SPS_SUPPORT_BAMDMA

int sps_alloc_dma_chan(const struct sps_alloc_dma_chan *alloc,
		       struct sps_dma_chan *chan);


int sps_free_dma_chan(struct sps_dma_chan *chan);


unsigned long sps_dma_get_bam_handle(void);


void sps_dma_free_bam_handle(unsigned long h);
#else
static inline int sps_alloc_dma_chan(const struct sps_alloc_dma_chan *alloc,
		       struct sps_dma_chan *chan)
{
	return -EPERM;
}

static inline int sps_free_dma_chan(struct sps_dma_chan *chan)
{
	return -EPERM;
}

static inline unsigned long sps_dma_get_bam_handle(void)
{
	return 0;
}

static inline void sps_dma_free_bam_handle(unsigned long h)
{
}
#endif


int sps_get_free_count(struct sps_pipe *h, u32 *count);


int sps_timer_ctrl(struct sps_pipe *h,
		   struct sps_timer_ctrl *timer_ctrl,
		   struct sps_timer_result *timer_result);


int sps_phy2h(phys_addr_t phys_addr, unsigned long *handle);


int sps_setup_bam2bam_fifo(struct sps_mem_buffer *mem_buffer,
		  u32 addr, u32 size, int use_offset);


int sps_get_unused_desc_num(struct sps_pipe *h, u32 *desc_num);


int sps_get_bam_debug_info(unsigned long dev, u32 option, u32 para,
		u32 tb_sel, u32 desc_sel);


int sps_ctrl_bam_dma_clk(bool clk_on);


int sps_pipe_reset(unsigned long dev, u32 pipe);


int sps_pipe_disable(unsigned long dev, u32 pipe);


int sps_pipe_pending_desc(unsigned long dev, u32 pipe, bool *pending);


int sps_bam_process_irq(unsigned long dev);


int sps_get_bam_addr(unsigned long dev, phys_addr_t *base,
				u32 *size);


int sps_pipe_inject_zlt(unsigned long dev, u32 pipe_index);
#else
static inline int sps_register_bam_device(const struct sps_bam_props
			*bam_props, unsigned long *dev_handle)
{
	return -EPERM;
}

static inline int sps_deregister_bam_device(unsigned long dev_handle)
{
	return -EPERM;
}

static inline struct sps_pipe *sps_alloc_endpoint(void)
{
	return NULL;
}

static inline int sps_free_endpoint(struct sps_pipe *h)
{
	return -EPERM;
}

static inline int sps_get_config(struct sps_pipe *h, struct sps_connect *config)
{
	return -EPERM;
}

static inline int sps_alloc_mem(struct sps_pipe *h, enum sps_mem mem,
		  struct sps_mem_buffer *mem_buffer)
{
	return -EPERM;
}

static inline int sps_free_mem(struct sps_pipe *h,
				struct sps_mem_buffer *mem_buffer)
{
	return -EPERM;
}

static inline int sps_connect(struct sps_pipe *h, struct sps_connect *connect)
{
	return -EPERM;
}

static inline int sps_disconnect(struct sps_pipe *h)
{
	return -EPERM;
}

static inline int sps_register_event(struct sps_pipe *h,
					struct sps_register_event *reg)
{
	return -EPERM;
}

static inline int sps_transfer_one(struct sps_pipe *h, phys_addr_t addr,
					u32 size, void *user, u32 flags)
{
	return -EPERM;
}

static inline int sps_get_event(struct sps_pipe *h,
				struct sps_event_notify *event)
{
	return -EPERM;
}

static inline int sps_get_iovec(struct sps_pipe *h, struct sps_iovec *iovec)
{
	return -EPERM;
}

static inline int sps_flow_on(struct sps_pipe *h)
{
	return -EPERM;
}

static inline int sps_flow_off(struct sps_pipe *h, enum sps_flow_off mode)
{
	return -EPERM;
}

static inline int sps_transfer(struct sps_pipe *h,
				struct sps_transfer *transfer)
{
	return -EPERM;
}

static inline int sps_is_pipe_empty(struct sps_pipe *h, u32 *empty)
{
	return -EPERM;
}

static inline int sps_device_reset(unsigned long dev)
{
	return -EPERM;
}

static inline int sps_set_config(struct sps_pipe *h, struct sps_connect *config)
{
	return -EPERM;
}

static inline int sps_set_owner(struct sps_pipe *h, enum sps_owner owner,
		  struct sps_satellite *connect)
{
	return -EPERM;
}

static inline int sps_get_free_count(struct sps_pipe *h, u32 *count)
{
	return -EPERM;
}

static inline int sps_alloc_dma_chan(const struct sps_alloc_dma_chan *alloc,
		       struct sps_dma_chan *chan)
{
	return -EPERM;
}

static inline int sps_free_dma_chan(struct sps_dma_chan *chan)
{
	return -EPERM;
}

static inline unsigned long sps_dma_get_bam_handle(void)
{
	return 0;
}

static inline void sps_dma_free_bam_handle(unsigned long h)
{
}

static inline int sps_timer_ctrl(struct sps_pipe *h,
		   struct sps_timer_ctrl *timer_ctrl,
		   struct sps_timer_result *timer_result)
{
	return -EPERM;
}

static inline int sps_phy2h(phys_addr_t phys_addr, unsigned long *handle)
{
	return -EPERM;
}

static inline int sps_setup_bam2bam_fifo(struct sps_mem_buffer *mem_buffer,
		  u32 addr, u32 size, int use_offset)
{
	return -EPERM;
}

static inline int sps_get_unused_desc_num(struct sps_pipe *h, u32 *desc_num)
{
	return -EPERM;
}

static inline int sps_get_bam_debug_info(unsigned long dev, u32 option,
		u32 para, u32 tb_sel, u32 desc_sel)
{
	return -EPERM;
}

static inline int sps_ctrl_bam_dma_clk(bool clk_on)
{
	return -EPERM;
}

static inline int sps_pipe_reset(unsigned long dev, u32 pipe)
{
	return -EPERM;
}

static inline int sps_pipe_disable(unsigned long dev, u32 pipe)
{
	return -EPERM;
}

static inline int sps_pipe_pending_desc(unsigned long dev, u32 pipe,
					bool *pending)
{
	return -EPERM;
}

static inline int sps_bam_process_irq(unsigned long dev)
{
	return -EPERM;
}

static inline int sps_get_bam_addr(unsigned long dev, phys_addr_t *base,
				u32 *size)
{
	return -EPERM;
}

static inline int sps_pipe_inject_zlt(unsigned long dev, u32 pipe_index)
{
	return -EPERM;
}
#endif

#endif 
