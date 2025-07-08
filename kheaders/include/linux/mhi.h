/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _MHI_H_
#define _MHI_H_

struct mhi_chan;
struct mhi_event;
struct mhi_ctxt;
struct mhi_cmd;
struct image_info;
struct bhi_vec_entry;
struct mhi_timesync;
struct mhi_buf_info;
struct mhi_sfr_info;

#define REG_WRITE_QUEUE_LEN 1024


enum MHI_CB {
	MHI_CB_IDLE,
	MHI_CB_PENDING_DATA,
	MHI_CB_DTR_SIGNAL,
	MHI_CB_LPM_ENTER,
	MHI_CB_LPM_EXIT,
	MHI_CB_EE_RDDM,
	MHI_CB_EE_MISSION_MODE,
	MHI_CB_SYS_ERROR,
	MHI_CB_FATAL_ERROR,
	MHI_CB_FW_FALLBACK_IMG,
	MHI_CB_BOOTUP_TIMEOUT,
};


enum MHI_DEBUG_LEVEL {
	MHI_MSG_LVL_VERBOSE,
	MHI_MSG_LVL_INFO,
	MHI_MSG_LVL_ERROR,
	MHI_MSG_LVL_CRITICAL,
	MHI_MSG_LVL_MASK_ALL,
	MHI_MSG_LVL_MAX,
};


enum MHI_FLAGS {
	MHI_EOB,
	MHI_EOT,
	MHI_CHAIN,
};


enum mhi_device_type {
	MHI_XFER_TYPE,
	MHI_TIMESYNC_TYPE,
	MHI_CONTROLLER_TYPE,
};


enum mhi_ee {
	MHI_EE_PBL,
	MHI_EE_SBL,
	MHI_EE_AMSS,
	MHI_EE_RDDM,
	MHI_EE_WFW,
	MHI_EE_PTHRU,
	MHI_EE_EDL,
	MHI_EE_MAX_SUPPORTED = MHI_EE_EDL,
	MHI_EE_DISABLE_TRANSITION, 
	MHI_EE_NOT_SUPPORTED,
	MHI_EE_MAX,
};


enum mhi_dev_state {
	MHI_STATE_RESET = 0x0,
	MHI_STATE_READY = 0x1,
	MHI_STATE_M0 = 0x2,
	MHI_STATE_M1 = 0x3,
	MHI_STATE_M2 = 0x4,
	MHI_STATE_M3 = 0x5,
	MHI_STATE_M3_FAST = 0x6,
	MHI_STATE_BHI  = 0x7,
	MHI_STATE_SYS_ERR  = 0xFF,
	MHI_STATE_MAX,
};

#define MHI_VOTE_BUS BIT(0) 
#define MHI_VOTE_DEVICE BIT(1) 


struct mhi_link_info {
	unsigned int target_link_speed;
	unsigned int target_link_width;
	int sequence_num;
};


struct image_info {
	struct mhi_buf *mhi_buf;
	struct bhi_vec_entry *bhi_vec;
	u32 entries;
};



#define MAX_RDDM_TABLE_SIZE 6


struct rddm_table_info {
	u64 base_address;
	u64 actual_phys_address;
	u64 size;
	char description[20];
	char file_name[20];
};


struct rddm_header {
	u32 version;
	u32 header_size;
	struct rddm_table_info table_info[MAX_RDDM_TABLE_SIZE];
};


struct file_info {
	u8 *file_offset;
	u32 file_size;
	u32 seg_idx;
	u32 rem_seg_len;
};


struct reg_write_info {
	void __iomem *reg_addr;
	u32 val;
	bool valid;
};


