

#ifndef __USB_TYPEC_MANAGER_NOTIFIER_H__
#define __USB_TYPEC_MANAGER_NOTIFIER_H__

#include <linux/muic/common/muic.h>
#include <linux/muic/common/muic_notifier.h>
#if IS_ENABLED(CONFIG_VBUS_NOTIFIER)
#include <linux/vbus_notifier.h>
#endif
#include <linux/usb/typec/common/pdic_notifier.h>

#define TYPEC_MANAGER_MAJ_VERSION 2
#define TYPEC_MANAGER_MIN_VERSION 1


typedef enum {

	MANAGER_NOTIFY_MUIC_NONE = 0,
	MANAGER_NOTIFY_MUIC_USB,
	MANAGER_NOTIFY_MUIC_OTG,
	MANAGER_NOTIFY_MUIC_CHARGER,
	MANAGER_NOTIFY_MUIC_TIMEOUT_OPEN_DEVICE,
	MANAGER_NOTIFY_MUIC_UART,


	MANAGER_NOTIFY_PDIC_INITIAL = 20,
	MANAGER_NOTIFY_PDIC_WACOM, 
	MANAGER_NOTIFY_PDIC_SENSORHUB,
	MANAGER_NOTIFY_PDIC_USBDP,
	MANAGER_NOTIFY_PDIC_DP,
	MANAGER_NOTIFY_PDIC_SUB_BATTERY,
	MANAGER_NOTIFY_PDIC_BATTERY,
	MANAGER_NOTIFY_PDIC_USB,
	MANAGER_NOTIFY_PDIC_MUIC, 
	MANAGER_NOTIFY_PDIC_DELAY_DONE,
} manager_notifier_device_t;

typedef enum {
	PD_USB_TYPE,
	PD_TA_TYPE,
	PD_NONE_TYPE,
} pd_usb_state_t;

typedef enum
{
	VBUS_NOTIFIER,
	PDIC_NOTIFIER,
	MUIC_NOTIFIER
}notifier_register;

typedef struct
{
	uint64_t src:4;
	uint64_t dest:4;
	uint64_t id:8;
	uint64_t sub1:16;
	uint64_t sub2:16;
	uint64_t sub3:16;
	void *pd;
} MANAGER_NOTI_TYPEDEF;

struct typec_manager_event_work
{
	struct work_struct typec_manager_work;
	MANAGER_NOTI_TYPEDEF event;
};

struct manager_dwork {
	struct delayed_work dwork;
	bool pending;
};

struct manager_dp {
	int is_support;
	int attach_state;
	int cable_type;
	int hpd_state;
	int is_connect;
	int hs_connect;
	int check_done;
};

struct manager_water {
	int detected;
	int detOnPowerOff;
	int wVbus_det;
	int report_type;
};

struct typec_manager_muic {
	int attach_state;
	int cable_type;
};

struct typec_manager_usb {
	uint dr;
	int enum_state;
	bool enable_state;
	int ufp_repeat_check;
};

typedef struct _manager_data_t
{
	struct blocking_notifier_head manager_muic_notifier;
	struct blocking_notifier_head manager_notifier;
	struct notifier_block pdic_nb;
	struct notifier_block muic_nb;
#if IS_ENABLED(CONFIG_VBUS_NOTIFIER)
	struct notifier_block vbus_nb;
#endif
#if defined(CONFIG_CABLE_TYPE_NOTIFIER)
	struct	notifier_block cable_type_nb;
#endif

	struct delayed_work manager_init_work;
	struct workqueue_struct *manager_noti_wq;
	struct workqueue_struct *manager_muic_noti_wq;
	struct manager_dwork usb_enum_check;
	struct manager_dwork usb_event_by_vbus;
#if IS_ENABLED(CONFIG_MUIC_SM5504_POGO)
	struct manager_dwork usb_event_by_pogo;
#endif

	struct mutex mo_lock;
	int vbus_state;
#if IS_ENABLED(CONFIG_MUIC_SM5504_POGO)
	int is_muic_pogo;
#endif
	int classified_cable_type;

	int pdic_attach_state;
	int pdic_rid_state;
	int alt_is_support;
	int usb_factory;

	unsigned long otg_stamp;
	int vbus_by_otg_detection;

	int pd_con_state;
	int svid_info;
	void *pd;

	char fac_control[16];

	struct typec_manager_usb usb;
	struct typec_manager_muic muic;
#ifdef CONFIG_USE_SECOND_MUIC
	struct typec_manager_muic second_muic;
#endif
	struct manager_water water;
	struct manager_dp dp;
	struct notifier_block manager_external_notifier_nb; 
	struct typec_manager_gadget_ops *gadget_ops;
}manager_data_t;

struct typec_manager_gadget_ops {
	void		*driver_data;
	int		(*get_cmply_link_state)(void *dev);
};

typedef union {
	struct {
		uint64_t src:4;
		uint64_t dest:4;
		uint64_t id:8;
		uint64_t sub1:16;
		uint64_t sub2:16;
		uint64_t sub3:16;
	};
	uint64_t noti_event;

} MANAGER_NOTI_TYPEDEF_REF;

#define PDIC_BATTERY	(1<<0)
#define PDIC_USB	(1<<1)
#define PDIC_DP		(1<<2)
#define PDIC_DELAY_DONE	(1<<3)


#define CANCEL_USB_DWORK 0
#define MAX_USB_DWORK_TIME 120000
#define MIN_USB_DWORK_TIME 2000
#ifdef CONFIG_USB_CONFIGFS_F_MBIM
#define BOOT_USB_DWORK_TIME 9000
#else
#define BOOT_USB_DWORK_TIME 12000
#endif


#define VBUS_USB_OFF_TIMEOUT 1000


#define OTG_VBUS_CHECK_TIME 300


#define NOTIFIER_REG_RETRY 2000

#define UFP_REPEAT_ERROR 3

#define MANAGER_NOTIFIER_BLOCK(name)	\
	struct notifier_block (name)

#define SET_MANAGER_NOTIFIER_BLOCK(nb, fn, dev) do {	\
		(nb)->notifier_call = (fn);		\
		(nb)->priority = (dev);			\
	} while (0)

#define DESTROY_MANAGER_NOTIFIER_BLOCK(nb)			\
		SET_MANAGER_NOTIFIER_BLOCK(nb, NULL, -1)


int manager_notifier_register(struct notifier_block *nb,
		notifier_fn_t notifier, manager_notifier_device_t listener);
int manager_notifier_unregister(struct notifier_block *nb);

void manager_notifier_usbdp_support(void);
void set_usb_enumeration_state(int state);
void set_usb_enable_state(void);
void probe_typec_manager_gadget_ops (struct typec_manager_gadget_ops *ops);
#endif 
