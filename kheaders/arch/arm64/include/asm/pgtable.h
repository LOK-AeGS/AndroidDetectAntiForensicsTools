
#ifndef __ASM_PGTABLE_H
#define __ASM_PGTABLE_H

#include <asm/bug.h>
#include <asm/proc-fns.h>

#include <asm/bug.h>
#include <asm/memory.h>
#include <asm/pgtable-hwdef.h>
#include <asm/pgtable-prot.h>


#define VMALLOC_START		(MODULES_END)
#define VMALLOC_END		(PAGE_OFFSET - PUD_SIZE - VMEMMAP_SIZE - SZ_64K)

#define vmemmap			((struct page *)VMEMMAP_START - (memstart_addr >> PAGE_SHIFT))

#define FIRST_USER_ADDRESS	0UL

#ifndef __ASSEMBLY__

#include <asm/cmpxchg.h>
#include <asm/fixmap.h>
#include <linux/mmdebug.h>
#include <linux/mm_types.h>
#include <linux/sched.h>

extern void __pte_error(const char *file, int line, unsigned long val);
extern void __pmd_error(const char *file, int line, unsigned long val);
extern void __pud_error(const char *file, int line, unsigned long val);
extern void __pgd_error(const char *file, int line, unsigned long val);


extern unsigned long empty_zero_page[PAGE_SIZE / sizeof(unsigned long)];
#define ZERO_PAGE(vaddr)	phys_to_page(__pa_symbol(empty_zero_page))

#define pte_ERROR(pte)		__pte_error(__FILE__, __LINE__, pte_val(pte))


#ifdef CONFIG_ARM64_PA_BITS_52
#define __pte_to_phys(pte)	\
	((pte_val(pte) & PTE_ADDR_LOW) | ((pte_val(pte) & PTE_ADDR_HIGH) << 36))
#define __phys_to_pte_val(phys)	(((phys) | ((phys) >> 36)) & PTE_ADDR_MASK)
#else
#define __pte_to_phys(pte)	(pte_val(pte) & PTE_ADDR_MASK)
#define __phys_to_pte_val(phys)	(phys)
#endif

#define pte_pfn(pte)		(__pte_to_phys(pte) >> PAGE_SHIFT)
#define pfn_pte(pfn,prot)	\
	__pte(__phys_to_pte_val((phys_addr_t)(pfn) << PAGE_SHIFT) | pgprot_val(prot))

#define pte_none(pte)		(!pte_val(pte))
#define pte_clear(mm,addr,ptep)	set_pte(ptep, __pte(0))
#define pte_page(pte)		(pfn_to_page(pte_pfn(pte)))


#define pte_present(pte)	(!!(pte_val(pte) & (PTE_VALID | PTE_PROT_NONE)))
#define pte_young(pte)		(!!(pte_val(pte) & PTE_AF))
#define pte_special(pte)	(!!(pte_val(pte) & PTE_SPECIAL))
#define pte_write(pte)		(!!(pte_val(pte) & PTE_WRITE))
#define pte_user_exec(pte)	(!(pte_val(pte) & PTE_UXN))
#define pte_cont(pte)		(!!(pte_val(pte) & PTE_CONT))

#define pte_cont_addr_end(addr, end)						\
({	unsigned long __boundary = ((addr) + CONT_PTE_SIZE) & CONT_PTE_MASK;	\
	(__boundary - 1 < (end) - 1) ? __boundary : (end);			\
})

#define pmd_cont_addr_end(addr, end)						\
({	unsigned long __boundary = ((addr) + CONT_PMD_SIZE) & CONT_PMD_MASK;	\
	(__boundary - 1 < (end) - 1) ? __boundary : (end);			\
})

#define pte_hw_dirty(pte)	(pte_write(pte) && !(pte_val(pte) & PTE_RDONLY))
#define pte_sw_dirty(pte)	(!!(pte_val(pte) & PTE_DIRTY))
#define pte_dirty(pte)		(pte_sw_dirty(pte) || pte_hw_dirty(pte))

#define pte_valid(pte)		(!!(pte_val(pte) & PTE_VALID))
#define pte_valid_not_user(pte) \
	((pte_val(pte) & (PTE_VALID | PTE_USER)) == PTE_VALID)
#define pte_valid_user(pte) \
	((pte_val(pte) & (PTE_VALID | PTE_USER)) == (PTE_VALID | PTE_USER))