struct mhi_controller {
	struct list_head node;
	struct mhi_device *mhi_dev;

	
	struct device *dev;
	struct device_node *of_node;

	
	phys_addr_t base_addr;
	unsigned int len;
	void __iomem *regs;
	void __iomem *bhi;
	void __iomem *bhie;
	void __iomem *wake_db;
	void __iomem *tsync_db;
	void __iomem *bw_scale_db;

	
	u32 dev_id;
	u32 domain;
	u32 bus;
	u32 slot;
	u32 family_number;
	u32 device_number;
	u32 major_version;
	u32 minor_version;

	
	dma_addr_t iova_start;
	dma_addr_t iova_stop;

	
	const char *fw_image;
	const char *fw_image_fallback;
	const char *edl_image;

	
	bool fbc_download;
	bool rddm_supported;
	size_t rddm_size;
	size_t sbl_size;
	size_t seg_len;
	u32 session_id;
	u32 sequence_id;

	bool img_pre_alloc;
	struct image_info *fbc_image;
	struct image_info *rddm_image;

	
	u32 max_chan;
	struct mhi_chan *mhi_chan;
	struct list_head lpm_chans; 

	
	u32 total_ev_rings;
	u32 hw_ev_rings;
	u32 sw_ev_rings;
	u32 msi_required;
	u32 msi_allocated;
	int *irq; 
	struct mhi_event *mhi_event;
	struct list_head sp_ev_rings; 

	
	struct mhi_cmd *mhi_cmd;

	
	struct mhi_ctxt *mhi_ctxt;

	u32 timeout_ms;
	u32 m2_timeout_ms; 

	
	struct mutex pm_mutex;
	struct mutex tsync_mutex;
	bool pre_init;
	rwlock_t pm_lock;
	u32 pm_state;
	u32 saved_pm_state; 
	u32 db_access; 
	enum mhi_ee ee;
	u32 ee_table[MHI_EE_MAX]; 
	enum mhi_dev_state dev_state;
	enum mhi_dev_state saved_dev_state;
	bool wake_set;
	bool ignore_override;
	atomic_t dev_wake;
	atomic_t alloc_size;
	atomic_t pending_pkts;
	struct list_head transition_list;
	spinlock_t transition_lock;
	spinlock_t wlock;

	
	struct mhi_link_info mhi_link_info;

	
	u32 M0, M2, M3, M3_FAST;

	
	struct work_struct st_worker;
	struct work_struct special_work;
	struct workqueue_struct *wq;

	wait_queue_head_t state_event;

	
	void (*status_cb)(struct mhi_controller *mhi_cntrl, void *priv,
			  enum MHI_CB reason);
	int (*link_status)(struct mhi_controller *mhi_cntrl, void *priv);
	void (*wake_get)(struct mhi_controller *mhi_cntrl, bool override);
	void (*wake_put)(struct mhi_controller *mhi_cntrl, bool override);
	void (*wake_toggle)(struct mhi_controller *mhi_cntrl);
	int (*runtime_get)(struct mhi_controller *mhi_cntrl, void *priv);
	void (*runtime_put)(struct mhi_controller *mhi_cntrl, void *priv);
	u64 (*time_get)(struct mhi_controller *mhi_cntrl, void *priv);
	int (*lpm_disable)(struct mhi_controller *mhi_cntrl, void *priv);
	int (*lpm_enable)(struct mhi_controller *mhi_cntrl, void *priv);
	int (*map_single)(struct mhi_controller *mhi_cntrl,
			  struct mhi_buf_info *buf);
	void (*unmap_single)(struct mhi_controller *mhi_cntrl,
			     struct mhi_buf_info *buf);
	void (*tsync_log)(struct mhi_controller *mhi_cntrl, u64 remote_time);
	int (*bw_scale)(struct mhi_controller *mhi_cntrl,
			struct mhi_link_info *link_info);
	void (*write_reg)(struct mhi_controller *mhi_cntrl, void __iomem *base,
			u32 offset, u32 val);

	
	struct mhi_device *dtr_dev;

	
	bool bounce_buf;
	size_t buffer_len;

	
	struct mhi_timesync *mhi_tsync;
	u64 local_timer_freq;
	u64 remote_timer_freq;

	
	struct mhi_sfr_info *mhi_sfr;
	size_t sfr_len;

	
	enum MHI_DEBUG_LEVEL klog_lvl;

	
	enum MHI_DEBUG_LEVEL log_lvl;

	
	const char *name;
	bool power_down;
	bool initiate_mhi_reset;
	void *priv_data;
	void *log_buf;
	void *cntrl_log_buf;
	struct dentry *dentry;
	struct dentry *parent;

	
	struct workqueue_struct *offload_wq;
	struct work_struct reg_write_work;
	struct reg_write_info *reg_write_q;
	atomic_t write_idx;
	u32 read_idx;
};


