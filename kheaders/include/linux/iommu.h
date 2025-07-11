

#ifndef __LINUX_IOMMU_H
#define __LINUX_IOMMU_H

#include <linux/scatterlist.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/of.h>

#define IOMMU_READ	(1 << 0)
#define IOMMU_WRITE	(1 << 1)
#define IOMMU_CACHE	(1 << 2) 
#define IOMMU_NOEXEC	(1 << 3)
#define IOMMU_MMIO	(1 << 4) 

#define IOMMU_PRIV	(1 << 5)

#define IOMMU_USE_UPSTREAM_HINT	(1 << 6)


#define IOMMU_USE_LLC_NWA	(1 << 7)

struct iommu_ops;
struct iommu_group;
struct bus_type;
struct device;
struct iommu_domain;
struct notifier_block;


#define IOMMU_FAULT_READ                (1 << 0)
#define IOMMU_FAULT_WRITE               (1 << 1)
#define IOMMU_FAULT_TRANSLATION         (1 << 2)
#define IOMMU_FAULT_PERMISSION          (1 << 3)
#define IOMMU_FAULT_EXTERNAL            (1 << 4)
#define IOMMU_FAULT_TRANSACTION_STALLED (1 << 5)

typedef int (*iommu_fault_handler_t)(struct iommu_domain *,
			struct device *, unsigned long, int, void *);

struct iommu_fault_ids {
	u32 bid;
	u32 pid;
	u32 mid;
};

struct iommu_domain_geometry {
	dma_addr_t aperture_start; 
	dma_addr_t aperture_end;   
	bool force_aperture;       
};


#define IOMMU_TRANS_WRITE	BIT(0)	
#define IOMMU_TRANS_PRIV	BIT(1)	
#define IOMMU_TRANS_INST	BIT(2)	
#define IOMMU_TRANS_SEC	BIT(3)	


#define IOMMU_TRANS_DEFAULT	(0U)

struct iommu_pgtbl_info {
	void *ops;
};


#define __IOMMU_DOMAIN_PAGING	(1U << 0)  
#define __IOMMU_DOMAIN_DMA_API	(1U << 1)  
#define __IOMMU_DOMAIN_PT	(1U << 2)  


#define IOMMU_DOMAIN_BLOCKED	(0U)
#define IOMMU_DOMAIN_IDENTITY	(__IOMMU_DOMAIN_PT)
#define IOMMU_DOMAIN_UNMANAGED	(__IOMMU_DOMAIN_PAGING)
#define IOMMU_DOMAIN_DMA	(__IOMMU_DOMAIN_PAGING |	\
				 __IOMMU_DOMAIN_DMA_API)


#define IOMMU_DOMAIN_NAME_LEN 32
struct iommu_domain {
	unsigned type;
	const struct iommu_ops *ops;
	unsigned long pgsize_bitmap;	
	iommu_fault_handler_t handler;
	void *handler_token;
	struct iommu_domain_geometry geometry;
	void *iova_cookie;
	bool is_debug_domain;
	char name[IOMMU_DOMAIN_NAME_LEN];
};

enum iommu_cap {
	IOMMU_CAP_CACHE_COHERENCY,	
	IOMMU_CAP_INTR_REMAP,		
	IOMMU_CAP_NOEXEC,		
};



