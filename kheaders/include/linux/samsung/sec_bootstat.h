#ifndef __SEC_BOOTSTAT_H__
#define __SEC_BOOTSTAT_H__

#ifdef CONFIG_SEC_BOOTSTAT

#include <linux/dma-mapping.h>
#include <linux/miscdevice.h>

#define DEVICE_INIT_TIME_100MS		100000

struct device_init_time_entry {
	struct list_head next;
	char *buf;
	unsigned long long duration;
};

#define MAX_LENGTH_OF_SYSTEMSERVER_LOG 90
struct systemserver_init_time_entry {
	struct list_head next;
	char buf[MAX_LENGTH_OF_SYSTEMSERVER_LOG];
};


extern struct list_head device_init_time_list;


extern void sec_boot_stat_add(const char * c);


extern void sec_bootstat_add_initcall(const char *s);




extern void sec_bootstat_suspend_resume_add(const char *c);
#else 
static inline void sec_boot_stat_add(const char *c) {}
static inline void sec_bootstat_add_initcall(const char *s) {}
static inline void sec_bootstat_suspend_resume_add(const char *c) {}
#endif 

#endif 
