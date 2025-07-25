/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_VIRTIO_NET_H
#define _LINUX_VIRTIO_NET_H

#include <linux/if_vlan.h>
#include <uapi/linux/tcp.h>
#include <uapi/linux/udp.h>
#include <uapi/linux/virtio_net.h>

static inline int virtio_net_hdr_set_proto(struct sk_buff *skb,
					   const struct virtio_net_hdr *hdr)
{
	switch (hdr->gso_type & ~VIRTIO_NET_HDR_GSO_ECN) {
	case VIRTIO_NET_HDR_GSO_TCPV4:
	case VIRTIO_NET_HDR_GSO_UDP:
		skb->protocol = cpu_to_be16(ETH_P_IP);
		break;
	case VIRTIO_NET_HDR_GSO_TCPV6:
		skb->protocol = cpu_to_be16(ETH_P_IPV6);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static inline int virtio_net_hdr_to_skb(struct sk_buff *skb,
					const struct virtio_net_hdr *hdr,
					bool little_endian)
{
	unsigned int gso_type = 0;
	unsigned int thlen = 0;
	unsigned int p_off = 0;
	unsigned int ip_proto;

	if (hdr->gso_type != VIRTIO_NET_HDR_GSO_NONE) {
		switch (hdr->gso_type & ~VIRTIO_NET_HDR_GSO_ECN) {
		case VIRTIO_NET_HDR_GSO_TCPV4:
			gso_type = SKB_GSO_TCPV4;
			ip_proto = IPPROTO_TCP;
			thlen = sizeof(struct tcphdr);
			break;
		case VIRTIO_NET_HDR_GSO_TCPV6:
			gso_type = SKB_GSO_TCPV6;
			ip_proto = IPPROTO_TCP;
			thlen = sizeof(struct tcphdr);
			break;
		case VIRTIO_NET_HDR_GSO_UDP:
			gso_type = SKB_GSO_UDP;
			ip_proto = IPPROTO_UDP;
			thlen = sizeof(struct udphdr);
			break;
		default:
			return -EINVAL;
		}

		if (hdr->gso_type & VIRTIO_NET_HDR_GSO_ECN)
			gso_type |= SKB_GSO_TCP_ECN;

		if (hdr->gso_size == 0)
			return -EINVAL;
	}

	if (hdr->flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) {
		u16 start = __virtio16_to_cpu(little_endian, hdr->csum_start);
		u16 off = __virtio16_to_cpu(little_endian, hdr->csum_offset);

		if (!skb_partial_csum_set(skb, start, off))
			return -EINVAL;

		p_off = skb_transport_offset(skb) + thlen;
		if (p_off > skb_headlen(skb))
			return -EINVAL;
	} else {
		
		if (gso_type && skb->network_header) {
			struct flow_keys_basic keys;

			if (!skb->protocol)
				virtio_net_hdr_set_proto(skb, hdr);
retry:
			if (!skb_flow_dissect_flow_keys_basic(skb, &keys,
							      NULL, 0, 0, 0,
							      0)) {
				
				if (gso_type & SKB_GSO_UDP &&
				    skb->protocol == htons(ETH_P_IP)) {
					skb->protocol = htons(ETH_P_IPV6);
					goto retry;
				}
				return -EINVAL;
			}

			p_off = keys.control.thoff + thlen;
			if (p_off > skb_headlen(skb) ||
			    keys.basic.ip_proto != ip_proto)
				return -EINVAL;

			skb_set_transport_header(skb, keys.control.thoff);
		} else if (gso_type) {
			p_off = thlen;
			if (p_off > skb_headlen(skb))
				return -EINVAL;
		}
	}

	if (hdr->gso_type != VIRTIO_NET_HDR_GSO_NONE) {
		u16 gso_size = __virtio16_to_cpu(little_endian, hdr->gso_size);
		struct skb_shared_info *shinfo = skb_shinfo(skb);

		
		if (skb->len - p_off > gso_size) {
			shinfo->gso_size = gso_size;
			shinfo->gso_type = gso_type;

			
			shinfo->gso_type |= SKB_GSO_DODGY;
			shinfo->gso_segs = 0;
		}
	}

	return 0;
}

static inline int virtio_net_hdr_from_skb(const struct sk_buff *skb,
					  struct virtio_net_hdr *hdr,
					  bool little_endian,
					  bool has_data_valid,
					  int vlan_hlen)
{
	memset(hdr, 0, sizeof(*hdr));   

	if (skb_is_gso(skb)) {
		struct skb_shared_info *sinfo = skb_shinfo(skb);

		
		hdr->hdr_len = __cpu_to_virtio16(little_endian,
						 skb_headlen(skb));
		hdr->gso_size = __cpu_to_virtio16(little_endian,
						  sinfo->gso_size);
		if (sinfo->gso_type & SKB_GSO_TCPV4)
			hdr->gso_type = VIRTIO_NET_HDR_GSO_TCPV4;
		else if (sinfo->gso_type & SKB_GSO_TCPV6)
			hdr->gso_type = VIRTIO_NET_HDR_GSO_TCPV6;
		else
			return -EINVAL;
		if (sinfo->gso_type & SKB_GSO_TCP_ECN)
			hdr->gso_type |= VIRTIO_NET_HDR_GSO_ECN;
	} else
		hdr->gso_type = VIRTIO_NET_HDR_GSO_NONE;

	if (skb->ip_summed == CHECKSUM_PARTIAL) {
		hdr->flags = VIRTIO_NET_HDR_F_NEEDS_CSUM;
		hdr->csum_start = __cpu_to_virtio16(little_endian,
			skb_checksum_start_offset(skb) + vlan_hlen);
		hdr->csum_offset = __cpu_to_virtio16(little_endian,
				skb->csum_offset);
	} else if (has_data_valid &&
		   skb->ip_summed == CHECKSUM_UNNECESSARY) {
		hdr->flags = VIRTIO_NET_HDR_F_DATA_VALID;
	} 

	return 0;
}

#endif 
