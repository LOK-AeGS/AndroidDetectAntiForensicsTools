

#ifndef PHY_QCOM_UFS_H_
#define PHY_QCOM_UFS_H_

#include "phy.h"


void ufs_qcom_phy_enable_dev_ref_clk(struct phy *phy);


void ufs_qcom_phy_disable_dev_ref_clk(struct phy *phy);

int ufs_qcom_phy_start_serdes(struct phy *generic_phy);
int ufs_qcom_phy_is_pcs_ready(struct phy *generic_phy);
int ufs_qcom_phy_calibrate_phy(struct phy *generic_phy, bool is_rate_B,
			       bool is_g4);
int ufs_qcom_phy_set_tx_lane_enable(struct phy *phy, u32 tx_lanes);
int ufs_qcom_phy_ctrl_rx_linecfg(struct phy *generic_phy, bool ctrl);
void ufs_qcom_phy_save_controller_version(struct phy *phy,
			u8 major, u16 minor, u16 step);
const char *ufs_qcom_phy_name(struct phy *phy);
int ufs_qcom_phy_configure_lpm(struct phy *generic_phy, bool enable);
void ufs_qcom_phy_dbg_register_dump(struct phy *generic_phy);

#endif 
