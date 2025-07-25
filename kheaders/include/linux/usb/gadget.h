// SPDX-License-Identifier: GPL-2.0


#ifndef __LINUX_USB_GADGET_H
#define __LINUX_USB_GADGET_H

#include <linux/device.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/scatterlist.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <linux/usb/ch9.h>
#include <linux/pm_runtime.h>
#include <linux/android_kabi.h>

#define UDC_TRACE_STR_MAX	512


#define MSM_PIPE_ID_MASK		(0x1F)
#define MSM_TX_PIPE_ID_OFS		(16)
#define MSM_SPS_MODE			BIT(5)
#define MSM_IS_FINITE_TRANSFER		BIT(6)
#define MSM_PRODUCER			BIT(7)
#define MSM_DISABLE_WB			BIT(8)
#define MSM_ETD_IOC			BIT(9)
#define MSM_INTERNAL_MEM		BIT(10)
#define MSM_VENDOR_ID			BIT(16)

struct usb_ep;

enum ep_type {
	EP_TYPE_NORMAL = 0,
	EP_TYPE_GSI,
};


enum gsi_ep_op {
	GSI_EP_OP_CONFIG = 0,
	GSI_EP_OP_STARTXFER,
	GSI_EP_OP_STORE_DBL_INFO,
	GSI_EP_OP_ENABLE_GSI,
	GSI_EP_OP_UPDATEXFER,
	GSI_EP_OP_RING_DB,
	GSI_EP_OP_ENDXFER,
	GSI_EP_OP_GET_CH_INFO,
	GSI_EP_OP_GET_XFER_IDX,
	GSI_EP_OP_PREPARE_TRBS,
	GSI_EP_OP_FREE_TRBS,
	GSI_EP_OP_SET_CLR_BLOCK_DBL,
	GSI_EP_OP_CHECK_FOR_SUSPEND,
	GSI_EP_OP_DISABLE,
};


struct usb_gsi_request {
	void *buf_base_addr;
	dma_addr_t dma;
	size_t num_bufs;
	size_t buf_len;
	u32 db_reg_phs_addr_lsb;
	dma_addr_t mapped_db_reg_phs_addr_lsb;
	u32 db_reg_phs_addr_msb;
	struct sg_table sgt_trb_xfer_ring;
	struct sg_table sgt_data_buff;
	struct device *dev;
};


struct gsi_channel_info {
	u16 last_trb_addr;
	u8 const_buffer_size;
	u32 depcmd_low_addr;
	u8 depcmd_hi_addr;
	u32 gevntcount_low_addr;
	u8 gevntcount_hi_addr;
	u16 xfer_ring_len;
	u64 xfer_ring_base_addr;
	struct usb_gsi_request *ch_req;
};



struct usb_request {
	void			*buf;
	unsigned		length;
	dma_addr_t		dma;

	struct scatterlist	*sg;
	unsigned		num_sgs;
	unsigned		num_mapped_sgs;

	unsigned		stream_id:16;
	unsigned		no_interrupt:1;
	unsigned		zero:1;
	unsigned		short_not_ok:1;
	unsigned		dma_mapped:1;

	void			(*complete)(struct usb_ep *ep,
					struct usb_request *req);
	void			*context;
	struct list_head	list;

	int			status;
	unsigned		actual;
	unsigned int		udc_priv;
};




struct usb_ep_ops {
	int (*enable) (struct usb_ep *ep,
		const struct usb_endpoint_descriptor *desc);
	int (*disable) (struct usb_ep *ep);
	void (*dispose) (struct usb_ep *ep);

	struct usb_request *(*alloc_request) (struct usb_ep *ep,
		gfp_t gfp_flags);
	void (*free_request) (struct usb_ep *ep, struct usb_request *req);

	int (*queue) (struct usb_ep *ep, struct usb_request *req,
		gfp_t gfp_flags);
	int (*dequeue) (struct usb_ep *ep, struct usb_request *req);

	int (*set_halt) (struct usb_ep *ep, int value);
	int (*set_wedge) (struct usb_ep *ep);

