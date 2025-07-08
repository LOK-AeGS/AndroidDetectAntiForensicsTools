// SPDX-License-Identifier: GPL-2.0-only


#ifndef _LINUX_REGULATOR_RPM_SMD_H
#define _LINUX_REGULATOR_RPM_SMD_H

#include <linux/device.h>

struct rpm_regulator;


enum rpm_regulator_voltage_corner {
	RPM_REGULATOR_CORNER_NONE = 1,
	RPM_REGULATOR_CORNER_RETENTION,
	RPM_REGULATOR_CORNER_SVS_KRAIT,
	RPM_REGULATOR_CORNER_SVS_SOC,
	RPM_REGULATOR_CORNER_NORMAL,
	RPM_REGULATOR_CORNER_TURBO,
	RPM_REGULATOR_CORNER_SUPER_TURBO,
};


enum rpm_regulator_voltage_level {
	RPM_REGULATOR_LEVEL_NONE		= 0,
	RPM_REGULATOR_LEVEL_RETENTION		= 16,
	RPM_REGULATOR_LEVEL_RETENTION_PLUS	= 32,
	RPM_REGULATOR_LEVEL_MIN_SVS		= 48,
	RPM_REGULATOR_LEVEL_LOW_SVS		= 64,
	RPM_REGULATOR_LEVEL_SVS			= 128,
	RPM_REGULATOR_LEVEL_SVS_PLUS		= 192,
	RPM_REGULATOR_LEVEL_NOM			= 256,
	RPM_REGULATOR_LEVEL_NOM_PLUS		= 320,
	RPM_REGULATOR_LEVEL_TURBO		= 384,
	RPM_REGULATOR_LEVEL_TURBO_NO_CPR	= 416,
	RPM_REGULATOR_LEVEL_BINNING		= 512,
	RPM_REGULATOR_LEVEL_MAX			= 65535,
};


enum rpm_regulator_mode {
	RPM_REGULATOR_MODE_AUTO,
	RPM_REGULATOR_MODE_IPEAK,
	RPM_REGULATOR_MODE_HPM,
};

#ifdef CONFIG_REGULATOR_RPM_SMD

struct rpm_regulator *rpm_regulator_get(struct device *dev, const char *supply);

void rpm_regulator_put(struct rpm_regulator *regulator);

int rpm_regulator_enable(struct rpm_regulator *regulator);

int rpm_regulator_disable(struct rpm_regulator *regulator);

int rpm_regulator_set_voltage(struct rpm_regulator *regulator, int min_uV,
			      int max_uV);

int rpm_regulator_set_mode(struct rpm_regulator *regulator,
				enum rpm_regulator_mode mode);

int __init rpm_smd_regulator_driver_init(void);

#else

static inline struct rpm_regulator *rpm_regulator_get(struct device *dev,
					const char *supply) { return NULL; }

static inline void rpm_regulator_put(struct rpm_regulator *regulator) { }

static inline int rpm_regulator_enable(struct rpm_regulator *regulator)
			{ return 0; }

static inline int rpm_regulator_disable(struct rpm_regulator *regulator)
			{ return 0; }

static inline int rpm_regulator_set_voltage(struct rpm_regulator *regulator,
					int min_uV, int max_uV) { return 0; }

static inline int rpm_regulator_set_mode(struct rpm_regulator *regulator,
				enum rpm_regulator_mode mode) { return 0; }

static inline int __init rpm_smd_regulator_driver_init(void) { return 0; }

#endif 
#endif
