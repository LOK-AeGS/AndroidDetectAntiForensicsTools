/* SPDX-License-Identifier: GPL-2.0 */



#ifndef __QPNP_ADC_H
#define __QPNP_ADC_H

#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/qpnp/qpnp-revid.h>
#include <linux/regulator/consumer.h>

enum qpnp_vadc_channels {
	USBIN = 0,
	DCIN,
	VCHG_SNS,
	SPARE1_03,
	USB_ID_MV,
	VCOIN,
	VBAT_SNS,
	VSYS,
	DIE_TEMP,
	REF_625MV,
	REF_125V,
	CHG_TEMP,
	SPARE1,
	SPARE2,
	GND_REF,
	VDD_VADC,
	P_MUX1_1_1,
	P_MUX2_1_1,
	P_MUX3_1_1,
	P_MUX4_1_1,
	P_MUX5_1_1,
	P_MUX6_1_1,
	P_MUX7_1_1,
	P_MUX8_1_1,
	P_MUX9_1_1,
	P_MUX10_1_1,
	P_MUX11_1_1,
	P_MUX12_1_1,
	P_MUX13_1_1,
	P_MUX14_1_1,
	P_MUX15_1_1,
	P_MUX16_1_1,
	P_MUX1_1_3,
	P_MUX2_1_3,
	P_MUX3_1_3,
	P_MUX4_1_3,
	P_MUX5_1_3,
	P_MUX6_1_3,
	P_MUX7_1_3,
	P_MUX8_1_3,
	P_MUX9_1_3,
	P_MUX10_1_3,
	P_MUX11_1_3,
	P_MUX12_1_3,
	P_MUX13_1_3,
	P_MUX14_1_3,
	P_MUX15_1_3,
	P_MUX16_1_3,
	LR_MUX1_BATT_THERM,
	LR_MUX2_BAT_ID,
	LR_MUX3_XO_THERM,
	LR_MUX4_AMUX_THM1,
	LR_MUX5_AMUX_THM2,
	LR_MUX6_AMUX_THM3,
	LR_MUX7_HW_ID,
	LR_MUX8_AMUX_THM4,
	LR_MUX9_AMUX_THM5,
	LR_MUX10_USB_ID_LV,
	AMUX_PU1,
	AMUX_PU2,
	LR_MUX3_BUF_XO_THERM_BUF,
	LR_MUX1_PU1_BAT_THERM = 112,
	LR_MUX2_PU1_BAT_ID = 113,
	LR_MUX3_PU1_XO_THERM = 114,
	LR_MUX4_PU1_AMUX_THM1 = 115,
	LR_MUX5_PU1_AMUX_THM2 = 116,
	LR_MUX6_PU1_AMUX_THM3 = 117,
	LR_MUX7_PU1_AMUX_HW_ID = 118,
	LR_MUX8_PU1_AMUX_THM4 = 119,
	LR_MUX9_PU1_AMUX_THM5 = 120,
	LR_MUX10_PU1_AMUX_USB_ID_LV = 121,
	LR_MUX3_BUF_PU1_XO_THERM_BUF = 124,
	LR_MUX1_PU2_BAT_THERM = 176,
	LR_MUX2_PU2_BAT_ID = 177,
	LR_MUX3_PU2_XO_THERM = 178,
	LR_MUX4_PU2_AMUX_THM1 = 179,
	LR_MUX5_PU2_AMUX_THM2 = 180,
	LR_MUX6_PU2_AMUX_THM3 = 181,
	LR_MUX7_PU2_AMUX_HW_ID = 182,
	LR_MUX8_PU2_AMUX_THM4 = 183,
	LR_MUX9_PU2_AMUX_THM5 = 184,
	LR_MUX10_PU2_AMUX_USB_ID_LV = 185,
	LR_MUX3_BUF_PU2_XO_THERM_BUF = 188,
	LR_MUX1_PU1_PU2_BAT_THERM = 240,
	LR_MUX2_PU1_PU2_BAT_ID = 241,
	LR_MUX3_PU1_PU2_XO_THERM = 242,
	LR_MUX4_PU1_PU2_AMUX_THM1 = 243,
	LR_MUX5_PU1_PU2_AMUX_THM2 = 244,
	LR_MUX6_PU1_PU2_AMUX_THM3 = 245,
	LR_MUX7_PU1_PU2_AMUX_HW_ID = 246,
	LR_MUX8_PU1_PU2_AMUX_THM4 = 247,
	LR_MUX9_PU1_PU2_AMUX_THM5 = 248,
	LR_MUX10_PU1_PU2_AMUX_USB_ID_LV = 249,
	LR_MUX3_BUF_PU1_PU2_XO_THERM_BUF = 252,
	ALL_OFF = 255,
	ADC_MAX_NUM = 0xffff,
};

