/* SPDX-License-Identifier: LGPL-2.1 WITH Linux-syscall-note */


#ifndef _LINUX_TASKSTATS_H
#define _LINUX_TASKSTATS_H

#include <linux/types.h>




#define TASKSTATS_VERSION	9
#define TASKSTATS2_VERSION	2
#define TS_COMM_LEN		32	

struct taskstats {

	
	__u16	version;
	__u32	ac_exitcode;		

	
	__u8	ac_flag;		
	__u8	ac_nice;		

	

	
	__u64	cpu_count __attribute__((aligned(8)));
	__u64	cpu_delay_total;

	

	
	__u64	blkio_count;
	__u64	blkio_delay_total;

	
	__u64	swapin_count;
	__u64	swapin_delay_total;

	
	__u64	cpu_run_real_total;

	
	__u64	cpu_run_virtual_total;
	
	

	
	char	ac_comm[TS_COMM_LEN];	
	__u8	ac_sched __attribute__((aligned(8)));
					
	__u8	ac_pad[3];
	__u32	ac_uid __attribute__((aligned(8)));
					
	__u32	ac_gid;			
	__u32	ac_pid;			
	__u32	ac_ppid;		
	__u32	ac_btime;		
	__u64	ac_etime __attribute__((aligned(8)));
					
	__u64	ac_utime;		
	__u64	ac_stime;		
	__u64	ac_minflt;		
	__u64	ac_majflt;		
	

	
	
	__u64	coremem;		
	
	__u64	virtmem;		

	
	__u64	hiwater_rss;		
	__u64	hiwater_vm;		

	
	__u64	read_char;		
	__u64	write_char;		
	__u64	read_syscalls;		
	__u64	write_syscalls;		
	

#define TASKSTATS_HAS_IO_ACCOUNTING
	
	__u64	read_bytes;		
	__u64	write_bytes;		
	__u64	cancelled_write_bytes;	

	__u64  nvcsw;			
	__u64  nivcsw;			

	
	__u64	ac_utimescaled;		
	__u64	ac_stimescaled;		
	__u64	cpu_scaled_run_real_total; 

	
	__u64	freepages_count;
	__u64	freepages_delay_total;

	
	__u64	thrashing_count;
	__u64	thrashing_delay_total;
};

struct taskstats2 {
	__u16 version;
	__s16 oom_score;
	__u32 pid;
	__u64 anon_rss;	
	__u64 file_rss;	
	__u64 swap_rss;	
	__u64 shmem_rss;	
	__u64 unreclaimable;	
	

	
	__u64	utime;		
	__u64	stime;		
	__u64	cutime;		
	__u64	cstime;		

	__u32	uid __attribute__((aligned(8)));
					
	__u32	ppid;  
	char	name[TS_COMM_LEN];  
	char    state[TS_COMM_LEN]; 
	

};



enum {
	TASKSTATS_CMD_UNSPEC = 0,	
	TASKSTATS_CMD_GET,		
	TASKSTATS_CMD_NEW,		
	TASKSTATS2_CMD_GET,		
	__TASKSTATS_CMD_MAX,
};

#define TASKSTATS_CMD_MAX (__TASKSTATS_CMD_MAX - 1)

enum {
	TASKSTATS_TYPE_UNSPEC = 0,	
	TASKSTATS_TYPE_PID,		
	TASKSTATS_TYPE_TGID,		
	TASKSTATS_TYPE_STATS,		
	TASKSTATS_TYPE_AGGR_PID,	
	TASKSTATS_TYPE_AGGR_TGID,	
	TASKSTATS_TYPE_NULL,		
	TASKSTATS_TYPE_FOREACH,		
	__TASKSTATS_TYPE_MAX,
};

#define TASKSTATS_TYPE_MAX (__TASKSTATS_TYPE_MAX - 1)

enum {
	TASKSTATS_CMD_ATTR_UNSPEC = 0,
	TASKSTATS_CMD_ATTR_PID,
	TASKSTATS_CMD_ATTR_TGID,
	TASKSTATS_CMD_ATTR_REGISTER_CPUMASK,
	TASKSTATS_CMD_ATTR_DEREGISTER_CPUMASK,
	TASKSTATS_CMD_ATTR_FOREACH,
	__TASKSTATS_CMD_ATTR_MAX,
};

#define TASKSTATS_CMD_ATTR_MAX (__TASKSTATS_CMD_ATTR_MAX - 1)



#define TASKSTATS_GENL_NAME	"TASKSTATS"
#define TASKSTATS_GENL_VERSION	0x1

#endif 
