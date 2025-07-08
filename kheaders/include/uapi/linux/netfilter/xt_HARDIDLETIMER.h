/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */


#ifndef _XT_HARDIDLETIMER_H
#define _XT_HARDIDLETIMER_H

#include <linux/types.h>

#define MAX_HARDIDLETIMER_LABEL_SIZE 28
#define NLMSG_MAX_SIZE 64

#define NL_EVENT_TYPE_INACTIVE 0
#define NL_EVENT_TYPE_ACTIVE 1

struct hardidletimer_tg_info {
	__u32 timeout;

	char label[MAX_HARDIDLETIMER_LABEL_SIZE];

	
	__u8 send_nl_msg;

	
	struct hardidletimer_tg *timer __attribute__((aligned(8)));
};

#endif
