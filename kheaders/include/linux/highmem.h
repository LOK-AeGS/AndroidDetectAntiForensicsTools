/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_HIGHMEM_H
#define _LINUX_HIGHMEM_H

#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/bug.h>
#include <linux/mm.h>
#include <linux/uaccess.h>
#include <linux/hardirq.h>

#include <asm/cacheflush.h>

#ifndef ARCH_HAS_FLUSH_ANON_PAGE
static inline void flush_anon_page(struct vm_area_struct *vma, struct page *page, unsigned long vmaddr)
{
}
#endif

#ifndef ARCH_HAS_FLUSH_KERNEL_DCACHE_PAGE
static inline void flush_kernel_dcache_page(struct page *page)
{
}
static inline void flush_kernel_vmap_range(void *vaddr, int size)
{
}
static inline void invalidate_kernel_vmap_range(void *vaddr, int size)
{
}
#endif

#include <asm/kmap_types.h>

#ifdef CONFIG_HIGHMEM
#include <asm/highmem.h>


unsigned int nr_free_highpages(void);
extern unsigned long totalhigh_pages;

void kmap_flush_unused(void);

#ifdef CONFIG_ARCH_WANT_KMAP_ATOMIC_FLUSH
void kmap_atomic_flush_unused(void);
#else
static inline void kmap_atomic_flush_unused(void) { }
#endif

struct page *kmap_to_page(void *addr);

#else 

static inline unsigned int nr_free_highpages(void) { return 0; }

static inline struct page *kmap_to_page(void *addr)
{
	return virt_to_page(addr);
}

#define totalhigh_pages 0UL

#ifndef ARCH_HAS_KMAP
static inline void *kmap(struct page *page)
{
	might_sleep();
	return page_address(page);
}

static inline void kunmap(struct page *page)
{
}

static inline void *kmap_atomic(struct page *page)
{
	preempt_disable();
	pagefault_disable();
	return page_address(page);
}
#define kmap_atomic_prot(page, prot)	kmap_atomic(page)

static inline void __kunmap_atomic(void *addr)
{
	pagefault_enable();
	preempt_enable();
}

#define kmap_atomic_pfn(pfn)	kmap_atomic(pfn_to_page(pfn))

#define kmap_flush_unused()	do {} while(0)
#define kmap_atomic_flush_unused()	do {} while (0)
#endif

#endif 

#if defined(CONFIG_HIGHMEM) || defined(CONFIG_X86_32)

DECLARE_PER_CPU(int, __kmap_atomic_idx);

static inline int kmap_atomic_idx_push(void)
{
	int idx = __this_cpu_inc_return(__kmap_atomic_idx) - 1;

#ifdef CONFIG_DEBUG_HIGHMEM
	WARN_ON_ONCE(in_irq() && !irqs_disabled());
	BUG_ON(idx >= KM_TYPE_NR);
#endif
	return idx;
}

static inline int kmap_atomic_idx(void)
{
	return __this_cpu_read(__kmap_atomic_idx) - 1;
}

static inline void kmap_atomic_idx_pop(void)
{
#ifdef CONFIG_DEBUG_HIGHMEM
	int idx = __this_cpu_dec_return(__kmap_atomic_idx);

	BUG_ON(idx < 0);
#else
	__this_cpu_dec(__kmap_atomic_idx);
#endif
}

#endif


#define kunmap_atomic(addr)                                     \
do {                                                            \
	BUILD_BUG_ON(__same_type((addr), struct page *));       \
	__kunmap_atomic(addr);                                  \
} while (0)



#ifndef clear_user_highpage
static inline void clear_user_highpage(struct page *page, unsigned long vaddr)
{
	void *addr = kmap_atomic(page);
	clear_user_page(addr, vaddr, page);
	kunmap_atomic(addr);
}
#endif

#ifndef __HAVE_ARCH_ALLOC_ZEROED_USER_HIGHPAGE

static inline struct page *
__alloc_zeroed_user_highpage(gfp_t movableflags,
			struct vm_area_struct *vma,
			unsigned long vaddr)
{
	struct page *page = alloc_page_vma(GFP_HIGHUSER | movableflags,
			vma, vaddr);

	if (page)
		clear_user_highpage(page, vaddr);

	return page;
}
#endif


static inline struct page *
alloc_zeroed_user_highpage_movable(struct vm_area_struct *vma,
					unsigned long vaddr)
{
#ifndef CONFIG_CMA
	return __alloc_zeroed_user_highpage(__GFP_MOVABLE, vma, vaddr);
#else
	return __alloc_zeroed_user_highpage(__GFP_MOVABLE|__GFP_CMA, vma,
						vaddr);
#endif
}

static inline void clear_highpage(struct page *page)
{
	void *kaddr = kmap_atomic(page);
	clear_page(kaddr);
	kunmap_atomic(kaddr);
}

static inline void zero_user_segments(struct page *page,
	unsigned start1, unsigned end1,
	unsigned start2, unsigned end2)
{
	void *kaddr = kmap_atomic(page);

	BUG_ON(end1 > PAGE_SIZE || end2 > PAGE_SIZE);

	if (end1 > start1)
		memset(kaddr + start1, 0, end1 - start1);

	if (end2 > start2)
		memset(kaddr + start2, 0, end2 - start2);

	kunmap_atomic(kaddr);
	flush_dcache_page(page);
}

static inline void zero_user_segment(struct page *page,
	unsigned start, unsigned end)
{
	zero_user_segments(page, start, end, 0, 0);
}

static inline void zero_user(struct page *page,
	unsigned start, unsigned size)
{
	zero_user_segments(page, start, start + size, 0, 0);
}

#ifndef __HAVE_ARCH_COPY_USER_HIGHPAGE

static inline void copy_user_highpage(struct page *to, struct page *from,
	unsigned long vaddr, struct vm_area_struct *vma)
{
	char *vfrom, *vto;

	vfrom = kmap_atomic(from);
	vto = kmap_atomic(to);
	copy_user_page(vto, vfrom, vaddr, to);
	kunmap_atomic(vto);
	kunmap_atomic(vfrom);
}

#endif

#ifndef __HAVE_ARCH_COPY_HIGHPAGE

static inline void copy_highpage(struct page *to, struct page *from)
{
	char *vfrom, *vto;

	vfrom = kmap_atomic(from);
	vto = kmap_atomic(to);
	copy_page(vto, vfrom);
	kunmap_atomic(vto);
	kunmap_atomic(vfrom);
}

#endif

#endif 
