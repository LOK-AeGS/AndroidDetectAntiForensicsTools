

#ifndef __ARM64_KVM_ARM_H__
#define __ARM64_KVM_ARM_H__

#include <asm/esr.h>
#include <asm/memory.h>
#include <asm/types.h>


#define HCR_FWB		(UL(1) << 46)
#define HCR_API		(UL(1) << 41)
#define HCR_APK		(UL(1) << 40)
#define HCR_TEA		(UL(1) << 37)
#define HCR_TERR	(UL(1) << 36)
#define HCR_TLOR	(UL(1) << 35)
#define HCR_E2H		(UL(1) << 34)
#define HCR_ID		(UL(1) << 33)
#define HCR_CD		(UL(1) << 32)
#define HCR_RW_SHIFT	31
#define HCR_RW		(UL(1) << HCR_RW_SHIFT)
#define HCR_TRVM	(UL(1) << 30)
#define HCR_HCD		(UL(1) << 29)
#define HCR_TDZ		(UL(1) << 28)
#define HCR_TGE		(UL(1) << 27)
#define HCR_TVM		(UL(1) << 26)
#define HCR_TTLB	(UL(1) << 25)
#define HCR_TPU		(UL(1) << 24)
#define HCR_TPC		(UL(1) << 23)
#define HCR_TSW		(UL(1) << 22)
#define HCR_TAC		(UL(1) << 21)
#define HCR_TIDCP	(UL(1) << 20)
#define HCR_TSC		(UL(1) << 19)
#define HCR_TID3	(UL(1) << 18)
#define HCR_TID2	(UL(1) << 17)
#define HCR_TID1	(UL(1) << 16)
#define HCR_TID0	(UL(1) << 15)
#define HCR_TWE		(UL(1) << 14)
#define HCR_TWI		(UL(1) << 13)
#define HCR_DC		(UL(1) << 12)
#define HCR_BSU		(3 << 10)
#define HCR_BSU_IS	(UL(1) << 10)
#define HCR_FB		(UL(1) << 9)
#define HCR_VSE		(UL(1) << 8)
#define HCR_VI		(UL(1) << 7)
#define HCR_VF		(UL(1) << 6)
#define HCR_AMO		(UL(1) << 5)
#define HCR_IMO		(UL(1) << 4)
#define HCR_FMO		(UL(1) << 3)
#define HCR_PTW		(UL(1) << 2)
#define HCR_SWIO	(UL(1) << 1)
#define HCR_VM		(UL(1) << 0)


#define HCR_GUEST_FLAGS (HCR_TSC | HCR_TSW | HCR_TWE | HCR_TWI | HCR_VM | \
			 HCR_TVM | HCR_BSU_IS | HCR_FB | HCR_TAC | \
			 HCR_AMO | HCR_SWIO | HCR_TIDCP | HCR_RW | HCR_TLOR | \
			 HCR_FMO | HCR_IMO | HCR_PTW )
#define HCR_VIRT_EXCP_MASK (HCR_VSE | HCR_VI | HCR_VF)
#define HCR_HOST_NVHE_FLAGS (HCR_RW | HCR_API | HCR_APK)
#define HCR_HOST_VHE_FLAGS (HCR_RW | HCR_TGE | HCR_E2H)


#define TCR_EL2_RES1		((1 << 31) | (1 << 23))
#define TCR_EL2_TBI		(1 << 20)
#define TCR_EL2_PS_SHIFT	16
#define TCR_EL2_PS_MASK		(7 << TCR_EL2_PS_SHIFT)
#define TCR_EL2_PS_40B		(2 << TCR_EL2_PS_SHIFT)
#define TCR_EL2_TG0_MASK	TCR_TG0_MASK
#define TCR_EL2_SH0_MASK	TCR_SH0_MASK
#define TCR_EL2_ORGN0_MASK	TCR_ORGN0_MASK
#define TCR_EL2_IRGN0_MASK	TCR_IRGN0_MASK
#define TCR_EL2_T0SZ_MASK	0x3f
#define TCR_EL2_MASK	(TCR_EL2_TG0_MASK | TCR_EL2_SH0_MASK | \
			 TCR_EL2_ORGN0_MASK | TCR_EL2_IRGN0_MASK | TCR_EL2_T0SZ_MASK)


#define VTCR_EL2_RES1		(1U << 31)
#define VTCR_EL2_HD		(1 << 22)
#define VTCR_EL2_HA		(1 << 21)
#define VTCR_EL2_PS_MASK	TCR_EL2_PS_MASK
#define VTCR_EL2_TG0_MASK	TCR_TG0_MASK
#define VTCR_EL2_TG0_4K		TCR_TG0_4K
#define VTCR_EL2_TG0_16K	TCR_TG0_16K
#define VTCR_EL2_TG0_64K	TCR_TG0_64K
#define VTCR_EL2_SH0_MASK	TCR_SH0_MASK
#define VTCR_EL2_SH0_INNER	TCR_SH0_INNER
#define VTCR_EL2_ORGN0_MASK	TCR_ORGN0_MASK
#define VTCR_EL2_ORGN0_WBWA	TCR_ORGN0_WBWA
#define VTCR_EL2_IRGN0_MASK	TCR_IRGN0_MASK
#define VTCR_EL2_IRGN0_WBWA	TCR_IRGN0_WBWA
#define VTCR_EL2_SL0_SHIFT	6
#define VTCR_EL2_SL0_MASK	(3 << VTCR_EL2_SL0_SHIFT)
#define VTCR_EL2_SL0_LVL1	(1 << VTCR_EL2_SL0_SHIFT)
#define VTCR_EL2_T0SZ_MASK	0x3f
#define VTCR_EL2_T0SZ_40B	24
#define VTCR_EL2_VS_SHIFT	19
#define VTCR_EL2_VS_8BIT	(0 << VTCR_EL2_VS_SHIFT)
#define VTCR_EL2_VS_16BIT	(1 << VTCR_EL2_VS_SHIFT)



