

#ifndef __ASM_SYSREG_H
#define __ASM_SYSREG_H

#include <asm/compiler.h>
#include <linux/stringify.h>


#define Op0_shift	19
#define Op0_mask	0x3
#define Op1_shift	16
#define Op1_mask	0x7
#define CRn_shift	12
#define CRn_mask	0xf
#define CRm_shift	8
#define CRm_mask	0xf
#define Op2_shift	5
#define Op2_mask	0x7

#define sys_reg(op0, op1, crn, crm, op2) \
	(((op0) << Op0_shift) | ((op1) << Op1_shift) | \
	 ((crn) << CRn_shift) | ((crm) << CRm_shift) | \
	 ((op2) << Op2_shift))

#define sys_insn	sys_reg

#define sys_reg_Op0(id)	(((id) >> Op0_shift) & Op0_mask)
#define sys_reg_Op1(id)	(((id) >> Op1_shift) & Op1_mask)
#define sys_reg_CRn(id)	(((id) >> CRn_shift) & CRn_mask)
#define sys_reg_CRm(id)	(((id) >> CRm_shift) & CRm_mask)
#define sys_reg_Op2(id)	(((id) >> Op2_shift) & Op2_mask)

#ifndef CONFIG_BROKEN_GAS_INST

#ifdef __ASSEMBLY__
// The space separator is omitted so that __emit_inst(x) can be parsed as
// either an assembler directive or an assembler macro argument.
#define __emit_inst(x)			.inst(x)
#else
#define __emit_inst(x)			".inst " __stringify((x)) "\n\t"
#endif

#else  

#ifndef CONFIG_CPU_BIG_ENDIAN
#define __INSTR_BSWAP(x)		(x)
#else  
#define __INSTR_BSWAP(x)		((((x) << 24) & 0xff000000)	| \
					 (((x) <<  8) & 0x00ff0000)	| \
					 (((x) >>  8) & 0x0000ff00)	| \
					 (((x) >> 24) & 0x000000ff))
#endif	

#ifdef __ASSEMBLY__
#define __emit_inst(x)			.long __INSTR_BSWAP(x)
#else  
#define __emit_inst(x)			".long " __stringify(__INSTR_BSWAP(x)) "\n\t"
#endif	

#endif	


#define pstate_field(op1, op2)		((op1) << Op1_shift | (op2) << Op2_shift)
#define PSTATE_Imm_shift		CRm_shift

#define PSTATE_PAN			pstate_field(0, 4)
#define PSTATE_UAO			pstate_field(0, 3)
#define PSTATE_SSBS			pstate_field(3, 1)

#define SET_PSTATE_PAN(x)		__emit_inst(0xd500401f | PSTATE_PAN | ((!!x) << PSTATE_Imm_shift))
#define SET_PSTATE_UAO(x)		__emit_inst(0xd500401f | PSTATE_UAO | ((!!x) << PSTATE_Imm_shift))
#define SET_PSTATE_SSBS(x)		__emit_inst(0xd500401f | PSTATE_SSBS | ((!!x) << PSTATE_Imm_shift))

#define SYS_DC_ISW			sys_insn(1, 0, 7, 6, 2)
#define SYS_DC_CSW			sys_insn(1, 0, 7, 10, 2)
#define SYS_DC_CISW			sys_insn(1, 0, 7, 14, 2)

#define SYS_OSDTRRX_EL1			sys_reg(2, 0, 0, 0, 2)
#define SYS_MDCCINT_EL1			sys_reg(2, 0, 0, 2, 0)
#define SYS_MDSCR_EL1			sys_reg(2, 0, 0, 2, 2)
#define SYS_OSDTRTX_EL1			sys_reg(2, 0, 0, 3, 2)
#define SYS_OSECCR_EL1			sys_reg(2, 0, 0, 6, 2)
#define SYS_DBGBVRn_EL1(n)		sys_reg(2, 0, 0, n, 4)
#define SYS_DBGBCRn_EL1(n)		sys_reg(2, 0, 0, n, 5)
#define SYS_DBGWVRn_EL1(n)		sys_reg(2, 0, 0, n, 6)
#define SYS_DBGWCRn_EL1(n)		sys_reg(2, 0, 0, n, 7)
#define SYS_MDRAR_EL1			sys_reg(2, 0, 1, 0, 0)
#define SYS_OSLAR_EL1			sys_reg(2, 0, 1, 0, 4)
#define SYS_OSLSR_EL1			sys_reg(2, 0, 1, 1, 4)
#define SYS_OSDLR_EL1			sys_reg(2, 0, 1, 3, 4)
#define SYS_DBGPRCR_EL1			sys_reg(2, 0, 1, 4, 4)
#define SYS_DBGCLAIMSET_EL1		sys_reg(2, 0, 7, 8, 6)
#define SYS_DBGCLAIMCLR_EL1		sys_reg(2, 0, 7, 9, 6)
#define SYS_DBGAUTHSTATUS_EL1		sys_reg(2, 0, 7, 14, 6)
#define SYS_MDCCSR_EL0			sys_reg(2, 3, 0, 1, 0)
#define SYS_DBGDTR_EL0			sys_reg(2, 3, 0, 4, 0)
#define SYS_DBGDTRRX_EL0		sys_reg(2, 3, 0, 5, 0)
#define SYS_DBGDTRTX_EL0		sys_reg(2, 3, 0, 5, 0)
#define SYS_DBGVCR32_EL2		sys_reg(2, 4, 0, 7, 0)

