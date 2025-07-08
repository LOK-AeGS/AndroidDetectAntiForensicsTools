/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef __UAPI_CORESIGHT_STM_H_
#define __UAPI_CORESIGHT_STM_H_

#define STM_FLAG_NONE          0x00
#define STM_FLAG_TIMESTAMPED   0x08
#define STM_FLAG_GUARANTEED    0x80

#define        OST_ENTITY_NONE                 0x00
#define        OST_ENTITY_FTRACE_EVENTS        0x01
#define        OST_ENTITY_TRACE_PRINTK         0x02
#define        OST_ENTITY_TRACE_MARKER         0x04
#define        OST_ENTITY_DEV_NODE             0x08
#define        OST_ENTITY_DIAG                 0xEE
#define        OST_ENTITY_QVIEW                0xFE
#define        OST_ENTITY_MAX                  0xFF

enum {
	STM_OPTION_GUARANTEED = 0,
	STM_OPTION_INVARIANT,
};

#endif
