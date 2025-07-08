#ifndef __SEC_DEBUG_SCHED_LOG_INDIRECT
#warning "samsung/debug/sec_debug_sched_log.h is included directly."
#error "please include sec_debug.h instead of this file"
#endif

#ifndef __INDIRECT__SEC_DEBUG_SCHED_LOG_H__
#define __INDIRECT__SEC_DEBUG_SCHED_LOG_H__

#include "sec_debug_sched_log_type.h"

#if IS_ENABLED(CONFIG_SEC_DEBUG_SCHED_LOG)

void sec_debug_save_last_pet(unsigned long long last_pet);


void notrace sec_debug_save_last_ns(unsigned long long last_ns);


extern void sec_debug_task_sched_log(int cpu, bool preempt, struct task_struct *task, struct task_struct *prev);



extern void sec_debug_irq_sched_log(unsigned int irq, void *desc_or_fn, void *action_or_name, unsigned int en);


extern void sec_debug_softirq_sched_log(unsigned int irq, void *fn, char *name, unsigned int en);





extern int sec_debug_sched_msg(char *fmt, ...);


extern void sec_debug_secure_log(u32 svc_id, u32 cmd_id);


extern void __deprecated sec_debug_irq_enterexit_log(unsigned int irq, u64 start_time);

extern void __deprecated sec_debug_timer_log(unsigned int type, int int_lock, void *fn);
#else 
static inline void sec_debug_save_last_pet(unsigned long long last_pet) {}
static inline void sec_debug_save_last_ns(unsigned long long last_ns) {}
static inline void sec_debug_irq_enterexit_log(unsigned int irq, u64 start_time) {}
static inline int sec_debug_sched_msg(char *fmt, ...) { return 0; }
static inline void sec_debug_secure_log(u32 svc_id, u32 cmd_id) {}
static inline void sec_debug_task_sched_log(int cpu, bool preempt, struct task_struct *task, struct task_struct *prev) {}
static inline void sec_debug_timer_log(unsigned int type, int int_lock, void *fn) {}
static inline void sec_debug_irq_sched_log(unsigned int irq, void *desc_or_fn, void *action_or_name, unsigned int en) {}
static inline void sec_debug_softirq_sched_log(unsigned int irq, void *fn, char *name, unsigned int en) {}
#endif 


#if IS_ENABLED(CONFIG_SEC_DEBUG_MSG_LOG)

extern int ___sec_debug_msg_log(void *caller, const char *fmt, ...);




#define sec_debug_msg_log(fmt, ...) \
	___sec_debug_msg_log(__builtin_return_address(0), fmt, ##__VA_ARGS__)
#else 
#define sec_debug_msg_log(fmt, ...)
#endif 



#ifdef CONFIG_SEC_DEBUG_AVC_LOG

extern int __deprecated sec_debug_avc_log(const char *fmt, ...);

#else 
static inline int sec_debug_avc_log(const char *fmt, ...) { return 0; }
#endif 



#ifdef CONFIG_SEC_DEBUG_DCVS_LOG

extern void __deprecated sec_debug_dcvs_log(int cpu_no, unsigned int prev_freq, unsigned int new_freq);
#else 
static inline void sec_debug_dcvs_log(int cpu_no, unsigned int prev_freq, unsigned int new_freq) {}
#endif 


#ifdef CONFIG_SEC_DEBUG_FUELGAUGE_LOG

extern void __deprecated sec_debug_fuelgauge_log(unsigned int voltage, unsigned short soc, unsigned short charging_status);
#else 
static inline void sec_debug_fuelgauge_log(unsigned int voltage, unsigned short soc, unsigned short charging_status) {}
#endif 


#if IS_ENABLED(CONFIG_SEC_DEBUG_POWER_LOG)

extern void sec_debug_cpu_lpm_log(int cpu, unsigned int index, bool success, int entry_exit);


extern void sec_debug_cluster_lpm_log(const char *name, int index, unsigned long sync_cpus, unsigned long child_cpus, bool from_idle, int entry_exit);


extern void sec_debug_clock_log(const char *name, unsigned int state, unsigned int cpu_id, int complete);

#define sec_debug_clock_rate_log(name, state, cpu_id)			\
	sec_debug_clock_log((name), (state), (cpu_id), 0)
#define sec_debug_clock_rate_complete_log(name, state, cpu_id)		\
	sec_debug_clock_log((name), (state), (cpu_id), 1)
#else 
static inline void sec_debug_cpu_lpm_log(int cpu, unsigned int index, bool success, int entry_exit) {}
static inline void sec_debug_cluster_lpm_log(const char *name, int index, unsigned long sync_cpus, unsigned long child_cpus, bool from_idle, int entry_exit) {}
static inline void sec_debug_clock_log(const char *name, unsigned int state, unsigned int cpu_id, int complete) {}

#define sec_debug_clock_rate_log(name, state, cpu_id)
#define sec_debug_clock_rate_complete_log(name, state, cpu_id)
#endif	

#endif 
