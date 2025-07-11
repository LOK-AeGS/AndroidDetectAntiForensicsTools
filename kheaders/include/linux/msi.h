/* SPDX-License-Identifier: GPL-2.0 */
#ifndef LINUX_MSI_H
#define LINUX_MSI_H

#include <linux/kobject.h>
#include <linux/list.h>

struct msi_msg {
	u32	address_lo;	
	u32	address_hi;	
	u32	data;		
};

extern int pci_msi_ignore_mask;

struct irq_data;
struct msi_desc;
struct pci_dev;
struct platform_msi_priv_data;
void __get_cached_msi_msg(struct msi_desc *entry, struct msi_msg *msg);
#ifdef CONFIG_GENERIC_MSI_IRQ
void get_cached_msi_msg(unsigned int irq, struct msi_msg *msg);
#else
static inline void get_cached_msi_msg(unsigned int irq, struct msi_msg *msg)
{
}
#endif

typedef void (*irq_write_msi_msg_t)(struct msi_desc *desc,
				    struct msi_msg *msg);


struct platform_msi_desc {
	struct platform_msi_priv_data	*msi_priv_data;
	u16				msi_index;
};


struct fsl_mc_msi_desc {
	u16				msi_index;
};


struct msi_desc {
	
	struct list_head		list;
	unsigned int			irq;
	unsigned int			nvec_used;
	struct device			*dev;
	struct msi_msg			msg;
	struct cpumask			*affinity;

	union {
		
		struct {
			u32 masked;
			struct {
				__u8	is_msix		: 1;
				__u8	multiple	: 3;
				__u8	multi_cap	: 3;
				__u8	maskbit		: 1;
				__u8	is_64		: 1;
				__u16	entry_nr;
				unsigned default_irq;
			} msi_attrib;
			union {
				u8	mask_pos;
				void __iomem *mask_base;
			};
		};

		
		struct platform_msi_desc platform;
		struct fsl_mc_msi_desc fsl_mc;
	};
};


#define msi_desc_to_dev(desc)		((desc)->dev)
#define dev_to_msi_list(dev)		(&(dev)->msi_list)
#define first_msi_entry(dev)		\
	list_first_entry(dev_to_msi_list((dev)), struct msi_desc, list)
#define for_each_msi_entry(desc, dev)	\
	list_for_each_entry((desc), dev_to_msi_list((dev)), list)
#define for_each_msi_entry_safe(desc, tmp, dev)	\
	list_for_each_entry_safe((desc), (tmp), dev_to_msi_list((dev)), list)

#ifdef CONFIG_PCI_MSI
#define first_pci_msi_entry(pdev)	first_msi_entry(&(pdev)->dev)
#define for_each_pci_msi_entry(desc, pdev)	\
	for_each_msi_entry((desc), &(pdev)->dev)

struct pci_dev *msi_desc_to_pci_dev(struct msi_desc *desc);
void *msi_desc_to_pci_sysdata(struct msi_desc *desc);
void pci_write_msi_msg(unsigned int irq, struct msi_msg *msg);
#else 
static inline void *msi_desc_to_pci_sysdata(struct msi_desc *desc)
{
	return NULL;
}
static inline void pci_write_msi_msg(unsigned int irq, struct msi_msg *msg)
{
}
#endif 

struct msi_desc *alloc_msi_entry(struct device *dev, int nvec,
				 const struct cpumask *affinity);
void free_msi_entry(struct msi_desc *entry);
void __pci_read_msi_msg(struct msi_desc *entry, struct msi_msg *msg);
void __pci_write_msi_msg(struct msi_desc *entry, struct msi_msg *msg);

u32 __pci_msix_desc_mask_irq(struct msi_desc *desc, u32 flag);
u32 __pci_msi_desc_mask_irq(struct msi_desc *desc, u32 mask, u32 flag);
void pci_msi_mask_irq(struct irq_data *data);
void pci_msi_unmask_irq(struct irq_data *data);


static inline void __write_msi_msg(struct msi_desc *entry, struct msi_msg *msg)
{
	__pci_write_msi_msg(entry, msg);
}
static inline void write_msi_msg(int irq, struct msi_msg *msg)
{
	pci_write_msi_msg(irq, msg);
}
static inline void mask_msi_irq(struct irq_data *data)
{
	pci_msi_mask_irq(data);
}
static inline void unmask_msi_irq(struct irq_data *data)
{
	pci_msi_unmask_irq(data);
}


int arch_setup_msi_irq(struct pci_dev *dev, struct msi_desc *desc);
void arch_teardown_msi_irq(unsigned int irq);
int arch_setup_msi_irqs(struct pci_dev *dev, int nvec, int type);
void arch_teardown_msi_irqs(struct pci_dev *dev);
void arch_restore_msi_irqs(struct pci_dev *dev);

void default_teardown_msi_irqs(struct pci_dev *dev);
void default_restore_msi_irqs(struct pci_dev *dev);

struct msi_controller {
	struct module *owner;
	struct device *dev;
	struct device_node *of_node;
	struct list_head list;

