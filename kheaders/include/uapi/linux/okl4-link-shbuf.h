
#ifndef _LINUX_OKL4_LINK_SHBUF_H
#define _LINUX_OKL4_LINK_SHBUF_H

#include <linux/ioctl.h>
#include <linux/types.h>


#define OKL4_LINK_SHBUF_IOCTL_IRQ_TX _IOW(0x8d, 1, __u64)


#define OKL4_LINK_SHBUF_IOCTL_IRQ_CLR _IOR(0x8d, 2, __u64)

#endif 
