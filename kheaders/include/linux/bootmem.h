/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _LINUX_BOOTMEM_H
#define _LINUX_BOOTMEM_H

#include <linux/mmzone.h>
#include <linux/mm_types.h>
#include <asm/dma.h>
#include <asm/processor.h>
#include <linux/memblock.h>



extern unsigned long max_low_pfn;
extern unsigned long min_low_pfn;


extern unsigned long max_pfn;

extern unsigned long long max_possible_pfn;

#ifndef CONFIG_NO_BOOTMEM

typedef struct bootmem_data {
	unsigned long node_min_pfn;
	unsigned long node_low_pfn;
	void *node_bootmem_map;
	unsigned long last_end_off;
	unsigned long hint_idx;
	struct list_head list;
} bootmem_data_t;

extern bootmem_data_t bootmem_node_data[];
#endif

extern unsigned long bootmem_bootmap_pages(unsigned long);

extern unsigned long init_bootmem_node(pg_data_t *pgdat,
				       unsigned long freepfn,
				       unsigned long startpfn,
				       unsigned long endpfn);
extern unsigned long init_bootmem(unsigned long addr, unsigned long memend);

extern unsigned long free_all_bootmem(void);
extern void reset_node_managed_pages(pg_data_t *pgdat);
extern void reset_all_zones_managed_pages(void);

extern void free_bootmem_node(pg_data_t *pgdat,
			      unsigned long addr,
			      unsigned long size);
extern void free_bootmem(unsigned long physaddr, unsigned long size);
extern void free_bootmem_late(unsigned long physaddr, unsigned long size);


#define BOOTMEM_DEFAULT		0
#define BOOTMEM_EXCLUSIVE	(1<<0)

extern int reserve_bootmem(unsigned long addr,
			   unsigned long size,
			   int flags);
extern int reserve_bootmem_node(pg_data_t *pgdat,
				unsigned long physaddr,
				unsigned long size,
				int flags);

extern void *__alloc_bootmem(unsigned long size,
			     unsigned long align,
			     unsigned long goal);
extern void *__alloc_bootmem_nopanic(unsigned long size,
				     unsigned long align,
				     unsigned long goal) __malloc;
extern void *__alloc_bootmem_node(pg_data_t *pgdat,
				  unsigned long size,
				  unsigned long align,
				  unsigned long goal) __malloc;
void *__alloc_bootmem_node_high(pg_data_t *pgdat,
				  unsigned long size,
				  unsigned long align,
				  unsigned long goal) __malloc;
extern void *__alloc_bootmem_node_nopanic(pg_data_t *pgdat,
				  unsigned long size,
				  unsigned long align,
				  unsigned long goal) __malloc;
void *___alloc_bootmem_node_nopanic(pg_data_t *pgdat,
				  unsigned long size,
				  unsigned long align,
				  unsigned long goal,
				  unsigned long limit) __malloc;
extern void *__alloc_bootmem_low(unsigned long size,
				 unsigned long align,
				 unsigned long goal) __malloc;
void *__alloc_bootmem_low_nopanic(unsigned long size,
				 unsigned long align,
				 unsigned long goal) __malloc;
extern void *__alloc_bootmem_low_node(pg_data_t *pgdat,
				      unsigned long size,
				      unsigned long align,
				      unsigned long goal) __malloc;

#ifdef CONFIG_NO_BOOTMEM

#define BOOTMEM_LOW_LIMIT 0
#else
#define BOOTMEM_LOW_LIMIT __pa(MAX_DMA_ADDRESS)
#endif

#ifndef ARCH_LOW_ADDRESS_LIMIT
#define ARCH_LOW_ADDRESS_LIMIT  0xffffffffUL
#endif

