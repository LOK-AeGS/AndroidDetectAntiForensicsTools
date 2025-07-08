/* SPDX-License-Identifier: GPL-2.0-only */


#include <linux/slimbus/slimbus.h>
#include <linux/of_irq.h>

#ifdef CONFIG_OF_SLIMBUS

extern int of_register_slim_devices(struct slim_controller *ctrl);
#else
static int of_register_slim_devices(struct slim_controller *ctrl)
{
	return 0;
}
#endif 
