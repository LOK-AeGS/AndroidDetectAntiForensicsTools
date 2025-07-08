/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _USB_BAM_H_
#define _USB_BAM_H_

#include <linux/msm-sps.h>
#include <linux/ipa.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/usb/ch9.h>

#define MAX_BAMS	NUM_CTRL	


enum usb_ctrl {
	DWC3_CTRL = 0,  
	CI_CTRL,        
	HSIC_CTRL,      
	NUM_CTRL,
};

enum usb_bam_mode {
	USB_BAM_DEVICE = 0,
	USB_BAM_HOST,
};

enum peer_bam {
	QDSS_P_BAM = 0,
	IPA_P_BAM,
	MAX_PEER_BAMS,
};

enum usb_bam_pipe_dir {
	USB_TO_PEER_PERIPHERAL,
	PEER_PERIPHERAL_TO_USB,
};

enum usb_pipe_mem_type {
	SPS_PIPE_MEM = 0,	
	SYSTEM_MEM,		
	OCI_MEM,		
};

enum usb_bam_pipe_type {
	USB_BAM_PIPE_BAM2BAM = 0,	
	USB_BAM_PIPE_SYS2BAM,		
	USB_BAM_MAX_PIPE_TYPES,
};


struct usb_bam_connect_ipa_params {
	u8 src_idx;
	u8 dst_idx;
	u32 *src_pipe;
	u32 *dst_pipe;
	bool keep_ipa_awake;
	enum usb_bam_pipe_dir dir;
	
	u32 ipa_cons_ep_idx;
	u32 ipa_prod_ep_idx;
	
	u32 prod_clnt_hdl;
	u32 cons_clnt_hdl;
	
	enum ipa_client_type src_client;
	enum ipa_client_type dst_client;
	struct ipa_ep_cfg ipa_ep_cfg;
	void *priv;
	void (*notify)(void *priv, enum ipa_dp_evt_type evt,
			unsigned long data);
	int (*activity_notify)(void *priv);
	int (*inactivity_notify)(void *priv);
	bool skip_ep_cfg;
	bool reset_pipe_after_lpm;
	enum usb_device_speed usb_connection_speed;
};

#if  IS_ENABLED(CONFIG_USB_BAM)

int usb_bam_connect(enum usb_ctrl bam_type, int idx, u32 *bam_pipe_idx,
						unsigned long iova);


int usb_bam_connect_ipa(enum usb_ctrl bam_type,
			struct usb_bam_connect_ipa_params *ipa_params);


int usb_bam_disconnect_ipa(enum usb_ctrl bam_type,
		struct usb_bam_connect_ipa_params *ipa_params);



int usb_bam_register_wake_cb(enum usb_ctrl bam_type, u8 idx,
	int (*callback)(void *), void *param);


int usb_bam_register_start_stop_cbs(enum usb_ctrl bam_type,
	u8 idx,
	void (*start)(void *, enum usb_bam_pipe_dir),
	void (*stop)(void *, enum usb_bam_pipe_dir),
	void *param);


void usb_bam_suspend(enum usb_ctrl bam_type,
		     struct usb_bam_connect_ipa_params *ipa_params);


void usb_bam_resume(enum usb_ctrl bam_type,
		     struct usb_bam_connect_ipa_params *ipa_params);



int usb_bam_disconnect_pipe(enum usb_ctrl bam_type, u8 idx);


int get_bam2bam_connection_info(enum usb_ctrl bam_type, u8 idx,
	u32 *usb_bam_pipe_idx, struct sps_mem_buffer *desc_fifo,
	struct sps_mem_buffer *data_fifo, enum usb_pipe_mem_type *mem_type);


int get_qdss_bam_connection_info(
	unsigned long *usb_bam_handle, u32 *usb_bam_pipe_idx,
	u32 *peer_pipe_idx, struct sps_mem_buffer *desc_fifo,
	struct sps_mem_buffer *data_fifo, enum usb_pipe_mem_type *mem_type);


int usb_bam_get_connection_idx(enum usb_ctrl bam_type, enum peer_bam client,
	enum usb_bam_pipe_dir dir, u32 num);


enum usb_ctrl usb_bam_get_bam_type(const char *core_name);


int usb_bam_get_pipe_type(enum usb_ctrl bam_type,
			  u8 idx, enum usb_bam_pipe_type *type);


bool usb_bam_get_prod_granted(enum usb_ctrl bam_type, u8 idx);


int usb_bam_alloc_fifos(enum usb_ctrl cur_bam, u8 idx);


int usb_bam_free_fifos(enum usb_ctrl cur_bam, u8 idx);
int get_qdss_bam_info(enum usb_ctrl cur_bam, u8 idx,
			phys_addr_t *p_addr, u32 *bam_size);
