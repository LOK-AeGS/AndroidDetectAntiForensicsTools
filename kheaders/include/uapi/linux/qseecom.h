/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */


#ifndef _UAPI_QSEECOM_H_
#define _UAPI_QSEECOM_H_

#include <linux/types.h>
#include <linux/ioctl.h>

#define MAX_ION_FD  4
#define MAX_APP_NAME_SIZE  64
#define QSEECOM_HASH_SIZE  32


#define QSEECOM_TA_ION_ALLOCATE_DELAY           50
#define QSEECOM_TA_ION_ALLOCATE_MAX_ATTEMP      20

#define ICE_KEY_SIZE 32
#define ICE_SALT_SIZE 32


struct qseecom_register_listener_req {
	uint32_t listener_id; 
	int32_t ifd_data_fd; 
	void *virt_sb_base; 
	uint32_t sb_size; 
};


struct qseecom_send_cmd_req {
	void *cmd_req_buf; 
	unsigned int cmd_req_len; 
	void *resp_buf; 
	unsigned int resp_len; 
};


struct qseecom_ion_fd_info {
	int32_t fd;
	uint32_t cmd_buf_offset;
};

struct qseecom_send_modfd_cmd_req {
	void *cmd_req_buf; 
	unsigned int cmd_req_len; 
	void *resp_buf; 
	unsigned int resp_len; 
	struct qseecom_ion_fd_info ifd_data[MAX_ION_FD];
};


struct qseecom_send_resp_req {
	void *resp_buf; 
	unsigned int resp_len; 
};


struct qseecom_load_img_req {
	uint32_t mdt_len; 
	uint32_t img_len; 
	int32_t  ifd_data_fd; 
	char	 img_name[MAX_APP_NAME_SIZE]; 
	uint32_t app_arch; 
	uint32_t app_id; 
};

struct qseecom_set_sb_mem_param_req {
	int32_t ifd_data_fd; 
	void *virt_sb_base; 
	uint32_t sb_len; 
};


struct qseecom_qseos_version_req {
	unsigned int qseos_version; 
};


struct qseecom_qseos_app_load_query {
	char app_name[MAX_APP_NAME_SIZE]; 
	uint32_t app_id; 
	uint32_t app_arch;
};

struct qseecom_send_svc_cmd_req {
	uint32_t cmd_id;
	void *cmd_req_buf; 
	unsigned int cmd_req_len; 
	void *resp_buf; 
	unsigned int resp_len; 
};

enum qseecom_key_management_usage_type {
	QSEOS_KM_USAGE_DISK_ENCRYPTION = 0x01,
	QSEOS_KM_USAGE_FILE_ENCRYPTION = 0x02,
	QSEOS_KM_USAGE_UFS_ICE_DISK_ENCRYPTION = 0x03,
	QSEOS_KM_USAGE_SDCC_ICE_DISK_ENCRYPTION = 0x04,
	QSEOS_KM_USAGE_MAX
};

struct qseecom_create_key_req {
	unsigned char hash32[QSEECOM_HASH_SIZE];
	enum qseecom_key_management_usage_type usage;
};

struct qseecom_wipe_key_req {
	enum qseecom_key_management_usage_type usage;
	int wipe_key_flag;
			  
};

struct qseecom_update_key_userinfo_req {
	unsigned char current_hash32[QSEECOM_HASH_SIZE];
	unsigned char new_hash32[QSEECOM_HASH_SIZE];
	enum qseecom_key_management_usage_type usage;
};

#define SHA256_DIGEST_LENGTH	(256/8)

struct qseecom_save_partition_hash_req {
	int partition_id; 
	char digest[SHA256_DIGEST_LENGTH]; 
};


struct qseecom_is_es_activated_req {
	int is_activated; 
};


struct qseecom_mdtp_cipher_dip_req {
	uint8_t *in_buf;
	uint32_t in_buf_size;
	uint8_t *out_buf;
	uint32_t out_buf_size;
	uint32_t direction;
};

