
#ifndef _TCP_H
#define _TCP_H

#define FASTRETRANS_DEBUG 1

#include <linux/list.h>
#include <linux/tcp.h>
#include <linux/bug.h>
#include <linux/slab.h>
#include <linux/cache.h>
#include <linux/percpu.h>
#include <linux/skbuff.h>
#include <linux/cryptohash.h>
#include <linux/kref.h>
#include <linux/ktime.h>

#include <net/inet_connection_sock.h>
#include <net/inet_timewait_sock.h>
#include <net/inet_hashtables.h>
#include <net/checksum.h>
#include <net/request_sock.h>
#include <net/sock_reuseport.h>
#include <net/sock.h>
#include <net/snmp.h>
#include <net/ip.h>
#include <net/tcp_states.h>
#include <net/inet_ecn.h>
#include <net/dst.h>

#include <linux/seq_file.h>
#include <linux/memcontrol.h>
#include <linux/bpf-cgroup.h>

extern struct inet_hashinfo tcp_hashinfo;

extern struct percpu_counter tcp_orphan_count;
void tcp_time_wait(struct sock *sk, int state, int timeo);

#define MAX_TCP_HEADER	L1_CACHE_ALIGN(128 + MAX_HEADER)
#define MAX_TCP_OPTION_SPACE 40
#define TCP_MIN_SND_MSS		48
#define TCP_MIN_GSO_SIZE	(TCP_MIN_SND_MSS - MAX_TCP_OPTION_SPACE)


#define MAX_TCP_WINDOW		32767U


#define TCP_MIN_MSS		88U


#define TCP_BASE_MSS		1024


#define TCP_PROBE_INTERVAL	600


#define TCP_PROBE_THRESHOLD	8


#define TCP_FASTRETRANS_THRESH 3


#define TCP_MAX_QUICKACKS	16U


#define TCP_MAX_WSCALE		14U


#define TCP_URG_VALID	0x0100
#define TCP_URG_NOTYET	0x0200
#define TCP_URG_READ	0x0400

#define TCP_RETR1	3	

#define TCP_RETR2	15	

#define TCP_SYN_RETRIES	 6	

#define TCP_SYNACK_RETRIES 5	

#define TCP_TIMEWAIT_LEN (60*HZ) 
#define TCP_FIN_TIMEOUT	TCP_TIMEWAIT_LEN
                                 

#define TCP_DELACK_MAX	((unsigned)(HZ/5))	
#if HZ >= 100
#define TCP_DELACK_MIN	((unsigned)(HZ/25))	
#define TCP_ATO_MIN	((unsigned)(HZ/25))
#else
#define TCP_DELACK_MIN	4U
#define TCP_ATO_MIN	4U
#endif
#define TCP_RTO_MAX	((unsigned)(120*HZ))
#define TCP_RTO_MIN	((unsigned)(HZ/5))
#define TCP_TIMEOUT_MIN	(2U) 
#define TCP_TIMEOUT_INIT ((unsigned)(1*HZ))	
#define TCP_TIMEOUT_FALLBACK ((unsigned)(3*HZ))	


#define TCP_DELACK_SEG          1

#define TCP_RESOURCE_PROBE_INTERVAL ((unsigned)(HZ/2U)) 
#define TCP_KEEPALIVE_TIME	(120*60*HZ)	
#define TCP_KEEPALIVE_PROBES	9		
#define TCP_KEEPALIVE_INTVL	(75*HZ)

#define MAX_TCP_KEEPIDLE	32767
#define MAX_TCP_KEEPINTVL	32767
#define MAX_TCP_KEEPCNT		127
#define MAX_TCP_SYNCNT		127

#define TCP_SYNQ_INTERVAL	(HZ/5)	

#define TCP_PAWS_24DAYS	(60 * 60 * 24 * 24)
#define TCP_PAWS_MSL	60		
#define TCP_PAWS_WINDOW	1		


#define TCPOPT_NOP		1	
#define TCPOPT_EOL		0	
#define TCPOPT_MSS		2	
#define TCPOPT_WINDOW		3	
#define TCPOPT_SACK_PERM        4       
#define TCPOPT_SACK             5       
#define TCPOPT_TIMESTAMP	8	
#define TCPOPT_MD5SIG		19	
#define TCPOPT_FASTOPEN		34	
#define TCPOPT_EXP		254	

#define TCPOPT_FASTOPEN_MAGIC	0xF989
#define TCPOPT_SMC_MAGIC	0xE2D4C3D9



#define TCPOLEN_MSS            4
#define TCPOLEN_WINDOW         3
#define TCPOLEN_SACK_PERM      2
#define TCPOLEN_TIMESTAMP      10
#define TCPOLEN_MD5SIG         18
#define TCPOLEN_FASTOPEN_BASE  2
#define TCPOLEN_EXP_FASTOPEN_BASE  4
#define TCPOLEN_EXP_SMC_BASE   6


#define TCPOLEN_TSTAMP_ALIGNED		12
#define TCPOLEN_WSCALE_ALIGNED		4
#define TCPOLEN_SACKPERM_ALIGNED	4
#define TCPOLEN_SACK_BASE		2
#define TCPOLEN_SACK_BASE_ALIGNED	4
#define TCPOLEN_SACK_PERBLOCK		8
#define TCPOLEN_MD5SIG_ALIGNED		20
#define TCPOLEN_MSS_ALIGNED		4
#define TCPOLEN_EXP_SMC_BASE_ALIGNED	8


#define TCP_NAGLE_OFF		1	
#define TCP_NAGLE_CORK		2	
#define TCP_NAGLE_PUSH		4	


#define TCP_THIN_LINEAR_RETRIES 6       


#define TCP_INIT_CWND		10


#define	TFO_CLIENT_ENABLE	1
#define	TFO_SERVER_ENABLE	2
#define	TFO_CLIENT_NO_COOKIE	4	


#define	TFO_SERVER_COOKIE_NOT_REQD	0x200


#define	TFO_SERVER_WO_SOCKOPT1	0x400



extern int sysctl_tcp_max_orphans;
extern long sysctl_tcp_mem[3];

#define TCP_RACK_LOSS_DETECTION  0x1 
#define TCP_RACK_STATIC_REO_WND  0x2 
#define TCP_RACK_NO_DUPTHRESH    0x4 

extern atomic_long_t tcp_memory_allocated;


extern int sysctl_tcp_delack_seg;
extern int sysctl_tcp_use_userconfig;

extern struct percpu_counter tcp_sockets_allocated;
extern unsigned long tcp_memory_pressure;


static inline bool tcp_under_memory_pressure(const struct sock *sk)
{
	if (mem_cgroup_sockets_enabled && sk->sk_memcg &&
	    mem_cgroup_under_socket_pressure(sk->sk_memcg))
		return true;

	return READ_ONCE(tcp_memory_pressure);
}


static inline bool before(__u32 seq1, __u32 seq2)
{
        return (__s32)(seq1-seq2) < 0;
}
#define after(seq2, seq1) 	before(seq1, seq2)


static inline bool between(__u32 seq1, __u32 seq2, __u32 seq3)
{
	return seq3 - seq2 >= seq1 - seq2;
}

static inline bool tcp_out_of_memory(struct sock *sk)
{
	if (sk->sk_wmem_queued > SOCK_MIN_SNDBUF &&
	    sk_memory_allocated(sk) > sk_prot_mem_limits(sk, 2))
		return true;
	return false;
}

void sk_forced_mem_schedule(struct sock *sk, int size);

static inline bool tcp_too_many_orphans(struct sock *sk, int shift)
{
	struct percpu_counter *ocp = sk->sk_prot->orphan_count;
	int orphans = percpu_counter_read_positive(ocp);

	if (orphans << shift > sysctl_tcp_max_orphans) {
		orphans = percpu_counter_sum_positive(ocp);
		if (orphans << shift > sysctl_tcp_max_orphans)
			return true;
	}
	return false;
}

bool tcp_check_oom(struct sock *sk, int shift);


extern struct proto tcp_prot;

#define TCP_INC_STATS(net, field)	SNMP_INC_STATS((net)->mib.tcp_statistics, field)
#define __TCP_INC_STATS(net, field)	__SNMP_INC_STATS((net)->mib.tcp_statistics, field)
#define TCP_DEC_STATS(net, field)	SNMP_DEC_STATS((net)->mib.tcp_statistics, field)
#define TCP_ADD_STATS(net, field, val)	SNMP_ADD_STATS((net)->mib.tcp_statistics, field, val)

void tcp_tasklet_init(void);

void tcp_v4_err(struct sk_buff *skb, u32);

void tcp_shutdown(struct sock *sk, int how);

