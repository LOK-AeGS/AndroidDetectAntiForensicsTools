

#ifndef __MUIC_H__
#define __MUIC_H__

#include <linux/power_supply.h>

#define MUIC_CORE "MUIC_CORE"

#define SIOP (1 << 0)
#define AFC_REQUEST_CHARGER SIOP
#define FLED (1 << 1)
#define AFC_REQUEST_MST (1 << 2)
#define AFC_REQUEST_MFC (1 << 3)
#define AFC_REQUEST_DETACH_CLEAR_BIT ((SIOP))


enum {
	MUIC_SUSPEND		= 0,
	MUIC_RESUME,
};


enum {
	MUIC_INTR_DETACH	= 0,
	MUIC_INTR_ATTACH
};


enum {
	MUIC_DOCK_DETACHED	= 0,
	MUIC_DOCK_DESKDOCK	= 1,
	MUIC_DOCK_CARDOCK	= 2,
	MUIC_DOCK_AUDIODOCK	= 101,
	MUIC_DOCK_SMARTDOCK	= 102,
	MUIC_DOCK_HMT		= 105,
	MUIC_DOCK_ABNORMAL	= 106,
	MUIC_DOCK_GAMEPAD	= 107,
	MUIC_DOCK_GAMEPAD_WITH_EARJACK	= 108,
};


enum {
	MUIC_PATH_USB_AP	= 0,
	MUIC_PATH_USB_CP,
	MUIC_PATH_UART_AP,
	MUIC_PATH_UART_CP,
	MUIC_PATH_OPEN,
	MUIC_PATH_AUDIO,
};

#ifdef CONFIG_MUIC_HV_FORCE_LIMIT
enum {
	HV_9V = 0,
	HV_5V,
};
#endif


enum {
	SWITCH_SEL_USB_MASK	= 0x1,
	SWITCH_SEL_UART_MASK	= 0x2,
	SWITCH_SEL_RUSTPROOF_MASK	= 0x8,
	SWITCH_SEL_AFC_DISABLE_MASK	= 0x100,
};


enum {
	CH_MODE_AFC_DISABLE_VAL = 0x31, 
};


typedef enum {
	ADC_GND			= 0x00,
	ADC_SEND_END		= 0x01, 
	ADC_REMOTE_S11		= 0x0c, 
	ADC_REMOTE_S12		= 0x0d, 
	ADC_RESERVED_VZW	= 0x0e, 
	ADC_INCOMPATIBLE_VZW	= 0x0f, 
	ADC_SMARTDOCK		= 0x10, 
	ADC_RDU_TA		= 0x10, 
	ADC_HMT			= 0x11, 
	ADC_AUDIODOCK		= 0x12, 
	ADC_USB_LANHUB		= 0x13, 
	ADC_CHARGING_CABLE	= 0x14,	
	ADC_UNIVERSAL_MMDOCK	= 0x15, 
	ADC_GAMEPAD		= 0x15, 
	ADC_UART_CABLE		= 0x16, 
	ADC_CEA936ATYPE1_CHG	= 0x17,	
	ADC_JIG_USB_OFF		= 0x18, 
	ADC_JIG_USB_ON		= 0x19, 
	ADC_DESKDOCK		= 0x1a, 
	ADC_CEA936ATYPE2_CHG	= 0x1b, 
	ADC_JIG_UART_OFF	= 0x1c, 
	ADC_JIG_UART_ON		= 0x1d, 
	ADC_AUDIOMODE_W_REMOTE	= 0x1e, 
	ADC_OPEN		= 0x1f,
	ADC_OPEN_219		= 0xfb, 
	ADC_219			= 0xfc, 

	ADC_UNDEFINED		= 0xfd, 
	ADC_DONTCARE		= 0xfe, 
	ADC_ERROR		= 0xff, 
} muic_adc_t;

#define IS_JIG_ADC(adc) \
	(((adc == ADC_JIG_USB_OFF) \
	|| (adc == ADC_JIG_USB_ON) \
	|| (adc == ADC_JIG_UART_OFF) \
	|| (adc == ADC_JIG_UART_ON)) ? 1 : 0)

#define ADC_WATER_THRESHOLD	ADC_OPEN