#define pte_accessible(mm, pte)	\
	(mm_tlb_flush_pending(mm) ? pte_present(pte) : pte_valid(pte))


#define pte_access_permitted(pte, write) \
	(pte_valid_user(pte) && (!(write) || pte_write(pte)))
#define pmd_access_permitted(pmd, write) \
	(pte_access_permitted(pmd_pte(pmd), (write)))
#define pud_access_permitted(pud, write) \
	(pte_access_permitted(pud_pte(pud), (write)))

static inline pte_t clear_pte_bit(pte_t pte, pgprot_t prot)
{
	pte_val(pte) &= ~pgprot_val(prot);
	return pte;
}

static inline pte_t set_pte_bit(pte_t pte, pgprot_t prot)
{
	pte_val(pte) |= pgprot_val(prot);
	return pte;
}

static inline pte_t pte_wrprotect(pte_t pte)
{
	pte = clear_pte_bit(pte, __pgprot(PTE_WRITE));
	pte = set_pte_bit(pte, __pgprot(PTE_RDONLY));
	return pte;
}

static inline pte_t pte_mkwrite(pte_t pte)
{
	pte = set_pte_bit(pte, __pgprot(PTE_WRITE));
	pte = clear_pte_bit(pte, __pgprot(PTE_RDONLY));
	return pte;
}

static inline pte_t pte_mkclean(pte_t pte)
{
	pte = clear_pte_bit(pte, __pgprot(PTE_DIRTY));
	pte = set_pte_bit(pte, __pgprot(PTE_RDONLY));

	return pte;
}

static inline pte_t pte_mkdirty(pte_t pte)
{
	pte = set_pte_bit(pte, __pgprot(PTE_DIRTY));

	if (pte_write(pte))
		pte = clear_pte_bit(pte, __pgprot(PTE_RDONLY));

	return pte;
}

static inline pte_t pte_mkold(pte_t pte)
{
	return clear_pte_bit(pte, __pgprot(PTE_AF));
}

static inline pte_t pte_mkyoung(pte_t pte)
{
	return set_pte_bit(pte, __pgprot(PTE_AF));
}

static inline pte_t pte_mkspecial(pte_t pte)
{
	return set_pte_bit(pte, __pgprot(PTE_SPECIAL));
}

static inline pte_t pte_mkcont(pte_t pte)
{
	pte = set_pte_bit(pte, __pgprot(PTE_CONT));
	return set_pte_bit(pte, __pgprot(PTE_TYPE_PAGE));
}

static inline pte_t pte_mknoncont(pte_t pte)
{
	return clear_pte_bit(pte, __pgprot(PTE_CONT));
}

static inline pte_t pte_mkpresent(pte_t pte)
{
	return set_pte_bit(pte, __pgprot(PTE_VALID));
}

static inline pmd_t pmd_mkcont(pmd_t pmd)
{
	return __pmd(pmd_val(pmd) | PMD_SECT_CONT);
}

static inline void set_pte(pte_t *ptep, pte_t pte)
{
#ifdef CONFIG_ARM64_STRICT_BREAK_BEFORE_MAKE
	pteval_t old = pte_val(*ptep);
	pteval_t new = pte_val(pte);

	
	if (!(old & new & PTE_VALID))
		goto pte_ok;

	
	if (WARN_ON((old & PTE_ATTRINDX_MASK) != (new & PTE_ATTRINDX_MASK)))
		goto pte_bad;

	
	if (!(old & new & PTE_RDONLY) &&
	    WARN_ON(pte_pfn(*ptep) != pte_pfn(pte)))
		goto pte_bad;

	goto pte_ok;

pte_bad:
	*ptep = __pte(0);
	dsb(ishst);
	asm("tlbi	vmalle1is");
	dsb(ish);
	isb();
pte_ok:
#endif

	WRITE_ONCE(*ptep, pte);

	
	if (pte_valid_not_user(pte)) {
		dsb(ishst);
		isb();
	}
}

extern void __sync_icache_dcache(pte_t pteval);


