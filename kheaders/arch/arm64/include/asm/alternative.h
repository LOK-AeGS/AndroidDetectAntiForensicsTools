/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_ALTERNATIVE_H
#define __ASM_ALTERNATIVE_H

#include <asm/cpucaps.h>
#include <asm/insn.h>

#define ARM64_CB_PATCH ARM64_NCAPS

#ifndef __ASSEMBLY__

#include <linux/init.h>
#include <linux/types.h>
#include <linux/stddef.h>
#include <linux/stringify.h>

extern int alternatives_applied;

struct alt_instr {
	s32 orig_offset;	
	s32 alt_offset;		
	u16 cpufeature;		
	u8  orig_len;		
	u8  alt_len;		
};

typedef void (*alternative_cb_t)(struct alt_instr *alt,
				 __le32 *origptr, __le32 *updptr, int nr_inst);

void __init apply_alternatives_all(void);

#ifdef CONFIG_MODULES
void apply_alternatives_module(void *start, size_t length);
#else
static inline void apply_alternatives_module(void *start, size_t length) { }
#endif

#define ALTINSTR_ENTRY(feature)					              \
	" .word 661b - .\n"				 \
	" .word 663f - .\n"				 \
	" .hword " __stringify(feature) "\n"		 \
	" .byte 662b-661b\n"				 \
	" .byte 664f-663f\n"				

#define ALTINSTR_ENTRY_CB(feature, cb)					      \
	" .word 661b - .\n"				 \
	" .word " __stringify(cb) "- .\n"			      \
	" .hword " __stringify(feature) "\n"		 \
	" .byte 662b-661b\n"				 \
	" .byte 664f-663f\n"				


#define __ALTERNATIVE_CFG(oldinstr, newinstr, feature, cfg_enabled)	\
	".if "__stringify(cfg_enabled)" == 1\n"				\
	"661:\n\t"							\
	oldinstr "\n"							\
	"662:\n"							\
	".pushsection .altinstructions,\"a\"\n"				\
	ALTINSTR_ENTRY(feature)						\
	".popsection\n"							\
	".pushsection .altinstr_replacement, \"a\"\n"			\
	"663:\n\t"							\
	newinstr "\n"							\
	"664:\n\t"							\
	".popsection\n\t"						\
	".org	. - (664b-663b) + (662b-661b)\n\t"			\
	".org	. - (662b-661b) + (664b-663b)\n"			\
	".endif\n"

#define __ALTERNATIVE_CFG_CB(oldinstr, feature, cfg_enabled, cb)	\
	".if "__stringify(cfg_enabled)" == 1\n"				\
	"661:\n\t"							\
	oldinstr "\n"							\
	"662:\n"							\
	".pushsection .altinstructions,\"a\"\n"				\
	ALTINSTR_ENTRY_CB(feature, cb)					\
	".popsection\n"							\
	"663:\n\t"							\
	"664:\n\t"							\
	".endif\n"

#define _ALTERNATIVE_CFG(oldinstr, newinstr, feature, cfg, ...)	\
	__ALTERNATIVE_CFG(oldinstr, newinstr, feature, IS_ENABLED(cfg))

#define ALTERNATIVE_CB(oldinstr, cb) \
	__ALTERNATIVE_CFG_CB(oldinstr, ARM64_CB_PATCH, 1, cb)
#else

#include <asm/assembler.h>

.macro altinstruction_entry orig_offset alt_offset feature orig_len alt_len
	.word \orig_offset - .
	.word \alt_offset - .
	.hword \feature
	.byte \orig_len
	.byte \alt_len
.endm

.macro alternative_insn insn1, insn2, cap, enable = 1
	.if \enable
661:	\insn1
662:	.pushsection .altinstructions, "a"
	altinstruction_entry 661b, 663f, \cap, 662b-661b, 664f-663f
	.popsection
	.pushsection .altinstr_replacement, "ax"
663:	\insn2
664:	.popsection
	.org	. - (664b-663b) + (662b-661b)
	.org	. - (662b-661b) + (664b-663b)
	.endif
