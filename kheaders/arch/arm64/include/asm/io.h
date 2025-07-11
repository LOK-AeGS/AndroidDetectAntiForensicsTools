
#ifndef __ASM_IO_H
#define __ASM_IO_H

#ifdef __KERNEL__

#include <linux/types.h>

#include <asm/byteorder.h>
#include <asm/barrier.h>
#include <asm/memory.h>
#include <asm/pgtable.h>
#include <asm/early_ioremap.h>
#include <asm/alternative.h>
#include <asm/cpufeature.h>
#include <linux/msm_rtb.h>

#include <xen/xen.h>


static inline void __raw_writeb_no_log(u8 val, volatile void __iomem *addr)
{
	asm volatile("strb %w0, [%1]" : : "rZ" (val), "r" (addr));
}

static inline void __raw_writew_no_log(u16 val, volatile void __iomem *addr)
{
	asm volatile("strh %w0, [%1]" : : "rZ" (val), "r" (addr));
}

static inline void __raw_writel_no_log(u32 val, volatile void __iomem *addr)
{
	asm volatile("str %w0, [%1]" : : "rZ" (val), "r" (addr));
}

static inline void __raw_writeq_no_log(u64 val, volatile void __iomem *addr)
{
	asm volatile("str %x0, [%1]" : : "rZ" (val), "r" (addr));
}

static inline u8 __raw_readb_no_log(const volatile void __iomem *addr)
{
	u8 val;
	asm volatile(ALTERNATIVE("ldrb %w0, [%1]",
				 "ldarb %w0, [%1]",
				 ARM64_WORKAROUND_DEVICE_LOAD_ACQUIRE)
		     : "=r" (val) : "r" (addr));
	return val;
}

static inline u16 __raw_readw_no_log(const volatile void __iomem *addr)
{
	u16 val;

	asm volatile(ALTERNATIVE("ldrh %w0, [%1]",
				 "ldarh %w0, [%1]",
				 ARM64_WORKAROUND_DEVICE_LOAD_ACQUIRE)
		     : "=r" (val) : "r" (addr));
	return val;
}

static inline u32 __raw_readl_no_log(const volatile void __iomem *addr)
{
	u32 val;
	asm volatile(ALTERNATIVE("ldr %w0, [%1]",
				 "ldar %w0, [%1]",
				 ARM64_WORKAROUND_DEVICE_LOAD_ACQUIRE)
		     : "=r" (val) : "r" (addr));
	return val;
}

static inline u64 __raw_readq_no_log(const volatile void __iomem *addr)
{
	u64 val;
	asm volatile(ALTERNATIVE("ldr %0, [%1]",
				 "ldar %0, [%1]",
				 ARM64_WORKAROUND_DEVICE_LOAD_ACQUIRE)
		     : "=r" (val) : "r" (addr));
	return val;
}



#if defined(CONFIG_QCOM_RTB)
#define SEC_DEBUG_ETB_WAYPOINT_COND(__cond) \
	if (!IS_ENABLED(CONFIG_SEC_DEBUG)) \
		ETB_WAYPOINT; \
	else if (__cond) \
		ETB_WAYPOINT;
#else
#define SEC_DEBUG_ETB_WAYPOINT_COND(__cond)	ETB_WAYPOINT
#endif

#define __raw_write_logged(v, a, _t) ({ \
	int _ret; \
	void *_addr = (void *)(a); \
	_ret = uncached_logk(LOGK_WRITEL, _addr); \
	SEC_DEBUG_ETB_WAYPOINT_COND(_ret); \
	__raw_write##_t##_no_log((v), _addr); \
	if (_ret) \
		LOG_BARRIER; \
	})

#define __raw_writeb(v, a)	__raw_write_logged((v), a, b)
#define __raw_writew(v, a)	__raw_write_logged((v), a, w)
#define __raw_writel(v, a)	__raw_write_logged((v), a, l)
#define __raw_writeq(v, a)	__raw_write_logged((v), a, q)