int tcp_v4_early_demux(struct sk_buff *skb);
int tcp_v4_rcv(struct sk_buff *skb);

int tcp_v4_tw_remember_stamp(struct inet_timewait_sock *tw);
int tcp_sendmsg(struct sock *sk, struct msghdr *msg, size_t size);
int tcp_sendmsg_locked(struct sock *sk, struct msghdr *msg, size_t size);
int tcp_sendpage(struct sock *sk, struct page *page, int offset, size_t size,
		 int flags);
int tcp_sendpage_locked(struct sock *sk, struct page *page, int offset,
			size_t size, int flags);
ssize_t do_tcp_sendpages(struct sock *sk, struct page *page, int offset,
		 size_t size, int flags);
void tcp_release_cb(struct sock *sk);
void tcp_wfree(struct sk_buff *skb);
void tcp_write_timer_handler(struct sock *sk);
void tcp_delack_timer_handler(struct sock *sk);
int tcp_ioctl(struct sock *sk, int cmd, unsigned long arg);
int tcp_rcv_state_process(struct sock *sk, struct sk_buff *skb);
void tcp_rcv_established(struct sock *sk, struct sk_buff *skb);
void tcp_rcv_space_adjust(struct sock *sk);
int tcp_twsk_unique(struct sock *sk, struct sock *sktw, void *twp);
void tcp_twsk_destructor(struct sock *sk);
ssize_t tcp_splice_read(struct socket *sk, loff_t *ppos,
			struct pipe_inode_info *pipe, size_t len,
			unsigned int flags);


extern int tcp_use_userconfig_sysctl_handler(struct ctl_table *table,
				int write, void __user *buffer, size_t *length,
				loff_t *ppos);
extern int tcp_proc_delayed_ack_control(struct ctl_table *table, int write,
				void __user *buffer, size_t *length,
				loff_t *ppos);

void tcp_enter_quickack_mode(struct sock *sk, unsigned int max_quickacks);
static inline void tcp_dec_quickack_mode(struct sock *sk,
					 const unsigned int pkts)
{
	struct inet_connection_sock *icsk = inet_csk(sk);

	if (icsk->icsk_ack.quick) {
		if (pkts >= icsk->icsk_ack.quick) {
			icsk->icsk_ack.quick = 0;
			
			icsk->icsk_ack.ato   = TCP_ATO_MIN;
		} else
			icsk->icsk_ack.quick -= pkts;
	}
}

#define	TCP_ECN_OK		1
#define	TCP_ECN_QUEUE_CWR	2
#define	TCP_ECN_DEMAND_CWR	4
#define	TCP_ECN_SEEN		8

enum tcp_tw_status {
	TCP_TW_SUCCESS = 0,
	TCP_TW_RST = 1,
	TCP_TW_ACK = 2,
	TCP_TW_SYN = 3
};


enum tcp_tw_status tcp_timewait_state_process(struct inet_timewait_sock *tw,
					      struct sk_buff *skb,
					      const struct tcphdr *th);
struct sock *tcp_check_req(struct sock *sk, struct sk_buff *skb,
			   struct request_sock *req, bool fastopen,
			   bool *lost_race);
int tcp_child_process(struct sock *parent, struct sock *child,
		      struct sk_buff *skb);
void tcp_enter_loss(struct sock *sk);
void tcp_cwnd_reduction(struct sock *sk, int newly_acked_sacked, int flag);
void tcp_clear_retrans(struct tcp_sock *tp);
void tcp_update_metrics(struct sock *sk);
void tcp_init_metrics(struct sock *sk);
void tcp_metrics_init(void);
bool tcp_peer_is_proven(struct request_sock *req, struct dst_entry *dst);
void tcp_close(struct sock *sk, long timeout);
void tcp_init_sock(struct sock *sk);
void tcp_init_transfer(struct sock *sk, int bpf_op);
__poll_t tcp_poll(struct file *file, struct socket *sock,
		      struct poll_table_struct *wait);
int tcp_getsockopt(struct sock *sk, int level, int optname,
		   char __user *optval, int __user *optlen);
int tcp_setsockopt(struct sock *sk, int level, int optname,
		   char __user *optval, unsigned int optlen);
int compat_tcp_getsockopt(struct sock *sk, int level, int optname,
			  char __user *optval, int __user *optlen);
int compat_tcp_setsockopt(struct sock *sk, int level, int optname,
			  char __user *optval, unsigned int optlen);
void tcp_set_keepalive(struct sock *sk, int val);
void tcp_syn_ack_timeout(const struct request_sock *req);
int tcp_recvmsg(struct sock *sk, struct msghdr *msg, size_t len, int nonblock,
		int flags, int *addr_len);
int tcp_set_rcvlowat(struct sock *sk, int val);
void tcp_data_ready(struct sock *sk);
int tcp_mmap(struct file *file, struct socket *sock,
	     struct vm_area_struct *vma);
void tcp_parse_options(const struct net *net, const struct sk_buff *skb,
		       struct tcp_options_received *opt_rx,
		       int estab, struct tcp_fastopen_cookie *foc);
const u8 *tcp_parse_md5sig_option(const struct tcphdr *th);



void tcp_v4_send_check(struct sock *sk, struct sk_buff *skb);
void tcp_v4_mtu_reduced(struct sock *sk);
void tcp_req_err(struct sock *sk, u32 seq, bool abort);
int tcp_v4_conn_request(struct sock *sk, struct sk_buff *skb);
struct sock *tcp_create_openreq_child(const struct sock *sk,
				      struct request_sock *req,
				      struct sk_buff *skb);
void tcp_ca_openreq_child(struct sock *sk, const struct dst_entry *dst);
struct sock *tcp_v4_syn_recv_sock(const struct sock *sk, struct sk_buff *skb,
				  struct request_sock *req,
				  struct dst_entry *dst,
				  struct request_sock *req_unhash,
				  bool *own_req);
int tcp_v4_do_rcv(struct sock *sk, struct sk_buff *skb);
int tcp_v4_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len);
int tcp_connect(struct sock *sk);
enum tcp_synack_type {
	TCP_SYNACK_NORMAL,
	TCP_SYNACK_FASTOPEN,
	TCP_SYNACK_COOKIE,
};
struct sk_buff *tcp_make_synack(const struct sock *sk, struct dst_entry *dst,
				struct request_sock *req,
				struct tcp_fastopen_cookie *foc,
				enum tcp_synack_type synack_type);
int tcp_disconnect(struct sock *sk, int flags);

void tcp_finish_connect(struct sock *sk, struct sk_buff *skb);
int tcp_send_rcvq(struct sock *sk, struct msghdr *msg, size_t size);
void inet_sk_rx_dst_set(struct sock *sk, const struct sk_buff *skb);


struct sock *tcp_get_cookie_sock(struct sock *sk, struct sk_buff *skb,
				 struct request_sock *req,
				 struct dst_entry *dst, u32 tsoff);
int __cookie_v4_check(const struct iphdr *iph, const struct tcphdr *th,
		      u32 cookie);
struct sock *cookie_v4_check(struct sock *sk, struct sk_buff *skb);
#ifdef CONFIG_SYN_COOKIES


#define MAX_SYNCOOKIE_AGE	2
#define TCP_SYNCOOKIE_PERIOD	(60 * HZ)
#define TCP_SYNCOOKIE_VALID	(MAX_SYNCOOKIE_AGE * TCP_SYNCOOKIE_PERIOD)


static inline void tcp_synq_overflow(const struct sock *sk)
{
	unsigned int last_overflow;
	unsigned int now = jiffies;

	if (sk->sk_reuseport) {
		struct sock_reuseport *reuse;

		reuse = rcu_dereference(sk->sk_reuseport_cb);
		if (likely(reuse)) {
			last_overflow = READ_ONCE(reuse->synq_overflow_ts);
			if (!time_between32(now, last_overflow,
					    last_overflow + HZ))
				WRITE_ONCE(reuse->synq_overflow_ts, now);
			return;
		}
	}

	last_overflow = READ_ONCE(tcp_sk(sk)->rx_opt.ts_recent_stamp);
	if (!time_between32(now, last_overflow, last_overflow + HZ))
		WRITE_ONCE(tcp_sk(sk)->rx_opt.ts_recent_stamp, now);
}


static inline bool tcp_synq_no_recent_overflow(const struct sock *sk)
{
	unsigned int last_overflow;
	unsigned int now = jiffies;

	if (sk->sk_reuseport) {
		struct sock_reuseport *reuse;

		reuse = rcu_dereference(sk->sk_reuseport_cb);
		if (likely(reuse)) {
			last_overflow = READ_ONCE(reuse->synq_overflow_ts);
			return !time_between32(now, last_overflow - HZ,
					       last_overflow +
					       TCP_SYNCOOKIE_VALID);
		}
	}

	last_overflow = READ_ONCE(tcp_sk(sk)->rx_opt.ts_recent_stamp);

	
	return !time_between32(now, last_overflow - HZ,
			       last_overflow + TCP_SYNCOOKIE_VALID);
}

