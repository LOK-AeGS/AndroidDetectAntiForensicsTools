/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_PCI_H
#define __ASM_PCI_H
#ifdef __KERNEL__

#include <linux/types.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>

#include <asm/io.h>

#define PCIBIOS_MIN_IO		0x1000
#define PCIBIOS_MIN_MEM		0


#define pcibios_assign_all_busses() \
	(pci_has_flag(PCI_REASSIGN_ALL_BUS))

#define ARCH_GENERIC_PCI_MMAP_RESOURCE	1

extern int isa_dma_bridge_buggy;

#ifdef CONFIG_PCI
static inline int pci_get_legacy_ide_irq(struct pci_dev *dev, int channel)
{
	
	return -ENODEV;
}

static inline int pci_proc_domain(struct pci_bus *bus)
{
	return 1;
}
#endif  

#endif  
#endif  
