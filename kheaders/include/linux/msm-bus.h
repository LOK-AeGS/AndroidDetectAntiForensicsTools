/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _ARCH_ARM_MACH_MSM_BUS_H
#define _ARCH_ARM_MACH_MSM_BUS_H

#include <linux/types.h>
#include <linux/input.h>
#include <linux/platform_device.h>
#include <soc/qcom/tcs.h>


#define IB_RECURRBLOCK(Ws, Bs) ((Ws) == 0 ? 0 : ((Bs)/(Ws)))
#define AB_RECURRBLOCK(Ws, Per) ((Ws) == 0 ? 0 : ((Bs)/(Per)))
#define IB_THROUGHPUTBW(Tb) (Tb)
#define AB_THROUGHPUTBW(Tb, R) ((Tb) * (R))
#define MSM_BUS_MAX_TCS_CMDS 16

struct msm_bus_vectors {
	int src; 
	int dst; 
	uint64_t ab; 
	uint64_t ib; 
};

struct msm_bus_paths {
	int num_paths;
	struct msm_bus_vectors *vectors;
};

struct msm_bus_lat_vectors {
	uint64_t fal_ns; 
	uint64_t idle_t_ns; 
};

struct msm_bus_scale_pdata {
	struct msm_bus_paths *usecase;
	struct msm_bus_lat_vectors *usecase_lat;
	int num_usecases;
	const char *name;
	
	unsigned int active_only;
	
	unsigned int alc;
};

struct msm_bus_client_handle {
	char *name;
	int mas;
	int slv;
	int first_hop;
	struct device *mas_dev;
	u64 cur_act_ib;
	u64 cur_act_ab;
	u64 cur_dual_ib;
	u64 cur_dual_ab;
	bool active_only;
};

struct msm_bus_tcs_usecase {
	int num_cmds;
	struct tcs_cmd cmds[MSM_BUS_MAX_TCS_CMDS];
};

struct msm_bus_tcs_handle {
	int num_usecases;
	struct msm_bus_tcs_usecase *usecases;
};





#if (defined(CONFIG_QCOM_BUS_SCALING) ||\
	defined(CONFIG_QCOM_BUS_TOPOLOGY_ADHOC))
int __init msm_bus_fabric_init_driver(void);
uint32_t msm_bus_scale_register_client(struct msm_bus_scale_pdata *pdata);
int msm_bus_scale_client_update_request(uint32_t cl, unsigned int index);
void msm_bus_scale_unregister_client(uint32_t cl);
int msm_bus_scale_client_update_context(uint32_t cl, bool active_only,
							unsigned int ctx_idx);

struct msm_bus_client_handle*
msm_bus_scale_register(uint32_t mas, uint32_t slv, char *name,
							bool active_only);
void msm_bus_scale_unregister(struct msm_bus_client_handle *cl);
int msm_bus_scale_update_bw(struct msm_bus_client_handle *cl, u64 ab, u64 ib);
int msm_bus_scale_update_bw_context(struct msm_bus_client_handle *cl,
		u64 act_ab, u64 act_ib, u64 dual_ib, u64 dual_ab);
int msm_bus_scale_query_tcs_cmd(struct msm_bus_tcs_usecase *tcs_usecase,
					uint32_t cl, unsigned int index);
int msm_bus_scale_query_tcs_cmd_all(struct msm_bus_tcs_handle *tcs_handle,
					uint32_t cl);


int msm_bus_axi_porthalt(int master_port);
int msm_bus_axi_portunhalt(int master_port);

#else
static inline int __init msm_bus_fabric_init_driver(void) { return 0; }
static struct msm_bus_client_handle dummy_cl;

static inline uint32_t
msm_bus_scale_register_client(struct msm_bus_scale_pdata *pdata)
{
	return 1;
}

static inline int
msm_bus_scale_client_update_request(uint32_t cl, unsigned int index)
{
	return 0;
}

static inline int
msm_bus_scale_client_update_context(uint32_t cl, bool active_only,
							unsigned int ctx_idx)
{
	return 0;
}

static inline void
msm_bus_scale_unregister_client(uint32_t cl)
{
}

static inline int msm_bus_axi_porthalt(int master_port)
{
	return 0;
}

static inline int msm_bus_axi_portunhalt(int master_port)
{
	return 0;
}

static inline struct msm_bus_client_handle*
msm_bus_scale_register(uint32_t mas, uint32_t slv, char *name,
							bool active_only)
{
	return &dummy_cl;
}

static inline void msm_bus_scale_unregister(struct msm_bus_client_handle *cl)
{
}

static inline int
msm_bus_scale_update_bw(struct msm_bus_client_handle *cl, u64 ab, u64 ib)
{
	return 0;
}

static inline int
msm_bus_scale_update_bw_context(struct msm_bus_client_handle *cl, u64 act_ab,
				u64 act_ib, u64 dual_ib, u64 dual_ab)

{
	return 0;
}

static inline int msm_bus_scale_query_tcs_cmd(struct msm_bus_tcs_usecase
						*tcs_usecase, uint32_t cl,
						unsigned int index)
{
	return 0;
}

static inline int msm_bus_scale_query_tcs_cmd_all(struct msm_bus_tcs_handle
						*tcs_handle, uint32_t cl)
{
	return 0;
}

#endif

#if defined(CONFIG_OF) && defined(CONFIG_QCOM_BUS_SCALING)
struct msm_bus_scale_pdata *msm_bus_pdata_from_node(
		struct platform_device *pdev, struct device_node *of_node);
struct msm_bus_scale_pdata *msm_bus_cl_get_pdata(struct platform_device *pdev);
struct msm_bus_scale_pdata *msm_bus_cl_get_pdata_from_dev(struct device *dev);
#else
static inline struct msm_bus_scale_pdata
*msm_bus_cl_get_pdata(struct platform_device *pdev)
{
	return NULL;
}

static inline struct msm_bus_scale_pdata
*msm_bus_cl_get_pdata_from_dev(struct device *dev)
{
	return NULL;
}

static inline struct msm_bus_scale_pdata *msm_bus_pdata_from_node(
		struct platform_device *pdev, struct device_node *of_node)
{
	return NULL;
}
#endif

static inline void msm_bus_cl_clear_pdata(struct msm_bus_scale_pdata *pdata)
{
}

#ifdef CONFIG_DEBUG_BUS_VOTER
int msm_bus_floor_vote_context(const char *name, u64 floor_hz,
						bool active_only);
int msm_bus_floor_vote(const char *name, u64 floor_hz);
#else
static inline int msm_bus_floor_vote(const char *name, u64 floor_hz)
{
	return -EINVAL;
}

static inline int msm_bus_floor_vote_context(const char *name, u64 floor_hz,
						bool active_only)
{
	return -EINVAL;
}
#endif 
#endif 
