/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _IPA_USB_H_
#define _IPA_USB_H_

enum ipa_usb_teth_prot {
	IPA_USB_RNDIS = 0,
	IPA_USB_ECM = 1,
	IPA_USB_RMNET = 2,
	IPA_USB_MBIM = 3,
	IPA_USB_DIAG = 4,
	IPA_USB_MAX_TETH_PROT_SIZE
};


struct ipa_usb_teth_params {
	u8 host_ethaddr[ETH_ALEN];
	u8 device_ethaddr[ETH_ALEN];
};

enum ipa_usb_notify_event {
	IPA_USB_DEVICE_READY,
	IPA_USB_REMOTE_WAKEUP,
	IPA_USB_SUSPEND_COMPLETED
};

enum ipa_usb_max_usb_packet_size {
	IPA_USB_FULL_SPEED_64B = 64,
	IPA_USB_HIGH_SPEED_512B = 512,
	IPA_USB_SUPER_SPEED_1024B = 1024
};


struct ipa_usb_teth_prot_params {
	u32 max_xfer_size_bytes_to_dev;
	u32 max_packet_number_to_dev;
	u32 max_xfer_size_bytes_to_host;
};


struct ipa_usb_xdci_connect_params {
	enum ipa_usb_max_usb_packet_size max_pkt_size;
	u8 ipa_to_usb_xferrscidx;
	bool ipa_to_usb_xferrscidx_valid;
	u8 usb_to_ipa_xferrscidx;
	bool usb_to_ipa_xferrscidx_valid;
	enum ipa_usb_teth_prot teth_prot;
	struct ipa_usb_teth_prot_params teth_prot_params;
	u32 max_supported_bandwidth_mbps;
};


struct ipa_usb_xdci_chan_scratch {
	u16 last_trb_addr_iova;
	u8 const_buffer_size;
	u32 depcmd_low_addr;
	u8 depcmd_hi_addr;
};


struct ipa_usb_xdci_chan_params {
	
	enum ipa_client_type client;
	struct ipa_ep_cfg ipa_ep_cfg;
	bool keep_ipa_awake;
	enum ipa_usb_teth_prot teth_prot;
	
	u32 gevntcount_low_addr;
	u8 gevntcount_hi_addr;
	
	enum gsi_chan_dir dir;
	u16 xfer_ring_len;
	struct ipa_usb_xdci_chan_scratch xfer_scratch;
	u64 xfer_ring_base_addr_iova;
	u32 data_buff_base_len;
	u64 data_buff_base_addr_iova;
	struct sg_table *sgt_xfer_rings;
	struct sg_table *sgt_data_buff;
};


struct ipa_req_chan_out_params {
	u32 clnt_hdl;
	u32 db_reg_phs_addr_lsb;
	u32 db_reg_phs_addr_msb;
};

#ifdef CONFIG_IPA3


int ipa_usb_init_teth_prot(enum ipa_usb_teth_prot teth_prot,
			   struct ipa_usb_teth_params *teth_params,
			   int (*ipa_usb_notify_cb)(enum ipa_usb_notify_event,
			   void *),
			   void *user_data);


int ipa_usb_xdci_connect(struct ipa_usb_xdci_chan_params *ul_chan_params,
			 struct ipa_usb_xdci_chan_params *dl_chan_params,
			 struct ipa_req_chan_out_params *ul_out_params,
			 struct ipa_req_chan_out_params *dl_out_params,
			 struct ipa_usb_xdci_connect_params *connect_params);


int ipa_usb_xdci_disconnect(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			    enum ipa_usb_teth_prot teth_prot);


int ipa_usb_deinit_teth_prot(enum ipa_usb_teth_prot teth_prot);


int ipa_usb_xdci_suspend(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			 enum ipa_usb_teth_prot teth_prot,
			 bool with_remote_wakeup);


int ipa_usb_xdci_resume(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			enum ipa_usb_teth_prot teth_prot);

#else 

static inline int ipa_usb_init_teth_prot(enum ipa_usb_teth_prot teth_prot,
			   struct ipa_usb_teth_params *teth_params,
			   int (*ipa_usb_notify_cb)(enum ipa_usb_notify_event,
			   void *),
			   void *user_data)
{
	return -EPERM;
}

static inline int ipa_usb_xdci_connect(
			 struct ipa_usb_xdci_chan_params *ul_chan_params,
			 struct ipa_usb_xdci_chan_params *dl_chan_params,
			 struct ipa_req_chan_out_params *ul_out_params,
			 struct ipa_req_chan_out_params *dl_out_params,
			 struct ipa_usb_xdci_connect_params *connect_params)
{
	return -EPERM;
}

static inline int ipa_usb_xdci_disconnect(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			    enum ipa_usb_teth_prot teth_prot)
{
	return -EPERM;
}

static inline int ipa_usb_deinit_teth_prot(enum ipa_usb_teth_prot teth_prot)
{
	return -EPERM;
}

static inline int ipa_usb_xdci_suspend(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			 enum ipa_usb_teth_prot teth_prot,
			 bool with_remote_wakeup)
{
	return -EPERM;
}

static inline int ipa_usb_xdci_resume(u32 ul_clnt_hdl, u32 dl_clnt_hdl,
			enum ipa_usb_teth_prot teth_prot)
{
	return -EPERM;
}


#endif 

#endif 
