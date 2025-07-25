

#ifndef __ASM_ESR_H
#define __ASM_ESR_H

#include <asm/memory.h>
#include <asm/sysreg.h>

#define ESR_ELx_EC_UNKNOWN	(0x00)
#define ESR_ELx_EC_WFx		(0x01)

#define ESR_ELx_EC_CP15_32	(0x03)
#define ESR_ELx_EC_CP15_64	(0x04)
#define ESR_ELx_EC_CP14_MR	(0x05)
#define ESR_ELx_EC_CP14_LS	(0x06)
#define ESR_ELx_EC_FP_ASIMD	(0x07)
#define ESR_ELx_EC_CP10_ID	(0x08)

#define ESR_ELx_EC_CP14_64	(0x0C)

#define ESR_ELx_EC_ILL		(0x0E)

#define ESR_ELx_EC_SVC32	(0x11)
#define ESR_ELx_EC_HVC32	(0x12)
#define ESR_ELx_EC_SMC32	(0x13)

#define ESR_ELx_EC_SVC64	(0x15)
#define ESR_ELx_EC_HVC64	(0x16)
#define ESR_ELx_EC_SMC64	(0x17)
#define ESR_ELx_EC_SYS64	(0x18)
#define ESR_ELx_EC_SVE		(0x19)

#define ESR_ELx_EC_IMP_DEF	(0x1f)
#define ESR_ELx_EC_IABT_LOW	(0x20)
#define ESR_ELx_EC_IABT_CUR	(0x21)
#define ESR_ELx_EC_PC_ALIGN	(0x22)

#define ESR_ELx_EC_DABT_LOW	(0x24)
#define ESR_ELx_EC_DABT_CUR	(0x25)
#define ESR_ELx_EC_SP_ALIGN	(0x26)

#define ESR_ELx_EC_FP_EXC32	(0x28)

#define ESR_ELx_EC_FP_EXC64	(0x2C)

#define ESR_ELx_EC_SERROR	(0x2F)
#define ESR_ELx_EC_BREAKPT_LOW	(0x30)
#define ESR_ELx_EC_BREAKPT_CUR	(0x31)
#define ESR_ELx_EC_SOFTSTP_LOW	(0x32)
#define ESR_ELx_EC_SOFTSTP_CUR	(0x33)
#define ESR_ELx_EC_WATCHPT_LOW	(0x34)
#define ESR_ELx_EC_WATCHPT_CUR	(0x35)

#define ESR_ELx_EC_BKPT32	(0x38)

#define ESR_ELx_EC_VECTOR32	(0x3A)

#define ESR_ELx_EC_BRK64	(0x3C)

#define ESR_ELx_EC_MAX		(0x3F)

#define ESR_ELx_EC_SHIFT	(26)
#define ESR_ELx_EC_MASK		(UL(0x3F) << ESR_ELx_EC_SHIFT)
#define ESR_ELx_EC(esr)		(((esr) & ESR_ELx_EC_MASK) >> ESR_ELx_EC_SHIFT)

#define ESR_ELx_IL_SHIFT	(25)
#define ESR_ELx_IL		(UL(1) << ESR_ELx_IL_SHIFT)
#define ESR_ELx_ISS_MASK	(ESR_ELx_IL - 1)


#define ESR_ELx_WNR_SHIFT	(6)
#define ESR_ELx_WNR		(UL(1) << ESR_ELx_WNR_SHIFT)


#define ESR_ELx_IDS_SHIFT	(24)
#define ESR_ELx_IDS		(UL(1) << ESR_ELx_IDS_SHIFT)
#define ESR_ELx_AET_SHIFT	(10)
#define ESR_ELx_AET		(UL(0x7) << ESR_ELx_AET_SHIFT)

#define ESR_ELx_AET_UC		(UL(0) << ESR_ELx_AET_SHIFT)
#define ESR_ELx_AET_UEU		(UL(1) << ESR_ELx_AET_SHIFT)
#define ESR_ELx_AET_UEO		(UL(2) << ESR_ELx_AET_SHIFT)
#define ESR_ELx_AET_UER		(UL(3) << ESR_ELx_AET_SHIFT)
#define ESR_ELx_AET_CE		(UL(6) << ESR_ELx_AET_SHIFT)


#define ESR_ELx_SET_SHIFT	(11)
#define ESR_ELx_SET_MASK	(UL(3) << ESR_ELx_SET_SHIFT)
#define ESR_ELx_FnV_SHIFT	(10)
#define ESR_ELx_FnV		(UL(1) << ESR_ELx_FnV_SHIFT)
#define ESR_ELx_EA_SHIFT	(9)
#define ESR_ELx_EA		(UL(1) << ESR_ELx_EA_SHIFT)
#define ESR_ELx_S1PTW_SHIFT	(7)
#define ESR_ELx_S1PTW		(UL(1) << ESR_ELx_S1PTW_SHIFT)


