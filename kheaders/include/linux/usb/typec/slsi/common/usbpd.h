#ifndef __USBPD_H__
#define __USBPD_H__

#include <linux/usb/typec/slsi/common/usbpd_msg.h>
#include <linux/usb/typec/common/pdic_core.h>
#include <linux/muic/common/muic.h>

#include <linux/time.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ktime.h>
#include <linux/power_supply.h>
#include <linux/usb/typec.h>

#if IS_ENABLED(CONFIG_BATTERY_SAMSUNG) && IS_ENABLED(CONFIG_USB_TYPEC_MANAGER_NOTIFIER)
#if IS_ENABLED(CONFIG_BATTERY_NOTIFIER)
#include <linux/battery/battery_notifier.h>
#else
#include <linux/battery/sec_pd.h>
#endif
#endif

#define MAX_CHARGING_VOLT		12000 
#define USBPD_VOLT_UNIT			50 
#define USBPD_CURRENT_UNIT		10 
#define USBPD_POWER_UNIT		250 
#define USBPD_PPS_VOLT_UNIT			100 
#define USBPD_PPS_CURRENT_UNIT		50 
#define USBPD_PPS_RQ_VOLT_UNIT			20 
#define USBPD_PPS_RQ_CURRENT_UNIT		50 

#define USBPD_MAX_COUNT_MSG_OBJECT	(8) 


#define USBPD_nMessageIDCount		(7)
#define USBPD_nRetryCount		(3)
#define USBPD_nHardResetCount		(4)
#define USBPD_nCapsCount		(16)
#define USBPD_nDiscoverIdentityCount	(20)


#define tSrcTransition		(25)	
#define tPSSourceOn		(420)	
#define tPSSourceOff		(750)	
#if defined(CONFIG_SEC_FACTORY)
#define tSenderResponse		(1100)	
#else
#define tSenderResponse		(25)	
#endif
#define tSenderResponseSRC	(300)	
#define tSendSourceCap		(10)	
#define tPSHardReset		(22)	
#define tSinkWaitCap		(2500)	
#define tPSTransition		(500)	
#define tVCONNSourceOn		(100)	
#define tVDMSenderResponse	(35)	
#define tVDMWaitModeEntry	(50)	
#define tVDMWaitModeExit	(50)    
#define tDiscoverIdentity	(50)	
#define tSwapSourceStart        (20)	
#define tTypeCSinkWaitCap       (550)	
#define tTypeCSendSourceCap (100) 
#define tSrcRecover (880) 
#define tNoResponse (5500) 
#define tDRPtry (75) 
#define tTryCCDebounce (15) 


#define tStartAmsMargin (100)

enum s2m_pdic_power_role {
	PDIC_SINK,
	PDIC_SOURCE
};

typedef enum {
	VBUS_OFF = 0,
	VBUS_ON = 1,
} PDIC_VBUS_SEL;


typedef enum {
	
	PRL_Rx_Layer_Reset_for_Receive	= 0x11,
	PRL_Rx_Wait_for_PHY_Message	= 0x12,
	PRL_Rx_Send_GoodCRC		= 0x13,
	PRL_Rx_Store_MessageID		= 0x14,
	PRL_Rx_Check_MessageID		= 0x15,

	
	PRL_Tx_PHY_Layer_Reset		= 0x21,
	PRL_Tx_Wait_for_Message_Request	= 0x22,
	PRL_Tx_Layer_Reset_for_Transmit	= 0x23,
	PRL_Tx_Construct_Message	= 0x24,
	PRL_Tx_Wait_for_PHY_Response	= 0x25,
	PRL_Tx_Match_MessageID		= 0x26,
	PRL_Tx_Message_Sent		= 0x27,
	PRL_Tx_Check_RetryCounter	= 0x28,
	PRL_Tx_Transmission_Error	= 0x29,
	PRL_Tx_Discard_Message		= 0x2A,
} protocol_state;