	int (*setup_irq)(struct msi_controller *chip, struct pci_dev *dev,
			 struct msi_desc *desc);
	int (*setup_irqs)(struct msi_controller *chip, struct pci_dev *dev,
			  int nvec, int type);
	void (*teardown_irq)(struct msi_controller *chip, unsigned int irq);
};

#ifdef CONFIG_GENERIC_MSI_IRQ_DOMAIN

#include <linux/irqhandler.h>
#include <asm/msi.h>

struct irq_domain;
struct irq_domain_ops;
struct irq_chip;
struct device_node;
struct fwnode_handle;
struct msi_domain_info;


struct msi_domain_ops {
	irq_hw_number_t	(*get_hwirq)(struct msi_domain_info *info,
				     msi_alloc_info_t *arg);
	int		(*msi_init)(struct irq_domain *domain,
				    struct msi_domain_info *info,
				    unsigned int virq, irq_hw_number_t hwirq,
				    msi_alloc_info_t *arg);
	void		(*msi_free)(struct irq_domain *domain,
				    struct msi_domain_info *info,
				    unsigned int virq);
	int		(*msi_check)(struct irq_domain *domain,
				     struct msi_domain_info *info,
				     struct device *dev);
	int		(*msi_prepare)(struct irq_domain *domain,
				       struct device *dev, int nvec,
				       msi_alloc_info_t *arg);
	void		(*msi_finish)(msi_alloc_info_t *arg, int retval);
	void		(*set_desc)(msi_alloc_info_t *arg,
				    struct msi_desc *desc);
	int		(*handle_error)(struct irq_domain *domain,
					struct msi_desc *desc, int error);
};


struct msi_domain_info {
	u32			flags;
	struct msi_domain_ops	*ops;
	struct irq_chip		*chip;
	void			*chip_data;
	irq_flow_handler_t	handler;
	void			*handler_data;
	const char		*handler_name;
	void			*data;
};


enum {
	
	MSI_FLAG_USE_DEF_DOM_OPS	= (1 << 0),
	
	MSI_FLAG_USE_DEF_CHIP_OPS	= (1 << 1),
	
	MSI_FLAG_MULTI_PCI_MSI		= (1 << 2),
	
	MSI_FLAG_PCI_MSIX		= (1 << 3),
	
	MSI_FLAG_ACTIVATE_EARLY		= (1 << 4),
	
	MSI_FLAG_MUST_REACTIVATE	= (1 << 5),
	
	MSI_FLAG_LEVEL_CAPABLE		= (1 << 6),
};

int msi_domain_set_affinity(struct irq_data *data, const struct cpumask *mask,
			    bool force);

struct irq_domain *msi_create_irq_domain(struct fwnode_handle *fwnode,
					 struct msi_domain_info *info,
					 struct irq_domain *parent);
int msi_domain_alloc_irqs(struct irq_domain *domain, struct device *dev,
			  int nvec);
void msi_domain_free_irqs(struct irq_domain *domain, struct device *dev);
struct msi_domain_info *msi_get_domain_info(struct irq_domain *domain);

struct irq_domain *platform_msi_create_irq_domain(struct fwnode_handle *fwnode,
						  struct msi_domain_info *info,
						  struct irq_domain *parent);
int platform_msi_domain_alloc_irqs(struct device *dev, unsigned int nvec,
				   irq_write_msi_msg_t write_msi_msg);
void platform_msi_domain_free_irqs(struct device *dev);


int msi_domain_prepare_irqs(struct irq_domain *domain, struct device *dev,
			    int nvec, msi_alloc_info_t *args);
int msi_domain_populate_irqs(struct irq_domain *domain, struct device *dev,
			     int virq, int nvec, msi_alloc_info_t *args);
struct irq_domain *
platform_msi_create_device_domain(struct device *dev,
				  unsigned int nvec,
				  irq_write_msi_msg_t write_msi_msg,
				  const struct irq_domain_ops *ops,
				  void *host_data);
int platform_msi_domain_alloc(struct irq_domain *domain, unsigned int virq,
			      unsigned int nr_irqs);
void platform_msi_domain_free(struct irq_domain *domain, unsigned int virq,
			      unsigned int nvec);
void *platform_msi_get_host_data(struct irq_domain *domain);
#endif 

#ifdef CONFIG_PCI_MSI_IRQ_DOMAIN
void pci_msi_domain_write_msg(struct irq_data *irq_data, struct msi_msg *msg);
struct irq_domain *pci_msi_create_irq_domain(struct fwnode_handle *fwnode,
					     struct msi_domain_info *info,
					     struct irq_domain *parent);
irq_hw_number_t pci_msi_domain_calc_hwirq(struct pci_dev *dev,
					  struct msi_desc *desc);
int pci_msi_domain_check_cap(struct irq_domain *domain,
			     struct msi_domain_info *info, struct device *dev);
u32 pci_msi_domain_get_msi_rid(struct irq_domain *domain, struct pci_dev *pdev);
struct irq_domain *pci_msi_get_device_domain(struct pci_dev *pdev);
#else
static inline struct irq_domain *pci_msi_get_device_domain(struct pci_dev *pdev)
{
	return NULL;
}
#endif 

#endif 
