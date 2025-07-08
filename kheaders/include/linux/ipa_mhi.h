/* SPDX-License-Identifier: GPL-2.0 */


#ifndef IPA_MHI_H_
#define IPA_MHI_H_

#include <linux/ipa.h>
#include <linux/types.h>


enum ipa_mhi_event_type {
	IPA_MHI_EVENT_READY,
	IPA_MHI_EVENT_DATA_AVAILABLE,
	IPA_MHI_EVENT_MAX,
};

typedef void (*mhi_client_cb)(void *priv, enum ipa_mhi_event_type event,
	unsigned long data);


struct ipa_mhi_msi_info {
	u32 addr_low;
	u32 addr_hi;
	u32 data;
	u32 mask;
};


struct ipa_mhi_init_params {
	struct ipa_mhi_msi_info msi;
	u32 mmio_addr;
	u32 first_ch_idx;
	u32 first_er_idx;
	bool assert_bit40;
	mhi_client_cb notify;
	void *priv;
	bool test_mode;
};


struct ipa_mhi_start_params {
	u32 host_ctrl_addr;
	u32 host_data_addr;
	u64 channel_context_array_addr;
	u64 event_context_array_addr;
};


struct ipa_mhi_connect_params {
	struct ipa_sys_connect_params sys;
	u8 channel_id;
};


#define IPA_MHI_HOST_ADDR(addr) ((addr) | BIT_ULL(40))

#if defined CONFIG_IPA || defined CONFIG_IPA3

int ipa_mhi_init(struct ipa_mhi_init_params *params);

int ipa_mhi_start(struct ipa_mhi_start_params *params);

int ipa_mhi_connect_pipe(struct ipa_mhi_connect_params *in, u32 *clnt_hdl);

int ipa_mhi_disconnect_pipe(u32 clnt_hdl);

int ipa_mhi_suspend(bool force);

int ipa_mhi_resume(void);

void ipa_mhi_destroy(void);

#else 

static inline int ipa_mhi_init(struct ipa_mhi_init_params *params)
{
	return -EPERM;
}

static inline int ipa_mhi_start(struct ipa_mhi_start_params *params)
{
	return -EPERM;
}

static inline int ipa_mhi_connect_pipe(struct ipa_mhi_connect_params *in,
	u32 *clnt_hdl)
{
	return -EPERM;
}

static inline int ipa_mhi_disconnect_pipe(u32 clnt_hdl)
{
	return -EPERM;
}

static inline int ipa_mhi_suspend(bool force)
{
	return -EPERM;
}

static inline int ipa_mhi_resume(void)
{
	return -EPERM;
}

static inline void ipa_mhi_destroy(void)
{

}

#endif 

#endif 
