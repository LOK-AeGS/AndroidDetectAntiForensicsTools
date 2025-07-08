/* SPDX-License-Identifier: GPL-2.0 */

#ifndef FASTCVPD_H
#define FASTCVPD_H

#include <linux/types.h>

#define FASTCVPD_GLINK_GUID "fastcvpd-glink-apps-dsp"
#define FASTCVPD_SMD_GUID "fastcvpd-smd-apps-dsp"
#define FASTCVPD_DEVICE_NAME "fastcvpd-smd"

#ifdef CONFIG_MSM_FASTCVPD

int fastcvpd_video_send_cmd_hfi_queue(phys_addr_t *phys_addr,
	uint32_t size_in_bytes);


int fastcvpd_video_suspend(uint32_t session_flag);


int fastcvpd_video_resume(uint32_t session_flag);


int fastcvpd_video_shutdown(uint32_t session_flag);

#else

static inline int fastcvpd_video_send_cmd_hfi_queue(
	phys_addr_t *phys_addr,
	uint32_t size_in_bytes)
{
	return -ENODEV;
}

static inline int fastcvpd_video_shutdown(uint32_t session_flag)
{
	return -ENODEV;
}

static inline int fastcvpd_video_suspend(uint32_t session_flag)
{
	return -ENODEV;
}

static inline int fastcvpd_video_resume(uint32_t session_flag)
{
	return -ENODEV;
}

#endif // CONFIG_FASTCVPD
#endif // FASTCVPD_H
