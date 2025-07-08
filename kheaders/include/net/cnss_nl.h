/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _NET_CNSS_GENETLINK_H_
#define _NET_CNSS_GENETLINK_H_

#define CLD80211_MAX_COMMANDS 40
#define CLD80211_MAX_NL_DATA  4096


enum cld80211_attr {
	CLD80211_ATTR_VENDOR_DATA = 1,
	CLD80211_ATTR_DATA,
	CLD80211_ATTR_META_DATA,
	CLD80211_ATTR_CMD,
	CLD80211_ATTR_CMD_TAG_DATA,
	

	__CLD80211_ATTR_AFTER_LAST,
	CLD80211_ATTR_MAX = __CLD80211_ATTR_AFTER_LAST - 1
};


enum cld80211_multicast_groups {
	CLD80211_MCGRP_SVC_MSGS,
	CLD80211_MCGRP_HOST_LOGS,
	CLD80211_MCGRP_FW_LOGS,
	CLD80211_MCGRP_PER_PKT_STATS,
	CLD80211_MCGRP_DIAG_EVENTS,
	CLD80211_MCGRP_FATAL_EVENTS,
	CLD80211_MCGRP_OEM_MSGS,
};


typedef void (*cld80211_cb)(const void *data, int data_len,
			    void *cb_ctx, int pid);


int register_cld_cmd_cb(u8 cmd_id, cld80211_cb cb, void *cb_ctx);


int deregister_cld_cmd_cb(u8 cmd_id);


struct genl_family *cld80211_get_genl_family(void);

#endif 
