/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _SCSI_SCSI_HOST_H
#define _SCSI_SCSI_HOST_H

#include <linux/device.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <linux/mutex.h>
#include <linux/seq_file.h>
#include <linux/blk-mq.h>
#include <scsi/scsi.h>
#include <linux/android_kabi.h>

struct request_queue;
struct block_device;
struct completion;
struct module;
struct scsi_cmnd;
struct scsi_device;
struct scsi_host_cmd_pool;
struct scsi_target;
struct Scsi_Host;
struct scsi_host_cmd_pool;
struct scsi_transport_template;
struct blk_queue_tags;



#define SG_NONE 0
#define SG_ALL	SG_CHUNK_SIZE

#define MODE_UNKNOWN 0x00
#define MODE_INITIATOR 0x01
#define MODE_TARGET 0x02

#define DISABLE_CLUSTERING 0
#define ENABLE_CLUSTERING 1

struct scsi_host_template {
	struct module *module;
	const char *name;

	
	const char *(* info)(struct Scsi_Host *);

	
	int (* ioctl)(struct scsi_device *dev, int cmd, void __user *arg);


#ifdef CONFIG_COMPAT
	
	int (* compat_ioctl)(struct scsi_device *dev, int cmd, void __user *arg);
#endif

	
	int (* queuecommand)(struct Scsi_Host *, struct scsi_cmnd *);

	
	int (* eh_abort_handler)(struct scsi_cmnd *);
	int (* eh_device_reset_handler)(struct scsi_cmnd *);
	int (* eh_target_reset_handler)(struct scsi_cmnd *);
	int (* eh_bus_reset_handler)(struct scsi_cmnd *);
	int (* eh_host_reset_handler)(struct scsi_cmnd *);

	
	int (* slave_alloc)(struct scsi_device *);

	
	int (* slave_configure)(struct scsi_device *);

	
	void (* slave_destroy)(struct scsi_device *);

	
	int (* target_alloc)(struct scsi_target *);

	
	void (* target_destroy)(struct scsi_target *);

	
	int (* scan_finished)(struct Scsi_Host *, unsigned long);

	
	void (* scan_start)(struct Scsi_Host *);

	
	int (* change_queue_depth)(struct scsi_device *, int);

	
	int (* map_queues)(struct Scsi_Host *shost);

	
	int (* bios_param)(struct scsi_device *, struct block_device *,
			sector_t, int []);

	
	void (*unlock_native_capacity)(struct scsi_device *);

	
	int (*show_info)(struct seq_file *, struct Scsi_Host *);
	int (*write_info)(struct Scsi_Host *, char *, int);

	
	enum blk_eh_timer_return (*eh_timed_out)(struct scsi_cmnd *);

	

	int (*host_reset)(struct Scsi_Host *shost, int reset_type);
#define SCSI_ADAPTER_RESET	1
#define SCSI_FIRMWARE_RESET	2

	void (*tw_ctrl)(struct scsi_device *sdev, int en);

	
	const char *proc_name;

	
	struct proc_dir_entry *proc_dir;

	
	int can_queue;

	
	int this_id;

	
	unsigned short sg_tablesize;
	unsigned short sg_prot_tablesize;

	
	unsigned int max_sectors;

	
	unsigned long dma_boundary;

	
#define SCSI_DEFAULT_MAX_SECTORS	1024

	
	short cmd_per_lun;

	
	unsigned char present;

	
	int tag_alloc_policy;

	
	unsigned track_queue_depth:1;

	
	unsigned supported_mode:2;

	
	unsigned unchecked_isa_dma:1;

	
	unsigned use_clustering:1;

	
	unsigned emulated:1;

	
	unsigned skip_settle_delay:1;

	
	unsigned no_write_same:1;

	
	unsigned force_blk_mq:1;

	
	unsigned int max_host_blocked;

	
#define SCSI_DEFAULT_HOST_BLOCKED	7

	
	struct device_attribute **shost_attrs;

	
	struct device_attribute **sdev_attrs;

	
	const struct attribute_group **sdev_groups;

	
	u64 vendor_id;

	
	unsigned int cmd_size;
	struct scsi_host_cmd_pool *cmd_pool;

	
	int rpm_autosuspend_delay;

	ANDROID_KABI_RESERVE(1);
	ANDROID_KABI_RESERVE(2);
	ANDROID_KABI_RESERVE(3);
	ANDROID_KABI_RESERVE(4);
};