static noinline void set_pte_at(struct mm_struct *mm, unsigned long addr,
			      pte_t *ptep, pte_t pte)
{
	pte_t old_pte;

	if (pte_present(pte) && pte_user_exec(pte) && !pte_special(pte))
		__sync_icache_dcache(pte);

	
	old_pte = READ_ONCE(*ptep);
	if (IS_ENABLED(CONFIG_DEBUG_VM) && pte_valid(old_pte) && pte_valid(pte) &&
	   (mm == current->active_mm || atomic_read(&mm->mm_users) > 1)) {
		VM_WARN_ONCE(!pte_young(pte),
			     "%s: racy access flag clearing: 0x%016llx -> 0x%016llx",
			     __func__, pte_val(old_pte), pte_val(pte));
		VM_WARN_ONCE(pte_write(old_pte) && !pte_dirty(pte),
			     "%s: racy dirty state clearing: 0x%016llx -> 0x%016llx",
			     __func__, pte_val(old_pte), pte_val(pte));
	}

	set_pte(ptep, pte);
}


#define pte_huge(pte)		(!(pte_val(pte) & PTE_TABLE_BIT))
#define pte_mkhuge(pte)		(__pte(pte_val(pte) & ~PTE_TABLE_BIT))


#define HUGE_MAX_HSTATE		4
#define HPAGE_SHIFT		PMD_SHIFT
#define HPAGE_SIZE		(_AC(1, UL) << HPAGE_SHIFT)
#define HPAGE_MASK		(~(HPAGE_SIZE - 1))
#define HUGETLB_PAGE_ORDER	(HPAGE_SHIFT - PAGE_SHIFT)

static inline pte_t pgd_pte(pgd_t pgd)
{
	return __pte(pgd_val(pgd));
}

static inline pte_t pud_pte(pud_t pud)
{
	return __pte(pud_val(pud));
}

static inline pmd_t pud_pmd(pud_t pud)
{
	return __pmd(pud_val(pud));
}

static inline pte_t pmd_pte(pmd_t pmd)
{
	return __pte(pmd_val(pmd));
}

static inline pmd_t pte_pmd(pte_t pte)
{
	return __pmd(pte_val(pte));
}

static inline pgprot_t mk_sect_prot(pgprot_t prot)
{
	return __pgprot(pgprot_val(prot) & ~PTE_TABLE_BIT);
}

#ifdef CONFIG_NUMA_BALANCING

static inline int pte_protnone(pte_t pte)
{
	return (pte_val(pte) & (PTE_VALID | PTE_PROT_NONE)) == PTE_PROT_NONE;
}

static inline int pmd_protnone(pmd_t pmd)
{
	return pte_protnone(pmd_pte(pmd));
}
#endif



#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define pmd_trans_huge(pmd)	(pmd_val(pmd) && !(pmd_val(pmd) & PMD_TABLE_BIT))
#endif 

#define pmd_present(pmd)	pte_present(pmd_pte(pmd))
#define pmd_dirty(pmd)		pte_dirty(pmd_pte(pmd))
#define pmd_young(pmd)		pte_young(pmd_pte(pmd))
#define pmd_wrprotect(pmd)	pte_pmd(pte_wrprotect(pmd_pte(pmd)))
#define pmd_mkold(pmd)		pte_pmd(pte_mkold(pmd_pte(pmd)))
#define pmd_mkwrite(pmd)	pte_pmd(pte_mkwrite(pmd_pte(pmd)))
#define pmd_mkclean(pmd)	pte_pmd(pte_mkclean(pmd_pte(pmd)))
#define pmd_mkdirty(pmd)	pte_pmd(pte_mkdirty(pmd_pte(pmd)))
#define pmd_mkyoung(pmd)	pte_pmd(pte_mkyoung(pmd_pte(pmd)))
#define pmd_mknotpresent(pmd)	(__pmd(pmd_val(pmd) & ~PMD_SECT_VALID))

#define pmd_thp_or_huge(pmd)	(pmd_huge(pmd) || pmd_trans_huge(pmd))

#define pmd_write(pmd)		pte_write(pmd_pte(pmd))

#define pmd_mkhuge(pmd)		(__pmd(pmd_val(pmd) & ~PMD_TABLE_BIT))

#define __pmd_to_phys(pmd)	__pte_to_phys(pmd_pte(pmd))
#define __phys_to_pmd_val(phys)	__phys_to_pte_val(phys)
#define pmd_pfn(pmd)		((__pmd_to_phys(pmd) & PMD_MASK) >> PAGE_SHIFT)
#define pfn_pmd(pfn,prot)	__pmd(__phys_to_pmd_val((phys_addr_t)(pfn) << PAGE_SHIFT) | pgprot_val(prot))
#define mk_pmd(page,prot)	pfn_pmd(page_to_pfn(page),prot)

