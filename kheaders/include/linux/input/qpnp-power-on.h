/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef QPNP_PON_H
#define QPNP_PON_H

#include <dt-bindings/input/qcom,qpnp-power-on.h>
#include <linux/errno.h>


enum pon_trigger_source {
	PON_SMPL = 1,
	PON_RTC,
	PON_DC_CHG,
	PON_USB_CHG,
	PON_PON1,
	PON_CBLPWR_N,
	PON_KPDPWR_N,
};


enum pon_power_off_type {
	PON_POWER_OFF_RESERVED		= 0x00,
	PON_POWER_OFF_WARM_RESET	= PON_POWER_OFF_TYPE_WARM_RESET,
	PON_POWER_OFF_SHUTDOWN		= PON_POWER_OFF_TYPE_SHUTDOWN,
	PON_POWER_OFF_HARD_RESET	= PON_POWER_OFF_TYPE_HARD_RESET,
	PON_POWER_OFF_MAX_TYPE		= 0x10,
};

#if IS_ENABLED(CONFIG_SEC_DEBUG)
#include <linux/sec_debug.h>
#else
enum pon_restart_reason {
	PON_RESTART_REASON_UNKNOWN		= 0x00,
	PON_RESTART_REASON_RECOVERY		= 0x01,
	PON_RESTART_REASON_BOOTLOADER		= 0x02,
	PON_RESTART_REASON_RTC			= 0x03,
	PON_RESTART_REASON_DMVERITY_CORRUPTED	= 0x04,
	PON_RESTART_REASON_DMVERITY_ENFORCE	= 0x05,
	PON_RESTART_REASON_KEYS_CLEAR		= 0x06,
};
#endif

#ifdef CONFIG_INPUT_QPNP_POWER_ON
int qpnp_pon_system_pwr_off(enum pon_power_off_type type);
int qpnp_pon_is_warm_reset(void);
int qpnp_pon_trigger_config(enum pon_trigger_source pon_src, bool enable);
int qpnp_pon_wd_config(bool enable);
int qpnp_pon_set_restart_reason(enum pon_restart_reason reason);
bool qpnp_pon_check_hard_reset_stored(void);
int qpnp_pon_modem_pwr_off(enum pon_power_off_type type);

#else

static int qpnp_pon_system_pwr_off(enum pon_power_off_type type)
{
	return -ENODEV;
}

static inline int qpnp_pon_is_warm_reset(void)
{
	return -ENODEV;
}

static inline int qpnp_pon_trigger_config(enum pon_trigger_source pon_src,
							bool enable)
{
	return -ENODEV;
}

int qpnp_pon_wd_config(bool enable)
{
	return -ENODEV;
}

static inline int qpnp_pon_set_restart_reason(enum pon_restart_reason reason)
{
	return -ENODEV;
}

static inline bool qpnp_pon_check_hard_reset_stored(void)
{
	return false;
}

static inline int qpnp_pon_modem_pwr_off(enum pon_power_off_type type)
{
	return -ENODEV;
}

#endif

#endif
