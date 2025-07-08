/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _IPA_WIGIG_H_
#define _IPA_WIGIG_H_

#include <linux/msm_ipa.h>
#include <linux/ipa.h>

typedef void (*ipa_wigig_misc_int_cb)(void *priv);


struct ipa_wigig_init_in_params {
	phys_addr_t periph_baddr_pa;
	phys_addr_t pseudo_cause_pa;
	phys_addr_t int_gen_tx_pa;
	phys_addr_t int_gen_rx_pa;
	phys_addr_t dma_ep_misc_pa;
	ipa_uc_ready_cb notify;
	ipa_wigig_misc_int_cb int_notify;
	void *priv;
};


struct ipa_wigig_init_out_params {
	bool is_uc_ready;
	phys_addr_t uc_db_pa;
	bool lan_rx_napi_enable;
};


struct ipa_wigig_hdr_info {
	u8 *hdr;
	u8 hdr_len;
	u8 dst_mac_addr_offset;
	enum ipa_hdr_l2_type hdr_type;
};


struct ipa_wigig_reg_intf_in_params {
	const char *netdev_name;
	u8 netdev_mac[IPA_MAC_ADDR_SIZE];
	struct ipa_wigig_hdr_info hdr_info[IPA_IP_MAX];
};


struct ipa_wigig_pipe_setup_info {
	phys_addr_t desc_ring_base_pa;
	u16 desc_ring_size;
	phys_addr_t desc_ring_HWHEAD_pa;
	phys_addr_t desc_ring_HWTAIL_pa;

	phys_addr_t status_ring_base_pa;
	u16 status_ring_size;
	phys_addr_t status_ring_HWHEAD_pa;
	phys_addr_t status_ring_HWTAIL_pa;
};


struct ipa_wigig_pipe_setup_info_smmu {
	struct sg_table desc_ring_base;
	u64 desc_ring_base_iova;
	u16 desc_ring_size;
	phys_addr_t desc_ring_HWHEAD_pa;
	phys_addr_t desc_ring_HWTAIL_pa;

	struct sg_table status_ring_base;
	u64 status_ring_base_iova;
	u16 status_ring_size;
	phys_addr_t status_ring_HWHEAD_pa;
	phys_addr_t status_ring_HWTAIL_pa;
};


struct ipa_wigig_rx_pipe_data_buffer_info {
	phys_addr_t data_buffer_base_pa;
	u32 data_buffer_size;
};


struct ipa_wigig_rx_pipe_data_buffer_info_smmu {
	struct sg_table data_buffer_base;
	u64 data_buffer_base_iova;
	u32 data_buffer_size;
};


struct ipa_wigig_conn_rx_in_params {
	ipa_notify_cb notify;
	void *priv;
	struct ipa_wigig_pipe_setup_info pipe;
	struct ipa_wigig_rx_pipe_data_buffer_info dbuff;
};


struct ipa_wigig_conn_rx_in_params_smmu {
	ipa_notify_cb notify;
	void *priv;
	struct ipa_wigig_pipe_setup_info_smmu pipe_smmu;
	struct ipa_wigig_rx_pipe_data_buffer_info_smmu dbuff_smmu;
};


struct ipa_wigig_conn_out_params {
	enum ipa_client_type client;
};


struct ipa_wigig_tx_pipe_data_buffer_info {
	u32 data_buffer_size;
};


struct ipa_wigig_tx_pipe_data_buffer_info_smmu {
	struct sg_table *data_buffer_base;
	u64 *data_buffer_base_iova;
	u32 num_buffers;
	u32 data_buffer_size;
};


struct ipa_wigig_conn_tx_in_params {
	struct ipa_wigig_pipe_setup_info pipe;
	struct ipa_wigig_tx_pipe_data_buffer_info dbuff;
	u8 int_gen_tx_bit_num;
	u8 client_mac[IPA_MAC_ADDR_SIZE];
};


struct ipa_wigig_conn_tx_in_params_smmu {
	struct ipa_wigig_pipe_setup_info_smmu pipe_smmu;
	struct ipa_wigig_tx_pipe_data_buffer_info_smmu dbuff_smmu;
	u8 int_gen_tx_bit_num;
	u8 client_mac[IPA_MAC_ADDR_SIZE];
};

#if defined CONFIG_IPA || defined CONFIG_IPA3


int ipa_wigig_init(struct ipa_wigig_init_in_params *in,
	struct ipa_wigig_init_out_params *out);


int ipa_wigig_cleanup(void);


bool ipa_wigig_is_smmu_enabled(void);


int ipa_wigig_reg_intf(struct ipa_wigig_reg_intf_in_params *in);


int ipa_wigig_dereg_intf(const char *netdev_name);


int ipa_wigig_conn_rx_pipe(struct ipa_wigig_conn_rx_in_params *in,
	struct ipa_wigig_conn_out_params *out);


int ipa_wigig_conn_rx_pipe_smmu(struct ipa_wigig_conn_rx_in_params_smmu *in,
	struct ipa_wigig_conn_out_params *out);


int ipa_wigig_conn_client(struct ipa_wigig_conn_tx_in_params *in,
	struct ipa_wigig_conn_out_params *out);


int ipa_wigig_conn_client_smmu(struct ipa_wigig_conn_tx_in_params_smmu *in,
	struct ipa_wigig_conn_out_params *out);


int ipa_wigig_disconn_pipe(enum ipa_client_type client);



int ipa_wigig_enable_pipe(enum ipa_client_type client);


int ipa_wigig_disable_pipe(enum ipa_client_type client);


int ipa_wigig_tx_dp(enum ipa_client_type dst, struct sk_buff *skb);


int ipa_wigig_set_perf_profile(u32 max_supported_bw_mbps);

#else 
static inline int ipa_wigig_init(struct ipa_wigig_init_in_params *in,
	struct ipa_wigig_init_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wigig_cleanup(void)
{
	return -EPERM;
}

static inline bool ipa_wigig_is_smmu_enabled(void)
{
	return -EPERM;
}

static inline int ipa_wigig_reg_intf(struct ipa_wigig_reg_intf_in_params *in)
{
	return -EPERM;
}

static inline int ipa_wigig_dereg_intf(const char *netdev_name)
{
	return -EPERM;
}

static inline int ipa_wigig_conn_rx_pipe(
	struct ipa_wigig_conn_rx_in_params *in,
	struct ipa_wigig_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wigig_conn_rx_pipe_smmu(
	struct ipa_wigig_conn_rx_in_params_smmu *in,
	struct ipa_wigig_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wigig_conn_client(
	struct ipa_wigig_conn_tx_in_params *in,
	struct ipa_wigig_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wigig_conn_client_smmu(
	struct ipa_wigig_conn_tx_in_params_smmu *in,
	struct ipa_wigig_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wigig_disconn_pipe(enum ipa_client_type client)
{
	return -EPERM;
}

static inline int ipa_wigig_enable_pipe(enum ipa_client_type client)
{
	return -EPERM;
}

static inline int ipa_wigig_disable_pipe(enum ipa_client_type client)
{
	return -EPERM;
}

static inline int ipa_wigig_tx_dp(enum ipa_client_type dst,
	struct sk_buff *skb)
{
	return -EPERM;
}

int ipa_wigig_set_perf_profile(u32 max_supported_bw_mbps)
{
	return -EPERM;
}
#endif 
#endif 