typedef enum {
	ATTACHED_DEV_NONE_MUIC = 0,

	ATTACHED_DEV_USB_MUIC,
	ATTACHED_DEV_CDP_MUIC,
	ATTACHED_DEV_OTG_MUIC,
	ATTACHED_DEV_TA_MUIC,
	ATTACHED_DEV_UNOFFICIAL_MUIC,
	ATTACHED_DEV_UNOFFICIAL_TA_MUIC,
	ATTACHED_DEV_UNOFFICIAL_ID_MUIC,
	ATTACHED_DEV_UNOFFICIAL_ID_TA_MUIC,
	ATTACHED_DEV_UNOFFICIAL_ID_ANY_MUIC,
	ATTACHED_DEV_UNOFFICIAL_ID_USB_MUIC,

	ATTACHED_DEV_UNOFFICIAL_ID_CDP_MUIC = 11,
	ATTACHED_DEV_UNDEFINED_CHARGING_MUIC,
	ATTACHED_DEV_DESKDOCK_MUIC,
	ATTACHED_DEV_UNKNOWN_VB_MUIC,
	ATTACHED_DEV_DESKDOCK_VB_MUIC,
	ATTACHED_DEV_CARDOCK_MUIC,
	ATTACHED_DEV_JIG_UART_OFF_MUIC,
	ATTACHED_DEV_JIG_UART_OFF_VB_MUIC,	
	ATTACHED_DEV_JIG_UART_OFF_VB_OTG_MUIC,	
	ATTACHED_DEV_JIG_UART_OFF_VB_FG_MUIC,	

	ATTACHED_DEV_JIG_UART_ON_MUIC = 21,
	ATTACHED_DEV_JIG_UART_ON_VB_MUIC,	
	ATTACHED_DEV_JIG_USB_OFF_MUIC,
	ATTACHED_DEV_JIG_USB_ON_MUIC,
	ATTACHED_DEV_SMARTDOCK_MUIC,
	ATTACHED_DEV_SMARTDOCK_VB_MUIC,
	ATTACHED_DEV_SMARTDOCK_TA_MUIC,
	ATTACHED_DEV_SMARTDOCK_USB_MUIC,
	ATTACHED_DEV_UNIVERSAL_MMDOCK_MUIC,
	ATTACHED_DEV_AUDIODOCK_MUIC,

	ATTACHED_DEV_MHL_MUIC = 31,
	ATTACHED_DEV_CHARGING_CABLE_MUIC,
	ATTACHED_DEV_AFC_CHARGER_PREPARE_MUIC,
	ATTACHED_DEV_AFC_CHARGER_PREPARE_DUPLI_MUIC,
	ATTACHED_DEV_AFC_CHARGER_5V_MUIC,
	ATTACHED_DEV_AFC_CHARGER_5V_DUPLI_MUIC,
	ATTACHED_DEV_AFC_CHARGER_9V_MUIC,
	ATTACHED_DEV_AFC_CHARGER_9V_DUPLI_MUIC,
	ATTACHED_DEV_AFC_CHARGER_12V_MUIC,
	ATTACHED_DEV_AFC_CHARGER_12V_DUPLI_MUIC,

	ATTACHED_DEV_AFC_CHARGER_ERR_V_MUIC = 41,
	ATTACHED_DEV_AFC_CHARGER_ERR_V_DUPLI_MUIC,
	ATTACHED_DEV_AFC_CHARGER_DISABLED_MUIC,
	ATTACHED_DEV_QC_CHARGER_PREPARE_MUIC,
	ATTACHED_DEV_QC_CHARGER_5V_MUIC,
	ATTACHED_DEV_QC_CHARGER_ERR_V_MUIC,
	ATTACHED_DEV_QC_CHARGER_9V_MUIC,
	ATTACHED_DEV_HV_ID_ERR_UNDEFINED_MUIC,
	ATTACHED_DEV_HV_ID_ERR_UNSUPPORTED_MUIC,
	ATTACHED_DEV_HV_ID_ERR_SUPPORTED_MUIC,

	ATTACHED_DEV_HMT_MUIC = 51,
	ATTACHED_DEV_VZW_ACC_MUIC,
	ATTACHED_DEV_VZW_INCOMPATIBLE_MUIC,
	ATTACHED_DEV_USB_LANHUB_MUIC,
	ATTACHED_DEV_TYPE1_CHG_MUIC,
	ATTACHED_DEV_TYPE2_CHG_MUIC,
	ATTACHED_DEV_TYPE3_MUIC,
	ATTACHED_DEV_TYPE3_MUIC_TA,
	ATTACHED_DEV_TYPE3_ADAPTER_MUIC,
	ATTACHED_DEV_TYPE3_CHARGER_MUIC,

	ATTACHED_DEV_NONE_TYPE3_MUIC = 61,
	ATTACHED_DEV_UNSUPPORTED_ID_MUIC,
	ATTACHED_DEV_UNSUPPORTED_ID_VB_MUIC,
	ATTACHED_DEV_TIMEOUT_OPEN_MUIC,
	ATTACHED_DEV_WIRELESS_PAD_MUIC,
	ATTACHED_DEV_CARKIT_MUIC,
	ATTACHED_DEV_POWERPACK_MUIC,
	ATTACHED_DEV_UNDEFINED_RANGE_MUIC,
	ATTACHED_DEV_HICCUP_MUIC,
	ATTACHED_DEV_CHK_WATER_REQ,

	ATTACHED_DEV_CHK_WATER_DRY_REQ = 71,
	ATTACHED_DEV_GAMEPAD_MUIC,
	ATTACHED_DEV_CHECK_OCP,
	ATTACHED_DEV_RDU_TA_MUIC,
	ATTACHED_DEV_FACTORY_UART_MUIC,
	ATTACHED_DEV_POGO_DOCK_MUIC,
	ATTACHED_DEV_POGO_DOCK_5V_MUIC,
	ATTACHED_DEV_POGO_DOCK_9V_MUIC,
	ATTACHED_DEV_ABNORMAL_OTG_MUIC,
	ATTACHED_DEV_RETRY_TIMEOUT_OPEN_MUIC,

	ATTACHED_DEV_RETRY_AFC_CHARGER_5V_MUIC = 81,
	ATTACHED_DEV_RETRY_AFC_CHARGER_9V_MUIC,
	ATTACHED_DEV_UNKNOWN_MUIC,
	ATTACHED_DEV_LO_TA_MUIC,

	ATTACHED_DEV_NUM,
} muic_attached_dev_t;

