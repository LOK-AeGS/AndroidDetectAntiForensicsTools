/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _ECM_IPA_H_
#define _ECM_IPA_H_

#include <linux/ipa.h>


typedef void (*ecm_ipa_callback)(void *priv,
		enum ipa_dp_evt_type evt,
		unsigned long data);


struct ecm_ipa_params {
	void (*device_ready_notify)(void);
	ecm_ipa_callback ecm_ipa_rx_dp_notify;
	ecm_ipa_callback ecm_ipa_tx_dp_notify;
	u8 host_ethaddr[ETH_ALEN];
	u8 device_ethaddr[ETH_ALEN];
	void *private;
	bool skip_ep_cfg;
};


#ifdef CONFIG_ECM_IPA

int ecm_ipa_init(struct ecm_ipa_params *params);

int ecm_ipa_connect(u32 usb_to_ipa_hdl, u32 ipa_to_usb_hdl,
		void *priv);

int ecm_ipa_disconnect(void *priv);

void ecm_ipa_cleanup(void *priv);

#else 

static inline int ecm_ipa_init(struct ecm_ipa_params *params)
{
	return 0;
}

static inline int ecm_ipa_connect(u32 usb_to_ipa_hdl, u32 ipa_to_usb_hdl,
		void *priv)
{
	return 0;
}

static inline int ecm_ipa_disconnect(void *priv)
{
	return 0;
}

static inline void ecm_ipa_cleanup(void *priv)
{

}
#endif 

#endif 
