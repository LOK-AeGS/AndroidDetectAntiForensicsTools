/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __LINUX_PINCTRL_MSM_H__
#define __LINUX_PINCTRL_MSM_H__

enum msm_gpio_wake {
	MSM_GPIO_WAKE_NONE = 0,
	MSM_GPIO_WAKE_DISABLED,
	MSM_GPIO_WAKE_ENABLED
};


int msm_qup_write(u32 mode, u32 val);
int msm_qup_read(u32 mode);


int msm_gpio_mpm_wake_set(unsigned int gpio, bool enable);
enum msm_gpio_wake msm_gpio_mpm_wake_get(unsigned int gpio);

#endif 