#define ESR_ELx_FSC		(0x3F)
#define ESR_ELx_FSC_TYPE	(0x3C)
#define ESR_ELx_FSC_EXTABT	(0x10)
#define ESR_ELx_FSC_SERROR	(0x11)
#define ESR_ELx_FSC_ACCESS	(0x08)
#define ESR_ELx_FSC_FAULT	(0x04)
#define ESR_ELx_FSC_PERM	(0x0C)


#define ESR_ELx_ISV_SHIFT	(24)
#define ESR_ELx_ISV		(UL(1) << ESR_ELx_ISV_SHIFT)
#define ESR_ELx_SAS_SHIFT	(22)
#define ESR_ELx_SAS		(UL(3) << ESR_ELx_SAS_SHIFT)
#define ESR_ELx_SSE_SHIFT	(21)
#define ESR_ELx_SSE		(UL(1) << ESR_ELx_SSE_SHIFT)
#define ESR_ELx_SRT_SHIFT	(16)
#define ESR_ELx_SRT_MASK	(UL(0x1F) << ESR_ELx_SRT_SHIFT)
#define ESR_ELx_SF_SHIFT	(15)
#define ESR_ELx_SF 		(UL(1) << ESR_ELx_SF_SHIFT)
#define ESR_ELx_AR_SHIFT	(14)
#define ESR_ELx_AR 		(UL(1) << ESR_ELx_AR_SHIFT)
#define ESR_ELx_CM_SHIFT	(8)
#define ESR_ELx_CM 		(UL(1) << ESR_ELx_CM_SHIFT)


#define ESR_ELx_CV		(UL(1) << 24)
#define ESR_ELx_COND_SHIFT	(20)
#define ESR_ELx_COND_MASK	(UL(0xF) << ESR_ELx_COND_SHIFT)
#define ESR_ELx_WFx_ISS_WFE	(UL(1) << 0)
#define ESR_ELx_xVC_IMM_MASK	((1UL << 16) - 1)

#define DISR_EL1_IDS		(UL(1) << 24)

#define DISR_EL1_ESR_MASK	(ESR_ELx_AET | ESR_ELx_EA | ESR_ELx_FSC)




#define ESR_ELx_VAL_BRK64(imm)					\
	((ESR_ELx_EC_BRK64 << ESR_ELx_EC_SHIFT) | ESR_ELx_IL |	\
	 ((imm) & 0xffff))


#define ESR_ELx_SYS64_ISS_RES0_SHIFT	22
#define ESR_ELx_SYS64_ISS_RES0_MASK	(UL(0x7) << ESR_ELx_SYS64_ISS_RES0_SHIFT)
#define ESR_ELx_SYS64_ISS_DIR_MASK	0x1
#define ESR_ELx_SYS64_ISS_DIR_READ	0x1
#define ESR_ELx_SYS64_ISS_DIR_WRITE	0x0

#define ESR_ELx_SYS64_ISS_RT_SHIFT	5
#define ESR_ELx_SYS64_ISS_RT_MASK	(UL(0x1f) << ESR_ELx_SYS64_ISS_RT_SHIFT)
#define ESR_ELx_SYS64_ISS_CRM_SHIFT	1
#define ESR_ELx_SYS64_ISS_CRM_MASK	(UL(0xf) << ESR_ELx_SYS64_ISS_CRM_SHIFT)
#define ESR_ELx_SYS64_ISS_CRN_SHIFT	10
#define ESR_ELx_SYS64_ISS_CRN_MASK	(UL(0xf) << ESR_ELx_SYS64_ISS_CRN_SHIFT)
#define ESR_ELx_SYS64_ISS_OP1_SHIFT	14
#define ESR_ELx_SYS64_ISS_OP1_MASK	(UL(0x7) << ESR_ELx_SYS64_ISS_OP1_SHIFT)
#define ESR_ELx_SYS64_ISS_OP2_SHIFT	17
#define ESR_ELx_SYS64_ISS_OP2_MASK	(UL(0x7) << ESR_ELx_SYS64_ISS_OP2_SHIFT)
#define ESR_ELx_SYS64_ISS_OP0_SHIFT	20
#define ESR_ELx_SYS64_ISS_OP0_MASK	(UL(0x3) << ESR_ELx_SYS64_ISS_OP0_SHIFT)
#define ESR_ELx_SYS64_ISS_SYS_MASK	(ESR_ELx_SYS64_ISS_OP0_MASK | \
					 ESR_ELx_SYS64_ISS_OP1_MASK | \
					 ESR_ELx_SYS64_ISS_OP2_MASK | \
					 ESR_ELx_SYS64_ISS_CRN_MASK | \
					 ESR_ELx_SYS64_ISS_CRM_MASK)