enum qseecom_bandwidth_request_mode {
	INACTIVE = 0,
	LOW,
	MEDIUM,
	HIGH,
};


struct qseecom_send_modfd_listener_resp {
	void *resp_buf_ptr; 
	unsigned int resp_len; 
	struct qseecom_ion_fd_info ifd_data[MAX_ION_FD]; 
};

struct qseecom_qteec_req {
	void    *req_ptr;
	uint32_t    req_len;
	void    *resp_ptr;
	uint32_t    resp_len;
};

struct qseecom_qteec_modfd_req {
	void    *req_ptr;
	uint32_t    req_len;
	void    *resp_ptr;
	uint32_t    resp_len;
	struct qseecom_ion_fd_info ifd_data[MAX_ION_FD];
};

struct qseecom_sg_entry {
	uint32_t phys_addr;
	uint32_t len;
};

struct qseecom_sg_entry_64bit {
	uint64_t phys_addr;
	uint32_t len;
} __attribute__ ((packed));


#define QSEECOM_SG_LIST_BUF_FORMAT_VERSION_1	1
#define QSEECOM_SG_LIST_BUF_FORMAT_VERSION_2	2

struct qseecom_sg_list_buf_hdr_64bit {
	struct qseecom_sg_entry_64bit  blank_entry;	
	uint32_t version;		
	uint64_t new_buf_phys_addr;	
	uint32_t nents_total;		
} __attribute__ ((packed));

#define QSEECOM_SG_LIST_BUF_HDR_SZ_64BIT	\
			sizeof(struct qseecom_sg_list_buf_hdr_64bit)

#define MAX_CE_PIPE_PAIR_PER_UNIT 3
#define INVALID_CE_INFO_UNIT_NUM 0xffffffff

#define CE_PIPE_PAIR_USE_TYPE_FDE 0
#define CE_PIPE_PAIR_USE_TYPE_PFE 1

struct qseecom_ce_pipe_entry {
	int valid;
	unsigned int ce_num;
	unsigned int ce_pipe_pair;
};

struct qseecom_ice_data_t {
	int flag;
};

#define MAX_CE_INFO_HANDLE_SIZE 32
struct qseecom_ce_info_req {
	unsigned char handle[MAX_CE_INFO_HANDLE_SIZE];
	unsigned int usage;
	unsigned int unit_num;
	unsigned int num_ce_pipe_entries;
	struct qseecom_ce_pipe_entry ce_pipe_entry[MAX_CE_PIPE_PAIR_PER_UNIT];
};

struct qseecom_ice_key_data_t {
	uint8_t key[ICE_KEY_SIZE];
	uint32_t key_len;
	uint8_t salt[ICE_SALT_SIZE];
	uint32_t salt_len;
};

#define SG_ENTRY_SZ		sizeof(struct qseecom_sg_entry)
#define SG_ENTRY_SZ_64BIT	sizeof(struct qseecom_sg_entry_64bit)

struct file;


#define QSEECOM_IOC_MAGIC    0x97


#define QSEECOM_IOCTL_REGISTER_LISTENER_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 1, struct qseecom_register_listener_req)

#define QSEECOM_IOCTL_UNREGISTER_LISTENER_REQ \
	_IO(QSEECOM_IOC_MAGIC, 2)

#define QSEECOM_IOCTL_SEND_CMD_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 3, struct qseecom_send_cmd_req)

#define QSEECOM_IOCTL_SEND_MODFD_CMD_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 4, struct qseecom_send_modfd_cmd_req)

#define QSEECOM_IOCTL_RECEIVE_REQ \
	_IO(QSEECOM_IOC_MAGIC, 5)

#define QSEECOM_IOCTL_SEND_RESP_REQ \
	_IO(QSEECOM_IOC_MAGIC, 6)

#define QSEECOM_IOCTL_LOAD_APP_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 7, struct qseecom_load_img_req)

#define QSEECOM_IOCTL_SET_MEM_PARAM_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 8, struct qseecom_set_sb_mem_param_req)

