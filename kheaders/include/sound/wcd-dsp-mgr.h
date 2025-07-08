/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __WCD_DSP_MGR_H__
#define __WCD_DSP_MGR_H__

#include <linux/types.h>
#include <linux/device.h>


enum wdsp_cmpnt_type {
	
	WDSP_CMPNT_CONTROL = 0,
	
	WDSP_CMPNT_TRANSPORT,
	
	WDSP_CMPNT_IPC,

	WDSP_CMPNT_TYPE_MAX,
};

enum wdsp_event_type {
	
	WDSP_EVENT_POST_INIT,

	
	WDSP_EVENT_PRE_DLOAD_CODE,
	WDSP_EVENT_DLOAD_SECTION,
	WDSP_EVENT_POST_DLOAD_CODE,
	WDSP_EVENT_PRE_DLOAD_DATA,
	WDSP_EVENT_POST_DLOAD_DATA,
	WDSP_EVENT_DLOAD_FAILED,

	WDSP_EVENT_READ_SECTION,

	
	WDSP_EVENT_PRE_BOOTUP,
	WDSP_EVENT_DO_BOOT,
	WDSP_EVENT_POST_BOOTUP,
	WDSP_EVENT_PRE_SHUTDOWN,
	WDSP_EVENT_DO_SHUTDOWN,
	WDSP_EVENT_POST_SHUTDOWN,

	
	WDSP_EVENT_IPC1_INTR,

	
	WDSP_EVENT_SUSPEND,
	WDSP_EVENT_RESUME,

	
	WDSP_EVENT_GET_DEVOPS
};

enum wdsp_signal {
	
	WDSP_IPC1_INTR,
	WDSP_ERR_INTR,

	
	WDSP_CDC_DOWN_SIGNAL,
	WDSP_CDC_UP_SIGNAL,

	
	WDSP_DEBUG_DUMP,
	WDSP_DEBUG_DUMP_INTERNAL,
};


struct wdsp_cmpnt_ops {
	int (*init)(struct device *dev, void *priv_data);
	int (*deinit)(struct device *dev, void *priv_data);
	int (*event_handler)(struct device *dev, void *priv_data,
			     enum wdsp_event_type, void *data);
};

struct wdsp_img_section {
	u32 addr;
	size_t size;
	u8 *data;
};

struct wdsp_err_signal_arg {
	bool mem_dumps_enabled;
	u32 remote_start_addr;
	size_t dump_size;
};



struct wdsp_mgr_ops {
	int (*register_cmpnt_ops)(struct device *wdsp_dev,
				  struct device *cdev,
				  void *priv_data,
				  struct wdsp_cmpnt_ops *ops);
	struct device *(*get_dev_for_cmpnt)(struct device *wdsp_dev,
					    enum wdsp_cmpnt_type type);
	int (*get_devops_for_cmpnt)(struct device *wdsp_dev,
				    enum wdsp_cmpnt_type type, void *data);
	int (*signal_handler)(struct device *wdsp_dev,
			      enum wdsp_signal signal, void *arg);
	int (*vote_for_dsp)(struct device *wdsp_dev, bool vote);
	int (*suspend)(struct device *wdsp_dev);
	int (*resume)(struct device *wdsp_dev);
};

int wcd_dsp_mgr_init(void);
void wcd_dsp_mgr_exit(void);
#endif 