struct mhi_device {
	struct device dev;
	u32 dev_id;
	u32 domain;
	u32 bus;
	u32 slot;
	size_t mtu;
	int ul_chan_id;
	int dl_chan_id;
	int ul_event_id;
	int dl_event_id;
	u32 tiocm;
	bool early_notif;
	const struct mhi_device_id *id;
	const char *chan_name;
	struct mhi_controller *mhi_cntrl;
	struct mhi_chan *ul_chan;
	struct mhi_chan *dl_chan;
	atomic_t dev_vote;
	atomic_t bus_vote;
	enum mhi_device_type dev_type;
	void *priv_data;
	int (*ul_xfer)(struct mhi_device *mhi_dev, struct mhi_chan *mhi_chan,
		       void *buf, size_t len, enum MHI_FLAGS flags);
	int (*dl_xfer)(struct mhi_device *mhi_dev, struct mhi_chan *mhi_chan,
		       void *buf, size_t size, enum MHI_FLAGS flags);
	void (*status_cb)(struct mhi_device *mhi_dev, enum MHI_CB reason);
};


struct mhi_result {
	void *buf_addr;
	enum dma_data_direction dir;
	size_t bytes_xferd;
	int transaction_status;
};


struct mhi_buf {
	struct list_head node;
	struct page *page;
	void *buf;
	phys_addr_t phys_addr;
	dma_addr_t dma_addr;
	struct sk_buff *skb;
	size_t len;
	const char *name; 
};


struct mhi_driver {
	const struct mhi_device_id *id_table;
	int (*probe)(struct mhi_device *mhi_dev,
		     const struct mhi_device_id *id);
	void (*remove)(struct mhi_device *mhi_dev);
	void (*ul_xfer_cb)(struct mhi_device *mhi_dev, struct mhi_result *res);
	void (*dl_xfer_cb)(struct mhi_device *mhi_dev, struct mhi_result *res);
	void (*status_cb)(struct mhi_device *mhi_dev, enum MHI_CB mhi_cb);
	struct device_driver driver;
};

#define to_mhi_driver(drv) container_of(drv, struct mhi_driver, driver)
#define to_mhi_device(dev) container_of(dev, struct mhi_device, dev)

static inline void mhi_device_set_devdata(struct mhi_device *mhi_dev,
					  void *priv)
{
	mhi_dev->priv_data = priv;
}

static inline void *mhi_device_get_devdata(struct mhi_device *mhi_dev)
{
	return mhi_dev->priv_data;
}


static inline int mhi_queue_transfer(struct mhi_device *mhi_dev,
				     enum dma_data_direction dir,
				     void *buf,
				     size_t len,
				     enum MHI_FLAGS mflags)
{
	if (dir == DMA_TO_DEVICE)
		return mhi_dev->ul_xfer(mhi_dev, mhi_dev->ul_chan, buf, len,
					mflags);
	else
		return mhi_dev->dl_xfer(mhi_dev, mhi_dev->dl_chan, buf, len,
					mflags);
}

static inline void *mhi_controller_get_devdata(struct mhi_controller *mhi_cntrl)
{
	return mhi_cntrl->priv_data;
}

static inline void mhi_free_controller(struct mhi_controller *mhi_cntrl)
{
	kfree(mhi_cntrl);
}


