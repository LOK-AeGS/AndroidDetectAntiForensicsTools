/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _ASM_ARCH_MSM_WATCHDOG_H_
#define _ASM_ARCH_MSM_WATCHDOG_H_

#ifdef CONFIG_QCOM_FORCE_WDOG_BITE_ON_PANIC
#define WDOG_BITE_ON_PANIC 1
#else
#define WDOG_BITE_ON_PANIC 0
#endif

#ifdef CONFIG_QCOM_WATCHDOG_V2
void msm_trigger_wdog_bite(void);
#else
static inline void msm_trigger_wdog_bite(void) { }
#endif

#endif
