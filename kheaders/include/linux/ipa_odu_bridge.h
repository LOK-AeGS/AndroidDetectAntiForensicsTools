/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _IPA_ODO_BRIDGE_H_
#define _IPA_ODO_BRIDGE_H_

#include <linux/ipa.h>


struct odu_bridge_params {
	const char *netdev_name;
	void *priv;
	ipa_notify_cb tx_dp_notify;
	int (*send_dl_skb)(void *priv, struct sk_buff *skb);
	u8 device_ethaddr[ETH_ALEN];
	u32 ipa_desc_size;
};


struct ipa_bridge_init_params {
	struct odu_bridge_params info;
	void (*wakeup_request)(void *cl_priv);
};

#ifdef CONFIG_IPA3

int ipa_bridge_init(struct ipa_bridge_init_params *params, u32 *hdl);

int ipa_bridge_connect(u32 hdl);

int ipa_bridge_set_perf_profile(u32 hdl, u32 bandwidth);

int ipa_bridge_disconnect(u32 hdl);

int ipa_bridge_suspend(u32 hdl);

int ipa_bridge_resume(u32 hdl);

int ipa_bridge_tx_dp(u32 hdl, struct sk_buff *skb,
	struct ipa_tx_meta *metadata);

int ipa_bridge_cleanup(u32 hdl);

#else

static inline int ipa_bridge_init(struct odu_bridge_params *params, u32 *hdl)
{
	return -EPERM;
}

static inline int ipa_bridge_connect(u32 hdl)
{
	return -EPERM;
}

static inline int ipa_bridge_set_perf_profile(u32 hdl, u32 bandwidth)
{
	return -EPERM;
}

static inline int ipa_bridge_disconnect(u32 hdl)
{
	return -EPERM;
}

static inline int ipa_bridge_suspend(u32 hdl)
{
	return -EPERM;
}

static inline int ipa_bridge_resume(u32 hdl)
{
	return -EPERM;
}

static inline int ipa_bridge_tx_dp(u32 hdl, struct sk_buff *skb,
struct ipa_tx_meta *metadata)
{
	return -EPERM;
}

static inline int ipa_bridge_cleanup(u32 hdl)
{
	return -EPERM;
}

#endif 


# if defined CONFIG_IPA || defined CONFIG_IPA3

int odu_bridge_init(struct odu_bridge_params *params);

int odu_bridge_connect(void);

int odu_bridge_disconnect(void);

int odu_bridge_tx_dp(struct sk_buff *skb, struct ipa_tx_meta *metadata);

int odu_bridge_cleanup(void);

#else

static inline int odu_bridge_init(struct odu_bridge_params *params)
{
	return -EPERM;
}

static inline int odu_bridge_disconnect(void)
{
	return -EPERM;
}

static inline int odu_bridge_connect(void)
{
	return -EPERM;
}

static inline int odu_bridge_tx_dp(struct sk_buff *skb,
						struct ipa_tx_meta *metadata)
{
	return -EPERM;
}

static inline int odu_bridge_cleanup(void)
{
	return -EPERM;
}

#endif 

#endif 
