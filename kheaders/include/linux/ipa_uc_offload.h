/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _IPA_UC_OFFLOAD_H_
#define _IPA_UC_OFFLOAD_H_

#include <linux/ipa.h>


enum ipa_uc_offload_proto {
	IPA_UC_INVALID = 0,
	IPA_UC_WDI = 1,
	IPA_UC_NTN = 2,
	IPA_UC_MAX_PROT_SIZE
};


struct ipa_hdr_info {
	u8 *hdr;
	u8 hdr_len;
	u8 dst_mac_addr_offset;
	enum ipa_hdr_l2_type hdr_type;
};


struct ipa_uc_offload_intf_params {
	const char *netdev_name;
	ipa_notify_cb notify;
	void *priv;
	struct ipa_hdr_info hdr_info[IPA_IP_MAX];
	u8 is_meta_data_valid;
	u32 meta_data;
	u32 meta_data_mask;
	enum ipa_uc_offload_proto proto;
	enum ipa_client_type alt_dst_pipe;
};


struct ntn_buff_smmu_map {
	dma_addr_t iova;
	phys_addr_t pa;
};


struct ipa_ntn_setup_info {
	enum ipa_client_type client;
	bool smmu_enabled;
	phys_addr_t ring_base_pa;
	dma_addr_t ring_base_iova;
	struct sg_table *ring_base_sgt;

	u32 ntn_ring_size;

	phys_addr_t buff_pool_base_pa;
	dma_addr_t buff_pool_base_iova;
	struct sg_table *buff_pool_base_sgt;

	struct ntn_buff_smmu_map *data_buff_list;

	u32 num_buffers;

	u32 data_buff_size;

	phys_addr_t ntn_reg_base_ptr_pa;
};


struct ipa_uc_offload_out_params {
	u32 clnt_hndl;
};


struct ipa_ntn_conn_in_params {
	struct ipa_ntn_setup_info ul;
	struct ipa_ntn_setup_info dl;
};


struct ipa_ntn_conn_out_params {
	phys_addr_t ul_uc_db_pa;
	phys_addr_t dl_uc_db_pa;
};


struct ipa_uc_offload_conn_in_params {
	u32 clnt_hndl;
	union {
		struct ipa_ntn_conn_in_params ntn;
	} u;
};


struct ipa_uc_offload_conn_out_params {
	union {
		struct ipa_ntn_conn_out_params ntn;
	} u;
};


struct ipa_perf_profile {
	enum ipa_client_type client;
	u32 max_supported_bw_mbps;
};


struct ipa_uc_ready_params {
	bool is_uC_ready;
	void *priv;
	ipa_uc_ready_cb notify;
	enum ipa_uc_offload_proto proto;
};

#if defined CONFIG_IPA || defined CONFIG_IPA3


int ipa_uc_offload_reg_intf(
	struct ipa_uc_offload_intf_params *in,
	struct ipa_uc_offload_out_params *out);


int ipa_uc_offload_cleanup(u32 clnt_hdl);


int ipa_uc_offload_conn_pipes(struct ipa_uc_offload_conn_in_params *in,
			struct ipa_uc_offload_conn_out_params *out);


int ipa_uc_offload_disconn_pipes(u32 clnt_hdl);


int ipa_set_perf_profile(struct ipa_perf_profile *profile);



int ipa_uc_offload_reg_rdyCB(struct ipa_uc_ready_params *param);


void ipa_uc_offload_dereg_rdyCB(enum ipa_uc_offload_proto proto);

#else 

static inline int ipa_uc_offload_reg_intf(
		struct ipa_uc_offload_intf_params *in,
		struct ipa_uc_offload_out_params *out)
{
	return -EPERM;
}

static inline int ipa_uC_offload_cleanup(u32 clnt_hdl)
{
	return -EPERM;
}

static inline int ipa_uc_offload_conn_pipes(
		struct ipa_uc_offload_conn_in_params *in,
		struct ipa_uc_offload_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_uc_offload_disconn_pipes(u32 clnt_hdl)
{
	return -EPERM;
}

static inline int ipa_set_perf_profile(struct ipa_perf_profile *profile)
{
	return -EPERM;
}

static inline int ipa_uc_offload_reg_rdyCB(struct ipa_uc_ready_params *param)
{
	return -EPERM;
}

static inline void ipa_uc_offload_dereg_rdyCB(enum ipa_uc_offload_proto proto)
{
}

#endif 

#endif 
