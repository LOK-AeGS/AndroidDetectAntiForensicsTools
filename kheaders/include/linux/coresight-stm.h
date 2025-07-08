/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __LINUX_CORESIGHT_STM_H_
#define __LINUX_CORESIGHT_STM_H_

#include <asm/local.h>
#include <linux/stm.h>
#include <linux/bitmap.h>
#include <uapi/linux/coresight-stm.h>

#define BYTES_PER_CHANNEL		256

enum stm_pkt_type {
	STM_PKT_TYPE_DATA	= 0x98,
	STM_PKT_TYPE_FLAG	= 0xE8,
	STM_PKT_TYPE_TRIG	= 0xF8,
};

#define stm_channel_off(type, opts)	(type & ~opts)

#define stm_channel_addr(drvdata, ch)	(drvdata->chs.base +	\
					(ch * BYTES_PER_CHANNEL))

#define stm_log_inv(entity_id, proto_id, data, size)			\
	stm_trace(STM_FLAG_NONE, entity_id, proto_id, data, size)

#define stm_log_inv_ts(entity_id, proto_id, data, size)			\
	stm_trace(STM_FLAG_TIMESTAMPED, entity_id, proto_id,		\
		  data, size)

#define stm_log_gtd(entity_id, proto_id, data, size)			\
	stm_trace(STM_FLAG_GUARANTEED, entity_id, proto_id,		\
		  data, size)

#define stm_log_gtd_ts(entity_id, proto_id, data, size)			\
	stm_trace(STM_FLAG_GUARANTEED | STM_OPTION_TIMESTAMPED,	\
		  entity_id, proto_id, data, size)

#define stm_log(entity_id, data, size)					\
	stm_log_inv_ts(entity_id, 0, data, size)


struct channel_space {
	void __iomem		*base;
	phys_addr_t		phys;
	unsigned long		*guaranteed;
	unsigned long		*bitmap;
};


struct stm_drvdata {
	void __iomem		*base;
	struct device		*dev;
	struct clk		*atclk;
	struct coresight_device	*csdev;
	spinlock_t		spinlock;
	struct channel_space	chs;
	bool			enable;
	DECLARE_BITMAP(entities, OST_ENTITY_MAX);
	struct stm_data		stm;
	local_t			mode;
	u8			traceid;
	u32			write_bytes;
	u32			stmsper;
	u32			stmspscr;
	u32			numsp;
	u32			stmheer;
	u32			stmheter;
	u32			stmhebsr;
	u32			ch_alloc_fail_count;
};

#ifdef CONFIG_CORESIGHT_STM
extern int stm_trace(uint32_t flags, uint8_t entity_id, uint8_t proto_id,
		     const void *data, uint32_t size);

void stm_send(void *addr, const void *data, u32 size, u8 write_bytes);
#else
static inline int stm_trace(uint32_t flags, uint8_t entity_id,
			    uint8_t proto_id, const void *data, uint32_t size)
{
	return 0;
}
static inline void stm_send(void *addr, const void *data, u32 size,
			    u8 write_bytes) {}
#endif
#endif
