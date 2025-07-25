
#ifndef __ASM_PTDUMP_H
#define __ASM_PTDUMP_H

#ifdef CONFIG_ARM64_PTDUMP_CORE

#include <linux/mm_types.h>
#include <linux/seq_file.h>

struct addr_marker {
	unsigned long start_address;
	char *name;
};

struct ptdump_info {
	struct mm_struct		*mm;
	const struct addr_marker	*markers;
	unsigned long			base_addr;
};

void ptdump_walk_pgd(struct seq_file *s, struct ptdump_info *info);
#ifdef CONFIG_ARM64_PTDUMP_DEBUGFS
int ptdump_debugfs_register(struct ptdump_info *info, const char *name);
#else
static inline int ptdump_debugfs_register(struct ptdump_info *info,
					const char *name)
{
	return 0;
}
#endif
void ptdump_check_wx(void);
#endif 

#ifdef CONFIG_DEBUG_WX
#define debug_checkwx()	ptdump_check_wx()
#else
#define debug_checkwx()	do { } while (0)
#endif

#endif 