enum iommu_attr {
	DOMAIN_ATTR_GEOMETRY,
	DOMAIN_ATTR_PAGING,
	DOMAIN_ATTR_WINDOWS,
	DOMAIN_ATTR_FSL_PAMU_STASH,
	DOMAIN_ATTR_FSL_PAMU_ENABLE,
	DOMAIN_ATTR_FSL_PAMUV1,
	DOMAIN_ATTR_NESTING,	
	DOMAIN_ATTR_PT_BASE_ADDR,
	DOMAIN_ATTR_CONTEXT_BANK,
	DOMAIN_ATTR_DYNAMIC,
	DOMAIN_ATTR_TTBR0,
	DOMAIN_ATTR_CONTEXTIDR,
	DOMAIN_ATTR_PROCID,
	DOMAIN_ATTR_NON_FATAL_FAULTS,
	DOMAIN_ATTR_S1_BYPASS,
	DOMAIN_ATTR_ATOMIC,
	DOMAIN_ATTR_SECURE_VMID,
	DOMAIN_ATTR_FAST,
	DOMAIN_ATTR_PGTBL_INFO,
	DOMAIN_ATTR_USE_UPSTREAM_HINT,
	DOMAIN_ATTR_EARLY_MAP,
	DOMAIN_ATTR_PAGE_TABLE_IS_COHERENT,
	DOMAIN_ATTR_PAGE_TABLE_FORCE_COHERENT,
	DOMAIN_ATTR_BITMAP_IOVA_ALLOCATOR,
	DOMAIN_ATTR_USE_LLC_NWA,
	DOMAIN_ATTR_FAULT_MODEL_NO_CFRE,
	DOMAIN_ATTR_FAULT_MODEL_NO_STALL,
	DOMAIN_ATTR_FAULT_MODEL_HUPCF,
	DOMAIN_ATTR_MAX,
};


enum iommu_resv_type {
	
	IOMMU_RESV_DIRECT,
	
	IOMMU_RESV_RESERVED,
	
	IOMMU_RESV_MSI,
	
	IOMMU_RESV_SW_MSI,
};


struct iommu_resv_region {
	struct list_head	list;
	phys_addr_t		start;
	size_t			length;
	int			prot;
	enum iommu_resv_type	type;
};

extern struct dentry *iommu_debugfs_top;

#ifdef CONFIG_IOMMU_API


struct iommu_ops {
	bool (*capable)(enum iommu_cap);

	
	struct iommu_domain *(*domain_alloc)(unsigned iommu_domain_type);
	void (*domain_free)(struct iommu_domain *);

	int (*attach_dev)(struct iommu_domain *domain, struct device *dev);
	void (*detach_dev)(struct iommu_domain *domain, struct device *dev);
	int (*map)(struct iommu_domain *domain, unsigned long iova,
		   phys_addr_t paddr, size_t size, int prot);
	size_t (*unmap)(struct iommu_domain *domain, unsigned long iova,
		     size_t size);
	size_t (*map_sg)(struct iommu_domain *domain, unsigned long iova,
			 struct scatterlist *sg, unsigned int nents, int prot);
	void (*flush_iotlb_all)(struct iommu_domain *domain);
	void (*iotlb_range_add)(struct iommu_domain *domain,
				unsigned long iova, size_t size);
	void (*iotlb_sync)(struct iommu_domain *domain);
	phys_addr_t (*iova_to_phys)(struct iommu_domain *domain, dma_addr_t iova);
	phys_addr_t (*iova_to_phys_hard)(struct iommu_domain *domain,
				 dma_addr_t iova, unsigned long trans_flags);
	int (*add_device)(struct device *dev);
	void (*remove_device)(struct device *dev);
	struct iommu_group *(*device_group)(struct device *dev);
	int (*domain_get_attr)(struct iommu_domain *domain,
			       enum iommu_attr attr, void *data);
	int (*domain_set_attr)(struct iommu_domain *domain,
			       enum iommu_attr attr, void *data);

	
	void (*get_resv_regions)(struct device *dev, struct list_head *list);
	void (*put_resv_regions)(struct device *dev, struct list_head *list);
	void (*apply_resv_region)(struct device *dev,
				  struct iommu_domain *domain,
				  struct iommu_resv_region *region);

	
	int (*domain_window_enable)(struct iommu_domain *domain, u32 wnd_nr,
				    phys_addr_t paddr, u64 size, int prot);
	void (*domain_window_disable)(struct iommu_domain *domain, u32 wnd_nr);
	
	int (*domain_set_windows)(struct iommu_domain *domain, u32 w_count);
	
	u32 (*domain_get_windows)(struct iommu_domain *domain);
	void (*trigger_fault)(struct iommu_domain *domain, unsigned long flags);
	void (*tlbi_domain)(struct iommu_domain *domain);
	int (*enable_config_clocks)(struct iommu_domain *domain);
	void (*disable_config_clocks)(struct iommu_domain *domain);
	uint64_t (*iova_to_pte)(struct iommu_domain *domain,
			 dma_addr_t iova);

