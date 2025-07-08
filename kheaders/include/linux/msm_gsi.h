/* SPDX-License-Identifier: GPL-2.0 */


#ifndef MSM_GSI_H
#define MSM_GSI_H
#include <linux/types.h>
#include <linux/interrupt.h>

enum gsi_ver {
	GSI_VER_ERR = 0,
	GSI_VER_1_0 = 1,
	GSI_VER_1_2 = 2,
	GSI_VER_1_3 = 3,
	GSI_VER_2_0 = 4,
	GSI_VER_2_2 = 5,
	GSI_VER_2_5 = 6,
	GSI_VER_2_7 = 7,
	GSI_VER_MAX,
};

enum gsi_status {
	GSI_STATUS_SUCCESS = 0,
	GSI_STATUS_ERROR = 1,
	GSI_STATUS_RING_INSUFFICIENT_SPACE = 2,
	GSI_STATUS_RING_EMPTY = 3,
	GSI_STATUS_RES_ALLOC_FAILURE = 4,
	GSI_STATUS_BAD_STATE = 5,
	GSI_STATUS_INVALID_PARAMS = 6,
	GSI_STATUS_UNSUPPORTED_OP = 7,
	GSI_STATUS_NODEV = 8,
	GSI_STATUS_POLL_EMPTY = 9,
	GSI_STATUS_EVT_RING_INCOMPATIBLE = 10,
	GSI_STATUS_TIMED_OUT = 11,
	GSI_STATUS_AGAIN = 12,
	GSI_STATUS_PENDING_IRQ = 13,
};

enum gsi_per_evt {
	GSI_PER_EVT_GLOB_ERROR,
	GSI_PER_EVT_GLOB_GP1,
	GSI_PER_EVT_GLOB_GP2,
	GSI_PER_EVT_GLOB_GP3,
	GSI_PER_EVT_GENERAL_BREAK_POINT,
	GSI_PER_EVT_GENERAL_BUS_ERROR,
	GSI_PER_EVT_GENERAL_CMD_FIFO_OVERFLOW,
	GSI_PER_EVT_GENERAL_MCS_STACK_OVERFLOW,
};


struct gsi_per_notify {
	void *user_data;
	enum gsi_per_evt evt_id;
	union {
		uint16_t err_desc;
	} data;
};

enum gsi_intr_type {
	GSI_INTR_MSI = 0x0,
	GSI_INTR_IRQ = 0x1
};



struct gsi_per_props {
	enum gsi_ver ver;
	unsigned int ee;
	enum gsi_intr_type intr;
	uint32_t intvec;
	uint64_t msi_addr;
	unsigned int irq;
	phys_addr_t phys_addr;
	unsigned long size;
	phys_addr_t emulator_intcntrlr_addr;
	unsigned long emulator_intcntrlr_size;
	irq_handler_t emulator_intcntrlr_client_isr;
	bool mhi_er_id_limits_valid;
	uint32_t mhi_er_id_limits[2];
	void (*notify_cb)(struct gsi_per_notify *notify);
	void (*req_clk_cb)(void *user_data, bool *granted);
	int (*rel_clk_cb)(void *user_data);
	void *user_data;
	int (*clk_status_cb)(void);
	void (*enable_clk_bug_on)(void);
	bool skip_ieob_mask_wa;
};

enum gsi_evt_err {
	GSI_EVT_OUT_OF_BUFFERS_ERR = 0x0,
	GSI_EVT_OUT_OF_RESOURCES_ERR = 0x1,
	GSI_EVT_UNSUPPORTED_INTER_EE_OP_ERR = 0x2,
	GSI_EVT_EVT_RING_EMPTY_ERR = 0x3,
};


struct gsi_evt_err_notify {
	void *user_data;
	enum gsi_evt_err evt_id;
	uint16_t err_desc;
};

