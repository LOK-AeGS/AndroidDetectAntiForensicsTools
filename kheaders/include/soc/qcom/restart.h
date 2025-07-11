/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _ASM_ARCH_MSM_RESTART_H_
#define _ASM_ARCH_MSM_RESTART_H_

#define RESTART_NORMAL 0x0
#define RESTART_DLOAD  0x1

void msm_set_restart_mode(int mode);
extern int pmic_reset_irq;

#endif

