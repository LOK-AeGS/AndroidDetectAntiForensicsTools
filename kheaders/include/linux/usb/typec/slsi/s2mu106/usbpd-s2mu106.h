
#if IS_ENABLED(CONFIG_PDIC_NOTIFIER)
#include <linux/usb/typec/common/pdic_notifier.h>
#include <linux/usb/typec/common/pdic_core.h>
#endif
#include <linux/usb/typec/slsi/common/s2m_pdic_notifier.h>
#include <linux/usb/typec/slsi/common/usbpd_msg.h>
#include <linux/usb/typec/slsi/common/usbpd.h>
#if IS_ENABLED(CONFIG_TYPEC)
#include <linux/usb/typec.h>
#endif
#include <linux/power_supply.h>
#include <linux/pm_wakeup.h>
#if defined(CONFIG_S2MU106_PDIC_TRY_SNK)
#include <linux/alarmtimer.h>
#endif

#ifndef __USBPD_S2MU106_H__
#define __USBPD_S2MU106_H__

#define USBPD_S2MU106_NAME    "usbpd-s2mu106"


#define S2MU106_MAX_NUM_MSG_OBJ (7)

#define S2MU106_MAX_NUM_INT_STATUS (7)

#define S2MU106_REG_TYPEC_DIS (1 << 2)

#define TA_WATER_CHK_DURATION_MS    5000


#define S2MU106_ROLE_SWAP_TIME_MS		(1350)
#define S2MU106_HARD_RESET_DELAY_MS		(300)
#define S2MU106_WAIT_RD_DETACH_DELAY_MS		(200)
#define S2MU106_WAIT_ATTACH_DELAY_MS		(30)

#define S2MU106_WATER_CHK_INTERVAL_TIME        (300)
#define S2MU106_ATTACH_STATE_CHECK_TIME        (1000)

#define S2MU106_WATER_THRESHOLD_MV (pdic_data->water_th)
#define S2MU106_WATER_POST (pdic_data->water_post)
#define S2MU106_DRY_THRESHOLD_MV (pdic_data->dry_th)
#define S2MU106_DRY_THRESHOLD_POST_MV (pdic_data->dry_th_post)
#define S2MU106_WATER_DELAY_MS (pdic_data->water_delay)
#define S2MU106_WATER_THRESHOLD_RA_MV (pdic_data->water_th_ra)

#define S2MU106_WATER_GPADC_SHORT (pdic_data->water_gpadc_short)
#define PD_GPADC_SHORT(x) ((x) >= S2MU106_WATER_GPADC_SHORT)

#define WATER_CHK_RETRY_CNT    2

#define IS_CC_OR_UNDER_RA(cc1, cc2)\
	((cc1 <= S2MU106_WATER_THRESHOLD_RA_MV) || (cc2 <= S2MU106_WATER_THRESHOLD_RA_MV))
#define IS_CC_AND_UNDER_WATER(cc1, cc2)\
	((cc1 <= S2MU106_WATER_THRESHOLD_MV) && (cc2 <= S2MU106_WATER_THRESHOLD_MV))

#define IS_CC_WATER(cc1, cc2)\
	((cc1 <= S2MU106_WATER_THRESHOLD_MV) && (cc2 >= (cc1*S2MU106_WATER_POST/10)))
#define IS_CC_DRY(pd1, pd2)    \
	((pd1 > S2MU106_DRY_THRESHOLD_MV) && (pd2 > S2MU106_DRY_THRESHOLD_MV))
#define IS_CC_DRY_POST(pd1, pd2)    \
	((pd1 < S2MU106_DRY_THRESHOLD_POST_MV) && (pd2 < S2MU106_DRY_THRESHOLD_POST_MV))




#define S2MU106_RESET_REG_00        (0x00)


#define S2MU106_REG_BMC_RX_TF_TRIM_SHIFT (0)
#define S2MU106_REG_VBUS_WAKEUP_DIS_SHIFT (1)
#define S2MU106_REG_COMP_HYS_TRIM_SHIFT (2)

#define S2MU106_REG_BMC_RX_TF_TRIM  (0x1 << S2MU106_REG_BMC_RX_TF_TRIM) 
#define S2MU106_REG_VBUS_WAKEUP_DIS  (0x1 << S2MU106_REG_VBUS_WAKEUP_DIS_SHIFT) 
#define S2MU106_REG_COMP_HYS_TRIM  (0x3 << S2MU106_REG_VBUS_WAKEUP_DIS_SHIFT) 



#define S2MU106_REG_LP_LDO_D_SHIFT (0)
#define S2MU106_REG_LPM_EN_SHIFT (1)
#define S2MU106_REG_LP_LDO_D \
	(1 << S2MU106_REG_LP_LDO_D_SHIFT) 
#define S2MU106_REG_LPM_EN \
	(0x1 << S2MU106_REG_LPM_EN_SHIFT) 


#define S2MU106_REG_PD_OCP_SHIFT (4)
#define S2MU106_REG_PD_OCP_MASK  (0xf << S2MU106_REG_PD_OCP_SHIFT)

#define S2MU106_REG_IFG_SHIFT (4)
#define S2MU106_REG_IFG_MASK (0xf << S2MU106_REG_IFG_SHIFT) 