#define pud_write(pud)		pte_write(pud_pte(pud))

#define __pud_to_phys(pud)	__pte_to_phys(pud_pte(pud))
#define __phys_to_pud_val(phys)	__phys_to_pte_val(phys)
#define pud_pfn(pud)		((__pud_to_phys(pud) & PUD_MASK) >> PAGE_SHIFT)
#define pfn_pud(pfn,prot)	__pud(__phys_to_pud_val((phys_addr_t)(pfn) << PAGE_SHIFT) | pgprot_val(prot))

#define set_pmd_at(mm, addr, pmdp, pmd)	set_pte_at(mm, addr, (pte_t *)pmdp, pmd_pte(pmd))

#define __pgd_to_phys(pgd)	__pte_to_phys(pgd_pte(pgd))
#define __phys_to_pgd_val(phys)	__phys_to_pte_val(phys)

#define __pgprot_modify(prot,mask,bits) \
	__pgprot((pgprot_val(prot) & ~(mask)) | (bits))


#define pgprot_noncached(prot) \
	__pgprot_modify(prot, PTE_ATTRINDX_MASK, PTE_ATTRINDX(MT_DEVICE_nGnRnE) | PTE_PXN | PTE_UXN)
#define pgprot_writecombine(prot) \
	__pgprot_modify(prot, PTE_ATTRINDX_MASK, PTE_ATTRINDX(MT_NORMAL_NC) | PTE_PXN | PTE_UXN)
#define pgprot_device(prot) \
	__pgprot_modify(prot, PTE_ATTRINDX_MASK, PTE_ATTRINDX(MT_DEVICE_nGnRE) | PTE_PXN | PTE_UXN)
#define __HAVE_PHYS_MEM_ACCESS_PROT
struct file;
extern pgprot_t phys_mem_access_prot(struct file *file, unsigned long pfn,
				     unsigned long size, pgprot_t vma_prot);

#define pmd_none(pmd)		(!pmd_val(pmd))

#define pmd_bad(pmd)		(!(pmd_val(pmd) & PMD_TABLE_BIT))

#define pmd_table(pmd)		((pmd_val(pmd) & PMD_TYPE_MASK) == \
				 PMD_TYPE_TABLE)
#define pmd_sect(pmd)		((pmd_val(pmd) & PMD_TYPE_MASK) == \
				 PMD_TYPE_SECT)

#if defined(CONFIG_ARM64_64K_PAGES) || CONFIG_PGTABLE_LEVELS < 3
static inline bool pud_sect(pud_t pud) { return false; }
static inline bool pud_table(pud_t pud) { return true; }
#else
#define pud_sect(pud)		((pud_val(pud) & PUD_TYPE_MASK) == \
				 PUD_TYPE_SECT)
#define pud_table(pud)		((pud_val(pud) & PUD_TYPE_MASK) == \
				 PUD_TYPE_TABLE)
#endif

static inline void set_pmd(pmd_t *pmdp, pmd_t pmd)
{
	WRITE_ONCE(*pmdp, pmd);
	dsb(ishst);
	isb();
}

static inline void pmd_clear(pmd_t *pmdp)
{
	set_pmd(pmdp, __pmd(0));
}

static inline phys_addr_t pmd_page_paddr(pmd_t pmd)
{
	return __pmd_to_phys(pmd);
}

static inline unsigned long pmd_page_vaddr(pmd_t pmd)
{
	return (unsigned long) __va(pmd_page_paddr(pmd));
}

static inline void pte_unmap(pte_t *pte) { }


#define pte_index(addr)		(((addr) >> PAGE_SHIFT) & (PTRS_PER_PTE - 1))

#define pte_offset_phys(dir,addr)	(pmd_page_paddr(READ_ONCE(*(dir))) + pte_index(addr) * sizeof(pte_t))
#define pte_offset_kernel(dir,addr)	((pte_t *)__va(pte_offset_phys((dir), (addr))))