#define QPNP_ADC_625_UV		625000
#define QPNP_MAX_PROP_NAME_LEN	32


struct qpnp_adc_tm_chip;


enum qpnp_adc_decimation_type {
	DECIMATION_TYPE1 = 0,
	DECIMATION_TYPE2,
	DECIMATION_TYPE3,
	DECIMATION_TYPE4,
	DECIMATION_NONE = 0xff,
};


enum qpnp_adc_calib_type {
	CALIB_ABSOLUTE = 0,
	CALIB_RATIOMETRIC,
	CALIB_NONE,
};


enum qpnp_adc_channel_scaling_param {
	PATH_SCALING0 = 0,
	PATH_SCALING1,
	PATH_SCALING2,
	PATH_SCALING3,
	PATH_SCALING4,
	PATH_SCALING5,
	PATH_SCALING6,
	PATH_SCALING7,
	PATH_SCALING8,
	PATH_SCALING_NONE,
};


enum qpnp_adc_tm_rscale_fn_type {
	SCALE_R_VBATT = 0,
	SCALE_RBATT_THERM,
	SCALE_R_USB_ID,
	SCALE_RPMIC_THERM,
	SCALE_R_SMB_BATT_THERM,
	SCALE_R_ABSOLUTE,
	SCALE_QRD_SKUH_RBATT_THERM,
	SCALE_QRD_SKUT1_RBATT_THERM,
	SCALE_QRD_215_RBATT_THERM,
	SCALE_RSCALE_NONE,
};


enum qpnp_adc_fast_avg_ctl {
	ADC_FAST_AVG_SAMPLE_1 = 0,
	ADC_FAST_AVG_SAMPLE_2,
	ADC_FAST_AVG_SAMPLE_4,
	ADC_FAST_AVG_SAMPLE_8,
	ADC_FAST_AVG_SAMPLE_16,
	ADC_FAST_AVG_SAMPLE_32,
	ADC_FAST_AVG_SAMPLE_64,
	ADC_FAST_AVG_SAMPLE_128,
	ADC_FAST_AVG_SAMPLE_256,
	ADC_FAST_AVG_SAMPLE_512,
	ADC_FAST_AVG_SAMPLE_NONE,
};


enum qpnp_adc_hw_settle_time {
	ADC_CHANNEL_HW_SETTLE_DELAY_0US = 0,
	ADC_CHANNEL_HW_SETTLE_DELAY_100US,
	ADC_CHANNEL_HW_SETTLE_DELAY_2000US,
	ADC_CHANNEL_HW_SETTLE_DELAY_300US,
	ADC_CHANNEL_HW_SETTLE_DELAY_400US,
	ADC_CHANNEL_HW_SETTLE_DELAY_500US,
	ADC_CHANNEL_HW_SETTLE_DELAY_600US,
	ADC_CHANNEL_HW_SETTLE_DELAY_700US,
	ADC_CHANNEL_HW_SETTLE_DELAY_800US,
	ADC_CHANNEL_HW_SETTLE_DELAY_900US,
	ADC_CHANNEL_HW_SETTLE_DELAY_1MS,
	ADC_CHANNEL_HW_SETTLE_DELAY_2MS,
	ADC_CHANNEL_HW_SETTLE_DELAY_4MS,
	ADC_CHANNEL_HW_SETTLE_DELAY_6MS,
	ADC_CHANNEL_HW_SETTLE_DELAY_8MS,
	ADC_CHANNEL_HW_SETTLE_DELAY_10MS,
	ADC_CHANNEL_HW_SETTLE_NONE,
};


enum qpnp_vadc_dec_ratio_sel {
	ADC_DEC_RATIO_256 = 0,
	ADC_DEC_RATIO_512,
	ADC_DEC_RATIO_1024,
	ADC_DEC_RATIO_NONE,
};