#define S2MU106_REG_OTP_PD_PUB_SHIFT    (7)
#define S2MU106_REG_PD_PU_LPM_CTRL_DIS_SHIFT    (2)
#define S2MU106_REG_PD2_RS_SW_ON_SHIFT    (1)
#define S2MU106_REG_PD1_RS_SW_ON_SHIFT    (0)

#define S2MU106_REG_OTP_PD_PUB_MASK \
	(0x1 << S2MU106_REG_OTP_PD_PUB_SHIFT)
#define S2MU106_REG_PD_PU_LPM_CTRL_DIS_MASK \
	(0x1 << S2MU106_REG_PD_PU_LPM_CTRL_DIS_SHIFT)
#define S2MU106_REG_PD2_RS_SW_ON_MASK    (0x1 << S2MU106_REG_PD2_RS_SW_ON_SHIFT)
#define S2MU106_REG_PD1_RS_SW_ON_MASK    (0x1 << S2MU106_REG_PD1_RS_SW_ON_SHIFT)


#define S2MU106_REG_LPMPUI_SEL_SHIFT        (2)
#define S2MU106_REG_LPMPUI_SEL_MASK            (0x3 << S2MU106_REG_LPMPUI_SEL_SHIFT)
#define S2MU106_REG_LPMPUI_SEL_250NA_MASK    (0x0 << S2MU106_REG_LPMPUI_SEL_SHIFT)
#define S2MU106_REG_LPMPUI_SEL_500NA_MASK    (0x1 << S2MU106_REG_LPMPUI_SEL_SHIFT)
#define S2MU106_REG_LPMPUI_SEL_1UA_MASK        (0x2 << S2MU106_REG_LPMPUI_SEL_SHIFT)
#define S2MU106_REG_LPMPUI_SEL_2UA_MASK        (0x3 << S2MU106_REG_LPMPUI_SEL_SHIFT)


#define S2MU106_REG_OVP_ON_SHIFT        (7)
#define S2MU106_REG_OVP_ON            (0x1 << S2MU106_REG_OVP_ON_SHIFT)


