/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_DELAY_H
#define _LINUX_DELAY_H



#include <linux/kernel.h>

extern unsigned long loops_per_jiffy;

#include <asm/delay.h>



#ifndef MAX_UDELAY_MS
#define MAX_UDELAY_MS	5
#endif

#define MAX_MDELAY      1000

#if defined(CONFIG_SEC_DEBUG_SUMMARY) && !defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
extern unsigned long sec_delay_check;

#define BUG_MDELAY_LOG(irq, atomic)  if (unlikely(irq) || unlikely(atomic)) { \
	if (irq) \
	pr_err("BUG: mdelay called @ IRQ disabled context\n"); \
	if (atomic) \
	pr_err("BUG: mdelay called @ non-Atomic context\n"); \
}
#endif

#ifndef mdelay
#if !defined(CONFIG_SEC_DEBUG_SUMMARY) || defined(CONFIG_SAMSUNG_PRODUCT_SHIP)
#define mdelay(n) (\
		(__builtin_constant_p(n) && (n)<=MAX_UDELAY_MS) ? udelay((n)*1000) : \
		({unsigned long __ms=(n); while (__ms--) udelay(1000);}))
#else
#define mdelay(n) ({\
	BUILD_BUG_ON(__builtin_constant_p(n) && (n) > MAX_MDELAY); \
	if (__builtin_constant_p(n) && (n) <= MAX_UDELAY_MS) \
		udelay((n) * 1000); \
	else {\
		unsigned long __ms = (n); \
		bool irq_cond = irqs_disabled();\
		bool atomic_cond = !in_atomic();\
		BUG_MDELAY_LOG(irq_cond, atomic_cond);\
		BUG_ON((irq_cond || atomic_cond) && sec_delay_check);\
		while (__ms--) \
		udelay(1000); \
	} \
})
#endif
#endif

#ifndef ndelay
static inline void ndelay(unsigned long x)
{
	udelay(DIV_ROUND_UP(x, 1000));
}
#define ndelay(x) ndelay(x)
#endif

extern unsigned long lpj_fine;
void calibrate_delay(void);
void msleep(unsigned int msecs);
unsigned long msleep_interruptible(unsigned int msecs);
void usleep_range(unsigned long min, unsigned long max);

static inline void ssleep(unsigned int seconds)
{
	msleep(seconds * 1000);
}

#endif 
