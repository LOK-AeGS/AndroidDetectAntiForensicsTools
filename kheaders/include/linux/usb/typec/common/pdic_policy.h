

#ifndef __LINUX_PDIC_POLICY_H__
#define __LINUX_PDIC_POLICY_H__

#include <linux/usb/typec.h>
#include <linux/usb/typec/common/pdic_notifier.h>

enum pdic_message {
	MSG_INITIAL,
	MSG_SRC,			
	MSG_SNK,
	MSG_VBUSON,
	MSG_VBUSOFF,
	MSG_RP56K,
	MSG_RP22K,
	MSG_RP10K,
	MSG_UFP,
	MSG_DFP,
	MSG_AUDIO,
	MSG_DEBUG,
	MSG_CC1,
	MSG_CC2,
	MSG_NOCC_WAKE,
	MSG_CC_SHORT,
	MSG_SBU_SHORT,
	MSG_WATER,
	MSG_DRY,
	MSG_ROPEN,
	MSG_R301K,
	MSG_R255K,
	MSG_R523K,
	MSG_R619K,
	MSG_UOPEN,
	MSG_U301K,
	MSG_U255K,
	MSG_U523K,
	MSG_U619K,
	MSG_EX_CNT,
	MSG_KILLER,
	MSG_DCOVER,
	MSG_DP_CONN,
	MSG_DP_DISCONN,
	MSG_DP_LINK_CONF,
	MSG_DP_HPD,
	MSG_SELECT_PDO,
	MSG_CURRENT_PDO,
	MSG_PD_POWER_STATUS,
	MSG_CCOFF,
	MSG_MAX,
};

enum pdic_status {
	PP_STATUS_CC_ON,
	PP_STATUS_CC_STATE,
	PP_STATUS_CC_DIRECTION,
	PP_STATUS_CC_RP_CURRENT,
	PP_STATUS_POWER_ROLE,
	PP_STATUS_DATA_ROLE,
	PP_STATUS_VBUS_BOOSTER,
	PP_STATUS_RID,
	PP_STATUS_UID,
	PP_STATUS_WATER,
	PP_STATUS_CC_SHORT,
	PP_STATUS_SBU_SHORT,
	PP_STATUS_EXPLICIT_CONTRACT,
};

struct pdic_alt_info {
	u16 vendor_id;
	u16 product_id;
	u16 bcd_device;
	u16 svid[12];
	int dp_device;
	int dp_pin_assignment;
	int dp_selected_pin;
	int hpd_state;
	int hpd_irq;
};

struct pdic_ops {
	int (*dr_set)(void *data, enum typec_data_role role);
	int (*pr_set)(void *data, enum typec_role role);
	int (*vconn_set)(void *data, enum typec_role role);
	int (*port_type_set)(void *data, enum typec_port_type type);
	int (*get_alt_info)(void *data, struct pdic_alt_info *alt_info);
	void (*set_alt_mode)(int);
	void (*dp_info_clear)(void *data);
};

struct pp_ic_data {
	struct device *dev;
	const struct pdic_ops *p_ops;
	struct pdic_notifier_struct *pd_noti;
	int support_pd;
	int vbus_dischar_gpio;
	void *pp_data;
	void *drv_data;
	int typec_implemented;
};

#ifdef CONFIG_PDIC_POLICY
extern int pdic_policy_update_pdo_list(void *data, int max_v, int min_v,
		int max_icl, int cnt, int num);
extern int pdic_policy_send_msg(void *data, int msg, int param1, int param2);
extern void *pdic_policy_init(struct pp_ic_data *ic_data);
extern void pdic_policy_deinit(struct pp_ic_data *ic_data);
#else
static inline int pdic_policy_update_pdo_list(void *data, int max_v, int min_v,
		int max_icl, int cnt, int num) {return 0; }
static inline int pdic_policy_send_msg(void *data, int msg,
		int param1, int param2) {return 0; }
static inline void *pdic_policy_init(struct pp_ic_data *ic_data) {return NULL; }
static inline void pdic_policy_deinit(struct pp_ic_data *ic_data) {}
#endif
#endif 
