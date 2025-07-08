/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __QPNP_MISC_H
#define __QPNP_MISC_H

#include <linux/errno.h>

enum twm_state {
	PMIC_TWM_CLEAR,
	PMIC_TWM_ENABLE,
};

#ifdef CONFIG_QPNP_MISC


int qpnp_misc_irqs_available(struct device *consumer_dev);



int qpnp_misc_read_reg(struct device_node *node, u16 addr, u8 *val);

int qpnp_misc_twm_notifier_register(struct notifier_block *nb);


int qpnp_misc_twm_notifier_unregister(struct notifier_block *nb);
#else
static inline int qpnp_misc_irqs_available(struct device *consumer_dev)
{
	return 0;
}
static inline int qpnp_misc_read_reg(struct device_node *node, u16 addr,
					u8 *val)
{
	return 0;
}
static inline int qpnp_misc_twm_notifier_register(struct notifier_block *nb)
{
	return 0;
}
static inline int qpnp_misc_twm_notifier_unregister(struct notifier_block *nb)
{
	return 0;
}
#endif
#endif