enum gsi_evt_chtype {
	GSI_EVT_CHTYPE_MHI_EV = 0x0,
	GSI_EVT_CHTYPE_XHCI_EV = 0x1,
	GSI_EVT_CHTYPE_GPI_EV = 0x2,
	GSI_EVT_CHTYPE_XDCI_EV = 0x3,
	GSI_EVT_CHTYPE_WDI2_EV = 0x4,
	GSI_EVT_CHTYPE_GCI_EV = 0x5,
	GSI_EVT_CHTYPE_WDI3_EV = 0x6,
	GSI_EVT_CHTYPE_MHIP_EV = 0x7,
	GSI_EVT_CHTYPE_AQC_EV = 0x8,
	GSI_EVT_CHTYPE_11AD_EV = 0x9,
};

enum gsi_evt_ring_elem_size {
	GSI_EVT_RING_RE_SIZE_4B = 4,
	GSI_EVT_RING_RE_SIZE_8B = 8,
	GSI_EVT_RING_RE_SIZE_16B = 16,
};


struct gsi_evt_ring_props {
	enum gsi_evt_chtype intf;
	enum gsi_intr_type intr;
	enum gsi_evt_ring_elem_size re_size;
	uint16_t ring_len;
	uint64_t ring_base_addr;
	void *ring_base_vaddr;
	uint16_t int_modt;
	uint8_t int_modc;
	uint32_t intvec;
	uint64_t msi_addr;
	uint64_t rp_update_addr;
	bool exclusive;
	void (*err_cb)(struct gsi_evt_err_notify *notify);
	void *user_data;
	bool evchid_valid;
	uint8_t evchid;
};

enum gsi_chan_mode {
	GSI_CHAN_MODE_CALLBACK = 0x0,
	GSI_CHAN_MODE_POLL = 0x1,
};

enum gsi_chan_prot {
	GSI_CHAN_PROT_MHI = 0x0,
	GSI_CHAN_PROT_XHCI = 0x1,
	GSI_CHAN_PROT_GPI = 0x2,
	GSI_CHAN_PROT_XDCI = 0x3,
	GSI_CHAN_PROT_WDI2 = 0x4,
	GSI_CHAN_PROT_GCI = 0x5,
	GSI_CHAN_PROT_WDI3 = 0x6,
	GSI_CHAN_PROT_MHIP = 0x7,
	GSI_CHAN_PROT_AQC = 0x8,
	GSI_CHAN_PROT_11AD = 0x9,
};

enum gsi_chan_dir {
	GSI_CHAN_DIR_FROM_GSI = 0x0,
	GSI_CHAN_DIR_TO_GSI = 0x1
};

enum gsi_max_prefetch {
	GSI_ONE_PREFETCH_SEG = 0x0,
	GSI_TWO_PREFETCH_SEG = 0x1
};


enum gsi_prefetch_mode {
	GSI_USE_PREFETCH_BUFS = 0x0,
	GSI_ESCAPE_BUF_ONLY = 0x1,
	GSI_SMART_PRE_FETCH = 0x2,
	GSI_FREE_PRE_FETCH = 0x3,
};

enum gsi_chan_evt {
	GSI_CHAN_EVT_INVALID = 0x0,
	GSI_CHAN_EVT_SUCCESS = 0x1,
	GSI_CHAN_EVT_EOT = 0x2,
	GSI_CHAN_EVT_OVERFLOW = 0x3,
	GSI_CHAN_EVT_EOB = 0x4,
	GSI_CHAN_EVT_OOB = 0x5,
	GSI_CHAN_EVT_DB_MODE = 0x6,
	GSI_CHAN_EVT_UNDEFINED = 0x10,
	GSI_CHAN_EVT_RE_ERROR = 0x11,
};


enum gsi_chan_xfer_veid {
	GSI_VEID_0 = 0,
	GSI_VEID_1 = 1,
	GSI_VEID_2 = 2,
	GSI_VEID_3 = 3,
	GSI_VEID_DEFAULT,
	GSI_VEID_MAX
};


struct gsi_chan_xfer_notify {
	void *chan_user_data;
	void *xfer_user_data;
	enum gsi_chan_evt evt_id;
	uint16_t bytes_xfered;
	uint8_t veid;
};

