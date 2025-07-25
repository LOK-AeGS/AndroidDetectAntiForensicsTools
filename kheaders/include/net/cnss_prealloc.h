/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _NET_CNSS_PREALLOC_H_
#define _NET_CNSS_PREALLOC_H_

#define WCNSS_PRE_ALLOC_GET_THRESHOLD (4*1024)

extern void *wcnss_prealloc_get(size_t size);
extern int wcnss_prealloc_put(void *ptr);
extern int wcnss_pre_alloc_reset(void);
void wcnss_prealloc_check_memory_leak(void);

#endif 
