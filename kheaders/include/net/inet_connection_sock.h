
#ifndef _INET_CONNECTION_SOCK_H
#define _INET_CONNECTION_SOCK_H

#include <linux/compiler.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/poll.h>
#include <linux/kernel.h>

#include <net/inet_sock.h>
#include <net/request_sock.h>


#undef INET_CSK_CLEAR_TIMERS

struct inet_bind_bucket;
struct tcp_congestion_ops;


struct inet_connection_sock_af_ops {
	int	    (*queue_xmit)(struct sock *sk, struct sk_buff *skb, struct flowi *fl);
	void	    (*send_check)(struct sock *sk, struct sk_buff *skb);
	int	    (*rebuild_header)(struct sock *sk);
	void	    (*sk_rx_dst_set)(struct sock *sk, const struct sk_buff *skb);
	int	    (*conn_request)(struct sock *sk, struct sk_buff *skb);
	struct sock *(*syn_recv_sock)(const struct sock *sk, struct sk_buff *skb,
				      struct request_sock *req,
				      struct dst_entry *dst,
				      struct request_sock *req_unhash,
				      bool *own_req);
	u16	    net_header_len;
	u16	    net_frag_header_len;
	u16	    sockaddr_len;
	int	    (*setsockopt)(struct sock *sk, int level, int optname,
				  char __user *optval, unsigned int optlen);
	int	    (*getsockopt)(struct sock *sk, int level, int optname,
				  char __user *optval, int __user *optlen);
#ifdef CONFIG_COMPAT
	int	    (*compat_setsockopt)(struct sock *sk,
				int level, int optname,
				char __user *optval, unsigned int optlen);
	int	    (*compat_getsockopt)(struct sock *sk,
				int level, int optname,
				char __user *optval, int __user *optlen);
#endif
	void	    (*addr2sockaddr)(struct sock *sk, struct sockaddr *);
	void	    (*mtu_reduced)(struct sock *sk);
};


struct inet_connection_sock {
	
	struct inet_sock	  icsk_inet;
	struct request_sock_queue icsk_accept_queue;
	struct inet_bind_bucket	  *icsk_bind_hash;
	unsigned long		  icsk_timeout;
 	struct timer_list	  icsk_retransmit_timer;
 	struct timer_list	  icsk_delack_timer;
	__u32			  icsk_rto;
	__u32			  icsk_pmtu_cookie;
	const struct tcp_congestion_ops *icsk_ca_ops;
	const struct inet_connection_sock_af_ops *icsk_af_ops;
	const struct tcp_ulp_ops  *icsk_ulp_ops;
	void			  *icsk_ulp_data;
	void (*icsk_clean_acked)(struct sock *sk, u32 acked_seq);
	struct hlist_node         icsk_listen_portaddr_node;
	unsigned int		  (*icsk_sync_mss)(struct sock *sk, u32 pmtu);
	__u8			  icsk_ca_state:6,
				  icsk_ca_setsockopt:1,
				  icsk_ca_dst_locked:1;
	__u8			  icsk_retransmits;
	__u8			  icsk_pending;
	__u8			  icsk_backoff;
	__u8			  icsk_syn_retries;
	__u8			  icsk_probes_out;
	__u16			  icsk_ext_hdr_len;
	struct {
		__u8		  pending;	 
		__u8		  quick;	 
		__u8		  pingpong;	 
		__u8		  blocked;	 
		__u32		  ato;		 
		unsigned long	  timeout;	 
		__u32		  lrcvtime;	 
		__u16		  last_seg_size; 
		__u16		  rcv_mss;	 
	} icsk_ack;
	struct {
		int		  enabled;

		
		int		  search_high;
		int		  search_low;

		
		int		  probe_size;

		u32		  probe_timestamp;
	} icsk_mtup;
	u32			  icsk_user_timeout;

	u64			  icsk_ca_priv[104 / sizeof(u64)];
#define ICSK_CA_PRIV_SIZE      (13 * sizeof(u64))
};

#define ICSK_TIME_RETRANS	1	
#define ICSK_TIME_DACK		2	
#define ICSK_TIME_PROBE0	3	
#define ICSK_TIME_EARLY_RETRANS 4	
#define ICSK_TIME_LOSS_PROBE	5	
#define ICSK_TIME_REO_TIMEOUT	6	

static inline struct inet_connection_sock *inet_csk(const struct sock *sk)
{
	return (struct inet_connection_sock *)sk;
}

static inline void *inet_csk_ca(const struct sock *sk)
{
	return (void *)inet_csk(sk)->icsk_ca_priv;
}

struct sock *inet_csk_clone_lock(const struct sock *sk,
				 const struct request_sock *req,
				 const gfp_t priority);

enum inet_csk_ack_state_t {
	ICSK_ACK_SCHED	= 1,
	ICSK_ACK_TIMER  = 2,
	ICSK_ACK_PUSHED = 4,
	ICSK_ACK_PUSHED2 = 8,
	ICSK_ACK_NOW = 16	
};

void inet_csk_init_xmit_timers(struct sock *sk,
			       void (*retransmit_handler)(struct timer_list *),
			       void (*delack_handler)(struct timer_list *),
			       void (*keepalive_handler)(struct timer_list *));
void inet_csk_clear_xmit_timers(struct sock *sk);

static inline void inet_csk_schedule_ack(struct sock *sk)
{
	inet_csk(sk)->icsk_ack.pending |= ICSK_ACK_SCHED;
}

