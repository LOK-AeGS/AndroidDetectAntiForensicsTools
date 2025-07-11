

#ifndef __MFD_MT6397_CORE_H__
#define __MFD_MT6397_CORE_H__

enum mt6397_irq_numbers {
	MT6397_IRQ_SPKL_AB = 0,
	MT6397_IRQ_SPKR_AB,
	MT6397_IRQ_SPKL,
	MT6397_IRQ_SPKR,
	MT6397_IRQ_BAT_L,
	MT6397_IRQ_BAT_H,
	MT6397_IRQ_FG_BAT_L,
	MT6397_IRQ_FG_BAT_H,
	MT6397_IRQ_WATCHDOG,
	MT6397_IRQ_PWRKEY,
	MT6397_IRQ_THR_L,
	MT6397_IRQ_THR_H,
	MT6397_IRQ_VBATON_UNDET,
	MT6397_IRQ_BVALID_DET,
	MT6397_IRQ_CHRDET,
	MT6397_IRQ_OV,
	MT6397_IRQ_LDO,
	MT6397_IRQ_HOMEKEY,
	MT6397_IRQ_ACCDET,
	MT6397_IRQ_AUDIO,
	MT6397_IRQ_RTC,
	MT6397_IRQ_PWRKEY_RSTB,
	MT6397_IRQ_HDMI_SIFM,
	MT6397_IRQ_HDMI_CEC,
	MT6397_IRQ_VCA15,
	MT6397_IRQ_VSRMCA15,
	MT6397_IRQ_VCORE,
	MT6397_IRQ_VGPU,
	MT6397_IRQ_VIO18,
	MT6397_IRQ_VPCA7,
	MT6397_IRQ_VSRMCA7,
	MT6397_IRQ_VDRM,
	MT6397_IRQ_NR,
};

struct mt6397_chip {
	struct device *dev;
	struct regmap *regmap;
	int irq;
	struct irq_domain *irq_domain;
	struct mutex irqlock;
	u16 wake_mask[2];
	u16 irq_masks_cur[2];
	u16 irq_masks_cache[2];
	u16 int_con[2];
	u16 int_status[2];
};

#endif 
