/* SPDX-License-Identifier: GPL-2.0-only */




#ifndef __QCOM_CDSPRM_H__
#define __QCOM_CDSPRM_H__


struct cdsprm_l3 {
	int (*set_l3_freq)(unsigned int freq_khz);
};


void cdsprm_register_cdspl3gov(struct cdsprm_l3 *arg);


void cdsprm_unregister_cdspl3gov(void);

#endif