	int (*of_xlate)(struct device *dev, struct of_phandle_args *args);
	bool (*is_attach_deferred)(struct iommu_domain *domain, struct device *dev);

	bool (*is_iova_coherent)(struct iommu_domain *domain, dma_addr_t iova);
	unsigned long pgsize_bitmap;
};


struct iommu_device {
	struct list_head list;
	const struct iommu_ops *ops;
	struct fwnode_handle *fwnode;
	struct device *dev;
};

int  iommu_device_register(struct iommu_device *iommu);
void iommu_device_unregister(struct iommu_device *iommu);
int  iommu_device_sysfs_add(struct iommu_device *iommu,
			    struct device *parent,
			    const struct attribute_group **groups,
			    const char *fmt, ...) __printf(4, 5);
void iommu_device_sysfs_remove(struct iommu_device *iommu);
int  iommu_device_link(struct iommu_device   *iommu, struct device *link);
void iommu_device_unlink(struct iommu_device *iommu, struct device *link);

static inline void iommu_device_set_ops(struct iommu_device *iommu,
					const struct iommu_ops *ops)
{
	iommu->ops = ops;
}

static inline void iommu_device_set_fwnode(struct iommu_device *iommu,
					   struct fwnode_handle *fwnode)
{
	iommu->fwnode = fwnode;
}

static inline struct iommu_device *dev_to_iommu_device(struct device *dev)
{
	return (struct iommu_device *)dev_get_drvdata(dev);
}

#define IOMMU_GROUP_NOTIFY_ADD_DEVICE		1 
#define IOMMU_GROUP_NOTIFY_DEL_DEVICE		2 
#define IOMMU_GROUP_NOTIFY_BIND_DRIVER		3 
#define IOMMU_GROUP_NOTIFY_BOUND_DRIVER		4 
#define IOMMU_GROUP_NOTIFY_UNBIND_DRIVER	5 
#define IOMMU_GROUP_NOTIFY_UNBOUND_DRIVER	6 

extern int bus_set_iommu(struct bus_type *bus, const struct iommu_ops *ops);
extern bool iommu_present(struct bus_type *bus);
extern bool iommu_capable(struct bus_type *bus, enum iommu_cap cap);
extern struct iommu_domain *iommu_domain_alloc(struct bus_type *bus);
extern struct iommu_group *iommu_group_get_by_id(int id);
extern void iommu_domain_free(struct iommu_domain *domain);
extern int iommu_attach_device(struct iommu_domain *domain,
			       struct device *dev);
extern void iommu_detach_device(struct iommu_domain *domain,
				struct device *dev);
extern struct iommu_domain *iommu_get_domain_for_dev(struct device *dev);
extern size_t iommu_pgsize(unsigned long pgsize_bitmap,
			   unsigned long addr_merge, size_t size);
extern int iommu_map(struct iommu_domain *domain, unsigned long iova,
		     phys_addr_t paddr, size_t size, int prot);
extern size_t iommu_unmap(struct iommu_domain *domain, unsigned long iova,
			  size_t size);
extern size_t iommu_unmap_fast(struct iommu_domain *domain,
			       unsigned long iova, size_t size);
extern size_t iommu_map_sg(struct iommu_domain *domain, unsigned long iova,
				struct scatterlist *sg, unsigned int nents,
				int prot);
extern size_t default_iommu_map_sg(struct iommu_domain *domain, unsigned long iova,
			   struct scatterlist *sg,unsigned int nents, int prot);
extern phys_addr_t iommu_iova_to_phys(struct iommu_domain *domain, dma_addr_t iova);
extern phys_addr_t iommu_iova_to_phys_hard(struct iommu_domain *domain,
				   dma_addr_t iova, unsigned long trans_flags);
extern bool iommu_is_iova_coherent(struct iommu_domain *domain,
				dma_addr_t iova);
extern void iommu_set_fault_handler(struct iommu_domain *domain,
			iommu_fault_handler_t handler, void *token);
extern int iommu_get_fault_ids(struct iommu_domain *domain,
				struct iommu_fault_ids *f_ids);