#define ESR_ELx_SYS64_ISS_SYS_VAL(op0, op1, op2, crn, crm) \
					(((op0) << ESR_ELx_SYS64_ISS_OP0_SHIFT) | \
					 ((op1) << ESR_ELx_SYS64_ISS_OP1_SHIFT) | \
					 ((op2) << ESR_ELx_SYS64_ISS_OP2_SHIFT) | \
					 ((crn) << ESR_ELx_SYS64_ISS_CRN_SHIFT) | \
					 ((crm) << ESR_ELx_SYS64_ISS_CRM_SHIFT))

#define ESR_ELx_SYS64_ISS_SYS_OP_MASK	(ESR_ELx_SYS64_ISS_SYS_MASK | \
					 ESR_ELx_SYS64_ISS_DIR_MASK)

#define ESR_ELx_SYS64_ISS_CRM_DC_CIVAC	14
#define ESR_ELx_SYS64_ISS_CRM_DC_CVAP	12
#define ESR_ELx_SYS64_ISS_CRM_DC_CVAU	11
#define ESR_ELx_SYS64_ISS_CRM_DC_CVAC	10
#define ESR_ELx_SYS64_ISS_CRM_IC_IVAU	5

#define ESR_ELx_SYS64_ISS_EL0_CACHE_OP_MASK	(ESR_ELx_SYS64_ISS_OP0_MASK | \
						 ESR_ELx_SYS64_ISS_OP1_MASK | \
						 ESR_ELx_SYS64_ISS_OP2_MASK | \
						 ESR_ELx_SYS64_ISS_CRN_MASK | \
						 ESR_ELx_SYS64_ISS_DIR_MASK)
#define ESR_ELx_SYS64_ISS_EL0_CACHE_OP_VAL \
				(ESR_ELx_SYS64_ISS_SYS_VAL(1, 3, 1, 7, 0) | \
				 ESR_ELx_SYS64_ISS_DIR_WRITE)

#define ESR_ELx_SYS64_ISS_SYS_CTR	ESR_ELx_SYS64_ISS_SYS_VAL(3, 3, 1, 0, 0)
#define ESR_ELx_SYS64_ISS_SYS_CTR_READ	(ESR_ELx_SYS64_ISS_SYS_CTR | \
					 ESR_ELx_SYS64_ISS_DIR_READ)

#define ESR_ELx_SYS64_ISS_SYS_CNTVCT	(ESR_ELx_SYS64_ISS_SYS_VAL(3, 3, 2, 14, 0) | \
					 ESR_ELx_SYS64_ISS_DIR_READ)

#define ESR_ELx_SYS64_ISS_SYS_CNTFRQ	(ESR_ELx_SYS64_ISS_SYS_VAL(3, 3, 0, 14, 0) | \
					 ESR_ELx_SYS64_ISS_DIR_READ)

#define esr_sys64_to_sysreg(e)					\
	sys_reg((((e) & ESR_ELx_SYS64_ISS_OP0_MASK) >>		\
		 ESR_ELx_SYS64_ISS_OP0_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_OP1_MASK) >>		\
		 ESR_ELx_SYS64_ISS_OP1_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_CRN_MASK) >>		\
		 ESR_ELx_SYS64_ISS_CRN_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_CRM_MASK) >>		\
		 ESR_ELx_SYS64_ISS_CRM_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_OP2_MASK) >>		\
		 ESR_ELx_SYS64_ISS_OP2_SHIFT))

#define esr_cp15_to_sysreg(e)					\
	sys_reg(3,						\
		(((e) & ESR_ELx_SYS64_ISS_OP1_MASK) >>		\
		 ESR_ELx_SYS64_ISS_OP1_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_CRN_MASK) >>		\
		 ESR_ELx_SYS64_ISS_CRN_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_CRM_MASK) >>		\
		 ESR_ELx_SYS64_ISS_CRM_SHIFT),			\
		(((e) & ESR_ELx_SYS64_ISS_OP2_MASK) >>		\
		 ESR_ELx_SYS64_ISS_OP2_SHIFT))



#define ESR_ELx_FP_EXC_TFV	(UL(1) << 23)


#define ESR_ELx_CP15_32_ISS_DIR_MASK	0x1
#define ESR_ELx_CP15_32_ISS_DIR_READ	0x1
#define ESR_ELx_CP15_32_ISS_DIR_WRITE	0x0