	int (*fifo_status) (struct usb_ep *ep);
	void (*fifo_flush) (struct usb_ep *ep);
	int (*gsi_ep_op)(struct usb_ep *ep, void *op_data,
		enum gsi_ep_op op);

};


struct usb_ep_caps {
	unsigned type_control:1;
	unsigned type_iso:1;
	unsigned type_bulk:1;
	unsigned type_int:1;
	unsigned dir_in:1;
	unsigned dir_out:1;
};

#define USB_EP_CAPS_TYPE_CONTROL     0x01
#define USB_EP_CAPS_TYPE_ISO         0x02
#define USB_EP_CAPS_TYPE_BULK        0x04
#define USB_EP_CAPS_TYPE_INT         0x08
#define USB_EP_CAPS_TYPE_ALL \
	(USB_EP_CAPS_TYPE_ISO | USB_EP_CAPS_TYPE_BULK | USB_EP_CAPS_TYPE_INT)
#define USB_EP_CAPS_DIR_IN           0x01
#define USB_EP_CAPS_DIR_OUT          0x02
#define USB_EP_CAPS_DIR_ALL  (USB_EP_CAPS_DIR_IN | USB_EP_CAPS_DIR_OUT)

#define USB_EP_CAPS(_type, _dir) \
	{ \
		.type_control = !!(_type & USB_EP_CAPS_TYPE_CONTROL), \
		.type_iso = !!(_type & USB_EP_CAPS_TYPE_ISO), \
		.type_bulk = !!(_type & USB_EP_CAPS_TYPE_BULK), \
		.type_int = !!(_type & USB_EP_CAPS_TYPE_INT), \
		.dir_in = !!(_dir & USB_EP_CAPS_DIR_IN), \
		.dir_out = !!(_dir & USB_EP_CAPS_DIR_OUT), \
	}



struct usb_ep {
	void			*driver_data;

	const char		*name;
	const struct usb_ep_ops	*ops;
	struct list_head	ep_list;
	struct usb_ep_caps	caps;
	bool			claimed;
	bool			enabled;
	unsigned		maxpacket:16;
	unsigned		maxpacket_limit:16;
	unsigned		max_streams:16;
	unsigned		mult:2;
	unsigned		maxburst:5;
	u8			address;
	const struct usb_endpoint_descriptor	*desc;
	const struct usb_ss_ep_comp_descriptor	*comp_desc;
	enum ep_type		ep_type;
	u8			ep_num;
	u8			ep_intr_num;
	bool			endless;
};



#if IS_ENABLED(CONFIG_USB_GADGET)
void usb_ep_set_maxpacket_limit(struct usb_ep *ep, unsigned maxpacket_limit);
int usb_ep_enable(struct usb_ep *ep);
int usb_ep_disable(struct usb_ep *ep);
struct usb_request *usb_ep_alloc_request(struct usb_ep *ep, gfp_t gfp_flags);
void usb_ep_free_request(struct usb_ep *ep, struct usb_request *req);
int usb_ep_queue(struct usb_ep *ep, struct usb_request *req, gfp_t gfp_flags);
int usb_ep_dequeue(struct usb_ep *ep, struct usb_request *req);
int usb_ep_set_halt(struct usb_ep *ep);
int usb_ep_clear_halt(struct usb_ep *ep);
int usb_ep_set_wedge(struct usb_ep *ep);
int usb_ep_fifo_status(struct usb_ep *ep);
void usb_ep_fifo_flush(struct usb_ep *ep);
int usb_gsi_ep_op(struct usb_ep *ep,
		struct usb_gsi_request *req, enum gsi_ep_op op);
