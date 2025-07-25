
#ifndef _DRM_DP_MST_HELPER_H_
#define _DRM_DP_MST_HELPER_H_

#include <linux/types.h>
#include <drm/drm_dp_helper.h>
#include <drm/drm_atomic.h>

struct drm_dp_mst_branch;
struct drm_dp_mst_port;


struct drm_dp_vcpi {
	int vcpi;
	int pbn;
	int aligned_pbn;
	int num_slots;
};

struct drm_dp_mst_dsc_dpcd_cache {
	bool valid;
	bool use_parent_dpcd;
	u8 dsc_dpcd[16];
};

struct drm_dp_mst_dsc_info {
	bool dsc_support;
	struct drm_dp_mst_port *dsc_port;
	struct drm_dp_mst_dsc_dpcd_cache dsc_dpcd_cache;
};


struct drm_dp_mst_port {
	struct kref kref;

	u8 port_num;
	bool input;
	bool mcs;
	bool ddps;
	u8 pdt;
	bool ldps;
	u8 dpcd_rev;
	u8 num_sdp_streams;
	u8 num_sdp_stream_sinks;
	uint16_t available_pbn;
	struct list_head next;
	struct drm_dp_mst_branch *mstb; 
	struct drm_dp_aux aux; 
	struct drm_dp_mst_branch *parent;

	struct drm_dp_vcpi vcpi;
	struct drm_connector *connector;
	struct drm_dp_mst_topology_mgr *mgr;

	
	struct edid *cached_edid;
	
	bool has_audio;
	
	bool fec_capability;
	
	struct drm_dp_mst_dsc_info dsc_info;
};


struct drm_dp_mst_branch {
	struct kref kref;
	u8 rad[8];
	u8 lct;
	int num_ports;

	int msg_slots;
	struct list_head ports;

	
	struct drm_dp_mst_port *port_parent;
	struct drm_dp_mst_topology_mgr *mgr;

	
	struct drm_dp_sideband_msg_tx *tx_slots[2];
	int last_seqno;
	bool link_address_sent;

	
	u8 guid[16];
};



struct drm_dp_sideband_msg_hdr {
	u8 lct;
	u8 lcr;
	u8 rad[8];
	bool broadcast;
	bool path_msg;
	u8 msg_len;
	bool somt;
	bool eomt;
	bool seqno;
};

struct drm_dp_nak_reply {
	u8 guid[16];
	u8 reason;
	u8 nak_data;
};

struct drm_dp_link_address_ack_reply {
	u8 guid[16];
	u8 nports;
	struct drm_dp_link_addr_reply_port {
		bool input_port;
		u8 peer_device_type;
		u8 port_number;
		bool mcs;
		bool ddps;
		bool legacy_device_plug_status;
		u8 dpcd_revision;
		u8 peer_guid[16];
		u8 num_sdp_streams;
		u8 num_sdp_stream_sinks;
	} ports[16];
};

struct drm_dp_remote_dpcd_read_ack_reply {
	u8 port_number;
	u8 num_bytes;
	u8 bytes[255];
};

struct drm_dp_remote_dpcd_write_ack_reply {
	u8 port_number;
};

struct drm_dp_remote_dpcd_write_nak_reply {
	u8 port_number;
	u8 reason;
	u8 bytes_written_before_failure;
};

struct drm_dp_remote_i2c_read_ack_reply {
	u8 port_number;
	u8 num_bytes;
	u8 bytes[255];
};

struct drm_dp_remote_i2c_read_nak_reply {
	u8 port_number;
	u8 nak_reason;
	u8 i2c_nak_transaction;
};

struct drm_dp_remote_i2c_write_ack_reply {
	u8 port_number;
};


struct drm_dp_sideband_msg_rx {
	u8 chunk[48];
	u8 msg[256];
	u8 curchunk_len;
	u8 curchunk_idx; 
	u8 curchunk_hdrlen;
	u8 curlen; 
	bool have_somt;
	bool have_eomt;
	struct drm_dp_sideband_msg_hdr initial_hdr;
};