enum gsi_chan_err {
	GSI_CHAN_INVALID_TRE_ERR = 0x0,
	GSI_CHAN_NON_ALLOCATED_EVT_ACCESS_ERR = 0x1,
	GSI_CHAN_OUT_OF_BUFFERS_ERR = 0x2,
	GSI_CHAN_OUT_OF_RESOURCES_ERR = 0x3,
	GSI_CHAN_UNSUPPORTED_INTER_EE_OP_ERR = 0x4,
	GSI_CHAN_HWO_1_ERR = 0x5
};


struct gsi_chan_err_notify {
	void *chan_user_data;
	enum gsi_chan_err evt_id;
	uint16_t err_desc;
};

enum gsi_chan_ring_elem_size {
	GSI_CHAN_RE_SIZE_4B = 4,
	GSI_CHAN_RE_SIZE_8B = 8,
	GSI_CHAN_RE_SIZE_16B = 16,
	GSI_CHAN_RE_SIZE_32B = 32,
};

enum gsi_chan_use_db_eng {
	GSI_CHAN_DIRECT_MODE = 0x0,
	GSI_CHAN_DB_MODE = 0x1,
};


struct gsi_chan_props {
	enum gsi_chan_prot prot;
	enum gsi_chan_dir dir;
	uint8_t ch_id;
	unsigned long evt_ring_hdl;
	enum gsi_chan_ring_elem_size re_size;
	uint16_t ring_len;
	uint16_t max_re_expected;
	uint64_t ring_base_addr;
	void *ring_base_vaddr;
	enum gsi_chan_use_db_eng use_db_eng;
	enum gsi_max_prefetch max_prefetch;
	uint8_t low_weight;
	enum gsi_prefetch_mode prefetch_mode;
	uint8_t empty_lvl_threshold;
	void (*xfer_cb)(struct gsi_chan_xfer_notify *notify);
	void (*err_cb)(struct gsi_chan_err_notify *notify);
	void (*cleanup_cb)(void *chan_user_data, void *xfer_user_data);
	void *chan_user_data;
};

enum gsi_xfer_flag {
	GSI_XFER_FLAG_CHAIN = 0x1,
	GSI_XFER_FLAG_EOB = 0x100,
	GSI_XFER_FLAG_EOT = 0x200,
	GSI_XFER_FLAG_BEI = 0x400
};

enum gsi_xfer_elem_type {
	GSI_XFER_ELEM_DATA,
	GSI_XFER_ELEM_IMME_CMD,
	GSI_XFER_ELEM_NOP,
};


struct gsi_xfer_elem {
	uint64_t addr;
	uint16_t len;
	uint16_t flags;
	enum gsi_xfer_elem_type type;
	void *xfer_user_data;
};


struct __packed gsi_gpi_channel_scratch {
	uint64_t dl_nlo_channel:1; 
	uint64_t resvd1:63;
	uint32_t resvd2:16;
	uint32_t max_outstanding_tre:16; 
	uint32_t resvd3:16;
	uint32_t outstanding_threshold:16; 
};


struct __packed gsi_mhi_channel_scratch {
	uint64_t mhi_host_wp_addr;
	uint32_t rsvd1:1;
	uint32_t assert_bit40:1;
	uint32_t polling_configuration:5;
	uint32_t burst_mode_enabled:1;
	uint32_t polling_mode:1;
	uint32_t oob_mod_threshold:5;
	uint32_t resvd2:2;
	uint32_t max_outstanding_tre:16; 
	uint32_t resvd3:16;
	uint32_t outstanding_threshold:16; 
};


struct __packed gsi_xdci_channel_scratch {
	uint32_t last_trb_addr:16;
	uint32_t resvd1:4;
	uint32_t xferrscidx:7;
	uint32_t const_buffer_size:5;
	uint32_t depcmd_low_addr;
	uint32_t depcmd_hi_addr:8;
	uint32_t resvd2:8;
	uint32_t max_outstanding_tre:16; 
	uint32_t resvd3:16;
	uint32_t outstanding_threshold:16; 
};