#define SYS_MIDR_EL1			sys_reg(3, 0, 0, 0, 0)
#define SYS_MPIDR_EL1			sys_reg(3, 0, 0, 0, 5)
#define SYS_REVIDR_EL1			sys_reg(3, 0, 0, 0, 6)

#define SYS_ID_PFR0_EL1			sys_reg(3, 0, 0, 1, 0)
#define SYS_ID_PFR1_EL1			sys_reg(3, 0, 0, 1, 1)
#define SYS_ID_DFR0_EL1			sys_reg(3, 0, 0, 1, 2)
#define SYS_ID_AFR0_EL1			sys_reg(3, 0, 0, 1, 3)
#define SYS_ID_MMFR0_EL1		sys_reg(3, 0, 0, 1, 4)
#define SYS_ID_MMFR1_EL1		sys_reg(3, 0, 0, 1, 5)
#define SYS_ID_MMFR2_EL1		sys_reg(3, 0, 0, 1, 6)
#define SYS_ID_MMFR3_EL1		sys_reg(3, 0, 0, 1, 7)

#define SYS_ID_ISAR0_EL1		sys_reg(3, 0, 0, 2, 0)
#define SYS_ID_ISAR1_EL1		sys_reg(3, 0, 0, 2, 1)
#define SYS_ID_ISAR2_EL1		sys_reg(3, 0, 0, 2, 2)
#define SYS_ID_ISAR3_EL1		sys_reg(3, 0, 0, 2, 3)
#define SYS_ID_ISAR4_EL1		sys_reg(3, 0, 0, 2, 4)
#define SYS_ID_ISAR5_EL1		sys_reg(3, 0, 0, 2, 5)
#define SYS_ID_MMFR4_EL1		sys_reg(3, 0, 0, 2, 6)

#define SYS_MVFR0_EL1			sys_reg(3, 0, 0, 3, 0)
#define SYS_MVFR1_EL1			sys_reg(3, 0, 0, 3, 1)
#define SYS_MVFR2_EL1			sys_reg(3, 0, 0, 3, 2)

#define SYS_ID_AA64PFR0_EL1		sys_reg(3, 0, 0, 4, 0)
#define SYS_ID_AA64PFR1_EL1		sys_reg(3, 0, 0, 4, 1)
#define SYS_ID_AA64ZFR0_EL1		sys_reg(3, 0, 0, 4, 4)

#define SYS_ID_AA64DFR0_EL1		sys_reg(3, 0, 0, 5, 0)
#define SYS_ID_AA64DFR1_EL1		sys_reg(3, 0, 0, 5, 1)

#define SYS_ID_AA64AFR0_EL1		sys_reg(3, 0, 0, 5, 4)
#define SYS_ID_AA64AFR1_EL1		sys_reg(3, 0, 0, 5, 5)

#define SYS_ID_AA64ISAR0_EL1		sys_reg(3, 0, 0, 6, 0)
#define SYS_ID_AA64ISAR1_EL1		sys_reg(3, 0, 0, 6, 1)

#define SYS_ID_AA64MMFR0_EL1		sys_reg(3, 0, 0, 7, 0)
#define SYS_ID_AA64MMFR1_EL1		sys_reg(3, 0, 0, 7, 1)
#define SYS_ID_AA64MMFR2_EL1		sys_reg(3, 0, 0, 7, 2)

#define SYS_SCTLR_EL1			sys_reg(3, 0, 1, 0, 0)
#define SYS_ACTLR_EL1			sys_reg(3, 0, 1, 0, 1)
#define SYS_CPACR_EL1			sys_reg(3, 0, 1, 0, 2)

#define SYS_ZCR_EL1			sys_reg(3, 0, 1, 2, 0)

#define SYS_TTBR0_EL1			sys_reg(3, 0, 2, 0, 0)
#define SYS_TTBR1_EL1			sys_reg(3, 0, 2, 0, 1)
#define SYS_TCR_EL1			sys_reg(3, 0, 2, 0, 2)

#define SYS_ICC_PMR_EL1			sys_reg(3, 0, 4, 6, 0)

#define SYS_AFSR0_EL1			sys_reg(3, 0, 5, 1, 0)
#define SYS_AFSR1_EL1			sys_reg(3, 0, 5, 1, 1)
#define SYS_ESR_EL1			sys_reg(3, 0, 5, 2, 0)

#define SYS_ERRIDR_EL1			sys_reg(3, 0, 5, 3, 0)
#define SYS_ERRSELR_EL1			sys_reg(3, 0, 5, 3, 1)
#define SYS_ERXFR_EL1			sys_reg(3, 0, 5, 4, 0)
#define SYS_ERXCTLR_EL1			sys_reg(3, 0, 5, 4, 1)
#define SYS_ERXSTATUS_EL1		sys_reg(3, 0, 5, 4, 2)
#define SYS_ERXADDR_EL1			sys_reg(3, 0, 5, 4, 3)
#define SYS_ERXMISC0_EL1		sys_reg(3, 0, 5, 5, 0)
#define SYS_ERXMISC1_EL1		sys_reg(3, 0, 5, 5, 1)

#define SYS_FAR_EL1			sys_reg(3, 0, 6, 0, 0)
#define SYS_PAR_EL1			sys_reg(3, 0, 7, 4, 0)



