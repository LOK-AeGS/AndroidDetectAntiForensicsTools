/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _SCSI_SCSI_H
#define _SCSI_SCSI_H

#include <linux/types.h>
#include <linux/scatterlist.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <scsi/scsi_common.h>
#include <scsi/scsi_proto.h>

struct scsi_cmnd;

enum scsi_timeouts {
	SCSI_DEFAULT_EH_TIMEOUT		= 10 * HZ,
};


#define SCSI_MAX_PROT_SG_SEGMENTS	0xFFFF


#define SCAN_WILD_CARD	~0


static inline int scsi_status_is_good(int status)
{
	
	status &= 0xfe;
	return ((status == SAM_STAT_GOOD) ||
		(status == SAM_STAT_CONDITION_MET) ||
		
		(status == SAM_STAT_INTERMEDIATE) ||
		(status == SAM_STAT_INTERMEDIATE_CONDITION_MET) ||
		
		(status == SAM_STAT_COMMAND_TERMINATED));
}




struct ccs_modesel_head {
	__u8 _r1;			
	__u8 medium;		
	__u8 _r2;			
	__u8 block_desc_length;	
	__u8 density;		
	__u8 number_blocks_hi;	
	__u8 number_blocks_med;
	__u8 number_blocks_lo;
	__u8 _r3;
	__u8 block_length_hi;	
	__u8 block_length_med;
	__u8 block_length_lo;
};


#define SCSI_W_LUN_BASE 0xc100
#define SCSI_W_LUN_REPORT_LUNS (SCSI_W_LUN_BASE + 1)
#define SCSI_W_LUN_ACCESS_CONTROL (SCSI_W_LUN_BASE + 2)
#define SCSI_W_LUN_TARGET_LOG_PAGE (SCSI_W_LUN_BASE + 3)

static inline int scsi_is_wlun(u64 lun)
{
	return (lun & 0xff00) == SCSI_W_LUN_BASE;
}




#define COMMAND_COMPLETE    0x00
#define EXTENDED_MESSAGE    0x01
#define     EXTENDED_MODIFY_DATA_POINTER    0x00
#define     EXTENDED_SDTR                   0x01
#define     EXTENDED_EXTENDED_IDENTIFY      0x02    
#define     EXTENDED_WDTR                   0x03
#define     EXTENDED_PPR                    0x04
#define     EXTENDED_MODIFY_BIDI_DATA_PTR   0x05
#define SAVE_POINTERS       0x02
#define RESTORE_POINTERS    0x03
#define DISCONNECT          0x04
#define INITIATOR_ERROR     0x05
#define ABORT_TASK_SET      0x06
#define MESSAGE_REJECT      0x07
#define NOP                 0x08
#define MSG_PARITY_ERROR    0x09
#define LINKED_CMD_COMPLETE 0x0a
#define LINKED_FLG_CMD_COMPLETE 0x0b
#define TARGET_RESET        0x0c
#define ABORT_TASK          0x0d
#define CLEAR_TASK_SET      0x0e
#define INITIATE_RECOVERY   0x0f            
#define RELEASE_RECOVERY    0x10            
#define CLEAR_ACA           0x16
#define LOGICAL_UNIT_RESET  0x17
#define SIMPLE_QUEUE_TAG    0x20
#define HEAD_OF_QUEUE_TAG   0x21
#define ORDERED_QUEUE_TAG   0x22
#define IGNORE_WIDE_RESIDUE 0x23
#define ACA                 0x24
#define QAS_REQUEST         0x55


#define BUS_DEVICE_RESET    TARGET_RESET
#define ABORT               ABORT_TASK_SET



#define DID_OK          0x00	
#define DID_NO_CONNECT  0x01	
#define DID_BUS_BUSY    0x02	
#define DID_TIME_OUT    0x03	
#define DID_BAD_TARGET  0x04	
#define DID_ABORT       0x05	
#define DID_PARITY      0x06	
#define DID_ERROR       0x07	
#define DID_RESET       0x08	
#define DID_BAD_INTR    0x09	
#define DID_PASSTHROUGH 0x0a	
#define DID_SOFT_ERROR  0x0b	
#define DID_IMM_RETRY   0x0c	
#define DID_REQUEUE	0x0d	
#define DID_TRANSPORT_DISRUPTED 0x0e 
#define DID_TRANSPORT_FAILFAST	0x0f 
#define DID_TARGET_FAILURE 0x10 
#define DID_NEXUS_FAILURE 0x11  
#define DID_ALLOC_FAILURE 0x12  
#define DID_MEDIUM_ERROR  0x13  
#define DRIVER_OK       0x00	



#define DRIVER_BUSY         0x01
#define DRIVER_SOFT         0x02
#define DRIVER_MEDIA        0x03
#define DRIVER_ERROR        0x04

#define DRIVER_INVALID      0x05
#define DRIVER_TIMEOUT      0x06
#define DRIVER_HARD         0x07
#define DRIVER_SENSE	    0x08



#define NEEDS_RETRY     0x2001
#define SUCCESS         0x2002
#define FAILED          0x2003
#define QUEUED          0x2004
#define SOFT_ERROR      0x2005
#define ADD_TO_MLQUEUE  0x2006
#define TIMEOUT_ERROR   0x2007
#define SCSI_RETURN_NOT_HANDLED   0x2008
#define FAST_IO_FAIL	0x2009


#define SCSI_MLQUEUE_HOST_BUSY   0x1055
#define SCSI_MLQUEUE_DEVICE_BUSY 0x1056
#define SCSI_MLQUEUE_EH_RETRY    0x1057
#define SCSI_MLQUEUE_TARGET_BUSY 0x1058


#define status_byte(result) (((result) >> 1) & 0x7f)
#define msg_byte(result)    (((result) >> 8) & 0xff)
#define host_byte(result)   (((result) >> 16) & 0xff)
#define driver_byte(result) (((result) >> 24) & 0xff)

#define sense_class(sense)  (((sense) >> 4) & 0x7)
#define sense_error(sense)  ((sense) & 0xf)
#define sense_valid(sense)  ((sense) & 0x80)


#define FORMAT_UNIT_TIMEOUT		(2 * 60 * 60 * HZ)
#define START_STOP_TIMEOUT		(60 * HZ)
#define UFS_START_STOP_TIMEOUT		(10 * HZ)
#define MOVE_MEDIUM_TIMEOUT		(5 * 60 * HZ)
#define READ_ELEMENT_STATUS_TIMEOUT	(5 * 60 * HZ)
#define READ_DEFECT_DATA_TIMEOUT	(60 * HZ )


#define IDENTIFY_BASE       0x80
#define IDENTIFY(can_disconnect, lun)   (IDENTIFY_BASE |\
		     ((can_disconnect) ?  0x40 : 0) |\
		     ((lun) & 0x07))



#define SCSI_UNKNOWN    0
#define SCSI_1          1
#define SCSI_1_CCS      2
#define SCSI_2          3
#define SCSI_3          4        
#define SCSI_SPC_2      5
#define SCSI_SPC_3      6


#define SCSI_INQ_PQ_CON         0x00
#define SCSI_INQ_PQ_NOT_CON     0x01
#define SCSI_INQ_PQ_NOT_CAP     0x03


static inline __u32 scsi_to_u32(__u8 *ptr)
{
	return (ptr[0]<<24) + (ptr[1]<<16) + (ptr[2]<<8) + ptr[3];
}

#endif 
