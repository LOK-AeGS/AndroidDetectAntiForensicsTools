/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */


#ifndef _LINUX_SYSSTATS_H
#define _LINUX_SYSSTATS_H

#include <linux/types.h>
#include <linux/taskstats.h>
#include <linux/cgroupstats.h>

#define SYSSTATS_VERSION	1


struct sys_memstats {
	__u64	version;
	__u64	memtotal;
	__u64	vmalloc_total;
	__u64	reclaimable;
	__u64	zram_compressed;
	__u64	swap_used;
	__u64	swap_total;
	__u64	unreclaimable;
	__u64	buffer;
	__u64	slab_reclaimable;
	__u64	slab_unreclaimable;
	__u64	free_cma;
	__u64	file_mapped;
	__u64	swapcache;
	__u64	pagetable;
	__u64	kernelstack;
	__u64	shmem;
	__u64	dma_nr_free_pages;
	__u64	dma_nr_active_anon;
	__u64	dma_nr_inactive_anon;
	__u64	dma_nr_active_file;
	__u64	dma_nr_inactive_file;
	__u64	normal_nr_free_pages;
	__u64	normal_nr_active_anon;
	__u64	normal_nr_inactive_anon;
	__u64	normal_nr_active_file;
	__u64	normal_nr_inactive_file;
	__u64	movable_nr_free_pages;
	__u64	movable_nr_active_anon;
	__u64	movable_nr_inactive_anon;
	__u64	movable_nr_active_file;
	__u64	movable_nr_inactive_file;
	__u64	highmem_nr_free_pages;
	__u64	highmem_nr_active_anon;
	__u64	highmem_nr_inactive_anon;
	__u64	highmem_nr_active_file;
	__u64	highmem_nr_inactive_file;
	
};



enum {
	SYSSTATS_CMD_UNSPEC = __CGROUPSTATS_CMD_MAX,	
	SYSSTATS_CMD_GET,		
	SYSSTATS_CMD_NEW,		
};

#define SYSSTATS_CMD_UNSPEC SYSSTATS_CMD_UNSPEC
#define SYSSTATS_CMD_GET SYSSTATS_CMD_GET
#define SYSSTATS_CMD_NEW SYSSTATS_CMD_NEW

enum {
	SYSSTATS_TYPE_UNSPEC = 0,	
	SYSSTATS_TYPE_SYSMEM_STATS,	
};

#define SYSSTATS_TYPE_UNSPEC SYSSTATS_TYPE_UNSPEC
#define SYSSTATS_TYPE_SYSMEM_STATS SYSSTATS_TYPE_SYSMEM_STATS

enum {
	SYSSTATS_CMD_ATTR_UNSPEC = 0,
	SYSSTATS_CMD_ATTR_SYSMEM_STATS,
};

#define SYSSTATS_CMD_ATTR_UNSPEC SYSSTATS_CMD_ATTR_UNSPEC
#define SYSSTATS_CMD_ATTR_SYSMEM_STATS SYSSTATS_CMD_ATTR_SYSMEM_STATS

#endif 
