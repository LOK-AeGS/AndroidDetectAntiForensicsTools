/* SPDX-License-Identifier: GPL-2.0-only */



#ifndef _SUBSYS_NOTIFIER_H
#define _SUBSYS_NOTIFIER_H

#include <linux/notifier.h>

enum subsys_notif_type {
	SUBSYS_BEFORE_SHUTDOWN,
	SUBSYS_AFTER_SHUTDOWN,
	SUBSYS_BEFORE_POWERUP,
	SUBSYS_AFTER_POWERUP,
	SUBSYS_BEFORE_AUTH_AND_RESET,
	SUBSYS_RAMDUMP_NOTIFICATION,
	SUBSYS_POWERUP_FAILURE,
	SUBSYS_PROXY_VOTE,
	SUBSYS_PROXY_UNVOTE,
	SUBSYS_SOC_RESET,
	SUBSYS_NOTIF_TYPE_COUNT
};

enum early_subsys_notif_type {
	XPORT_LAYER_NOTIF,
	PCIE_DRV_LAYER_NOTIF,
	NUM_EARLY_NOTIFS
};

#if defined(CONFIG_MSM_SUBSYSTEM_RESTART)

void *subsys_notif_register_notifier(
			const char *subsys_name, struct notifier_block *nb);
int subsys_notif_unregister_notifier(void *subsys_handle,
				struct notifier_block *nb);


void *subsys_notif_add_subsys(const char *subsys_name);
int subsys_notif_queue_notification(void *subsys_handle,
					enum subsys_notif_type notif_type,
					void *data);
void *subsys_get_early_notif_info(const char *subsys_name);
int subsys_register_early_notifier(const char *subsys_name,
				   enum early_subsys_notif_type notif_type,
				   void (*early_notif_cb)(void *),
				   void *data);
int subsys_unregister_early_notifier(const char *subsys_name, enum
				     early_subsys_notif_type notif_type);
void send_early_notifications(void *early_notif_handle);
#else

static inline void *subsys_notif_register_notifier(
			const char *subsys_name, struct notifier_block *nb)
{
	return NULL;
}

static inline int subsys_notif_unregister_notifier(void *subsys_handle,
					struct notifier_block *nb)
{
	return 0;
}

static inline void *subsys_notif_add_subsys(const char *subsys_name)
{
	return NULL;
}

static inline int subsys_notif_queue_notification(void *subsys_handle,
					enum subsys_notif_type notif_type,
					void *data)
{
	return 0;
}

static inline void *subsys_get_early_notif_info(const char *subsys_name)
{
	return NULL;
}

static inline int subsys_register_early_notifier(const char *subsys_name,
				   enum early_subsys_notif_type notif_type,
				   void (*early_notif_cb)(void *),
				   void *data)
{
	return -ENOTSUPP;
}

static inline int subsys_unregister_early_notifier(const char *subsys_name,
						   enum early_subsys_notif_type
						   notif_type)
{
	return -ENOTSUPP;
}

static inline void send_early_notifications(void *early_notif_handle)
{
}
#endif 

#endif