#ifdef CONFIG_MUIC_HV_FORCE_LIMIT

typedef enum {
	SILENT_CHG_DONE = 0,
	SILENT_CHG_CHANGING = 1,

	SILENT_CHG_NUM,
} muic_silent_change_state_t;
#endif

#if defined(CONFIG_MUIC_HV)

typedef enum {
	HV_STATE_INVALID = -1,
	HV_STATE_IDLE = 0,
	HV_STATE_DCP_CHARGER = 1,
	HV_STATE_FAST_CHARGE_ADAPTOR = 2,
	HV_STATE_FAST_CHARGE_COMMUNICATION = 3,
	HV_STATE_AFC_5V_CHARGER = 4,
	HV_STATE_AFC_9V_CHARGER = 5,
	HV_STATE_QC_CHARGER = 6,
	HV_STATE_QC_5V_CHARGER = 7,
	HV_STATE_QC_9V_CHARGER = 8,
	HV_STATE_MAX_NUM = 9,
} muic_hv_state_t;

typedef enum {
	HV_TRANS_INVALID = -1,
	HV_TRANS_MUIC_DETACH = 0,
	HV_TRANS_DCP_DETECTED = 1,
	HV_TRANS_NO_RESPONSE = 2,
	HV_TRANS_VDNMON_LOW = 3,
	HV_TRANS_FAST_CHARGE_PING_RESPONSE = 4,
	HV_TRANS_VBUS_BOOST = 5,
	HV_TRANS_VBUS_REDUCE = 6,
	HV_TRANS_FAST_CHARGE_REOPEN = 7,
	HV_TRANS_MAX_NUM = 8,
} muic_hv_transaction_t;
#endif


struct muic_platform_data {
	void *drv_data;
	void *muic_if;
	int irq_gpio;
	bool suspended;
	bool need_to_noti;

	int switch_sel;

	
	int usb_path;
	int uart_path;

	int gpio_uart_sel;
	int gpio_usb_sel;

	bool rustproof_on;
	bool afc_disable;
	bool is_new_factory;
	bool dcd_timeout;
	int afc_disabled_updated;

#ifdef CONFIG_MUIC_HV_FORCE_LIMIT
	int hv_sel;
	int silent_chg_change_state;
#endif

#if IS_ENABLED(CONFIG_MUIC_SYSFS)
	struct device *switch_device;
	struct mutex sysfs_mutex;
#endif

#if defined(CONFIG_MUIC_HV)
	muic_hv_state_t hv_state;
#endif

	
	muic_attached_dev_t	attached_dev;

