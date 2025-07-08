/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __REGULATOR_CPR_REGULATOR_H__
#define __REGULATOR_CPR_REGULATOR_H__

#include <linux/init.h>

#ifdef CONFIG_REGULATOR_CPR

int __init cpr_regulator_init(void);

#else

static inline int __init cpr_regulator_init(void)
{
	return -ENODEV;
}

#endif 

#endif 
