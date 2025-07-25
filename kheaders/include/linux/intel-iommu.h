

#ifndef _INTEL_IOMMU_H_
#define _INTEL_IOMMU_H_

#include <linux/types.h>
#include <linux/iova.h>
#include <linux/io.h>
#include <linux/idr.h>
#include <linux/dma_remapping.h>
#include <linux/mmu_notifier.h>
#include <linux/list.h>
#include <linux/iommu.h>
#include <linux/io-64-nonatomic-lo-hi.h>
#include <linux/dmar.h>

#include <asm/cacheflush.h>
#include <asm/iommu.h>



#define	DMAR_VER_REG	0x0	
#define	DMAR_CAP_REG	0x8	
#define	DMAR_ECAP_REG	0x10	
#define	DMAR_GCMD_REG	0x18	
#define	DMAR_GSTS_REG	0x1c	
#define	DMAR_RTADDR_REG	0x20	
#define	DMAR_CCMD_REG	0x28	
#define	DMAR_FSTS_REG	0x34	
#define	DMAR_FECTL_REG	0x38	
#define	DMAR_FEDATA_REG	0x3c	
#define	DMAR_FEADDR_REG	0x40	
#define	DMAR_FEUADDR_REG 0x44	
#define	DMAR_AFLOG_REG	0x58	
#define	DMAR_PMEN_REG	0x64	
#define	DMAR_PLMBASE_REG 0x68	
#define	DMAR_PLMLIMIT_REG 0x6c	
#define	DMAR_PHMBASE_REG 0x70	
#define	DMAR_PHMLIMIT_REG 0x78	
#define DMAR_IQH_REG	0x80	
#define DMAR_IQT_REG	0x88	
#define DMAR_IQ_SHIFT	4	
#define DMAR_IQA_REG	0x90	
#define DMAR_ICS_REG	0x9c	
#define DMAR_IRTA_REG	0xb8    
#define DMAR_PQH_REG	0xc0	
#define DMAR_PQT_REG	0xc8	
#define DMAR_PQA_REG	0xd0	
#define DMAR_PRS_REG	0xdc	
#define DMAR_PECTL_REG	0xe0	
#define	DMAR_PEDATA_REG	0xe4	
#define	DMAR_PEADDR_REG	0xe8	
#define	DMAR_PEUADDR_REG 0xec	

#define OFFSET_STRIDE		(9)

#define dmar_readq(a) readq(a)
#define dmar_writeq(a,v) writeq(v,a)

#define DMAR_VER_MAJOR(v)		(((v) & 0xf0) >> 4)
#define DMAR_VER_MINOR(v)		((v) & 0x0f)


#define cap_5lp_support(c)	(((c) >> 60) & 1)
#define cap_pi_support(c)	(((c) >> 59) & 1)
#define cap_fl1gp_support(c)	(((c) >> 56) & 1)
#define cap_read_drain(c)	(((c) >> 55) & 1)
#define cap_write_drain(c)	(((c) >> 54) & 1)
#define cap_max_amask_val(c)	(((c) >> 48) & 0x3f)
#define cap_num_fault_regs(c)	((((c) >> 40) & 0xff) + 1)
#define cap_pgsel_inv(c)	(((c) >> 39) & 1)

#define cap_super_page_val(c)	(((c) >> 34) & 0xf)
#define cap_super_offset(c)	(((find_first_bit(&cap_super_page_val(c), 4)) \
					* OFFSET_STRIDE) + 21)

#define cap_fault_reg_offset(c)	((((c) >> 24) & 0x3ff) * 16)
#define cap_max_fault_reg_offset(c) \
	(cap_fault_reg_offset(c) + cap_num_fault_regs(c) * 16)