static inline u32 tcp_cookie_time(void)
{
	u64 val = get_jiffies_64();

	do_div(val, TCP_SYNCOOKIE_PERIOD);
	return val;
}

u32 __cookie_v4_init_sequence(const struct iphdr *iph, const struct tcphdr *th,
			      u16 *mssp);
__u32 cookie_v4_init_sequence(const struct sk_buff *skb, __u16 *mss);
u64 cookie_init_timestamp(struct request_sock *req);
bool cookie_timestamp_decode(const struct net *net,
			     struct tcp_options_received *opt);
bool cookie_ecn_ok(const struct tcp_options_received *opt,
		   const struct net *net, const struct dst_entry *dst);


int __cookie_v6_check(const struct ipv6hdr *iph, const struct tcphdr *th,
		      u32 cookie);
struct sock *cookie_v6_check(struct sock *sk, struct sk_buff *skb);

u32 __cookie_v6_init_sequence(const struct ipv6hdr *iph,
			      const struct tcphdr *th, u16 *mssp);
__u32 cookie_v6_init_sequence(const struct sk_buff *skb, __u16 *mss);
#endif


void __tcp_push_pending_frames(struct sock *sk, unsigned int cur_mss,
			       int nonagle);
int __tcp_retransmit_skb(struct sock *sk, struct sk_buff *skb, int segs);
int tcp_retransmit_skb(struct sock *sk, struct sk_buff *skb, int segs);
void tcp_retransmit_timer(struct sock *sk);
void tcp_xmit_retransmit_queue(struct sock *);
void tcp_simple_retransmit(struct sock *);
void tcp_enter_recovery(struct sock *sk, bool ece_ack);
int tcp_trim_head(struct sock *, struct sk_buff *, u32);
enum tcp_queue {
	TCP_FRAG_IN_WRITE_QUEUE,
	TCP_FRAG_IN_RTX_QUEUE,
};
int tcp_fragment(struct sock *sk, enum tcp_queue tcp_queue,
		 struct sk_buff *skb, u32 len,
		 unsigned int mss_now, gfp_t gfp);

void tcp_send_probe0(struct sock *);
void tcp_send_partial(struct sock *);
int tcp_write_wakeup(struct sock *, int mib);
void tcp_send_fin(struct sock *sk);
void tcp_send_active_reset(struct sock *sk, gfp_t priority);
int tcp_send_synack(struct sock *);
void tcp_push_one(struct sock *, unsigned int mss_now);
void __tcp_send_ack(struct sock *sk, u32 rcv_nxt);
void tcp_send_ack(struct sock *sk);
void tcp_send_delayed_ack(struct sock *sk);
void tcp_send_loss_probe(struct sock *sk);
bool tcp_schedule_loss_probe(struct sock *sk, bool advancing_rto);
void tcp_skb_collapse_tstamp(struct sk_buff *skb,
			     const struct sk_buff *next_skb);


void tcp_rearm_rto(struct sock *sk);
void tcp_synack_rtt_meas(struct sock *sk, struct request_sock *req);
void tcp_reset(struct sock *sk);
void tcp_skb_mark_lost_uncond_verify(struct tcp_sock *tp, struct sk_buff *skb);
void tcp_fin(struct sock *sk);


void tcp_init_xmit_timers(struct sock *);
static inline void tcp_clear_xmit_timers(struct sock *sk)
{
	if (hrtimer_try_to_cancel(&tcp_sk(sk)->pacing_timer) == 1)
		__sock_put(sk);

	if (hrtimer_try_to_cancel(&tcp_sk(sk)->compressed_ack_timer) == 1)
		__sock_put(sk);

	inet_csk_clear_xmit_timers(sk);
}

unsigned int tcp_sync_mss(struct sock *sk, u32 pmtu);
unsigned int tcp_current_mss(struct sock *sk);


static inline int tcp_bound_to_half_wnd(struct tcp_sock *tp, int pktsize)
{
	int cutoff;

	
	if (tp->max_window > TCP_MSS_DEFAULT)
		cutoff = (tp->max_window >> 1);
	else
		cutoff = tp->max_window;

	if (cutoff && pktsize > cutoff)
		return max_t(int, cutoff, 68U - tp->tcp_header_len);
	else
		return pktsize;
}


void tcp_get_info(struct sock *, struct tcp_info *);


int tcp_read_sock(struct sock *sk, read_descriptor_t *desc,
		  sk_read_actor_t recv_actor);

void tcp_initialize_rcv_mss(struct sock *sk);

int tcp_mtu_to_mss(struct sock *sk, int pmtu);
int tcp_mss_to_mtu(struct sock *sk, int mss);
void tcp_mtup_init(struct sock *sk);
void tcp_init_buffer_space(struct sock *sk);

static inline void tcp_bound_rto(const struct sock *sk)
{
	if (inet_csk(sk)->icsk_rto > TCP_RTO_MAX)
		inet_csk(sk)->icsk_rto = TCP_RTO_MAX;
}

static inline u32 __tcp_set_rto(const struct tcp_sock *tp)
{
	return usecs_to_jiffies((tp->srtt_us >> 3) + tp->rttvar_us);
}

static inline void __tcp_fast_path_on(struct tcp_sock *tp, u32 snd_wnd)
{
	tp->pred_flags = htonl((tp->tcp_header_len << 26) |
			       ntohl(TCP_FLAG_ACK) |
			       snd_wnd);
}

static inline void tcp_fast_path_on(struct tcp_sock *tp)
{
	__tcp_fast_path_on(tp, tp->snd_wnd >> tp->rx_opt.snd_wscale);
}

static inline void tcp_fast_path_check(struct sock *sk)
{
	struct tcp_sock *tp = tcp_sk(sk);

	if (RB_EMPTY_ROOT(&tp->out_of_order_queue) &&
	    tp->rcv_wnd &&
	    atomic_read(&sk->sk_rmem_alloc) < sk->sk_rcvbuf &&
	    !tp->urg_data)
		tcp_fast_path_on(tp);
}


static inline u32 tcp_rto_min(struct sock *sk)
{
	const struct dst_entry *dst = __sk_dst_get(sk);
	u32 rto_min = TCP_RTO_MIN;

	if (dst && dst_metric_locked(dst, RTAX_RTO_MIN))
		rto_min = dst_metric_rtt(dst, RTAX_RTO_MIN);
	return rto_min;
}

static inline u32 tcp_rto_min_us(struct sock *sk)
{
	return jiffies_to_usecs(tcp_rto_min(sk));
}

static inline bool tcp_ca_dst_locked(const struct dst_entry *dst)
{
	return dst_metric_locked(dst, RTAX_CC_ALGO);
}


static inline u32 tcp_min_rtt(const struct tcp_sock *tp)
{
	return minmax_get(&tp->rtt_min);
}


static inline u32 tcp_receive_window(const struct tcp_sock *tp)
{
	s32 win = tp->rcv_wup + tp->rcv_wnd - tp->rcv_nxt;

	if (win < 0)
		win = 0;
	return (u32) win;
}


u32 __tcp_select_window(struct sock *sk);

void tcp_send_window_probe(struct sock *sk);


#define tcp_jiffies32 ((u32)jiffies)


#define TCP_TS_HZ	1000

static inline u64 tcp_clock_ns(void)
{
	return local_clock();
}

static inline u64 tcp_clock_us(void)
{
	return div_u64(tcp_clock_ns(), NSEC_PER_USEC);
}


static inline u32 tcp_time_stamp(const struct tcp_sock *tp)
{
	return div_u64(tp->tcp_mstamp, USEC_PER_SEC / TCP_TS_HZ);
}


static inline u32 tcp_time_stamp_raw(void)
{
	return div_u64(tcp_clock_ns(), NSEC_PER_SEC / TCP_TS_HZ);
}



static inline void tcp_mstamp_refresh(struct tcp_sock *tp)
{
	u64 val = tcp_clock_us();

	if (val > tp->tcp_mstamp)
		tp->tcp_mstamp = val;
}

static inline u32 tcp_stamp_us_delta(u64 t1, u64 t0)
{
	return max_t(s64, t1 - t0, 0);
}

static inline u32 tcp_skb_timestamp(const struct sk_buff *skb)
{
	return div_u64(skb->skb_mstamp, USEC_PER_SEC / TCP_TS_HZ);
}