bool msm_usb_bam_enable(enum usb_ctrl ctrl, bool bam_enable);
void msm_bam_set_hsic_host_dev(struct device *dev);
bool msm_bam_hsic_lpm_ok(void);
void msm_bam_hsic_host_notify_on_resume(void);
void msm_bam_wait_for_hsic_host_prod_granted(void);
bool msm_bam_hsic_host_pipe_empty(void);
#else
static inline int usb_bam_connect(enum usb_ctrl bam, u8 idx, u32 *bam_pipe_idx,
							unsigned long iova)
{
	return -ENODEV;
}

static inline int usb_bam_connect_ipa(enum usb_ctrl bam_type,
			struct usb_bam_connect_ipa_params *ipa_params)
{
	return -ENODEV;
}

static inline int usb_bam_disconnect_ipa(enum usb_ctrl bam_type,
			struct usb_bam_connect_ipa_params *ipa_params)
{
	return -ENODEV;
}

static inline int usb_bam_register_wake_cb(enum usb_ctrl bam_type, u8 idx,
	int (*callback)(void *), void *param)
{
	return -ENODEV;
}

static inline int usb_bam_register_start_stop_cbs(enum usb_ctrl bam, u8 idx,
	void (*start)(void *, enum usb_bam_pipe_dir),
	void (*stop)(void *, enum usb_bam_pipe_dir),
	void *param)
{
	return -ENODEV;
}

static inline void usb_bam_suspend(enum usb_ctrl bam_type,
	struct usb_bam_connect_ipa_params *ipa_params){}

static inline void usb_bam_resume(enum usb_ctrl bam_type,
	struct usb_bam_connect_ipa_params *ipa_params) {}

static inline int usb_bam_disconnect_pipe(enum usb_ctrl bam_type, u8 idx)
{
	return -ENODEV;
}

static inline int get_bam2bam_connection_info(enum usb_ctrl bam_type, u8 idx,
	u32 *usb_bam_pipe_idx, struct sps_mem_buffer *desc_fifo,
	struct sps_mem_buffer *data_fifo, enum usb_pipe_mem_type *mem_type)
{
	return -ENODEV;
}

static inline int get_qdss_bam_connection_info(
	unsigned long *usb_bam_handle, u32 *usb_bam_pipe_idx,
	u32 *peer_pipe_idx, struct sps_mem_buffer *desc_fifo,
	struct sps_mem_buffer *data_fifo, enum usb_pipe_mem_type *mem_type)
{
	return -ENODEV;
}

static inline int usb_bam_get_connection_idx(enum usb_ctrl bam_type,
		enum peer_bam client, enum usb_bam_pipe_dir dir, u32 num)
{
	return -ENODEV;
}

static inline enum usb_ctrl usb_bam_get_bam_type(const char *core_nam)
{
	return -ENODEV;
}

static inline int usb_bam_get_pipe_type(enum usb_ctrl bam_type, u8 idx,
					enum usb_bam_pipe_type *type)
{
	return -ENODEV;
}

static inline bool usb_bam_get_prod_granted(enum usb_ctrl bam_type, u8 idx)
{
	return false;
}

static inline int usb_bam_alloc_fifos(enum usb_ctrl cur_bam, u8 idx)
{
	return false;
}

static inline int usb_bam_free_fifos(enum usb_ctrl cur_bam, u8 idx)
{
	return false;
}

static inline int get_qdss_bam_info(enum usb_ctrl cur_bam, u8 idx,
				phys_addr_t *p_addr, u32 *bam_size)
{
	return false;
}

static inline bool msm_usb_bam_enable(enum usb_ctrl ctrl, bool bam_enable)
{
	return false;
}

static inline void msm_bam_set_hsic_host_dev(struct device *dev) {}

static inline bool msm_bam_hsic_lpm_ok(void)
{
	return false;
}

static inline void msm_bam_hsic_host_notify_on_resume(void) {}

static inline void msm_bam_wait_for_hsic_host_prod_granted(void) {}

static inline bool msm_bam_hsic_host_pipe_empty(void)
{
	return false;
}

#endif


#ifdef CONFIG_PM
static inline int get_pm_runtime_counter(struct device *dev)
{
	return atomic_read(&dev->power.usage_count);
}
#else

static inline int get_pm_runtime_counter(struct device *dev)
{ return -EOPNOTSUPP; }
#endif
#ifdef CONFIG_USB_CI13XXX_MSM
void msm_hw_bam_disable(bool bam_disable);
#else
static inline void msm_hw_bam_disable(bool bam_disable)
{}
#endif
#endif				