int mhi_driver_register(struct mhi_driver *mhi_drv);


void mhi_driver_unregister(struct mhi_driver *mhi_drv);


int mhi_device_configure(struct mhi_device *mhi_div,
			 enum dma_data_direction dir,
			 struct mhi_buf *mhi_buf,
			 int elements);


void mhi_device_get(struct mhi_device *mhi_dev, int vote);


int mhi_device_get_sync(struct mhi_device *mhi_dev, int vote);


int mhi_device_get_sync_atomic(struct mhi_device *mhi_dev,
			       int timeout_us,
			       bool in_panic);


void mhi_device_put(struct mhi_device *mhi_dev, int vote);


int mhi_prepare_for_transfer(struct mhi_device *mhi_dev);


void mhi_unprepare_from_transfer(struct mhi_device *mhi_dev);


int mhi_pause_transfer(struct mhi_device *mhi_dev);


int mhi_resume_transfer(struct mhi_device *mhi_dev);


int mhi_get_no_free_descriptors(struct mhi_device *mhi_dev,
				enum dma_data_direction dir);


int mhi_poll(struct mhi_device *mhi_dev, u32 budget);


long mhi_ioctl(struct mhi_device *mhi_dev, unsigned int cmd, unsigned long arg);


struct mhi_controller *mhi_alloc_controller(size_t size);


int of_register_mhi_controller(struct mhi_controller *mhi_cntrl);

void mhi_unregister_mhi_controller(struct mhi_controller *mhi_cntrl);


struct mhi_controller *mhi_bdf_to_controller(u32 domain, u32 bus, u32 slot,
					     u32 dev_id);


int mhi_prepare_for_power_up(struct mhi_controller *mhi_cntrl);


int mhi_async_power_up(struct mhi_controller *mhi_cntrl);
int mhi_sync_power_up(struct mhi_controller *mhi_cntrl);


void mhi_power_down(struct mhi_controller *mhi_cntrl, bool graceful);


void mhi_unprepare_after_power_down(struct mhi_controller *mhi_cntrl);


int mhi_pm_suspend(struct mhi_controller *mhi_cntrl);


int mhi_pm_fast_suspend(struct mhi_controller *mhi_cntrl, bool notify_client);


int mhi_pm_resume(struct mhi_controller *mhi_cntrl);


int mhi_pm_fast_resume(struct mhi_controller *mhi_cntrl, bool notify_client);


int mhi_download_rddm_img(struct mhi_controller *mhi_cntrl, bool in_panic);


int mhi_force_rddm_mode(struct mhi_controller *mhi_cntrl);


void mhi_dump_sfr(struct mhi_controller *mhi_cntrl);


int mhi_get_remote_time(struct mhi_device *mhi_dev,
			u32 sequence,
			void (*cb_func)(struct mhi_device *mhi_dev,
					u32 sequence,
					u64 local_time,
					u64 remote_time));


int mhi_get_remote_time_sync(struct mhi_device *mhi_dev,
			     u64 *t_host,
			     u64 *t_dev);


enum mhi_ee mhi_get_exec_env(struct mhi_controller *mhi_cntrl);


enum mhi_dev_state mhi_get_mhi_state(struct mhi_controller *mhi_cntrl);


void mhi_set_mhi_state(struct mhi_controller *mhi_cntrl,
		       enum mhi_dev_state state);



static inline bool mhi_is_active(struct mhi_device *mhi_dev)
{
	struct mhi_controller *mhi_cntrl = mhi_dev->mhi_cntrl;

	return (mhi_cntrl->dev_state >= MHI_STATE_M0 &&
		mhi_cntrl->dev_state <= MHI_STATE_M3_FAST);
}


void mhi_control_error(struct mhi_controller *mhi_cntrl);


void mhi_debug_reg_dump(struct mhi_controller *mhi_cntrl);


