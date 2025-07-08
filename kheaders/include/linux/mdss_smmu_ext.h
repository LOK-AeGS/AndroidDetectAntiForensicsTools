/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef MDSS_SMMU_EXT_H
#define MDSS_SMMU_EXT_H


struct mdss_smmu_intf {
	struct device *dev;
	int domain;
	bool is_secure;
	int (*iommu_ctrl)(int i);
	int (*secure_session_ctrl)(int i);
	int (*wait_for_transition)(int state, int request);
	void (*reg_lock)(void);
	void (*reg_unlock)(void);
	bool (*handoff_pending)(void);
};

typedef void (*msm_smmu_handler_t) (struct mdss_smmu_intf *smmu);


#ifdef CONFIG_FB_MSM_MDSS
int mdss_smmu_request_mappings(msm_smmu_handler_t callback);
#else
static inline int mdss_smmu_request_mappings(msm_smmu_handler_t callback)
{
	return 0;
}
#endif
#endif 