typedef enum {
	
	PE_SRC_Startup			= 0x30,
	PE_SRC_Discovery		= 0x31,
	PE_SRC_Send_Capabilities	= 0x32,
	PE_SRC_Negotiate_Capability	= 0x33,
	PE_SRC_Transition_Supply	= 0x34,
	PE_SRC_Ready			= 0x35,
	PE_SRC_Disabled			= 0x36,
	PE_SRC_Capability_Response	= 0x37,
	PE_SRC_Hard_Reset		= 0x38,
	PE_SRC_Hard_Reset_Received	= 0x39,
	PE_SRC_Transition_to_default	= 0x3A,
	PE_SRC_Give_Source_Cap		= 0x3B,
	PE_SRC_Get_Sink_Cap		= 0x3C,
	PE_SRC_Wait_New_Capabilities	= 0x3D,

	
	PE_SNK_Startup			= 0x40,
	PE_SNK_Discovery		= 0x41,
	PE_SNK_Wait_for_Capabilities	= 0x42,
	PE_SNK_Evaluate_Capability	= 0x43,
	PE_SNK_Select_Capability	= 0x44,
	PE_SNK_Transition_Sink		= 0x45,
	PE_SNK_Ready			= 0x46,
	PE_SNK_Hard_Reset		= 0x47,
	PE_SNK_Transition_to_default	= 0x48,
	PE_SNK_Give_Sink_Cap		= 0x49,
	PE_SNK_Get_Source_Cap		= 0x4A,

	
	PE_SRC_Send_Soft_Reset		= 0x50,
	PE_SRC_Soft_Reset		= 0x51,

	
	PE_SNK_Send_Soft_Reset		= 0x60,
	PE_SNK_Soft_Reset		= 0x61,

	
	PE_UFP_VDM_Get_Identity		= 0x70,
	PE_UFP_VDM_Send_Identity	= 0x71,
	PE_UFP_VDM_Get_Identity_NAK	= 0x72,
	PE_UFP_VDM_Get_SVIDs		= 0x73,
	PE_UFP_VDM_Send_SVIDs		= 0x74,
	PE_UFP_VDM_Get_SVIDs_NAK	= 0x75,
	PE_UFP_VDM_Get_Modes		= 0x76,
	PE_UFP_VDM_Send_Modes		= 0x77,
	PE_UFP_VDM_Get_Modes_NAK	= 0x78,
	PE_UFP_VDM_Evaluate_Mode_Entry	= 0x79,
	PE_UFP_VDM_Mode_Entry_ACK	= 0x7A,
	PE_UFP_VDM_Mode_Entry_NAK	= 0x7B,
	PE_UFP_VDM_Mode_Exit		= 0x7C,
	PE_UFP_VDM_Mode_Exit_ACK	= 0x7D,
	PE_UFP_VDM_Mode_Exit_NAK	= 0x7E,
	PE_UFP_VDM_Attention_Request	= 0x7F,
	PE_UFP_VDM_Evaluate_Status	= 0x80,
	PE_UFP_VDM_Status_ACK		= 0x81,
	PE_UFP_VDM_Status_NAK		= 0x82,
	PE_UFP_VDM_Evaluate_Configure	= 0x83,
	PE_UFP_VDM_Configure_ACK	= 0x84,
	PE_UFP_VDM_Configure_NAK	= 0x85,

	
	PE_DFP_VDM_Identity_Request		= 0x8A,
	PE_DFP_VDM_Identity_ACKed		= 0x8B,
	PE_DFP_VDM_Identity_NAKed		= 0x8C,
	PE_DFP_VDM_SVIDs_Request		= 0x8D,
	PE_DFP_VDM_SVIDs_ACKed			= 0x8E,
	PE_DFP_VDM_SVIDs_NAKed			= 0x8F,
	PE_DFP_VDM_Modes_Request		= 0x90,
	PE_DFP_VDM_Modes_ACKed			= 0x91,
	PE_DFP_VDM_Modes_NAKed			= 0x92,
	PE_DFP_VDM_Mode_Entry_Request		= 0x93,
	PE_DFP_VDM_Mode_Entry_ACKed		= 0x94,
	PE_DFP_VDM_Mode_Entry_NAKed		= 0x95,
	PE_DFP_VDM_Mode_Exit_Request		= 0x96,
	PE_DFP_VDM_Mode_Exit_ACKed		= 0x97,
	PE_DFP_VDM_Mode_Exit_NAKed		= 0x98,
	PE_DFP_VDM_Status_Update		= 0x99,
	PE_DFP_VDM_Status_Update_ACKed		= 0x9A,
	PE_DFP_VDM_Status_Update_NAKed		= 0x9B,
	PE_DFP_VDM_DisplayPort_Configure	= 0x9C,
	PE_DFP_VDM_DisplayPort_Configure_ACKed	= 0x9D,
	PE_DFP_VDM_DisplayPort_Configure_NAKed	= 0x9E,
	PE_DFP_VDM_Attention_Request		= 0x9F,

	
	PE_PRS_SRC_SNK_Reject_PR_Swap	= 0xA0,
	PE_PRS_SRC_SNK_Evaluate_Swap	= 0xA1,
	PE_PRS_SRC_SNK_Send_Swap	= 0xA2,
	PE_PRS_SRC_SNK_Accept_Swap	= 0xA3,
	PE_PRS_SRC_SNK_Transition_off	= 0xA4,
	PE_PRS_SRC_SNK_Assert_Rd	= 0xA5,
	PE_PRS_SRC_SNK_Wait_Source_on	= 0xA6,
	PE_PRS_SNK_SRC_Reject_Swap	= 0xA7,
	PE_PRS_SNK_SRC_Evaluate_Swap	= 0xA8,
	PE_PRS_SNK_SRC_Send_Swap	= 0xA9,
	PE_PRS_SNK_SRC_Accept_Swap	= 0xAA,
	PE_PRS_SNK_SRC_Transition_off	= 0xAB,
	PE_PRS_SNK_SRC_Assert_Rp	= 0xAC,
	PE_PRS_SNK_SRC_Source_on	= 0xAD,

	
	PE_DRS_DFP_UFP_Evaluate_DR_Swap	= 0xAE,
	PE_DRS_DFP_UFP_Accept_DR_Swap	= 0xAF,
	PE_DRS_DFP_UFP_Change_to_UFP	= 0xB0,
	PE_DRS_DFP_UFP_Send_DR_Swap	= 0xB1,
	PE_DRS_DFP_UFP_Reject_DR_Swap	= 0xB2,
	PE_DRS_UFP_DFP_Evaluate_DR_Swap	= 0xB3,
	PE_DRS_UFP_DFP_Accept_DR_Swap	= 0xB4,
	PE_DRS_UFP_DFP_Change_to_DFP	= 0xB5,
	PE_DRS_UFP_DFP_Send_DR_Swap	= 0xB6,
	PE_DRS_UFP_DFP_Reject_DR_Swap	= 0xB7,
	PE_DRS_Evaluate_Port		= 0xB8,
	PE_DRS_Evaluate_Send_Port	= 0xB9,

	
	PE_VCS_Evaluate_Swap		= 0xC0,
	PE_VCS_Accept_Swap		= 0xC1,
	PE_VCS_Wait_for_VCONN		= 0xC2,
	PE_VCS_Turn_Off_VCONN		= 0xC3,
	PE_VCS_Turn_On_VCONN		= 0xC4,
	PE_VCS_Send_PS_RDY		= 0xC5,
	PE_VCS_Send_Swap		= 0xC6,
	PE_VCS_Reject_VCONN_Swap	= 0xC7,

	
	PE_DFP_UVDM_Send_Message	= 0xD0,
	PE_DFP_UVDM_Receive_Message	= 0xD1,

	
	PE_DR_SRC_Get_Source_Cap = 0xE0,
	PE_DR_SRC_Give_Sink_Cap = 0xE1,
	PE_DR_SNK_Get_Sink_Cap  = 0xE2,
	PE_DR_SNK_Give_Source_Cap = 0xE3,
	PE_DR_SRC_Get_Source_Cap_Ext	= 0xE4,
	PE_DR_SNK_Give_Source_Cap_Ext	= 0xE5,

	
	PE_BIST_Carrier_Mode = 0xE6,

	
	PE_SRC_Send_Not_Supported	= 0xE7,
	PE_SRC_Not_Supported_Received	= 0xE8,
	PE_SRC_Chunk_Received	= 0xE9,

	PE_SNK_Send_Not_Supported	= 0xEA,
	PE_SNK_Not_Supported_Received	= 0xEB,
	PE_SNK_Chunk_Received	= 0xEC,

	PE_SRC_Send_Source_Alert	= 0xED,
	PE_SNK_Source_Alert_Received	= 0xEE,
	PE_SNK_Send_Sink_Alert	= 0xEF,
	PE_SRC_Sink_Alert_Received	= 0xF0,

	PE_SNK_Get_Source_Cap_Ext	= 0xF1,
	PE_SRC_Give_Source_Cap_Ext	= 0xF2,
	PE_SNK_Get_Source_Status	= 0xF3,
	PE_SRC_Give_Source_Status	= 0xF4,
	PE_SRC_Get_Sink_Status		= 0xF5,
	PE_SNK_Give_Sink_Status		= 0xF6,
	PE_SNK_Get_PPS_Status		= 0xF7,
	PE_SRC_Give_PPS_Status		= 0xF8,

	PE_Get_Battery_Cap	= 0xF9,
	PE_Give_Battery_Cap	= 0xFA,
	PE_Get_Battery_Status	= 0xFB,
	PE_Give_Battery_Status	= 0xFC,
	PE_Get_Manufacturer_Info	= 0xFD,
	PE_Give_Manufacturer_Info	= 0xFE,

	PE_Get_Country_Codes	= 0x10,
	PE_Give_Country_Codes	= 0x11,
	PE_Get_Country_Info		= 0x12,
	PE_Give_Country_Info	= 0x13,
	PE_Send_Security_Request	= 0x14,
	PE_Send_Security_Response	= 0x15,
	PE_Security_Response_Received	= 0x16,
	PE_Send_Firmware_Update_Request	= 0x17,
	PE_Send_Firmware_Update_Response	= 0x18,
	PE_Firmware_Update_Response_Received	= 0x19,

	
	PE_FRS_SRC_SNK_Evaluate_Swap	= 0x1A,
	PE_FRS_SRC_SNK_Accept_Swap		= 0x1B,
	PE_FRS_SRC_SNK_Transition_to_off = 0x1C,
	PE_FRS_SRC_SNK_Assert_Rd		= 0x1D,
	PE_FRS_SRC_SNK_Wait_Source_on	= 0x1E,

	PE_FRS_SNK_SRC_Start_AMS		= 0x1F,
	PE_FRS_SNK_SRC_Send_Swap		= 0x20,
	PE_FRS_SNK_SRC_Transition_to_off = 0x21,
	PE_FRS_SNK_SRC_Vbus_Applied		= 0x22,
	PE_FRS_SNK_SRC_Assert_Rp		= 0x23,
	PE_FRS_SNK_SRC_Source_on		= 0x24,

	
	PE_DFP_VDM_EVALUATE,

	Error_Recovery			= 0xFF
} policy_state;