extern void iommu_get_resv_regions(struct device *dev, struct list_head *list);
extern void iommu_put_resv_regions(struct device *dev, struct list_head *list);
extern int iommu_request_dm_for_dev(struct device *dev);
extern struct iommu_resv_region *
iommu_alloc_resv_region(phys_addr_t start, size_t length, int prot,
			enum iommu_resv_type type);
extern int iommu_get_group_resv_regions(struct iommu_group *group,
					struct list_head *head);

extern int iommu_attach_group(struct iommu_domain *domain,
			      struct iommu_group *group);
extern void iommu_detach_group(struct iommu_domain *domain,
			       struct iommu_group *group);
extern struct iommu_group *iommu_group_alloc(void);
extern void *iommu_group_get_iommudata(struct iommu_group *group);
extern void iommu_group_set_iommudata(struct iommu_group *group,
				      void *iommu_data,
				      void (*release)(void *iommu_data));
extern int iommu_group_set_name(struct iommu_group *group, const char *name);
extern int iommu_group_add_device(struct iommu_group *group,
				  struct device *dev);
extern void iommu_group_remove_device(struct device *dev);
extern int iommu_group_for_each_dev(struct iommu_group *group, void *data,
				    int (*fn)(struct device *, void *));
extern struct iommu_group *iommu_group_get(struct device *dev);
extern struct iommu_group *iommu_group_ref_get(struct iommu_group *group);
extern void iommu_group_put(struct iommu_group *group);
extern int iommu_group_register_notifier(struct iommu_group *group,
					 struct notifier_block *nb);
extern int iommu_group_unregister_notifier(struct iommu_group *group,
					   struct notifier_block *nb);
extern int iommu_group_id(struct iommu_group *group);
extern struct iommu_group *iommu_group_get_for_dev(struct device *dev);
extern struct iommu_domain *iommu_group_default_domain(struct iommu_group *);

extern int iommu_domain_get_attr(struct iommu_domain *domain, enum iommu_attr,
				 void *data);
extern int iommu_domain_set_attr(struct iommu_domain *domain, enum iommu_attr,
				 void *data);


extern int iommu_domain_window_enable(struct iommu_domain *domain, u32 wnd_nr,
				      phys_addr_t offset, u64 size,
				      int prot);
extern void iommu_domain_window_disable(struct iommu_domain *domain, u32 wnd_nr);

extern uint64_t iommu_iova_to_pte(struct iommu_domain *domain,
	    dma_addr_t iova);

extern int report_iommu_fault(struct iommu_domain *domain, struct device *dev,
			      unsigned long iova, int flags);

static inline void iommu_flush_tlb_all(struct iommu_domain *domain)
{
	if (domain->ops->flush_iotlb_all)
		domain->ops->flush_iotlb_all(domain);
}

static inline void iommu_tlb_range_add(struct iommu_domain *domain,
				       unsigned long iova, size_t size)
{
	if (domain->ops->iotlb_range_add)
		domain->ops->iotlb_range_add(domain, iova, size);
}

static inline void iommu_tlb_sync(struct iommu_domain *domain)
{
	if (domain->ops->iotlb_sync)
		domain->ops->iotlb_sync(domain);
}

extern void iommu_trigger_fault(struct iommu_domain *domain,
				unsigned long flags);

extern unsigned long iommu_reg_read(struct iommu_domain *domain,
				    unsigned long offset);
extern void iommu_reg_write(struct iommu_domain *domain, unsigned long offset,
			    unsigned long val);


extern struct iommu_group *pci_device_group(struct device *dev);

extern struct iommu_group *generic_device_group(struct device *dev);

static inline void iommu_tlbiall(struct iommu_domain *domain)
{
	if (domain->ops->tlbi_domain)
		domain->ops->tlbi_domain(domain);
}

static inline int iommu_enable_config_clocks(struct iommu_domain *domain)
{
	if (domain->ops->enable_config_clocks)
		return domain->ops->enable_config_clocks(domain);
	return 0;
}

static inline void iommu_disable_config_clocks(struct iommu_domain *domain)
{
	if (domain->ops->disable_config_clocks)
		domain->ops->disable_config_clocks(domain);
}


struct iommu_fwspec {
	const struct iommu_ops	*ops;
	struct fwnode_handle	*iommu_fwnode;
	void			*iommu_priv;
	unsigned int		num_ids;
	u32			ids[1];
};

