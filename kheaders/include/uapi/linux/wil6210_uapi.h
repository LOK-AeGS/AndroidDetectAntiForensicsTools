/* SPDX-License-Identifier: ISC */


#ifndef __WIL6210_UAPI_H__
#define __WIL6210_UAPI_H__

#if !defined(__KERNEL__)
#define __user
#endif

#include <linux/sockios.h>




#define WIL_IOCTL_MEMIO (SIOCDEVPRIVATE + 2)


#define WIL_IOCTL_MEMIO_BLOCK (SIOCDEVPRIVATE + 3)


#define WIL_MMIO_READ 0
#define WIL_MMIO_WRITE 1
#define WIL_MMIO_OP_MASK 0xff


#define WIL_MMIO_ADDR_LINKER (0 << 8)
#define WIL_MMIO_ADDR_AHB (1 << 8)
#define WIL_MMIO_ADDR_BAR (2 << 8)
#define WIL_MMIO_ADDR_MASK 0xff00

struct wil_memio {
	uint32_t op; 
	uint32_t addr; 
	uint32_t val;
};

struct wil_memio_block {
	uint32_t op; 
	uint32_t addr; 
	uint32_t size; 
	uint64_t __user block; 
};

#endif 