#define DRM_DP_MAX_SDP_STREAMS 16
struct drm_dp_allocate_payload {
	u8 port_number;
	u8 number_sdp_streams;
	u8 vcpi;
	u16 pbn;
	u8 sdp_stream_sink[DRM_DP_MAX_SDP_STREAMS];
};

struct drm_dp_allocate_payload_ack_reply {
	u8 port_number;
	u8 vcpi;
	u16 allocated_pbn;
};

struct drm_dp_connection_status_notify {
	u8 guid[16];
	u8 port_number;
	bool legacy_device_plug_status;
	bool displayport_device_plug_status;
	bool message_capability_status;
	bool input_port;
	u8 peer_device_type;
};

struct drm_dp_remote_dpcd_read {
	u8 port_number;
	u32 dpcd_address;
	u8 num_bytes;
};

struct drm_dp_remote_dpcd_write {
	u8 port_number;
	u32 dpcd_address;
	u8 num_bytes;
	u8 *bytes;
};

#define DP_REMOTE_I2C_READ_MAX_TRANSACTIONS 4
struct drm_dp_remote_i2c_read {
	u8 num_transactions;
	u8 port_number;
	struct {
		u8 i2c_dev_id;
		u8 num_bytes;
		u8 *bytes;
		u8 no_stop_bit;
		u8 i2c_transaction_delay;
	} transactions[DP_REMOTE_I2C_READ_MAX_TRANSACTIONS];
	u8 read_i2c_device_id;
	u8 num_bytes_read;
};

struct drm_dp_remote_i2c_write {
	u8 port_number;
	u8 write_i2c_device_id;
	u8 num_bytes;
	u8 *bytes;
};


struct drm_dp_port_number_req {
	u8 port_number;
};

struct drm_dp_enum_path_resources_ack_reply {
	u8 port_number;
	bool fec_capability;
	u16 full_payload_bw_number;
	u16 avail_payload_bw_number;
};


struct drm_dp_port_number_rep {
	u8 port_number;
};

struct drm_dp_query_payload {
	u8 port_number;
	u8 vcpi;
};

struct drm_dp_resource_status_notify {
	u8 port_number;
	u8 guid[16];
	u16 available_pbn;
};

struct drm_dp_query_payload_ack_reply {
	u8 port_number;
	u16 allocated_pbn;
};

struct drm_dp_sideband_msg_req_body {
	u8 req_type;
	union ack_req {
		struct drm_dp_connection_status_notify conn_stat;
		struct drm_dp_port_number_req port_num;
		struct drm_dp_resource_status_notify resource_stat;

		struct drm_dp_query_payload query_payload;
		struct drm_dp_allocate_payload allocate_payload;

		struct drm_dp_remote_dpcd_read dpcd_read;
		struct drm_dp_remote_dpcd_write dpcd_write;

		struct drm_dp_remote_i2c_read i2c_read;
		struct drm_dp_remote_i2c_write i2c_write;
	} u;
};

struct drm_dp_sideband_msg_reply_body {
	u8 reply_type;
	u8 req_type;
	union ack_replies {
		struct drm_dp_nak_reply nak;
		struct drm_dp_link_address_ack_reply link_addr;
		struct drm_dp_port_number_rep port_number;

		struct drm_dp_enum_path_resources_ack_reply path_resources;
		struct drm_dp_allocate_payload_ack_reply allocate_payload;
		struct drm_dp_query_payload_ack_reply query_payload;

		struct drm_dp_remote_dpcd_read_ack_reply remote_dpcd_read_ack;
		struct drm_dp_remote_dpcd_write_ack_reply remote_dpcd_write_ack;
		struct drm_dp_remote_dpcd_write_nak_reply remote_dpcd_write_nack;

		struct drm_dp_remote_i2c_read_ack_reply remote_i2c_read_ack;
		struct drm_dp_remote_i2c_read_nak_reply remote_i2c_read_nack;
		struct drm_dp_remote_i2c_write_ack_reply remote_i2c_write_ack;
	} u;
};