#define __raw_read_logged(a, _l, _t)    ({ \
	_t __a; \
	void *_addr = (void *)(a); \
	int _ret; \
	_ret = uncached_logk(LOGK_READL, _addr); \
	SEC_DEBUG_ETB_WAYPOINT_COND(_ret); \
	__a = __raw_read##_l##_no_log(_addr); \
	if (_ret) \
		LOG_BARRIER; \
	__a; \
	})

#define __raw_readb(a)		__raw_read_logged((a), b, u8)
#define __raw_readw(a)		__raw_read_logged((a), w, u16)
#define __raw_readl(a)		__raw_read_logged((a), l, u32)
#define __raw_readq(a)		__raw_read_logged((a), q, u64)


#define __iormb(v)							\
({									\
	unsigned long tmp;						\
									\
	rmb();								\
									\
									\
	asm volatile("eor	%0, %1, %1\n"				\
		     "cbnz	%0, ."					\
		     : "=r" (tmp) : "r" ((unsigned long)(v))		\
		     : "memory");					\
})

#define __iowmb()		wmb()

#define mmiowb()		do { } while (0)


#define readb_relaxed(c)	({ u8  __r = __raw_readb(c); __r; })
#define readw_relaxed(c)	({ u16 __r = le16_to_cpu((__force __le16)__raw_readw(c)); __r; })
#define readl_relaxed(c)	({ u32 __r = le32_to_cpu((__force __le32)__raw_readl(c)); __r; })
#define readq_relaxed(c)	({ u64 __r = le64_to_cpu((__force __le64)__raw_readq(c)); __r; })

#define writeb_relaxed(v,c)	((void)__raw_writeb((v),(c)))
#define writew_relaxed(v,c)	((void)__raw_writew((__force u16)cpu_to_le16(v),(c)))
#define writel_relaxed(v,c)	((void)__raw_writel((__force u32)cpu_to_le32(v),(c)))
#define writeq_relaxed(v,c)	((void)__raw_writeq((__force u64)cpu_to_le64(v),(c)))

#define readb_relaxed_no_log(c)	({ u8 __v = __raw_readb_no_log(c); __v; })
#define readw_relaxed_no_log(c) \
	({ u16 __v = le16_to_cpu((__force __le16)__raw_readw_no_log(c)); __v; })
#define readl_relaxed_no_log(c) \
	({ u32 __v = le32_to_cpu((__force __le32)__raw_readl_no_log(c)); __v; })
#define readq_relaxed_no_log(c) \
	({ u64 __v = le64_to_cpu((__force __le64)__raw_readq_no_log(c)); __v; })

#define writeb_relaxed_no_log(v, c)	((void)__raw_writeb_no_log((v), (c)))
#define writew_relaxed_no_log(v, c) \
	((void)__raw_writew_no_log((__force u16)cpu_to_le32(v), (c)))
#define writel_relaxed_no_log(v, c) \
	((void)__raw_writel_no_log((__force u32)cpu_to_le32(v), (c)))
#define writeq_relaxed_no_log(v, c) \
	((void)__raw_writeq_no_log((__force u64)cpu_to_le32(v), (c)))


#define readb(c)		({ u8  __v = readb_relaxed(c); __iormb(__v); __v; })
#define readw(c)		({ u16 __v = readw_relaxed(c); __iormb(__v); __v; })
#define readl(c)		({ u32 __v = readl_relaxed(c); __iormb(__v); __v; })
#define readq(c)		({ u64 __v = readq_relaxed(c); __iormb(__v); __v; })

#define writeb(v,c)		({ __iowmb(); writeb_relaxed((v),(c)); })
#define writew(v,c)		({ __iowmb(); writew_relaxed((v),(c)); })
#define writel(v,c)		({ __iowmb(); writel_relaxed((v),(c)); })
#define writeq(v,c)		({ __iowmb(); writeq_relaxed((v),(c)); })

#define readb_no_log(c) \
		({ u8  __v = readb_relaxed_no_log(c); __iormb(__v); __v; })
#define readw_no_log(c) \
		({ u16 __v = readw_relaxed_no_log(c); __iormb(__v); __v; })