#define SYS_PMSIDR_EL1			sys_reg(3, 0, 9, 9, 7)
#define SYS_PMSIDR_EL1_FE_SHIFT		0
#define SYS_PMSIDR_EL1_FT_SHIFT		1
#define SYS_PMSIDR_EL1_FL_SHIFT		2
#define SYS_PMSIDR_EL1_ARCHINST_SHIFT	3
#define SYS_PMSIDR_EL1_LDS_SHIFT	4
#define SYS_PMSIDR_EL1_ERND_SHIFT	5
#define SYS_PMSIDR_EL1_INTERVAL_SHIFT	8
#define SYS_PMSIDR_EL1_INTERVAL_MASK	0xfUL
#define SYS_PMSIDR_EL1_MAXSIZE_SHIFT	12
#define SYS_PMSIDR_EL1_MAXSIZE_MASK	0xfUL
#define SYS_PMSIDR_EL1_COUNTSIZE_SHIFT	16
#define SYS_PMSIDR_EL1_COUNTSIZE_MASK	0xfUL

#define SYS_PMBIDR_EL1			sys_reg(3, 0, 9, 10, 7)
#define SYS_PMBIDR_EL1_ALIGN_SHIFT	0
#define SYS_PMBIDR_EL1_ALIGN_MASK	0xfU
#define SYS_PMBIDR_EL1_P_SHIFT		4
#define SYS_PMBIDR_EL1_F_SHIFT		5


#define SYS_PMSCR_EL1			sys_reg(3, 0, 9, 9, 0)
#define SYS_PMSCR_EL1_E0SPE_SHIFT	0
#define SYS_PMSCR_EL1_E1SPE_SHIFT	1
#define SYS_PMSCR_EL1_CX_SHIFT		3
#define SYS_PMSCR_EL1_PA_SHIFT		4
#define SYS_PMSCR_EL1_TS_SHIFT		5
#define SYS_PMSCR_EL1_PCT_SHIFT		6

#define SYS_PMSCR_EL2			sys_reg(3, 4, 9, 9, 0)
#define SYS_PMSCR_EL2_E0HSPE_SHIFT	0
#define SYS_PMSCR_EL2_E2SPE_SHIFT	1
#define SYS_PMSCR_EL2_CX_SHIFT		3
#define SYS_PMSCR_EL2_PA_SHIFT		4
#define SYS_PMSCR_EL2_TS_SHIFT		5
#define SYS_PMSCR_EL2_PCT_SHIFT		6

#define SYS_PMSICR_EL1			sys_reg(3, 0, 9, 9, 2)

#define SYS_PMSIRR_EL1			sys_reg(3, 0, 9, 9, 3)
#define SYS_PMSIRR_EL1_RND_SHIFT	0
#define SYS_PMSIRR_EL1_INTERVAL_SHIFT	8
#define SYS_PMSIRR_EL1_INTERVAL_MASK	0xffffffUL


#define SYS_PMSFCR_EL1			sys_reg(3, 0, 9, 9, 4)
#define SYS_PMSFCR_EL1_FE_SHIFT		0
#define SYS_PMSFCR_EL1_FT_SHIFT		1
#define SYS_PMSFCR_EL1_FL_SHIFT		2
#define SYS_PMSFCR_EL1_B_SHIFT		16
#define SYS_PMSFCR_EL1_LD_SHIFT		17
#define SYS_PMSFCR_EL1_ST_SHIFT		18

#define SYS_PMSEVFR_EL1			sys_reg(3, 0, 9, 9, 5)
#define SYS_PMSEVFR_EL1_RES0		0x0000ffff00ff0f55UL

#define SYS_PMSLATFR_EL1		sys_reg(3, 0, 9, 9, 6)
#define SYS_PMSLATFR_EL1_MINLAT_SHIFT	0


#define SYS_PMBLIMITR_EL1		sys_reg(3, 0, 9, 10, 0)
#define SYS_PMBLIMITR_EL1_E_SHIFT	0
#define SYS_PMBLIMITR_EL1_FM_SHIFT	1
#define SYS_PMBLIMITR_EL1_FM_MASK	0x3UL
#define SYS_PMBLIMITR_EL1_FM_STOP_IRQ	(0 << SYS_PMBLIMITR_EL1_FM_SHIFT)

#define SYS_PMBPTR_EL1			sys_reg(3, 0, 9, 10, 1)


#define SYS_PMBSR_EL1			sys_reg(3, 0, 9, 10, 3)
#define SYS_PMBSR_EL1_COLL_SHIFT	16
#define SYS_PMBSR_EL1_S_SHIFT		17
#define SYS_PMBSR_EL1_EA_SHIFT		18
#define SYS_PMBSR_EL1_DL_SHIFT		19
#define SYS_PMBSR_EL1_EC_SHIFT		26
#define SYS_PMBSR_EL1_EC_MASK		0x3fUL

#define SYS_PMBSR_EL1_EC_BUF		(0x0UL << SYS_PMBSR_EL1_EC_SHIFT)
#define SYS_PMBSR_EL1_EC_FAULT_S1	(0x24UL << SYS_PMBSR_EL1_EC_SHIFT)
#define SYS_PMBSR_EL1_EC_FAULT_S2	(0x25UL << SYS_PMBSR_EL1_EC_SHIFT)

#define SYS_PMBSR_EL1_FAULT_FSC_SHIFT	0
#define SYS_PMBSR_EL1_FAULT_FSC_MASK	0x3fUL

#define SYS_PMBSR_EL1_BUF_BSC_SHIFT	0
#define SYS_PMBSR_EL1_BUF_BSC_MASK	0x3fUL

#define SYS_PMBSR_EL1_BUF_BSC_FULL	(0x1UL << SYS_PMBSR_EL1_BUF_BSC_SHIFT)



#define SYS_PMINTENSET_EL1		sys_reg(3, 0, 9, 14, 1)
#define SYS_PMINTENCLR_EL1		sys_reg(3, 0, 9, 14, 2)

