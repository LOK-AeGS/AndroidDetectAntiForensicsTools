/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __LINUX_USB_PHY_H
#define __LINUX_USB_PHY_H

#include <linux/extcon.h>
#include <linux/notifier.h>
#include <linux/usb.h>
#include <uapi/linux/usb/charger.h>

#define ENABLE_DP_MANUAL_PULLUP	BIT(0)
#define ENABLE_SECONDARY_PHY	BIT(1)
#define PHY_HOST_MODE		BIT(2)
#define PHY_CHARGER_CONNECTED	BIT(3)
#define PHY_VBUS_VALID_OVERRIDE	BIT(4)
#define DEVICE_IN_SS_MODE	BIT(5)
#define PHY_LANE_A		BIT(6)
#define PHY_LANE_B		BIT(7)
#define PHY_HSFS_MODE		BIT(8)
#define PHY_LS_MODE		BIT(9)
#define PHY_USB_DP_CONCURRENT_MODE	BIT(10)
#define EUD_SPOOF_DISCONNECT	BIT(11)
#define EUD_SPOOF_CONNECT	BIT(12)
#define PHY_SUS_OVERRIDE	BIT(13)

enum usb_phy_interface {
	USBPHY_INTERFACE_MODE_UNKNOWN,
	USBPHY_INTERFACE_MODE_UTMI,
	USBPHY_INTERFACE_MODE_UTMIW,
	USBPHY_INTERFACE_MODE_ULPI,
	USBPHY_INTERFACE_MODE_SERIAL,
	USBPHY_INTERFACE_MODE_HSIC,
};

enum usb_phy_events {
	USB_EVENT_NONE,         
	USB_EVENT_VBUS,         
	USB_EVENT_ID,           
	USB_EVENT_CHARGER,      
	USB_EVENT_ENUMERATED,   
};


enum usb_phy_type {
	USB_PHY_TYPE_UNDEFINED,
	USB_PHY_TYPE_USB2,
	USB_PHY_TYPE_USB3,
	USB_PHY_TYPE_USB3_OR_DP,
	USB_PHY_TYPE_USB3_AND_DP,
};


enum usb_otg_state {
	OTG_STATE_UNDEFINED = 0,

	
	OTG_STATE_B_IDLE,
	OTG_STATE_B_SRP_INIT,
	OTG_STATE_B_PERIPHERAL,
	OTG_STATE_B_SUSPEND,

	
	OTG_STATE_B_WAIT_ACON,
	OTG_STATE_B_HOST,

	
	OTG_STATE_A_IDLE,
	OTG_STATE_A_WAIT_VRISE,
	OTG_STATE_A_WAIT_BCON,
	OTG_STATE_A_HOST,
	OTG_STATE_A_SUSPEND,
	OTG_STATE_A_PERIPHERAL,
	OTG_STATE_A_WAIT_VFALL,
	OTG_STATE_A_VBUS_ERR,
};

struct usb_phy;
struct usb_otg;


struct usb_phy_io_ops {
	int (*read)(struct usb_phy *x, u32 reg);
	int (*write)(struct usb_phy *x, u32 val, u32 reg);
};

struct usb_charger_current {
	unsigned int sdp_min;
	unsigned int sdp_max;
	unsigned int dcp_min;
	unsigned int dcp_max;
	unsigned int cdp_min;
	unsigned int cdp_max;
	unsigned int aca_min;
	unsigned int aca_max;
};

struct usb_phy {
	struct device		*dev;
	const char		*label;
	unsigned int		 flags;

	enum usb_phy_type	type;
	enum usb_phy_events	last_event;

	struct usb_otg		*otg;

	struct device		*io_dev;
	struct usb_phy_io_ops	*io_ops;
	void __iomem		*io_priv;

	
	struct extcon_dev	*edev;
	struct extcon_dev	*id_edev;
	struct notifier_block	vbus_nb;
	struct notifier_block	id_nb;
	struct notifier_block	type_nb;

	
	enum usb_charger_type	chg_type;
	enum usb_charger_state	chg_state;
	struct usb_charger_current	chg_cur;
	struct work_struct		chg_work;

	
	struct atomic_notifier_head	notifier;

	
	u16			port_status;
	u16			port_change;

	
	struct list_head	head;

	
	int	(*init)(struct usb_phy *x);
	void	(*shutdown)(struct usb_phy *x);

	
	int	(*set_vbus)(struct usb_phy *x, int on);

	
	int	(*set_power)(struct usb_phy *x,
				unsigned mA);

	
	int	(*set_suspend)(struct usb_phy *x,
				int suspend);

	
	int	(*set_wakeup)(struct usb_phy *x, bool enabled);

	
	int	(*notify_connect)(struct usb_phy *x,
			enum usb_device_speed speed);
	int	(*notify_disconnect)(struct usb_phy *x,
			enum usb_device_speed speed);

	
	enum usb_charger_type (*charger_detect)(struct usb_phy *x);

	
	int     (*reset)(struct usb_phy *x);
	int	(*drive_dp_pulse)(struct usb_phy *x, unsigned int pulse_width);

	
	void    (*dbg_event)(struct usb_phy *x,
			char *event, int msg1, int msg2);

};


extern int usb_add_phy(struct usb_phy *, enum usb_phy_type type);
extern int usb_add_phy_dev(struct usb_phy *);
extern void usb_remove_phy(struct usb_phy *);


