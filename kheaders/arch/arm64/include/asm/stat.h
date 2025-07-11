
#ifndef __ASM_STAT_H
#define __ASM_STAT_H

#include <uapi/asm/stat.h>

#ifdef CONFIG_COMPAT

#include <linux/compat_time.h>
#include <asm/compat.h>


struct stat64 {
	compat_u64	st_dev;
	unsigned char   __pad0[4];

#define STAT64_HAS_BROKEN_ST_INO	1
	compat_ulong_t	__st_ino;
	compat_uint_t	st_mode;
	compat_uint_t	st_nlink;

	compat_ulong_t	st_uid;
	compat_ulong_t	st_gid;

	compat_u64	st_rdev;
	unsigned char   __pad3[4];

	compat_s64	st_size;
	compat_ulong_t	st_blksize;
	compat_u64	st_blocks;	

	compat_ulong_t	st_atime;
	compat_ulong_t	st_atime_nsec;

	compat_ulong_t	st_mtime;
	compat_ulong_t	st_mtime_nsec;

	compat_ulong_t	st_ctime;
	compat_ulong_t	st_ctime_nsec;

	compat_u64	st_ino;
};

#endif
#endif