#else
static inline void usb_ep_set_maxpacket_limit(struct usb_ep *ep,
		unsigned maxpacket_limit)
{ }
static inline int usb_ep_enable(struct usb_ep *ep)
{ return 0; }
static inline int usb_ep_disable(struct usb_ep *ep)
{ return 0; }
static inline struct usb_request *usb_ep_alloc_request(struct usb_ep *ep,
		gfp_t gfp_flags)
{ return NULL; }
static inline void usb_ep_free_request(struct usb_ep *ep,
		struct usb_request *req)
{ }
static inline int usb_ep_queue(struct usb_ep *ep, struct usb_request *req,
		gfp_t gfp_flags)
{ return 0; }
static inline int usb_ep_dequeue(struct usb_ep *ep, struct usb_request *req)
{ return 0; }
static inline int usb_ep_set_halt(struct usb_ep *ep)
{ return 0; }
static inline int usb_ep_clear_halt(struct usb_ep *ep)
{ return 0; }
static inline int usb_ep_set_wedge(struct usb_ep *ep)
{ return 0; }
static inline int usb_ep_fifo_status(struct usb_ep *ep)
{ return 0; }
static inline void usb_ep_fifo_flush(struct usb_ep *ep)
{ }

static int usb_gsi_ep_op(struct usb_ep *ep,
		struct usb_gsi_request *req, enum gsi_ep_op op)
{ return 0; }
#endif 



struct usb_dcd_config_params {
	__u8  bU1devExitLat;	
#define USB_DEFAULT_U1_DEV_EXIT_LAT	0x01	
	__le16 bU2DevExitLat;	
#define USB_DEFAULT_U2_DEV_EXIT_LAT	0x1F4	
};


struct usb_gadget;
struct usb_gadget_driver;
struct usb_udc;


struct usb_gadget_ops {
	int	(*get_frame)(struct usb_gadget *);
	int	(*wakeup)(struct usb_gadget *);
	int	(*func_wakeup)(struct usb_gadget *g, int interface_id);
	int	(*set_selfpowered) (struct usb_gadget *, int is_selfpowered);
	int	(*vbus_session) (struct usb_gadget *, int is_active);
	int	(*vbus_draw) (struct usb_gadget *, unsigned mA);
	int	(*pullup) (struct usb_gadget *, int is_on);
	int	(*ioctl)(struct usb_gadget *,
				unsigned code, unsigned long param);
	void	(*get_config_params)(struct usb_dcd_config_params *);
	int	(*udc_start)(struct usb_gadget *,
			struct usb_gadget_driver *);
	int	(*udc_stop)(struct usb_gadget *);
	void	(*udc_set_speed)(struct usb_gadget *, enum usb_device_speed);
	struct usb_ep *(*match_ep)(struct usb_gadget *,
			struct usb_endpoint_descriptor *,
			struct usb_ss_ep_comp_descriptor *);
	int	(*restart)(struct usb_gadget *g);
};


struct usb_gadget {
	struct work_struct		work;
	struct usb_udc			*udc;
	
	const struct usb_gadget_ops	*ops;
	struct usb_ep			*ep0;
	struct list_head		ep_list;	
	enum usb_device_speed		speed;
	enum usb_device_speed		max_speed;
	enum usb_device_state		state;
	const char			*name;
	struct device			dev;
	unsigned			isoch_delay;
	unsigned			out_epnum;
	unsigned			in_epnum;
	unsigned			mA;
	struct usb_otg_caps		*otg_caps;

	unsigned			sg_supported:1;
	unsigned			is_otg:1;
	unsigned			is_a_peripheral:1;
	unsigned			b_hnp_enable:1;
	unsigned			a_hnp_support:1;
	unsigned			a_alt_hnp_support:1;
	unsigned			hnp_polling_support:1;
	unsigned			host_request_flag:1;
	unsigned			quirk_ep_out_aligned_size:1;
	unsigned			quirk_altset_not_supp:1;
	unsigned			quirk_stall_not_supp:1;
	unsigned			quirk_zlp_not_supp:1;
	unsigned			quirk_avoids_skb_reserve:1;
	unsigned			is_selfpowered:1;
	unsigned			deactivated:1;
	unsigned			connected:1;
	unsigned			lpm_capable:1;
	unsigned			remote_wakeup:1;
	bool				bam2bam_func_enabled;
	u32				extra_buf_alloc;
	bool				l1_supported;
	bool				is_chipidea;
	bool				self_powered;