struct __packed gsi_wdi_channel_scratch {
	uint32_t wifi_rx_ri_addr_low;
	uint32_t wifi_rx_ri_addr_high;
	uint32_t update_ri_moderation_threshold:5;
	uint32_t update_ri_moderation_counter:6;
	uint32_t wdi_rx_tre_proc_in_progress:1;
	uint32_t resv1:4;
	uint32_t wdi_rx_vdev_id:8;
	uint32_t wdi_rx_fw_desc:8;
	uint32_t endp_metadatareg_offset:16;
	uint32_t qmap_id:16;
	uint32_t wdi_rx_pkt_length:16;
	uint32_t resv2:2;
	uint32_t pkt_comp_count:11;
	uint32_t stop_in_progress_stm:3;
	uint32_t resv3:16;
	uint32_t wdi_rx_qmap_id_internal:16;
};


struct __packed gsi_wdi2_channel_scratch_new {
	uint32_t wifi_rx_ri_addr_low;
	uint32_t wifi_rx_ri_addr_high;
	uint32_t update_ri_moderation_threshold:5;
	uint32_t qmap_id:8;
	uint32_t resv1:3;
	uint32_t endp_metadatareg_offset:16;
	uint32_t wdi_rx_vdev_id:8;
	uint32_t wdi_rx_fw_desc:8;
	uint32_t update_ri_moderation_counter:6;
	uint32_t wdi_rx_tre_proc_in_progress:1;
	uint32_t resv4:1;
	uint32_t outstanding_tlvs_counter:8;
	uint32_t wdi_rx_pkt_length:16;
	uint32_t resv2:2;
	uint32_t pkt_comp_count:11;
	uint32_t stop_in_progress_stm:3;
	uint32_t resv3:16;
	uint32_t wdi_rx_qmap_id_internal:16;
};

struct __packed gsi_mhip_channel_scratch {
	uint32_t assert_bit_40:1;
	uint32_t host_channel:1;
	uint32_t resvd1:30;
};


struct __packed gsi_11ad_rx_channel_scratch {
	uint32_t status_ring_hwtail_address_lsb;
	uint32_t status_ring_hwtail_address_msb;
	uint32_t data_buffers_base_address_lsb;
	uint32_t data_buffers_base_address_msb:8;
	uint32_t fixed_data_buffer_size_pow_2:16;
	uint32_t resv1:8;
};


struct __packed gsi_11ad_tx_channel_scratch {
	uint32_t status_ring_hwtail_address_lsb;
	uint32_t status_ring_hwhead_address_lsb;
	uint32_t status_ring_hwhead_hwtail_8_msb:8;
	uint32_t update_status_hwtail_mod_threshold:8;
	uint32_t status_ring_num_elem:16;
	uint32_t resv1:8;
	uint32_t fixed_data_buffer_size_pow_2:16;
	uint32_t resv2:8;
};


struct __packed gsi_wdi3_channel_scratch {
	uint32_t wifi_rp_address_low;
	uint32_t wifi_rp_address_high;
	uint32_t update_rp_moderation_threshold : 5;
	uint32_t qmap_id : 8;
	uint32_t reserved1 : 3;
	uint32_t endp_metadata_reg_offset : 16;
	uint32_t rx_pkt_offset : 16;
	uint32_t reserved2 : 16;
};


union __packed gsi_channel_scratch {
	struct __packed gsi_gpi_channel_scratch gpi;
	struct __packed gsi_mhi_channel_scratch mhi;
	struct __packed gsi_xdci_channel_scratch xdci;
	struct __packed gsi_wdi_channel_scratch wdi;
	struct __packed gsi_11ad_rx_channel_scratch rx_11ad;
	struct __packed gsi_11ad_tx_channel_scratch tx_11ad;
	struct __packed gsi_wdi3_channel_scratch wdi3;
	struct __packed gsi_mhip_channel_scratch mhip;
	struct __packed gsi_wdi2_channel_scratch_new wdi2_new;
	struct __packed {
		uint32_t word1;
		uint32_t word2;
		uint32_t word3;
		uint32_t word4;
	} data;
};



struct __packed gsi_wdi_channel_scratch3 {
	uint32_t endp_metadatareg_offset:16;
	uint32_t qmap_id:16;
};



union __packed gsi_wdi_channel_scratch3_reg {
	struct __packed gsi_wdi_channel_scratch3 wdi;
	struct __packed {
		uint32_t word1;
	} data;
};