enum qpnp_vadc_mode_sel {
	ADC_OP_NORMAL_MODE = 0,
	ADC_OP_CONVERSION_SEQUENCER,
	ADC_OP_MEASUREMENT_INTERVAL,
	ADC_OP_MODE_NONE,
};


enum qpnp_adc_meas_timer_1 {
	ADC_MEAS1_INTERVAL_0MS = 0,
	ADC_MEAS1_INTERVAL_1P0MS,
	ADC_MEAS1_INTERVAL_2P0MS,
	ADC_MEAS1_INTERVAL_3P9MS,
	ADC_MEAS1_INTERVAL_7P8MS,
	ADC_MEAS1_INTERVAL_15P6MS,
	ADC_MEAS1_INTERVAL_31P3MS,
	ADC_MEAS1_INTERVAL_62P5MS,
	ADC_MEAS1_INTERVAL_125MS,
	ADC_MEAS1_INTERVAL_250MS,
	ADC_MEAS1_INTERVAL_500MS,
	ADC_MEAS1_INTERVAL_1S,
	ADC_MEAS1_INTERVAL_2S,
	ADC_MEAS1_INTERVAL_4S,
	ADC_MEAS1_INTERVAL_8S,
	ADC_MEAS1_INTERVAL_16S,
	ADC_MEAS1_INTERVAL_NONE,
};


enum qpnp_adc_meas_timer_2 {
	ADC_MEAS2_INTERVAL_0MS = 0,
	ADC_MEAS2_INTERVAL_100MS,
	ADC_MEAS2_INTERVAL_200MS,
	ADC_MEAS2_INTERVAL_300MS,
	ADC_MEAS2_INTERVAL_400MS,
	ADC_MEAS2_INTERVAL_500MS,
	ADC_MEAS2_INTERVAL_600MS,
	ADC_MEAS2_INTERVAL_700MS,
	ADC_MEAS2_INTERVAL_800MS,
	ADC_MEAS2_INTERVAL_900MS,
	ADC_MEAS2_INTERVAL_1S,
	ADC_MEAS2_INTERVAL_1P1S,
	ADC_MEAS2_INTERVAL_1P2S,
	ADC_MEAS2_INTERVAL_1P3S,
	ADC_MEAS2_INTERVAL_1P4S,
	ADC_MEAS2_INTERVAL_1P5S,
	ADC_MEAS2_INTERVAL_NONE,
};


enum qpnp_adc_meas_timer_3 {
	ADC_MEAS3_INTERVAL_0S = 0,
	ADC_MEAS3_INTERVAL_1S,
	ADC_MEAS3_INTERVAL_2S,
	ADC_MEAS3_INTERVAL_3S,
	ADC_MEAS3_INTERVAL_4S,
	ADC_MEAS3_INTERVAL_5S,
	ADC_MEAS3_INTERVAL_6S,
	ADC_MEAS3_INTERVAL_7S,
	ADC_MEAS3_INTERVAL_8S,
	ADC_MEAS3_INTERVAL_9S,
	ADC_MEAS3_INTERVAL_10S,
	ADC_MEAS3_INTERVAL_11S,
	ADC_MEAS3_INTERVAL_12S,
	ADC_MEAS3_INTERVAL_13S,
	ADC_MEAS3_INTERVAL_14S,
	ADC_MEAS3_INTERVAL_15S,
	ADC_MEAS3_INTERVAL_NONE,
};


enum qpnp_adc_meas_timer_select {
	ADC_MEAS_TIMER_SELECT1 = 0,
	ADC_MEAS_TIMER_SELECT2,
	ADC_MEAS_TIMER_SELECT3,
	ADC_MEAS_TIMER_NUM,
};


enum qpnp_adc_tm_channel_select	{
	QPNP_ADC_TM_M0_ADC_CH_SEL_CTL = 0x48,
	QPNP_ADC_TM_M1_ADC_CH_SEL_CTL = 0x68,
	QPNP_ADC_TM_M2_ADC_CH_SEL_CTL = 0x70,
	QPNP_ADC_TM_M3_ADC_CH_SEL_CTL = 0x78,
	QPNP_ADC_TM_M4_ADC_CH_SEL_CTL = 0x80,
	QPNP_ADC_TM_M5_ADC_CH_SEL_CTL = 0x88,
	QPNP_ADC_TM_M6_ADC_CH_SEL_CTL = 0x90,
	QPNP_ADC_TM_M7_ADC_CH_SEL_CTL = 0x98,
	QPNP_ADC_TM_CH_SELECT_NONE
};


