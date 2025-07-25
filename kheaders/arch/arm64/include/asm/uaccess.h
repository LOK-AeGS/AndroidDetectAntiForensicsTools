
#ifndef __ASM_UACCESS_H
#define __ASM_UACCESS_H

#include <asm/alternative.h>
#include <asm/kernel-pgtable.h>
#include <asm/sysreg.h>


#include <linux/bitops.h>
#include <linux/kasan-checks.h>
#include <linux/string.h>

#include <asm/cpufeature.h>
#include <asm/ptrace.h>
#include <asm/memory.h>
#include <asm/compiler.h>
#include <asm/extable.h>

#define get_ds()	(KERNEL_DS)
#define get_fs()	(current_thread_info()->addr_limit)

static inline void set_fs(mm_segment_t fs)
{
	current_thread_info()->addr_limit = fs;

	
	dsb(nsh);
	isb();

	
	set_thread_flag(TIF_FSCHECK);

	
	if (IS_ENABLED(CONFIG_ARM64_UAO) && fs == KERNEL_DS)
		asm(ALTERNATIVE("nop", SET_PSTATE_UAO(1), ARM64_HAS_UAO));
	else
		asm(ALTERNATIVE("nop", SET_PSTATE_UAO(0), ARM64_HAS_UAO,
				CONFIG_ARM64_UAO));
}

#define segment_eq(a, b)	((a) == (b))


static inline unsigned long __range_ok(const void __user *addr, unsigned long size)
{
	unsigned long ret, limit = current_thread_info()->addr_limit;

	
	if (IS_ENABLED(CONFIG_ARM64_TAGGED_ADDR_ABI) &&
	    (current->flags & PF_KTHREAD || test_thread_flag(TIF_TAGGED_ADDR)))
		addr = untagged_addr(addr);

	__chk_user_ptr(addr);
	asm volatile(
	// A + B <= C + 1 for all A,B,C, in four easy steps:
	// 1: X = A + B; X' = X % 2^64
	"	adds	%0, %3, %2\n"
	// 2: Set C = 0 if X > 2^64, to guarantee X' > C in step 4
	"	csel	%1, xzr, %1, hi\n"
	// 3: Set X' = ~0 if X >= 2^64. For X == 2^64, this decrements X'
	//    to compensate for the carry flag being set in step 4. For
	//    X > 2^64, X' merely has to remain nonzero, which it does.
	"	csinv	%0, %0, xzr, cc\n"
	// 4: For X < 2^64, this gives us X' - C - 1 <= 0, where the -1
	//    comes from the carry in being clear. Otherwise, we are
	//    testing X' - C == 0, subject to the previous adjustments.
	"	sbcs	xzr, %0, %1\n"
	"	cset	%0, ls\n"
	: "=&r" (ret), "+r" (limit) : "Ir" (size), "0" (addr) : "cc");

	return ret;
}

#define access_ok(type, addr, size)	__range_ok(addr, size)
#define user_addr_max			get_fs

#define _ASM_EXTABLE(from, to)						\
	"	.pushsection	__ex_table, \"a\"\n"			\
	"	.align		3\n"					\
	"	.long		(" #from " - .), (" #to " - .)\n"	\
	"	.popsection\n"


#ifdef CONFIG_ARM64_SW_TTBR0_PAN
static inline void __uaccess_ttbr0_disable(void)
{
	unsigned long flags, ttbr;

	local_irq_save(flags);
	ttbr = read_sysreg(ttbr1_el1);
	ttbr &= ~TTBR_ASID_MASK;
	
	write_sysreg(ttbr - RESERVED_TTBR0_SIZE, ttbr0_el1);
	isb();
	
	write_sysreg(ttbr, ttbr1_el1);
	isb();
	local_irq_restore(flags);
}

static inline void __uaccess_ttbr0_enable(void)
{
	unsigned long flags, ttbr0, ttbr1;

	
	local_irq_save(flags);
	ttbr0 = READ_ONCE(current_thread_info()->ttbr0);

	
	ttbr1 = read_sysreg(ttbr1_el1);
	ttbr1 &= ~TTBR_ASID_MASK;		
	ttbr1 |= ttbr0 & TTBR_ASID_MASK;
	write_sysreg(ttbr1, ttbr1_el1);
	isb();

	
	write_sysreg(ttbr0, ttbr0_el1);
	isb();
	local_irq_restore(flags);
}

static inline bool uaccess_ttbr0_disable(void)
{
	if (!system_uses_ttbr0_pan())
		return false;
	__uaccess_ttbr0_disable();
	return true;
}