#define pte_offset_map(dir,addr)	pte_offset_kernel((dir), (addr))
#define pte_offset_map_nested(dir,addr)	pte_offset_kernel((dir), (addr))
#define pte_unmap_nested(pte)		do { } while (0)

#define pte_set_fixmap(addr)		((pte_t *)set_fixmap_offset(FIX_PTE, addr))
#define pte_set_fixmap_offset(pmd, addr)	pte_set_fixmap(pte_offset_phys(pmd, addr))
#define pte_clear_fixmap()		clear_fixmap(FIX_PTE)

#define pmd_page(pmd)		pfn_to_page(__phys_to_pfn(__pmd_to_phys(pmd)))


#define pte_offset_kimg(dir,addr)	((pte_t *)__phys_to_kimg(pte_offset_phys((dir), (addr))))


#define mk_pte(page,prot)	pfn_pte(page_to_pfn(page),prot)

#if CONFIG_PGTABLE_LEVELS > 2

#define pmd_ERROR(pmd)		__pmd_error(__FILE__, __LINE__, pmd_val(pmd))

#define pud_none(pud)		(!pud_val(pud))
#define pud_bad(pud)		(!(pud_val(pud) & PUD_TABLE_BIT))
#define pud_present(pud)	pte_present(pud_pte(pud))

static inline void set_pud(pud_t *pudp, pud_t pud)
{
	WRITE_ONCE(*pudp, pud);
	dsb(ishst);
	isb();
}

static inline void pud_clear(pud_t *pudp)
{
	set_pud(pudp, __pud(0));
}

static inline phys_addr_t pud_page_paddr(pud_t pud)
{
	return __pud_to_phys(pud);
}

static inline unsigned long pud_page_vaddr(pud_t pud)
{
	return (unsigned long) __va(pud_page_paddr(pud));
}


#define pmd_index(addr)		(((addr) >> PMD_SHIFT) & (PTRS_PER_PMD - 1))

#define pmd_offset_phys(dir, addr)	(pud_page_paddr(READ_ONCE(*(dir))) + pmd_index(addr) * sizeof(pmd_t))
#define pmd_offset(dir, addr)		((pmd_t *)__va(pmd_offset_phys((dir), (addr))))

#define pmd_set_fixmap(addr)		((pmd_t *)set_fixmap_offset(FIX_PMD, addr))
#define pmd_set_fixmap_offset(pud, addr)	pmd_set_fixmap(pmd_offset_phys(pud, addr))
#define pmd_clear_fixmap()		clear_fixmap(FIX_PMD)

#define pud_page(pud)		pfn_to_page(__phys_to_pfn(__pud_to_phys(pud)))


#define pmd_offset_kimg(dir,addr)	((pmd_t *)__phys_to_kimg(pmd_offset_phys((dir), (addr))))

#else

#define pud_page_paddr(pud)	({ BUILD_BUG(); 0; })


#define pmd_set_fixmap(addr)		NULL
#define pmd_set_fixmap_offset(pudp, addr)	((pmd_t *)pudp)
#define pmd_clear_fixmap()

#define pmd_offset_kimg(dir,addr)	((pmd_t *)dir)

#endif	

#if CONFIG_PGTABLE_LEVELS > 3

#define pud_ERROR(pud)		__pud_error(__FILE__, __LINE__, pud_val(pud))

#define pgd_none(pgd)		(!pgd_val(pgd))
#define pgd_bad(pgd)		(!(pgd_val(pgd) & 2))
#define pgd_present(pgd)	(pgd_val(pgd))

static inline void set_pgd(pgd_t *pgdp, pgd_t pgd)
{
	WRITE_ONCE(*pgdp, pgd);
	dsb(ishst);
}

static inline void pgd_clear(pgd_t *pgdp)
{
	set_pgd(pgdp, __pgd(0));
}

static inline phys_addr_t pgd_page_paddr(pgd_t pgd)
{
	return __pgd_to_phys(pgd);
}

static inline unsigned long pgd_page_vaddr(pgd_t pgd)
{
	return (unsigned long) __va(pgd_page_paddr(pgd));
}


#define pud_index(addr)		(((addr) >> PUD_SHIFT) & (PTRS_PER_PUD - 1))

#define pud_offset_phys(dir, addr)	(pgd_page_paddr(READ_ONCE(*(dir))) + pud_index(addr) * sizeof(pud_t))
#define pud_offset(dir, addr)		((pud_t *)__va(pud_offset_phys((dir), (addr))))