static inline int usb_phy_io_read(struct usb_phy *x, u32 reg)
{
	if (x && x->io_ops && x->io_ops->read)
		return x->io_ops->read(x, reg);

	return -EINVAL;
}

static inline int usb_phy_io_write(struct usb_phy *x, u32 val, u32 reg)
{
	if (x && x->io_ops && x->io_ops->write)
		return x->io_ops->write(x, val, reg);

	return -EINVAL;
}

static inline int
usb_phy_init(struct usb_phy *x)
{
	if (x && x->init)
		return x->init(x);

	return 0;
}

static inline void
usb_phy_shutdown(struct usb_phy *x)
{
	if (x && x->shutdown)
		x->shutdown(x);
}

static inline int
usb_phy_vbus_on(struct usb_phy *x)
{
	if (!x || !x->set_vbus)
		return 0;

	return x->set_vbus(x, true);
}

static inline int
usb_phy_vbus_off(struct usb_phy *x)
{
	if (!x || !x->set_vbus)
		return 0;

	return x->set_vbus(x, false);
}

static inline int
usb_phy_reset(struct usb_phy *x)
{
	if (x && x->reset)
		return x->reset(x);

	return 0;
}

static inline int
usb_phy_drive_dp_pulse(struct usb_phy *x, unsigned int pulse_width)
{
	if (x && x->drive_dp_pulse)
		return x->drive_dp_pulse(x, pulse_width);

	return 0;
}


#if IS_ENABLED(CONFIG_USB_PHY)
extern struct usb_phy *usb_get_phy(enum usb_phy_type type);
extern struct usb_phy *devm_usb_get_phy(struct device *dev,
	enum usb_phy_type type);
extern struct usb_phy *devm_usb_get_phy_by_phandle(struct device *dev,
	const char *phandle, u8 index);
extern struct usb_phy *devm_usb_get_phy_by_node(struct device *dev,
	struct device_node *node, struct notifier_block *nb);
extern void usb_put_phy(struct usb_phy *);
extern void devm_usb_put_phy(struct device *dev, struct usb_phy *x);
extern void usb_phy_set_event(struct usb_phy *x, unsigned long event);
extern void usb_phy_set_charger_current(struct usb_phy *usb_phy,
					unsigned int mA);
extern void usb_phy_get_charger_current(struct usb_phy *usb_phy,
					unsigned int *min, unsigned int *max);
extern void usb_phy_set_charger_state(struct usb_phy *usb_phy,
				      enum usb_charger_state state);
#else
static inline struct usb_phy *usb_get_phy(enum usb_phy_type type)
{
	return ERR_PTR(-ENXIO);
}

static inline struct usb_phy *devm_usb_get_phy(struct device *dev,
	enum usb_phy_type type)
{
	return ERR_PTR(-ENXIO);
}

static inline struct usb_phy *devm_usb_get_phy_by_phandle(struct device *dev,
	const char *phandle, u8 index)
{
	return ERR_PTR(-ENXIO);
}

static inline struct usb_phy *devm_usb_get_phy_by_node(struct device *dev,
	struct device_node *node, struct notifier_block *nb)
{
	return ERR_PTR(-ENXIO);
}

static inline void usb_put_phy(struct usb_phy *x)
{
}

static inline void devm_usb_put_phy(struct device *dev, struct usb_phy *x)
{
}

static inline void usb_phy_set_event(struct usb_phy *x, unsigned long event)
{
}

static inline void usb_phy_set_charger_current(struct usb_phy *usb_phy,
					       unsigned int mA)
{
}

static inline void usb_phy_get_charger_current(struct usb_phy *usb_phy,
					       unsigned int *min,
					       unsigned int *max)
{
}

static inline void usb_phy_set_charger_state(struct usb_phy *usb_phy,
					     enum usb_charger_state state)
{
}
#endif

static inline int
usb_phy_set_power(struct usb_phy *x, unsigned mA)
{
	if (!x)
		return 0;

	usb_phy_set_charger_current(x, mA);

	if (x->set_power)
		return x->set_power(x, mA);
	return 0;
}


static inline int
usb_phy_set_suspend(struct usb_phy *x, int suspend)
{
	if (x && x->set_suspend != NULL)
		return x->set_suspend(x, suspend);
	else
		return 0;
}

static inline int
usb_phy_set_wakeup(struct usb_phy *x, bool enabled)
{
	if (x && x->set_wakeup)
		return x->set_wakeup(x, enabled);
	else
		return 0;
}

static inline int
usb_phy_notify_connect(struct usb_phy *x, enum usb_device_speed speed)
{
	if (x && x->notify_connect)
		return x->notify_connect(x, speed);
	else
		return 0;
}

static inline int
usb_phy_notify_disconnect(struct usb_phy *x, enum usb_device_speed speed)
{
	if (x && x->notify_disconnect)
		return x->notify_disconnect(x, speed);
	else
		return 0;
}


static inline int
usb_register_notifier(struct usb_phy *x, struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&x->notifier, nb);
}

static inline void
usb_unregister_notifier(struct usb_phy *x, struct notifier_block *nb)
{
	atomic_notifier_chain_unregister(&x->notifier, nb);
}

static inline const char *usb_phy_type_string(enum usb_phy_type type)
{
	switch (type) {
	case USB_PHY_TYPE_USB2:
		return "USB2 PHY";
	case USB_PHY_TYPE_USB3:
		return "USB3 PHY";
	default:
		return "UNKNOWN PHY TYPE";
	}
}
#endif 