typedef enum usbpd_manager_command {
	MANAGER_REQ_GET_SNKCAP			= 1,
	MANAGER_REQ_GOTOMIN			= 1 << 2,
	MANAGER_REQ_SRCCAP_CHANGE		= 1 << 3,
	MANAGER_REQ_PR_SWAP			= 1 << 4,
	MANAGER_REQ_DR_SWAP			= 1 << 5,
	MANAGER_REQ_VCONN_SWAP			= 1 << 6,
	MANAGER_REQ_VDM_DISCOVER_IDENTITY	= 1 << 7,
	MANAGER_REQ_VDM_DISCOVER_SVID		= 1 << 8,
	MANAGER_REQ_VDM_DISCOVER_MODE		= 1 << 9,
	MANAGER_REQ_VDM_ENTER_MODE		= 1 << 10,
	MANAGER_REQ_VDM_EXIT_MODE		= 1 << 11,
	MANAGER_REQ_VDM_ATTENTION		= 1 << 12,
	MANAGER_REQ_VDM_STATUS_UPDATE		= 1 << 13,
	MANAGER_REQ_VDM_DisplayPort_Configure	= 1 << 14,
	MANAGER_REQ_NEW_POWER_SRC		= 1 << 15,
	MANAGER_REQ_UVDM_SEND_MESSAGE		= 1 << 16,
	MANAGER_REQ_UVDM_RECEIVE_MESSAGE	= 1 << 17,
	MANAGER_REQ_GET_SRC_CAP			= 1 << 18,
} usbpd_manager_command_type;

