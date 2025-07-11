
#ifndef __ASM_DEBUG_MONITORS_H
#define __ASM_DEBUG_MONITORS_H

#ifdef __KERNEL__

#include <linux/errno.h>
#include <linux/types.h>
#include <asm/brk-imm.h>
#include <asm/esr.h>
#include <asm/insn.h>
#include <asm/ptrace.h>


#define DBG_MDSCR_SS		(1 << 0)
#define DBG_SPSR_SS		(1 << 21)


#define DBG_MDSCR_KDE		(1 << 13)
#define DBG_MDSCR_HDE		(1 << 14)
#define DBG_MDSCR_MDE		(1 << 15)
#define DBG_MDSCR_MASK		~(DBG_MDSCR_KDE | DBG_MDSCR_MDE)

#define	DBG_ESR_EVT(x)		(((x) >> 27) & 0x7)


#define DBG_ESR_EVT_HWBP	0x0
#define DBG_ESR_EVT_HWSS	0x1
#define DBG_ESR_EVT_HWWP	0x2
#define DBG_ESR_EVT_BRK		0x6


#define BREAK_INSTR_SIZE		AARCH64_INSN_SIZE


#define AARCH64_BREAK_MON	0xd4200000


#define AARCH64_BREAK_FAULT	(AARCH64_BREAK_MON | (FAULT_BRK_IMM << 5))

#define AARCH64_BREAK_KGDB_DYN_DBG	\
	(AARCH64_BREAK_MON | (KGDB_DYN_DBG_BRK_IMM << 5))

#define CACHE_FLUSH_IS_SAFE		1


#define BRK64_ESR_MASK		0xFFFF
#define BRK64_ESR_KPROBES	0x0004
#define BRK64_OPCODE_KPROBES	(AARCH64_BREAK_MON | (BRK64_ESR_KPROBES << 5))

#define BRK64_ESR_UPROBES	0x0005
#define BRK64_OPCODE_UPROBES	(AARCH64_BREAK_MON | (BRK64_ESR_UPROBES << 5))


#define DBG_ESR_EVT_BKPT	0x4
#define DBG_ESR_EVT_VECC	0x5

#define AARCH32_BREAK_ARM	0x07f001f0
#define AARCH32_BREAK_THUMB	0xde01
#define AARCH32_BREAK_THUMB2_LO	0xf7f0
#define AARCH32_BREAK_THUMB2_HI	0xa000

#ifndef __ASSEMBLY__
struct task_struct;

#define DBG_ARCH_ID_RESERVED	0	

#define DBG_HOOK_HANDLED	0
#define DBG_HOOK_ERROR		1

struct step_hook {
	struct list_head node;
	int (*fn)(struct pt_regs *regs, unsigned int esr);
};

void register_step_hook(struct step_hook *hook);
void unregister_step_hook(struct step_hook *hook);

struct break_hook {
	struct list_head node;
	u32 esr_val;
	u32 esr_mask;
	int (*fn)(struct pt_regs *regs, unsigned int esr);
};

void register_break_hook(struct break_hook *hook);
void unregister_break_hook(struct break_hook *hook);

u8 debug_monitors_arch(void);

enum dbg_active_el {
	DBG_ACTIVE_EL0 = 0,
	DBG_ACTIVE_EL1,
};

void enable_debug_monitors(enum dbg_active_el el);
void disable_debug_monitors(enum dbg_active_el el);

void user_rewind_single_step(struct task_struct *task);
void user_fastforward_single_step(struct task_struct *task);
void user_regs_reset_single_step(struct user_pt_regs *regs,
				 struct task_struct *task);

void kernel_enable_single_step(struct pt_regs *regs);
void kernel_disable_single_step(void);
int kernel_active_single_step(void);

#ifdef CONFIG_HAVE_HW_BREAKPOINT
int reinstall_suspended_bps(struct pt_regs *regs);
#else
static inline int reinstall_suspended_bps(struct pt_regs *regs)
{
	return -ENODEV;
}
#endif

int aarch32_break_handler(struct pt_regs *regs);

#endif	
#endif	
#endif	
