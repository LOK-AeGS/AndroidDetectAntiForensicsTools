/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __LINUX_USB_USBPD_H
#define __LINUX_USB_USBPD_H

#include <linux/list.h>

struct usbpd;
struct device;


#define USBPD_SID			0xff00


enum usbpd_svdm_cmd_type {
	SVDM_CMD_TYPE_INITIATOR,
	SVDM_CMD_TYPE_RESP_ACK,
	SVDM_CMD_TYPE_RESP_NAK,
	SVDM_CMD_TYPE_RESP_BUSY,
};


#define USBPD_SVDM_DISCOVER_IDENTITY	0x1
#define USBPD_SVDM_DISCOVER_SVIDS	0x2
#define USBPD_SVDM_DISCOVER_MODES	0x3
#define USBPD_SVDM_ENTER_MODE		0x4
#define USBPD_SVDM_EXIT_MODE		0x5
#define USBPD_SVDM_ATTENTION		0x6


struct usbpd_svid_handler {
	u16 svid;

	
	void (*connect)(struct usbpd_svid_handler *hdlr,
			bool supports_usb_comm);
	void (*disconnect)(struct usbpd_svid_handler *hdlr);

	
	int (*request_usb_ss_lane)(struct usbpd *pd,
			struct usbpd_svid_handler *hdlr);

	
	void (*vdm_received)(struct usbpd_svid_handler *hdlr, u32 vdm_hdr,
			const u32 *vdos, int num_vdos);

	
	void (*svdm_received)(struct usbpd_svid_handler *hdlr, u8 cmd,
			enum usbpd_svdm_cmd_type cmd_type, const u32 *vdos,
			int num_vdos);

	
	struct list_head entry;
	bool discovered;
};

enum plug_orientation {
	ORIENTATION_NONE,
	ORIENTATION_CC1,
	ORIENTATION_CC2,
};

#if IS_ENABLED(CONFIG_USB_PD_POLICY)

struct usbpd *devm_usbpd_get_by_phandle(struct device *dev,
		const char *phandle);


int usbpd_register_svid(struct usbpd *pd, struct usbpd_svid_handler *hdlr);

void usbpd_unregister_svid(struct usbpd *pd, struct usbpd_svid_handler *hdlr);


int usbpd_send_vdm(struct usbpd *pd, u32 vdm_hdr, const u32 *vdos,
		int num_vdos);


int usbpd_send_svdm(struct usbpd *pd, u16 svid, u8 cmd,
		enum usbpd_svdm_cmd_type cmd_type, int obj_pos,
		const u32 *vdos, int num_vdos);


enum plug_orientation usbpd_get_plug_orientation(struct usbpd *pd);

void usbpd_vdm_in_suspend(struct usbpd *pd, bool in_suspend);
#else
static inline struct usbpd *devm_usbpd_get_by_phandle(struct device *dev,
		const char *phandle)
{
	return ERR_PTR(-ENODEV);
}

static inline int usbpd_register_svid(struct usbpd *pd,
		struct usbpd_svid_handler *hdlr)
{
	return -EINVAL;
}

static inline void usbpd_unregister_svid(struct usbpd *pd,
		struct usbpd_svid_handler *hdlr)
{
}

static inline int usbpd_send_vdm(struct usbpd *pd, u32 vdm_hdr, const u32 *vdos,
		int num_vdos)
{
	return -EINVAL;
}

static inline int usbpd_send_svdm(struct usbpd *pd, u16 svid, u8 cmd,
		enum usbpd_svdm_cmd_type cmd_type, int obj_pos,
		const u32 *vdos, int num_vdos)
{
	return -EINVAL;
}

static inline enum plug_orientation usbpd_get_plug_orientation(struct usbpd *pd)
{
	return ORIENTATION_NONE;
}

static inline void usbpd_vdm_in_suspend(struct usbpd *pd, bool in_suspend) { }
#endif 



static inline int usbpd_enter_mode(struct usbpd *pd, u16 svid, int mode,
		const u32 *vdo)
{
	return usbpd_send_svdm(pd, svid, USBPD_SVDM_ENTER_MODE,
			SVDM_CMD_TYPE_INITIATOR, mode, vdo, vdo ? 1 : 0);
}

static inline int usbpd_exit_mode(struct usbpd *pd, u16 svid, int mode,
		const u32 *vdo)
{
	return usbpd_send_svdm(pd, svid, USBPD_SVDM_EXIT_MODE,
			SVDM_CMD_TYPE_INITIATOR, mode, vdo, vdo ? 1 : 0);
}

#endif 
