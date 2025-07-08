/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _SDE_RSC_H_
#define _SDE_RSC_H_

#include <linux/kernel.h>


#define SDE_RSC_INDEX		0

#define MAX_RSC_CLIENT_NAME_LEN 128


#define SDE_RSC_INVALID_CRTC_ID 0


#define SDE_RSC_EVENT_PRE_CORE_PC 0x1

#define SDE_RSC_EVENT_POST_CORE_PC 0x2

#define SDE_RSC_EVENT_PRE_CORE_RESTORE 0x4

#define SDE_RSC_EVENT_POST_CORE_RESTORE 0x8

#define SDE_RSC_EVENT_SOLVER_ENABLED 0x10

#define SDE_RSC_EVENT_SOLVER_DISABLED 0x20


enum sde_rsc_client_type {
	SDE_RSC_PRIMARY_DISP_CLIENT,
	SDE_RSC_EXTERNAL_DISP_CLIENT,
	SDE_RSC_CLK_CLIENT,
	SDE_RSC_INVALID_CLIENT,
};


enum sde_rsc_state {
	SDE_RSC_IDLE_STATE,
	SDE_RSC_CLK_STATE,
	SDE_RSC_CMD_STATE,
	SDE_RSC_VID_STATE,
};


struct sde_rsc_client {
	char name[MAX_RSC_CLIENT_NAME_LEN];
	short current_state;
	int crtc_id;
	u32 rsc_index;
	u32 id;
	enum sde_rsc_client_type client_type;
	struct list_head list;
};


struct sde_rsc_event {
	void (*cb_func)(uint32_t event_type, void *usr);
	void *usr;
	u32 rsc_index;
	uint32_t event_type;
	struct list_head list;
};


struct sde_rsc_cmd_config {
	u32 fps;
	u32 vtotal;
	u32 jitter_numer;
	u32 jitter_denom;
	u32 prefill_lines;
};

#ifdef CONFIG_DRM_SDE_RSC

struct sde_rsc_client *sde_rsc_client_create(u32 rsc_index, char *name,
	enum sde_rsc_client_type client_type, u32 vsync_source);


void sde_rsc_client_destroy(struct sde_rsc_client *client);


int sde_rsc_client_state_update(struct sde_rsc_client *client,
	enum sde_rsc_state state,
	struct sde_rsc_cmd_config *config, int crtc_id,
	int *wait_vblank_crtc_id);


int sde_rsc_client_get_vsync_refcount(
		struct sde_rsc_client *caller_client);


int sde_rsc_client_reset_vsync_refcount(
		struct sde_rsc_client *caller_client);


bool sde_rsc_client_is_state_update_complete(
		struct sde_rsc_client *caller_client);


int sde_rsc_client_vote(struct sde_rsc_client *caller_client,
	u32 bus_id, u64 ab_vote, u64 ib_vote);


struct sde_rsc_event *sde_rsc_register_event(int rsc_index, uint32_t event_type,
		void (*cb_func)(uint32_t event_type, void *usr), void *usr);


void sde_rsc_unregister_event(struct sde_rsc_event *event);


bool is_sde_rsc_available(int rsc_index);


enum sde_rsc_state get_sde_rsc_current_state(int rsc_index);


int sde_rsc_client_trigger_vote(struct sde_rsc_client *caller_client,
	bool delta_vote);

#else

static inline struct sde_rsc_client *sde_rsc_client_create(u32 rsc_index,
	char *name, enum sde_rsc_client_type client_type, u32 vsync_source)
{
	return NULL;
}

static inline void sde_rsc_client_destroy(struct sde_rsc_client *client)
{
}

static inline int sde_rsc_client_state_update(struct sde_rsc_client *client,
	enum sde_rsc_state state,
	struct sde_rsc_cmd_config *config, int crtc_id,
	int *wait_vblank_crtc_id)
{
	return 0;
}

static inline int sde_rsc_client_get_vsync_refcount(
		struct sde_rsc_client *caller_client)
{
	return 0;
}

static inline int sde_rsc_client_reset_vsync_refcount(
		struct sde_rsc_client *caller_client)
{
	return 0;
}

static inline bool sde_rsc_client_is_state_update_complete(
		struct sde_rsc_client *caller_client)
{
	return false;
}

static inline int sde_rsc_client_vote(struct sde_rsc_client *caller_client,
	u32 bus_id, u64 ab_vote, u64 ib_vote)
{
	return 0;
}

static inline struct sde_rsc_event *sde_rsc_register_event(int rsc_index,
		uint32_t event_type,
		void (*cb_func)(uint32_t event_type, void *usr), void *usr)
{
	return NULL;
}

static inline void sde_rsc_unregister_event(struct sde_rsc_event *event)
{
}

static inline bool is_sde_rsc_available(int rsc_index)
{
	return false;
}

static inline enum sde_rsc_state get_sde_rsc_current_state(int rsc_index)
{
	return SDE_RSC_IDLE_STATE;
}

static inline int sde_rsc_client_trigger_vote(
	struct sde_rsc_client *caller_client, bool delta_vote)
{
	return 0;
}
#endif 

#endif 