#define DRM_DP_SIDEBAND_TX_QUEUED 0

#define DRM_DP_SIDEBAND_TX_START_SEND 1

#define DRM_DP_SIDEBAND_TX_SENT 2

#define DRM_DP_SIDEBAND_TX_RX 3
#define DRM_DP_SIDEBAND_TX_TIMEOUT 4

struct drm_dp_sideband_msg_tx {
	u8 msg[256];
	u8 chunk[48];
	u8 cur_offset;
	u8 cur_len;
	struct drm_dp_mst_branch *dst;
	struct list_head next;
	int seqno;
	int state;
	bool path_msg;
	struct drm_dp_sideband_msg_reply_body reply;
};


struct drm_dp_mst_topology_mgr;
struct drm_dp_mst_topology_cbs {
	
	struct drm_connector *(*add_connector)(struct drm_dp_mst_topology_mgr *mgr, struct drm_dp_mst_port *port, const char *path);
	void (*register_connector)(struct drm_connector *connector);
	void (*destroy_connector)(struct drm_dp_mst_topology_mgr *mgr,
				  struct drm_connector *connector);
	void (*hotplug)(struct drm_dp_mst_topology_mgr *mgr);

};

#define DP_MAX_PAYLOAD (sizeof(unsigned long) * 8)

#define DP_PAYLOAD_LOCAL 1
#define DP_PAYLOAD_REMOTE 2
#define DP_PAYLOAD_DELETE_LOCAL 3

struct drm_dp_payload {
	int payload_state;
	int start_slot;
	int num_slots;
	int vcpi;
};

#define to_dp_mst_topology_state(x) container_of(x, struct drm_dp_mst_topology_state, base)

struct drm_dp_mst_topology_state {
	struct drm_private_state base;
	int avail_slots;
	struct drm_atomic_state *state;
	struct drm_dp_mst_topology_mgr *mgr;
};

#define to_dp_mst_topology_mgr(x) container_of(x, struct drm_dp_mst_topology_mgr, base)


struct drm_dp_mst_topology_mgr {
	
	struct drm_private_obj base;

	
	struct drm_device *dev;
	
	const struct drm_dp_mst_topology_cbs *cbs;
	
	int max_dpcd_transaction_bytes;
	
	struct drm_dp_aux *aux;
	
	int max_payloads;
	
	int conn_base_id;

	
	struct drm_dp_sideband_msg_rx down_rep_recv;
	
	struct drm_dp_sideband_msg_rx up_req_recv;

	
	struct mutex lock;

	
	bool mst_state;
	
	struct drm_dp_mst_branch *mst_primary;

	
	u8 dpcd[DP_RECEIVER_CAP_SIZE];
	
	u8 sink_count;
	
	int pbn_div;

	
	struct drm_dp_mst_topology_state *state;

	
	const struct drm_private_state_funcs *funcs;

	
	struct mutex qlock;
	
	struct list_head tx_msg_downq;

	
	struct mutex payload_lock;
	
	struct drm_dp_vcpi **proposed_vcpis;
	
	struct drm_dp_payload *payloads;
	
	unsigned long payload_mask;
	
	unsigned long vcpi_mask;

	
	wait_queue_head_t tx_waitq;
	
	struct work_struct work;
	
	struct work_struct tx_work;

	
	struct list_head destroy_connector_list;
	
	struct mutex destroy_connector_lock;
	
	struct work_struct destroy_connector_work;
};

int drm_dp_mst_topology_mgr_init(struct drm_dp_mst_topology_mgr *mgr,
				 struct drm_device *dev, struct drm_dp_aux *aux,
				 int max_dpcd_transaction_bytes,
				 int max_payloads, int conn_base_id);

void drm_dp_mst_topology_mgr_destroy(struct drm_dp_mst_topology_mgr *mgr);


int drm_dp_mst_topology_mgr_set_mst(struct drm_dp_mst_topology_mgr *mgr, bool mst_state);