#define cap_zlr(c)		(((c) >> 22) & 1)
#define cap_isoch(c)		(((c) >> 23) & 1)
#define cap_mgaw(c)		((((c) >> 16) & 0x3f) + 1)
#define cap_sagaw(c)		(((c) >> 8) & 0x1f)
#define cap_caching_mode(c)	(((c) >> 7) & 1)
#define cap_phmr(c)		(((c) >> 6) & 1)
#define cap_plmr(c)		(((c) >> 5) & 1)
#define cap_rwbf(c)		(((c) >> 4) & 1)
#define cap_afl(c)		(((c) >> 3) & 1)
#define cap_ndoms(c)		(((unsigned long)1) << (4 + 2 * ((c) & 0x7)))


#define ecap_dit(e)		((e >> 41) & 0x1)
#define ecap_pasid(e)		((e >> 40) & 0x1)
#define ecap_pss(e)		((e >> 35) & 0x1f)
#define ecap_eafs(e)		((e >> 34) & 0x1)
#define ecap_nwfs(e)		((e >> 33) & 0x1)
#define ecap_srs(e)		((e >> 31) & 0x1)
#define ecap_ers(e)		((e >> 30) & 0x1)
#define ecap_prs(e)		((e >> 29) & 0x1)
#define ecap_broken_pasid(e)	((e >> 28) & 0x1)
#define ecap_dis(e)		((e >> 27) & 0x1)
#define ecap_nest(e)		((e >> 26) & 0x1)
#define ecap_mts(e)		((e >> 25) & 0x1)
#define ecap_ecs(e)		((e >> 24) & 0x1)
#define ecap_iotlb_offset(e) 	((((e) >> 8) & 0x3ff) * 16)
#define ecap_max_iotlb_offset(e) (ecap_iotlb_offset(e) + 16)
#define ecap_coherent(e)	((e) & 0x1)
#define ecap_qis(e)		((e) & 0x2)
#define ecap_pass_through(e)	((e >> 6) & 0x1)
#define ecap_eim_support(e)	((e >> 4) & 0x1)
#define ecap_ir_support(e)	((e >> 3) & 0x1)
#define ecap_dev_iotlb_support(e)	(((e) >> 2) & 0x1)
#define ecap_max_handle_mask(e) ((e >> 20) & 0xf)
#define ecap_sc_support(e)	((e >> 7) & 0x1) 


#define DMA_TLB_FLUSH_GRANU_OFFSET  60
#define DMA_TLB_GLOBAL_FLUSH (((u64)1) << 60)
#define DMA_TLB_DSI_FLUSH (((u64)2) << 60)
#define DMA_TLB_PSI_FLUSH (((u64)3) << 60)
#define DMA_TLB_IIRG(type) ((type >> 60) & 3)
#define DMA_TLB_IAIG(val) (((val) >> 57) & 3)
#define DMA_TLB_READ_DRAIN (((u64)1) << 49)
#define DMA_TLB_WRITE_DRAIN (((u64)1) << 48)
#define DMA_TLB_DID(id)	(((u64)((id) & 0xffff)) << 32)
#define DMA_TLB_IVT (((u64)1) << 63)
#define DMA_TLB_IH_NONLEAF (((u64)1) << 6)
#define DMA_TLB_MAX_SIZE (0x3f)


#define DMA_CCMD_INVL_GRANU_OFFSET  61
#define DMA_ID_TLB_GLOBAL_FLUSH	(((u64)1) << 4)
#define DMA_ID_TLB_DSI_FLUSH	(((u64)2) << 4)
#define DMA_ID_TLB_PSI_FLUSH	(((u64)3) << 4)
#define DMA_ID_TLB_READ_DRAIN	(((u64)1) << 7)
#define DMA_ID_TLB_WRITE_DRAIN	(((u64)1) << 6)
#define DMA_ID_TLB_DID(id)	(((u64)((id & 0xffff) << 16)))
#define DMA_ID_TLB_IH_NONLEAF	(((u64)1) << 6)
#define DMA_ID_TLB_ADDR(addr)	(addr)
#define DMA_ID_TLB_ADDR_MASK(mask)	(mask)


#define DMA_PMEN_EPM (((u32)1)<<31)
#define DMA_PMEN_PRS (((u32)1)<<0)


