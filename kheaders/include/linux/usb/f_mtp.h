

#ifndef __LINUX_USB_F_MTP_H
#define __LINUX_USB_F_MTP_H

#include <uapi/linux/usb/f_mtp.h>
#include <linux/ioctl.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif

#ifdef __KERNEL__

#ifdef CONFIG_COMPAT
struct __compat_mtp_file_range {
	compat_int_t	fd;
	compat_loff_t	offset;
	int64_t		length;
	uint16_t	command;
	uint32_t	transaction_id;
};

struct __compat_mtp_event {
	compat_size_t	length;
	compat_caddr_t	data;
};

#define COMPAT_MTP_SEND_FILE              _IOW('M', 0, \
						struct __compat_mtp_file_range)
#define COMPAT_MTP_RECEIVE_FILE           _IOW('M', 1, \
						struct __compat_mtp_file_range)
#define COMPAT_MTP_SEND_EVENT             _IOW('M', 3, \
						struct __compat_mtp_event)
#define COMPAT_MTP_SEND_FILE_WITH_HEADER  _IOW('M', 4, \
						struct __compat_mtp_file_range)
#endif
#endif
#endif 
