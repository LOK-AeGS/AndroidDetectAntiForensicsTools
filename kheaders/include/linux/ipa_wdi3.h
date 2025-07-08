/* SPDX-License-Identifier: GPL-2.0 */


#ifndef _IPA_WDI3_H_
#define _IPA_WDI3_H_

#include <linux/ipa.h>

#define IPA_HW_WDI3_TCL_DATA_CMD_ER_DESC_SIZE 32
#define IPA_HW_WDI3_IPA2FW_ER_DESC_SIZE 8

#define IPA_HW_WDI3_MAX_ER_DESC_SIZE \
	(((IPA_HW_WDI3_TCL_DATA_CMD_ER_DESC_SIZE) > \
	(IPA_HW_WDI3_IPA2FW_ER_DESC_SIZE)) ?  \
	(IPA_HW_WDI3_TCL_DATA_CMD_ER_DESC_SIZE) : \
	(IPA_HW_WDI3_IPA2FW_ER_DESC_SIZE))

#define IPA_WDI_MAX_SUPPORTED_SYS_PIPE 3

enum ipa_wdi_version {
	IPA_WDI_1,
	IPA_WDI_2,
	IPA_WDI_3
};

#define IPA_WDI3_TX_DIR 1
#define IPA_WDI3_RX_DIR 2


struct ipa_wdi_init_in_params {
	enum ipa_wdi_version wdi_version;
	ipa_uc_ready_cb notify;
	void *priv;
#ifdef IPA_WAN_MSG_IPv6_ADDR_GW_LEN
	ipa_wdi_meter_notifier_cb wdi_notify;
#endif
};


struct ipa_wdi_init_out_params {
	bool is_uC_ready;
	bool is_smmu_enabled;
	bool is_over_gsi;
};


struct ipa_wdi_hdr_info {
	u8 *hdr;
	u8 hdr_len;
	u8 dst_mac_addr_offset;
	enum ipa_hdr_l2_type hdr_type;
};


struct ipa_wdi_reg_intf_in_params {
	const char *netdev_name;
	struct ipa_wdi_hdr_info hdr_info[IPA_IP_MAX];
	enum ipa_client_type alt_dst_pipe;
	u8 is_meta_data_valid;
	u32 meta_data;
	u32 meta_data_mask;
};


struct ipa_wdi_pipe_setup_info {
	struct ipa_ep_cfg ipa_ep_cfg;
	enum ipa_client_type client;
	phys_addr_t  transfer_ring_base_pa;
	u32  transfer_ring_size;
	phys_addr_t  transfer_ring_doorbell_pa;
	bool is_txr_rn_db_pcie_addr;

	phys_addr_t  event_ring_base_pa;
	u32  event_ring_size;
	phys_addr_t  event_ring_doorbell_pa;
	bool is_evt_rn_db_pcie_addr;
	u16  num_pkt_buffers;

	u16 pkt_offset;

	u32  desc_format_template[IPA_HW_WDI3_MAX_ER_DESC_SIZE];
};


struct ipa_wdi_pipe_setup_info_smmu {
	struct ipa_ep_cfg ipa_ep_cfg;
	enum ipa_client_type client;
	struct sg_table  transfer_ring_base;
	u32  transfer_ring_size;
	phys_addr_t  transfer_ring_doorbell_pa;
	bool is_txr_rn_db_pcie_addr;

	struct sg_table  event_ring_base;
	u32  event_ring_size;
	phys_addr_t  event_ring_doorbell_pa;
	bool is_evt_rn_db_pcie_addr;
	u16  num_pkt_buffers;

	u16 pkt_offset;

	u32  desc_format_template[IPA_HW_WDI3_MAX_ER_DESC_SIZE];
};


struct ipa_wdi_conn_in_params {
	ipa_notify_cb notify;
	void *priv;
	bool is_smmu_enabled;
	u8 num_sys_pipe_needed;
	struct ipa_sys_connect_params sys_in[IPA_WDI_MAX_SUPPORTED_SYS_PIPE];
	union {
		struct ipa_wdi_pipe_setup_info tx;
		struct ipa_wdi_pipe_setup_info_smmu tx_smmu;
	} u_tx;
	union {
		struct ipa_wdi_pipe_setup_info rx;
		struct ipa_wdi_pipe_setup_info_smmu rx_smmu;
	} u_rx;
};


struct ipa_wdi_conn_out_params {
	phys_addr_t tx_uc_db_pa;
	phys_addr_t rx_uc_db_pa;
};


struct ipa_wdi_perf_profile {
	enum ipa_client_type client;
	u32 max_supported_bw_mbps;
};

#if defined CONFIG_IPA || defined CONFIG_IPA3


int ipa_wdi_init(struct ipa_wdi_init_in_params *in,
	struct ipa_wdi_init_out_params *out);


int ipa_wdi_cleanup(void);


int ipa_wdi_reg_intf(
	struct ipa_wdi_reg_intf_in_params *in);


int ipa_wdi_dereg_intf(const char *netdev_name);


int ipa_wdi_conn_pipes(struct ipa_wdi_conn_in_params *in,
	struct ipa_wdi_conn_out_params *out);


int ipa_wdi_disconn_pipes(void);


int ipa_wdi_enable_pipes(void);


int ipa_wdi_disable_pipes(void);


int ipa_wdi_set_perf_profile(struct ipa_wdi_perf_profile *profile);


int ipa_wdi_create_smmu_mapping(u32 num_buffers,
	struct ipa_wdi_buffer_info *info);


int ipa_wdi_release_smmu_mapping(u32 num_buffers,
	struct ipa_wdi_buffer_info *info);


int ipa_wdi_get_stats(struct IpaHwStatsWDIInfoData_t *stats);



int ipa_wdi_bw_monitor(struct ipa_wdi_bw_info *info);


int ipa_wdi_sw_stats(struct ipa_wdi_tx_info *info);

#else 

static inline int ipa_wdi_init(struct ipa_wdi_init_in_params *in,
	struct ipa_wdi_init_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wdi_cleanup(void)
{
	return -EPERM;
}

static inline int ipa_wdi_reg_intf(
	struct ipa_wdi_reg_intf_in_params *in)
{
	return -EPERM;
}

static inline int ipa_wdi_dereg_intf(const char *netdev_name)
{
	return -EPERM;
}

static inline int ipa_wdi_conn_pipes(struct ipa_wdi_conn_in_params *in,
	struct ipa_wdi_conn_out_params *out)
{
	return -EPERM;
}

static inline int ipa_wdi_disconn_pipes(void)
{
	return -EPERM;
}

static inline int ipa_wdi_enable_pipes(void)
{
	return -EPERM;
}

static inline int ipa_wdi_disable_pipes(void)
{
	return -EPERM;
}

static inline int ipa_wdi_set_perf_profile(
	struct ipa_wdi_perf_profile *profile)
{
	return -EPERM;
}

static inline int ipa_wdi_create_smmu_mapping(u32 num_buffers,
	struct ipa_wdi_buffer_info *info)
{
	return -EPERM;
}

static inline int ipa_wdi_release_smmu_mapping(u32 num_buffers,
	struct ipa_wdi_buffer_info *info)
{
	return -EPERM;
}

static inline int ipa_wdi_get_stats(struct IpaHwStatsWDIInfoData_t *stats)
{
	return -EPERM;
}

static inline int ipa_wdi_bw_monitor(struct ipa_wdi_bw_info *info)
{
	return -EPERM;
}

static inline int ipa_wdi_sw_stats(struct ipa_wdi_tx_info *info)
{
	return -EPERM;
}

#endif 

#endif 
