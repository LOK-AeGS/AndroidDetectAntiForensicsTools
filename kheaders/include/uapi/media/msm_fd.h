/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
#ifndef __UAPI_MSM_FD__
#define __UAPI_MSM_FD__

#include <linux/videodev2.h>
#include <linux/types.h>


struct msm_fd_event {
	__u32 buf_index;
	__u32 frame_id;
	__u32 face_cnt;
};


enum msm_fd_pose {
	MSM_FD_POSE_FRONT,
	MSM_FD_POSE_RIGHT_DIAGONAL,
	MSM_FD_POSE_RIGHT,
	MSM_FD_POSE_LEFT_DIAGONAL,
	MSM_FD_POSE_LEFT,
};


struct msm_fd_face_data {
	__u32 pose;
	__u32 angle;
	__u32 confidence;
	__u32 reserved;
	struct v4l2_rect face;
};


struct msm_fd_result {
	__u32 frame_id;
	__u32 face_cnt;
	struct msm_fd_face_data __user *face_data;
};


#define VIDIOC_MSM_FD_GET_RESULT \
	_IOWR('V', BASE_VIDIOC_PRIVATE, struct msm_fd_result)


#define MSM_EVENT_FD (V4L2_EVENT_PRIVATE_START)


#define V4L2_CID_FD_SPEED                (V4L2_CID_PRIVATE_BASE)
#define V4L2_CID_FD_FACE_ANGLE           (V4L2_CID_PRIVATE_BASE + 1)
#define V4L2_CID_FD_MIN_FACE_SIZE        (V4L2_CID_PRIVATE_BASE + 2)
#define V4L2_CID_FD_FACE_DIRECTION       (V4L2_CID_PRIVATE_BASE + 3)
#define V4L2_CID_FD_DETECTION_THRESHOLD  (V4L2_CID_PRIVATE_BASE + 4)
#define V4L2_CID_FD_WORK_MEMORY_SIZE     (V4L2_CID_PRIVATE_BASE + 5)
#define V4L2_CID_FD_WORK_MEMORY_FD       (V4L2_CID_PRIVATE_BASE + 6)

#endif