#define VTCR_EL2_T0SZ_IPA	VTCR_EL2_T0SZ_40B
#define VTCR_EL2_COMMON_BITS	(VTCR_EL2_SH0_INNER | VTCR_EL2_ORGN0_WBWA | \
				 VTCR_EL2_IRGN0_WBWA | VTCR_EL2_RES1)

#ifdef CONFIG_ARM64_64K_PAGES

#define VTCR_EL2_TGRAN_FLAGS		(VTCR_EL2_TG0_64K | VTCR_EL2_SL0_LVL1)
#define VTTBR_X_TGRAN_MAGIC		38
#elif defined(CONFIG_ARM64_16K_PAGES)

#define VTCR_EL2_TGRAN_FLAGS		(VTCR_EL2_TG0_16K | VTCR_EL2_SL0_LVL1)
#define VTTBR_X_TGRAN_MAGIC		42
#else	

#define VTCR_EL2_TGRAN_FLAGS		(VTCR_EL2_TG0_4K | VTCR_EL2_SL0_LVL1)
#define VTTBR_X_TGRAN_MAGIC		37
#endif

#define VTCR_EL2_FLAGS			(VTCR_EL2_COMMON_BITS | VTCR_EL2_TGRAN_FLAGS)
#define VTTBR_X				(VTTBR_X_TGRAN_MAGIC - VTCR_EL2_T0SZ_IPA)

#define VTTBR_BADDR_MASK  (((UL(1) << (PHYS_MASK_SHIFT - VTTBR_X)) - 1) << VTTBR_X)
#define VTTBR_VMID_SHIFT  (UL(48))
#define VTTBR_VMID_MASK(size) (_AT(u64, (1 << size) - 1) << VTTBR_VMID_SHIFT)


#define HSTR_EL2_T(x)	(1 << x)


#define CPTR_EL2_TFP_SHIFT 10


#define CPTR_EL2_TCPAC	(1 << 31)
#define CPTR_EL2_TTA	(1 << 20)
#define CPTR_EL2_TFP	(1 << CPTR_EL2_TFP_SHIFT)
#define CPTR_EL2_TZ	(1 << 8)
#define CPTR_EL2_RES1	0x000032ff 
#define CPTR_EL2_DEFAULT	CPTR_EL2_RES1


#define MDCR_EL2_TPMS		(1 << 14)
#define MDCR_EL2_E2PB_MASK	(UL(0x3))
#define MDCR_EL2_E2PB_SHIFT	(UL(12))
#define MDCR_EL2_TDRA		(1 << 11)
#define MDCR_EL2_TDOSA		(1 << 10)
#define MDCR_EL2_TDA		(1 << 9)
#define MDCR_EL2_TDE		(1 << 8)
#define MDCR_EL2_HPME		(1 << 7)
#define MDCR_EL2_TPM		(1 << 6)
#define MDCR_EL2_TPMCR		(1 << 5)
#define MDCR_EL2_HPMN_MASK	(0x1F)


#define FSC_FAULT	ESR_ELx_FSC_FAULT
#define FSC_ACCESS	ESR_ELx_FSC_ACCESS
#define FSC_PERM	ESR_ELx_FSC_PERM
#define FSC_SEA		ESR_ELx_FSC_EXTABT
#define FSC_SEA_TTW0	(0x14)
#define FSC_SEA_TTW1	(0x15)
#define FSC_SEA_TTW2	(0x16)
#define FSC_SEA_TTW3	(0x17)
#define FSC_SECC	(0x18)
#define FSC_SECC_TTW0	(0x1c)
#define FSC_SECC_TTW1	(0x1d)
#define FSC_SECC_TTW2	(0x1e)
#define FSC_SECC_TTW3	(0x1f)


#define HPFAR_MASK	(~UL(0xf))

#define kvm_arm_exception_type	\
	{0, "IRQ" }, 		\
	{1, "TRAP" }

#define ECN(x) { ESR_ELx_EC_##x, #x }

#define kvm_arm_exception_class \
	ECN(UNKNOWN), ECN(WFx), ECN(CP15_32), ECN(CP15_64), ECN(CP14_MR), \
	ECN(CP14_LS), ECN(FP_ASIMD), ECN(CP10_ID), ECN(CP14_64), ECN(SVC64), \
	ECN(HVC64), ECN(SMC64), ECN(SYS64), ECN(IMP_DEF), ECN(IABT_LOW), \
	ECN(IABT_CUR), ECN(PC_ALIGN), ECN(DABT_LOW), ECN(DABT_CUR), \
	ECN(SP_ALIGN), ECN(FP_EXC32), ECN(FP_EXC64), ECN(SERROR), \
	ECN(BREAKPT_LOW), ECN(BREAKPT_CUR), ECN(SOFTSTP_LOW), \
	ECN(SOFTSTP_CUR), ECN(WATCHPT_LOW), ECN(WATCHPT_CUR), \
	ECN(BKPT32), ECN(VECTOR32), ECN(BRK64)

#define CPACR_EL1_FPEN		(3 << 20)
#define CPACR_EL1_TTA		(1 << 28)
#define CPACR_EL1_DEFAULT	(CPACR_EL1_FPEN | CPACR_EL1_ZEN_EL1EN)

#endif 