#define SYS_MAIR_EL1			sys_reg(3, 0, 10, 2, 0)
#define SYS_AMAIR_EL1			sys_reg(3, 0, 10, 3, 0)

#define SYS_LORSA_EL1			sys_reg(3, 0, 10, 4, 0)
#define SYS_LOREA_EL1			sys_reg(3, 0, 10, 4, 1)
#define SYS_LORN_EL1			sys_reg(3, 0, 10, 4, 2)
#define SYS_LORC_EL1			sys_reg(3, 0, 10, 4, 3)
#define SYS_LORID_EL1			sys_reg(3, 0, 10, 4, 7)

#define SYS_VBAR_EL1			sys_reg(3, 0, 12, 0, 0)
#define SYS_DISR_EL1			sys_reg(3, 0, 12, 1, 1)

#define SYS_ICC_IAR0_EL1		sys_reg(3, 0, 12, 8, 0)
#define SYS_ICC_EOIR0_EL1		sys_reg(3, 0, 12, 8, 1)
#define SYS_ICC_HPPIR0_EL1		sys_reg(3, 0, 12, 8, 2)
#define SYS_ICC_BPR0_EL1		sys_reg(3, 0, 12, 8, 3)
#define SYS_ICC_AP0Rn_EL1(n)		sys_reg(3, 0, 12, 8, 4 | n)
#define SYS_ICC_AP0R0_EL1		SYS_ICC_AP0Rn_EL1(0)
#define SYS_ICC_AP0R1_EL1		SYS_ICC_AP0Rn_EL1(1)
#define SYS_ICC_AP0R2_EL1		SYS_ICC_AP0Rn_EL1(2)
#define SYS_ICC_AP0R3_EL1		SYS_ICC_AP0Rn_EL1(3)
#define SYS_ICC_AP1Rn_EL1(n)		sys_reg(3, 0, 12, 9, n)
#define SYS_ICC_AP1R0_EL1		SYS_ICC_AP1Rn_EL1(0)
#define SYS_ICC_AP1R1_EL1		SYS_ICC_AP1Rn_EL1(1)
#define SYS_ICC_AP1R2_EL1		SYS_ICC_AP1Rn_EL1(2)
#define SYS_ICC_AP1R3_EL1		SYS_ICC_AP1Rn_EL1(3)
#define SYS_ICC_DIR_EL1			sys_reg(3, 0, 12, 11, 1)
#define SYS_ICC_RPR_EL1			sys_reg(3, 0, 12, 11, 3)
#define SYS_ICC_SGI1R_EL1		sys_reg(3, 0, 12, 11, 5)
#define SYS_ICC_ASGI1R_EL1		sys_reg(3, 0, 12, 11, 6)
#define SYS_ICC_SGI0R_EL1		sys_reg(3, 0, 12, 11, 7)
#define SYS_ICC_IAR1_EL1		sys_reg(3, 0, 12, 12, 0)
#define SYS_ICC_EOIR1_EL1		sys_reg(3, 0, 12, 12, 1)
#define SYS_ICC_HPPIR1_EL1		sys_reg(3, 0, 12, 12, 2)
#define SYS_ICC_BPR1_EL1		sys_reg(3, 0, 12, 12, 3)
#define SYS_ICC_CTLR_EL1		sys_reg(3, 0, 12, 12, 4)
#define SYS_ICC_SRE_EL1			sys_reg(3, 0, 12, 12, 5)
#define SYS_ICC_IGRPEN0_EL1		sys_reg(3, 0, 12, 12, 6)
#define SYS_ICC_IGRPEN1_EL1		sys_reg(3, 0, 12, 12, 7)

#define SYS_CONTEXTIDR_EL1		sys_reg(3, 0, 13, 0, 1)
#define SYS_TPIDR_EL1			sys_reg(3, 0, 13, 0, 4)

#define SYS_CNTKCTL_EL1			sys_reg(3, 0, 14, 1, 0)

#define SYS_CLIDR_EL1			sys_reg(3, 1, 0, 0, 1)
#define SYS_AIDR_EL1			sys_reg(3, 1, 0, 0, 7)

#define SYS_CSSELR_EL1			sys_reg(3, 2, 0, 0, 0)

#define SYS_CTR_EL0			sys_reg(3, 3, 0, 0, 1)
#define SYS_DCZID_EL0			sys_reg(3, 3, 0, 0, 7)

#define SYS_PMCR_EL0			sys_reg(3, 3, 9, 12, 0)
#define SYS_PMCNTENSET_EL0		sys_reg(3, 3, 9, 12, 1)
#define SYS_PMCNTENCLR_EL0		sys_reg(3, 3, 9, 12, 2)
#define SYS_PMOVSCLR_EL0		sys_reg(3, 3, 9, 12, 3)
#define SYS_PMSWINC_EL0			sys_reg(3, 3, 9, 12, 4)
#define SYS_PMSELR_EL0			sys_reg(3, 3, 9, 12, 5)
#define SYS_PMCEID0_EL0			sys_reg(3, 3, 9, 12, 6)
#define SYS_PMCEID1_EL0			sys_reg(3, 3, 9, 12, 7)
#define SYS_PMCCNTR_EL0			sys_reg(3, 3, 9, 13, 0)
#define SYS_PMXEVTYPER_EL0		sys_reg(3, 3, 9, 13, 1)
#define SYS_PMXEVCNTR_EL0		sys_reg(3, 3, 9, 13, 2)
#define SYS_PMUSERENR_EL0		sys_reg(3, 3, 9, 14, 0)
#define SYS_PMOVSSET_EL0		sys_reg(3, 3, 9, 14, 3)