#define tcp_flag_byte(th) (((u_int8_t *)th)[13])

#define TCPHDR_FIN 0x01
#define TCPHDR_SYN 0x02
#define TCPHDR_RST 0x04
#define TCPHDR_PSH 0x08
#define TCPHDR_ACK 0x10
#define TCPHDR_URG 0x20
#define TCPHDR_ECE 0x40
#define TCPHDR_CWR 0x80

#define TCPHDR_SYN_ECN	(TCPHDR_SYN | TCPHDR_ECE | TCPHDR_CWR)


struct tcp_skb_cb {
	__u32		seq;		
	__u32		end_seq;	
	union {
		
		__u32		tcp_tw_isn;
		struct {
			u16	tcp_gso_segs;
			u16	tcp_gso_size;
		};
	};
	__u8		tcp_flags;	

	__u8		sacked;		
#define TCPCB_SACKED_ACKED	0x01	
#define TCPCB_SACKED_RETRANS	0x02	
#define TCPCB_LOST		0x04	
#define TCPCB_TAGBITS		0x07	
#define TCPCB_REPAIRED		0x10	
#define TCPCB_EVER_RETRANS	0x80	
#define TCPCB_RETRANS		(TCPCB_SACKED_RETRANS|TCPCB_EVER_RETRANS| \
				TCPCB_REPAIRED)

	__u8		ip_dsfield;	
	__u8		txstamp_ack:1,	
			eor:1,		
			has_rxtstamp:1,	
			unused:5;
	__u32		ack_seq;	
	union {
		struct {
			
			__u32 in_flight:30,
			      is_app_limited:1, 
			      unused:1;
			
			__u32 delivered;
			
			u64 first_tx_mstamp;
			
			u64 delivered_mstamp;
		} tx;   
		union {
			struct inet_skb_parm	h4;
#if IS_ENABLED(CONFIG_IPV6)
			struct inet6_skb_parm	h6;
#endif
		} header;	
		struct {
			__u32 flags;
			struct sock *sk_redir;
			void *data_end;
		} bpf;
	};
};

#define TCP_SKB_CB(__skb)	((struct tcp_skb_cb *)&((__skb)->cb[0]))

static inline void bpf_compute_data_end_sk_skb(struct sk_buff *skb)
{
	TCP_SKB_CB(skb)->bpf.data_end = skb->data + skb_headlen(skb);
}

#if IS_ENABLED(CONFIG_IPV6)

static inline int tcp_v6_iif(const struct sk_buff *skb)
{
	return TCP_SKB_CB(skb)->header.h6.iif;
}

static inline int tcp_v6_iif_l3_slave(const struct sk_buff *skb)
{
	bool l3_slave = ipv6_l3mdev_skb(TCP_SKB_CB(skb)->header.h6.flags);

	return l3_slave ? skb->skb_iif : TCP_SKB_CB(skb)->header.h6.iif;
}


static inline int tcp_v6_sdif(const struct sk_buff *skb)
{
#if IS_ENABLED(CONFIG_NET_L3_MASTER_DEV)
	if (skb && ipv6_l3mdev_skb(TCP_SKB_CB(skb)->header.h6.flags))
		return TCP_SKB_CB(skb)->header.h6.iif;
#endif
	return 0;
}
#endif

static inline bool inet_exact_dif_match(struct net *net, struct sk_buff *skb)
{
#if IS_ENABLED(CONFIG_NET_L3_MASTER_DEV)
	if (!net->ipv4.sysctl_tcp_l3mdev_accept &&
	    skb && ipv4_l3mdev_skb(IPCB(skb)->flags))
		return true;
#endif
	return false;
}


static inline int tcp_v4_sdif(struct sk_buff *skb)
{
#if IS_ENABLED(CONFIG_NET_L3_MASTER_DEV)
	if (skb && ipv4_l3mdev_skb(TCP_SKB_CB(skb)->header.h4.flags))
		return TCP_SKB_CB(skb)->header.h4.iif;
#endif
	return 0;
}


static inline int tcp_skb_pcount(const struct sk_buff *skb)
{
	return TCP_SKB_CB(skb)->tcp_gso_segs;
}

static inline void tcp_skb_pcount_set(struct sk_buff *skb, int segs)
{
	TCP_SKB_CB(skb)->tcp_gso_segs = segs;
}

static inline void tcp_skb_pcount_add(struct sk_buff *skb, int segs)
{
	TCP_SKB_CB(skb)->tcp_gso_segs += segs;
}


static inline int tcp_skb_mss(const struct sk_buff *skb)
{
	return TCP_SKB_CB(skb)->tcp_gso_size;
}

static inline bool tcp_skb_can_collapse_to(const struct sk_buff *skb)
{
	return likely(!TCP_SKB_CB(skb)->eor);
}


enum tcp_ca_event {
	CA_EVENT_TX_START,	
	CA_EVENT_CWND_RESTART,	
	CA_EVENT_COMPLETE_CWR,	
	CA_EVENT_LOSS,		
	CA_EVENT_ECN_NO_CE,	
	CA_EVENT_ECN_IS_CE,	
};


enum tcp_ca_ack_event_flags {
	CA_ACK_SLOWPATH		= (1 << 0),	
	CA_ACK_WIN_UPDATE	= (1 << 1),	
	CA_ACK_ECE		= (1 << 2),	
};


#define TCP_CA_NAME_MAX	16
#define TCP_CA_MAX	128
#define TCP_CA_BUF_MAX	(TCP_CA_NAME_MAX*TCP_CA_MAX)

#define TCP_CA_UNSPEC	0


#define TCP_CONG_NON_RESTRICTED 0x1

#define TCP_CONG_NEEDS_ECN	0x2

union tcp_cc_info;

struct ack_sample {
	u32 pkts_acked;
	s32 rtt_us;
	u32 in_flight;
};


struct rate_sample {
	u64  prior_mstamp; 
	u32  prior_delivered;	
	s32  delivered;		
	long interval_us;	
	u32 snd_interval_us;	
	u32 rcv_interval_us;	
	long rtt_us;		
	int  losses;		
	u32  acked_sacked;	
	u32  prior_in_flight;	
	bool is_app_limited;	
	bool is_retrans;	
	bool is_ack_delayed;	
};

struct tcp_congestion_ops {
	struct list_head	list;
	u32 key;
	u32 flags;

	
	void (*init)(struct sock *sk);
	
	void (*release)(struct sock *sk);

	
	u32 (*ssthresh)(struct sock *sk);
	
	void (*cong_avoid)(struct sock *sk, u32 ack, u32 acked);
	
	void (*set_state)(struct sock *sk, u8 new_state);
	
	void (*cwnd_event)(struct sock *sk, enum tcp_ca_event ev);
	
	void (*in_ack_event)(struct sock *sk, u32 flags);
	
	u32  (*undo_cwnd)(struct sock *sk);
	
	void (*pkts_acked)(struct sock *sk, const struct ack_sample *sample);
	
	u32 (*min_tso_segs)(struct sock *sk);
	
	u32 (*sndbuf_expand)(struct sock *sk);
	
	void (*cong_control)(struct sock *sk, const struct rate_sample *rs);
	
	size_t (*get_info)(struct sock *sk, u32 ext, int *attr,
			   union tcp_cc_info *info);

	char 		name[TCP_CA_NAME_MAX];
	struct module 	*owner;
};

int tcp_register_congestion_control(struct tcp_congestion_ops *type);
void tcp_unregister_congestion_control(struct tcp_congestion_ops *type);

void tcp_assign_congestion_control(struct sock *sk);
void tcp_init_congestion_control(struct sock *sk);
void tcp_cleanup_congestion_control(struct sock *sk);
int tcp_set_default_congestion_control(struct net *net, const char *name);
void tcp_get_default_congestion_control(struct net *net, char *name);
void tcp_get_available_congestion_control(char *buf, size_t len);
void tcp_get_allowed_congestion_control(char *buf, size_t len);
int tcp_set_allowed_congestion_control(char *allowed);
int tcp_set_congestion_control(struct sock *sk, const char *name, bool load,
			       bool reinit, bool cap_net_admin);
u32 tcp_slow_start(struct tcp_sock *tp, u32 acked);
void tcp_cong_avoid_ai(struct tcp_sock *tp, u32 w, u32 acked);

u32 tcp_reno_ssthresh(struct sock *sk);
u32 tcp_reno_undo_cwnd(struct sock *sk);
void tcp_reno_cong_avoid(struct sock *sk, u32 ack, u32 acked);
extern struct tcp_congestion_ops tcp_reno;

