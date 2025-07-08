

#define VSERVICE_CORE_PROTOCOL_NAME "com.ok-labs.core"
#define VSERVICE_CORE_PARAM_SIZE_SERVICE_INFO__PROTOCOL_NAME 32
#define VSERVICE_CORE_PARAM_SIZE_SERVICE_INFO__SERVICE_NAME 16


typedef enum {
	
	
	VSERVICE_CORE_MSG_STARTUP,

	
	VSERVICE_CORE_MSG_SHUTDOWN,

	
	VSERVICE_CORE_REQ_CONNECT,
	VSERVICE_CORE_ACK_CONNECT,
	VSERVICE_CORE_NACK_CONNECT,

	
	VSERVICE_CORE_REQ_DISCONNECT,
	VSERVICE_CORE_ACK_DISCONNECT,
	VSERVICE_CORE_NACK_DISCONNECT,

	
	VSERVICE_CORE_REQ_SERVICE_COUNT,
	VSERVICE_CORE_ACK_SERVICE_COUNT,
	VSERVICE_CORE_NACK_SERVICE_COUNT,

	
	VSERVICE_CORE_REQ_SERVICE_INFO,
	VSERVICE_CORE_ACK_SERVICE_INFO,
	VSERVICE_CORE_NACK_SERVICE_INFO,

	
	VSERVICE_CORE_MSG_SERVICE_RESET,

	
	VSERVICE_CORE_MSG_SERVICE_READY,

	
	VSERVICE_CORE_MSG_NOTIFICATION_BITS_INFO,

} vservice_core_message_id_t;




typedef enum {
	
	

	VSERVICE_CORE_NBIT_IN__COUNT = 0,
} vservice_core_nbit_in_t;





typedef enum {
	
	
	VSERVICE_CORE_NBIT_OUT_REENUMERATE = 0,

	VSERVICE_CORE_NBIT_OUT__COUNT,
} vservice_core_nbit_out_t;


#define VSERVICE_CORE_NMASK_OUT_REENUMERATE \
		(1 << VSERVICE_CORE_NBIT_OUT_REENUMERATE)


typedef enum {
	
	VSERVICE_CORE_STATE_OFFLINE = 0,

	
	VSERVICE_CORE_STATE_DISCONNECTED,
	VSERVICE_CORE_STATE_DISCONNECTED__CONNECT,

	
	VSERVICE_CORE_STATE_CONNECTED,
	VSERVICE_CORE_STATE_CONNECTED__DISCONNECT,

	
	VSERVICE_CORE_STATE__RESET = VSERVICE_CORE_STATE_OFFLINE,
} vservice_core_statenum_t;

typedef struct {
	vservice_core_statenum_t statenum;
	bool pending_service_count;
	unsigned pending_service_info;
} vservice_core_state_t;

#define VSERVICE_CORE_RESET_STATE (vservice_core_state_t) { \
	.statenum = VSERVICE_CORE_STATE__RESET, \
	.pending_service_count = false, \
	.pending_service_info = 0 }

#define VSERVICE_CORE_STATE_IS_OFFLINE(state) ( \
	((state).statenum == VSERVICE_CORE_STATE_OFFLINE))
#define VSERVICE_CORE_STATE_IS_DISCONNECTED(state) ( \
	((state).statenum == VSERVICE_CORE_STATE_DISCONNECTED) || \
	((state).statenum == VSERVICE_CORE_STATE_DISCONNECTED__CONNECT))
#define VSERVICE_CORE_STATE_IS_CONNECTED(state) ( \
	((state).statenum == VSERVICE_CORE_STATE_CONNECTED) || \
	((state).statenum == VSERVICE_CORE_STATE_CONNECTED__DISCONNECT))

#define VSERVICE_CORE_STATE_VALID(state) \
	VSERVICE_CORE_STATE_IS_OFFLINE(state) ? ( \
		((state).pending_service_count == false) && \
		((state).pending_service_info == 0)) : \
	VSERVICE_CORE_STATE_IS_DISCONNECTED(state) ? ( \
		((state).pending_service_count == false) && \
		((state).pending_service_info == 0)) : \
	VSERVICE_CORE_STATE_IS_CONNECTED(state) ? true : \
	false)
