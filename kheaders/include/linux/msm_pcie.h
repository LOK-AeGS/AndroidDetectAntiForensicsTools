/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __MSM_PCIE_H
#define __MSM_PCIE_H

#include <linux/types.h>
#include <linux/pci.h>

enum msm_pcie_config {
	MSM_PCIE_CONFIG_INVALID = 0,
	MSM_PCIE_CONFIG_NO_CFG_RESTORE = 0x1,
	MSM_PCIE_CONFIG_LINKDOWN = 0x2,
	MSM_PCIE_CONFIG_NO_RECOVERY = 0x4,
	MSM_PCIE_CONFIG_NO_L1SS_TO = 0x8,
};

enum msm_pcie_pm_opt {
	MSM_PCIE_DRV_SUSPEND,
	MSM_PCIE_SUSPEND,
	MSM_PCIE_RESUME,
	MSM_PCIE_DISABLE_PC,
	MSM_PCIE_ENABLE_PC,
	MSM_PCIE_HANDLE_LINKDOWN,
};

enum msm_pcie_event {
	MSM_PCIE_EVENT_INVALID = 0,
	MSM_PCIE_EVENT_LINKDOWN = 0x1,
	MSM_PCIE_EVENT_LINKUP = 0x2,
	MSM_PCIE_EVENT_WAKEUP = 0x4,
	MSM_PCIE_EVENT_L1SS_TIMEOUT = BIT(3),
	MSM_PCIE_EVENT_DRV_CONNECT = BIT(4),
	MSM_PCIE_EVENT_DRV_DISCONNECT = BIT(5),
	MSM_PCIE_EVENT_LINK_RECOVER = BIT(6),
};

enum msm_pcie_trigger {
	MSM_PCIE_TRIGGER_CALLBACK,
	MSM_PCIE_TRIGGER_COMPLETION,
};

struct msm_pcie_notify {
	enum msm_pcie_event event;
	void *user;
	void *data;
	u32 options;
};

struct msm_pcie_register_event {
	u32 events;
	void *user;
	enum msm_pcie_trigger mode;
	void (*callback)(struct msm_pcie_notify *notify);
	struct msm_pcie_notify notify;
	struct completion *completion;
	u32 options;
};

#ifdef CONFIG_PCI_MSM_MSI
int msm_msi_init(struct device *dev);
#else
static inline int msm_msi_init(struct device *dev)
{
	return -EINVAL;
}
#endif

#ifdef CONFIG_PCI_MSM


int msm_pcie_set_target_link_speed(u32 rc_idx, u32 target_link_speed);


void msm_pcie_allow_l1(struct pci_dev *pci_dev);


int msm_pcie_prevent_l1(struct pci_dev *pci_dev);


int msm_pcie_set_link_bandwidth(struct pci_dev *pci_dev, u16 target_link_speed,
				u16 target_link_width);


void msm_pcie_l1ss_timeout_disable(struct pci_dev *pci_dev);


void msm_pcie_l1ss_timeout_enable(struct pci_dev *pci_dev);


int msm_pcie_pm_control(enum msm_pcie_pm_opt pm_opt, u32 busnr, void *user,
			void *data, u32 options);


int msm_pcie_register_event(struct msm_pcie_register_event *reg);


int msm_pcie_deregister_event(struct msm_pcie_register_event *reg);


int msm_pcie_recover_config(struct pci_dev *dev);


int msm_pcie_enumerate(u32 rc_idx);


int msm_pcie_recover_config(struct pci_dev *dev);


int msm_pcie_shadow_control(struct pci_dev *dev, bool enable);


int msm_pcie_debug_info(struct pci_dev *dev, u32 option, u32 base,
			u32 offset, u32 mask, u32 value);


int msm_pcie_reg_dump(struct pci_dev *pci_dev, u8 *buff, u32 len);

#else 
static inline int msm_pcie_pm_control(enum msm_pcie_pm_opt pm_opt, u32 busnr,
			void *user, void *data, u32 options)
{
	return -ENODEV;
}

static inline int msm_pcie_set_target_link_speed(u32 rc_idx,
						u32 target_link_speed)
{
	return -ENODEV;
}

static inline void msm_pcie_allow_l1(struct pci_dev *pci_dev)
{
}

static inline int msm_pcie_prevent_l1(struct pci_dev *pci_dev)
{
	return -ENODEV;
}

static inline int msm_pcie_l1ss_timeout_disable(struct pci_dev *pci_dev)
{
	return -ENODEV;
}

static inline int msm_pcie_l1ss_timeout_enable(struct pci_dev *pci_dev)
{
	return -ENODEV;
}

static inline int msm_pcie_register_event(struct msm_pcie_register_event *reg)
{
	return -ENODEV;
}

static inline int msm_pcie_deregister_event(struct msm_pcie_register_event *reg)
{
	return -ENODEV;
}

static inline int msm_pcie_recover_config(struct pci_dev *dev)
{
	return -ENODEV;
}

static inline int msm_pcie_enumerate(u32 rc_idx)
{
	return -ENODEV;
}

static inline int msm_pcie_shadow_control(struct pci_dev *dev, bool enable)
{
	return -ENODEV;
}

static inline int msm_pcie_debug_info(struct pci_dev *dev, u32 option, u32 base,
			u32 offset, u32 mask, u32 value)
{
	return -ENODEV;
}

static inline int msm_pcie_reg_dump(struct pci_dev *pci_dev, u8 *buff, u32 len)
{
	return -ENODEV;
}
#endif 

#endif 
