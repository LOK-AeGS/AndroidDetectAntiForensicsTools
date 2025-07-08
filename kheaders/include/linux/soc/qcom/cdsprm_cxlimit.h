/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __QCOM_CDSPRM_LIMITS_H__
#define __QCOM_CDSPRM_LIMITS_H__

enum cdsprm_npu_corner {
	CDSPRM_NPU_CLK_OFF = 0,
	CDSPRM_NPU_MIN_SVS,
	CDSPRM_NPU_LOW_SVS,
	CDSPRM_NPU_SVS,
	CDSPRM_NPU_SVS_L1,
	CDSPRM_NPU_NOM,
	CDSPRM_NPU_NOM_L1,
	CDSPRM_NPU_TURBO,
	CDSPRM_NPU_TURBO_L1,
};

struct cdsprm_npu_limit_cbs {
	int (*set_corner_limit)(enum cdsprm_npu_corner);
};

enum cdsprm_compute_priority {
	CDSPRM_COMPUTE_HVX_MAX = 1,
	CDSPRM_COMPUTE_AIX_MAX = 2,
	CDSPRM_COMPUTE_HVX_OVER_AIX = 3,
	CDSPRM_COMPUTE_AIX_OVER_HVX = 4,
	CDSPRM_COMPUTE_BALANCED = 5,
};

int cdsprm_compute_core_set_priority(enum cdsprm_compute_priority);




int cdsprm_cxlimit_npu_limit_register(const struct cdsprm_npu_limit_cbs *arg);

int cdsprm_cxlimit_npu_limit_deregister(void);

int cdsprm_cxlimit_npu_activity_notify(unsigned int b_enabled);

enum cdsprm_npu_corner cdsprm_cxlimit_npu_corner_notify(enum cdsprm_npu_corner);




int cdsprm_cxlimit_camera_activity_notify(unsigned int b_enabled);

#endif