#define SYS_TPIDR_EL0			sys_reg(3, 3, 13, 0, 2)
#define SYS_TPIDRRO_EL0			sys_reg(3, 3, 13, 0, 3)

#define SYS_CNTFRQ_EL0			sys_reg(3, 3, 14, 0, 0)

#define SYS_CNTP_TVAL_EL0		sys_reg(3, 3, 14, 2, 0)
#define SYS_CNTP_CTL_EL0		sys_reg(3, 3, 14, 2, 1)
#define SYS_CNTP_CVAL_EL0		sys_reg(3, 3, 14, 2, 2)

#define __PMEV_op2(n)			((n) & 0x7)
#define __CNTR_CRm(n)			(0x8 | (((n) >> 3) & 0x3))
#define SYS_PMEVCNTRn_EL0(n)		sys_reg(3, 3, 14, __CNTR_CRm(n), __PMEV_op2(n))
#define __TYPER_CRm(n)			(0xc | (((n) >> 3) & 0x3))
#define SYS_PMEVTYPERn_EL0(n)		sys_reg(3, 3, 14, __TYPER_CRm(n), __PMEV_op2(n))

#define SYS_PMCCFILTR_EL0		sys_reg (3, 3, 14, 15, 7)

#define SYS_ZCR_EL2			sys_reg(3, 4, 1, 2, 0)

#define SYS_DACR32_EL2			sys_reg(3, 4, 3, 0, 0)
#define SYS_IFSR32_EL2			sys_reg(3, 4, 5, 0, 1)
#define SYS_VSESR_EL2			sys_reg(3, 4, 5, 2, 3)
#define SYS_FPEXC32_EL2			sys_reg(3, 4, 5, 3, 0)

#define SYS_VDISR_EL2			sys_reg(3, 4, 12, 1,  1)
#define __SYS__AP0Rx_EL2(x)		sys_reg(3, 4, 12, 8, x)
#define SYS_ICH_AP0R0_EL2		__SYS__AP0Rx_EL2(0)
#define SYS_ICH_AP0R1_EL2		__SYS__AP0Rx_EL2(1)
#define SYS_ICH_AP0R2_EL2		__SYS__AP0Rx_EL2(2)
#define SYS_ICH_AP0R3_EL2		__SYS__AP0Rx_EL2(3)

#define __SYS__AP1Rx_EL2(x)		sys_reg(3, 4, 12, 9, x)
#define SYS_ICH_AP1R0_EL2		__SYS__AP1Rx_EL2(0)
#define SYS_ICH_AP1R1_EL2		__SYS__AP1Rx_EL2(1)
#define SYS_ICH_AP1R2_EL2		__SYS__AP1Rx_EL2(2)
#define SYS_ICH_AP1R3_EL2		__SYS__AP1Rx_EL2(3)

#define SYS_ICH_VSEIR_EL2		sys_reg(3, 4, 12, 9, 4)
#define SYS_ICC_SRE_EL2			sys_reg(3, 4, 12, 9, 5)
#define SYS_ICH_HCR_EL2			sys_reg(3, 4, 12, 11, 0)
#define SYS_ICH_VTR_EL2			sys_reg(3, 4, 12, 11, 1)
#define SYS_ICH_MISR_EL2		sys_reg(3, 4, 12, 11, 2)
#define SYS_ICH_EISR_EL2		sys_reg(3, 4, 12, 11, 3)
#define SYS_ICH_ELSR_EL2		sys_reg(3, 4, 12, 11, 5)
#define SYS_ICH_VMCR_EL2		sys_reg(3, 4, 12, 11, 7)

#define __SYS__LR0_EL2(x)		sys_reg(3, 4, 12, 12, x)
#define SYS_ICH_LR0_EL2			__SYS__LR0_EL2(0)
#define SYS_ICH_LR1_EL2			__SYS__LR0_EL2(1)
#define SYS_ICH_LR2_EL2			__SYS__LR0_EL2(2)
#define SYS_ICH_LR3_EL2			__SYS__LR0_EL2(3)
#define SYS_ICH_LR4_EL2			__SYS__LR0_EL2(4)
#define SYS_ICH_LR5_EL2			__SYS__LR0_EL2(5)
#define SYS_ICH_LR6_EL2			__SYS__LR0_EL2(6)
#define SYS_ICH_LR7_EL2			__SYS__LR0_EL2(7)

#define __SYS__LR8_EL2(x)		sys_reg(3, 4, 12, 13, x)
#define SYS_ICH_LR8_EL2			__SYS__LR8_EL2(0)
#define SYS_ICH_LR9_EL2			__SYS__LR8_EL2(1)
#define SYS_ICH_LR10_EL2		__SYS__LR8_EL2(2)
#define SYS_ICH_LR11_EL2		__SYS__LR8_EL2(3)
#define SYS_ICH_LR12_EL2		__SYS__LR8_EL2(4)
#define SYS_ICH_LR13_EL2		__SYS__LR8_EL2(5)
#define SYS_ICH_LR14_EL2		__SYS__LR8_EL2(6)
#define SYS_ICH_LR15_EL2		__SYS__LR8_EL2(7)


#define SCTLR_ELx_DSSBS	(1UL << 44)
#define SCTLR_ELx_EE    (1 << 25)
#define SCTLR_ELx_IESB	(1 << 21)
#define SCTLR_ELx_WXN	(1 << 19)
#define SCTLR_ELx_I	(1 << 12)
#define SCTLR_ELx_SA	(1 << 3)
#define SCTLR_ELx_C	(1 << 2)
#define SCTLR_ELx_A	(1 << 1)
#define SCTLR_ELx_M	1