#define DEF_SCSI_QCMD(func_name) \
	int func_name(struct Scsi_Host *shost, struct scsi_cmnd *cmd)	\
	{								\
		unsigned long irq_flags;				\
		int rc;							\
		spin_lock_irqsave(shost->host_lock, irq_flags);		\
		scsi_cmd_get_serial(shost, cmd);			\
		rc = func_name##_lck (cmd, cmd->scsi_done);			\
		spin_unlock_irqrestore(shost->host_lock, irq_flags);	\
		return rc;						\
	}



enum scsi_host_state {
	SHOST_CREATED = 1,
	SHOST_RUNNING,
	SHOST_CANCEL,
	SHOST_DEL,
	SHOST_RECOVERY,
	SHOST_CANCEL_RECOVERY,
	SHOST_DEL_RECOVERY,
};

struct Scsi_Host {
	
	struct list_head	__devices;
	struct list_head	__targets;
	
	struct list_head	starved_list;

	spinlock_t		default_lock;
	spinlock_t		*host_lock;

	struct mutex		scan_mutex;

	struct list_head	eh_cmd_q;
	struct task_struct    * ehandler;  
	struct completion     * eh_action; 
	wait_queue_head_t       host_wait;
	struct scsi_host_template *hostt;
	struct scsi_transport_template *transportt;

	
	union {
		struct blk_queue_tag	*bqt;
		struct blk_mq_tag_set	tag_set;
	};

	atomic_t host_busy;		   
	atomic_t host_blocked;

	unsigned int host_failed;	   
	unsigned int host_eh_scheduled;    
    
	unsigned int host_no;  

	
	int eh_deadline;
	unsigned long last_reset;


	
	unsigned int max_channel;
	unsigned int max_id;
	u64 max_lun;

	
	unsigned int unique_id;

	
	unsigned short max_cmd_len;

	int this_id;
	int can_queue;
	short cmd_per_lun;
	short unsigned int sg_tablesize;
	short unsigned int sg_prot_tablesize;
	unsigned int max_sectors;
	unsigned long dma_boundary;
	
	unsigned nr_hw_queues;
	
	unsigned long cmd_serial_number;
	
	unsigned active_mode:2;
	unsigned unchecked_isa_dma:1;
	unsigned use_clustering:1;

	
	unsigned host_self_blocked:1;
    
	
	unsigned reverse_ordering:1;

	
	unsigned tmf_in_progress:1;

	
	unsigned async_scan:1;

	
	unsigned eh_noresume:1;

	
	unsigned no_write_same:1;

	unsigned use_blk_mq:1;
	unsigned use_cmd_list:1;

	
	unsigned short_inquiry:1;

	
	unsigned set_dbd_for_caching:1;

	
	char work_q_name[20];
	struct workqueue_struct *work_q;

	
	struct workqueue_struct *tmf_work_q;

	
	unsigned no_scsi2_lun_in_cdb:1;

	
	unsigned int max_host_blocked;

	
	unsigned int prot_capabilities;
	unsigned char prot_guard_type;

	
	unsigned long base;
	unsigned long io_port;
	unsigned char n_io_port;
	unsigned char dma_channel;
	unsigned int  irq;
	

	enum scsi_host_state shost_state;

	
	struct device		shost_gendev, shost_dev;

	
	void *shost_data;

	
	struct device *dma_dev;

#if IS_ENABLED(CONFIG_UFS_DATA_LOG)
	sector_t  ufs_system_start;
	sector_t  ufs_system_end;
	bool ufs_sys_log_en;
#endif
	
	unsigned long hostdata[0]  
		__attribute__ ((aligned (sizeof(unsigned long))));
};

#define		class_to_shost(d)	\
	container_of(d, struct Scsi_Host, shost_dev)

