

#ifndef __HDM_H__
#define __HDM_H__
#include <linux/types.h>


#ifndef __ASSEMBLY__

#define HDM_CMD_LEN ((size_t)8)

#define HDM_P_BITMASK		0xFFFF
#define HDM_C_BITMASK		0xF0000
#define HDM_HYP_CALL		0x40000
#define HDM_HYP_CALLP		0x80000
#define HDM_CMD_MAX		0xFFFFF

enum {
	HDM_ALLOW = 0,
	HDM_PROTECT,
};

extern const struct file_operations hdm_fops;

#endif //__ASSEMBLY__
#endif //__HDM_H__