#define SCTLR_ELx_FLAGS	(SCTLR_ELx_M  | SCTLR_ELx_A | SCTLR_ELx_C | \
			 SCTLR_ELx_SA | SCTLR_ELx_I | SCTLR_ELx_IESB)


#define SCTLR_EL2_RES1	((1 << 4)  | (1 << 5)  | (1 << 11) | (1 << 16) | \
			 (1 << 18) | (1 << 22) | (1 << 23) | (1 << 28) | \
			 (1 << 29))
#define SCTLR_EL2_RES0	((1 << 6)  | (1 << 7)  | (1 << 8)  | (1 << 9)  | \
			 (1 << 10) | (1 << 13) | (1 << 14) | (1 << 15) | \
			 (1 << 17) | (1 << 20) | (1 << 24) | (1 << 26) | \
			 (1 << 27) | (1 << 30) | (1 << 31) | \
			 (0xffffefffUL << 32))

#ifdef CONFIG_CPU_BIG_ENDIAN
#define ENDIAN_SET_EL2		SCTLR_ELx_EE
#define ENDIAN_CLEAR_EL2	0
#else
#define ENDIAN_SET_EL2		0
#define ENDIAN_CLEAR_EL2	SCTLR_ELx_EE
#endif


#define SCTLR_EL2_SET	(SCTLR_ELx_IESB   | ENDIAN_SET_EL2   | SCTLR_EL2_RES1)
#define SCTLR_EL2_CLEAR	(SCTLR_ELx_M      | SCTLR_ELx_A    | SCTLR_ELx_C   | \
			 SCTLR_ELx_SA     | SCTLR_ELx_I    | SCTLR_ELx_WXN | \
			 SCTLR_ELx_DSSBS | ENDIAN_CLEAR_EL2 | SCTLR_EL2_RES0)

#if (SCTLR_EL2_SET ^ SCTLR_EL2_CLEAR) != 0xffffffffffffffff
#error "Inconsistent SCTLR_EL2 set/clear bits"
#endif


#define SCTLR_EL1_UCI		(1 << 26)
#define SCTLR_EL1_E0E		(1 << 24)
#define SCTLR_EL1_SPAN		(1 << 23)
#define SCTLR_EL1_NTWE		(1 << 18)
#define SCTLR_EL1_NTWI		(1 << 16)
#define SCTLR_EL1_UCT		(1 << 15)
#define SCTLR_EL1_DZE		(1 << 14)
#define SCTLR_EL1_UMA		(1 << 9)
#define SCTLR_EL1_SED		(1 << 8)
#define SCTLR_EL1_ITD		(1 << 7)
#define SCTLR_EL1_CP15BEN	(1 << 5)
#define SCTLR_EL1_SA0		(1 << 4)

#define SCTLR_EL1_RES1	((1 << 11) | (1 << 20) | (1 << 22) | (1 << 28) | \
			 (1 << 29))
#define SCTLR_EL1_RES0  ((1 << 6)  | (1 << 10) | (1 << 13) | (1 << 17) | \
			 (1 << 27) | (1 << 30) | (1 << 31) | \
			 (0xffffefffUL << 32))

#ifdef CONFIG_CPU_BIG_ENDIAN
#define ENDIAN_SET_EL1		(SCTLR_EL1_E0E | SCTLR_ELx_EE)
#define ENDIAN_CLEAR_EL1	0
#else
#define ENDIAN_SET_EL1		0
#define ENDIAN_CLEAR_EL1	(SCTLR_EL1_E0E | SCTLR_ELx_EE)
#endif

#define SCTLR_EL1_SET	(SCTLR_ELx_M    | SCTLR_ELx_C    | SCTLR_ELx_SA   |\
			 SCTLR_EL1_SA0  | SCTLR_EL1_SED  | SCTLR_ELx_I    |\
			 SCTLR_EL1_DZE  | SCTLR_EL1_UCT  | SCTLR_EL1_NTWI |\
			 SCTLR_EL1_NTWE | SCTLR_ELx_IESB | SCTLR_EL1_SPAN |\
			 ENDIAN_SET_EL1 | SCTLR_EL1_UCI  | SCTLR_EL1_RES1)
#define SCTLR_EL1_CLEAR	(SCTLR_ELx_A   | SCTLR_EL1_CP15BEN | SCTLR_EL1_ITD    |\
			 SCTLR_EL1_UMA | SCTLR_ELx_WXN     | ENDIAN_CLEAR_EL1 |\
			 SCTLR_ELx_DSSBS | SCTLR_EL1_RES0)

#if (SCTLR_EL1_SET ^ SCTLR_EL1_CLEAR) != 0xffffffffffffffff
#error "Inconsistent SCTLR_EL1 set/clear bits"
#endif


#define ID_AA64ISAR0_TS_SHIFT		52
#define ID_AA64ISAR0_FHM_SHIFT		48
#define ID_AA64ISAR0_DP_SHIFT		44
#define ID_AA64ISAR0_SM4_SHIFT		40
#define ID_AA64ISAR0_SM3_SHIFT		36
#define ID_AA64ISAR0_SHA3_SHIFT		32
#define ID_AA64ISAR0_RDM_SHIFT		28
#define ID_AA64ISAR0_ATOMICS_SHIFT	20
#define ID_AA64ISAR0_CRC32_SHIFT	16
#define ID_AA64ISAR0_SHA2_SHIFT		12
#define ID_AA64ISAR0_SHA1_SHIFT		8
#define ID_AA64ISAR0_AES_SHIFT		4


#define ID_AA64ISAR1_LRCPC_SHIFT	20
#define ID_AA64ISAR1_FCMA_SHIFT		16
#define ID_AA64ISAR1_JSCVT_SHIFT	12
#define ID_AA64ISAR1_DPB_SHIFT		0