	bool is_usb_ready;
	bool is_factory_start;
	bool is_rustproof;
	bool is_otg_test;

	bool is_jig_on;
	bool jig_disable;
	bool is_factory_uart;

	int vbvolt;
	int adc;

	
	void (*init_switch_dev_cb) (void);
	void (*cleanup_switch_dev_cb) (void);

	void (*jig_uart_cb)(int jig_state);

	
	int (*init_gpio_cb) (void *, int switch_sel);
	int (*set_gpio_usb_sel) (int usb_path);
	int (*set_gpio_uart_sel) (int uart_path);
	int (*set_safeout) (int safeout_path);

	
	void (*set_path_switch_suspend) (struct device *dev);
	void (*set_path_switch_resume) (struct device *dev);

	
	void (*init_cable_data_collect_cb)(void);

	
	int (*muic_hv_charger_init_cb)(void);

	
	int (*muic_set_hiccup_mode_cb)(int on_off);
};

#define MUIC_PDATA_VOID_FUNC(func, param) \
{\
	if (func)	\
		func(param);	\
	else	\
		pr_err("[muic_core] func not defined %s\n", __func__);	\
}

#define MUIC_PDATA_FUNC(func, param, ret) \
{\
	*ret = -1;	\
	if (func)	\
		*ret = func(param);	\
	else	\
		pr_err("[muic_core] func not defined %s\n", __func__);	\
}

#define MUIC_PDATA_FUNC_MULTI_PARAM(func, param1, param2, ret) \
{					\
	*ret = -1;	\
	if (func)	\
		*ret = func(param1, param2);	\
	else	\
		pr_err("[muic_core] func not defined %s\n", __func__);	\
}

#define MUIC_IS_ATTACHED(dev) \
	(((dev != ATTACHED_DEV_UNKNOWN_MUIC) && (dev != ATTACHED_DEV_NONE_MUIC)) ? (1) : (0))

enum muic_param_en {
	MUIC_DISABLE = 0,
	MUIC_ENABLE
};


#define ENUM_STR(x, r) { case x: r = #x; break; }

#define REQUEST_IRQ(_irq, _dev_id, _name, _func)			\
do {									\
	ret = request_threaded_irq(_irq, NULL, _func,			\
				0, _name, _dev_id);			\
	if (ret < 0) {							\
		pr_err("%s:%s Failed to request IRQ #%d: %d\n",		\
				MUIC_DEV_NAME, __func__, _irq, ret);	\
		_irq = 0;						\
	}								\
} while (0)

#define FREE_IRQ(_irq, _dev_id, _name)					\
do {									\
	if (_irq) {							\
		free_irq(_irq, _dev_id);				\
		pr_info("%s:%s IRQ(%d):%s free done\n", MUIC_DEV_NAME,	\
				__func__, _irq, _name);			\
	}								\
} while (0)

#define MASK_1b (1)
#define MASK_2b (0x3)
#define MASK_3b (0x7)
#define MASK_4b (0xf)
#define MASK_5b (0x1f)
#define MASK_6b (0x3f)
#define MASK_7b (0x7f)
#define MASK_8b (0xff)

#if defined(CONFIG_MUIC_HV)
#define IS_VCHGIN_9V(x) ((8000 <= x) && (x <= 10300))
#define IS_VCHGIN_5V(x) ((4000 <= x) && (x <= 6000))

#define AFC_MRXRDY_CNT_LIMIT (3)
#define AFC_MPING_RETRY_CNT_LIMIT (20)
#define AFC_QC_RETRY_CNT_LIMIT (3)
#define VCHGIN_CHECK_CNT_LIMIT (3)
#define AFC_QC_RETRY_WAIT_CNT_LIMIT (3)

typedef enum {
	AFC_IRQ_VDNMON = 1,
	AFC_IRQ_DNRES,
	AFC_IRQ_MPNACK,
	AFC_IRQ_MRXBUFOW,
	AFC_IRQ_MRXTRF,
	AFC_IRQ_MRXPERR,
	AFC_IRQ_MRXRDY = 7,
} afc_int_t;

typedef enum {
	AFC_NOT_MASK = 0,
	AFC_MASK = 1,
} int_mask_t;

typedef enum {
	QC_PROTOCOL,
	AFC_PROTOCOL,
} protocol_sw_t;