int drm_dp_mst_hpd_irq(struct drm_dp_mst_topology_mgr *mgr, u8 *esi, bool *handled);


enum drm_connector_status drm_dp_mst_detect_port(struct drm_connector *connector, struct drm_dp_mst_topology_mgr *mgr, struct drm_dp_mst_port *port);

bool drm_dp_mst_port_has_audio(struct drm_dp_mst_topology_mgr *mgr,
					struct drm_dp_mst_port *port);

bool drm_dp_mst_has_fec(struct drm_dp_mst_topology_mgr *mgr,
			struct drm_dp_mst_port *port);

struct edid *drm_dp_mst_get_edid(struct drm_connector *connector, struct drm_dp_mst_topology_mgr *mgr, struct drm_dp_mst_port *port);


int drm_dp_calc_pbn_mode(int clock, int bpp);


bool drm_dp_mst_allocate_vcpi(struct drm_dp_mst_topology_mgr *mgr,
			      struct drm_dp_mst_port *port, int pbn, int slots);

int drm_dp_mst_get_vcpi_slots(struct drm_dp_mst_topology_mgr *mgr, struct drm_dp_mst_port *port);


void drm_dp_mst_reset_vcpi_slots(struct drm_dp_mst_topology_mgr *mgr, struct drm_dp_mst_port *port);


void drm_dp_mst_deallocate_vcpi(struct drm_dp_mst_topology_mgr *mgr,
				struct drm_dp_mst_port *port);


int drm_dp_find_vcpi_slots(struct drm_dp_mst_topology_mgr *mgr,
			   int pbn);


int drm_dp_update_payload_part1(struct drm_dp_mst_topology_mgr *mgr);


int drm_dp_update_payload_part2(struct drm_dp_mst_topology_mgr *mgr);

int drm_dp_check_act_status(struct drm_dp_mst_topology_mgr *mgr);

void drm_dp_mst_dump_topology(struct seq_file *m,
			      struct drm_dp_mst_topology_mgr *mgr);

void drm_dp_mst_topology_mgr_suspend(struct drm_dp_mst_topology_mgr *mgr);
int drm_dp_mst_topology_mgr_resume(struct drm_dp_mst_topology_mgr *mgr);
struct drm_dp_mst_topology_state *drm_atomic_get_mst_topology_state(struct drm_atomic_state *state,
								    struct drm_dp_mst_topology_mgr *mgr);
int drm_dp_atomic_find_vcpi_slots(struct drm_atomic_state *state,
				  struct drm_dp_mst_topology_mgr *mgr,
				  struct drm_dp_mst_port *port, int pbn);
int drm_dp_atomic_release_vcpi_slots(struct drm_atomic_state *state,
				     struct drm_dp_mst_topology_mgr *mgr,
				     int slots);
int drm_dp_send_power_updown_phy(struct drm_dp_mst_topology_mgr *mgr,
				 struct drm_dp_mst_port *port, bool power_up);

int drm_dp_mst_get_dsc_info(struct drm_dp_mst_topology_mgr *mgr,
			    struct drm_dp_mst_port *port,
			    struct drm_dp_mst_dsc_info *dsc_info);

int drm_dp_mst_update_dsc_info(struct drm_dp_mst_topology_mgr *mgr,
			       struct drm_dp_mst_port *port,
			       struct drm_dp_mst_dsc_info *dsc_info);

int drm_dp_send_dpcd_write(struct drm_dp_mst_topology_mgr *mgr,
			   struct drm_dp_mst_port *port,
			   int offset, int size, u8 *bytes);

int drm_dp_send_dpcd_read(struct drm_dp_mst_topology_mgr *mgr,
			  struct drm_dp_mst_port *port,
			  int offset, int size, u8 *bytes);

int drm_dp_mst_get_max_sdp_streams_supported(
		struct drm_dp_mst_topology_mgr *mgr,
		struct drm_dp_mst_port *port);

#endif
