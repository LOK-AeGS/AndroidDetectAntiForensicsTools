/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */


#ifndef __UAPI_MSM_SDE_ROTATOR_H__
#define __UAPI_MSM_SDE_ROTATOR_H__

#include <linux/videodev2.h>
#include <linux/types.h>
#include <linux/ioctl.h>


#define SDE_PIX_FMT_XRGB_8888		V4L2_PIX_FMT_XBGR32
#define SDE_PIX_FMT_ARGB_8888		V4L2_PIX_FMT_ABGR32
#define SDE_PIX_FMT_ABGR_8888		V4L2_PIX_FMT_SDE_ABGR_8888
#define SDE_PIX_FMT_RGBA_8888		V4L2_PIX_FMT_SDE_RGBA_8888
#define SDE_PIX_FMT_BGRA_8888		V4L2_PIX_FMT_ARGB32
#define SDE_PIX_FMT_RGBX_8888		V4L2_PIX_FMT_SDE_RGBX_8888
#define SDE_PIX_FMT_BGRX_8888		V4L2_PIX_FMT_XRGB32
#define SDE_PIX_FMT_XBGR_8888		V4L2_PIX_FMT_SDE_XBGR_8888
#define SDE_PIX_FMT_RGBA_5551		V4L2_PIX_FMT_SDE_RGBA_5551
#define SDE_PIX_FMT_ARGB_1555		V4L2_PIX_FMT_ARGB555
#define SDE_PIX_FMT_ABGR_1555		V4L2_PIX_FMT_SDE_ABGR_1555
#define SDE_PIX_FMT_BGRA_5551		V4L2_PIX_FMT_SDE_BGRA_5551
#define SDE_PIX_FMT_BGRX_5551		V4L2_PIX_FMT_SDE_BGRX_5551
#define SDE_PIX_FMT_RGBX_5551		V4L2_PIX_FMT_SDE_RGBX_5551
#define SDE_PIX_FMT_XBGR_1555		V4L2_PIX_FMT_SDE_XBGR_1555
#define SDE_PIX_FMT_XRGB_1555		V4L2_PIX_FMT_XRGB555
#define SDE_PIX_FMT_ARGB_4444		V4L2_PIX_FMT_ARGB444
#define SDE_PIX_FMT_RGBA_4444		V4L2_PIX_FMT_SDE_RGBA_4444
#define SDE_PIX_FMT_BGRA_4444		V4L2_PIX_FMT_SDE_BGRA_4444
#define SDE_PIX_FMT_ABGR_4444		V4L2_PIX_FMT_SDE_ABGR_4444
#define SDE_PIX_FMT_RGBX_4444		V4L2_PIX_FMT_SDE_RGBX_4444
#define SDE_PIX_FMT_XRGB_4444		V4L2_PIX_FMT_XRGB444
#define SDE_PIX_FMT_BGRX_4444		V4L2_PIX_FMT_SDE_BGRX_4444
#define SDE_PIX_FMT_XBGR_4444		V4L2_PIX_FMT_SDE_XBGR_4444
#define SDE_PIX_FMT_RGB_888		V4L2_PIX_FMT_RGB24
#define SDE_PIX_FMT_BGR_888		V4L2_PIX_FMT_BGR24
#define SDE_PIX_FMT_RGB_565		V4L2_PIX_FMT_RGB565
#define SDE_PIX_FMT_BGR_565		V4L2_PIX_FMT_SDE_BGR_565
#define SDE_PIX_FMT_Y_CB_CR_H2V2	V4L2_PIX_FMT_YUV420
#define SDE_PIX_FMT_Y_CR_CB_H2V2	V4L2_PIX_FMT_YVU420
#define SDE_PIX_FMT_Y_CR_CB_GH2V2	V4L2_PIX_FMT_SDE_Y_CR_CB_GH2V2
#define SDE_PIX_FMT_Y_CBCR_H2V2		V4L2_PIX_FMT_NV12
#define SDE_PIX_FMT_Y_CRCB_H2V2		V4L2_PIX_FMT_NV21
#define SDE_PIX_FMT_Y_CBCR_H1V2		V4L2_PIX_FMT_SDE_Y_CBCR_H1V2
#define SDE_PIX_FMT_Y_CRCB_H1V2		V4L2_PIX_FMT_SDE_Y_CRCB_H1V2
#define SDE_PIX_FMT_Y_CBCR_H2V1		V4L2_PIX_FMT_NV16
#define SDE_PIX_FMT_Y_CRCB_H2V1		V4L2_PIX_FMT_NV61
#define SDE_PIX_FMT_YCBYCR_H2V1		V4L2_PIX_FMT_YUYV
#define SDE_PIX_FMT_Y_CBCR_H2V2_VENUS	V4L2_PIX_FMT_SDE_Y_CBCR_H2V2_VENUS
#define SDE_PIX_FMT_Y_CRCB_H2V2_VENUS	V4L2_PIX_FMT_SDE_Y_CRCB_H2V2_VENUS
#define SDE_PIX_FMT_RGBA_8888_UBWC	V4L2_PIX_FMT_RGBA8888_UBWC
#define SDE_PIX_FMT_RGBX_8888_UBWC	V4L2_PIX_FMT_SDE_RGBX_8888_UBWC
#define SDE_PIX_FMT_RGB_565_UBWC	V4L2_PIX_FMT_SDE_RGB_565_UBWC
#define SDE_PIX_FMT_Y_CBCR_H2V2_UBWC	V4L2_PIX_FMT_NV12_UBWC
#define SDE_PIX_FMT_RGBA_1010102	V4L2_PIX_FMT_SDE_RGBA_1010102
#define SDE_PIX_FMT_RGBX_1010102	V4L2_PIX_FMT_SDE_RGBX_1010102
#define SDE_PIX_FMT_ARGB_2101010	V4L2_PIX_FMT_SDE_ARGB_2101010
#define SDE_PIX_FMT_XRGB_2101010	V4L2_PIX_FMT_SDE_XRGB_2101010
#define SDE_PIX_FMT_BGRA_1010102	V4L2_PIX_FMT_SDE_BGRA_1010102
#define SDE_PIX_FMT_BGRX_1010102	V4L2_PIX_FMT_SDE_BGRX_1010102
#define SDE_PIX_FMT_ABGR_2101010	V4L2_PIX_FMT_SDE_ABGR_2101010
#define SDE_PIX_FMT_XBGR_2101010	V4L2_PIX_FMT_SDE_XBGR_2101010
#define SDE_PIX_FMT_RGBA_1010102_UBWC	V4L2_PIX_FMT_SDE_RGBA_1010102_UBWC
#define SDE_PIX_FMT_RGBX_1010102_UBWC	V4L2_PIX_FMT_SDE_RGBX_1010102_UBWC
#define SDE_PIX_FMT_Y_CBCR_H2V2_P010	V4L2_PIX_FMT_SDE_Y_CBCR_H2V2_P010
#define SDE_PIX_FMT_Y_CBCR_H2V2_P010_VENUS \
	V4L2_PIX_FMT_SDE_Y_CBCR_H2V2_P010_VENUS