enum qpnp_adc_tm_channel_num {
	QPNP_ADC_TM_CHAN0 = 0,
	QPNP_ADC_TM_CHAN1,
	QPNP_ADC_TM_CHAN2,
	QPNP_ADC_TM_CHAN3,
	QPNP_ADC_TM_CHAN4,
	QPNP_ADC_TM_CHAN5,
	QPNP_ADC_TM_CHAN6,
	QPNP_ADC_TM_CHAN7,
	QPNP_ADC_TM_CHAN_NONE
};


struct qpnp_adc_tm_config {
	int	channel;
	int	adc_code;
	int	high_thr_temp;
	int	low_thr_temp;
	int64_t	high_thr_voltage;
	int64_t	low_thr_voltage;
};


enum qpnp_adc_tm_trip_type {
	ADC_TM_TRIP_HIGH_WARM = 0,
	ADC_TM_TRIP_LOW_COOL,
	ADC_TM_TRIP_NUM,
};

#define ADC_TM_WRITABLE_TRIPS_MASK ((1 << ADC_TM_TRIP_NUM) - 1)


enum qpnp_tm_state {
	ADC_TM_HIGH_STATE = 0,
	ADC_TM_COOL_STATE = ADC_TM_HIGH_STATE,
	ADC_TM_LOW_STATE,
	ADC_TM_WARM_STATE = ADC_TM_LOW_STATE,
	ADC_TM_STATE_NUM,
};


enum qpnp_state_request {
	ADC_TM_HIGH_THR_ENABLE = 0,
	ADC_TM_COOL_THR_ENABLE = ADC_TM_HIGH_THR_ENABLE,
	ADC_TM_LOW_THR_ENABLE,
	ADC_TM_WARM_THR_ENABLE = ADC_TM_LOW_THR_ENABLE,
	ADC_TM_HIGH_LOW_THR_ENABLE,
	ADC_TM_HIGH_THR_DISABLE,
	ADC_TM_COOL_THR_DISABLE = ADC_TM_HIGH_THR_DISABLE,
	ADC_TM_LOW_THR_DISABLE,
	ADC_TM_WARM_THR_DISABLE = ADC_TM_LOW_THR_DISABLE,
	ADC_TM_HIGH_LOW_THR_DISABLE,
	ADC_TM_THR_NUM,
};


struct qpnp_adc_tm_btm_param {
	uint32_t				full_scale_code;
	int32_t					high_temp;
	int32_t					low_temp;
	int32_t					high_thr;
	int32_t					low_thr;
	int32_t					gain_num;
	int32_t					gain_den;
	enum qpnp_vadc_channels			channel;
	enum qpnp_state_request			state_request;
	enum qpnp_adc_meas_timer_1		timer_interval;
	enum qpnp_adc_meas_timer_2		timer_interval2;
	enum qpnp_adc_meas_timer_3		timer_interval3;
	void					*btm_ctx;
	void	(*threshold_notification)(enum qpnp_tm_state state,
						void *ctx);
};


struct qpnp_vadc_linear_graph {
	int64_t dy;
	int64_t dx;
	int64_t adc_vref;
	int64_t adc_gnd;
};


struct qpnp_vadc_map_pt {
	int32_t x;
	int32_t y;
};


struct qpnp_vadc_scaling_ratio {
	int32_t num;
	int32_t den;
};


struct qpnp_adc_properties {
	uint32_t	adc_vdd_reference;
	uint32_t	full_scale_code;
	bool		bipolar;
};


struct qpnp_vadc_chan_properties {
	uint32_t			offset_gain_numerator;
	uint32_t			offset_gain_denominator;
	uint32_t				high_thr;
	uint32_t				low_thr;
	enum qpnp_adc_meas_timer_select		timer_select;
	enum qpnp_adc_meas_timer_1		meas_interval1;
	enum qpnp_adc_meas_timer_2		meas_interval2;
	enum qpnp_adc_tm_channel_select		tm_channel_select;
	enum qpnp_state_request			state_request;
	enum qpnp_adc_calib_type		calib_type;
	struct qpnp_vadc_linear_graph		adc_graph[CALIB_NONE];
};


