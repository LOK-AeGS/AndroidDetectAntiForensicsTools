
#ifndef __LINUX_IP6_NETFILTER_H
#define __LINUX_IP6_NETFILTER_H

#include <uapi/linux/netfilter_ipv6.h>


struct ip6_rt_info {
	struct in6_addr daddr;
	struct in6_addr saddr;
	u_int32_t mark;
};

struct nf_queue_entry;


struct nf_ipv6_ops {
	int (*chk_addr)(struct net *net, const struct in6_addr *addr,
			const struct net_device *dev, int strict);
	void (*route_input)(struct sk_buff *skb);
	int (*fragment)(struct net *net, struct sock *sk, struct sk_buff *skb,
			int (*output)(struct net *, struct sock *, struct sk_buff *));
	int (*route)(struct net *net, struct dst_entry **dst, struct flowi *fl,
		     bool strict);
	int (*reroute)(struct sk_buff *skb, const struct nf_queue_entry *entry);
};

#ifdef CONFIG_NETFILTER
int ip6_route_me_harder(struct net *net, struct sk_buff *skb);
__sum16 nf_ip6_checksum(struct sk_buff *skb, unsigned int hook,
			unsigned int dataoff, u_int8_t protocol);

int ipv6_netfilter_init(void);
void ipv6_netfilter_fini(void);

extern const struct nf_ipv6_ops __rcu *nf_ipv6_ops;
static inline const struct nf_ipv6_ops *nf_get_ipv6_ops(void)
{
	return rcu_dereference(nf_ipv6_ops);
}

#else 
static inline int ipv6_netfilter_init(void) { return 0; }
static inline void ipv6_netfilter_fini(void) { return; }
static inline const struct nf_ipv6_ops *nf_get_ipv6_ops(void) { return NULL; }
#endif 

#endif 