#define DMA_GCMD_TE (((u32)1) << 31)
#define DMA_GCMD_SRTP (((u32)1) << 30)
#define DMA_GCMD_SFL (((u32)1) << 29)
#define DMA_GCMD_EAFL (((u32)1) << 28)
#define DMA_GCMD_WBF (((u32)1) << 27)
#define DMA_GCMD_QIE (((u32)1) << 26)
#define DMA_GCMD_SIRTP (((u32)1) << 24)
#define DMA_GCMD_IRE (((u32) 1) << 25)
#define DMA_GCMD_CFI (((u32) 1) << 23)


#define DMA_GSTS_TES (((u32)1) << 31)
#define DMA_GSTS_RTPS (((u32)1) << 30)
#define DMA_GSTS_FLS (((u32)1) << 29)
#define DMA_GSTS_AFLS (((u32)1) << 28)
#define DMA_GSTS_WBFS (((u32)1) << 27)
#define DMA_GSTS_QIES (((u32)1) << 26)
#define DMA_GSTS_IRTPS (((u32)1) << 24)
#define DMA_GSTS_IRES (((u32)1) << 25)
#define DMA_GSTS_CFIS (((u32)1) << 23)


#define DMA_RTADDR_RTT (((u64)1) << 11)


#define DMA_CCMD_ICC (((u64)1) << 63)
#define DMA_CCMD_GLOBAL_INVL (((u64)1) << 61)
#define DMA_CCMD_DOMAIN_INVL (((u64)2) << 61)
#define DMA_CCMD_DEVICE_INVL (((u64)3) << 61)
#define DMA_CCMD_FM(m) (((u64)((m) & 0x3)) << 32)
#define DMA_CCMD_MASK_NOBIT 0
#define DMA_CCMD_MASK_1BIT 1
#define DMA_CCMD_MASK_2BIT 2
#define DMA_CCMD_MASK_3BIT 3
#define DMA_CCMD_SID(s) (((u64)((s) & 0xffff)) << 16)
#define DMA_CCMD_DID(d) ((u64)((d) & 0xffff))


#define DMA_FECTL_IM (((u32)1) << 31)


#define DMA_FSTS_PFO (1 << 0) 
#define DMA_FSTS_PPF (1 << 1) 
#define DMA_FSTS_IQE (1 << 4) 
#define DMA_FSTS_ICE (1 << 5) 
#define DMA_FSTS_ITE (1 << 6) 
#define DMA_FSTS_PRO (1 << 7) 
#define dma_fsts_fault_record_index(s) (((s) >> 8) & 0xff)


#define DMA_FRCD_F (((u32)1) << 31)
#define dma_frcd_type(d) ((d >> 30) & 1)
#define dma_frcd_fault_reason(c) (c & 0xff)
#define dma_frcd_source_id(c) (c & 0xffff)

#define dma_frcd_page_addr(d) (d & (((u64)-1) << PAGE_SHIFT))


#define DMA_PRS_PPR	((u32)1)

#define IOMMU_WAIT_OP(iommu, offset, op, cond, sts)			\
do {									\
	cycles_t start_time = get_cycles();				\
	while (1) {							\
		sts = op(iommu->reg + offset);				\
		if (cond)						\
			break;						\
		if (DMAR_OPERATION_TIMEOUT < (get_cycles() - start_time))\
			panic("DMAR hardware is malfunctioning\n");	\
		cpu_relax();						\
	}								\
} while (0)

#define QI_LENGTH	256	

enum {
	QI_FREE,
	QI_IN_USE,
	QI_DONE,
	QI_ABORT
};

#define QI_CC_TYPE		0x1
#define QI_IOTLB_TYPE		0x2
#define QI_DIOTLB_TYPE		0x3
#define QI_IEC_TYPE		0x4
#define QI_IWD_TYPE		0x5
#define QI_EIOTLB_TYPE		0x6
#define QI_PC_TYPE		0x7
#define QI_DEIOTLB_TYPE		0x8
#define QI_PGRP_RESP_TYPE	0x9
#define QI_PSTRM_RESP_TYPE	0xa

