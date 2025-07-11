

#ifndef __ASM_GNTTAB_H__
#define __ASM_GNTTAB_H__

#include <asm/page.h>

#include <xen/interface/xen.h>
#include <xen/interface/grant_table.h>

#include <asm/xen/hypervisor.h>

#include <xen/features.h>
#include <xen/page.h>
#include <linux/mm_types.h>
#include <linux/page-flags.h>
#include <linux/kernel.h>

#define GNTTAB_RESERVED_XENSTORE 1


#define NR_GRANT_FRAMES 4

struct gnttab_free_callback {
	struct gnttab_free_callback *next;
	void (*fn)(void *);
	void *arg;
	u16 count;
};

struct gntab_unmap_queue_data;

typedef void (*gnttab_unmap_refs_done)(int result, struct gntab_unmap_queue_data *data);

struct gntab_unmap_queue_data
{
	struct delayed_work	gnttab_work;
	void *data;
	gnttab_unmap_refs_done	done;
	struct gnttab_unmap_grant_ref *unmap_ops;
	struct gnttab_unmap_grant_ref *kunmap_ops;
	struct page **pages;
	unsigned int count;
	unsigned int age;
};

int gnttab_init(void);
int gnttab_suspend(void);
int gnttab_resume(void);

int gnttab_grant_foreign_access(domid_t domid, unsigned long frame,
				int readonly);


int gnttab_end_foreign_access_ref(grant_ref_t ref, int readonly);


void gnttab_end_foreign_access(grant_ref_t ref, int readonly,
			       unsigned long page);

int gnttab_grant_foreign_transfer(domid_t domid, unsigned long pfn);

unsigned long gnttab_end_foreign_transfer_ref(grant_ref_t ref);
unsigned long gnttab_end_foreign_transfer(grant_ref_t ref);

int gnttab_query_foreign_access(grant_ref_t ref);


int gnttab_alloc_grant_references(u16 count, grant_ref_t *pprivate_head);

void gnttab_free_grant_reference(grant_ref_t ref);

void gnttab_free_grant_references(grant_ref_t head);

int gnttab_empty_grant_references(const grant_ref_t *pprivate_head);

int gnttab_claim_grant_reference(grant_ref_t *pprivate_head);

void gnttab_release_grant_reference(grant_ref_t *private_head,
				    grant_ref_t release);

void gnttab_request_free_callback(struct gnttab_free_callback *callback,
				  void (*fn)(void *), void *arg, u16 count);
void gnttab_cancel_free_callback(struct gnttab_free_callback *callback);

void gnttab_grant_foreign_access_ref(grant_ref_t ref, domid_t domid,
				     unsigned long frame, int readonly);


static inline void gnttab_page_grant_foreign_access_ref_one(
	grant_ref_t ref, domid_t domid,
	struct page *page, int readonly)
{
	gnttab_grant_foreign_access_ref(ref, domid, xen_page_to_gfn(page),
					readonly);
}

void gnttab_grant_foreign_transfer_ref(grant_ref_t, domid_t domid,
				       unsigned long pfn);

static inline void
gnttab_set_map_op(struct gnttab_map_grant_ref *map, phys_addr_t addr,
		  uint32_t flags, grant_ref_t ref, domid_t domid)
{
	if (flags & GNTMAP_contains_pte)
		map->host_addr = addr;
	else if (xen_feature(XENFEAT_auto_translated_physmap))
		map->host_addr = __pa(addr);
	else
		map->host_addr = addr;

	map->flags = flags;
	map->ref = ref;
	map->dom = domid;
}

static inline void
gnttab_set_unmap_op(struct gnttab_unmap_grant_ref *unmap, phys_addr_t addr,
		    uint32_t flags, grant_handle_t handle)
{
	if (flags & GNTMAP_contains_pte)
		unmap->host_addr = addr;
	else if (xen_feature(XENFEAT_auto_translated_physmap))
		unmap->host_addr = __pa(addr);
	else
		unmap->host_addr = addr;

	unmap->handle = handle;
	unmap->dev_bus_addr = 0;
}

