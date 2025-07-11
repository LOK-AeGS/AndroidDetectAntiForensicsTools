/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __QCOM_ADC_TM_H_CLIENTS__
#define __QCOM_ADC_TM_H_CLIENTS__

struct adc_tm_chip;


enum adc_tm_state {
	ADC_TM_HIGH_STATE = 0,
	ADC_TM_COOL_STATE = ADC_TM_HIGH_STATE,
	ADC_TM_LOW_STATE,
	ADC_TM_WARM_STATE = ADC_TM_LOW_STATE,
	ADC_TM_STATE_NUM,
};


enum adc_tm_state_request {
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

struct adc_tm_param {
	unsigned long		id;
	int			low_thr;
	int			high_thr;
	uint32_t				channel;
	enum adc_tm_state_request	state_request;
	void					*btm_ctx;
	void	(*threshold_notification)(enum adc_tm_state state,
						void *ctx);
};


#if defined(CONFIG_QTI_ADC_TM)
struct adc_tm_chip *get_adc_tm(struct device *dev, const char *name);
int32_t adc_tm5_channel_measure(struct adc_tm_chip *chip,
					struct adc_tm_param *param);
int32_t adc_tm5_disable_chan_meas(struct adc_tm_chip *chip,
					struct adc_tm_param *param);

#else
static inline struct adc_tm_chip *get_adc_tm(
	struct device *dev, const char *name)
{ return ERR_PTR(-ENXIO); }

static inline int32_t adc_tm5_channel_measure(
					struct adc_tm_chip *chip,
					struct adc_tm_param *param)
{ return -ENXIO; }
static inline int32_t adc_tm5_disable_chan_meas(
					struct adc_tm_chip *chip,
					struct adc_tm_param *param)
{ return -ENXIO; }

#endif

#endif 
