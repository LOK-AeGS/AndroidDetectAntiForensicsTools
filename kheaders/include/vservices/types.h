

#ifndef _VSERVICE_TYPES_H
#define _VSERVICE_TYPES_H

#include <linux/types.h>

typedef u16 vs_service_id_t;
typedef u16 vs_message_id_t;


typedef struct vservice_queued_request vservice_queued_request_t;


typedef enum vs_server_response_type {
	VS_SERVER_RESP_SUCCESS,
	VS_SERVER_RESP_FAILURE,
	VS_SERVER_RESP_EXPLICIT_COMPLETE
} vs_server_response_type_t;

#endif 
