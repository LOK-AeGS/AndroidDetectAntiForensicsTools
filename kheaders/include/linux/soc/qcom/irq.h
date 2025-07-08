/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __QCOM_IRQ_H
#define __QCOM_IRQ_H

#include <linux/irqdomain.h>

#define GPIO_NO_WAKE_IRQ	~0U


struct qcom_irq_fwspec {
	struct irq_fwspec fwspec;
	bool mask;
};

#endif