static inline bool uaccess_ttbr0_enable(void)
{
	if (!system_uses_ttbr0_pan())
		return false;
	__uaccess_ttbr0_enable();
	return true;
}
#else
static inline bool uaccess_ttbr0_disable(void)
{
	return false;
}

static inline bool uaccess_ttbr0_enable(void)
{
	return false;
}
#endif

static inline void __uaccess_disable_hw_pan(void)
{
	asm(ALTERNATIVE("nop", SET_PSTATE_PAN(0), ARM64_HAS_PAN,
			CONFIG_ARM64_PAN));
}

static inline void __uaccess_enable_hw_pan(void)
{
	asm(ALTERNATIVE("nop", SET_PSTATE_PAN(1), ARM64_HAS_PAN,
			CONFIG_ARM64_PAN));
}

#define __uaccess_disable(alt)						\
do {									\
	if (!uaccess_ttbr0_disable())					\
		asm(ALTERNATIVE("nop", SET_PSTATE_PAN(1), alt,		\
				CONFIG_ARM64_PAN));			\
} while (0)

#define __uaccess_enable(alt)						\
do {									\
	if (!uaccess_ttbr0_enable())					\
		asm(ALTERNATIVE("nop", SET_PSTATE_PAN(0), alt,		\
				CONFIG_ARM64_PAN));			\
} while (0)

static inline void uaccess_disable(void)
{
	__uaccess_disable(ARM64_HAS_PAN);
}

static inline void uaccess_enable(void)
{
	__uaccess_enable(ARM64_HAS_PAN);
}


static inline void uaccess_disable_not_uao(void)
{
	__uaccess_disable(ARM64_ALT_PAN_NOT_UAO);
}

static inline void uaccess_enable_not_uao(void)
{
	__uaccess_enable(ARM64_ALT_PAN_NOT_UAO);
}


#define uaccess_mask_ptr(ptr) (__typeof__(ptr))__uaccess_mask_ptr(ptr)
static inline void __user *__uaccess_mask_ptr(const void __user *ptr)
{
	void __user *safe_ptr;

	asm volatile(
	"	bics	xzr, %3, %2\n"
	"	csel	%0, %1, xzr, eq\n"
	: "=&r" (safe_ptr)
	: "r" (ptr), "r" (current_thread_info()->addr_limit),
	  "r" (untagged_addr(ptr))
	: "cc");

	csdb();
	return safe_ptr;
}


#define __get_user_asm(instr, alt_instr, reg, x, addr, err, feature)	\
	asm volatile(							\
	"1:"ALTERNATIVE(instr "     " reg "1, [%2]\n",			\
			alt_instr " " reg "1, [%2]\n", feature)		\
	"2:\n"								\
	"	.section .fixup, \"ax\"\n"				\
	"	.align	2\n"						\
	"3:	mov	%w0, %3\n"					\
	"	mov	%1, #0\n"					\
	"	b	2b\n"						\
	"	.previous\n"						\
	_ASM_EXTABLE(1b, 3b)						\
	: "+r" (err), "=&r" (x)						\
	: "r" (addr), "i" (-EFAULT))

