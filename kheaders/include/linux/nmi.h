/* SPDX-License-Identifier: GPL-2.0 */

#ifndef LINUX_NMI_H
#define LINUX_NMI_H

#include <linux/sched.h>
#include <asm/irq.h>
#if defined(CONFIG_HAVE_NMI_WATCHDOG)
#include <asm/nmi.h>
#endif

#ifdef CONFIG_LOCKUP_DETECTOR
void lockup_detector_init(void);
extern void watchdog_enable(unsigned int cpu);
extern void watchdog_disable(unsigned int cpu);
extern bool watchdog_configured(unsigned int cpu);
void lockup_detector_soft_poweroff(void);
void lockup_detector_cleanup(void);
bool is_hardlockup(void);

extern int watchdog_user_enabled;
extern int nmi_watchdog_user_enabled;
extern int soft_watchdog_user_enabled;
extern int watchdog_thresh;
extern unsigned long watchdog_enabled;

extern struct cpumask watchdog_cpumask;
extern unsigned long *watchdog_cpumask_bits;
#ifdef CONFIG_SMP
extern int sysctl_softlockup_all_cpu_backtrace;
extern int sysctl_hardlockup_all_cpu_backtrace;
#else
#define sysctl_softlockup_all_cpu_backtrace 0
#define sysctl_hardlockup_all_cpu_backtrace 0
#endif 

#else 
static inline void lockup_detector_init(void) { }
static inline void lockup_detector_soft_poweroff(void) { }
static inline void lockup_detector_cleanup(void) { }
static inline void watchdog_enable(unsigned int cpu)
{
}
static inline void watchdog_disable(unsigned int cpu)
{
}
static inline bool watchdog_configured(unsigned int cpu)
{
	
	return true;
}
#endif 

#ifdef CONFIG_SOFTLOCKUP_DETECTOR
extern void touch_softlockup_watchdog_sched(void);
extern void touch_softlockup_watchdog(void);
extern void touch_softlockup_watchdog_sync(void);
extern void touch_all_softlockup_watchdogs(void);
extern unsigned int  softlockup_panic;

extern int lockup_detector_online_cpu(unsigned int cpu);
extern int lockup_detector_offline_cpu(unsigned int cpu);
#else 
static inline void touch_softlockup_watchdog_sched(void) { }
static inline void touch_softlockup_watchdog(void) { }
static inline void touch_softlockup_watchdog_sync(void) { }
static inline void touch_all_softlockup_watchdogs(void) { }

#define lockup_detector_online_cpu	NULL
#define lockup_detector_offline_cpu	NULL
#endif 

#ifdef CONFIG_DETECT_HUNG_TASK
void reset_hung_task_detector(void);
#else
static inline void reset_hung_task_detector(void) { }
#endif


#define NMI_WATCHDOG_ENABLED_BIT   0
#define SOFT_WATCHDOG_ENABLED_BIT  1
#define NMI_WATCHDOG_ENABLED      (1 << NMI_WATCHDOG_ENABLED_BIT)
#define SOFT_WATCHDOG_ENABLED     (1 << SOFT_WATCHDOG_ENABLED_BIT)

#if defined(CONFIG_HARDLOCKUP_DETECTOR)
extern void hardlockup_detector_disable(void);
extern unsigned int hardlockup_panic;
#else
static inline void hardlockup_detector_disable(void) {}
#endif

#if defined(CONFIG_HAVE_NMI_WATCHDOG) || defined(CONFIG_HARDLOCKUP_DETECTOR)
# define NMI_WATCHDOG_SYSCTL_PERM	0644
#else
# define NMI_WATCHDOG_SYSCTL_PERM	0444
#endif

#if defined(CONFIG_HARDLOCKUP_DETECTOR_PERF)
extern void arch_touch_nmi_watchdog(void);
extern void hardlockup_detector_perf_stop(void);
extern void hardlockup_detector_perf_restart(void);
extern void hardlockup_detector_perf_disable(void);
extern void hardlockup_detector_perf_enable(void);
extern void hardlockup_detector_perf_cleanup(void);
extern int hardlockup_detector_perf_init(void);
#else
static inline void hardlockup_detector_perf_stop(void) { }
static inline void hardlockup_detector_perf_restart(void) { }
static inline void hardlockup_detector_perf_disable(void) { }
static inline void hardlockup_detector_perf_enable(void) { }
static inline void hardlockup_detector_perf_cleanup(void) { }
# if !defined(CONFIG_HAVE_NMI_WATCHDOG)
static inline int hardlockup_detector_perf_init(void) { return -ENODEV; }
static inline void arch_touch_nmi_watchdog(void) {}
# else
static inline int hardlockup_detector_perf_init(void) { return 0; }
# endif
#endif

void watchdog_nmi_stop(void);
void watchdog_nmi_start(void);
int watchdog_nmi_probe(void);
int watchdog_nmi_enable(unsigned int cpu);
void watchdog_nmi_disable(unsigned int cpu);


static inline void touch_nmi_watchdog(void)
{
	arch_touch_nmi_watchdog();
	touch_softlockup_watchdog();
}


#ifdef arch_trigger_cpumask_backtrace
static inline bool trigger_all_cpu_backtrace(void)
{
	arch_trigger_cpumask_backtrace(cpu_online_mask, false);
	return true;
}

static inline bool trigger_allbutself_cpu_backtrace(void)
{
	arch_trigger_cpumask_backtrace(cpu_online_mask, true);
	return true;
}

static inline bool trigger_cpumask_backtrace(struct cpumask *mask)
{
	arch_trigger_cpumask_backtrace(mask, false);
	return true;
}

static inline bool trigger_single_cpu_backtrace(int cpu)
{
	arch_trigger_cpumask_backtrace(cpumask_of(cpu), false);
	return true;
}


void nmi_trigger_cpumask_backtrace(const cpumask_t *mask,
				   bool exclude_self,
				   void (*raise)(cpumask_t *mask));
bool nmi_cpu_backtrace(struct pt_regs *regs);

#else
static inline bool trigger_all_cpu_backtrace(void)
{
	return false;
}
static inline bool trigger_allbutself_cpu_backtrace(void)
{
	return false;
}
static inline bool trigger_cpumask_backtrace(struct cpumask *mask)
{
	return false;
}
static inline bool trigger_single_cpu_backtrace(int cpu)
{
	return false;
}
#endif

#ifdef CONFIG_HARDLOCKUP_DETECTOR_PERF
u64 hw_nmi_get_sample_period(int watchdog_thresh);
#endif

#if defined(CONFIG_HARDLOCKUP_CHECK_TIMESTAMP) && \
    defined(CONFIG_HARDLOCKUP_DETECTOR)
void watchdog_update_hrtimer_threshold(u64 period);
#else
static inline void watchdog_update_hrtimer_threshold(u64 period) { }
#endif

struct ctl_table;
extern int proc_watchdog(struct ctl_table *, int ,
			 void __user *, size_t *, loff_t *);
extern int proc_nmi_watchdog(struct ctl_table *, int ,
			     void __user *, size_t *, loff_t *);
extern int proc_soft_watchdog(struct ctl_table *, int ,
			      void __user *, size_t *, loff_t *);
extern int proc_watchdog_thresh(struct ctl_table *, int ,
				void __user *, size_t *, loff_t *);
extern int proc_watchdog_cpumask(struct ctl_table *, int,
				 void __user *, size_t *, loff_t *);

#ifdef CONFIG_HAVE_ACPI_APEI_NMI
#include <asm/nmi.h>
#endif

#endif
