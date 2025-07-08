/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ASM_ARCH_MSM_HSUSB_H
#define __ASM_ARCH_MSM_HSUSB_H

#include <linux/types.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/otg.h>
#include <linux/clk.h>
#include <linux/pm_qos.h>
#include <linux/hrtimer.h>
#include <linux/power_supply.h>
#include <linux/cdev.h>
#include <linux/usb_bam.h>
#include <linux/extcon.h>
#include <linux/regulator/driver.h>


enum usb_vdd_value {
	VDD_NONE = 0,
	VDD_MIN,
	VDD_MAX,
	VDD_VAL_MAX,
};


enum usb_noc_mode {
	USB_NOC_NOM_VOTE = 0,
	USB_NOC_SVS_VOTE,
	USB_NOC_NUM_VOTE,
};


enum usb_chg_state {
	USB_CHG_STATE_UNDEFINED = 0,
	USB_CHG_STATE_IN_PROGRESS,
	USB_CHG_STATE_WAIT_FOR_DCD,
	USB_CHG_STATE_DCD_DONE,
	USB_CHG_STATE_PRIMARY_DONE,
	USB_CHG_STATE_SECONDARY_DONE,
	USB_CHG_STATE_DETECTED,
	USB_CHG_STATE_QUEUE_SM_WORK,
};


enum usb_chg_type {
	USB_INVALID_CHARGER = 0,
	USB_SDP_CHARGER,
	USB_DCP_CHARGER,
	USB_CDP_CHARGER,
	USB_NONCOMPLIANT_CHARGER,
	USB_FLOATED_CHARGER,
};



enum usb_ext_chg_status {
	DEFAULT = 1,
	ACTIVE,
	INACTIVE,
};


enum usb_id_state {
	USB_ID_GROUND = 0,
	USB_ID_FLOAT,
};

#define USB_NUM_BUS_CLOCKS      3


struct msm_otg {
	struct usb_phy phy;
	struct msm_otg_platform_data *pdata;
	struct platform_device *pdev;
	struct mutex lock;
	int irq;
	int async_irq;
	int phy_irq;
	struct clk *xo_clk;
	struct clk *pclk;
	struct clk *core_clk;
	struct clk *sleep_clk;
	struct clk *phy_reset_clk;
	struct clk *phy_por_clk;
	struct clk *phy_csr_clk;
	struct clk *bus_clks[USB_NUM_BUS_CLOCKS];
	struct clk *phy_ref_clk;
	struct reset_control *core_reset;
	struct reset_control *phy_reset;
	struct reset_control *phy_por_reset;
	long core_clk_rate;
	long core_clk_svs_rate;
	long core_clk_nominal_rate;
	enum usb_noc_mode default_noc_mode;
	struct resource *io_res;
	void __iomem *regs;
	void __iomem *phy_csr_regs;
	void __iomem *usb_phy_ctrl_reg;
#define ID		0
#define B_SESS_VLD	1
#define A_BUS_SUSPEND	14
	unsigned long inputs;
	struct work_struct sm_work;
	bool sm_work_pending;
	bool resume_pending;
	atomic_t pm_suspended;
	struct notifier_block pm_notify;
	atomic_t in_lpm;
	bool err_event_seen;
	int async_int;
	unsigned int cur_power;
	struct workqueue_struct *otg_wq;
	struct delayed_work chg_work;
	struct delayed_work id_status_work;
	enum usb_chg_state chg_state;
	enum usb_chg_type chg_type;
	bool chg_detection;
	unsigned int dcd_time;
	unsigned long caps;
	uint32_t bus_perf_client;
	bool host_bus_suspend;
	bool device_bus_suspend;
	bool bus_clks_enabled;
	
#define ALLOW_PHY_POWER_COLLAPSE	BIT(0)
	
#define ALLOW_PHY_RETENTION		BIT(1)
	
#define ALLOW_LPM_ON_DEV_SUSPEND	BIT(2)
	
#define ALLOW_PHY_REGULATORS_LPM	BIT(3)
	
#define ALLOW_HOST_PHY_RETENTION	BIT(4)
	
#define ALLOW_VDD_MIN_WITH_RETENTION_DISABLED BIT(5)

	
#define ALLOW_BUS_SUSPEND_WITHOUT_REWORK BIT(6)
	unsigned long lpm_flags;
#define PHY_PWR_COLLAPSED		BIT(0)
#define PHY_RETENTIONED			BIT(1)
#define XO_SHUTDOWN			BIT(2)
#define CLOCKS_DOWN			BIT(3)
#define PHY_REGULATORS_LPM	BIT(4)
	int reset_counter;
	unsigned int online;

	dev_t ext_chg_dev;
	struct pinctrl *phy_pinctrl;
	bool is_ext_chg_dcp;
	struct qpnp_vadc_chip	*vadc_dev;
	int ext_id_irq;
	bool phy_irq_pending;
	enum usb_id_state id_state;
	bool rm_pulldown;
	struct regulator_desc	dpdm_rdesc;
	struct regulator_dev	*dpdm_rdev;

#define DEBUG_MSG_LEN   128UL

#define DEBUG_MAX_MSG   256UL
	unsigned int dbg_idx;
	rwlock_t dbg_lock;

	char (buf[DEBUG_MAX_MSG])[DEBUG_MSG_LEN];   
	unsigned int vbus_state;
	unsigned int usb_irq_count;
	int pm_qos_latency;
	unsigned int notify_current_mA;
	struct pm_qos_request pm_qos_req_dma;
	struct delayed_work perf_vote_work;
	struct delayed_work sdp_check;
	struct work_struct notify_charger_work;
	bool enable_sdp_check_timer;
};

struct ci13xxx_platform_data {
	u8 usb_core_id;
	int *tlmm_init_seq;
	int tlmm_seq_count;
	
	int log2_itc;
	bool l1_supported;
	bool enable_ahb2ahb_bypass;
	bool enable_streaming;
	bool enable_axi_prefetch;
};

#ifdef CONFIG_USB_BAM
void msm_bam_set_usb_host_dev(struct device *dev);
int msm_do_bam_disable_enable(enum usb_ctrl ctrl);
#else
static inline void msm_bam_set_usb_host_dev(struct device *dev) {}
static inline int msm_do_bam_disable_enable(enum usb_ctrl ctrl)
{ return true; }
#endif
#ifdef CONFIG_USB_CI13XXX_MSM
void msm_hw_soft_reset(void);
#else
static inline void msm_hw_soft_reset(void)
{
}
#endif

#endif
