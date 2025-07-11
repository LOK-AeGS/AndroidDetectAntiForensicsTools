

#ifndef _LINUX_WAKEUP_REASON_H
#define _LINUX_WAKEUP_REASON_H

#define MAX_SUSPEND_ABORT_LEN 256

#ifdef CONFIG_SUSPEND
void log_irq_wakeup_reason(int irq);
void log_threaded_irq_wakeup_reason(int irq, int parent_irq);
void log_suspend_abort_reason(const char *fmt, ...);
void log_abnormal_wakeup_reason(const char *fmt, ...);
void clear_wakeup_reasons(void);
#else
static inline void log_irq_wakeup_reason(int irq) { }
static inline void log_threaded_irq_wakeup_reason(int irq, int parent_irq) { }
static inline void log_suspend_abort_reason(const char *fmt, ...) { }
static inline void log_abnormal_wakeup_reason(const char *fmt, ...) { }
static inline void clear_wakeup_reasons(void) { }
#endif

#endif 