static inline int inet_csk_ack_scheduled(const struct sock *sk)
{
	return inet_csk(sk)->icsk_ack.pending & ICSK_ACK_SCHED;
}

static inline void inet_csk_delack_init(struct sock *sk)
{
	memset(&inet_csk(sk)->icsk_ack, 0, sizeof(inet_csk(sk)->icsk_ack));
}

void inet_csk_delete_keepalive_timer(struct sock *sk);
void inet_csk_reset_keepalive_timer(struct sock *sk, unsigned long timeout);

static inline void inet_csk_clear_xmit_timer(struct sock *sk, const int what)
{
	struct inet_connection_sock *icsk = inet_csk(sk);

	if (what == ICSK_TIME_RETRANS || what == ICSK_TIME_PROBE0) {
		icsk->icsk_pending = 0;
#ifdef INET_CSK_CLEAR_TIMERS
		sk_stop_timer(sk, &icsk->icsk_retransmit_timer);
#endif
	} else if (what == ICSK_TIME_DACK) {
		icsk->icsk_ack.blocked = icsk->icsk_ack.pending = 0;
#ifdef INET_CSK_CLEAR_TIMERS
		sk_stop_timer(sk, &icsk->icsk_delack_timer);
#endif
	} else {
		pr_debug("inet_csk BUG: unknown timer value\n");
	}
}


static inline void inet_csk_reset_xmit_timer(struct sock *sk, const int what,
					     unsigned long when,
					     const unsigned long max_when)
{
	struct inet_connection_sock *icsk = inet_csk(sk);

	if (when > max_when) {
		pr_debug("reset_xmit_timer: sk=%p %d when=0x%lx, caller=%p\n",
			 sk, what, when, (void *)_THIS_IP_);
		when = max_when;
	}

	if (what == ICSK_TIME_RETRANS || what == ICSK_TIME_PROBE0 ||
	    what == ICSK_TIME_EARLY_RETRANS || what == ICSK_TIME_LOSS_PROBE ||
	    what == ICSK_TIME_REO_TIMEOUT) {
		icsk->icsk_pending = what;
		icsk->icsk_timeout = jiffies + when;
		sk_reset_timer(sk, &icsk->icsk_retransmit_timer, icsk->icsk_timeout);
	} else if (what == ICSK_TIME_DACK) {
		icsk->icsk_ack.pending |= ICSK_ACK_TIMER;
		icsk->icsk_ack.timeout = jiffies + when;
		sk_reset_timer(sk, &icsk->icsk_delack_timer, icsk->icsk_ack.timeout);
	} else {
		pr_debug("inet_csk BUG: unknown timer value\n");
	}
}

static inline unsigned long
inet_csk_rto_backoff(const struct inet_connection_sock *icsk,
		     unsigned long max_when)
{
        u64 when = (u64)icsk->icsk_rto << icsk->icsk_backoff;

        return (unsigned long)min_t(u64, when, max_when);
}

struct sock *inet_csk_accept(struct sock *sk, int flags, int *err, bool kern);

int inet_csk_get_port(struct sock *sk, unsigned short snum);

struct dst_entry *inet_csk_route_req(const struct sock *sk, struct flowi4 *fl4,
				     const struct request_sock *req);
struct dst_entry *inet_csk_route_child_sock(const struct sock *sk,
					    struct sock *newsk,
					    const struct request_sock *req);

struct sock *inet_csk_reqsk_queue_add(struct sock *sk,
				      struct request_sock *req,
				      struct sock *child);
void inet_csk_reqsk_queue_hash_add(struct sock *sk, struct request_sock *req,
				   unsigned long timeout);
struct sock *inet_csk_complete_hashdance(struct sock *sk, struct sock *child,
					 struct request_sock *req,
					 bool own_req);

static inline void inet_csk_reqsk_queue_added(struct sock *sk)
{
	reqsk_queue_added(&inet_csk(sk)->icsk_accept_queue);
}

static inline int inet_csk_reqsk_queue_len(const struct sock *sk)
{
	return reqsk_queue_len(&inet_csk(sk)->icsk_accept_queue);
}

static inline int inet_csk_reqsk_queue_is_full(const struct sock *sk)
{
	return inet_csk_reqsk_queue_len(sk) >= sk->sk_max_ack_backlog;
}

void inet_csk_reqsk_queue_drop(struct sock *sk, struct request_sock *req);
void inet_csk_reqsk_queue_drop_and_put(struct sock *sk, struct request_sock *req);

void inet_csk_destroy_sock(struct sock *sk);
void inet_csk_prepare_forced_close(struct sock *sk);


static inline __poll_t inet_csk_listen_poll(const struct sock *sk)
{
	return !reqsk_queue_empty(&inet_csk(sk)->icsk_accept_queue) ?
			(EPOLLIN | EPOLLRDNORM) : 0;
}

int inet_csk_listen_start(struct sock *sk, int backlog);
void inet_csk_listen_stop(struct sock *sk);

void inet_csk_addr2sockaddr(struct sock *sk, struct sockaddr *uaddr);

int inet_csk_compat_getsockopt(struct sock *sk, int level, int optname,
			       char __user *optval, int __user *optlen);
int inet_csk_compat_setsockopt(struct sock *sk, int level, int optname,
			       char __user *optval, unsigned int optlen);


void inet_csk_update_fastreuse(struct inet_bind_bucket *tb,
			       struct sock *sk);

struct dst_entry *inet_csk_update_pmtu(struct sock *sk, u32 mtu);
#endif 
