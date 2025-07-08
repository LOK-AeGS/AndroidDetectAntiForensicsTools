/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _MSM_EXT_DISPLAY_H_
#define _MSM_EXT_DISPLAY_H_

#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/extcon.h>

#define AUDIO_ACK_SET_ENABLE BIT(5)
#define AUDIO_ACK_ENABLE BIT(4)
#define AUDIO_ACK_CONNECT BIT(0)

#define MSM_EXT_DISP_MAX_CODECS    2


#define MSM_EXT_DISP_HPD_AUDIO BIT(0)
#define MSM_EXT_DISP_HPD_VIDEO BIT(1)


struct ext_disp_cable_notify {
	struct list_head link;
	int status;
	void (*hpd_notify)(struct ext_disp_cable_notify *h);
};

struct msm_ext_disp_audio_edid_blk {
	u8 *audio_data_blk;
	unsigned int audio_data_blk_size; 
	u8 *spk_alloc_data_blk;
	unsigned int spk_alloc_data_blk_size; 
};

struct msm_ext_disp_audio_setup_params {
	u32 sample_rate_hz;
	u32 num_of_channels;
	u32 channel_allocation;
	u32 level_shift;
	bool down_mix;
	u32 sample_present;
};


enum msm_ext_disp_type {
	EXT_DISPLAY_TYPE_HDMI = EXTCON_DISP_HDMI,
	EXT_DISPLAY_TYPE_DP = EXTCON_DISP_DP,
	EXT_DISPLAY_TYPE_MAX = 0xFFFFFFFF
};


enum msm_ext_disp_cable_state {
	EXT_DISPLAY_CABLE_DISCONNECT,
	EXT_DISPLAY_CABLE_CONNECT,
	EXT_DISPLAY_CABLE_STATE_MAX
};


enum msm_ext_disp_power_state {
	EXT_DISPLAY_POWER_OFF,
	EXT_DISPLAY_POWER_ON,
	EXT_DISPLAY_POWER_MAX
};


struct msm_ext_disp_codec_id {
	enum msm_ext_disp_type type;
	int ctrl_id;
	int stream_id;
};


struct msm_ext_disp_intf_ops {
	int (*audio_config)(struct platform_device *pdev,
			struct msm_ext_disp_codec_id *codec,
			enum msm_ext_disp_cable_state state);

	int (*audio_notify)(struct platform_device *pdev,
			struct msm_ext_disp_codec_id *codec,
			enum msm_ext_disp_cable_state state);

	int (*video_notify)(struct platform_device *pdev,
			struct msm_ext_disp_codec_id *codec,
			enum msm_ext_disp_cable_state state);
};


struct msm_ext_disp_audio_codec_ops {
	int (*audio_info_setup)(struct platform_device *pdev,
			struct msm_ext_disp_audio_setup_params *params);
	int (*get_audio_edid_blk)(struct platform_device *pdev,
			struct msm_ext_disp_audio_edid_blk *blk);
	int (*cable_status)(struct platform_device *pdev, u32 vote);
	int (*get_intf_id)(struct platform_device *pdev);
	void (*teardown_done)(struct platform_device *pdev);
	int (*acknowledge)(struct platform_device *pdev, u32 ack);
	int (*ready)(struct platform_device *pdev);
};


struct msm_ext_disp_init_data {
	struct msm_ext_disp_codec_id codec;
	struct msm_ext_disp_intf_ops intf_ops;
	struct msm_ext_disp_audio_codec_ops codec_ops;
	struct platform_device *pdev;
	void *intf_data;
};


struct msm_ext_disp_data {
	struct platform_device *intf_pdev;
	void *intf_data;
};


int msm_ext_disp_register_audio_codec(struct platform_device *pdev,
		struct msm_ext_disp_audio_codec_ops *ops);


int msm_ext_disp_select_audio_codec(struct platform_device *pdev,
		struct msm_ext_disp_codec_id *codec);


int msm_hdmi_register_audio_codec(struct platform_device *pdev,
		struct msm_ext_disp_audio_codec_ops *ops);


int msm_ext_disp_register_intf(struct platform_device *pdev,
		struct msm_ext_disp_init_data *init_data);


int msm_ext_disp_deregister_intf(struct platform_device *pdev,
		struct msm_ext_disp_init_data *init_data);

#endif 