#define QI_IEC_SELECTIVE	(((u64)1) << 4)
#define QI_IEC_IIDEX(idx)	(((u64)(idx & 0xffff) << 32))
#define QI_IEC_IM(m)		(((u64)(m & 0x1f) << 27))

#define QI_IWD_STATUS_DATA(d)	(((u64)d) << 32)
#define QI_IWD_STATUS_WRITE	(((u64)1) << 5)

#define QI_IOTLB_DID(did) 	(((u64)did) << 16)
#define QI_IOTLB_DR(dr) 	(((u64)dr) << 7)
#define QI_IOTLB_DW(dw) 	(((u64)dw) << 6)
#define QI_IOTLB_GRAN(gran) 	(((u64)gran) >> (DMA_TLB_FLUSH_GRANU_OFFSET-4))
#define QI_IOTLB_ADDR(addr)	(((u64)addr) & VTD_PAGE_MASK)
#define QI_IOTLB_IH(ih)		(((u64)ih) << 6)
#define QI_IOTLB_AM(am)		(((u8)am))

#define QI_CC_FM(fm)		(((u64)fm) << 48)
#define QI_CC_SID(sid)		(((u64)sid) << 32)
#define QI_CC_DID(did)		(((u64)did) << 16)
#define QI_CC_GRAN(gran)	(((u64)gran) >> (DMA_CCMD_INVL_GRANU_OFFSET-4))

#define QI_DEV_IOTLB_SID(sid)	((u64)((sid) & 0xffff) << 32)
#define QI_DEV_IOTLB_QDEP(qdep)	(((qdep) & 0x1f) << 16)
#define QI_DEV_IOTLB_ADDR(addr)	((u64)(addr) & VTD_PAGE_MASK)
#define QI_DEV_IOTLB_PFSID(pfsid) (((u64)(pfsid & 0xf) << 12) | \
				   ((u64)((pfsid >> 4) & 0xfff) << 52))
#define QI_DEV_IOTLB_SIZE	1
#define QI_DEV_IOTLB_MAX_INVS	32

#define QI_PC_PASID(pasid)	(((u64)pasid) << 32)
#define QI_PC_DID(did)		(((u64)did) << 16)
#define QI_PC_GRAN(gran)	(((u64)gran) << 4)

#define QI_PC_ALL_PASIDS	(QI_PC_TYPE | QI_PC_GRAN(0))
#define QI_PC_PASID_SEL		(QI_PC_TYPE | QI_PC_GRAN(1))

#define QI_EIOTLB_ADDR(addr)	((u64)(addr) & VTD_PAGE_MASK)
#define QI_EIOTLB_GL(gl)	(((u64)gl) << 7)
#define QI_EIOTLB_IH(ih)	(((u64)ih) << 6)
#define QI_EIOTLB_AM(am)	(((u64)am))
#define QI_EIOTLB_PASID(pasid) 	(((u64)pasid) << 32)
#define QI_EIOTLB_DID(did)	(((u64)did) << 16)
#define QI_EIOTLB_GRAN(gran) 	(((u64)gran) << 4)

#define QI_DEV_EIOTLB_ADDR(a)	((u64)(a) & VTD_PAGE_MASK)
#define QI_DEV_EIOTLB_SIZE	(((u64)1) << 11)
#define QI_DEV_EIOTLB_GLOB(g)	((u64)(g) & 0x1)
#define QI_DEV_EIOTLB_PASID(p)	((u64)((p) & 0xfffff) << 32)
#define QI_DEV_EIOTLB_SID(sid)	((u64)((sid) & 0xffff) << 16)
#define QI_DEV_EIOTLB_QDEP(qd)	((u64)((qd) & 0x1f) << 4)
#define QI_DEV_EIOTLB_PFSID(pfsid) (((u64)(pfsid & 0xf) << 12) | \
				    ((u64)((pfsid >> 4) & 0xfff) << 52))
#define QI_DEV_EIOTLB_MAX_INVS	32

