/* SPDX-License-Identifier: GPL-2.0-only */


#include <linux/notifier.h>

int show_mem_notifier_register(struct notifier_block *nb);

int show_mem_notifier_unregister(struct notifier_block *nb);

void show_mem_call_notifiers(void);