char *mhi_get_restart_reason(const char *name);

#ifndef CONFIG_ARCH_QCOM

#ifdef CONFIG_MHI_DEBUG

#define MHI_VERB(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_VERBOSE) \
			pr_dbg("[D][%s] " fmt, __func__, ##__VA_ARGS__);\
} while (0)

#else

#define MHI_VERB(fmt, ...)

#endif

#define MHI_CNTRL_LOG(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_INFO) \
			pr_info("[I][%s] " fmt, __func__, ##__VA_ARGS__);\
} while (0)

#define MHI_CNTRL_ERR(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_ERROR) \
			pr_err("[E][%s] " fmt, __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_LOG(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_INFO) \
			pr_info("[I][%s] " fmt, __func__, ##__VA_ARGS__);\
} while (0)

#define MHI_ERR(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_ERROR) \
			pr_err("[E][%s] " fmt, __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_CRITICAL(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_CRITICAL) \
			pr_alert("[C][%s] " fmt, __func__, ##__VA_ARGS__); \
} while (0)

#else 

#include <linux/ipc_logging.h>

#ifdef CONFIG_MHI_DEBUG

#define MHI_VERB(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_VERBOSE) \
			pr_err("[D][%s] " fmt, __func__, ##__VA_ARGS__);\
		if (mhi_cntrl->log_buf && \
		    (mhi_cntrl->log_lvl <= MHI_MSG_LVL_VERBOSE)) \
			ipc_log_string(mhi_cntrl->log_buf, "[D][%s] " fmt, \
				       __func__, ##__VA_ARGS__); \
} while (0)

#else

#define MHI_VERB(fmt, ...) do { \
		if (mhi_cntrl->log_buf && \
		    (mhi_cntrl->log_lvl <= MHI_MSG_LVL_VERBOSE)) \
			ipc_log_string(mhi_cntrl->log_buf, "[D][%s] " fmt, \
				       __func__, ##__VA_ARGS__); \
} while (0)

#endif

#define MHI_CNTRL_LOG(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_INFO) \
			pr_err("[I][%s] " fmt, __func__, ##__VA_ARGS__);\
		ipc_log_string(mhi_cntrl->cntrl_log_buf, "[I][%s] " fmt, \
			       __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_CNTRL_ERR(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_ERROR) \
			pr_err("[E][%s] " fmt, __func__, ##__VA_ARGS__); \
		ipc_log_string(mhi_cntrl->cntrl_log_buf, "[E][%s] " fmt, \
			       __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_LOG(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_INFO) \
			pr_err("[I][%s] " fmt, __func__, ##__VA_ARGS__);\
		if (mhi_cntrl->log_buf && \
		    (mhi_cntrl->log_lvl <= MHI_MSG_LVL_INFO)) \
			ipc_log_string(mhi_cntrl->log_buf, "[I][%s] " fmt, \
				       __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_ERR(fmt, ...) do {	\
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_ERROR) \
			pr_err("[E][%s] " fmt, __func__, ##__VA_ARGS__); \
		if (mhi_cntrl->log_buf && \
		    (mhi_cntrl->log_lvl <= MHI_MSG_LVL_ERROR)) \
			ipc_log_string(mhi_cntrl->log_buf, "[E][%s] " fmt, \
				       __func__, ##__VA_ARGS__); \
} while (0)

#define MHI_CRITICAL(fmt, ...) do { \
		if (mhi_cntrl->klog_lvl <= MHI_MSG_LVL_CRITICAL) \
			pr_err("[C][%s] " fmt, __func__, ##__VA_ARGS__); \
		if (mhi_cntrl->log_buf && \
		    (mhi_cntrl->log_lvl <= MHI_MSG_LVL_CRITICAL)) \
			ipc_log_string(mhi_cntrl->log_buf, "[C][%s] " fmt, \
				       __func__, ##__VA_ARGS__); \
} while (0)

#endif

#endif 