#define pud_set_fixmap(addr)		((pud_t *)set_fixmap_offset(FIX_PUD, addr))
#define pud_set_fixmap_offset(pgd, addr)	pud_set_fixmap(pud_offset_phys(pgd, addr))
#define pud_clear_fixmap()		clear_fixmap(FIX_PUD)

#define pgd_page(pgd)		pfn_to_page(__phys_to_pfn(__pgd_to_phys(pgd)))


#define pud_offset_kimg(dir,addr)	((pud_t *)__phys_to_kimg(pud_offset_phys((dir), (addr))))

#else

#define pgd_page_paddr(pgd)	({ BUILD_BUG(); 0;})


#define pud_set_fixmap(addr)		NULL
#define pud_set_fixmap_offset(pgdp, addr)	((pud_t *)pgdp)
#define pud_clear_fixmap()

#define pud_offset_kimg(dir,addr)	((pud_t *)dir)

#endif  

#define pgd_ERROR(pgd)		__pgd_error(__FILE__, __LINE__, pgd_val(pgd))


#define pgd_index(addr)		(((addr) >> PGDIR_SHIFT) & (PTRS_PER_PGD - 1))

#define pgd_offset_raw(pgd, addr)	((pgd) + pgd_index(addr))

#define pgd_offset(mm, addr)	(pgd_offset_raw((mm)->pgd, (addr)))


#define pgd_offset_k(addr)	pgd_offset(&init_mm, addr)

#define pgd_set_fixmap(addr)	((pgd_t *)set_fixmap_offset(FIX_PGD, addr))
#define pgd_clear_fixmap()	clear_fixmap(FIX_PGD)

static inline pte_t pte_modify(pte_t pte, pgprot_t newprot)
{
	const pteval_t mask = PTE_USER | PTE_PXN | PTE_UXN | PTE_RDONLY |
			      PTE_PROT_NONE | PTE_VALID | PTE_WRITE;
	
	if (pte_hw_dirty(pte))
		pte = pte_mkdirty(pte);
	pte_val(pte) = (pte_val(pte) & ~mask) | (pgprot_val(newprot) & mask);
	return pte;
}

static inline pmd_t pmd_modify(pmd_t pmd, pgprot_t newprot)
{
	return pte_pmd(pte_modify(pmd_pte(pmd), newprot));
}

#define __HAVE_ARCH_PTEP_SET_ACCESS_FLAGS
extern int ptep_set_access_flags(struct vm_area_struct *vma,
				 unsigned long address, pte_t *ptep,
				 pte_t entry, int dirty);

#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define __HAVE_ARCH_PMDP_SET_ACCESS_FLAGS
static inline int pmdp_set_access_flags(struct vm_area_struct *vma,
					unsigned long address, pmd_t *pmdp,
					pmd_t entry, int dirty)
{
	return ptep_set_access_flags(vma, address, (pte_t *)pmdp, pmd_pte(entry), dirty);
}
#endif


#define __HAVE_ARCH_PTEP_TEST_AND_CLEAR_YOUNG
static inline int __ptep_test_and_clear_young(pte_t *ptep)
{
	pte_t old_pte, pte;

	pte = READ_ONCE(*ptep);
	do {
		old_pte = pte;
		pte = pte_mkold(pte);
		pte_val(pte) = cmpxchg_relaxed(&pte_val(*ptep),
					       pte_val(old_pte), pte_val(pte));
	} while (pte_val(pte) != pte_val(old_pte));

	return pte_young(pte);
}

static inline int ptep_test_and_clear_young(struct vm_area_struct *vma,
					    unsigned long address,
					    pte_t *ptep)
{
	return __ptep_test_and_clear_young(ptep);
}

#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define __HAVE_ARCH_PMDP_TEST_AND_CLEAR_YOUNG
static inline int pmdp_test_and_clear_young(struct vm_area_struct *vma,
					    unsigned long address,
					    pmd_t *pmdp)
{
	return ptep_test_and_clear_young(vma, address, (pte_t *)pmdp);
}
#endif 