#define shost_printk(prefix, shost, fmt, a...)	\
	dev_printk(prefix, &(shost)->shost_gendev, fmt, ##a)

static inline void *shost_priv(struct Scsi_Host *shost)
{
	return (void *)shost->hostdata;
}

int scsi_is_host_device(const struct device *);

static inline struct Scsi_Host *dev_to_shost(struct device *dev)
{
	while (!scsi_is_host_device(dev)) {
		if (!dev->parent)
			return NULL;
		dev = dev->parent;
	}
	return container_of(dev, struct Scsi_Host, shost_gendev);
}

static inline int scsi_host_in_recovery(struct Scsi_Host *shost)
{
	return shost->shost_state == SHOST_RECOVERY ||
		shost->shost_state == SHOST_CANCEL_RECOVERY ||
		shost->shost_state == SHOST_DEL_RECOVERY ||
		shost->tmf_in_progress;
}

static inline bool shost_use_blk_mq(struct Scsi_Host *shost)
{
	return shost->use_blk_mq;
}

extern int scsi_queue_work(struct Scsi_Host *, struct work_struct *);
extern void scsi_flush_work(struct Scsi_Host *);

extern struct Scsi_Host *scsi_host_alloc(struct scsi_host_template *, int);
extern int __must_check scsi_add_host_with_dma(struct Scsi_Host *,
					       struct device *,
					       struct device *);
extern void scsi_scan_host(struct Scsi_Host *);
extern void scsi_rescan_device(struct device *);
extern void scsi_remove_host(struct Scsi_Host *);
extern struct Scsi_Host *scsi_host_get(struct Scsi_Host *);
extern int scsi_host_busy(struct Scsi_Host *shost);
extern void scsi_host_put(struct Scsi_Host *t);
extern struct Scsi_Host *scsi_host_lookup(unsigned short);
extern const char *scsi_host_state_name(enum scsi_host_state);
extern void scsi_cmd_get_serial(struct Scsi_Host *, struct scsi_cmnd *);

static inline int __must_check scsi_add_host(struct Scsi_Host *host,
					     struct device *dev)
{
	return scsi_add_host_with_dma(host, dev, dev);
}

static inline struct device *scsi_get_device(struct Scsi_Host *shost)
{
        return shost->shost_gendev.parent;
}


static inline int scsi_host_scan_allowed(struct Scsi_Host *shost)
{
	return shost->shost_state == SHOST_RUNNING ||
	       shost->shost_state == SHOST_RECOVERY;
}

extern void scsi_unblock_requests(struct Scsi_Host *);
extern void scsi_block_requests(struct Scsi_Host *);
#if IS_ENABLED(CONFIG_BLK_TURBO_WRITE)
extern void scsi_reset_tw_state(struct Scsi_Host *);
#endif

struct class_container;


extern void scsi_free_host_dev(struct scsi_device *);
extern struct scsi_device *scsi_get_host_dev(struct Scsi_Host *);


enum scsi_host_prot_capabilities {
	SHOST_DIF_TYPE1_PROTECTION = 1 << 0, 
	SHOST_DIF_TYPE2_PROTECTION = 1 << 1, 
	SHOST_DIF_TYPE3_PROTECTION = 1 << 2, 

	SHOST_DIX_TYPE0_PROTECTION = 1 << 3, 
	SHOST_DIX_TYPE1_PROTECTION = 1 << 4, 
	SHOST_DIX_TYPE2_PROTECTION = 1 << 5, 
	SHOST_DIX_TYPE3_PROTECTION = 1 << 6, 
};


static inline void scsi_host_set_prot(struct Scsi_Host *shost, unsigned int mask)
{
	shost->prot_capabilities = mask;
}

static inline unsigned int scsi_host_get_prot(struct Scsi_Host *shost)
{
	return shost->prot_capabilities;
}

static inline int scsi_host_prot_dma(struct Scsi_Host *shost)
{
	return shost->prot_capabilities >= SHOST_DIX_TYPE0_PROTECTION;
}

static inline unsigned int scsi_host_dif_capable(struct Scsi_Host *shost, unsigned int target_type)
{
	static unsigned char cap[] = { 0,
				       SHOST_DIF_TYPE1_PROTECTION,
				       SHOST_DIF_TYPE2_PROTECTION,
				       SHOST_DIF_TYPE3_PROTECTION };

	if (target_type >= ARRAY_SIZE(cap))
		return 0;

	return shost->prot_capabilities & cap[target_type] ? target_type : 0;
}

static inline unsigned int scsi_host_dix_capable(struct Scsi_Host *shost, unsigned int target_type)
{
#if defined(CONFIG_BLK_DEV_INTEGRITY)
	static unsigned char cap[] = { SHOST_DIX_TYPE0_PROTECTION,
				       SHOST_DIX_TYPE1_PROTECTION,
				       SHOST_DIX_TYPE2_PROTECTION,
				       SHOST_DIX_TYPE3_PROTECTION };

	if (target_type >= ARRAY_SIZE(cap))
		return 0;

	return shost->prot_capabilities & cap[target_type];
#endif
	return 0;
}



enum scsi_host_guard_type {
	SHOST_DIX_GUARD_CRC = 1 << 0,
	SHOST_DIX_GUARD_IP  = 1 << 1,
};

static inline void scsi_host_set_guard(struct Scsi_Host *shost, unsigned char type)
{
	shost->prot_guard_type = type;
}

static inline unsigned char scsi_host_get_guard(struct Scsi_Host *shost)
{
	return shost->prot_guard_type;
}

extern int scsi_host_set_state(struct Scsi_Host *, enum scsi_host_state);

#endif 