typedef enum usbpd_manager_event {
	MANAGER_DISCOVER_IDENTITY_ACKED	= 0,
	MANAGER_DISCOVER_IDENTITY_NAKED	= 1,
	MANAGER_DISCOVER_SVID_ACKED	= 2,
	MANAGER_DISCOVER_SVID_NAKED	= 3,
	MANAGER_DISCOVER_MODE_ACKED	= 4,
	MANAGER_DISCOVER_MODE_NAKED	= 5,
	MANAGER_ENTER_MODE_ACKED	= 6,
	MANAGER_ENTER_MODE_NAKED	= 7,
	MANAGER_EXIT_MODE_ACKED		= 8,
	MANAGER_EXIT_MODE_NAKED		= 9,
	MANAGER_ATTENTION_REQUEST	= 10,
	MANAGER_STATUS_UPDATE_ACKED	= 11,
	MANAGER_STATUS_UPDATE_NAKED	= 12,
	MANAGER_DisplayPort_Configure_ACKED	= 13,
	MANAGER_DisplayPort_Configure_NACKED	= 14,
	MANAGER_NEW_POWER_SRC		= 15,
	MANAGER_UVDM_SEND_MESSAGE		= 16,
	MANAGER_UVDM_RECEIVE_MESSAGE		= 17,
	MANAGER_START_DISCOVER_IDENTITY	= 18,
	MANAGER_GET_SRC_CAP			= 19,
	MANAGER_SEND_PR_SWAP	= 20,
	MANAGER_SEND_DR_SWAP	= 21,
	MANAGER_CAP_MISMATCH	= 22,
} usbpd_manager_event_type;

enum usbpd_msg_status {
	MSG_GOODCRC	= 0,
	MSG_ACCEPT	= 1,
	MSG_PSRDY	= 2,
	MSG_REQUEST	= 3,
	MSG_REJECT	= 4,
	MSG_WAIT	= 5,
	MSG_ERROR	= 6,
	MSG_PING	= 7,
	MSG_GET_SNK_CAP = 8,
	MSG_GET_SRC_CAP = 9,
	MSG_SNK_CAP     = 10,
	MSG_SRC_CAP     = 11,
	MSG_PR_SWAP	= 12,
	MSG_DR_SWAP	= 13,
	MSG_VCONN_SWAP	= 14,
	VDM_DISCOVER_IDENTITY	= 15,
	VDM_DISCOVER_SVID	= 16,
	VDM_DISCOVER_MODE	= 17,
	VDM_ENTER_MODE		= 18,
	VDM_EXIT_MODE		= 19,
	VDM_ATTENTION		= 20,
	VDM_DP_STATUS_UPDATE	= 21,
	VDM_DP_CONFIGURE	= 22,
	MSG_SOFTRESET		= 23,
	PLUG_DETACH		= 24,
	PLUG_ATTACH		= 25,
	MSG_HARDRESET		= 26,
	PD_DETECT		= 27,
	UVDM_MSG		= 28,
	MSG_PASS		= 29,
	MSG_RID			= 30,
	MSG_BIST		= 31,

	
	MSG_NOT_SUPPORTED = 32,
	MSG_GET_SOURCE_CAP_EXTENDED = 33,
	MSG_GET_STATUS = 34,
	MSG_FR_SWAP = 35,
	MSG_GET_PPS_STATUS = 36,
	MSG_GET_COUNTRY_CODES = 37,
	MSG_GET_SINK_CAP_EXTENDED = 38,

	
	MSG_BATTERY_STATUS = 39,
	MSG_ALERT = 40,
	MSG_GET_COUNTRY_INFO = 41,

	
	MSG_SOURCE_CAPABILITIES_EXTENDED = 42,
	MSG_STATUS = 43,
	MSG_GET_BATTERY_CAP = 44,
	MSG_GET_BATTERY_STATUS = 45,
	MSG_BATTERY_CAPABILITIES = 46,
	MSG_GET_MANUFACTURER_INFO = 47,
	MSG_MANUFACTURER_INFO = 48,
	MSG_SECURITY_REQUEST = 49,
	MSG_SECURITY_RESPONSE = 50,
	MSG_FIRMWARE_UPDATE_REQUEST = 51,
	MSG_FIRMWARE_UPDATE_RESPONSE = 52,
	MSG_PPS_STATUS = 53,
	MSG_COUNTRY_INFO = 54,
	MSG_COUNTRY_CODES = 55,
	MSG_SINK_CAPABILITIES_EXTENDED = 56,