#define __HAVE_ARCH_PTEP_GET_AND_CLEAR
static inline pte_t ptep_get_and_clear(struct mm_struct *mm,
				       unsigned long address, pte_t *ptep)
{
#ifdef CONFIG_RKP
	pte_t old = __pte(pte_val(*ptep));
	pte_t zero_pte;

	pte_val(zero_pte) = 0;
	set_pte(ptep, zero_pte);
	return old;
#else
	return __pte(xchg_relaxed(&pte_val(*ptep), 0));
#endif
}

#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define __HAVE_ARCH_PMDP_HUGE_GET_AND_CLEAR
static inline pmd_t pmdp_huge_get_and_clear(struct mm_struct *mm,
					    unsigned long address, pmd_t *pmdp)
{
	return pte_pmd(ptep_get_and_clear(mm, address, (pte_t *)pmdp));
}
#endif 


#define __HAVE_ARCH_PTEP_SET_WRPROTECT
static inline void ptep_set_wrprotect(struct mm_struct *mm, unsigned long address, pte_t *ptep)
{
	pte_t old_pte, pte;

	pte = READ_ONCE(*ptep);
	do {
		old_pte = pte;
		
		if (pte_hw_dirty(pte))
			pte = pte_mkdirty(pte);
		pte = pte_wrprotect(pte);
		pte_val(pte) = cmpxchg_relaxed(&pte_val(*ptep),
					       pte_val(old_pte), pte_val(pte));
	} while (pte_val(pte) != pte_val(old_pte));
}

#ifdef CONFIG_TRANSPARENT_HUGEPAGE
#define __HAVE_ARCH_PMDP_SET_WRPROTECT
static inline void pmdp_set_wrprotect(struct mm_struct *mm,
				      unsigned long address, pmd_t *pmdp)
{
	ptep_set_wrprotect(mm, address, (pte_t *)pmdp);
}

#define pmdp_establish pmdp_establish
static inline pmd_t pmdp_establish(struct vm_area_struct *vma,
		unsigned long address, pmd_t *pmdp, pmd_t pmd)
{
	return __pmd(xchg_relaxed(&pmd_val(*pmdp), pmd_val(pmd)));
}
#endif

extern pgd_t swapper_pg_dir[PTRS_PER_PGD];
extern pgd_t swapper_pg_end[];
extern pgd_t idmap_pg_dir[PTRS_PER_PGD];
extern pgd_t tramp_pg_dir[PTRS_PER_PGD];


#define __SWP_TYPE_SHIFT	2
#define __SWP_TYPE_BITS		6
#define __SWP_OFFSET_BITS	50
#define __SWP_TYPE_MASK		((1 << __SWP_TYPE_BITS) - 1)
#define __SWP_OFFSET_SHIFT	(__SWP_TYPE_BITS + __SWP_TYPE_SHIFT)
#define __SWP_OFFSET_MASK	((1UL << __SWP_OFFSET_BITS) - 1)

#define __swp_type(x)		(((x).val >> __SWP_TYPE_SHIFT) & __SWP_TYPE_MASK)
#define __swp_offset(x)		(((x).val >> __SWP_OFFSET_SHIFT) & __SWP_OFFSET_MASK)
#define __swp_entry(type,offset) ((swp_entry_t) { ((type) << __SWP_TYPE_SHIFT) | ((offset) << __SWP_OFFSET_SHIFT) })

#define __pte_to_swp_entry(pte)	((swp_entry_t) { pte_val(pte) })
#define __swp_entry_to_pte(swp)	((pte_t) { (swp).val })


#define MAX_SWAPFILES_CHECK() BUILD_BUG_ON(MAX_SWAPFILES_SHIFT > __SWP_TYPE_BITS)

extern int kern_addr_valid(unsigned long addr);

#include <asm-generic/pgtable.h>

void pgd_cache_init(void);
#define pgtable_cache_init	pgd_cache_init


static inline void update_mmu_cache(struct vm_area_struct *vma,
				    unsigned long addr, pte_t *ptep)
{
	
}

#define update_mmu_cache_pmd(vma, address, pmd) do { } while (0)

#define kc_vaddr_to_offset(v)	((v) & ~VA_START)
#define kc_offset_to_vaddr(o)	((o) | VA_START)

#ifdef CONFIG_ARM64_PA_BITS_52
#define phys_to_ttbr(addr)	(((addr) | ((addr) >> 46)) & TTBR_BADDR_MASK_52)
#else
#define phys_to_ttbr(addr)	(addr)
#endif

#endif 

#endif 