typedef enum {
	QC_UNKHOWN,
	QC_5V,
	QC_9V,
	QC_12V,
} qc_2p0_type_t;

typedef enum {
	VDNMON_LOW		= 0x00,
	VDNMON_HIGH		= (0x1 << 1),

	VDNMON_DONTCARE		= 0xff,
} vdnmon_t;


typedef enum {
	MUIC_AFC_IRQ_VDNMON = 0,
	MUIC_AFC_IRQ_MRXRDY,
	MUIC_AFC_IRQ_VBADC,
	MUIC_AFC_IRQ_MPNACK,
	MUIC_AFC_IRQ_DONTCARE = 0xff,
} muic_afc_irq_t;

typedef enum tx_data{
    MUIC_HV_5V = 0,
    MUIC_HV_9V,
} muic_afc_txdata_t;
#endif

enum power_supply_lsi_property {
#if IS_MODULE(CONFIG_MFD_S2MU106) || defined(CONFIG_BATTERY_GKI)
	POWER_SUPPLY_LSI_PROP_MIN = 10000,
#else
	POWER_SUPPLY_LSI_PROP_MIN = POWER_SUPPLY_EXT_PROP_MAX + 1,
#endif
	POWER_SUPPLY_LSI_PROP_POWER_ROLE,
	POWER_SUPPLY_LSI_PROP_WATER_CHECK,
	POWER_SUPPLY_LSI_PROP_DRY_CHECK,
	POWER_SUPPLY_LSI_PROP_WATER_CHECKDONE,
	POWER_SUPPLY_LSI_PROP_PM_IRQ_TIME,
	POWER_SUPPLY_LSI_PROP_USBPD_OPMODE,
	POWER_SUPPLY_LSI_PROP_USBPD_RPCUR,
	POWER_SUPPLY_LSI_PROP_USBPD_ATTACHED,
	POWER_SUPPLY_LSI_PROP_USBPD_SOURCE_ATTACH,
	POWER_SUPPLY_LSI_PROP_WATER_GET_POWER_ROLE,
	POWER_SUPPLY_LSI_PROP_GET_CC_STATE,
	POWER_SUPPLY_LSI_PROP_WATER_STATUS,
	POWER_SUPPLY_LSI_PROP_PD_PSY,
	POWER_SUPPLY_LSI_PROP_HICCUP_MODE,
	POWER_SUPPLY_LSI_PROP_FAC_WATER_CHECK,
	POWER_SUPPLY_LSI_PROP_SET_TH,
	POWER_SUPPLY_LSI_PROP_PM_VCHGIN,
	POWER_SUPPLY_LSI_PROP_2LV_3LV_CHG_MODE,
	POWER_SUPPLY_LSI_PROP_USBPD_RESET,
	POWER_SUPPLY_LSI_PROP_PD_SUPPORT,
	POWER_SUPPLY_LSI_PROP_VCHGIN,
	POWER_SUPPLY_LSI_PROP_VWCIN,
	POWER_SUPPLY_LSI_PROP_VBYP,
	POWER_SUPPLY_LSI_PROP_VSYS,
	POWER_SUPPLY_LSI_PROP_VBAT,
	POWER_SUPPLY_LSI_PROP_VGPADC,
	POWER_SUPPLY_LSI_PROP_VCC1,
	POWER_SUPPLY_LSI_PROP_VCC2,
	POWER_SUPPLY_LSI_PROP_ICHGIN,
	POWER_SUPPLY_LSI_PROP_IWCIN,
	POWER_SUPPLY_LSI_PROP_IOTG,
	POWER_SUPPLY_LSI_PROP_ITX,
	POWER_SUPPLY_LSI_PROP_CO_ENABLE,
	POWER_SUPPLY_LSI_PROP_RR_ENABLE,
	POWER_SUPPLY_LSI_PROP_PM_FACTORY,
	POWER_SUPPLY_LSI_PROP_PCP_CLK,
#if IS_ENABLED(CONFIG_MFD_S2MU106) || defined(CONFIG_BATTERY_GKI)
	POWER_SUPPLY_LSI_PROP_MAX,
#endif
};