struct tcp_congestion_ops *tcp_ca_find_key(u32 key);
u32 tcp_ca_get_key_by_name(struct net *net, const char *name, bool *ecn_ca);
#ifdef CONFIG_INET
char *tcp_ca_get_name_by_key(u32 key, char *buffer);
#else
static inline char *tcp_ca_get_name_by_key(u32 key, char *buffer)
{
	return NULL;
}
#endif

static inline bool tcp_ca_needs_ecn(const struct sock *sk)
{
	const struct inet_connection_sock *icsk = inet_csk(sk);

	return icsk->icsk_ca_ops->flags & TCP_CONG_NEEDS_ECN;
}

static inline void tcp_set_ca_state(struct sock *sk, const u8 ca_state)
{
	struct inet_connection_sock *icsk = inet_csk(sk);

	if (icsk->icsk_ca_ops->set_state)
		icsk->icsk_ca_ops->set_state(sk, ca_state);
	icsk->icsk_ca_state = ca_state;
}

static inline void tcp_ca_event(struct sock *sk, const enum tcp_ca_event event)
{
	const struct inet_connection_sock *icsk = inet_csk(sk);

	if (icsk->icsk_ca_ops->cwnd_event)
		icsk->icsk_ca_ops->cwnd_event(sk, event);
}


void tcp_rate_skb_sent(struct sock *sk, struct sk_buff *skb);
void tcp_rate_skb_delivered(struct sock *sk, struct sk_buff *skb,
			    struct rate_sample *rs);
void tcp_rate_gen(struct sock *sk, u32 delivered, u32 lost,
		  bool is_sack_reneg, struct rate_sample *rs);
void tcp_rate_check_app_limited(struct sock *sk);


static inline int tcp_is_sack(const struct tcp_sock *tp)
{
	return tp->rx_opt.sack_ok;
}

static inline bool tcp_is_reno(const struct tcp_sock *tp)
{
	return !tcp_is_sack(tp);
}

static inline unsigned int tcp_left_out(const struct tcp_sock *tp)
{
	return tp->sacked_out + tp->lost_out;
}


static inline unsigned int tcp_packets_in_flight(const struct tcp_sock *tp)
{
	return tp->packets_out - tcp_left_out(tp) + tp->retrans_out;
}

#define TCP_INFINITE_SSTHRESH	0x7fffffff

static inline bool tcp_in_slow_start(const struct tcp_sock *tp)
{
	return tp->snd_cwnd < tp->snd_ssthresh;
}

static inline bool tcp_in_initial_slowstart(const struct tcp_sock *tp)
{
	return tp->snd_ssthresh >= TCP_INFINITE_SSTHRESH;
}

static inline bool tcp_in_cwnd_reduction(const struct sock *sk)
{
	return (TCPF_CA_CWR | TCPF_CA_Recovery) &
	       (1 << inet_csk(sk)->icsk_ca_state);
}


static inline __u32 tcp_current_ssthresh(const struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);

	if (tcp_in_cwnd_reduction(sk))
		return tp->snd_ssthresh;
	else
		return max(tp->snd_ssthresh,
			   ((tp->snd_cwnd >> 1) +
			    (tp->snd_cwnd >> 2)));
}


#define tcp_verify_left_out(tp)	WARN_ON(tcp_left_out(tp) > tp->packets_out)

void tcp_enter_cwr(struct sock *sk);
__u32 tcp_init_cwnd(const struct tcp_sock *tp, const struct dst_entry *dst);


static inline __u32 tcp_max_tso_deferred_mss(const struct tcp_sock *tp)
{
	return 3;
}


static inline u32 tcp_wnd_end(const struct tcp_sock *tp)
{
	return tp->snd_una + tp->snd_wnd;
}


static inline bool tcp_is_cwnd_limited(const struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);

	
	if (tcp_in_slow_start(tp))
		return tp->snd_cwnd < 2 * tp->max_packets_out;

	return tp->is_cwnd_limited;
}


static inline bool tcp_needs_internal_pacing(const struct sock *sk)
{
	return smp_load_acquire(&sk->sk_pacing_status) == SK_PACING_NEEDED;
}


static inline unsigned long tcp_probe0_base(const struct sock *sk)
{
	return max_t(unsigned long, inet_csk(sk)->icsk_rto, TCP_RTO_MIN);
}


static inline unsigned long tcp_probe0_when(const struct sock *sk,
					    unsigned long max_when)
{
	u64 when = (u64)tcp_probe0_base(sk) << inet_csk(sk)->icsk_backoff;

	return (unsigned long)min_t(u64, when, max_when);
}

static inline void tcp_check_probe_timer(struct sock *sk)
{
	if (!tcp_sk(sk)->packets_out && !inet_csk(sk)->icsk_pending)
		inet_csk_reset_xmit_timer(sk, ICSK_TIME_PROBE0,
					  tcp_probe0_base(sk), TCP_RTO_MAX);
}

static inline void tcp_init_wl(struct tcp_sock *tp, u32 seq)
{
	tp->snd_wl1 = seq;
}

static inline void tcp_update_wl(struct tcp_sock *tp, u32 seq)
{
	tp->snd_wl1 = seq;
}


static inline __sum16 tcp_v4_check(int len, __be32 saddr,
				   __be32 daddr, __wsum base)
{
	return csum_tcpudp_magic(saddr,daddr,len,IPPROTO_TCP,base);
}

static inline __sum16 __tcp_checksum_complete(struct sk_buff *skb)
{
	return __skb_checksum_complete(skb);
}

static inline bool tcp_checksum_complete(struct sk_buff *skb)
{
	return !skb_csum_unnecessary(skb) &&
		__tcp_checksum_complete(skb);
}

bool tcp_add_backlog(struct sock *sk, struct sk_buff *skb);
int tcp_filter(struct sock *sk, struct sk_buff *skb);

#undef STATE_TRACE

#ifdef STATE_TRACE
static const char *statename[]={
	"Unused","Established","Syn Sent","Syn Recv",
	"Fin Wait 1","Fin Wait 2","Time Wait", "Close",
	"Close Wait","Last ACK","Listen","Closing"
};
#endif
void tcp_set_state(struct sock *sk, int state);

void tcp_done(struct sock *sk);

int tcp_abort(struct sock *sk, int err);

static inline void tcp_sack_reset(struct tcp_options_received *rx_opt)
{
	rx_opt->dsack = 0;
	rx_opt->num_sacks = 0;
}

u32 tcp_default_init_rwnd(u32 mss);
void tcp_cwnd_restart(struct sock *sk, s32 delta);

static inline void tcp_slow_start_after_idle_check(struct sock *sk)
{
	const struct tcp_congestion_ops *ca_ops = inet_csk(sk)->icsk_ca_ops;
	struct tcp_sock *tp = tcp_sk(sk);
	s32 delta;

	if (!sock_net(sk)->ipv4.sysctl_tcp_slow_start_after_idle || tp->packets_out ||
	    ca_ops->cong_control)
		return;
	delta = tcp_jiffies32 - tp->lsndtime;
	if (delta > inet_csk(sk)->icsk_rto)
		tcp_cwnd_restart(sk, delta);
}


void tcp_select_initial_window(const struct sock *sk, int __space,
			       __u32 mss, __u32 *rcv_wnd,
			       __u32 *window_clamp, int wscale_ok,
			       __u8 *rcv_wscale, __u32 init_rcv_wnd);

static inline int tcp_win_from_space(const struct sock *sk, int space)
{
	int tcp_adv_win_scale = sock_net(sk)->ipv4.sysctl_tcp_adv_win_scale;

	return tcp_adv_win_scale <= 0 ?
		(space>>(-tcp_adv_win_scale)) :
		space - (space>>tcp_adv_win_scale);
}


static inline int tcp_space(const struct sock *sk)
{
	return tcp_win_from_space(sk, sk->sk_rcvbuf - sk->sk_backlog.len -
				  atomic_read(&sk->sk_rmem_alloc));
}

static inline int tcp_full_space(const struct sock *sk)
{
	return tcp_win_from_space(sk, sk->sk_rcvbuf);
}


static inline bool tcp_rmem_pressure(const struct sock *sk)
{
	int rcvbuf = READ_ONCE(sk->sk_rcvbuf);
	int threshold = rcvbuf - (rcvbuf >> 3);

	return atomic_read(&sk->sk_rmem_alloc) > threshold;
}

extern void tcp_openreq_init_rwin(struct request_sock *req,
				  const struct sock *sk_listener,
				  const struct dst_entry *dst);

void tcp_enter_memory_pressure(struct sock *sk);
void tcp_leave_memory_pressure(struct sock *sk);

static inline int keepalive_intvl_when(const struct tcp_sock *tp)
{
	struct net *net = sock_net((struct sock *)tp);

	return tp->keepalive_intvl ? : net->ipv4.sysctl_tcp_keepalive_intvl;
}