#define ESR_ELx_CP15_32_ISS_RT_SHIFT	5
#define ESR_ELx_CP15_32_ISS_RT_MASK	(UL(0x1f) << ESR_ELx_CP15_32_ISS_RT_SHIFT)
#define ESR_ELx_CP15_32_ISS_CRM_SHIFT	1
#define ESR_ELx_CP15_32_ISS_CRM_MASK	(UL(0xf) << ESR_ELx_CP15_32_ISS_CRM_SHIFT)
#define ESR_ELx_CP15_32_ISS_CRN_SHIFT	10
#define ESR_ELx_CP15_32_ISS_CRN_MASK	(UL(0xf) << ESR_ELx_CP15_32_ISS_CRN_SHIFT)
#define ESR_ELx_CP15_32_ISS_OP1_SHIFT	14
#define ESR_ELx_CP15_32_ISS_OP1_MASK	(UL(0x7) << ESR_ELx_CP15_32_ISS_OP1_SHIFT)
#define ESR_ELx_CP15_32_ISS_OP2_SHIFT	17
#define ESR_ELx_CP15_32_ISS_OP2_MASK	(UL(0x7) << ESR_ELx_CP15_32_ISS_OP2_SHIFT)

#define ESR_ELx_CP15_32_ISS_SYS_MASK	(ESR_ELx_CP15_32_ISS_OP1_MASK | \
					 ESR_ELx_CP15_32_ISS_OP2_MASK | \
					 ESR_ELx_CP15_32_ISS_CRN_MASK | \
					 ESR_ELx_CP15_32_ISS_CRM_MASK | \
					 ESR_ELx_CP15_32_ISS_DIR_MASK)
#define ESR_ELx_CP15_32_ISS_SYS_VAL(op1, op2, crn, crm) \
					(((op1) << ESR_ELx_CP15_32_ISS_OP1_SHIFT) | \
					 ((op2) << ESR_ELx_CP15_32_ISS_OP2_SHIFT) | \
					 ((crn) << ESR_ELx_CP15_32_ISS_CRN_SHIFT) | \
					 ((crm) << ESR_ELx_CP15_32_ISS_CRM_SHIFT))

#define ESR_ELx_CP15_64_ISS_DIR_MASK	0x1
#define ESR_ELx_CP15_64_ISS_DIR_READ	0x1
#define ESR_ELx_CP15_64_ISS_DIR_WRITE	0x0

#define ESR_ELx_CP15_64_ISS_RT_SHIFT	5
#define ESR_ELx_CP15_64_ISS_RT_MASK	(UL(0x1f) << ESR_ELx_CP15_64_ISS_RT_SHIFT)

#define ESR_ELx_CP15_64_ISS_RT2_SHIFT	10
#define ESR_ELx_CP15_64_ISS_RT2_MASK	(UL(0x1f) << ESR_ELx_CP15_64_ISS_RT2_SHIFT)

#define ESR_ELx_CP15_64_ISS_OP1_SHIFT	16
#define ESR_ELx_CP15_64_ISS_OP1_MASK	(UL(0xf) << ESR_ELx_CP15_64_ISS_OP1_SHIFT)
#define ESR_ELx_CP15_64_ISS_CRM_SHIFT	1
#define ESR_ELx_CP15_64_ISS_CRM_MASK	(UL(0xf) << ESR_ELx_CP15_64_ISS_CRM_SHIFT)

#define ESR_ELx_CP15_64_ISS_SYS_VAL(op1, crm) \
					(((op1) << ESR_ELx_CP15_64_ISS_OP1_SHIFT) | \
					 ((crm) << ESR_ELx_CP15_64_ISS_CRM_SHIFT))

#define ESR_ELx_CP15_64_ISS_SYS_MASK	(ESR_ELx_CP15_64_ISS_OP1_MASK |	\
					 ESR_ELx_CP15_64_ISS_CRM_MASK | \
					 ESR_ELx_CP15_64_ISS_DIR_MASK)

#define ESR_ELx_CP15_64_ISS_SYS_CNTVCT	(ESR_ELx_CP15_64_ISS_SYS_VAL(1, 14) | \
					 ESR_ELx_CP15_64_ISS_DIR_READ)

#define ESR_ELx_CP15_32_ISS_SYS_CNTFRQ	(ESR_ELx_CP15_32_ISS_SYS_VAL(0, 0, 14, 0) |\
					 ESR_ELx_CP15_32_ISS_DIR_READ)

#ifndef __ASSEMBLY__
#include <asm/types.h>

static inline bool esr_is_data_abort(u32 esr)
{
	const u32 ec = ESR_ELx_EC(esr);

	return ec == ESR_ELx_EC_DABT_LOW || ec == ESR_ELx_EC_DABT_CUR;
}

const char *esr_get_class_string(u32 esr);
#endif 

#endif 