int iommu_fwspec_init(struct device *dev, struct fwnode_handle *iommu_fwnode,
		      const struct iommu_ops *ops);
void iommu_fwspec_free(struct device *dev);
int iommu_fwspec_add_ids(struct device *dev, u32 *ids, int num_ids);
const struct iommu_ops *iommu_ops_from_fwnode(struct fwnode_handle *fwnode);
int iommu_fwspec_get_id(struct device *dev, u32 *id);
int iommu_is_available(struct device *dev);

#else 

struct iommu_ops {};
struct iommu_group {};
struct iommu_fwspec {};
struct iommu_device {};

static inline bool iommu_present(struct bus_type *bus)
{
	return false;
}

static inline bool iommu_capable(struct bus_type *bus, enum iommu_cap cap)
{
	return false;
}

static inline struct iommu_domain *iommu_domain_alloc(struct bus_type *bus)
{
	return NULL;
}

static inline struct iommu_group *iommu_group_get_by_id(int id)
{
	return NULL;
}

static inline void iommu_domain_free(struct iommu_domain *domain)
{
}

static inline int iommu_attach_device(struct iommu_domain *domain,
				      struct device *dev)
{
	return -ENODEV;
}

static inline void iommu_detach_device(struct iommu_domain *domain,
				       struct device *dev)
{
}

static inline struct iommu_domain *iommu_get_domain_for_dev(struct device *dev)
{
	return NULL;
}

static inline int iommu_map(struct iommu_domain *domain, unsigned long iova,
			    phys_addr_t paddr, size_t size, int prot)
{
	return -ENODEV;
}

static inline size_t iommu_unmap(struct iommu_domain *domain,
				 unsigned long iova, size_t size)
{
	return 0;
}

static inline size_t iommu_unmap_fast(struct iommu_domain *domain,
				      unsigned long iova, int gfp_order)
{
	return 0;
}

static inline size_t iommu_map_sg(struct iommu_domain *domain,
				  unsigned long iova, struct scatterlist *sg,
				  unsigned int nents, int prot)
{
	return 0;
}

static inline void iommu_flush_tlb_all(struct iommu_domain *domain)
{
}

static inline void iommu_tlb_range_add(struct iommu_domain *domain,
				       unsigned long iova, size_t size)
{
}

static inline void iommu_tlb_sync(struct iommu_domain *domain)
{
}

static inline int iommu_domain_window_enable(struct iommu_domain *domain,
					     u32 wnd_nr, phys_addr_t paddr,
					     u64 size, int prot)
{
	return -ENODEV;
}

static inline void iommu_domain_window_disable(struct iommu_domain *domain,
					       u32 wnd_nr)
{
}

static inline phys_addr_t iommu_iova_to_phys(struct iommu_domain *domain, dma_addr_t iova)
{
	return 0;
}

static inline phys_addr_t iommu_iova_to_phys_hard(struct iommu_domain *domain,
				dma_addr_t iova, unsigned long trans_flags)
{
	return 0;
}

static inline bool iommu_is_iova_coherent(struct iommu_domain *domain,
					  dma_addr_t iova)
{
	return 0;
}

static inline void iommu_set_fault_handler(struct iommu_domain *domain,
				iommu_fault_handler_t handler, void *token)
{
}
static inline int iommu_get_fault_ids(struct iommu_domain *domain,
				struct iommu_fault_ids *f_ids)
{
	return -EINVAL;
}

static inline void iommu_get_resv_regions(struct device *dev,
					struct list_head *list)
{
}
static inline void iommu_put_resv_regions(struct device *dev,
					struct list_head *list)
{
}

static inline int iommu_get_group_resv_regions(struct iommu_group *group,
					       struct list_head *head)
{
	return -ENODEV;
}

static inline int iommu_request_dm_for_dev(struct device *dev)
{
	return -ENODEV;
}

static inline int iommu_attach_group(struct iommu_domain *domain,
				     struct iommu_group *group)
{
	return -ENODEV;
}

static inline void iommu_detach_group(struct iommu_domain *domain,
				      struct iommu_group *group)
{
}

static inline struct iommu_group *iommu_group_alloc(void)
{
	return ERR_PTR(-ENODEV);
}