int arch_gnttab_init(unsigned long nr_shared, unsigned long nr_status);
int arch_gnttab_map_shared(xen_pfn_t *frames, unsigned long nr_gframes,
			   unsigned long max_nr_gframes,
			   void **__shared);
int arch_gnttab_map_status(uint64_t *frames, unsigned long nr_gframes,
			   unsigned long max_nr_gframes,
			   grant_status_t **__shared);
void arch_gnttab_unmap(void *shared, unsigned long nr_gframes);

struct grant_frames {
	xen_pfn_t *pfn;
	unsigned int count;
	void *vaddr;
};
extern struct grant_frames xen_auto_xlat_grant_frames;
unsigned int gnttab_max_grant_frames(void);
int gnttab_setup_auto_xlat_frames(phys_addr_t addr);
void gnttab_free_auto_xlat_frames(void);

#define gnttab_map_vaddr(map) ((void *)(map.host_virt_addr))

int gnttab_alloc_pages(int nr_pages, struct page **pages);
void gnttab_free_pages(int nr_pages, struct page **pages);

#ifdef CONFIG_XEN_GRANT_DMA_ALLOC
struct gnttab_dma_alloc_args {
	
	struct device *dev;
	
	bool coherent;

	int nr_pages;
	struct page **pages;
	xen_pfn_t *frames;
	void *vaddr;
	dma_addr_t dev_bus_addr;
};

int gnttab_dma_alloc_pages(struct gnttab_dma_alloc_args *args);
int gnttab_dma_free_pages(struct gnttab_dma_alloc_args *args);
#endif

int gnttab_pages_set_private(int nr_pages, struct page **pages);
void gnttab_pages_clear_private(int nr_pages, struct page **pages);

int gnttab_map_refs(struct gnttab_map_grant_ref *map_ops,
		    struct gnttab_map_grant_ref *kmap_ops,
		    struct page **pages, unsigned int count);
int gnttab_unmap_refs(struct gnttab_unmap_grant_ref *unmap_ops,
		      struct gnttab_unmap_grant_ref *kunmap_ops,
		      struct page **pages, unsigned int count);
void gnttab_unmap_refs_async(struct gntab_unmap_queue_data* item);
int gnttab_unmap_refs_sync(struct gntab_unmap_queue_data *item);



void gnttab_batch_map(struct gnttab_map_grant_ref *batch, unsigned count);
void gnttab_batch_copy(struct gnttab_copy *batch, unsigned count);


struct xen_page_foreign {
	domid_t domid;
	grant_ref_t gref;
};

static inline struct xen_page_foreign *xen_page_foreign(struct page *page)
{
	if (!PageForeign(page))
		return NULL;
#if BITS_PER_LONG < 64
	return (struct xen_page_foreign *)page->private;
#else
	BUILD_BUG_ON(sizeof(struct xen_page_foreign) > BITS_PER_LONG);
	return (struct xen_page_foreign *)&page->private;
#endif
}


typedef void (*xen_grant_fn_t)(unsigned long gfn, unsigned int offset,
			       unsigned int len, void *data);

void gnttab_foreach_grant_in_range(struct page *page,
				   unsigned int offset,
				   unsigned int len,
				   xen_grant_fn_t fn,
				   void *data);


static inline void gnttab_for_one_grant(struct page *page, unsigned int offset,
					unsigned len, xen_grant_fn_t fn,
					void *data)
{
	
	len = min_t(unsigned int, XEN_PAGE_SIZE - (offset & ~XEN_PAGE_MASK),
		    len);

	gnttab_foreach_grant_in_range(page, offset, len, fn, data);
}


void gnttab_foreach_grant(struct page **pages,
			  unsigned int nr_grefs,
			  xen_grant_fn_t fn,
			  void *data);


static inline unsigned int gnttab_count_grant(unsigned int start,
					      unsigned int len)
{
	return XEN_PFN_UP(xen_offset_in_page(start) + len);
}

#endif 
