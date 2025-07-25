/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __MSMB_ISP__
#define __MSMB_ISP__

#include <uapi/media/msmb_isp.h>

#ifdef CONFIG_COMPAT
struct msm_isp_event_data32 {
	struct compat_timeval timestamp;
	struct compat_timeval mono_timestamp;
	uint32_t frame_id;
	union {
		struct msm_isp_stats_event stats;
		struct msm_isp_buf_event buf_done;
		struct msm_isp_fetch_eng_event fetch_done;
		struct msm_isp_error_info error_info;
		struct msm_isp_output_info output_info;
		struct msm_isp_sof_info sof_info;
	} u;
};

struct msm_isp32_event_data32 {
	struct compat_timeval timestamp;
	struct compat_timeval mono_timestamp;
	enum msm_vfe_input_src input_intf;
	uint32_t frame_id;
	union {
		struct msm_isp_stats_event stats;
		struct msm_isp_buf_event buf_done;
		struct msm_isp32_error_info error_info;
	} u;
};

#endif
#ifdef CONFIG_MSM_AVTIMER
struct avtimer_fptr_t {
	int (*fptr_avtimer_open)(void);
	int (*fptr_avtimer_enable)(int enable);
	int (*fptr_avtimer_get_time)(uint64_t *avtimer_tick);
};
void msm_isp_set_avtimer_fptr(struct avtimer_fptr_t avtimer_func);
#endif
#endif
