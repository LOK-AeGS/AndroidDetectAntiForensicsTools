

#ifndef _LINUX_INITRAMFS_H
#define _LINUX_INITRAMFS_H

#include <linux/kconfig.h>

#if IS_BUILTIN(CONFIG_BLK_DEV_INITRD)

int __init default_rootfs(void);

#endif

#endif 
