

#ifndef __CPU_COOLING_H__
#define __CPU_COOLING_H__

#include <linux/of.h>
#include <linux/thermal.h>
#include <linux/cpumask.h>

struct cpufreq_policy;

typedef int (*plat_mitig_t)(int cpu, u32 clip_freq);

struct cpu_cooling_ops {
	plat_mitig_t ceil_limit, floor_limit;
};

#ifdef CONFIG_CPU_THERMAL

struct thermal_cooling_device *
cpufreq_cooling_register(struct cpufreq_policy *policy);


struct thermal_cooling_device *
cpufreq_platform_cooling_register(struct cpufreq_policy *policy,
					struct cpu_cooling_ops *ops);


void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev);

#else 
static inline struct thermal_cooling_device *
cpufreq_cooling_register(struct cpufreq_policy *policy)
{
	return ERR_PTR(-ENOSYS);
}

static inline
void cpufreq_cooling_unregister(struct thermal_cooling_device *cdev)
{
	return;
}
#endif	

#if defined(CONFIG_THERMAL_OF) && defined(CONFIG_CPU_THERMAL)

struct thermal_cooling_device *
of_cpufreq_cooling_register(struct cpufreq_policy *policy);
#else
static inline struct thermal_cooling_device *
of_cpufreq_cooling_register(struct cpufreq_policy *policy)
{
	return NULL;
}

static inline struct thermal_cooling_device *
cpufreq_platform_cooling_register(struct cpufreq_policy *policy,
					struct cpu_cooling_ops *ops)
{
	return NULL;
}
#endif 

#ifdef CONFIG_QTI_CPU_ISOLATE_COOLING_DEVICE
extern void cpu_cooling_max_level_notifier_register(struct notifier_block *n);
extern void cpu_cooling_max_level_notifier_unregister(struct notifier_block *n);
extern const struct cpumask *cpu_cooling_get_max_level_cpumask(void);
#else
static inline
void cpu_cooling_max_level_notifier_register(struct notifier_block *n)
{
}

static inline
void cpu_cooling_max_level_notifier_unregister(struct notifier_block *n)
{
}

static inline const struct cpumask *cpu_cooling_get_max_level_cpumask(void)
{
	return cpu_none_mask;
}
#endif 
#endif 