struct __packed gsi_wdi2_channel_scratch2 {
	uint32_t update_ri_moderation_threshold:5;
	uint32_t qmap_id:8;
	uint32_t resv1:3;
	uint32_t endp_metadatareg_offset:16;
};



union __packed gsi_wdi2_channel_scratch2_reg {
	struct __packed gsi_wdi2_channel_scratch2 wdi;
	struct __packed {
		uint32_t word1;
	} data;
};


struct __packed gsi_mhi_evt_scratch {
	uint32_t resvd1;
	uint32_t resvd2;
};


struct __packed gsi_mhip_evt_scratch {
	uint32_t rp_mod_threshold:8;
	uint32_t rp_mod_timer:4;
	uint32_t rp_mod_counter:8;
	uint32_t rp_mod_timer_id:4;
	uint32_t rp_mod_timer_running:1;
	uint32_t resvd1:7;
	uint32_t fixed_buffer_sz:16;
	uint32_t resvd2:16;
};



struct __packed gsi_xdci_evt_scratch {
	uint32_t gevntcount_low_addr;
	uint32_t gevntcount_hi_addr:8;
	uint32_t resvd1:24;
};



struct __packed gsi_wdi_evt_scratch {
	uint32_t update_ri_moderation_config:8;
	uint32_t resvd1:8;
	uint32_t update_ri_mod_timer_running:1;
	uint32_t evt_comp_count:14;
	uint32_t resvd2:1;
	uint32_t last_update_ri:16;
	uint32_t resvd3:16;
};


struct __packed gsi_11ad_evt_scratch {
	uint32_t update_status_hwtail_mod_threshold : 8;
	uint32_t resvd1:8;
	uint32_t resvd2:16;
	uint32_t resvd3;
};


struct __packed gsi_wdi3_evt_scratch {
	uint32_t update_rp_moderation_config : 8;
	uint32_t reserved1 : 24;
	uint32_t reserved2;
};


union __packed gsi_evt_scratch {
	struct __packed gsi_mhi_evt_scratch mhi;
	struct __packed gsi_xdci_evt_scratch xdci;
	struct __packed gsi_wdi_evt_scratch wdi;
	struct __packed gsi_11ad_evt_scratch w11ad;
	struct __packed gsi_wdi3_evt_scratch wdi3;
	struct __packed gsi_mhip_evt_scratch mhip;
	struct __packed {
		uint32_t word1;
		uint32_t word2;
	} data;
};


struct gsi_device_scratch {
	bool mhi_base_chan_idx_valid;
	uint8_t mhi_base_chan_idx;
	bool max_usb_pkt_size_valid;
	uint16_t max_usb_pkt_size;
};


struct gsi_chan_info {
	uint64_t wp;
	uint64_t rp;
	bool evt_valid;
	uint64_t evt_wp;
	uint64_t evt_rp;
};

#ifdef CONFIG_GSI

int gsi_register_device(struct gsi_per_props *props, unsigned long *dev_hdl);


int gsi_complete_clk_grant(unsigned long dev_hdl);


int gsi_write_device_scratch(unsigned long dev_hdl,
		struct gsi_device_scratch *val);


int gsi_deregister_device(unsigned long dev_hdl, bool force);


int gsi_alloc_evt_ring(struct gsi_evt_ring_props *props, unsigned long dev_hdl,
		unsigned long *evt_ring_hdl);


int gsi_write_evt_ring_scratch(unsigned long evt_ring_hdl,
		union __packed gsi_evt_scratch val);


int gsi_dealloc_evt_ring(unsigned long evt_ring_hdl);


int gsi_query_evt_ring_db_addr(unsigned long evt_ring_hdl,
		uint32_t *db_addr_wp_lsb, uint32_t *db_addr_wp_msb);


int gsi_ring_evt_ring_db(unsigned long evt_ring_hdl, uint64_t value);


int gsi_ring_ch_ring_db(unsigned long chan_hdl, uint64_t value);


int gsi_reset_evt_ring(unsigned long evt_ring_hdl);


int gsi_get_evt_ring_cfg(unsigned long evt_ring_hdl,
		struct gsi_evt_ring_props *props, union gsi_evt_scratch *scr);