static inline void *iommu_group_get_iommudata(struct iommu_group *group)
{
	return NULL;
}

static inline void iommu_group_set_iommudata(struct iommu_group *group,
					     void *iommu_data,
					     void (*release)(void *iommu_data))
{
}

static inline int iommu_group_set_name(struct iommu_group *group,
				       const char *name)
{
	return -ENODEV;
}

static inline int iommu_group_add_device(struct iommu_group *group,
					 struct device *dev)
{
	return -ENODEV;
}

static inline void iommu_group_remove_device(struct device *dev)
{
}

static inline int iommu_group_for_each_dev(struct iommu_group *group,
					   void *data,
					   int (*fn)(struct device *, void *))
{
	return -ENODEV;
}

static inline struct iommu_group *iommu_group_get(struct device *dev)
{
	return NULL;
}

static inline void iommu_group_put(struct iommu_group *group)
{
}

static inline int iommu_group_register_notifier(struct iommu_group *group,
						struct notifier_block *nb)
{
	return -ENODEV;
}

static inline int iommu_group_unregister_notifier(struct iommu_group *group,
						  struct notifier_block *nb)
{
	return 0;
}

static inline int iommu_group_id(struct iommu_group *group)
{
	return -ENODEV;
}

static inline int iommu_domain_get_attr(struct iommu_domain *domain,
					enum iommu_attr attr, void *data)
{
	return -EINVAL;
}

static inline int iommu_domain_set_attr(struct iommu_domain *domain,
					enum iommu_attr attr, void *data)
{
	return -EINVAL;
}

static inline int  iommu_device_register(struct iommu_device *iommu)
{
	return -ENODEV;
}

static inline void iommu_device_set_ops(struct iommu_device *iommu,
					const struct iommu_ops *ops)
{
}

static inline void iommu_device_set_fwnode(struct iommu_device *iommu,
					   struct fwnode_handle *fwnode)
{
}

static inline struct iommu_device *dev_to_iommu_device(struct device *dev)
{
	return NULL;
}

static inline void iommu_device_unregister(struct iommu_device *iommu)
{
}

static inline int  iommu_device_sysfs_add(struct iommu_device *iommu,
					  struct device *parent,
					  const struct attribute_group **groups,
					  const char *fmt, ...)
{
	return -ENODEV;
}

static inline void iommu_device_sysfs_remove(struct iommu_device *iommu)
{
}

static inline int iommu_device_link(struct device *dev, struct device *link)
{
	return -EINVAL;
}

static inline void iommu_device_unlink(struct device *dev, struct device *link)
{
}

static inline void iommu_trigger_fault(struct iommu_domain *domain,
				       unsigned long flags)
{
}

static inline unsigned long iommu_reg_read(struct iommu_domain *domain,
					   unsigned long offset)
{
	return 0;
}

static inline void iommu_reg_write(struct iommu_domain *domain,
				   unsigned long val, unsigned long offset)
{
}

static inline void iommu_tlbiall(struct iommu_domain *domain)
{
}

static inline int iommu_enable_config_clocks(struct iommu_domain *domain)
{
	return 0;
}

static inline void iommu_disable_config_clocks(struct iommu_domain *domain)
{
}

static inline int iommu_fwspec_init(struct device *dev,
				    struct fwnode_handle *iommu_fwnode,
				    const struct iommu_ops *ops)
{
	return -ENODEV;
}

static inline void iommu_fwspec_free(struct device *dev)
{
}

static inline int iommu_fwspec_add_ids(struct device *dev, u32 *ids,
				       int num_ids)
{
	return -ENODEV;
}

static inline
const struct iommu_ops *iommu_ops_from_fwnode(struct fwnode_handle *fwnode)
{
	return NULL;
}

static inline int iommu_fwspec_get_id(struct device *dev, u32 *id)
{
	return -ENODEV;
}

static inline int iommu_is_available(struct device *dev)
{
	return -ENODEV;
}
#endif 

#ifdef CONFIG_IOMMU_DEBUGFS
extern	struct dentry *iommu_debugfs_dir;
void iommu_debugfs_setup(void);
#else
static inline void iommu_debugfs_setup(void) {}
#endif

#endif 