	MSG_NONE = 61,
	
	MSG_RESERVED = 62,
};


enum usbpd_timer_id {
	DISCOVER_IDENTITY_TIMER   = 1,
	HARD_RESET_COMPLETE_TIMER = 2,
	NO_RESPONSE_TIMER         = 3,
	PS_HARD_RESET_TIMER       = 4,
	PS_SOURCE_OFF_TIMER       = 5,
	PS_SOURCE_ON_TIMER        = 6,
	PS_TRANSITION_TIMER       = 7,
	SENDER_RESPONSE_TIMER     = 8,
	SINK_ACTIVITY_TIMER       = 9,
	SINK_REQUEST_TIMER        = 10,
	SINK_WAIT_CAP_TIMER       = 11,
	SOURCE_ACTIVITY_TIMER     = 12,
	SOURCE_CAPABILITY_TIMER   = 13,
	SWAP_RECOVERY_TIMER       = 14,
	SWAP_SOURCE_START_TIMER   = 15,
	VCONN_ON_TIMER            = 16,
	VDM_MODE_ENTRY_TIMER      = 17,
	VDM_MODE_EXIT_TIMER       = 18,
	VDM_RESPONSE_TIMER        = 19,
	USBPD_TIMER_MAX_COUNT
};

enum usbpd_protocol_status {
	DEFAULT_PROTOCOL_NONE	= 0,
	MESSAGE_SENT		= 1,
	TRANSMISSION_ERROR	= 2
};

enum usbpd_policy_informed {
	DEFAULT_POLICY_NONE	= 0,
	HARDRESET_RECEIVED	= 1,
	SOFTRESET_RECEIVED	= 2,
	PLUG_EVENT		= 3,
	PLUG_ATTACHED		= 4,
	PLUG_DETACHED		= 5,
};

typedef enum {
	PLUG_CTRL_RP0 = 0,
	PLUG_CTRL_RP80 = 1,
	PLUG_CTRL_RP180 = 2,
	PLUG_CTRL_RP330 = 3
} PDIC_RP_SCR_SEL;

typedef enum {
	PPS_DISABLE = 0,
	PPS_ENABLE = 1,
} PPS_ENABLE_SEL;

enum  {
	S2MU106_USBPD_IP,
	S2MU107_USBPD_IP,
	S2MF301_USBPD_IP,
};

enum usbpd_pdic_rid {
    REG_RID_UNDF = 0x00,
    REG_RID_255K = 0x03,
    REG_RID_301K = 0x04,
    REG_RID_523K = 0x05,
    REG_RID_619K = 0x06,
    REG_RID_OPEN = 0x07,
    REG_RID_MAX  = 0x08,
};

enum {
	D2D_NONE	= 0,
	D2D_SNKONLY,
	D2D_SRCSNK,
};

typedef enum {
	PDO_TYPE_FIXED = 0,
	PDO_TYPE_BATTERY,
	PDO_TYPE_VARIABLE,
	PDO_TYPE_APDO
} pdo_supply_type_t;

enum {
	USBPD_ATTACH,
	USBPD_DETACH,
	USBPD_DEVICE_INFO,
	USBPD_CLEAR_INFO,
};

enum s2m_water_treshold {
	TH_PD_WATER,		//0
	TH_PD_WATER_POST,	//1
	TH_PD_DRY,		//2
	TH_PD_DRY_POST,		//3
	TH_PD_WATER_DELAY,	//4
	TH_PD_WATER_RA,		//5
	TH_PD_GPADC_SHORT,	//6
	TH_PD_GPADC_POWEROFF,	//7
	TH_PM_RWATER,		//8
	TH_PM_VWATER,		//9
	TH_PM_RDRY,		//10
	TH_PM_VDRY,		//11
	TH_PM_DRY_TIMER,	//12
	TH_PM_WATER_DELAY,	//13
	TH_MAX,			//14
};

typedef enum {
	PD_SINK,
	PD_SOURCE,
	PD_DETACH,
	PD_WATER,
	PD_RID,
} PDIC_WATER_POWER_ROLE;

typedef enum {
	WATER_CC_OPEN,
	WATER_CC_RD,
	WATER_CC_DRP,
	WATER_CC_DEFAULT,
}PDIC_WATER_CC_STATUS;

