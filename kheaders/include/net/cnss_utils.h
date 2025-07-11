/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _CNSS_UTILS_H_
#define _CNSS_UTILS_H_

enum cnss_utils_cc_src {
	CNSS_UTILS_SOURCE_CORE,
	CNSS_UTILS_SOURCE_11D,
	CNSS_UTILS_SOURCE_USER
};

extern int cnss_utils_set_wlan_unsafe_channel(struct device *dev,
					      u16 *unsafe_ch_list,
					      u16 ch_count);
extern int cnss_utils_get_wlan_unsafe_channel(struct device *dev,
					      u16 *unsafe_ch_list,
					      u16 *ch_count, u16 buf_len);
extern int cnss_utils_wlan_set_dfs_nol(struct device *dev,
				       const void *info, u16 info_len);
extern int cnss_utils_wlan_get_dfs_nol(struct device *dev,
				       void *info, u16 info_len);
extern int cnss_utils_get_driver_load_cnt(struct device *dev);
extern void cnss_utils_increment_driver_load_cnt(struct device *dev);
extern int cnss_utils_set_wlan_mac_address(const u8 *in, uint32_t len);
extern u8 *cnss_utils_get_wlan_mac_address(struct device *dev, uint32_t *num);
extern int cnss_utils_set_wlan_derived_mac_address(const u8 *in, uint32_t len);
extern u8 *cnss_utils_get_wlan_derived_mac_address(struct device *dev,
							uint32_t *num);
extern void cnss_utils_set_cc_source(struct device *dev,
				     enum cnss_utils_cc_src cc_source);
extern enum cnss_utils_cc_src cnss_utils_get_cc_source(struct device *dev);

#endif
