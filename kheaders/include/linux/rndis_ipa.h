/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _RNDIS_IPA_H_
#define _RNDIS_IPA_H_

#include <linux/ipa.h>


typedef void (*ipa_callback)(void *priv,
		enum ipa_dp_evt_type evt,
		unsigned long data);


struct ipa_usb_init_params {
	void (*device_ready_notify)(void);
	ipa_callback ipa_rx_notify;
	ipa_callback ipa_tx_notify;
	u8 host_ethaddr[ETH_ALEN];
	u8 device_ethaddr[ETH_ALEN];
	void *private;
	bool skip_ep_cfg;
};

#ifdef CONFIG_RNDIS_IPA

int rndis_ipa_init(struct ipa_usb_init_params *params);

int rndis_ipa_pipe_connect_notify(u32 usb_to_ipa_hdl,
			u32 ipa_to_usb_hdl,
			u32 max_xfer_size_bytes_to_dev,
			u32 max_packet_number_to_dev,
			u32 max_xfer_size_bytes_to_host,
			void *private);

int rndis_ipa_pipe_disconnect_notify(void *private);

void rndis_ipa_cleanup(void *private);

#else 

static inline int rndis_ipa_init(struct ipa_usb_init_params *params)
{
	return -ENOMEM;
}

static inline int rndis_ipa_pipe_connect_notify(u32 usb_to_ipa_hdl,
			u32 ipa_to_usb_hdl,
			u32 max_xfer_size_bytes_to_dev,
			u32 max_packet_number_to_dev,
			u32 max_xfer_size_bytes_to_host,
			void *private)
{
	return -ENOMEM;
}

static inline int rndis_ipa_pipe_disconnect_notify(void *private)
{
	return -ENOMEM;
}

static inline void rndis_ipa_cleanup(void *private)
{

}
#endif 

#endif 