#define QI_PGRP_IDX(idx)	(((u64)(idx)) << 55)
#define QI_PGRP_PRIV(priv)	(((u64)(priv)) << 32)
#define QI_PGRP_RESP_CODE(res)	((u64)(res))
#define QI_PGRP_PASID(pasid)	(((u64)(pasid)) << 32)
#define QI_PGRP_DID(did)	(((u64)(did)) << 16)
#define QI_PGRP_PASID_P(p)	(((u64)(p)) << 4)

#define QI_PSTRM_ADDR(addr)	(((u64)(addr)) & VTD_PAGE_MASK)
#define QI_PSTRM_DEVFN(devfn)	(((u64)(devfn)) << 4)
#define QI_PSTRM_RESP_CODE(res)	((u64)(res))
#define QI_PSTRM_IDX(idx)	(((u64)(idx)) << 55)
#define QI_PSTRM_PRIV(priv)	(((u64)(priv)) << 32)
#define QI_PSTRM_BUS(bus)	(((u64)(bus)) << 24)
#define QI_PSTRM_PASID(pasid)	(((u64)(pasid)) << 4)

#define QI_RESP_SUCCESS		0x0
#define QI_RESP_INVALID		0x1
#define QI_RESP_FAILURE		0xf

#define QI_GRAN_ALL_ALL			0
#define QI_GRAN_NONG_ALL		1
#define QI_GRAN_NONG_PASID		2
#define QI_GRAN_PSI_PASID		3

struct qi_desc {
	u64 low, high;
};

struct q_inval {
	raw_spinlock_t  q_lock;
	struct qi_desc  *desc;          
	int             *desc_status;   
	int             free_head;      
	int             free_tail;      
	int             free_cnt;
};

#ifdef CONFIG_IRQ_REMAP

#define INTR_REMAP_PAGE_ORDER	8
#define INTR_REMAP_TABLE_REG_SIZE	0xf
#define INTR_REMAP_TABLE_REG_SIZE_MASK  0xf

#define INTR_REMAP_TABLE_ENTRIES	65536

struct irq_domain;

struct ir_table {
	struct irte *base;
	unsigned long *bitmap;
};
#endif

struct iommu_flush {
	void (*flush_context)(struct intel_iommu *iommu, u16 did, u16 sid,
			      u8 fm, u64 type);
	void (*flush_iotlb)(struct intel_iommu *iommu, u16 did, u64 addr,
			    unsigned int size_order, u64 type);
};

enum {
	SR_DMAR_FECTL_REG,
	SR_DMAR_FEDATA_REG,
	SR_DMAR_FEADDR_REG,
	SR_DMAR_FEUADDR_REG,
	MAX_SR_DMAR_REGS
};

#define VTD_FLAG_TRANS_PRE_ENABLED	(1 << 0)
#define VTD_FLAG_IRQ_REMAP_PRE_ENABLED	(1 << 1)

struct pasid_entry;
struct pasid_state_entry;
struct page_req_dsc;

struct dmar_domain {
	int	nid;			

	unsigned	iommu_refcnt[DMAR_UNITS_SUPPORTED];
					


	u16		iommu_did[DMAR_UNITS_SUPPORTED];
					

	bool has_iotlb_device;
	struct list_head devices;	
	struct iova_domain iovad;	

	struct dma_pte	*pgd;		
	int		gaw;		

	
	int		agaw;

	int		flags;		

	int		iommu_coherency;
	int		iommu_snooping; 
	int		iommu_count;	
	int		iommu_superpage;
	u64		max_addr;	

	struct iommu_domain domain;	
};

struct intel_iommu {
	void __iomem	*reg; 
	u64 		reg_phys; 
	u64		reg_size; 
	u64		cap;
	u64		ecap;
	u32		gcmd; 
	raw_spinlock_t	register_lock; 
	int		seq_id;	
	int		agaw; 
	int		msagaw; 
	unsigned int 	irq, pr_irq;
	u16		segment;     
	unsigned char 	name[13];    

#ifdef CONFIG_INTEL_IOMMU
	unsigned long 	*domain_ids; 
	struct dmar_domain ***domains; 
	spinlock_t	lock; 
	struct root_entry *root_entry; 

