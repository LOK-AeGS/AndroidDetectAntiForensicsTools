

#ifndef __ARM_KVM_ASM_H__
#define __ARM_KVM_ASM_H__

#include <asm/virt.h>

#define	VCPU_WORKAROUND_2_FLAG_SHIFT	0
#define	VCPU_WORKAROUND_2_FLAG		(_AC(1, UL) << VCPU_WORKAROUND_2_FLAG_SHIFT)

#define ARM_EXIT_WITH_SERROR_BIT  31
#define ARM_EXCEPTION_CODE(x)	  ((x) & ~(1U << ARM_EXIT_WITH_SERROR_BIT))
#define ARM_SERROR_PENDING(x)	  !!((x) & (1U << ARM_EXIT_WITH_SERROR_BIT))

#define ARM_EXCEPTION_IRQ	  0
#define ARM_EXCEPTION_EL1_SERROR  1
#define ARM_EXCEPTION_TRAP	  2

#define ARM_EXCEPTION_HYP_GONE	  HVC_STUB_ERR

#ifndef __ASSEMBLY__

#include <linux/mm.h>


#define kvm_ksym_ref(sym)						\
	({								\
		void *val = &sym;					\
		if (!is_kernel_in_hyp_mode())				\
			val = lm_alias(&sym);				\
		val;							\
	 })

struct kvm;
struct kvm_vcpu;

extern char __kvm_hyp_init[];
extern char __kvm_hyp_init_end[];

extern char __kvm_hyp_vector[];

extern void __kvm_flush_vm_context(void);
extern void __kvm_tlb_flush_vmid_ipa(struct kvm *kvm, phys_addr_t ipa);
extern void __kvm_tlb_flush_vmid(struct kvm *kvm);
extern void __kvm_tlb_flush_local_vmid(struct kvm_vcpu *vcpu);

extern void __kvm_timer_set_cntvoff(u32 cntvoff_low, u32 cntvoff_high);

extern int kvm_vcpu_run_vhe(struct kvm_vcpu *vcpu);

extern int __kvm_vcpu_run_nvhe(struct kvm_vcpu *vcpu);

extern u64 __vgic_v3_get_ich_vtr_el2(void);
extern u64 __vgic_v3_read_vmcr(void);
extern void __vgic_v3_write_vmcr(u32 vmcr);
extern void __vgic_v3_init_lrs(void);

extern u32 __kvm_get_mdcr_el2(void);

extern u32 __init_stage2_translation(void);


#define __hyp_this_cpu_ptr(sym)						\
	({								\
		void *__ptr = hyp_symbol_addr(sym);			\
		__ptr += read_sysreg(tpidr_el2);			\
		(typeof(&sym))__ptr;					\
	 })

#define __hyp_this_cpu_read(sym)					\
	({								\
		*__hyp_this_cpu_ptr(sym);				\
	 })

#define __KVM_EXTABLE(from, to)						\
	"	.pushsection	__kvm_ex_table, \"a\"\n"		\
	"	.align		3\n"					\
	"	.long		(" #from " - .), (" #to " - .)\n"	\
	"	.popsection\n"


#define __kvm_at(at_op, addr)						\
( { 									\
	int __kvm_at_err = 0;						\
	u64 spsr, elr;							\
	asm volatile(							\
	"	mrs	%1, spsr_el2\n"					\
	"	mrs	%2, elr_el2\n"					\
	"1:	at	"at_op", %3\n"					\
	"	isb\n"							\
	"	b	9f\n"						\
	"2:	msr	spsr_el2, %1\n"					\
	"	msr	elr_el2, %2\n"					\
	"	mov	%w0, %4\n"					\
	"9:\n"								\
	__KVM_EXTABLE(1b, 2b)						\
	: "+r" (__kvm_at_err), "=&r" (spsr), "=&r" (elr)		\
	: "r" (addr), "i" (-EFAULT));					\
	__kvm_at_err;							\
} )


#else 

.macro hyp_adr_this_cpu reg, sym, tmp
	adr_l	\reg, \sym
	mrs	\tmp, tpidr_el2
	add	\reg, \reg, \tmp
.endm

.macro hyp_ldr_this_cpu reg, sym, tmp
	adr_l	\reg, \sym
	mrs	\tmp, tpidr_el2
	ldr	\reg,  [\reg, \tmp]
.endm

.macro get_host_ctxt reg, tmp
	hyp_adr_this_cpu \reg, kvm_host_cpu_state, \tmp
.endm

.macro get_vcpu_ptr vcpu, ctxt
	get_host_ctxt \ctxt, \vcpu
	ldr	\vcpu, [\ctxt, #HOST_CONTEXT_VCPU]
	kern_hyp_va	\vcpu
.endm


.macro	_kvm_extable, from, to
	.pushsection	__kvm_ex_table, "a"
	.align		3
	.long		(\from - .), (\to - .)
	.popsection
.endm

#endif

#endif 
