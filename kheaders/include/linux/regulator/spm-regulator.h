/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _LINUX_REGULATOR_SPM_H
#define _LINUX_REGULATOR_SPM_H

#include <linux/err.h>
#include <linux/init.h>

#ifdef CONFIG_REGULATOR_SPM
int __init spm_regulator_init(void);
#else
static inline int __init spm_regulator_init(void) { return -ENODEV; }
#endif

#endif