int gsi_set_evt_ring_cfg(unsigned long evt_ring_hdl,
		struct gsi_evt_ring_props *props, union gsi_evt_scratch *scr);


int gsi_alloc_channel(struct gsi_chan_props *props, unsigned long dev_hdl,
		unsigned long *chan_hdl);


int gsi_write_channel_scratch(unsigned long chan_hdl,
		union __packed gsi_channel_scratch val);


int gsi_write_channel_scratch3_reg(unsigned long chan_hdl,
		union __packed gsi_wdi_channel_scratch3_reg val);


int gsi_write_channel_scratch2_reg(unsigned long chan_hdl,
		union __packed gsi_wdi2_channel_scratch2_reg val);


int gsi_read_channel_scratch(unsigned long chan_hdl,
		union __packed gsi_channel_scratch *val);


int gsi_pending_irq_type(void);


int gsi_update_mhi_channel_scratch(unsigned long chan_hdl,
		struct __packed gsi_mhi_channel_scratch mscr);


int gsi_start_channel(unsigned long chan_hdl);


int gsi_stop_channel(unsigned long chan_hdl);


int gsi_reset_channel(unsigned long chan_hdl);


int gsi_dealloc_channel(unsigned long chan_hdl);


int gsi_stop_db_channel(unsigned long chan_hdl);


int gsi_query_channel_db_addr(unsigned long chan_hdl,
		uint32_t *db_addr_wp_lsb, uint32_t *db_addr_wp_msb);


int gsi_query_channel_info(unsigned long chan_hdl,
		struct gsi_chan_info *info);


int gsi_is_channel_empty(unsigned long chan_hdl, bool *is_empty);


int gsi_get_channel_cfg(unsigned long chan_hdl, struct gsi_chan_props *props,
		union gsi_channel_scratch *scr);


int gsi_set_channel_cfg(unsigned long chan_hdl, struct gsi_chan_props *props,
		union gsi_channel_scratch *scr);


int gsi_poll_channel(unsigned long chan_hdl,
		struct gsi_chan_xfer_notify *notify);



int gsi_poll_n_channel(unsigned long chan_hdl,
		struct gsi_chan_xfer_notify *notify,
		int expected_num, int *actual_num);



int gsi_config_channel_mode(unsigned long chan_hdl, enum gsi_chan_mode mode);


int gsi_queue_xfer(unsigned long chan_hdl, uint16_t num_xfers,
		struct gsi_xfer_elem *xfer, bool ring_db);


int gsi_start_xfer(unsigned long chan_hdl);


int gsi_configure_regs(phys_addr_t per_base_addr, enum gsi_ver ver);


int gsi_enable_fw(phys_addr_t gsi_base_addr, u32 gsi_size, enum gsi_ver ver);


void gsi_get_inst_ram_offset_and_size(unsigned long *base_offset,
		unsigned long *size, enum gsi_ver ver);


int gsi_halt_channel_ee(unsigned int chan_idx, unsigned int ee, int *code);


void gsi_wdi3_write_evt_ring_db(unsigned long chan_hdl, uint32_t db_addr_low,
	uint32_t db_addr_high);



void gsi_wdi3_dump_register(unsigned long chan_hdl);



int gsi_map_base(phys_addr_t gsi_base_addr, u32 gsi_size);


int gsi_unmap_base(void);


int gsi_map_virtual_ch_to_per_ep(u32 ee, u32 chan_num, u32 per_ep_index);


int gsi_alloc_channel_ee(unsigned int chan_idx, unsigned int ee, int *code);


int gsi_enable_flow_control_ee(unsigned int chan_idx, unsigned int ee,
								int *code);