#define SDE_PIX_FMT_Y_CBCR_H2V2_TP10	V4L2_PIX_FMT_SDE_Y_CBCR_H2V2_TP10
#define SDE_PIX_FMT_Y_CBCR_H2V2_TP10_UBWC	V4L2_PIX_FMT_NV12_TP10_UBWC
#define SDE_PIX_FMT_Y_CBCR_H2V2_P010_UBWC	V4L2_PIX_FMT_NV12_P010_UBWC


struct msm_sde_rotator_fence {
	__u32	index;
	__u32	type;
	__s32	fd;
	__u32	reserved[5];
};


struct msm_sde_rotator_comp_ratio {
	__u32	index;
	__u32	type;
	__u32	numer;
	__u32	denom;
	__u32	reserved[4];
};


#define VIDIOC_G_SDE_ROTATOR_FENCE \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 10, struct msm_sde_rotator_fence)
#define VIDIOC_S_SDE_ROTATOR_FENCE \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 11, struct msm_sde_rotator_fence)
#define VIDIOC_G_SDE_ROTATOR_COMP_RATIO \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 12, struct msm_sde_rotator_comp_ratio)
#define VIDIOC_S_SDE_ROTATOR_COMP_RATIO \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 13, struct msm_sde_rotator_comp_ratio)


#define V4L2_CID_SDE_ROTATOR_SECURE	(V4L2_CID_USER_BASE + 0x1000)


#define V4L2_CID_SDE_ROTATOR_SECURE_CAMERA	(V4L2_CID_USER_BASE + 0x2000)

#endif 