#define alloc_bootmem(x) \
	__alloc_bootmem(x, SMP_CACHE_BYTES, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_align(x, align) \
	__alloc_bootmem(x, align, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_nopanic(x) \
	__alloc_bootmem_nopanic(x, SMP_CACHE_BYTES, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_pages(x) \
	__alloc_bootmem(x, PAGE_SIZE, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_pages_nopanic(x) \
	__alloc_bootmem_nopanic(x, PAGE_SIZE, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_node(pgdat, x) \
	__alloc_bootmem_node(pgdat, x, SMP_CACHE_BYTES, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_node_nopanic(pgdat, x) \
	__alloc_bootmem_node_nopanic(pgdat, x, SMP_CACHE_BYTES, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_pages_node(pgdat, x) \
	__alloc_bootmem_node(pgdat, x, PAGE_SIZE, BOOTMEM_LOW_LIMIT)
#define alloc_bootmem_pages_node_nopanic(pgdat, x) \
	__alloc_bootmem_node_nopanic(pgdat, x, PAGE_SIZE, BOOTMEM_LOW_LIMIT)

#define alloc_bootmem_low(x) \
	__alloc_bootmem_low(x, SMP_CACHE_BYTES, 0)
#define alloc_bootmem_low_pages_nopanic(x) \
	__alloc_bootmem_low_nopanic(x, PAGE_SIZE, 0)
#define alloc_bootmem_low_pages(x) \
	__alloc_bootmem_low(x, PAGE_SIZE, 0)
#define alloc_bootmem_low_pages_node(pgdat, x) \
	__alloc_bootmem_low_node(pgdat, x, PAGE_SIZE, 0)


#if defined(CONFIG_HAVE_MEMBLOCK) && defined(CONFIG_NO_BOOTMEM)


#define BOOTMEM_ALLOC_ACCESSIBLE	0
#define BOOTMEM_ALLOC_ANYWHERE		(~(phys_addr_t)0)


void *memblock_virt_alloc_try_nid_raw(phys_addr_t size, phys_addr_t align,
				      phys_addr_t min_addr,
				      phys_addr_t max_addr, int nid);
void *memblock_virt_alloc_try_nid_nopanic(phys_addr_t size,
		phys_addr_t align, phys_addr_t min_addr,
		phys_addr_t max_addr, int nid);
void *memblock_virt_alloc_try_nid(phys_addr_t size, phys_addr_t align,
		phys_addr_t min_addr, phys_addr_t max_addr, int nid);
void __memblock_free_early(phys_addr_t base, phys_addr_t size);
void __memblock_free_late(phys_addr_t base, phys_addr_t size);

static inline void * __init memblock_virt_alloc(
					phys_addr_t size,  phys_addr_t align)
{
	memblock_dbg("%s: %llu bytes align=0x%llx %pS\n",
			__func__, (u64)size, (u64)align, (void *)_RET_IP_);

	return memblock_virt_alloc_try_nid(size, align, BOOTMEM_LOW_LIMIT,
					    BOOTMEM_ALLOC_ACCESSIBLE,
					    NUMA_NO_NODE);
}

static inline void * __init memblock_virt_alloc_raw(
					phys_addr_t size,  phys_addr_t align)
{
	return memblock_virt_alloc_try_nid_raw(size, align, BOOTMEM_LOW_LIMIT,
					    BOOTMEM_ALLOC_ACCESSIBLE,
					    NUMA_NO_NODE);
}

static inline void * __init memblock_virt_alloc_nopanic(
					phys_addr_t size, phys_addr_t align)
{
	return memblock_virt_alloc_try_nid_nopanic(size, align,
						    BOOTMEM_LOW_LIMIT,
						    BOOTMEM_ALLOC_ACCESSIBLE,
						    NUMA_NO_NODE);
}

static inline void * __init memblock_virt_alloc_low(
					phys_addr_t size, phys_addr_t align)
{
	return memblock_virt_alloc_try_nid(size, align,
						   BOOTMEM_LOW_LIMIT,
						   ARCH_LOW_ADDRESS_LIMIT,
						   NUMA_NO_NODE);
}
static inline void * __init memblock_virt_alloc_low_nopanic(
					phys_addr_t size, phys_addr_t align)
{
	return memblock_virt_alloc_try_nid_nopanic(size, align,
						   BOOTMEM_LOW_LIMIT,
						   ARCH_LOW_ADDRESS_LIMIT,
						   NUMA_NO_NODE);
}

static inline void * __init memblock_virt_alloc_from_nopanic(
		phys_addr_t size, phys_addr_t align, phys_addr_t min_addr)
{
	return memblock_virt_alloc_try_nid_nopanic(size, align, min_addr,
						    BOOTMEM_ALLOC_ACCESSIBLE,
						    NUMA_NO_NODE);
}

static inline void * __init memblock_virt_alloc_node(
						phys_addr_t size, int nid)
{
	return memblock_virt_alloc_try_nid(size, 0, BOOTMEM_LOW_LIMIT,
					    BOOTMEM_ALLOC_ACCESSIBLE, nid);
}

static inline void * __init memblock_virt_alloc_node_nopanic(
						phys_addr_t size, int nid)
{
	return memblock_virt_alloc_try_nid_nopanic(size, 0, BOOTMEM_LOW_LIMIT,
						    BOOTMEM_ALLOC_ACCESSIBLE,
						    nid);
}

static inline void __init memblock_free_early(
					phys_addr_t base, phys_addr_t size)
{
	__memblock_free_early(base, size);
}

static inline void __init memblock_free_early_nid(
				phys_addr_t base, phys_addr_t size, int nid)
{
	__memblock_free_early(base, size);
}

static inline void __init memblock_free_late(
					phys_addr_t base, phys_addr_t size)
{
	__memblock_free_late(base, size);
}

#else

#define BOOTMEM_ALLOC_ACCESSIBLE	0



static inline void * __init memblock_virt_alloc(
					phys_addr_t size,  phys_addr_t align)
{
	if (!align)
		align = SMP_CACHE_BYTES;
	return __alloc_bootmem(size, align, BOOTMEM_LOW_LIMIT);
}

static inline void * __init memblock_virt_alloc_raw(
					phys_addr_t size,  phys_addr_t align)
{
	if (!align)
		align = SMP_CACHE_BYTES;
	return __alloc_bootmem_nopanic(size, align, BOOTMEM_LOW_LIMIT);
}

static inline void * __init memblock_virt_alloc_nopanic(
					phys_addr_t size, phys_addr_t align)
{
	if (!align)
		align = SMP_CACHE_BYTES;
	return __alloc_bootmem_nopanic(size, align, BOOTMEM_LOW_LIMIT);
}

static inline void * __init memblock_virt_alloc_low(
					phys_addr_t size, phys_addr_t align)
{
	if (!align)
		align = SMP_CACHE_BYTES;
	return __alloc_bootmem_low(size, align, 0);
}

static inline void * __init memblock_virt_alloc_low_nopanic(
					phys_addr_t size, phys_addr_t align)
{
	if (!align)
		align = SMP_CACHE_BYTES;
	return __alloc_bootmem_low_nopanic(size, align, 0);
}

static inline void * __init memblock_virt_alloc_from_nopanic(
		phys_addr_t size, phys_addr_t align, phys_addr_t min_addr)
{
	return __alloc_bootmem_nopanic(size, align, min_addr);
}

static inline void * __init memblock_virt_alloc_node(
						phys_addr_t size, int nid)
{
	return __alloc_bootmem_node(NODE_DATA(nid), size, SMP_CACHE_BYTES,
				     BOOTMEM_LOW_LIMIT);
}

static inline void * __init memblock_virt_alloc_node_nopanic(
						phys_addr_t size, int nid)
{
	return __alloc_bootmem_node_nopanic(NODE_DATA(nid), size,
					     SMP_CACHE_BYTES,
					     BOOTMEM_LOW_LIMIT);
}

static inline void * __init memblock_virt_alloc_try_nid(phys_addr_t size,
	phys_addr_t align, phys_addr_t min_addr, phys_addr_t max_addr, int nid)
{
	return __alloc_bootmem_node_high(NODE_DATA(nid), size, align,
					  min_addr);
}

static inline void * __init memblock_virt_alloc_try_nid_raw(
			phys_addr_t size, phys_addr_t align,
			phys_addr_t min_addr, phys_addr_t max_addr, int nid)
{
	return ___alloc_bootmem_node_nopanic(NODE_DATA(nid), size, align,
				min_addr, max_addr);
}

static inline void * __init memblock_virt_alloc_try_nid_nopanic(
			phys_addr_t size, phys_addr_t align,
			phys_addr_t min_addr, phys_addr_t max_addr, int nid)
{
	return ___alloc_bootmem_node_nopanic(NODE_DATA(nid), size, align,
				min_addr, max_addr);
}

static inline void __init memblock_free_early(
					phys_addr_t base, phys_addr_t size)
{
	free_bootmem(base, size);
}

static inline void __init memblock_free_early_nid(
				phys_addr_t base, phys_addr_t size, int nid)
{
	free_bootmem_node(NODE_DATA(nid), base, size);
}

static inline void __init memblock_free_late(
					phys_addr_t base, phys_addr_t size)
{
	free_bootmem_late(base, size);
}
#endif 

extern void *alloc_large_system_hash(const char *tablename,
				     unsigned long bucketsize,
				     unsigned long numentries,
				     int scale,
				     int flags,
				     unsigned int *_hash_shift,
				     unsigned int *_hash_mask,
				     unsigned long low_limit,
				     unsigned long high_limit);

#define HASH_EARLY	0x00000001	
#define HASH_SMALL	0x00000002	
#define HASH_ZERO	0x00000004	


#ifdef CONFIG_NUMA
#define HASHDIST_DEFAULT IS_ENABLED(CONFIG_64BIT)
extern int hashdist;		
#else
#define hashdist (0)
#endif


#endif 
