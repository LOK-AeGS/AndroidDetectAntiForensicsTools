/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __QCOM_CRYPTO_DEVICE__H
#define __QCOM_CRYPTO_DEVICE__H

struct msm_ce_hw_support {
	uint32_t ce_shared;
	uint32_t shared_ce_resource;
	uint32_t hw_key_support;
	uint32_t sha_hmac;
	void *bus_scale_table;
};

#endif 