struct qpnp_adc_amux {
	char					*name;
	enum qpnp_vadc_channels			channel_num;
	enum qpnp_adc_channel_scaling_param	chan_path_prescaling;
	enum qpnp_adc_decimation_type		adc_decimation;
	enum qpnp_adc_tm_rscale_fn_type		adc_scale_fn;
	enum qpnp_adc_fast_avg_ctl		fast_avg_setup;
	enum qpnp_adc_hw_settle_time		hw_settle_time;
	enum qpnp_adc_calib_type		calib_type;
};


static const struct qpnp_vadc_scaling_ratio qpnp_vadc_amux_scaling_ratio[] = {
	{1, 1},
	{1, 3},
	{1, 4},
	{1, 6},
	{1, 20},
	{1, 8},
	{10, 81},
	{1, 10},
	{1, 16}
};


struct qpnp_adc_drv {
	struct platform_device		*pdev;
	struct regmap			*regmap;
	uint16_t			offset;
	struct qpnp_adc_properties	*adc_prop;
	struct qpnp_adc_amux_properties	*amux_prop;
	struct qpnp_adc_amux		*adc_channels;
	int				adc_irq_eoc;
	int				adc_irq_fifo_not_empty;
	int				adc_irq_conv_seq_timeout;
	int				adc_high_thr_irq;
	int				adc_low_thr_irq;
	struct mutex			adc_lock;
};


struct qpnp_adc_amux_properties {
	uint32_t				amux_channel;
	uint32_t				decimation;
	uint32_t				mode_sel;
	uint32_t				hw_settle_time;
	uint32_t				fast_avg_setup;
	enum qpnp_adc_calib_type		calib_type;
	struct qpnp_vadc_chan_properties	chan_prop[0];
};


#define QPNP_REV_ID_8941_3_1	1
#define QPNP_REV_ID_8026_1_0	2
#define QPNP_REV_ID_8026_2_0	3
#define QPNP_REV_ID_8110_1_0	4
#define QPNP_REV_ID_8026_2_1	5
#define QPNP_REV_ID_8110_2_0	6
#define QPNP_REV_ID_8026_2_2	7
#define QPNP_REV_ID_8941_3_0	8
#define QPNP_REV_ID_8941_2_0	9
#define QPNP_REV_ID_8916_1_0	10
#define QPNP_REV_ID_8916_1_1	11
#define QPNP_REV_ID_8916_2_0	12
#define QPNP_REV_ID_8909_1_0	13
#define QPNP_REV_ID_8909_1_1	14
#define QPNP_REV_ID_PM8950_1_0	16


struct qpnp_adc_tm_reverse_scale_fn {
	int32_t (*chan)(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);
};



int32_t qpnp_adc_get_devicetree_data(struct platform_device *pdev,
					struct qpnp_adc_drv *adc_qpnp);


int32_t qpnp_adc_qrd_215_btm_scaler(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);


int32_t qpnp_adc_tm_scale_therm_voltage_pu2(struct qpnp_adc_drv *adc,
		const struct qpnp_adc_properties *adc_properties,
				struct qpnp_adc_tm_config *param);


int32_t qpnp_adc_usb_scaler(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);

int32_t qpnp_adc_vbatt_rscaler(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);

int32_t qpnp_adc_absolute_rthr(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);

int32_t qpnp_adc_smb_btm_rscaler(struct qpnp_adc_drv *adc,
		struct qpnp_adc_tm_btm_param *param,
		uint32_t *low_threshold, uint32_t *high_threshold);


int qpnp_adc_get_revid_version(struct device *dev);



int32_t qpnp_adc_tm_channel_measure(struct qpnp_adc_tm_chip *chip,
					struct qpnp_adc_tm_btm_param *param);

int32_t qpnp_adc_tm_disable_chan_meas(struct qpnp_adc_tm_chip *chip,
					struct qpnp_adc_tm_btm_param *param);

struct qpnp_adc_tm_chip *qpnp_get_adc_tm(struct device *dev, const char *name);
#endif