#define S2MU106_REG_PLUG_CTRL_MODE_SHIFT    (0)
#define S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT    (4)
#define S2MU106_REG_PLUG_CTRL_DETECT_BAT_DISABLE_SHIFT    (6)
#define S2MU106_REG_PLUG_CTRL_DETECT_OCP_DISABLE_SHIFT    (7)
#define S2MU106_REG_PLUG_CTRL_DFP \
	(0x1 << S2MU106_REG_PLUG_CTRL_MODE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_UFP \
	(0x2 << S2MU106_REG_PLUG_CTRL_MODE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_DRP \
	(0x3 << S2MU106_REG_PLUG_CTRL_MODE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RP0 \
	(0x0 << S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RP80 \
	(0x1 << S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RP180 \
	(0x2 << S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RP330 \
	(0x3 << S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_MODE_MASK    \
	(0x3 << S2MU106_REG_PLUG_CTRL_MODE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RP_SEL_MASK \
	(0x3 << S2MU106_REG_PLUG_CTRL_RP_SEL_SHIFT)
#define S2MU106_REG_PLUG_CTRL_DETECT_BAT_DISABLE_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_DETECT_BAT_DISABLE_SHIFT)
#define S2MU106_REG_PLUG_CTRL_DETECT_OCP_DISABLE_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_DETECT_OCP_DISABLE_SHIFT)


#define S2MU106_REG_MSG_DATA_ROLE_SHIFT        (5)
#define S2MU106_REG_MSG_POWER_ROLE_SHIFT    (6)
#define S2MU106_REG_MSG_DATA_ROLE_UFP \
	(0x0 << S2MU106_REG_MSG_DATA_ROLE_SHIFT) 
#define S2MU106_REG_MSG_DATA_ROLE_DFP \
	(0x1 << S2MU106_REG_MSG_DATA_ROLE_SHIFT) 
#define S2MU106_REG_MSG_DATA_ROLE_MASK \
	(0x1 << S2MU106_REG_MSG_DATA_ROLE_SHIFT) 
#define S2MU106_REG_MSG_POWER_ROLE_SINK \
	(0x0 << S2MU106_REG_MSG_POWER_ROLE_SHIFT) 
#define S2MU106_REG_MSG_POWER_ROLE_SOURCE \
	(0x1 << S2MU106_REG_MSG_POWER_ROLE_SHIFT) 
#define S2MU106_REG_MSG_POWER_ROLE_MASK \
	(0x1 << S2MU106_REG_MSG_POWER_ROLE_SHIFT) 

#define S2MU106_REG_RD_OR_VBUS_MUX_SEL_SHIFT    (4)
#define S2MU106_REG_RD_OR_VBUS_MUX_SEL    \
	(0x1 << S2MU106_REG_RD_OR_VBUS_MUX_SEL_SHIFT)


#define S2MU106_REG_PLUG_CTRL_SET_MON_RD     (0x1 << 3)


#define S2MU106_REG_PLUG_CTRL_PD_HOLD_BIT     (0x1)
#define S2MU106_REG_PLUG_CTRL_SUPPORT_ACC     (0x1 << 7)


#define S2MU106_REG_PLUG_CTRL_FSM_MANUAL_EN_SHIFT    (2)
#define S2MU106_REG_PLUG_CTRL_RpRd_PLUG_SEL_SHIFT    (3)
#define S2MU106_REG_PLUG_CTRL_VCONN_MANUAL_EN_SHIFT    (4)
#define S2MU106_REG_PLUG_CTRL_RpRd_PD1_VCONN_SHIFT    (5)
#define S2MU106_REG_PLUG_CTRL_RpRd_PD2_VCONN_SHIFT    (6)
#define S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_SHIFT    (7)

#define S2MU106_REG_PLUG_CTRL_FSM_MANUAL_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_FSM_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PLUG_SEL_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_Rp_Source_Mode \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PLUG_SEL_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_Rd_Sink_Mode \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_VCONN_MANUAL_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_VCONN_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_PD1_VCONN \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PD1_VCONN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_PD2_VCONN \
	(0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PD2_VCONN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_RpRd_VCONN_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_VCONN_MANUAL_EN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PD1_VCONN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_RpRd_PD2_VCONN_SHIFT) 


#define S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN_SHIFT    (4)
#define S2MU106_REG_PLUG_CTRL_PD1_MANUAL_EN_SHIFT    (5)
#define S2MU106_REG_PLUG_CTRL_PD2_MANUAL_EN_SHIFT    (6)

#define S2MU106_REG_PLUG_CTRL_FSM_MANUAL_INPUT_MASK    (0xf)
#define S2MU106_REG_PLUG_CTRL_FSM_UNATTACHED_SNK        (0)
#define S2MU106_REG_PLUG_CTRL_FSM_ATTACHWAIT_SNK        (1)
#define S2MU106_REG_PLUG_CTRL_FSM_ATTACHED_SNK        (2)
#define S2MU106_REG_PLUG_CTRL_FSM_UNATTACHED_SRC        (4)
#define S2MU106_REG_PLUG_CTRL_FSM_ATTACHED_SRC        (6)
#define S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_PD1_MANUAL_ON \
	(0x1 << S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_PD1_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_PD2_MANUAL_ON \
	(0x1 << S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_PD2_MANUAL_EN_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_PD_MANUAL_MASK \
	(0x1 << S2MU106_REG_PLUG_CTRL_PD_MANUAL_EN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_PD1_MANUAL_EN_SHIFT | \
	0x1 << S2MU106_REG_PLUG_CTRL_PD2_MANUAL_EN_SHIFT) 


#define S2MU106_REG_PLUG_CTRL_SSM_DISABLE_SHIFT				(0)
#define S2MU106_REG_PLUG_CTRL_VDM_DISABLE_SHIFT				(1)
#define S2MU106_REG_PLUG_CTRL_OP_Mode_FORCE_EN_SHIFT		(2)
#define S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_MODE_SHIFT		(3)
#define S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_EN_SHIFT		(4)
#define S2MU106_REG_PLUG_CTRL_REG_UFP_ATTACH_OPT_EN_SHIFT	(5)
#define S2MU106_REG_PLUG_CTRL_ECO_SRC_CAP_RDY_SHIFT			(6)
#define S2MU106_REG_PLUG_CTRL_PD_RST_OPTION_SHIFT			(7)

#define S2MU106_REG_PLUG_CTRL_SSM_DISABLE \
	(0x1 << S2MU106_REG_PLUG_CTRL_SSM_DISABLE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_VDM_DISABLE \
	(0x1 << S2MU106_REG_PLUG_CTRL_VDM_DISABLE_SHIFT) 
#define S2MU106_REG_PLUG_CTRL_OP_Mode_FORCE_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_OP_Mode_FORCE_EN_SHIFT)	
#define S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_MODE \
	(0x1 << S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_MODE_SHIFT) 

#define S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_VBUS_IND_FORCE_EN_SHIFT)	
#define S2MU106_REG_PLUG_CTRL_REG_UFP_ATTACH_OPT_EN \
	(0x1 << S2MU106_REG_PLUG_CTRL_REG_UFP_ATTACH_OPT_EN_SHIFT)	
#define S2MU106_REG_PLUG_CTRL_ECO_SRC_CAP_RDY \
	(0x1 << S2MU106_REG_PLUG_CTRL_ECO_SRC_CAP_RDY_SHIFT)	
#define S2MU106_REG_PLUG_CTRL_PD_RST_OPTION \
	(0x1 << S2MU106_REG_PLUG_CTRL_PD_RST_OPTION_SHIFT)	


#define S2MU106_REG_MSG_SEND_CON_SEND_MSG_EN_SHIFT    (0)
#define S2MU106_REG_MSG_SEND_CON_OP_MODE_SHIFT        (1)
#define S2MU106_REG_MSG_SEND_CON_SOP_SHIFT            (2)
#define S2MU106_REG_MSG_SEND_CON_HARD_EN_SHIFT        (6)

#define S2MU106_REG_MSG_SEND_CON_SEND_MSG_EN \
	(0x1 << S2MU106_REG_MSG_SEND_CON_SEND_MSG_EN_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_OP_MODE \
	(0x1 << S2MU106_REG_MSG_SEND_CON_OP_MODE_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP \
	(0x0 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_Prime \
	(0x1 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_DPrime \
	(0x2 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_PDebug \
	(0x3 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_DPDebug \
	(0x4 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_HardRST \
	(0x5 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_SOP_CableRST \
	(0x6 << S2MU106_REG_MSG_SEND_CON_SOP_SHIFT) 
#define S2MU106_REG_MSG_SEND_CON_HARD_EN \
	(0x1 << S2MU106_REG_MSG_SEND_CON_HARD_EN_SHIFT) 


#define S2MU106_PDIC_RID_SHIFT        (5)
#define S2MU106_PDIC_RID_MASK        (0x7 << S2MU106_PDIC_RID_SHIFT) 


#define S2MU106_REG_CTRL_MON_PD1_SHIFT        (0)
#define S2MU106_REG_CTRL_MON_PD2_SHIFT        (3)
#define S2MU106_REG_CTRL_MON_PD1_MASK \
	(0x7 << S2MU106_REG_CTRL_MON_PD1_SHIFT) 
#define S2MU106_REG_CTRL_MON_PD2_MASK \
	(0x7 << S2MU106_REG_CTRL_MON_PD2_SHIFT) 


#define S2MU106_PDIC_PLUG_ATTACH_DONE_SHIFT    (1)
#define S2MU106_PDIC_SINK_SEL_MONITOR_SHIFT    (2)
#define S2MU106_PDIC_SOURCE_SEL_MONITOR_SHIFT    (3)

#define S2MU106_PDIC_SINK (1 << S2MU106_PDIC_SINK_SEL_MONITOR_SHIFT \
	| 1 << S2MU106_PDIC_PLUG_ATTACH_DONE_SHIFT) 
#define S2MU106_PDIC_SOURCE (1 << S2MU106_PDIC_SOURCE_SEL_MONITOR_SHIFT \
	| 1 << S2MU106_PDIC_PLUG_ATTACH_DONE_SHIFT) 
#define S2MU106_PDIC_ATTACH_MASK (1 << S2MU106_PDIC_PLUG_ATTACH_DONE_SHIFT) 
#define S2MU106_PR_MASK (S2MU106_PDIC_SINK | S2MU106_PDIC_SOURCE) 


#define S2MU106_REG_ETC_SOFT_RESET_EN_SHIFT    (1)
#define S2MU106_REG_ETC_SOFT_RESET_EN \
	(0x1 << S2MU106_REG_ETC_SOFT_RESET_EN_SHIFT) 
#define S2MU106_REG_ETC_SOFT_RESET_DIS \
	(0x0 << S2MU106_REG_ETC_SOFT_RESET_EN_SHIFT) 


#define S2MU106_REG_ID_MONITOR_MSG_ID_MASK    (0x07)





#define S2MU106_REG_INT_STATUS0_MSG_ACCEPT    (1<<0)
#define S2MU106_REG_INT_STATUS0_MSG_GOODCRC   (1<<1)
#define S2MU106_REG_INT_STATUS0_VDM_ATTENTION (1<<2)
#define S2MU106_REG_INT_STATUS0_VDM_EXIT      (1<<3)
#define S2MU106_REG_INT_STATUS0_VDM_ENTER     (1<<4)
#define S2MU106_REG_INT_STATUS0_VDM_DISCOVER_MODE (1<<5)
#define S2MU106_REG_INT_STATUS0_VDM_DISCOVER_SVID (1<<6)
#define S2MU106_REG_INT_STATUS0_VDM_DISCOVER_ID   (1<<7)


#define S2MU106_REG_INT_STATUS1_MSG_PING      (1<<7)
#define S2MU106_REG_INT_STATUS1_MSG_GOTOMIN   (1<<6)
#define S2MU106_REG_INT_STATUS1_MSG_REJECT    (1<<5)
#define S2MU106_REG_INT_STATUS1_MSG_PSRDY     (1<<4)
#define S2MU106_REG_INT_STATUS1_MSG_GETSRCCAP (1<<3)
#define S2MU106_REG_INT_STATUS1_MSG_GETSNKCAP (1<<2)
#define S2MU106_REG_INT_STATUS1_MSG_DR_SWAP   (1<<1)
#define S2MU106_REG_INT_STATUS1_MSG_PR_SWAP   (1<<0)


#define S2MU106_REG_INT_STATUS2_MSG_VCONN_SWAP (1<<7)
#define S2MU106_REG_INT_STATUS2_MSG_WAIT       (1<<6)
#define S2MU106_REG_INT_STATUS2_MSG_SRC_CAP    (1<<5)
#define S2MU106_REG_INT_STATUS2_MSG_SNK_CAP    (1<<4)
#define S2MU106_REG_INT_STATUS2_MSG_REQUEST    (1<<3)
#define S2MU106_REG_INT_STATUS2_MSG_SOFTRESET  (1<<2)
#define S2MU106_REG_INT_STATUS2_WAKEUP         (1<<0)


#define S2MU106_REG_INT_STATUS3_UNS_CMD_DATA   (1<<5)


#define S2MU106_REG_INT_STATUS4_PD12_DET_IRQ  (1<<6)
#define S2MU106_REG_INT_STATUS4_PLUG_IRQ      (1<<5)
#define S2MU106_REG_INT_STATUS4_USB_DETACH    (1<<4)
#define S2MU106_REG_INT_STATUS4_MSG_PASS      (1<<3)
#define S2MU106_REG_INT_STATUS4_MSG_SENT      (1<<2)
#define S2MU106_REG_INT_STATUS4_MSG_ERROR     (1<<1)


#define S2MU106_REG_INT_STATUS5_HARD_RESET     (1<<2)


#define ENABLED_INT_0    (S2MU106_REG_INT_STATUS0_MSG_GOODCRC |\
						S2MU106_REG_INT_STATUS0_MSG_ACCEPT)
#define ENABLED_INT_1    (S2MU106_REG_INT_STATUS1_MSG_PING |\
						S2MU106_REG_INT_STATUS1_MSG_REJECT |\
						S2MU106_REG_INT_STATUS1_MSG_PSRDY |\
						S2MU106_REG_INT_STATUS1_MSG_DR_SWAP |\
						S2MU106_REG_INT_STATUS1_MSG_PR_SWAP)
#define ENABLED_INT_2    (S2MU106_REG_INT_STATUS2_MSG_VCONN_SWAP |\
						S2MU106_REG_INT_STATUS2_MSG_WAIT |\
						S2MU106_REG_INT_STATUS2_MSG_REQUEST)
#define ENABLED_INT_2_WAKEUP    (S2MU106_REG_INT_STATUS2_MSG_VCONN_SWAP |\
						S2MU106_REG_INT_STATUS2_MSG_WAIT |\
						S2MU106_REG_INT_STATUS2_MSG_SOFTRESET |\
						S2MU106_REG_INT_STATUS2_WAKEUP)
#define ENABLED_INT_3    S2MU106_REG_INT_STATUS3_UNS_CMD_DATA
#define ENABLED_INT_4    (S2MU106_REG_INT_STATUS4_USB_DETACH |\
				S2MU106_REG_INT_STATUS4_PLUG_IRQ |\
				S2MU106_REG_INT_STATUS4_MSG_PASS |\
				S2MU106_REG_INT_STATUS4_MSG_ERROR)
#define ENABLED_INT_4_WATER    (S2MU106_REG_INT_STATUS4_MSG_PASS |\
				S2MU106_REG_INT_STATUS4_MSG_ERROR)
#define ENABLED_INT_5    (S2MU106_REG_INT_STATUS5_HARD_RESET)


enum s2mu106_usbpd_reg {
	S2MU106_REG_PD_TRIM            = 0x00,
	S2MU106_REG_PD_CTRL            = 0x01,
	S2MU106_REG_PD_CTRL_2          = 0x02,
	S2MU106_REG_ANALOG_OTP_04      = 0x04,
	S2MU106_REG_ANALOG_OTP_08      = 0x08,
	S2MU106_REG_ANALOG_OTP_0A      = 0x0A,
	S2MU106_REG_PHY_CTRL_00        = 0x10,
	S2MU106_REG_PHY_CTRL_IFG       = 0x13,
	S2MU106_REG_BMC_CTRL	       = 0x14,
	S2MU106_REG_PLUG_CTRL_PORT     = 0x18,
	S2MU106_REG_PLUG_CTRL_MSG      = 0x19,
	S2MU106_REG_PLUG_CTRL_VBUS_MUX = 0x1B,
	S2MU106_REG_PLUG_CTRL_SET_RD_2 = 0x1C,
	S2MU106_REG_PLUG_CTRL_SET_RP_2 = 0x1D,
	S2MU106_REG_PLUG_CTRL_SET_RD   = 0x1E,
	S2MU106_REG_PLUG_CTRL_SET_RP   = 0x1F,
	S2MU106_REG_PLUG_CTRL_PD_TIMER1 = 0x20,
	S2MU106_REG_PLUG_CTRL_PD_TIMER2 = 0x21,
	S2MU106_REG_PLUG_CTRL_SET_MON  = 0x22,
	S2MU106_REG_PLUG_CTRL_PD_HOLD  = 0x26,
	S2MU106_REG_PLUG_CTRL_RpRd     = 0x27,
	S2MU106_REG_PLUG_CTRL_PD12     = 0x28,
	S2MU106_REG_PLUG_CTRL          = 0x2E,
	S2MU106_REG_CTRL               = 0x2F,

	S2MU106_REG_INT_MASK0          = 0x3E,
	S2MU106_REG_INT_MASK1          = 0x3F,
	S2MU106_REG_INT_MASK2          = 0x40,
	S2MU106_REG_INT_MASK3          = 0x41,
	S2MU106_REG_INT_MASK4          = 0x42,
	S2MU106_REG_INT_STATUS0        = 0xE0,
	S2MU106_REG_INT_STATUS1        = 0xE1,
	S2MU106_REG_INT_STATUS2        = 0xE2,
	S2MU106_REG_INT_STATUS3        = 0xE3,
	S2MU106_REG_INT_STATUS4        = 0xE4,
	S2MU106_REG_ADC_STATUS         = 0xB2,
	S2MU106_REG_PLUG_MON1          = 0xB3,
	S2MU106_REG_PLUG_MON2          = 0xB4,
	S2MU106_REG_PLUG_FSM_MON       = 0xB7,

	S2MU106_REG_MSG_SEND_CON       = 0x90,
	S2MU106_REG_MSG_TX_HEADER_L    = 0x91,
	S2MU106_REG_MSG_TX_HEADER_H    = 0x92,
	S2MU106_REG_MSG_TX_OBJECT0_0_L = 0x93,
	S2MU106_REG_MSG_TX_OBJECT0_0_H = 0x94,
	S2MU106_REG_MSG_TX_OBJECT0_1_L = 0x95,
	S2MU106_REG_MSG_TX_OBJECT0_1_H = 0x96,
	S2MU106_REG_MSG_TX_OBJECT1_0_L = 0x97,
	S2MU106_REG_MSG_TX_OBJECT1_0_H = 0x98,
	S2MU106_REG_MSG_TX_OBJECT1_1_L = 0x99,
	S2MU106_REG_MSG_TX_OBJECT1_1_H = 0x9A,
	S2MU106_REG_MSG_TX_OBJECT2_0_L = 0x9B,
	S2MU106_REG_MSG_TX_OBJECT2_0_H = 0x9C,
	S2MU106_REG_MSG_TX_OBJECT2_1_L = 0x9D,
	S2MU106_REG_MSG_TX_OBJECT2_1_H = 0x9E,
	S2MU106_REG_MSG_TX_OBJECT3_0_L = 0x9F,
	S2MU106_REG_MSG_TX_OBJECT3_0_H = 0xA0,
	S2MU106_REG_MSG_TX_OBJECT3_1_L = 0xA1,
	S2MU106_REG_MSG_TX_OBJECT3_1_H = 0xA2,
	S2MU106_REG_MSG_TX_OBJECT4_0_L = 0xA3,
	S2MU106_REG_MSG_TX_OBJECT4_0_H = 0xA4,
	S2MU106_REG_MSG_TX_OBJECT4_1_L = 0xA5,
	S2MU106_REG_MSG_TX_OBJECT4_1_H = 0xA6,
	S2MU106_REG_MSG_TX_OBJECT5_0_L = 0xA7,
	S2MU106_REG_MSG_TX_OBJECT5_0_H = 0xA8,
	S2MU106_REG_MSG_TX_OBJECT5_1_L = 0xA9,
	S2MU106_REG_MSG_TX_OBJECT5_1_H = 0xAA,
	S2MU106_REG_MSG_TX_OBJECT6_0_L = 0xAB,
	S2MU106_REG_MSG_TX_OBJECT6_0_H = 0xAC,
	S2MU106_REG_MSG_TX_OBJECT6_1_L = 0xAD,
	S2MU106_REG_MSG_TX_OBJECT6_1_H = 0xAE,

	S2MU106_REG_MSG_RX_HEADER_L    = 0xC1,
	S2MU106_REG_MSG_RX_HEADER_H    = 0xC2,
	S2MU106_REG_MSG_RX_OBJECT0_0_L = 0xC3,
	S2MU106_REG_MSG_RX_OBJECT0_0_H = 0xC4,
	S2MU106_REG_MSG_RX_OBJECT0_1_L = 0xC5,
	S2MU106_REG_MSG_RX_OBJECT0_1_H = 0xC6,
	S2MU106_REG_MSG_RX_OBJECT1_0_L = 0xC7,
	S2MU106_REG_MSG_RX_OBJECT1_0_H = 0xC8,
	S2MU106_REG_MSG_RX_OBJECT1_1_L = 0xC9,
	S2MU106_REG_MSG_RX_OBJECT1_1_H = 0xCA,
	S2MU106_REG_MSG_RX_OBJECT2_0_L = 0xCB,
	S2MU106_REG_MSG_RX_OBJECT2_0_H = 0xCC,
	S2MU106_REG_MSG_RX_OBJECT2_1_L = 0xCD,
	S2MU106_REG_MSG_RX_OBJECT2_1_H = 0xCE,
	S2MU106_REG_MSG_RX_OBJECT3_0_L = 0xCF,
	S2MU106_REG_MSG_RX_OBJECT3_0_H = 0xD0,
	S2MU106_REG_MSG_RX_OBJECT3_1_L = 0xD1,
	S2MU106_REG_MSG_RX_OBJECT3_1_H = 0xD2,
	S2MU106_REG_MSG_RX_OBJECT4_0_L = 0xD3,
	S2MU106_REG_MSG_RX_OBJECT4_0_H = 0xD4,
	S2MU106_REG_MSG_RX_OBJECT4_1_L = 0xD5,
	S2MU106_REG_MSG_RX_OBJECT4_1_H = 0xD6,
	S2MU106_REG_MSG_RX_OBJECT5_0_L = 0xD7,
	S2MU106_REG_MSG_RX_OBJECT5_0_H = 0xD8,
	S2MU106_REG_MSG_RX_OBJECT5_1_L = 0xD9,
	S2MU106_REG_MSG_RX_OBJECT5_1_H = 0xDA,
	S2MU106_REG_MSG_RX_OBJECT6_0_L = 0xDB,
	S2MU106_REG_MSG_RX_OBJECT6_0_H = 0xDC,
	S2MU106_REG_MSG_RX_OBJECT6_1_L = 0xDD,
	S2MU106_REG_MSG_RX_OBJECT6_1_H = 0xDE,

	S2MU106_REG_ETC                = 0xF7,
	S2MU106_REG_ID_MONITOR         = 0xF8,
	S2MU106_REG_ID_MONITOR2        = 0xF9
};

typedef enum {
	S2MU106_THRESHOLD_128MV = 2,
	S2MU106_THRESHOLD_171MV = 3,
	S2MU106_THRESHOLD_214MV = 4,
	S2MU106_THRESHOLD_257MV = 5,
	S2MU106_THRESHOLD_300MV = 6,
	S2MU106_THRESHOLD_342MV = 7,
	S2MU106_THRESHOLD_385MV = 8,
	S2MU106_THRESHOLD_428MV = 9,
	S2MU106_THRESHOLD_450MV = 10,
	S2MU106_THRESHOLD_471MV = 11,
	S2MU106_THRESHOLD_492MV = 12,
	S2MU106_THRESHOLD_514MV = 13,
	S2MU106_THRESHOLD_535MV = 14,
	S2MU106_THRESHOLD_557MV = 15,
	S2MU106_THRESHOLD_578MV = 16,
	S2MU106_THRESHOLD_600MV = 17,
	S2MU106_THRESHOLD_621MV = 18,
	S2MU106_THRESHOLD_642MV = 19,
	S2MU106_THRESHOLD_685MV = 20,
	S2MU106_THRESHOLD_814MV = 23,
	S2MU106_THRESHOLD_1000MV = 27,

	S2MU106_THRESHOLD_1200MV = 32,
	S2MU106_THRESHOLD_1242MV = 33,
	S2MU106_THRESHOLD_1285MV = 34,
	S2MU106_THRESHOLD_1328MV = 35,
	S2MU106_THRESHOLD_1371MV = 36,
	S2MU106_THRESHOLD_1414MV = 37,
	S2MU106_THRESHOLD_1457MV = 38,
	S2MU106_THRESHOLD_1500MV = 39,
	S2MU106_THRESHOLD_1542MV = 40,
	S2MU106_THRESHOLD_1587MV = 41,
	S2MU106_THRESHOLD_1628MV = 42,
	S2MU106_THRESHOLD_1671MV = 43,
	S2MU106_THRESHOLD_1714MV = 44,
	S2MU106_THRESHOLD_1757MV = 45,
	S2MU106_THRESHOLD_1799MV = 46,
	S2MU106_THRESHOLD_1842MV = 47,
	S2MU106_THRESHOLD_1885MV = 48,
	S2MU106_THRESHOLD_1928MV = 49,
	S2MU106_THRESHOLD_1971MV = 50,
	S2MU106_THRESHOLD_2014MV = 51,
	S2MU106_THRESHOLD_2057MV = 52,
	S2MU106_THRESHOLD_2099MV = 53,
	S2MU106_THRESHOLD_2142MV = 54,
	S2MU106_THRESHOLD_2185MV = 55,
	S2MU106_THRESHOLD_2228MV = 56,
	S2MU106_THRESHOLD_2271MV = 57,

	S2MU106_THRESHOLD_MAX     = 63
} PDIC_THRESHOLD_SEL;

typedef enum {
	S2MU106_PD_OCP_255MV = 0,
	S2MU106_PD_OCP_262MV = 1,
	S2MU106_PD_OCP_273MV = 2,
	S2MU106_PD_OCP_282MV = 3,
	S2MU106_PD_OCP_301MV = 4,
	S2MU106_PD_OCP_311MV = 5,
	S2MU106_PD_OCP_327MV = 6,
	S2MU106_PD_OCP_339MV = 7,
	S2MU106_PD_OCP_375MV = 8,
	S2MU106_PD_OCP_390MV = 9,
	S2MU106_PD_OCP_415MV = 10,
	S2MU106_PD_OCP_433MV = 11,
	S2MU106_PD_OCP_478MV = 12,
	S2MU106_PD_OCP_502MV = 13,
	S2MU106_PD_OCP_542MV = 14,
	S2MU106_PD_OCP_575MV = 15,
	S2MU106_PD_OCP_MAX   = 16
} PDIC_PD_OCP_SEL;

typedef enum {
	CC_UNATTACHED_SNK = 0,
	CC_ATTACHWAIT_SNK = 1,
	CC_ATTACHED_SNK = 2,
	CC_RSVD_SNK = 3,
	CC_UNATTACHED_SRC = 4,
	CC_ATTACHWAIT_SRC = 5,
	CC_ATTACHED_SRC = 6,
	CC_RSVD_SRC = 7,
	CC_DISABLE = 8,
	CC_ERR_RECV = 9,
	CC_TRY_SNK = 10,
	CC_TRY_WAIT_SRC = 11,
	CC_TRY_SRC = 12,
	CC_TRY_WAIT_SNK = 13,
	CC_AUDIO_ACC = 14,
	CC_DEBUG_ACC = 15,
} TYPEC_STATE;

typedef enum {
	S2MU106_PHY_IFG_25US = 0,
	S2MU106_PHY_IFG_30US = 1,
	S2MU106_PHY_IFG_35US = 2,
} PDIC_PHY_IFG_SEL;


typedef enum {
	DET_HARD_RESET = 0,
	DET_DETACH = 1,
} PDIC_DETACH_TYPE;

typedef enum {
	PLUG_CTRL_RD = 0,
	PLUG_CTRL_RP = 1,
} PDIC_RP_RD_SEL;

typedef enum {
	PD_LPM_MODE = 0,
	PD_NORMAL_MODE = 1,
} PDIC_LPM_MODE_SEL;

typedef enum {
	VBUS_WAKEUP_ENABLE = 0,
	VBUS_WAKEUP_DISABLE = 1,
} PDIC_VBUS_WAKEUP_SEL;

struct s2mu106_usbpd_data {
	struct device *dev;
	struct i2c_client *i2c;
	struct mutex _mutex;
	struct mutex poll_mutex;
	struct mutex lpm_mutex;
	struct mutex pd_mutex;
	struct mutex water_mutex;
	struct mutex s2m_water_mutex;
	struct mutex otg_mutex;
	int vconn_en;
	int regulator_en;
	int irq_gpio;
	int irq;
	int power_role;
	int data_role;
	int vconn_source;
	msg_header_type header;
	data_obj_type obj[S2MU106_MAX_NUM_MSG_OBJ];
	u64 status_reg;
	bool lpm_mode;
	bool detach_valid;
	bool is_factory_mode;
	bool is_water_detect;
	bool is_cable_inserted;
	bool is_muic_water_detect;
	bool is_otg_vboost;
	bool is_otg_reboost;
	bool is_pr_swap;
	bool is_muic_attached;
	bool vbus_short_check;
	bool pd_vbus_short_check;
	bool vbus_short;
	bool first_attach;
	int vbus_short_check_cnt;
	int water_detect_cnt;
	int check_msg_pass;
	int rid;
	int is_host;
	int is_client;
	int is_attached;
	int is_killer;
	int vbus_dischg_gpio;
#if IS_ENABLED(CONFIG_DUAL_ROLE_USB_INTF)
	struct dual_role_phy_instance *dual_role;
	struct dual_role_phy_desc *desc;
	struct completion reverse_completion;
	int try_state_change;
	struct delayed_work role_swap_work;
	int data_role_dual; 
	int power_role_dual; 
#endif

	int rp_lvl;
	int slice_lvl[2];

	struct notifier_block type3_nb;
	struct workqueue_struct *pdic_queue;
	struct delayed_work plug_work;
	struct s2m_pdic_notifier_struct pdic_notifier;
	struct delayed_work vbus_dischg_off_work;
	int facwater_check_cnt;
	int pm_cc1;
	int pm_cc2;
	int pm_chgin;
	int pm_vgpadc;
	struct power_supply *psy_pm;
	struct power_supply *psy_pdic;
	struct power_supply *psy_muic;
	int cc1_val;
	int cc2_val;
	int cc_instead_of_vbus;
	bool checking_pm_water;
#if IS_ENABLED(CONFIG_S2MU106_TYPEC_WATER)
	struct delayed_work check_facwater;
	int water_status;
	int water_cc;
	int power_off_water_detected;

	int water_th;
	int water_post;
	int dry_th;
	int dry_th_post;
	int water_delay;
	int water_th_ra;

	int water_gpadc_short;
	int water_gpadc_poweroff;

	struct mutex plug_mutex;
#endif

#if !defined(CONFIG_ARCH_EXYNOS) && !defined(CONFIG_ARCH_MEDIATEK)
	struct wakeup_source	*water_wake;
	struct wakeup_source	*water_irq_wake;
	struct delayed_work	water_wake_work;
#endif

	struct regulator *regulator;
	int rprd_mode;
	int first_goodcrc;

	void (*rprd_mode_change)(void *data, u8 mode);

#if defined(CONFIG_S2MU106_PDIC_TRY_SNK)
	struct alarm srcdet_alarm;
	struct alarm snkdet_alarm;
	bool srcdet_expired;
	bool snkdet_expired;
#endif
};

extern int s2mu106_usbpd_get_adc(void);
extern void s2mu106_usbpd_set_muic_type(int type);
#if IS_ENABLED(CONFIG_PDIC_NOTIFIER)
extern void s2mu106_control_option_command(struct s2mu106_usbpd_data *usbpd_data, int cmd);
#endif
#if IS_ENABLED(CONFIG_SEC_FACTORY)
extern int s2mu106_sys_power_off_water_check(struct s2mu106_usbpd_data *pdic_data);
#endif
extern void s2mu106_rprd_mode_change(void *data, u8 mode);
extern int s2mu106_set_lpm_mode(struct s2mu106_usbpd_data *pdic_data);
extern int s2mu106_set_normal_mode(struct s2mu106_usbpd_data *pdic_data);
#endif 

