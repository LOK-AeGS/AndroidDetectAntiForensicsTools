/* SPDX-License-Identifier: GPL-2.0 */


#include <linux/of.h>
#include <linux/batterydata-lib.h>

#ifdef CONFIG_OF_BATTERYDATA

int of_batterydata_read_data(struct device_node *container_node,
				struct bms_battery_data *batt_data,
				int batt_id_uv);

struct device_node *of_batterydata_get_best_profile(
		const struct device_node *batterydata_container_node,
		int batt_id_kohm, const char *batt_type);


struct device_node *of_batterydata_get_best_aged_profile(
		const struct device_node *batterydata_container_node,
		int batt_id_kohm, int batt_age_level, int *avail_age_level);


int of_batterydata_get_aged_profile_count(
		const struct device_node *batterydata_node,
		int batt_id_kohm, int *count);


int of_batterydata_read_soh_aged_profiles(
		const struct device_node *batterydata_node,
		int batt_id_kohm, struct soh_range *soh_data);
#else
static inline int of_batterydata_read_data(struct device_node *container_node,
				struct bms_battery_data *batt_data,
				int batt_id_uv)
{
	return -ENXIO;
}
static inline struct device_node *of_batterydata_get_best_profile(
		const struct device_node *batterydata_container_node,
		int batt_id_kohm, const char *batt_type)
{
	return NULL;
}
static inline struct device_node *of_batterydata_get_best_aged_profile(
		const struct device_node *batterydata_container_node,
		int batt_id_kohm, u32 batt_age_level)
{
	return NULL;
}
static inline int of_batterydata_get_aged_profile_count(
		const struct device_node *batterydata_node,
		int batt_id_kohm, int *count)
{
	return -EINVAL;
}
static inline int of_batterydata_read_soh_aged_profiles(
		const struct device_node *batterydata_node,
		int batt_id_kohm, struct soh_range *soh_data)
{
	return -EINVAL;
}
#endif 