#define readl_no_log(c) \
		({ u32 __v = readl_relaxed_no_log(c); __iormb(__v); __v; })
#define readq_no_log(c) \
		({ u64 __v = readq_relaxed_no_log(c); __iormb(__v); __v; })

#define writeb_no_log(v, c) \
		({ __iowmb(); writeb_relaxed_no_log((v), (c)); })
#define writew_no_log(v, c) \
		({ __iowmb(); writew_relaxed_no_log((v), (c)); })
#define writel_no_log(v, c) \
		({ __iowmb(); writel_relaxed_no_log((v), (c)); })
#define writeq_no_log(v, c) \
		({ __iowmb(); writeq_relaxed_no_log((v), (c)); })


#define arch_has_dev_port()	(1)
#define IO_SPACE_LIMIT		(PCI_IO_SIZE - 1)
#define PCI_IOBASE		((void __iomem *)PCI_IO_START)


extern void __memcpy_fromio(void *, const volatile void __iomem *, size_t);
extern void __memcpy_toio(volatile void __iomem *, const void *, size_t);
extern void __memset_io(volatile void __iomem *, int, size_t);

#define memset_io(c,v,l)	__memset_io((c),(v),(l))
#define memcpy_fromio(a,c,l)	__memcpy_fromio((a),(c),(l))
#define memcpy_toio(c,a,l)	__memcpy_toio((c),(a),(l))


extern void __iomem *__ioremap(phys_addr_t phys_addr, size_t size, pgprot_t prot);
extern void __iounmap(volatile void __iomem *addr);
extern void __iomem *ioremap_cache(phys_addr_t phys_addr, size_t size);

#define ioremap(addr, size)		__ioremap((addr), (size), __pgprot(PROT_DEVICE_nGnRE))
#define ioremap_nocache(addr, size)	__ioremap((addr), (size), __pgprot(PROT_DEVICE_nGnRE))
#define ioremap_wc(addr, size)		__ioremap((addr), (size), __pgprot(PROT_NORMAL_NC))
#define ioremap_wt(addr, size)		__ioremap((addr), (size), __pgprot(PROT_DEVICE_nGnRE))
#define iounmap				__iounmap


#define pci_remap_cfgspace(addr, size) __ioremap((addr), (size), __pgprot(PROT_DEVICE_nGnRnE))


#define ioread16be(p)		({ __u16 __v = be16_to_cpu((__force __be16)__raw_readw_no_log(p)); __iormb(__v); __v; })
#define ioread32be(p)		({ __u32 __v = be32_to_cpu((__force __be32)__raw_readl_no_log(p)); __iormb(__v); __v; })
#define ioread64be(p)		({ __u64 __v = be64_to_cpu((__force __be64)__raw_readq_no_log(p)); __iormb(__v); __v; })

#define iowrite16be(v,p)	({ __iowmb(); __raw_writew_no_log((__force __u16)cpu_to_be16(v), p); })
#define iowrite32be(v,p)	({ __iowmb(); __raw_writel_no_log((__force __u32)cpu_to_be32(v), p); })
#define iowrite64be(v,p)	({ __iowmb(); __raw_writeq_no_log((__force __u64)cpu_to_be64(v), p); })

#include <asm-generic/io.h>


#define ARCH_HAS_VALID_PHYS_ADDR_RANGE
extern int valid_phys_addr_range(phys_addr_t addr, size_t size);
extern int valid_mmap_phys_addr_range(unsigned long pfn, size_t size);

extern int devmem_is_allowed(unsigned long pfn);

struct bio_vec;
extern bool xen_biovec_phys_mergeable(const struct bio_vec *vec1,
				      const struct bio_vec *vec2);
#define BIOVEC_PHYS_MERGEABLE(vec1, vec2)				\
	(__BIOVEC_PHYS_MERGEABLE(vec1, vec2) &&				\
	 (!xen_domain() || xen_biovec_phys_mergeable(vec1, vec2)))

#endif	
#endif	
