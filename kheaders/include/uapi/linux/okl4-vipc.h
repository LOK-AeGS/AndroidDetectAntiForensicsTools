
#ifndef OKL4_VIPC_H
#define OKL4_VIPC_H

#include <linux/ioctl.h>

struct okl4_vipc_data {
        unsigned int index;
        unsigned long long size;
        unsigned long flags;
};

#define OKL4_VIPC_IOC_MAGIC  'z'

#define OKL4_VIPC_GET_BUFFER_COUNT   _IOR(OKL4_VIPC_IOC_MAGIC, 0, unsigned long *)
#define OKL4_VIPC_GET_BUFFER_INFO    _IOR(OKL4_VIPC_IOC_MAGIC, 1, struct okl4_vipc_data *)

#endif 