typedef enum {
	PD_WATER_IDLE,
	PD_DRY_IDLE,
	PD_WATER_CHECKING,
	PD_DRY_CHECKING,
	PD_WATER_DEFAULT,
} PDIC_WATER_STATUS;

#define PDIC_OPS_FUNC(func, _data) \
	((pd_data->phy_ops.func) ? \
	 (pd_data->phy_ops.func(_data)) : \
	 (pr_info("%s, %s is not enabled\n", __func__, #func), -1))

#define PDIC_OPS_PARAM_FUNC(func, _data, param) \
	((pd_data->phy_ops.func) ? \
	 (pd_data->phy_ops.func(_data, param)) : \
	 (pr_info("%s, %s is not enabled\n", __func__, #func), -1))

#define PDIC_OPS_PARAM2_FUNC(func, _data, param1, param2) \
	((pd_data->phy_ops.func) ? \
	 (pd_data->phy_ops.func(_data, param1, param2))	: \
	 (pr_info("%s, %s is not enabled\n", __func__, #func), -1))

typedef struct usbpd_phy_ops {
	
	int    (*tx_msg)(void *, msg_header_type *, data_obj_type *);
	int    (*rx_msg)(void *, msg_header_type *, data_obj_type *);
	int    (*hard_reset)(void *);
	void    (*soft_reset)(void *);
	int    (*set_power_role)(void *, int);
	int    (*get_power_role)(void *, int *);
	int    (*set_data_role)(void *, int);
	int    (*get_data_role)(void *, int *);
	int    (*set_vconn_source)(void *, int);
	int    (*get_vconn_source)(void *, int *);
	int    (*set_check_msg_pass)(void *, int);
	unsigned   (*get_status)(void *, u64);
	bool   (*poll_status)(void *);
	void   (*driver_reset)(void *);
	int    (*set_otg_control)(void *, int);
	void    (*get_vbus_short_check)(void *, bool *);
	void    (*pd_vbus_short_check)(void *);
	int    (*set_pd_control)(void *, int);
	void    (*pr_swap)(void *, int);
	int    (*vbus_on_check)(void *);
	int		(*get_side_check)(void *_data);
	int    (*set_rp_control)(void *, int);
	int    (*set_chg_lv_mode)(void *, int);
#if IS_ENABLED(CONFIG_TYPEC)
	void	(*set_pwr_opmode)(void *, int);
#endif
	int    (*pd_instead_of_vbus)(void *, int);
	int    (*op_mode_clear)(void *);
	int    (*get_lpm_mode)(void *);
	void    (*set_lpm_mode)(void *);
	void    (*set_normal_mode)(void *);
	int    (*get_rid)(void *);
	void    (*control_option_command)(void *, int);
#if defined(CONFIG_SEC_FACTORY)
	int    (*power_off_water_check)(void *);
#endif
	int    (*get_water_detect)(void *);
#if IS_ENABLED(CONFIG_PDIC_PD30)
	int    (*get_pps_voltage)(void *);
	void    (*send_hard_reset_dc)(void *);
	void    (*force_pps_disable)(void *);
	void    (*send_psrdy)(void *);
	int    (*pps_enable)(void *, int);
	int    (*get_pps_enable)(void *, int *);
#endif
#if IS_ENABLED(CONFIG_S2MU106_TYPEC_WATER)
	int		(*water_get_power_role)(void *);
	int		(*ops_water_check)(void *);
	int		(*ops_dry_check)(void *);
	void	(*water_opmode)(void *, int );
	int		(*ops_get_is_water_detect)(void *);
	int		(*ops_power_off_water)(void *);
	int		(*ops_prt_water_threshold)(void *, char *);
	void	(*ops_set_water_threshold)(void *, int, int);
#endif
	void	(*energy_now)(void *, int);
	void	(*authentic)(void *);
	void	(*set_usbpd_reset)(void *);
	int		(*ops_get_fsm_state)(void *);
	int		(*get_detach_valid)(void *);
	void	(*rprd_mode_change)(void *, u8);
	void	(*irq_control)(void *, int);
	void	(*set_is_otg_vboost)(void *, int);
	int		(*ops_get_lpm_mode)(void *);
	int		(*ops_get_rid)(void *);
	void	(*ops_control_option_command)(void *, int);
	void	(*ops_sysfs_lpm_mode)(void *, int cmd);
	void	(*set_pcp_clk)(void *, int);

} usbpd_phy_ops_type;

struct policy_data {
	policy_state		state;
	msg_header_type         tx_msg_header;
	msg_header_type		rx_msg_header;
	data_obj_type           tx_data_obj[USBPD_MAX_COUNT_MSG_OBJECT];
	data_obj_type		rx_data_obj[USBPD_MAX_COUNT_MSG_OBJECT];
	bool			rx_hardreset;
	bool			rx_softreset;
	bool			plug;
	bool			plug_valid;
	bool			modal_operation;
	bool			abnormal_state;
	bool			sink_cap_received;
	bool			send_sink_cap;
	bool			txhardresetflag;
	bool			pd_support;
	bool			pps_enable;
	bool			cap_mismatch;
	int				send_reject;
	bool			pd_src_ready;
	bool			got_pps_apdo;
	int				selected_pdo_type;
	int				selected_pdo_num;
	int				requested_pdo_type;
	int				requested_pdo_num;
	int			got_ufp_vdm;
};

struct protocol_data {
	protocol_state		state;
	unsigned		stored_message_id;
	msg_header_type		msg_header;
	data_obj_type		data_obj[USBPD_MAX_COUNT_MSG_OBJECT];
	unsigned		status;
};

struct usbpd_counter {
	unsigned	retry_counter;
	unsigned	message_id_counter;
	unsigned	caps_counter;
	unsigned	hard_reset_counter;
	unsigned	discover_identity_counter;
	unsigned	swap_hard_reset_counter;
};

struct usbpd_manager_data {
	usbpd_manager_command_type cmd;  
	usbpd_manager_event_type   event;    

	msg_header_type		uvdm_msg_header;
	data_obj_type		uvdm_data_obj[USBPD_MAX_COUNT_MSG_OBJECT];

	int alt_sended;
	int vdm_en;
	
	int	max_power;
	int	op_power;
	int	max_current;
	int	op_current;
	int	min_current;
	bool	giveback;
	bool	usb_com_capable;
	bool	no_usb_suspend;

	
	int source_max_volt;
	int source_min_volt;
	int source_max_power;

	
	int sink_max_volt;
	int sink_min_volt;
	int sink_max_power;

	
	int sink_cap_max_volt;

	
	bool power_role_swap;
	
	bool data_role_swap;
	bool vconn_source_swap;
	bool vbus_short;

	bool flash_mode;
	int prev_available_pdo;
	int prev_current_pdo;
	bool ps_rdy;

	bool is_samsung_accessory_enter_mode;
	bool uvdm_first_req;
	bool uvdm_dir;
	struct completion uvdm_out_wait;
	struct completion uvdm_in_wait;

	uint16_t Vendor_ID;
	uint16_t Product_ID;
	uint16_t Device_Version;
	int acc_type;
	uint16_t SVID_0;
	uint16_t SVID_1;
	uint16_t Standard_Vendor_ID;

	struct mutex vdm_mutex;
	struct mutex pdo_mutex;

	struct usbpd_data *pd_data;
	struct delayed_work	acc_detach_handler;
	struct delayed_work select_pdo_handler;
	struct delayed_work start_discover_msg_handler;
	struct delayed_work short_check_work;
	muic_attached_dev_t	attached_dev;

	int pd_attached;
	bool support_vpdo;

	struct delayed_work d2d_work;

	int src_cap_done;
	int auth_type;
	int d2d_type;
	int req_pdo_type;
	bool psrdy_sent;
};

struct usbpd_data {
	struct device		*dev;
	void			*phy_driver_data;
	struct power_supply_desc pdic_desc;
	struct power_supply *psy_pdic;
	struct usbpd_counter	counter;
	struct hrtimer		timers[USBPD_TIMER_MAX_COUNT];
	unsigned                expired_timers;
	usbpd_phy_ops_type	phy_ops;
	struct protocol_data	protocol_tx;
	struct protocol_data	protocol_rx;
	struct policy_data	policy;
	msg_header_type		source_msg_header;
	data_obj_type           source_data_obj[7];
	msg_header_type		sink_msg_header;
	data_obj_type           sink_data_obj[2];
	data_obj_type		source_request_obj;
	data_obj_type		source_get_sink_obj;
	struct usbpd_manager_data	manager;
	struct workqueue_struct *policy_wqueue;
	struct work_struct	worker;
	struct completion	msg_arrived;
	unsigned                wait_for_msg_arrived;
	int					id_matched;

	int					msg_id;
	int					specification_revision;
	struct mutex		accept_mutex;
	int					is_prswap;
	struct timespec64	time_vdm;
	struct timespec64	time1;
	struct timespec64	time2;
	struct timespec64	check_time;

	struct wakeup_source	*policy_wake;
	int					ip_num;
	char				*pmeter_name;

#if IS_ENABLED(CONFIG_BATTERY_SAMSUNG) && IS_ENABLED(CONFIG_USB_TYPEC_MANAGER_NOTIFIER)
	struct pdic_notifier_struct pd_noti;
#endif

#if IS_ENABLED(CONFIG_TYPEC)
	struct typec_port *port;
	struct typec_partner *partner;
	struct usb_pd_identity partner_identity;
	struct typec_capability typec_cap;
	struct completion role_reverse_completion;
	int typec_power_role;
	int typec_data_role;
	int typec_try_state_change;
	struct delayed_work typec_role_swap_work;
#endif
#if IS_ENABLED(CONFIG_PDIC_NOTIFIER)
	ppdic_data_t ppdic_data;
	struct workqueue_struct *pdic_wq;
#endif
};

static inline struct usbpd_data *protocol_rx_to_usbpd(struct protocol_data *rx)
{
	return container_of(rx, struct usbpd_data, protocol_rx);
}

static inline struct usbpd_data *protocol_tx_to_usbpd(struct protocol_data *tx)
{
	return container_of(tx, struct usbpd_data, protocol_tx);
}

static inline struct usbpd_data *policy_to_usbpd(struct policy_data *policy)
{
	return container_of(policy, struct usbpd_data, policy);
}

static inline struct usbpd_data *manager_to_usbpd(struct usbpd_manager_data *manager)
{
	return container_of(manager, struct usbpd_data, manager);
}

extern char *pdo_type_to_str[];

extern int usbpd_init(struct device *dev, void *phy_driver_data);
extern void usbpd_init_policy(struct usbpd_data *);

extern void  usbpd_init_manager_val(struct usbpd_data *);
extern int  usbpd_init_manager(struct usbpd_data *);
extern int usbpd_manager_get_selected_voltage(struct usbpd_data *, int selected_pdo);
extern void usbpd_manager_plug_attach(struct device *, muic_attached_dev_t);
extern void usbpd_manager_plug_detach(struct device *dev, bool notify);
extern void usbpd_manager_acc_detach(struct device *dev);
extern int  usbpd_manager_match_request(struct usbpd_data *);
extern void usbpd_manager_response_req_pdo(struct usbpd_data *pd_data, int req_pdo_type, int req_pdo_num);
extern bool usbpd_manager_power_role_swap(struct usbpd_data *);
extern bool usbpd_manager_vconn_source_swap(struct usbpd_data *);
extern void usbpd_manager_turn_on_source(struct usbpd_data *);
extern void usbpd_manager_turn_off_power_supply(struct usbpd_data *);
extern void usbpd_manager_turn_off_power_sink(struct usbpd_data *);
extern void usbpd_manager_turn_off_vconn(struct usbpd_data *);
extern bool usbpd_manager_data_role_swap(struct usbpd_data *);
extern int usbpd_manager_get_identity(struct usbpd_data *);
extern int usbpd_manager_get_svids(struct usbpd_data *);
extern int usbpd_manager_get_modes(struct usbpd_data *);
extern int usbpd_manager_enter_mode(struct usbpd_data *);
extern int usbpd_manager_exit_mode(struct usbpd_data *, unsigned mode);
extern void usbpd_manager_inform_event(struct usbpd_data *,
		usbpd_manager_event_type);
extern int usbpd_manager_evaluate_capability(struct usbpd_data *);
extern data_obj_type usbpd_manager_select_capability(struct usbpd_data *);
extern bool usbpd_manager_vdm_request_enabled(struct usbpd_data *);
extern void usbpd_manager_acc_handler_cancel(struct device *);
extern void usbpd_manager_acc_detach_handler(struct work_struct *);
extern void usbpd_manager_short_check(struct usbpd_data *pd_data);
extern void usbpd_manager_send_pr_swap(struct device *);
extern void usbpd_manager_send_dr_swap(struct device *);
extern void usbpd_manager_match_sink_cap(struct usbpd_data *);
extern void usbpd_manager_remove_new_cap(struct usbpd_data *);
extern int usbpd_manager_command_to_policy(struct device *dev, usbpd_manager_command_type command);
extern void usbpd_manager_restart_discover_msg(struct usbpd_data *pd_data);
extern int usbpd_manager_psy_init(struct usbpd_data *_data, struct device *parent);
extern void usbpd_manager_vbus_turn_on_ctrl(void *_data, bool enbale);
extern void init_source_cap_data(struct usbpd_manager_data *_data);
extern void usbpd_policy_work(struct work_struct *);
extern void usbpd_protocol_tx(struct usbpd_data *);
extern void usbpd_protocol_rx(struct usbpd_data *);
extern void usbpd_kick_policy_work(struct device *);
extern void usbpd_cancel_policy_work(struct device *);
extern void usbpd_rx_hard_reset(struct device *);
extern void usbpd_rx_soft_reset(struct usbpd_data *);
extern void usbpd_policy_reset(struct usbpd_data *, unsigned flag);

extern void usbpd_set_ops(struct device *, usbpd_phy_ops_type *);
extern void usbpd_read_msg(struct usbpd_data *);
extern bool usbpd_send_msg(struct usbpd_data *, msg_header_type *,
		data_obj_type *);
extern bool usbpd_send_ctrl_msg(struct usbpd_data *d, msg_header_type *h,
		unsigned msg, unsigned dr, unsigned pr);
extern unsigned usbpd_wait_msg(struct usbpd_data *pd_data, unsigned msg_status,
		unsigned ms);
extern void usbpd_reinit(struct device *);
extern void usbpd_init_protocol(struct usbpd_data *);
extern void usbpd_init_counters(struct usbpd_data *);

extern int samsung_uvdm_ready(void);
extern void samsung_uvdm_close(void);
extern int samsung_uvdm_write(void *data, int size);
extern int samsung_uvdm_read(void *data);



void usbpd_timer1_start(struct usbpd_data *pd_data);
long long usbpd_check_time1(struct usbpd_data *pd_data);
void usbpd_timer2_start(struct usbpd_data *pd_data);
long long usbpd_check_time2(struct usbpd_data *pd_data);
void usbpd_timer_vdm_start(struct usbpd_data *pd_data);
long long usbpd_check_timer_vdm(struct usbpd_data *pd_data);

#endif
