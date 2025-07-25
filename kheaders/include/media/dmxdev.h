

#ifndef _DMXDEV_H_
#define _DMXDEV_H_

#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/dvb/dmx.h>

#include <media/dvbdev.h>
#include <media/demux.h>
#include <media/dvb_ringbuffer.h>
#include <media/dvb_vb2.h>


enum dmxdev_type {
	DMXDEV_TYPE_NONE,
	DMXDEV_TYPE_SEC,
	DMXDEV_TYPE_PES,
};


enum dmxdev_state {
	DMXDEV_STATE_FREE,
	DMXDEV_STATE_ALLOCATED,
	DMXDEV_STATE_SET,
	DMXDEV_STATE_GO,
	DMXDEV_STATE_DONE,
	DMXDEV_STATE_TIMEDOUT
};



struct dmxdev_feed {
	u16 pid;
	struct dmx_indexing_params idx_params;
	struct dmx_cipher_operations cipher_ops;
	struct dmx_ts_feed *ts;
	struct list_head next;
};

struct dmxdev_sec_feed {
	struct dmx_section_feed *feed;
	struct dmx_cipher_operations cipher_ops;
};

struct dmxdev_events_queue {
	
	u32 read_index;
	u32 write_index;
	u32 notified_index;

	
	u32 bytes_read_no_event;

	
	u32 current_event_data_size;
	u32 current_event_start_offset;

	
	struct dmx_events_mask event_mask;

	
	int data_read_event_masked;

	
	u32 wakeup_events_counter;

	struct dmx_filter_event queue[DMX_EVENT_QUEUE_SIZE];
};

#define DMX_MIN_INSERTION_REPETITION_TIME	25 
struct ts_insertion_buffer {
	
	struct delayed_work dwork;

	struct list_head next;

	
	char *buffer;

	
	size_t size;

	
	u32 identifier;

	
	u32 repetition_time;

	
	struct dmxdev_filter *dmxdevfilter;

	
	int abort;
};


struct dmxdev_filter {
	union {
		struct dmx_section_filter *sec;
	} filter;

	union {
		
		struct list_head ts;
		struct dmxdev_sec_feed sec;
	} feed;

	union {
		struct dmx_sct_filter_params sec;
		struct dmx_pes_filter_params pes;
	} params;

	struct dmxdev_events_queue events;

	enum dmxdev_type type;
	enum dmxdev_state state;
	struct dmxdev *dev;
	struct dvb_ringbuffer buffer;
	struct dvb_vb2_ctx vb2_ctx;
	struct ion_dma_buff_info buff_dma_info;
	enum dmx_buffer_mode buffer_mode;

	struct mutex mutex;

	
	enum dmx_tsp_format_t dmx_tsp_format;
	u32 rec_chunk_size;

	
	struct list_head insertion_buffers;

	
	int eos_state;

	
	struct timer_list timer;
	int todo;
	u8 secheader[3];

	struct dmx_secure_mode sec_mode;

	
	struct dmx_decoder_buffers decoder_buffers;
};


struct dmxdev {
	struct dvb_device *dvbdev;
	struct dvb_device *dvr_dvbdev;

	struct dmxdev_filter *filter;
	struct dmx_demux *demux;

	int filternum;
	int capabilities;

	enum dmx_playback_mode_t playback_mode;
	enum dmx_source_t source;

	unsigned int may_do_mmap:1;
	unsigned int exit:1;
	unsigned int dvr_in_exit:1;
	unsigned int dvr_processing_input:1;

#define DMXDEV_CAP_DUPLEX 1
	struct dmx_frontend *dvr_orig_fe;

	struct dvb_ringbuffer dvr_buffer;
	struct ion_dma_buff_info dvr_buff_dma_info;
	enum dmx_buffer_mode dvr_buffer_mode;
	struct dmxdev_events_queue dvr_output_events;
	struct dmxdev_filter *dvr_feed;
	int dvr_feeds_count;

	struct dvb_ringbuffer dvr_input_buffer;
	enum dmx_buffer_mode dvr_input_buffer_mode;
	struct task_struct *dvr_input_thread;
	
	struct dvb_ringbuffer dvr_cmd_buffer;

#define DVR_BUFFER_SIZE (10*188*1024)

	struct dvb_vb2_ctx dvr_vb2_ctx;

	struct mutex mutex;
	spinlock_t lock;
	spinlock_t dvr_in_lock;
};

enum dvr_cmd {
	DVR_DATA_FEED_CMD,
	DVR_OOB_CMD
};

struct dvr_command {
	enum dvr_cmd type;
	union {
		struct dmx_oob_command oobcmd;
		size_t data_feed_count;
	} cmd;
};

#define DVR_CMDS_BUFFER_SIZE (sizeof(struct dvr_command)*500)


int dvb_dmxdev_init(struct dmxdev *dmxdev, struct dvb_adapter *adap);


void dvb_dmxdev_release(struct dmxdev *dmxdev);

#endif 