#else
static inline int gsi_register_device(struct gsi_per_props *props,
		unsigned long *dev_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_complete_clk_grant(unsigned long dev_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_write_device_scratch(unsigned long dev_hdl,
		struct gsi_device_scratch *val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_deregister_device(unsigned long dev_hdl, bool force)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_alloc_evt_ring(struct gsi_evt_ring_props *props,
		unsigned long dev_hdl,
		unsigned long *evt_ring_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_write_evt_ring_scratch(unsigned long evt_ring_hdl,
		union __packed gsi_evt_scratch val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_dealloc_evt_ring(unsigned long evt_ring_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_query_evt_ring_db_addr(unsigned long evt_ring_hdl,
		uint32_t *db_addr_wp_lsb, uint32_t *db_addr_wp_msb)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_ring_evt_ring_db(unsigned long evt_ring_hdl,
		uint64_t value)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_ring_ch_ring_db(unsigned long chan_hdl, uint64_t value)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_reset_evt_ring(unsigned long evt_ring_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_alloc_channel(struct gsi_chan_props *props,
		unsigned long dev_hdl,
		unsigned long *chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_write_channel_scratch(unsigned long chan_hdl,
		union __packed gsi_channel_scratch val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}
static inline int gsi_write_channel_scratch3_reg(unsigned long chan_hdl,
		union __packed gsi_wdi_channel_scratch3_reg val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_write_channel_scratch2_reg(unsigned long chan_hdl,
		union __packed gsi_wdi2_channel_scratch2_reg val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_read_channel_scratch(unsigned long chan_hdl,
		union __packed gsi_channel_scratch *val)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_pending_irq_type(void)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_update_mhi_channel_scratch(unsigned long chan_hdl,
		struct __packed gsi_mhi_channel_scratch mscr)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_start_channel(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_stop_channel(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_reset_channel(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_dealloc_channel(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_stop_db_channel(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_query_channel_db_addr(unsigned long chan_hdl,
		uint32_t *db_addr_wp_lsb, uint32_t *db_addr_wp_msb)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_query_channel_info(unsigned long chan_hdl,
		struct gsi_chan_info *info)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_is_channel_empty(unsigned long chan_hdl, bool *is_empty)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_poll_channel(unsigned long chan_hdl,
		struct gsi_chan_xfer_notify *notify)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_poll_n_channel(unsigned long chan_hdl,
		struct gsi_chan_xfer_notify *notify,
		int expected_num, int *actual_num)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_config_channel_mode(unsigned long chan_hdl,
		enum gsi_chan_mode mode)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_queue_xfer(unsigned long chan_hdl, uint16_t num_xfers,
		struct gsi_xfer_elem *xfer, bool ring_db)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_start_xfer(unsigned long chan_hdl)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_get_channel_cfg(unsigned long chan_hdl,
		struct gsi_chan_props *props,
		union gsi_channel_scratch *scr)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_set_channel_cfg(unsigned long chan_hdl,
		struct gsi_chan_props *props,
		union gsi_channel_scratch *scr)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_get_evt_ring_cfg(unsigned long evt_ring_hdl,
		struct gsi_evt_ring_props *props, union gsi_evt_scratch *scr)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_set_evt_ring_cfg(unsigned long evt_ring_hdl,
		struct gsi_evt_ring_props *props, union gsi_evt_scratch *scr)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_configure_regs(
	phys_addr_t per_base_addr, enum gsi_ver ver)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_enable_fw(
	phys_addr_t gsi_base_addr, u32 gsi_size, enum gsi_ver ver)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline void gsi_get_inst_ram_offset_and_size(unsigned long *base_offset,
		unsigned long *size, enum gsi_ver ver)
{
}

static inline int gsi_halt_channel_ee(unsigned int chan_idx, unsigned int ee,
	 int *code)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_map_base(phys_addr_t gsi_base_addr, u32 gsi_size)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_unmap_base(void)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_map_virtual_ch_to_per_ep(
	u32 ee, u32 chan_num, u32 per_ep_index)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_alloc_channel_ee(unsigned int chan_idx, unsigned int ee,
	int *code)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline int gsi_enable_flow_control_ee(unsigned int chan_idx,
			unsigned int ee, int *code)
{
	return -GSI_STATUS_UNSUPPORTED_OP;
}

static inline void gsi_wdi3_write_evt_ring_db(
	unsigned long chan_hdl, uint32_t db_addr_low,
	uint32_t db_addr_high)
{
}

static inline void gsi_wdi3_dump_register(unsigned long chan_hdl)
{
}

#endif
#endif