#define ID_AA64PFR0_CSV3_SHIFT		60
#define ID_AA64PFR0_CSV2_SHIFT		56
#define ID_AA64PFR0_DIT_SHIFT		48
#define ID_AA64PFR0_SVE_SHIFT		32
#define ID_AA64PFR0_RAS_SHIFT		28
#define ID_AA64PFR0_GIC_SHIFT		24
#define ID_AA64PFR0_ASIMD_SHIFT		20
#define ID_AA64PFR0_FP_SHIFT		16
#define ID_AA64PFR0_EL3_SHIFT		12
#define ID_AA64PFR0_EL2_SHIFT		8
#define ID_AA64PFR0_EL1_SHIFT		4
#define ID_AA64PFR0_EL0_SHIFT		0

#define ID_AA64PFR0_SVE			0x1
#define ID_AA64PFR0_RAS_V1		0x1
#define ID_AA64PFR0_FP_NI		0xf
#define ID_AA64PFR0_FP_SUPPORTED	0x0
#define ID_AA64PFR0_ASIMD_NI		0xf
#define ID_AA64PFR0_ASIMD_SUPPORTED	0x0
#define ID_AA64PFR0_EL1_64BIT_ONLY	0x1
#define ID_AA64PFR0_EL0_64BIT_ONLY	0x1
#define ID_AA64PFR0_EL0_32BIT_64BIT	0x2


#define ID_AA64PFR1_SSBS_SHIFT		4

#define ID_AA64PFR1_SSBS_PSTATE_NI	0
#define ID_AA64PFR1_SSBS_PSTATE_ONLY	1
#define ID_AA64PFR1_SSBS_PSTATE_INSNS	2


#define ID_AA64MMFR0_TGRAN4_SHIFT	28
#define ID_AA64MMFR0_TGRAN64_SHIFT	24
#define ID_AA64MMFR0_TGRAN16_SHIFT	20
#define ID_AA64MMFR0_BIGENDEL0_SHIFT	16
#define ID_AA64MMFR0_SNSMEM_SHIFT	12
#define ID_AA64MMFR0_BIGENDEL_SHIFT	8
#define ID_AA64MMFR0_ASID_SHIFT		4
#define ID_AA64MMFR0_PARANGE_SHIFT	0

#define ID_AA64MMFR0_TGRAN4_NI		0xf
#define ID_AA64MMFR0_TGRAN4_SUPPORTED	0x0
#define ID_AA64MMFR0_TGRAN64_NI		0xf
#define ID_AA64MMFR0_TGRAN64_SUPPORTED	0x0
#define ID_AA64MMFR0_TGRAN16_NI		0x0
#define ID_AA64MMFR0_TGRAN16_SUPPORTED	0x1
#define ID_AA64MMFR0_PARANGE_48		0x5
#define ID_AA64MMFR0_PARANGE_52		0x6

#ifdef CONFIG_ARM64_PA_BITS_52
#define ID_AA64MMFR0_PARANGE_MAX	ID_AA64MMFR0_PARANGE_52
#else
#define ID_AA64MMFR0_PARANGE_MAX	ID_AA64MMFR0_PARANGE_48
#endif


#define ID_AA64MMFR1_PAN_SHIFT		20
#define ID_AA64MMFR1_LOR_SHIFT		16
#define ID_AA64MMFR1_HPD_SHIFT		12
#define ID_AA64MMFR1_VHE_SHIFT		8
#define ID_AA64MMFR1_VMIDBITS_SHIFT	4
#define ID_AA64MMFR1_HADBS_SHIFT	0

#define ID_AA64MMFR1_VMIDBITS_8		0
#define ID_AA64MMFR1_VMIDBITS_16	2


#define ID_AA64MMFR2_FWB_SHIFT		40
#define ID_AA64MMFR2_AT_SHIFT		32
#define ID_AA64MMFR2_LVA_SHIFT		16
#define ID_AA64MMFR2_IESB_SHIFT		12
#define ID_AA64MMFR2_LSM_SHIFT		8
#define ID_AA64MMFR2_UAO_SHIFT		4
#define ID_AA64MMFR2_CNP_SHIFT		0


#define ID_AA64DFR0_PMSVER_SHIFT	32
#define ID_AA64DFR0_CTX_CMPS_SHIFT	28
#define ID_AA64DFR0_WRPS_SHIFT		20
#define ID_AA64DFR0_BRPS_SHIFT		12
#define ID_AA64DFR0_PMUVER_SHIFT	8
#define ID_AA64DFR0_TRACEVER_SHIFT	4
#define ID_AA64DFR0_DEBUGVER_SHIFT	0

#define ID_ISAR5_RDM_SHIFT		24
#define ID_ISAR5_CRC32_SHIFT		16
#define ID_ISAR5_SHA2_SHIFT		12
#define ID_ISAR5_SHA1_SHIFT		8
#define ID_ISAR5_AES_SHIFT		4
#define ID_ISAR5_SEVL_SHIFT		0

#define MVFR0_FPROUND_SHIFT		28
#define MVFR0_FPSHVEC_SHIFT		24
#define MVFR0_FPSQRT_SHIFT		20
#define MVFR0_FPDIVIDE_SHIFT		16
#define MVFR0_FPTRAP_SHIFT		12
#define MVFR0_FPDP_SHIFT		8
#define MVFR0_FPSP_SHIFT		4
#define MVFR0_SIMD_SHIFT		0

