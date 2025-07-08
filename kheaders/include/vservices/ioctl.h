

#ifndef __LINUX_PUBLIC_VSERVICES_IOCTL_H__
#define __LINUX_PUBLIC_VSERVICES_IOCTL_H__

#include <linux/types.h>
#include <linux/compiler.h>


#define IOCTL_VS_RESET_SERVICE		_IO('4', 0)
#define IOCTL_VS_GET_NAME		_IOR('4', 1, char[16])
#define IOCTL_VS_GET_PROTOCOL		_IOR('4', 2, char[32])


struct vs_ioctl_bind {
	__u32 send_quota;
	__u32 recv_quota;
	__u32 send_notify_bits;
	__u32 recv_notify_bits;
	size_t msg_size;
};
#define IOCTL_VS_BIND_CLIENT _IOR('4', 3, struct vs_ioctl_bind)
#define IOCTL_VS_BIND_SERVER _IOWR('4', 4, struct vs_ioctl_bind)


#define IOCTL_VS_NOTIFY _IOW('4', 5, __u32)
struct vs_ioctl_iovec {
	union {
		__u32 iovcnt; 
		__u32 notify_bits; 
	};
	struct iovec *iov;
};
#define IOCTL_VS_SEND _IOW('4', 6, struct vs_ioctl_iovec)
#define IOCTL_VS_RECV _IOWR('4', 7, struct vs_ioctl_iovec)

#endif 