static inline int keepalive_time_when(const struct tcp_sock *tp)
{
	struct net *net = sock_net((struct sock *)tp);

	return tp->keepalive_time ? : net->ipv4.sysctl_tcp_keepalive_time;
}

static inline int keepalive_probes(const struct tcp_sock *tp)
{
	struct net *net = sock_net((struct sock *)tp);

	return tp->keepalive_probes ? : net->ipv4.sysctl_tcp_keepalive_probes;
}

static inline u32 keepalive_time_elapsed(const struct tcp_sock *tp)
{
	const struct inet_connection_sock *icsk = &tp->inet_conn;

	return min_t(u32, tcp_jiffies32 - icsk->icsk_ack.lrcvtime,
			  tcp_jiffies32 - tp->rcv_tstamp);
}

static inline int tcp_fin_time(const struct sock *sk)
{
	int fin_timeout = tcp_sk(sk)->linger2 ? : sock_net(sk)->ipv4.sysctl_tcp_fin_timeout;
	const int rto = inet_csk(sk)->icsk_rto;

	if (fin_timeout < (rto << 2) - (rto >> 1))
		fin_timeout = (rto << 2) - (rto >> 1);

	return fin_timeout;
}

static inline bool tcp_paws_check(const struct tcp_options_received *rx_opt,
				  int paws_win)
{
	if ((s32)(rx_opt->ts_recent - rx_opt->rcv_tsval) <= paws_win)
		return true;
	if (unlikely(!time_before32(ktime_get_seconds(),
				    rx_opt->ts_recent_stamp + TCP_PAWS_24DAYS)))
		return true;
	
	if (!rx_opt->ts_recent)
		return true;
	return false;
}

static inline bool tcp_paws_reject(const struct tcp_options_received *rx_opt,
				   int rst)
{
	if (tcp_paws_check(rx_opt, 0))
		return false;

	
	if (rst && !time_before32(ktime_get_seconds(),
				  rx_opt->ts_recent_stamp + TCP_PAWS_MSL))
		return false;
	return true;
}

bool tcp_oow_rate_limited(struct net *net, const struct sk_buff *skb,
			  int mib_idx, u32 *last_oow_ack_time);

static inline void tcp_mib_init(struct net *net)
{
	
	TCP_ADD_STATS(net, TCP_MIB_RTOALGORITHM, 1);
	TCP_ADD_STATS(net, TCP_MIB_RTOMIN, TCP_RTO_MIN*1000/HZ);
	TCP_ADD_STATS(net, TCP_MIB_RTOMAX, TCP_RTO_MAX*1000/HZ);
	TCP_ADD_STATS(net, TCP_MIB_MAXCONN, -1);
}


static inline void tcp_clear_retrans_hints_partial(struct tcp_sock *tp)
{
	tp->lost_skb_hint = NULL;
}

static inline void tcp_clear_all_retrans_hints(struct tcp_sock *tp)
{
	tcp_clear_retrans_hints_partial(tp);
	tp->retransmit_skb_hint = NULL;
}

union tcp_md5_addr {
	struct in_addr  a4;
#if IS_ENABLED(CONFIG_IPV6)
	struct in6_addr	a6;
#endif
};


struct tcp_md5sig_key {
	struct hlist_node	node;
	u8			keylen;
	u8			family; 
	union tcp_md5_addr	addr;
	u8			prefixlen;
	u8			key[TCP_MD5SIG_MAXKEYLEN];
	struct rcu_head		rcu;
};


struct tcp_md5sig_info {
	struct hlist_head	head;
	struct rcu_head		rcu;
};


struct tcp4_pseudohdr {
	__be32		saddr;
	__be32		daddr;
	__u8		pad;
	__u8		protocol;
	__be16		len;
};

struct tcp6_pseudohdr {
	struct in6_addr	saddr;
	struct in6_addr daddr;
	__be32		len;
	__be32		protocol;	
};

union tcp_md5sum_block {
	struct tcp4_pseudohdr ip4;
#if IS_ENABLED(CONFIG_IPV6)
	struct tcp6_pseudohdr ip6;
#endif
};


struct tcp_md5sig_pool {
	struct ahash_request	*md5_req;
	void			*scratch;
};


int tcp_v4_md5_hash_skb(char *md5_hash, const struct tcp_md5sig_key *key,
			const struct sock *sk, const struct sk_buff *skb);
int tcp_md5_do_add(struct sock *sk, const union tcp_md5_addr *addr,
		   int family, u8 prefixlen, const u8 *newkey, u8 newkeylen,
		   gfp_t gfp);
int tcp_md5_do_del(struct sock *sk, const union tcp_md5_addr *addr,
		   int family, u8 prefixlen);
struct tcp_md5sig_key *tcp_v4_md5_lookup(const struct sock *sk,
					 const struct sock *addr_sk);

#ifdef CONFIG_TCP_MD5SIG
struct tcp_md5sig_key *tcp_md5_do_lookup(const struct sock *sk,
					 const union tcp_md5_addr *addr,
					 int family);
#define tcp_twsk_md5_key(twsk)	((twsk)->tw_md5_key)
#else
static inline struct tcp_md5sig_key *tcp_md5_do_lookup(const struct sock *sk,
					 const union tcp_md5_addr *addr,
					 int family)
{
	return NULL;
}
#define tcp_twsk_md5_key(twsk)	NULL
#endif

bool tcp_alloc_md5sig_pool(void);

struct tcp_md5sig_pool *tcp_get_md5sig_pool(void);
static inline void tcp_put_md5sig_pool(void)
{
	local_bh_enable();
}

int tcp_md5_hash_skb_data(struct tcp_md5sig_pool *, const struct sk_buff *,
			  unsigned int header_len);
int tcp_md5_hash_key(struct tcp_md5sig_pool *hp,
		     const struct tcp_md5sig_key *key);


void tcp_fastopen_cache_get(struct sock *sk, u16 *mss,
			    struct tcp_fastopen_cookie *cookie);
void tcp_fastopen_cache_set(struct sock *sk, u16 mss,
			    struct tcp_fastopen_cookie *cookie, bool syn_lost,
			    u16 try_exp);
struct tcp_fastopen_request {
	
	struct tcp_fastopen_cookie	cookie;
	struct msghdr			*data;  
	size_t				size;
	int				copied;	
};
void tcp_free_fastopen_req(struct tcp_sock *tp);
void tcp_fastopen_destroy_cipher(struct sock *sk);
void tcp_fastopen_ctx_destroy(struct net *net);
int tcp_fastopen_reset_cipher(struct net *net, struct sock *sk,
			      void *key, unsigned int len);
void tcp_fastopen_add_skb(struct sock *sk, struct sk_buff *skb);
struct sock *tcp_try_fastopen(struct sock *sk, struct sk_buff *skb,
			      struct request_sock *req,
			      struct tcp_fastopen_cookie *foc,
			      const struct dst_entry *dst);
void tcp_fastopen_init_key_once(struct net *net);
bool tcp_fastopen_cookie_check(struct sock *sk, u16 *mss,
			     struct tcp_fastopen_cookie *cookie);
bool tcp_fastopen_defer_connect(struct sock *sk, int *err);
#define TCP_FASTOPEN_KEY_LENGTH 16


struct tcp_fastopen_context {
	struct crypto_cipher	*tfm;
	__u8			key[TCP_FASTOPEN_KEY_LENGTH];
	struct rcu_head		rcu;
};

extern unsigned int sysctl_tcp_fastopen_blackhole_timeout;
void tcp_fastopen_active_disable(struct sock *sk);
bool tcp_fastopen_active_should_disable(struct sock *sk);
void tcp_fastopen_active_disable_ofo_check(struct sock *sk);
void tcp_fastopen_active_detect_blackhole(struct sock *sk, bool expired);


enum tcp_chrono {
	TCP_CHRONO_UNSPEC,
	TCP_CHRONO_BUSY, 
	TCP_CHRONO_RWND_LIMITED, 
	TCP_CHRONO_SNDBUF_LIMITED, 
	__TCP_CHRONO_MAX,
};

void tcp_chrono_start(struct sock *sk, const enum tcp_chrono type);
void tcp_chrono_stop(struct sock *sk, const enum tcp_chrono type);


static inline void tcp_skb_tsorted_anchor_cleanup(struct sk_buff *skb)
{
	skb->destructor = NULL;
	skb->_skb_refdst = 0UL;
}

#define tcp_skb_tsorted_save(skb) {		\
	unsigned long _save = skb->_skb_refdst;	\
	skb->_skb_refdst = 0UL;

