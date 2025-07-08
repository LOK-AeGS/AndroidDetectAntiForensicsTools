/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _QMP_H_
#define _QMP_H_

#include <linux/types.h>


struct qmp_pkt {
	u32 size;
	void *data;
};

#endif 
