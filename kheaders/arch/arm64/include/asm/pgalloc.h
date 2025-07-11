
#ifndef __ASM_PGALLOC_H
#define __ASM_PGALLOC_H

#include <asm/pgtable-hwdef.h>
#include <asm/processor.h>
#include <asm/cacheflush.h>
#include <asm/tlbflush.h>

#ifdef CONFIG_RKP
#include <linux/rkp.h>
#endif

#define check_pgt_cache()		do { } while (0)

#define PGALLOC_GFP	(GFP_KERNEL | __GFP_ZERO)
#define PGD_SIZE	(PTRS_PER_PGD * sizeof(pgd_t))

#if CONFIG_PGTABLE_LEVELS > 2

static inline pmd_t *pmd_alloc_one(struct mm_struct *mm, unsigned long addr)
{
#ifdef CONFIG_RKP
	
	pmd_t *rkp_ropage = NULL;

	if (mm == &init_mm) {
		rkp_ropage = (pmd_t *)rkp_ro_alloc();
		if (rkp_ropage)
			return rkp_ropage;
		else
			return (pmd_t *)__get_free_page(PGALLOC_GFP);
	}
	else
#endif
	return (pmd_t *)__get_free_page(PGALLOC_GFP);
}

static inline void pmd_free(struct mm_struct *mm, pmd_t *pmdp)
{
	BUG_ON((unsigned long)pmdp & (PAGE_SIZE-1));
#ifdef CONFIG_RKP
	if(is_rkp_ro_buffer((u64)pmdp))
		rkp_ro_free((void *)pmdp);
	else
#endif
	free_page((unsigned long)pmdp);
}

static inline void __pud_populate(pud_t *pudp, phys_addr_t pmdp, pudval_t prot)
{
	set_pud(pudp, __pud(__phys_to_pud_val(pmdp) | prot));
}

static inline void pud_populate(struct mm_struct *mm, pud_t *pudp, pmd_t *pmdp)
{
	__pud_populate(pudp, __pa(pmdp), PMD_TYPE_TABLE);
}
#else
static inline void __pud_populate(pud_t *pudp, phys_addr_t pmdp, pudval_t prot)
{
	BUILD_BUG();
}
#endif	

#if CONFIG_PGTABLE_LEVELS > 3

static inline pud_t *pud_alloc_one(struct mm_struct *mm, unsigned long addr)
{
#ifdef CONFIG_RKP
	pud_t *rkp_ropage = NULL;

	rkp_ropage = (pud_t *)rkp_ro_alloc();
	if (rkp_ropage)
		return rkp_ropage;
	else
#endif
	return (pud_t *)__get_free_page(PGALLOC_GFP);
}

static inline void pud_free(struct mm_struct *mm, pud_t *pudp)
{
	BUG_ON((unsigned long)pudp & (PAGE_SIZE-1));
#ifdef CONFIG_RKP
	if(is_rkp_ro_buffer((u64)pudp))
		rkp_ro_free((void *)pudp);
	else
#endif
	free_page((unsigned long)pudp);
}

static inline void __pgd_populate(pgd_t *pgdp, phys_addr_t pudp, pgdval_t prot)
{
	set_pgd(pgdp, __pgd(__phys_to_pgd_val(pudp) | prot));
}

static inline void pgd_populate(struct mm_struct *mm, pgd_t *pgdp, pud_t *pudp)
{
	__pgd_populate(pgdp, __pa(pudp), PUD_TYPE_TABLE);
}
#else
static inline void __pgd_populate(pgd_t *pgdp, phys_addr_t pudp, pgdval_t prot)
{
	BUILD_BUG();
}
#endif	

extern pgd_t *pgd_alloc(struct mm_struct *mm);
extern void pgd_free(struct mm_struct *mm, pgd_t *pgdp);

static inline pte_t *
pte_alloc_one_kernel(struct mm_struct *mm, unsigned long addr)
{
	return (pte_t *)__get_free_page(PGALLOC_GFP);
}

static inline pgtable_t
pte_alloc_one(struct mm_struct *mm, unsigned long addr)
{
	struct page *pte;

	pte = alloc_pages(PGALLOC_GFP, 0);
	if (!pte)
		return NULL;
	if (!pgtable_page_ctor(pte)) {
		__free_page(pte);
		return NULL;
	}
	return pte;
}


static inline void pte_free_kernel(struct mm_struct *mm, pte_t *ptep)
{
	if (ptep)
		free_page((unsigned long)ptep);
}

static inline void pte_free(struct mm_struct *mm, pgtable_t pte)
{
	pgtable_page_dtor(pte);
	__free_page(pte);
}

static inline void __pmd_populate(pmd_t *pmdp, phys_addr_t ptep,
				  pmdval_t prot)
{
	set_pmd(pmdp, __pmd(__phys_to_pmd_val(ptep) | prot));
}


static inline void
pmd_populate_kernel(struct mm_struct *mm, pmd_t *pmdp, pte_t *ptep)
{
	
	__pmd_populate(pmdp, __pa(ptep), PMD_TYPE_TABLE);
}

static inline void
pmd_populate(struct mm_struct *mm, pmd_t *pmdp, pgtable_t ptep)
{
	__pmd_populate(pmdp, page_to_phys(ptep), PMD_TYPE_TABLE);
}
#define pmd_pgtable(pmd) pmd_page(pmd)

#endif
