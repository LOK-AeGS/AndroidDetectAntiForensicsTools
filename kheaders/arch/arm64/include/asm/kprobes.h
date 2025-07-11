

#ifndef _ARM_KPROBES_H
#define _ARM_KPROBES_H

#include <asm-generic/kprobes.h>

#ifdef CONFIG_KPROBES
#include <linux/types.h>
#include <linux/ptrace.h>
#include <linux/percpu.h>

#define __ARCH_WANT_KPROBES_INSN_SLOT
#define MAX_INSN_SIZE			1

#define flush_insn_slot(p)		do { } while (0)
#define kretprobe_blacklist_size	0

#include <asm/probes.h>

struct prev_kprobe {
	struct kprobe *kp;
	unsigned int status;
};


struct kprobe_step_ctx {
	unsigned long ss_pending;
	unsigned long match_addr;
};


struct kprobe_ctlblk {
	unsigned int kprobe_status;
	unsigned long saved_irqflag;
	struct prev_kprobe prev_kprobe;
	struct kprobe_step_ctx ss_ctx;
};

void arch_remove_kprobe(struct kprobe *);
int kprobe_fault_handler(struct pt_regs *regs, unsigned int fsr);
int kprobe_exceptions_notify(struct notifier_block *self,
			     unsigned long val, void *data);
int kprobe_breakpoint_handler(struct pt_regs *regs, unsigned int esr);
int kprobe_single_step_handler(struct pt_regs *regs, unsigned int esr);
void kretprobe_trampoline(void);
void __kprobes *trampoline_probe_handler(struct pt_regs *regs);

#endif 
#endif 
