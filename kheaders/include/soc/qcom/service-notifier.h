/* SPDX-License-Identifier: GPL-2.0-only */



#ifndef _SERVICE_NOTIFIER_H
#define _SERVICE_NOTIFIER_H

enum qmi_servreg_notif_service_state_enum_type_v01 {
	QMI_SERVREG_NOTIF_SERVICE_STATE_ENUM_TYPE_MIN_VAL_V01 = INT_MIN,
	QMI_SERVREG_NOTIF_SERVICE_STATE_ENUM_TYPE_MAX_VAL_V01 = INT_MAX,
	SERVREG_NOTIF_SERVICE_STATE_DOWN_V01 = 0x0FFFFFFF,
	SERVREG_NOTIF_SERVICE_STATE_UP_V01 = 0x1FFFFFFF,
	SERVREG_NOTIF_SERVICE_STATE_EARLY_DOWN_V01 = 0x2FFFFFFF,
	SERVREG_NOTIF_SERVICE_STATE_UNINIT_V01 = 0x7FFFFFFF,
};

enum pd_subsys_state {
	ROOT_PD_DOWN,
	ROOT_PD_UP,
	ROOT_PD_ERR_FATAL,
	ROOT_PD_WDOG_BITE,
	ROOT_PD_SHUTDOWN,
	USER_PD_STATE_CHANGE,
};
#if defined(CONFIG_MSM_SERVICE_NOTIFIER)


void *service_notif_register_notifier(const char *service_path, int instance_id,
				struct notifier_block *nb, int *curr_state);


int service_notif_unregister_notifier(void *service_notif_handle,
					struct notifier_block *nb);

int service_notif_pd_restart(const char *service_path, int instance_id);

#else

static inline void *service_notif_register_notifier(const char *service_path,
				int instance_id, struct notifier_block *nb,
				int *curr_state)
{
	return ERR_PTR(-ENODEV);
}

static inline int service_notif_unregister_notifier(void *service_notif_handle,
					struct notifier_block *nb)
{
	return -ENODEV;
}

static inline int service_notif_pd_restart(const char *service_path,
						int instance_id)
{
	return -ENODEV;
}

#endif 

#endif