.endm




.macro alternative_if_not cap
	.set .Lasm_alt_mode, 0
	.pushsection .altinstructions, "a"
	altinstruction_entry 661f, 663f, \cap, 662f-661f, 664f-663f
	.popsection
661:
.endm

.macro alternative_if cap
	.set .Lasm_alt_mode, 1
	.pushsection .altinstructions, "a"
	altinstruction_entry 663f, 661f, \cap, 664f-663f, 662f-661f
	.popsection
	.pushsection .altinstr_replacement, "ax"
	.align 2	
661:
.endm

.macro alternative_cb cb
	.set .Lasm_alt_mode, 0
	.pushsection .altinstructions, "a"
	altinstruction_entry 661f, \cb, ARM64_CB_PATCH, 662f-661f, 0
	.popsection
661:
.endm


.macro alternative_else
662:
	.if .Lasm_alt_mode==0
	.pushsection .altinstr_replacement, "ax"
	.else
	.popsection
	.endif
663:
.endm


.macro alternative_endif
664:
	.if .Lasm_alt_mode==0
	.popsection
	.endif
	.org	. - (664b-663b) + (662b-661b)
	.org	. - (662b-661b) + (664b-663b)
.endm


.macro alternative_cb_end
662:
.endm


.macro alternative_else_nop_endif
alternative_else
	nops	(662b-661b) / AARCH64_INSN_SIZE
alternative_endif
.endm

#define _ALTERNATIVE_CFG(insn1, insn2, cap, cfg, ...)	\
	alternative_insn insn1, insn2, cap, IS_ENABLED(cfg)

.macro user_alt, label, oldinstr, newinstr, cond
9999:	alternative_insn "\oldinstr", "\newinstr", \cond
	_asm_extable 9999b, \label
.endm


#ifdef CONFIG_ARM64_UAO
	.macro uao_ldp l, reg1, reg2, addr, post_inc
		alternative_if_not ARM64_HAS_UAO
8888:			ldp	\reg1, \reg2, [\addr], \post_inc;
8889:			nop;
			nop;
		alternative_else
			ldtr	\reg1, [\addr];
			ldtr	\reg2, [\addr, #8];
			add	\addr, \addr, \post_inc;
		alternative_endif

		_asm_extable	8888b,\l;
		_asm_extable	8889b,\l;
	.endm

	.macro uao_stp l, reg1, reg2, addr, post_inc
		alternative_if_not ARM64_HAS_UAO
8888:			stp	\reg1, \reg2, [\addr], \post_inc;
8889:			nop;
			nop;
		alternative_else
			sttr	\reg1, [\addr];
			sttr	\reg2, [\addr, #8];
			add	\addr, \addr, \post_inc;
		alternative_endif

		_asm_extable	8888b,\l;
		_asm_extable	8889b,\l;
	.endm

	.macro uao_user_alternative l, inst, alt_inst, reg, addr, post_inc
		alternative_if_not ARM64_HAS_UAO
8888:			\inst	\reg, [\addr], \post_inc;
			nop;
		alternative_else
			\alt_inst	\reg, [\addr];
			add		\addr, \addr, \post_inc;
		alternative_endif

		_asm_extable	8888b,\l;
	.endm
#else
	.macro uao_ldp l, reg1, reg2, addr, post_inc
		USER(\l, ldp \reg1, \reg2, [\addr], \post_inc)
	.endm
	.macro uao_stp l, reg1, reg2, addr, post_inc
		USER(\l, stp \reg1, \reg2, [\addr], \post_inc)
	.endm
	.macro uao_user_alternative l, inst, alt_inst, reg, addr, post_inc
		USER(\l, \inst \reg, [\addr], \post_inc)
	.endm
#endif

#endif  


#define ALTERNATIVE(oldinstr, newinstr, ...)   \
	_ALTERNATIVE_CFG(oldinstr, newinstr, __VA_ARGS__, 1)

#endif 