	ANDROID_KABI_RESERVE(1);
	ANDROID_KABI_RESERVE(2);
	ANDROID_KABI_RESERVE(3);
	ANDROID_KABI_RESERVE(4);
};
#define work_to_gadget(w)	(container_of((w), struct usb_gadget, work))

static inline void set_gadget_data(struct usb_gadget *gadget, void *data)
	{ dev_set_drvdata(&gadget->dev, data); }
static inline void *get_gadget_data(struct usb_gadget *gadget)
	{ return dev_get_drvdata(&gadget->dev); }
static inline struct usb_gadget *dev_to_usb_gadget(struct device *dev)
{
	return container_of(dev, struct usb_gadget, dev);
}


#define gadget_for_each_ep(tmp, gadget) \
	list_for_each_entry(tmp, &(gadget)->ep_list, ep_list)


static inline size_t usb_ep_align(struct usb_ep *ep, size_t len)
{
	int max_packet_size = (size_t)usb_endpoint_maxp(ep->desc) & 0x7ff;

	return round_up(len, max_packet_size);
}


static inline size_t
usb_ep_align_maybe(struct usb_gadget *g, struct usb_ep *ep, size_t len)
{
	return g->quirk_ep_out_aligned_size ? usb_ep_align(ep, len) : len;
}


static inline int gadget_is_altset_supported(struct usb_gadget *g)
{
	return !g->quirk_altset_not_supp;
}


static inline int gadget_is_stall_supported(struct usb_gadget *g)
{
	return !g->quirk_stall_not_supp;
}


static inline int gadget_is_zlp_supported(struct usb_gadget *g)
{
	return !g->quirk_zlp_not_supp;
}


static inline int gadget_avoids_skb_reserve(struct usb_gadget *g)
{
	return g->quirk_avoids_skb_reserve;
}


static inline int gadget_is_dualspeed(struct usb_gadget *g)
{
	return g->max_speed >= USB_SPEED_HIGH;
}


static inline int gadget_is_superspeed(struct usb_gadget *g)
{
	return g->max_speed >= USB_SPEED_SUPER;
}


static inline int gadget_is_superspeed_plus(struct usb_gadget *g)
{
	return g->max_speed >= USB_SPEED_SUPER_PLUS;
}


static inline int gadget_is_otg(struct usb_gadget *g)
{
#ifdef CONFIG_USB_OTG
	return g->is_otg;
#else
	return 0;
#endif
}