#define MVFR1_SIMDFMAC_SHIFT		28
#define MVFR1_FPHP_SHIFT		24
#define MVFR1_SIMDHP_SHIFT		20
#define MVFR1_SIMDSP_SHIFT		16
#define MVFR1_SIMDINT_SHIFT		12
#define MVFR1_SIMDLS_SHIFT		8
#define MVFR1_FPDNAN_SHIFT		4
#define MVFR1_FPFTZ_SHIFT		0


#define ID_AA64MMFR0_TGRAN4_SHIFT	28
#define ID_AA64MMFR0_TGRAN64_SHIFT	24
#define ID_AA64MMFR0_TGRAN16_SHIFT	20

#define ID_AA64MMFR0_TGRAN4_NI		0xf
#define ID_AA64MMFR0_TGRAN4_SUPPORTED	0x0
#define ID_AA64MMFR0_TGRAN64_NI		0xf
#define ID_AA64MMFR0_TGRAN64_SUPPORTED	0x0
#define ID_AA64MMFR0_TGRAN16_NI		0x0
#define ID_AA64MMFR0_TGRAN16_SUPPORTED	0x1

#if defined(CONFIG_ARM64_4K_PAGES)
#define ID_AA64MMFR0_TGRAN_SHIFT	ID_AA64MMFR0_TGRAN4_SHIFT
#define ID_AA64MMFR0_TGRAN_SUPPORTED	ID_AA64MMFR0_TGRAN4_SUPPORTED
#elif defined(CONFIG_ARM64_16K_PAGES)
#define ID_AA64MMFR0_TGRAN_SHIFT	ID_AA64MMFR0_TGRAN16_SHIFT
#define ID_AA64MMFR0_TGRAN_SUPPORTED	ID_AA64MMFR0_TGRAN16_SUPPORTED
#elif defined(CONFIG_ARM64_64K_PAGES)
#define ID_AA64MMFR0_TGRAN_SHIFT	ID_AA64MMFR0_TGRAN64_SHIFT
#define ID_AA64MMFR0_TGRAN_SUPPORTED	ID_AA64MMFR0_TGRAN64_SUPPORTED
#endif



#define ZCR_ELx_LEN_SHIFT	0
#define ZCR_ELx_LEN_SIZE	9
#define ZCR_ELx_LEN_MASK	0x1ff

#define CPACR_EL1_ZEN_EL1EN	(1 << 16) 
#define CPACR_EL1_ZEN_EL0EN	(1 << 17) 
#define CPACR_EL1_ZEN		(CPACR_EL1_ZEN_EL1EN | CPACR_EL1_ZEN_EL0EN)



#define SYS_MPIDR_SAFE_VAL		(1UL << 31)

#ifdef __ASSEMBLY__

	.irp	num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
	.equ	.L__reg_num_x\num, \num
	.endr
	.equ	.L__reg_num_xzr, 31

	.macro	mrs_s, rt, sreg
	 __emit_inst(0xd5200000|(\sreg)|(.L__reg_num_\rt))
	.endm

	.macro	msr_s, sreg, rt
	__emit_inst(0xd5000000|(\sreg)|(.L__reg_num_\rt))
	.endm

#else

#include <linux/build_bug.h>
#include <linux/types.h>

#define __DEFINE_MRS_MSR_S_REGNUM				\
"	.irp	num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30\n" \
"	.equ	.L__reg_num_x\\num, \\num\n"			\
"	.endr\n"						\
"	.equ	.L__reg_num_xzr, 31\n"

#define DEFINE_MRS_S						\
	__DEFINE_MRS_MSR_S_REGNUM				\
"	.macro	mrs_s, rt, sreg\n"				\
	__emit_inst(0xd5200000|(\\sreg)|(.L__reg_num_\\rt))	\
"	.endm\n"

#define DEFINE_MSR_S						\
	__DEFINE_MRS_MSR_S_REGNUM				\
"	.macro	msr_s, sreg, rt\n"				\
	__emit_inst(0xd5000000|(\\sreg)|(.L__reg_num_\\rt))	\
"	.endm\n"

#define UNDEFINE_MRS_S						\
"	.purgem	mrs_s\n"

#define UNDEFINE_MSR_S						\
"	.purgem	msr_s\n"

#define __mrs_s(v, r)						\
	DEFINE_MRS_S						\
"	mrs_s " v ", " __stringify(r) "\n"			\
	UNDEFINE_MRS_S

#define __msr_s(r, v)						\
	DEFINE_MSR_S						\
"	msr_s " __stringify(r) ", " v "\n"			\
	UNDEFINE_MSR_S


#define read_sysreg(r) ({					\
	u64 __val;						\
	asm volatile("mrs %0, " __stringify(r) : "=r" (__val));	\
	__val;							\
})


#define write_sysreg(v, r) do {					\
	u64 __val = (u64)(v);					\
	asm volatile("msr " __stringify(r) ", %x0"		\
		     : : "rZ" (__val));				\
} while (0)


#define read_sysreg_s(r) ({						\
	u64 __val;							\
	asm volatile(__mrs_s("%0", r) : "=r" (__val));			\
	__val;								\
})

#define write_sysreg_s(v, r) do {					\
	u64 __val = (u64)(v);						\
	asm volatile(__msr_s(r, "%x0") : : "rZ" (__val));		\
} while (0)


#define sysreg_clear_set(sysreg, clear, set) do {			\
	u64 __scs_val = read_sysreg(sysreg);				\
	u64 __scs_new = (__scs_val & ~(u64)(clear)) | (set);		\
	if (__scs_new != __scs_val)					\
		write_sysreg(__scs_new, sysreg);			\
} while (0)

#endif

#endif	
