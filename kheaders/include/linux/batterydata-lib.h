/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __BMS_BATTERYDATA_H
#define __BMS_BATTERYDATA_H

#include <linux/errno.h>

#define FCC_CC_COLS		5
#define FCC_TEMP_COLS		8

#define PC_CC_ROWS             31
#define PC_CC_COLS             13

#define PC_TEMP_ROWS		31
#define PC_TEMP_COLS		8

#define ACC_IBAT_ROWS		4
#define ACC_TEMP_COLS		3

#define MAX_SINGLE_LUT_COLS	20

#define MAX_BATT_ID_NUM		4
#define DEGC_SCALE		10

struct single_row_lut {
	int x[MAX_SINGLE_LUT_COLS];
	int y[MAX_SINGLE_LUT_COLS];
	int cols;
};


struct sf_lut {
	int rows;
	int cols;
	int row_entries[PC_CC_COLS];
	int percent[PC_CC_ROWS];
	int sf[PC_CC_ROWS][PC_CC_COLS];
};


struct pc_temp_ocv_lut {
	int rows;
	int cols;
	int temp[PC_TEMP_COLS];
	int percent[PC_TEMP_ROWS];
	int ocv[PC_TEMP_ROWS][PC_TEMP_COLS];
};

struct ibat_temp_acc_lut {
	int rows;
	int cols;
	int temp[ACC_TEMP_COLS];
	int ibat[ACC_IBAT_ROWS];
	int acc[ACC_IBAT_ROWS][ACC_TEMP_COLS];
};

struct batt_ids {
	int kohm[MAX_BATT_ID_NUM];
	int num;
};

enum battery_type {
	BATT_UNKNOWN = 0,
	BATT_PALLADIUM,
	BATT_DESAY,
	BATT_OEM,
	BATT_QRD_4V35_2000MAH,
	BATT_QRD_4V2_1300MAH,
};



struct bms_battery_data {
	unsigned int		fcc;
	struct single_row_lut	*fcc_temp_lut;
	struct single_row_lut	*fcc_sf_lut;
	struct pc_temp_ocv_lut	*pc_temp_ocv_lut;
	struct ibat_temp_acc_lut *ibat_acc_lut;
	struct sf_lut		*pc_sf_lut;
	struct sf_lut		*rbatt_sf_lut;
	int			default_rbatt_mohm;
	int			delta_rbatt_mohm;
	int			rbatt_capacitive_mohm;
	int			flat_ocv_threshold_uv;
	int			max_voltage_uv;
	int			cutoff_uv;
	int			iterm_ua;
	int			batt_id_kohm;
	int			fastchg_current_ma;
	int			fg_cc_cv_threshold_mv;
	const char		*battery_type;
};


struct soh_range {
	int	batt_age_level;
	int	soh_min;
	int	soh_max;
};

#define is_between(left, right, value) \
		(((left) >= (right) && (left) >= (value) \
			&& (value) >= (right)) \
		|| ((left) <= (right) && (left) <= (value) \
			&& (value) <= (right)))

#if defined(CONFIG_PM8921_BMS) || \
	defined(CONFIG_PM8921_BMS_MODULE) || \
	defined(CONFIG_QPNP_BMS) || \
	defined(CONFIG_QPNP_VM_BMS)
extern struct bms_battery_data  palladium_1500_data;
extern struct bms_battery_data  desay_5200_data;
extern struct bms_battery_data  oem_batt_data;
extern struct bms_battery_data QRD_4v35_2000mAh_data;
extern struct bms_battery_data  qrd_4v2_1300mah_data;

int interpolate_fcc(struct single_row_lut *fcc_temp_lut, int batt_temp);
int interpolate_scalingfactor(struct sf_lut *sf_lut, int row_entry, int pc);
int interpolate_scalingfactor_fcc(struct single_row_lut *fcc_sf_lut,
				int cycles);
int interpolate_pc(struct pc_temp_ocv_lut *pc_temp_ocv,
				int batt_temp_degc, int ocv);
int interpolate_ocv(struct pc_temp_ocv_lut *pc_temp_ocv,
				int batt_temp_degc, int pc);
int interpolate_slope(struct pc_temp_ocv_lut *pc_temp_ocv,
					int batt_temp, int pc);
int interpolate_acc(struct ibat_temp_acc_lut *ibat_acc_lut,
					int batt_temp, int ibat);
int linear_interpolate(int y0, int x0, int y1, int x1, int x);
#else
static inline int interpolate_fcc(struct single_row_lut *fcc_temp_lut,
			int batt_temp)
{
	return -EINVAL;
}
static inline int interpolate_scalingfactor(struct sf_lut *sf_lut,
			int row_entry, int pc)
{
	return -EINVAL;
}
static inline int interpolate_scalingfactor_fcc(
			struct single_row_lut *fcc_sf_lut, int cycles)
{
	return -EINVAL;
}
static inline int interpolate_pc(struct pc_temp_ocv_lut *pc_temp_ocv,
			int batt_temp_degc, int ocv)
{
	return -EINVAL;
}
static inline int interpolate_ocv(struct pc_temp_ocv_lut *pc_temp_ocv,
			int batt_temp_degc, int pc)
{
	return -EINVAL;
}
static inline int interpolate_slope(struct pc_temp_ocv_lut *pc_temp_ocv,
					int batt_temp, int pc)
{
	return -EINVAL;
}
static inline int linear_interpolate(int y0, int x0, int y1, int x1, int x)
{
	return -EINVAL;
}
static inline int interpolate_acc(struct ibat_temp_acc_lut *ibat_acc_lut,
						int batt_temp, int ibat)
{
	return -EINVAL;
}
#endif

#endif