#if IS_ENABLED(CONFIG_USB_GADGET)
int usb_gadget_frame_number(struct usb_gadget *gadget);
int usb_gadget_wakeup(struct usb_gadget *gadget);
int usb_gadget_func_wakeup(struct usb_gadget *gadget, int interface_id);
int usb_gadget_set_selfpowered(struct usb_gadget *gadget);
int usb_gadget_clear_selfpowered(struct usb_gadget *gadget);
int usb_gadget_vbus_connect(struct usb_gadget *gadget);
int usb_gadget_vbus_draw(struct usb_gadget *gadget, unsigned mA);
int usb_gadget_vbus_disconnect(struct usb_gadget *gadget);
int usb_gadget_connect(struct usb_gadget *gadget);
int usb_gadget_disconnect(struct usb_gadget *gadget);
int usb_gadget_deactivate(struct usb_gadget *gadget);
int usb_gadget_activate(struct usb_gadget *gadget);
#else
static inline int usb_gadget_frame_number(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_wakeup(struct usb_gadget *gadget)
{ return 0; }
static int usb_gadget_func_wakeup(struct usb_gadget *gadget, int interface_id)
{ return 0; }
static inline int usb_gadget_set_selfpowered(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_clear_selfpowered(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_vbus_connect(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_vbus_draw(struct usb_gadget *gadget, unsigned mA)
{ return 0; }
static inline int usb_gadget_vbus_disconnect(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_connect(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_disconnect(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_deactivate(struct usb_gadget *gadget)
{ return 0; }
static inline int usb_gadget_activate(struct usb_gadget *gadget)
{ return 0; }
#endif 




struct usb_gadget_driver {
	char			*function;
	enum usb_device_speed	max_speed;
	int			(*bind)(struct usb_gadget *gadget,
					struct usb_gadget_driver *driver);
	void			(*unbind)(struct usb_gadget *);
	int			(*setup)(struct usb_gadget *,
					const struct usb_ctrlrequest *);
	void			(*disconnect)(struct usb_gadget *);
	void			(*suspend)(struct usb_gadget *);
	void			(*resume)(struct usb_gadget *);
	void			(*reset)(struct usb_gadget *);

	
	struct device_driver	driver;

	char			*udc_name;
	struct list_head	pending;
	unsigned                match_existing_only:1;
};








int usb_gadget_probe_driver(struct usb_gadget_driver *driver);


int usb_gadget_unregister_driver(struct usb_gadget_driver *driver);

extern int usb_add_gadget_udc_release(struct device *parent,
		struct usb_gadget *gadget, void (*release)(struct device *dev));
extern int usb_add_gadget_udc(struct device *parent, struct usb_gadget *gadget);
extern void usb_del_gadget_udc(struct usb_gadget *gadget);
extern char *usb_get_gadget_udc_name(void);






struct usb_string {
	u8			id;
	const char		*s;
};


struct usb_gadget_strings {
	u16			language;	
	struct usb_string	*strings;
};

struct usb_gadget_string_container {
	struct list_head        list;
	u8                      *stash[0];
};


int usb_gadget_get_string(const struct usb_gadget_strings *table, int id, u8 *buf);






int usb_descriptor_fillbuf(void *, unsigned,
		const struct usb_descriptor_header **);


int usb_gadget_config_buf(const struct usb_config_descriptor *config,
	void *buf, unsigned buflen, const struct usb_descriptor_header **desc);


struct usb_descriptor_header **usb_copy_descriptors(
		struct usb_descriptor_header **);


static inline void usb_free_descriptors(struct usb_descriptor_header **v)
{
	kfree(v);
}

struct usb_function;
int usb_assign_descriptors(struct usb_function *f,
		struct usb_descriptor_header **fs,
		struct usb_descriptor_header **hs,
		struct usb_descriptor_header **ss,
		struct usb_descriptor_header **ssp);
void usb_free_all_descriptors(struct usb_function *f);

struct usb_descriptor_header *usb_otg_descriptor_alloc(
				struct usb_gadget *gadget);
int usb_otg_descriptor_init(struct usb_gadget *gadget,
		struct usb_descriptor_header *otg_desc);



int usb_func_ep_queue(struct usb_function *func, struct usb_ep *ep,
				struct usb_request *req, gfp_t gfp_flags);





#ifdef	CONFIG_HAS_DMA
extern int usb_gadget_map_request_by_dev(struct device *dev,
		struct usb_request *req, int is_in);
extern int usb_gadget_map_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in);

extern void usb_gadget_unmap_request_by_dev(struct device *dev,
		struct usb_request *req, int is_in);
extern void usb_gadget_unmap_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in);
#else 
static inline int usb_gadget_map_request_by_dev(struct device *dev,
		struct usb_request *req, int is_in) { return -ENOSYS; }
static inline int usb_gadget_map_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in) { return -ENOSYS; }

static inline void usb_gadget_unmap_request_by_dev(struct device *dev,
		struct usb_request *req, int is_in) { }
static inline void usb_gadget_unmap_request(struct usb_gadget *gadget,
		struct usb_request *req, int is_in) { }
#endif 





extern void usb_gadget_set_state(struct usb_gadget *gadget,
		enum usb_device_state state);




extern void usb_gadget_udc_reset(struct usb_gadget *gadget,
		struct usb_gadget_driver *driver);





extern void usb_gadget_giveback_request(struct usb_ep *ep,
		struct usb_request *req);





extern struct usb_ep *gadget_find_ep_by_name(struct usb_gadget *g,
		const char *name);





extern int usb_gadget_ep_match_desc(struct usb_gadget *gadget,
		struct usb_ep *ep, struct usb_endpoint_descriptor *desc,
		struct usb_ss_ep_comp_descriptor *ep_comp);




extern void usb_udc_vbus_handler(struct usb_gadget *gadget, bool status);


static inline int usb_gadget_autopm_get(struct usb_gadget *gadget)
{
	int status = -ENODEV;

	if (!gadget || !gadget->dev.parent)
		return status;

	status = pm_runtime_get_sync(gadget->dev.parent);
	if (status < 0)
		pm_runtime_put_sync(gadget->dev.parent);

	if (status > 0)
		status = 0;
	return status;
}


static inline int usb_gadget_autopm_get_async(struct usb_gadget *gadget)
{
	int status = -ENODEV;

	if (!gadget || !gadget->dev.parent)
		return status;

	status = pm_runtime_get(gadget->dev.parent);
	if (status < 0 && status != -EINPROGRESS)
		pm_runtime_put_noidle(gadget->dev.parent);

	if (status > 0 || status == -EINPROGRESS)
		status = 0;
	return status;
}


static inline void usb_gadget_autopm_get_noresume(struct usb_gadget *gadget)
{
	if (gadget && gadget->dev.parent)
		pm_runtime_get_noresume(gadget->dev.parent);
}


static inline void usb_gadget_autopm_put(struct usb_gadget *gadget)
{
	if (gadget && gadget->dev.parent)
		pm_runtime_put_sync(gadget->dev.parent);
}


static inline void usb_gadget_autopm_put_async(struct usb_gadget *gadget)
{
	if (gadget && gadget->dev.parent)
		pm_runtime_put(gadget->dev.parent);
}


static inline void usb_gadget_autopm_put_no_suspend(struct usb_gadget *gadget)
{
	if (gadget && gadget->dev.parent)
		pm_runtime_put_noidle(gadget->dev.parent);
}





extern struct usb_ep *usb_ep_autoconfig(struct usb_gadget *,
			struct usb_endpoint_descriptor *);


extern struct usb_ep *usb_ep_autoconfig_ss(struct usb_gadget *,
			struct usb_endpoint_descriptor *,
			struct usb_ss_ep_comp_descriptor *);

extern void usb_ep_autoconfig_release(struct usb_ep *);

extern void usb_ep_autoconfig_reset(struct usb_gadget *);
extern struct usb_ep *usb_ep_autoconfig_by_name(struct usb_gadget *gadget,
			struct usb_endpoint_descriptor *desc,
			const char *ep_name);

#ifdef CONFIG_USB_DWC3_MSM
int msm_ep_config(struct usb_ep *ep, struct usb_request *request);
int msm_ep_unconfig(struct usb_ep *ep);
void dwc3_tx_fifo_resize_request(struct usb_ep *ep, bool qdss_enable);
int msm_data_fifo_config(struct usb_ep *ep, unsigned long addr, u32 size,
	u8 dst_pipe_idx);
bool msm_dwc3_reset_ep_after_lpm(struct usb_gadget *gadget);
int msm_dwc3_reset_dbm_ep(struct usb_ep *ep);
#else
static inline int msm_data_fifo_config(struct usb_ep *ep, unsigned long addr,
	u32 size, u8 dst_pipe_idx)
{	return -ENODEV; }

static inline int msm_ep_config(struct usb_ep *ep, struct usb_request *request)
{ return -ENODEV; }

static inline int msm_ep_unconfig(struct usb_ep *ep)
{ return -ENODEV; }

static inline void dwc3_tx_fifo_resize_request(struct usb_ep *ep,
	bool qdss_enable)
{ }

static inline bool msm_dwc3_reset_ep_after_lpm(struct usb_gadget *gadget)
{ return false; }

static inline int msm_dwc3_reset_dbm_ep(struct usb_ep *ep)
{ return -ENODEV; }
#endif
#endif 
