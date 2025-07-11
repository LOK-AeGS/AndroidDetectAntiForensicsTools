/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef _UAPI_LINUX_INCREMENTALFS_H
#define _UAPI_LINUX_INCREMENTALFS_H

#include <linux/limits.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/xattr.h>


#define INCFS_NAME "incremental-fs"
#define INCFS_MAGIC_NUMBER (0x5346434e49ul)
#define INCFS_DATA_FILE_BLOCK_SIZE 4096
#define INCFS_HEADER_VER 1


#define INCFS_MAX_HASH_SIZE 32
#define INCFS_MAX_FILE_ATTR_SIZE 512

#define INCFS_PENDING_READS_FILENAME ".pending_reads"
#define INCFS_LOG_FILENAME ".log"
#define INCFS_XATTR_ID_NAME (XATTR_USER_PREFIX "incfs.id")
#define INCFS_XATTR_SIZE_NAME (XATTR_USER_PREFIX "incfs.size")
#define INCFS_XATTR_METADATA_NAME (XATTR_USER_PREFIX "incfs.metadata")

#define INCFS_MAX_SIGNATURE_SIZE 8096
#define INCFS_SIGNATURE_VERSION 2
#define INCFS_SIGNATURE_SECTIONS 2

#define INCFS_IOCTL_BASE_CODE 'g'




#define INCFS_IOC_CREATE_FILE \
	_IOWR(INCFS_IOCTL_BASE_CODE, 30, struct incfs_new_file_args)


#define INCFS_IOC_READ_FILE_SIGNATURE                                          \
	_IOR(INCFS_IOCTL_BASE_CODE, 31, struct incfs_get_file_sig_args)


#define INCFS_IOC_FILL_BLOCKS                                                  \
	_IOR(INCFS_IOCTL_BASE_CODE, 32, struct incfs_fill_blocks)


#define INCFS_IOC_PERMIT_FILL                                                  \
	_IOW(INCFS_IOCTL_BASE_CODE, 33, struct incfs_permit_fill)


#define INCFS_IOC_GET_FILLED_BLOCKS                                            \
	_IOR(INCFS_IOCTL_BASE_CODE, 34, struct incfs_get_filled_blocks_args)

enum incfs_compression_alg {
	COMPRESSION_NONE = 0,
	COMPRESSION_LZ4 = 1
};

enum incfs_block_flags {
	INCFS_BLOCK_FLAGS_NONE = 0,
	INCFS_BLOCK_FLAGS_HASH = 1,
};

typedef struct {
	__u8 bytes[16];
} incfs_uuid_t __attribute__((aligned (8)));


struct incfs_pending_read_info {
	
	incfs_uuid_t file_id;

	
	__aligned_u64 timestamp_us;

	
	__u32 block_index;

	
	__u32 serial_number;
};


struct incfs_fill_block {
	
	__u32 block_index;

	
	__u32 data_len;

	
	__aligned_u64 data;

	
	__u8 compression;

	
	__u8 flags;

	__u16 reserved1;

	__u32 reserved2;

	__aligned_u64 reserved3;
};


struct incfs_fill_blocks {
	
	__u64 count;

	
	__aligned_u64 fill_blocks;
};


struct incfs_permit_fill {
	
	__u32 file_descriptor;
};

enum incfs_hash_tree_algorithm {
	INCFS_HASH_TREE_NONE = 0,
	INCFS_HASH_TREE_SHA256 = 1
};


struct incfs_new_file_args {
	
	incfs_uuid_t file_id;

	
	__aligned_u64 size;

	
	__u16 mode;

	__u16 reserved1;

	__u32 reserved2;

	
	__aligned_u64 directory_path;

	
	__aligned_u64 file_name;

	
	__aligned_u64 file_attr;

	
	__u32 file_attr_len;

	__u32 reserved4;

	
	__aligned_u64 signature_info;

	
	__aligned_u64 signature_size;

	__aligned_u64 reserved6;
};


struct incfs_get_file_sig_args {
	
	__aligned_u64 file_signature;

	
	__u32 file_signature_buf_size;

	
	__u32 file_signature_len_out;
};

struct incfs_filled_range {
	__u32 begin;
	__u32 end;
};


struct incfs_get_filled_blocks_args {
	
	__aligned_u64 range_buffer;

	
	__u32 range_buffer_size;

	
	__u32 start_index;

	
	__u32 end_index;

	
	__u32 total_blocks_out;

	
	__u32 data_blocks_out;

	
	__u32 range_buffer_size_out;

	
	__u32 index_out;
};

#endif 