#define tcp_skb_tsorted_restore(skb)		\
	skb->_skb_refdst = _save;		\
}

void tcp_write_queue_purge(struct sock *sk);

static inline struct sk_buff *tcp_rtx_queue_head(const struct sock *sk)
{
	return skb_rb_first(&sk->tcp_rtx_queue);
}

static inline struct sk_buff *tcp_rtx_queue_tail(const struct sock *sk)
{
	return skb_rb_last(&sk->tcp_rtx_queue);
}

static inline struct sk_buff *tcp_write_queue_head(const struct sock *sk)
{
	return skb_peek(&sk->sk_write_queue);
}

static inline struct sk_buff *tcp_write_queue_tail(const struct sock *sk)
{
	return skb_peek_tail(&sk->sk_write_queue);
}

#define tcp_for_write_queue_from_safe(skb, tmp, sk)			\
	skb_queue_walk_from_safe(&(sk)->sk_write_queue, skb, tmp)

static inline struct sk_buff *tcp_send_head(const struct sock *sk)
{
	return skb_peek(&sk->sk_write_queue);
}

static inline bool tcp_skb_is_last(const struct sock *sk,
				   const struct sk_buff *skb)
{
	return skb_queue_is_last(&sk->sk_write_queue, skb);
}

static inline bool tcp_write_queue_empty(const struct sock *sk)
{
	return skb_queue_empty(&sk->sk_write_queue);
}

static inline bool tcp_rtx_queue_empty(const struct sock *sk)
{
	return RB_EMPTY_ROOT(&sk->tcp_rtx_queue);
}

static inline bool tcp_rtx_and_write_queues_empty(const struct sock *sk)
{
	return tcp_rtx_queue_empty(sk) && tcp_write_queue_empty(sk);
}

static inline void tcp_check_send_head(struct sock *sk, struct sk_buff *skb_unlinked)
{
	if (tcp_write_queue_empty(sk))
		tcp_chrono_stop(sk, TCP_CHRONO_BUSY);
}

static inline void __tcp_add_write_queue_tail(struct sock *sk, struct sk_buff *skb)
{
	__skb_queue_tail(&sk->sk_write_queue, skb);
}

static inline void tcp_add_write_queue_tail(struct sock *sk, struct sk_buff *skb)
{
	__tcp_add_write_queue_tail(sk, skb);

	
	if (sk->sk_write_queue.next == skb)
		tcp_chrono_start(sk, TCP_CHRONO_BUSY);
}


static inline void tcp_insert_write_queue_before(struct sk_buff *new,
						  struct sk_buff *skb,
						  struct sock *sk)
{
	__skb_queue_before(&sk->sk_write_queue, skb, new);
}

static inline void tcp_unlink_write_queue(struct sk_buff *skb, struct sock *sk)
{
	tcp_skb_tsorted_anchor_cleanup(skb);
	__skb_unlink(skb, &sk->sk_write_queue);
}

void tcp_rbtree_insert(struct rb_root *root, struct sk_buff *skb);

static inline void tcp_rtx_queue_unlink(struct sk_buff *skb, struct sock *sk)
{
	tcp_skb_tsorted_anchor_cleanup(skb);
	rb_erase(&skb->rbnode, &sk->tcp_rtx_queue);
}

static inline void tcp_rtx_queue_unlink_and_free(struct sk_buff *skb, struct sock *sk)
{
	list_del(&skb->tcp_tsorted_anchor);
	tcp_rtx_queue_unlink(skb, sk);
	sk_wmem_free_skb(sk, skb);
}

static inline void tcp_push_pending_frames(struct sock *sk)
{
	if (tcp_send_head(sk)) {
		struct tcp_sock *tp = tcp_sk(sk);

		__tcp_push_pending_frames(sk, tcp_current_mss(sk), tp->nonagle);
	}
}


static inline u32 tcp_highest_sack_seq(struct tcp_sock *tp)
{
	if (!tp->sacked_out)
		return tp->snd_una;

	if (tp->highest_sack == NULL)
		return tp->snd_nxt;

	return TCP_SKB_CB(tp->highest_sack)->seq;
}

static inline void tcp_advance_highest_sack(struct sock *sk, struct sk_buff *skb)
{
	tcp_sk(sk)->highest_sack = skb_rb_next(skb);
}

static inline struct sk_buff *tcp_highest_sack(struct sock *sk)
{
	return tcp_sk(sk)->highest_sack;
}

static inline void tcp_highest_sack_reset(struct sock *sk)
{
	tcp_sk(sk)->highest_sack = tcp_rtx_queue_head(sk);
}


static inline void tcp_highest_sack_replace(struct sock *sk,
					    struct sk_buff *old,
					    struct sk_buff *new)
{
	if (old == tcp_highest_sack(sk))
		tcp_sk(sk)->highest_sack = new;
}


static inline bool inet_sk_transparent(const struct sock *sk)
{
	switch (sk->sk_state) {
	case TCP_TIME_WAIT:
		return inet_twsk(sk)->tw_transparent;
	case TCP_NEW_SYN_RECV:
		return inet_rsk(inet_reqsk(sk))->no_srccheck;
	}
	return inet_sk(sk)->transparent;
}


static inline bool tcp_stream_is_thin(struct tcp_sock *tp)
{
	return tp->packets_out < 4 && !tcp_in_initial_slowstart(tp);
}


enum tcp_seq_states {
	TCP_SEQ_STATE_LISTENING,
	TCP_SEQ_STATE_ESTABLISHED,
};

void *tcp_seq_start(struct seq_file *seq, loff_t *pos);
void *tcp_seq_next(struct seq_file *seq, void *v, loff_t *pos);
void tcp_seq_stop(struct seq_file *seq, void *v);

struct tcp_seq_afinfo {
	sa_family_t			family;
};

struct tcp_iter_state {
	struct seq_net_private	p;
	enum tcp_seq_states	state;
	struct sock		*syn_wait_sk;
	int			bucket, offset, sbucket, num;
	loff_t			last_pos;
};

extern struct request_sock_ops tcp_request_sock_ops;
extern struct request_sock_ops tcp6_request_sock_ops;

void tcp_v4_destroy_sock(struct sock *sk);

struct sk_buff *tcp_gso_segment(struct sk_buff *skb,
				netdev_features_t features);
struct sk_buff *tcp_gro_receive(struct list_head *head, struct sk_buff *skb);
int tcp_gro_complete(struct sk_buff *skb);

void __tcp_v4_send_check(struct sk_buff *skb, __be32 saddr, __be32 daddr);

static inline u32 tcp_notsent_lowat(const struct tcp_sock *tp)
{
	struct net *net = sock_net((struct sock *)tp);
	return tp->notsent_lowat ?: net->ipv4.sysctl_tcp_notsent_lowat;
}

static inline bool tcp_stream_memory_free(const struct sock *sk)
{
	const struct tcp_sock *tp = tcp_sk(sk);
	u32 notsent_bytes = tp->write_seq - tp->snd_nxt;

	return notsent_bytes < tcp_notsent_lowat(tp);
}

#ifdef CONFIG_PROC_FS
int tcp4_proc_init(void);
void tcp4_proc_exit(void);
#endif

int tcp_rtx_synack(const struct sock *sk, struct request_sock *req);
int tcp_conn_request(struct request_sock_ops *rsk_ops,
		     const struct tcp_request_sock_ops *af_ops,
		     struct sock *sk, struct sk_buff *skb);


struct tcp_sock_af_ops {
#ifdef CONFIG_TCP_MD5SIG
	struct tcp_md5sig_key	*(*md5_lookup) (const struct sock *sk,
						const struct sock *addr_sk);
	int		(*calc_md5_hash)(char *location,
					 const struct tcp_md5sig_key *md5,
					 const struct sock *sk,
					 const struct sk_buff *skb);
	int		(*md5_parse)(struct sock *sk,
				     int optname,
				     char __user *optval,
				     int optlen);
#endif
};

struct tcp_request_sock_ops {
	u16 mss_clamp;
#ifdef CONFIG_TCP_MD5SIG
	struct tcp_md5sig_key *(*req_md5_lookup)(const struct sock *sk,
						 const struct sock *addr_sk);
	int		(*calc_md5_hash) (char *location,
					  const struct tcp_md5sig_key *md5,
					  const struct sock *sk,
					  const struct sk_buff *skb);
#endif
	void (*init_req)(struct request_sock *req,
			 const struct sock *sk_listener,
			 struct sk_buff *skb);
#ifdef CONFIG_SYN_COOKIES
	__u32 (*cookie_init_seq)(const struct sk_buff *skb,
				 __u16 *mss);
#endif
	struct dst_entry *(*route_req)(const struct sock *sk, struct flowi *fl,
				       const struct request_sock *req);
	u32 (*init_seq)(const struct sk_buff *skb);
	u32 (*init_ts_off)(const struct net *net, const struct sk_buff *skb);
	int (*send_synack)(const struct sock *sk, struct dst_entry *dst,
			   struct flowi *fl, struct request_sock *req,
			   struct tcp_fastopen_cookie *foc,
			   enum tcp_synack_type synack_type);
};

