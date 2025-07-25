

#ifndef __ASM_PGTABLE_TYPES_H
#define __ASM_PGTABLE_TYPES_H

#include <asm/types.h>

typedef u64 pteval_t;
typedef u64 pmdval_t;
typedef u64 pudval_t;
typedef u64 pgdval_t;


typedef struct { pteval_t pte; } pte_t;
#define pte_val(x)	((x).pte)
#define __pte(x)	((pte_t) { (x) } )

#if CONFIG_PGTABLE_LEVELS > 2
typedef struct { pmdval_t pmd; } pmd_t;
#define pmd_val(x)	((x).pmd)
#define __pmd(x)	((pmd_t) { (x) } )
#endif

#if CONFIG_PGTABLE_LEVELS > 3
typedef struct { pudval_t pud; } pud_t;
#define pud_val(x)	((x).pud)
#define __pud(x)	((pud_t) { (x) } )
#endif

typedef struct { pgdval_t pgd; } pgd_t;
#define pgd_val(x)	((x).pgd)
#define __pgd(x)	((pgd_t) { (x) } )

typedef struct { pteval_t pgprot; } pgprot_t;
#define pgprot_val(x)	((x).pgprot)
#define __pgprot(x)	((pgprot_t) { (x) } )

#if CONFIG_PGTABLE_LEVELS == 2
#define __ARCH_USE_5LEVEL_HACK
#include <asm-generic/pgtable-nopmd.h>
#elif CONFIG_PGTABLE_LEVELS == 3
#define __ARCH_USE_5LEVEL_HACK
#include <asm-generic/pgtable-nopud.h>
#elif CONFIG_PGTABLE_LEVELS == 4
#include <asm-generic/5level-fixup.h>
#endif

#endif	