#define __get_user_err(x, ptr, err)					\
do {									\
	unsigned long __gu_val;						\
	__chk_user_ptr(ptr);						\
	uaccess_enable_not_uao();					\
	switch (sizeof(*(ptr))) {					\
	case 1:								\
		__get_user_asm("ldrb", "ldtrb", "%w", __gu_val, (ptr),  \
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 2:								\
		__get_user_asm("ldrh", "ldtrh", "%w", __gu_val, (ptr),  \
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 4:								\
		__get_user_asm("ldr", "ldtr", "%w", __gu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 8:								\
		__get_user_asm("ldr", "ldtr", "%x",  __gu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	default:							\
		BUILD_BUG();						\
	}								\
	uaccess_disable_not_uao();					\
	(x) = (__force __typeof__(*(ptr)))__gu_val;			\
} while (0)

#define __get_user_check(x, ptr, err)					\
({									\
	__typeof__(*(ptr)) __user *__p = (ptr);				\
	might_fault();							\
	if (access_ok(VERIFY_READ, __p, sizeof(*__p))) {		\
		__p = uaccess_mask_ptr(__p);				\
		__get_user_err((x), __p, (err));			\
	} else {							\
		(x) = 0; (err) = -EFAULT;				\
	}								\
})

#define __get_user_error(x, ptr, err)					\
({									\
	__get_user_check((x), (ptr), (err));				\
	(void)0;							\
})

#define __get_user(x, ptr)						\
({									\
	int __gu_err = 0;						\
	__get_user_check((x), (ptr), __gu_err);				\
	__gu_err;							\
})

#define get_user	__get_user

#define __put_user_asm(instr, alt_instr, reg, x, addr, err, feature)	\
	asm volatile(							\
	"1:"ALTERNATIVE(instr "     " reg "1, [%2]\n",			\
			alt_instr " " reg "1, [%2]\n", feature)		\
	"2:\n"								\
	"	.section .fixup,\"ax\"\n"				\
	"	.align	2\n"						\
	"3:	mov	%w0, %3\n"					\
	"	b	2b\n"						\
	"	.previous\n"						\
	_ASM_EXTABLE(1b, 3b)						\
	: "+r" (err)							\
	: "r" (x), "r" (addr), "i" (-EFAULT))

#define __put_user_err(x, ptr, err)					\
do {									\
	__typeof__(*(ptr)) __pu_val = (x);				\
	__chk_user_ptr(ptr);						\
	uaccess_enable_not_uao();					\
	switch (sizeof(*(ptr))) {					\
	case 1:								\
		__put_user_asm("strb", "sttrb", "%w", __pu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 2:								\
		__put_user_asm("strh", "sttrh", "%w", __pu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 4:								\
		__put_user_asm("str", "sttr", "%w", __pu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	case 8:								\
		__put_user_asm("str", "sttr", "%x", __pu_val, (ptr),	\
			       (err), ARM64_HAS_UAO);			\
		break;							\
	default:							\
		BUILD_BUG();						\
	}								\
	uaccess_disable_not_uao();					\
} while (0)

#define __put_user_check(x, ptr, err)					\
({									\
	__typeof__(*(ptr)) __user *__p = (ptr);				\
	might_fault();							\
	if (access_ok(VERIFY_WRITE, __p, sizeof(*__p))) {		\
		__p = uaccess_mask_ptr(__p);				\
		__put_user_err((x), __p, (err));			\
	} else	{							\
		(err) = -EFAULT;					\
	}								\
})

#define __put_user_error(x, ptr, err)					\
({									\
	__put_user_check((x), (ptr), (err));				\
	(void)0;							\
})

#define __put_user(x, ptr)						\
({									\
	int __pu_err = 0;						\
	__put_user_check((x), (ptr), __pu_err);				\
	__pu_err;							\
})

#define put_user	__put_user

extern unsigned long __must_check __arch_copy_from_user(void *to, const void __user *from, unsigned long n);
#define raw_copy_from_user(to, from, n)					\
({									\
	__arch_copy_from_user((to), __uaccess_mask_ptr(from), (n));	\
})

extern unsigned long __must_check __arch_copy_to_user(void __user *to, const void *from, unsigned long n);
#define raw_copy_to_user(to, from, n)					\
({									\
	__arch_copy_to_user(__uaccess_mask_ptr(to), (from), (n));	\
})

extern unsigned long __must_check __arch_copy_in_user(void __user *to, const void __user *from, unsigned long n);
#define raw_copy_in_user(to, from, n)					\
({									\
	__arch_copy_in_user(__uaccess_mask_ptr(to),			\
			    __uaccess_mask_ptr(from), (n));		\
})

#define INLINE_COPY_TO_USER
#define INLINE_COPY_FROM_USER

extern unsigned long __must_check __arch_clear_user(void __user *to, unsigned long n);
static inline unsigned long __must_check __clear_user(void __user *to, unsigned long n)
{
	if (access_ok(VERIFY_WRITE, to, n))
		n = __arch_clear_user(__uaccess_mask_ptr(to), n);
	return n;
}
#define clear_user	__clear_user

extern long strncpy_from_user(char *dest, const char __user *src, long count);

extern __must_check long strnlen_user(const char __user *str, long n);

#ifdef CONFIG_ARCH_HAS_UACCESS_FLUSHCACHE
struct page;
void memcpy_page_flushcache(char *to, struct page *page, size_t offset, size_t len);
extern unsigned long __must_check __copy_user_flushcache(void *to, const void __user *from, unsigned long n);

static inline int __copy_from_user_flushcache(void *dst, const void __user *src, unsigned size)
{
	kasan_check_write(dst, size);
	return __copy_user_flushcache(dst, __uaccess_mask_ptr(src), size);
}
#endif

#endif 