#ifdef CONFIG_SYN_COOKIES
static inline __u32 cookie_init_sequence(const struct tcp_request_sock_ops *ops,
					 const struct sock *sk, struct sk_buff *skb,
					 __u16 *mss)
{
	tcp_synq_overflow(sk);
	__NET_INC_STATS(sock_net(sk), LINUX_MIB_SYNCOOKIESSENT);
	return ops->cookie_init_seq(skb, mss);
}
#else
static inline __u32 cookie_init_sequence(const struct tcp_request_sock_ops *ops,
					 const struct sock *sk, struct sk_buff *skb,
					 __u16 *mss)
{
	return 0;
}
#endif

int tcpv4_offload_init(void);

void tcp_v4_init(void);
void tcp_init(void);


void tcp_mark_skb_lost(struct sock *sk, struct sk_buff *skb);
void tcp_newreno_mark_lost(struct sock *sk, bool snd_una_advanced);
extern s32 tcp_rack_skb_timeout(struct tcp_sock *tp, struct sk_buff *skb,
				u32 reo_wnd);
extern void tcp_rack_mark_lost(struct sock *sk);
extern void tcp_rack_advance(struct tcp_sock *tp, u8 sacked, u32 end_seq,
			     u64 xmit_time);
extern void tcp_rack_reo_timeout(struct sock *sk);
extern void tcp_rack_update_reo_wnd(struct sock *sk, struct rate_sample *rs);


static inline s64 tcp_rto_delta_us(const struct sock *sk)
{
	const struct sk_buff *skb = tcp_rtx_queue_head(sk);
	u32 rto = inet_csk(sk)->icsk_rto;
	u64 rto_time_stamp_us = skb->skb_mstamp + jiffies_to_usecs(rto);

	return rto_time_stamp_us - tcp_sk(sk)->tcp_mstamp;
}


static inline struct ip_options_rcu *tcp_v4_save_options(struct net *net,
							 struct sk_buff *skb)
{
	const struct ip_options *opt = &TCP_SKB_CB(skb)->header.h4.opt;
	struct ip_options_rcu *dopt = NULL;

	if (opt->optlen) {
		int opt_size = sizeof(*dopt) + opt->optlen;

		dopt = kmalloc(opt_size, GFP_ATOMIC);
		if (dopt && __ip_options_echo(net, &dopt->opt, skb, opt)) {
			kfree(dopt);
			dopt = NULL;
		}
	}
	return dopt;
}


static inline bool skb_is_tcp_pure_ack(const struct sk_buff *skb)
{
	return skb->truesize == 2;
}

static inline void skb_set_tcp_pure_ack(struct sk_buff *skb)
{
	skb->truesize = 2;
}

static inline int tcp_inq(struct sock *sk)
{
	struct tcp_sock *tp = tcp_sk(sk);
	int answ;

	if ((1 << sk->sk_state) & (TCPF_SYN_SENT | TCPF_SYN_RECV)) {
		answ = 0;
	} else if (sock_flag(sk, SOCK_URGINLINE) ||
		   !tp->urg_data ||
		   before(tp->urg_seq, tp->copied_seq) ||
		   !before(tp->urg_seq, tp->rcv_nxt)) {

		answ = tp->rcv_nxt - tp->copied_seq;

		
		if (answ && sock_flag(sk, SOCK_DONE))
			answ--;
	} else {
		answ = tp->urg_seq - tp->copied_seq;
	}

	return answ;
}

int tcp_peek_len(struct socket *sock);

static inline void tcp_segs_in(struct tcp_sock *tp, const struct sk_buff *skb)
{
	u16 segs_in;

	segs_in = max_t(u16, 1, skb_shinfo(skb)->gso_segs);
	tp->segs_in += segs_in;
	if (skb->len > tcp_hdrlen(skb))
		tp->data_segs_in += segs_in;
}


static inline void tcp_listendrop(const struct sock *sk)
{
	atomic_inc(&((struct sock *)sk)->sk_drops);
	__NET_INC_STATS(sock_net(sk), LINUX_MIB_LISTENDROPS);
}

enum hrtimer_restart tcp_pace_kick(struct hrtimer *timer);



#define TCP_ULP_NAME_MAX	16
#define TCP_ULP_MAX		128
#define TCP_ULP_BUF_MAX		(TCP_ULP_NAME_MAX*TCP_ULP_MAX)

enum {
	TCP_ULP_TLS,
	TCP_ULP_BPF,
};

struct tcp_ulp_ops {
	struct list_head	list;

	
	int (*init)(struct sock *sk);
	
	void (*release)(struct sock *sk);

	int		uid;
	char		name[TCP_ULP_NAME_MAX];
	bool		user_visible;
	struct module	*owner;
};
int tcp_register_ulp(struct tcp_ulp_ops *type);
void tcp_unregister_ulp(struct tcp_ulp_ops *type);
int tcp_set_ulp(struct sock *sk, const char *name);
int tcp_set_ulp_id(struct sock *sk, const int ulp);
void tcp_get_available_ulp(char *buf, size_t len);
void tcp_cleanup_ulp(struct sock *sk);

#define MODULE_ALIAS_TCP_ULP(name)				\
	__MODULE_INFO(alias, alias_userspace, name);		\
	__MODULE_INFO(alias, alias_tcp_ulp, "tcp-ulp-" name)


#ifdef CONFIG_BPF
static inline int tcp_call_bpf(struct sock *sk, int op, u32 nargs, u32 *args)
{
	struct bpf_sock_ops_kern sock_ops;
	int ret;

	memset(&sock_ops, 0, offsetof(struct bpf_sock_ops_kern, temp));
	if (sk_fullsock(sk)) {
		sock_ops.is_fullsock = 1;
		sock_owned_by_me(sk);
	}

	sock_ops.sk = sk;
	sock_ops.op = op;
	if (nargs > 0)
		memcpy(sock_ops.args, args, nargs * sizeof(*args));

	ret = BPF_CGROUP_RUN_PROG_SOCK_OPS(&sock_ops);
	if (ret == 0)
		ret = sock_ops.reply;
	else
		ret = -1;
	return ret;
}

static inline int tcp_call_bpf_2arg(struct sock *sk, int op, u32 arg1, u32 arg2)
{
	u32 args[2] = {arg1, arg2};

	return tcp_call_bpf(sk, op, 2, args);
}

static inline int tcp_call_bpf_3arg(struct sock *sk, int op, u32 arg1, u32 arg2,
				    u32 arg3)
{
	u32 args[3] = {arg1, arg2, arg3};

	return tcp_call_bpf(sk, op, 3, args);
}

#else
static inline int tcp_call_bpf(struct sock *sk, int op, u32 nargs, u32 *args)
{
	return -EPERM;
}

static inline int tcp_call_bpf_2arg(struct sock *sk, int op, u32 arg1, u32 arg2)
{
	return -EPERM;
}

static inline int tcp_call_bpf_3arg(struct sock *sk, int op, u32 arg1, u32 arg2,
				    u32 arg3)
{
	return -EPERM;
}

#endif

static inline u32 tcp_timeout_init(struct sock *sk)
{
	int timeout;

	timeout = tcp_call_bpf(sk, BPF_SOCK_OPS_TIMEOUT_INIT, 0, NULL);

	if (timeout <= 0)
		timeout = TCP_TIMEOUT_INIT;
	return timeout;
}

static inline u32 tcp_rwnd_init_bpf(struct sock *sk)
{
	int rwnd;

	rwnd = tcp_call_bpf(sk, BPF_SOCK_OPS_RWND_INIT, 0, NULL);

	if (rwnd < 0)
		rwnd = 0;
	return rwnd;
}

static inline bool tcp_bpf_ca_needs_ecn(struct sock *sk)
{
	return (tcp_call_bpf(sk, BPF_SOCK_OPS_NEEDS_ECN, 0, NULL) == 1);
}

#if IS_ENABLED(CONFIG_SMC)
extern struct static_key_false tcp_have_smc;
#endif

#if IS_ENABLED(CONFIG_TLS_DEVICE)
void clean_acked_data_enable(struct inet_connection_sock *icsk,
			     void (*cad)(struct sock *sk, u32 ack_seq));
void clean_acked_data_disable(struct inet_connection_sock *icsk);

#endif

#endif	