#ifdef CONFIG_IFCONN_NOTIFIER
#define MUIC_SEND_NOTI_ATTACH(dev) \
{	\
	int ret;	\
	struct ifconn_notifier_template template;	\
	template.cable_type = dev;	\
	ret = ifconn_notifier_notify( \
					IFCONN_NOTIFY_MUIC,	\
					IFCONN_NOTIFY_MANAGER,	\
					IFCONN_NOTIFY_ID_ATTACH,	\
					IFCONN_NOTIFY_EVENT_ATTACH,	\
					&template);	\
	if (ret < 0) {	\
		pr_err("%s: Fail to send noti\n", \
				__func__);	\
	}	\
}

#define MUIC_SEND_NOTI_TO_PDIC_ATTACH(dev) \
{	\
	int ret;	\
	struct ifconn_notifier_template template;	\
	template.cable_type = dev;	\
	ret = ifconn_notifier_notify( \
					IFCONN_NOTIFY_MUIC,	\
					IFCONN_NOTIFY_PDIC,	\
					IFCONN_NOTIFY_ID_ATTACH,	\
					IFCONN_NOTIFY_EVENT_ATTACH,	\
					&template);	\
	if (ret < 0) {	\
		pr_err("%s: Fail to send noti\n", \
				__func__);	\
	}	\
}

#define MUIC_SEND_NOTI_TO_PDIC_DETACH(dev) \
{	\
	int ret;	\
	struct ifconn_notifier_template template;	\
	template.cable_type = dev;	\
	ret = ifconn_notifier_notify( \
					IFCONN_NOTIFY_MUIC,	\
					IFCONN_NOTIFY_PDIC,	\
					IFCONN_NOTIFY_ID_DETACH,	\
					IFCONN_NOTIFY_EVENT_DETACH,	\
					&template);	\
	if (ret < 0) {	\
		pr_err("%s: Fail to send noti\n", \
				__func__);	\
	}	\
}

#define MUIC_SEND_NOTI_DETACH(dev) \
{	\
	int ret;	\
	struct ifconn_notifier_template template;	\
	template.cable_type = dev;	\
	ret = ifconn_notifier_notify( \
					IFCONN_NOTIFY_MUIC,	\
					IFCONN_NOTIFY_MANAGER,	\
					IFCONN_NOTIFY_ID_DETACH,	\
					IFCONN_NOTIFY_EVENT_DETACH,	\
					&template);	\
	if (ret < 0) {	\
		pr_err("%s: Fail to send noti\n", \
				__func__);	\
	}	\
}
#else
#define MUIC_SEND_NOTI_ATTACH(dev)	\
		muic_notifier_attach_attached_dev(dev)
#define MUIC_SEND_NOTI_DETACH(dev) \
		muic_notifier_detach_attached_dev(dev)
#define MUIC_SEND_NOTI_TO_PDIC_ATTACH(dev) \
		muic_pdic_notifier_attach_attached_dev(dev)
#define MUIC_SEND_NOTI_TO_PDIC_DETACH(dev) \
		muic_pdic_notifier_detach_attached_dev(dev)
#endif

#if IS_ENABLED(CONFIG_MUIC_NOTIFIER)
extern int muic_set_hiccup_mode(int on_off);
extern int muic_hv_charger_init(void);
#else
static inline int muic_hv_charger_init(void) {return 0; }
#endif

int get_switch_sel(void);
int get_afc_mode(void);
void muic_set_hmt_status(int status);
int muic_core_handle_attach(struct muic_platform_data *muic_pdata,
			muic_attached_dev_t new_dev, int adc, u8 vbvolt);
int muic_core_handle_detach(struct muic_platform_data *muic_pdata);
extern bool muic_core_get_pdic_cable_state(struct muic_platform_data *muic_pdata);
extern struct muic_platform_data *muic_core_init(void *drv_data);
extern void muic_core_exit(struct muic_platform_data *muic_pdata);
extern void muic_disable_otg_detect(void);
#if defined(CONFIG_MUIC_HV)
int muic_core_hv_state_manager(struct muic_platform_data *muic_pdata,
		muic_hv_transaction_t trans);
void muic_core_hv_init(struct muic_platform_data *muic_pdata);
bool muic_core_hv_is_hv_dev(struct muic_platform_data *muic_pdata);
#endif
#if !defined(CONFIG_DISCRETE_CHARGER)
extern int muic_afc_set_voltage(int voltage);
extern int muic_afc_request_voltage(int cause, int voltage);
extern int muic_afc_request_cause_clear(void);
extern int muic_afc_get_request_cause(void);
extern bool muic_is_enable_afc_request(void);
#endif
#endif 