#define QSEECOM_IOCTL_UNLOAD_APP_REQ \
	_IO(QSEECOM_IOC_MAGIC, 9)

#define QSEECOM_IOCTL_GET_QSEOS_VERSION_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 10, struct qseecom_qseos_version_req)

#define QSEECOM_IOCTL_PERF_ENABLE_REQ \
	_IO(QSEECOM_IOC_MAGIC, 11)

#define QSEECOM_IOCTL_PERF_DISABLE_REQ \
	_IO(QSEECOM_IOC_MAGIC, 12)

#define QSEECOM_IOCTL_LOAD_EXTERNAL_ELF_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 13, struct qseecom_load_img_req)

#define QSEECOM_IOCTL_UNLOAD_EXTERNAL_ELF_REQ \
	_IO(QSEECOM_IOC_MAGIC, 14)

#define QSEECOM_IOCTL_APP_LOADED_QUERY_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 15, struct qseecom_qseos_app_load_query)

#define QSEECOM_IOCTL_SEND_CMD_SERVICE_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 16, struct qseecom_send_svc_cmd_req)

#define QSEECOM_IOCTL_CREATE_KEY_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 17, struct qseecom_create_key_req)

#define QSEECOM_IOCTL_WIPE_KEY_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 18, struct qseecom_wipe_key_req)

#define QSEECOM_IOCTL_SAVE_PARTITION_HASH_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 19, struct qseecom_save_partition_hash_req)

#define QSEECOM_IOCTL_IS_ES_ACTIVATED_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 20, struct qseecom_is_es_activated_req)

#define QSEECOM_IOCTL_SEND_MODFD_RESP \
	_IOWR(QSEECOM_IOC_MAGIC, 21, struct qseecom_send_modfd_listener_resp)

#define QSEECOM_IOCTL_SET_BUS_SCALING_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 23, int)

#define QSEECOM_IOCTL_UPDATE_KEY_USER_INFO_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 24, struct qseecom_update_key_userinfo_req)

#define QSEECOM_QTEEC_IOCTL_OPEN_SESSION_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 30, struct qseecom_qteec_modfd_req)

#define QSEECOM_QTEEC_IOCTL_CLOSE_SESSION_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 31, struct qseecom_qteec_req)

#define QSEECOM_QTEEC_IOCTL_INVOKE_MODFD_CMD_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 32, struct qseecom_qteec_modfd_req)

#define QSEECOM_QTEEC_IOCTL_REQUEST_CANCELLATION_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 33, struct qseecom_qteec_modfd_req)

#define QSEECOM_IOCTL_MDTP_CIPHER_DIP_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 34, struct qseecom_mdtp_cipher_dip_req)

#define QSEECOM_IOCTL_SEND_MODFD_CMD_64_REQ \
	_IOWR(QSEECOM_IOC_MAGIC, 35, struct qseecom_send_modfd_cmd_req)

#define QSEECOM_IOCTL_SEND_MODFD_RESP_64 \
	_IOWR(QSEECOM_IOC_MAGIC, 36, struct qseecom_send_modfd_listener_resp)

#define QSEECOM_IOCTL_GET_CE_PIPE_INFO \
	_IOWR(QSEECOM_IOC_MAGIC, 40, struct qseecom_ce_info_req)

#define QSEECOM_IOCTL_FREE_CE_PIPE_INFO \
	_IOWR(QSEECOM_IOC_MAGIC, 41, struct qseecom_ce_info_req)

#define QSEECOM_IOCTL_QUERY_CE_PIPE_INFO \
	_IOWR(QSEECOM_IOC_MAGIC, 42, struct qseecom_ce_info_req)

#define QSEECOM_IOCTL_SET_ICE_INFO \
	_IOWR(QSEECOM_IOC_MAGIC, 43, struct qseecom_ice_data_t)

#define QSEECOM_IOCTL_FBE_CLEAR_KEY \
	_IOWR(QSEECOM_IOC_MAGIC, 44, struct qseecom_ice_key_data_t)

#endif 