	struct iommu_flush flush;
#endif
#ifdef CONFIG_INTEL_IOMMU_SVM
	
	struct pasid_state_entry *pasid_state_table;
	struct page_req_dsc *prq;
	unsigned char prq_name[16];    
	u32 pasid_max;
#endif
	struct q_inval  *qi;            
	u32 *iommu_state; 

#ifdef CONFIG_IRQ_REMAP
	struct ir_table *ir_table;	
	struct irq_domain *ir_domain;
	struct irq_domain *ir_msi_domain;
#endif
	struct iommu_device iommu;  
	int		node;
	u32		flags;      
};


struct device_domain_info {
	struct list_head link;	
	struct list_head global; 
	struct list_head table;	
	u8 bus;			
	u8 devfn;		
	u16 pfsid;		
	u8 pasid_supported:3;
	u8 pasid_enabled:1;
	u8 pri_supported:1;
	u8 pri_enabled:1;
	u8 ats_supported:1;
	u8 ats_enabled:1;
	u8 ats_qdep;
	struct device *dev; 
	struct intel_iommu *iommu; 
	struct dmar_domain *domain; 
	struct pasid_table *pasid_table; 
};

static inline void __iommu_flush_cache(
	struct intel_iommu *iommu, void *addr, int size)
{
	if (!ecap_coherent(iommu->ecap))
		clflush_cache_range(addr, size);
}

extern struct dmar_drhd_unit * dmar_find_matched_drhd_unit(struct pci_dev *dev);
extern int dmar_find_matched_atsr_unit(struct pci_dev *dev);

extern int dmar_enable_qi(struct intel_iommu *iommu);
extern void dmar_disable_qi(struct intel_iommu *iommu);
extern int dmar_reenable_qi(struct intel_iommu *iommu);
extern void qi_global_iec(struct intel_iommu *iommu);

extern void qi_flush_context(struct intel_iommu *iommu, u16 did, u16 sid,
			     u8 fm, u64 type);
extern void qi_flush_iotlb(struct intel_iommu *iommu, u16 did, u64 addr,
			  unsigned int size_order, u64 type);
extern void qi_flush_dev_iotlb(struct intel_iommu *iommu, u16 sid, u16 pfsid,
			u16 qdep, u64 addr, unsigned mask);
extern int qi_submit_sync(struct qi_desc *desc, struct intel_iommu *iommu);

extern int dmar_ir_support(void);

struct dmar_domain *get_valid_domain_for_dev(struct device *dev);
void *alloc_pgtable_page(int node);
void free_pgtable_page(void *vaddr);
struct intel_iommu *domain_get_iommu(struct dmar_domain *domain);
int for_each_device_domain(int (*fn)(struct device_domain_info *info,
				     void *data), void *data);

#ifdef CONFIG_INTEL_IOMMU_SVM
int intel_svm_init(struct intel_iommu *iommu);
int intel_svm_exit(struct intel_iommu *iommu);
extern int intel_svm_enable_prq(struct intel_iommu *iommu);
extern int intel_svm_finish_prq(struct intel_iommu *iommu);

struct svm_dev_ops;

struct intel_svm_dev {
	struct list_head list;
	struct rcu_head rcu;
	struct device *dev;
	struct svm_dev_ops *ops;
	int users;
	u16 did;
	u16 dev_iotlb:1;
	u16 sid, qdep;
};

struct intel_svm {
	struct mmu_notifier notifier;
	struct mm_struct *mm;
	struct intel_iommu *iommu;
	int flags;
	int pasid;
	struct list_head devs;
	struct list_head list;
};

extern int intel_iommu_enable_pasid(struct intel_iommu *iommu, struct intel_svm_dev *sdev);
extern struct intel_iommu *intel_svm_device_to_iommu(struct device *dev);
#endif

extern const struct attribute_group *intel_iommu_groups[];

#endif
