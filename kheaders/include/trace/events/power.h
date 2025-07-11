/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM power

#if !defined(_TRACE_POWER_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_POWER_H

#include <linux/cpufreq.h>
#include <linux/ktime.h>
#include <linux/pm_qos.h>
#include <linux/tracepoint.h>
#include <linux/trace_events.h>

#define TPS(x)  tracepoint_string(x)

DECLARE_EVENT_CLASS(cpu,

	TP_PROTO(unsigned int state, unsigned int cpu_id),

	TP_ARGS(state, cpu_id),

	TP_STRUCT__entry(
		__field(	u32,		state		)
		__field(	u32,		cpu_id		)
	),

	TP_fast_assign(
		__entry->state = state;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("state=%lu cpu_id=%lu", (unsigned long)__entry->state,
		  (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(cpu, cpu_idle,

	TP_PROTO(unsigned int state, unsigned int cpu_id),

	TP_ARGS(state, cpu_id)
);

TRACE_EVENT(powernv_throttle,

	TP_PROTO(int chip_id, const char *reason, int pmax),

	TP_ARGS(chip_id, reason, pmax),

	TP_STRUCT__entry(
		__field(int, chip_id)
		__string(reason, reason)
		__field(int, pmax)
	),

	TP_fast_assign(
		__entry->chip_id = chip_id;
		__assign_str(reason, reason);
		__entry->pmax = pmax;
	),

	TP_printk("Chip %d Pmax %d %s", __entry->chip_id,
		  __entry->pmax, __get_str(reason))
);

TRACE_EVENT(pstate_sample,

	TP_PROTO(u32 core_busy,
		u32 scaled_busy,
		u32 from,
		u32 to,
		u64 mperf,
		u64 aperf,
		u64 tsc,
		u32 freq,
		u32 io_boost
		),

	TP_ARGS(core_busy,
		scaled_busy,
		from,
		to,
		mperf,
		aperf,
		tsc,
		freq,
		io_boost
		),

	TP_STRUCT__entry(
		__field(u32, core_busy)
		__field(u32, scaled_busy)
		__field(u32, from)
		__field(u32, to)
		__field(u64, mperf)
		__field(u64, aperf)
		__field(u64, tsc)
		__field(u32, freq)
		__field(u32, io_boost)
		),

	TP_fast_assign(
		__entry->core_busy = core_busy;
		__entry->scaled_busy = scaled_busy;
		__entry->from = from;
		__entry->to = to;
		__entry->mperf = mperf;
		__entry->aperf = aperf;
		__entry->tsc = tsc;
		__entry->freq = freq;
		__entry->io_boost = io_boost;
		),

	TP_printk("core_busy=%lu scaled=%lu from=%lu to=%lu mperf=%llu aperf=%llu tsc=%llu freq=%lu io_boost=%lu",
		(unsigned long)__entry->core_busy,
		(unsigned long)__entry->scaled_busy,
		(unsigned long)__entry->from,
		(unsigned long)__entry->to,
		(unsigned long long)__entry->mperf,
		(unsigned long long)__entry->aperf,
		(unsigned long long)__entry->tsc,
		(unsigned long)__entry->freq,
		(unsigned long)__entry->io_boost
		)

);


#ifndef _PWR_EVENT_AVOID_DOUBLE_DEFINING
#define _PWR_EVENT_AVOID_DOUBLE_DEFINING

#define PWR_EVENT_EXIT -1
#endif

#define pm_verb_symbolic(event) \
	__print_symbolic(event, \
		{ PM_EVENT_SUSPEND, "suspend" }, \
		{ PM_EVENT_RESUME, "resume" }, \
		{ PM_EVENT_FREEZE, "freeze" }, \
		{ PM_EVENT_QUIESCE, "quiesce" }, \
		{ PM_EVENT_HIBERNATE, "hibernate" }, \
		{ PM_EVENT_THAW, "thaw" }, \
		{ PM_EVENT_RESTORE, "restore" }, \
		{ PM_EVENT_RECOVER, "recover" })

DEFINE_EVENT(cpu, cpu_frequency,

	TP_PROTO(unsigned int frequency, unsigned int cpu_id),

	TP_ARGS(frequency, cpu_id)
);

TRACE_EVENT(cpu_frequency_limits,

	TP_PROTO(struct cpufreq_policy *policy),

	TP_ARGS(policy),

	TP_STRUCT__entry(
		__field(u32, min_freq)
		__field(u32, max_freq)
		__field(u32, cpu_id)
	),

	TP_fast_assign(
		__entry->min_freq = policy->min;
		__entry->max_freq = policy->max;
		__entry->cpu_id = policy->cpu;
	),

	TP_printk("min=%lu max=%lu cpu_id=%lu",
		  (unsigned long)__entry->min_freq,
		  (unsigned long)__entry->max_freq,
		  (unsigned long)__entry->cpu_id)
);

TRACE_EVENT(cpu_frequency_switch_start,

	TP_PROTO(unsigned int start_freq, unsigned int end_freq,
		 unsigned int cpu_id),

	TP_ARGS(start_freq, end_freq, cpu_id),

	TP_STRUCT__entry(
		__field(u32, start_freq)
		__field(u32, end_freq)
		__field(u32, cpu_id)
	),

	TP_fast_assign(
		__entry->start_freq = start_freq;
		__entry->end_freq = end_freq;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("start=%lu end=%lu cpu_id=%lu",
		  (unsigned long)__entry->start_freq,
		  (unsigned long)__entry->end_freq,
		  (unsigned long)__entry->cpu_id)
);

TRACE_EVENT(cpu_frequency_switch_end,

	TP_PROTO(unsigned int cpu_id),

	TP_ARGS(cpu_id),

	TP_STRUCT__entry(
		__field(u32, cpu_id)
	),

	TP_fast_assign(
		__entry->cpu_id = cpu_id;
	),

	TP_printk("cpu_id=%lu", (unsigned long)__entry->cpu_id)
);

TRACE_EVENT(device_pm_callback_start,

	TP_PROTO(struct device *dev, const char *pm_ops, int event),

	TP_ARGS(dev, pm_ops, event),

	TP_STRUCT__entry(
		__string(device, dev_name(dev))
		__string(driver, dev_driver_string(dev))
		__string(parent, dev->parent ? dev_name(dev->parent) : "none")
		__string(pm_ops, pm_ops ? pm_ops : "none ")
		__field(int, event)
	),

	TP_fast_assign(
		__assign_str(device, dev_name(dev));
		__assign_str(driver, dev_driver_string(dev));
		__assign_str(parent,
			dev->parent ? dev_name(dev->parent) : "none");
		__assign_str(pm_ops, pm_ops ? pm_ops : "none ");
		__entry->event = event;
	),

	TP_printk("%s %s, parent: %s, %s[%s]", __get_str(driver),
		__get_str(device), __get_str(parent), __get_str(pm_ops),
		pm_verb_symbolic(__entry->event))
);

TRACE_EVENT(device_pm_callback_end,

	TP_PROTO(struct device *dev, int error),

	TP_ARGS(dev, error),

	TP_STRUCT__entry(
		__string(device, dev_name(dev))
		__string(driver, dev_driver_string(dev))
		__field(int, error)
	),

	TP_fast_assign(
		__assign_str(device, dev_name(dev));
		__assign_str(driver, dev_driver_string(dev));
		__entry->error = error;
	),

	TP_printk("%s %s, err=%d",
		__get_str(driver), __get_str(device), __entry->error)
);

TRACE_EVENT(suspend_resume,

	TP_PROTO(const char *action, int val, bool start),

	TP_ARGS(action, val, start),

	TP_STRUCT__entry(
		__field(const char *, action)
		__field(int, val)
		__field(bool, start)
	),

	TP_fast_assign(
		__entry->action = action;
		__entry->val = val;
		__entry->start = start;
	),

	TP_printk("%s[%u] %s", __entry->action, (unsigned int)__entry->val,
		(__entry->start)?"begin":"end")
);

DECLARE_EVENT_CLASS(wakeup_source,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
	),

	TP_printk("%s state=0x%lx", __get_str(name),
		(unsigned long)__entry->state)
);

DEFINE_EVENT(wakeup_source, wakeup_source_activate,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state)
);

DEFINE_EVENT(wakeup_source, wakeup_source_deactivate,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state)
);


DECLARE_EVENT_CLASS(clock,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
		__field(        u64,            cpu_id          )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("%s state=%lu cpu_id=%lu", __get_str(name),
		(unsigned long)__entry->state, (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(clock, clock_enable,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

DEFINE_EVENT(clock, clock_disable,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

DEFINE_EVENT(clock, clock_set_rate,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);


DECLARE_EVENT_CLASS(power_domain,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
		__field(        u64,            cpu_id          )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
		__entry->cpu_id = cpu_id;
),

	TP_printk("%s state=%lu cpu_id=%lu", __get_str(name),
		(unsigned long)__entry->state, (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(power_domain, power_domain_target,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);


DECLARE_EVENT_CLASS(pm_qos_request,

	TP_PROTO(int pm_qos_class, s32 value),

	TP_ARGS(pm_qos_class, value),

	TP_STRUCT__entry(
		__field( int,                    pm_qos_class   )
		__field( s32,                    value          )
	),

	TP_fast_assign(
		__entry->pm_qos_class = pm_qos_class;
		__entry->value = value;
	),

	TP_printk("pm_qos_class=%s value=%d",
		  __print_symbolic(__entry->pm_qos_class,
			{ PM_QOS_CPU_DMA_LATENCY,	"CPU_DMA_LATENCY" },
			{ PM_QOS_NETWORK_LATENCY,	"NETWORK_LATENCY" },
			{ PM_QOS_NETWORK_THROUGHPUT,	"NETWORK_THROUGHPUT" }),
		  __entry->value)
);

DEFINE_EVENT(pm_qos_request, pm_qos_add_request,

	TP_PROTO(int pm_qos_class, s32 value),

	TP_ARGS(pm_qos_class, value)
);

DEFINE_EVENT(pm_qos_request, pm_qos_update_request,

	TP_PROTO(int pm_qos_class, s32 value),

	TP_ARGS(pm_qos_class, value)
);

DEFINE_EVENT(pm_qos_request, pm_qos_remove_request,

	TP_PROTO(int pm_qos_class, s32 value),

	TP_ARGS(pm_qos_class, value)
);

TRACE_EVENT(pm_qos_update_request_timeout,

	TP_PROTO(int pm_qos_class, s32 value, unsigned long timeout_us),

	TP_ARGS(pm_qos_class, value, timeout_us),

	TP_STRUCT__entry(
		__field( int,                    pm_qos_class   )
		__field( s32,                    value          )
		__field( unsigned long,          timeout_us     )
	),

	TP_fast_assign(
		__entry->pm_qos_class = pm_qos_class;
		__entry->value = value;
		__entry->timeout_us = timeout_us;
	),

	TP_printk("pm_qos_class=%s value=%d, timeout_us=%ld",
		  __print_symbolic(__entry->pm_qos_class,
			{ PM_QOS_CPU_DMA_LATENCY,	"CPU_DMA_LATENCY" },
			{ PM_QOS_NETWORK_LATENCY,	"NETWORK_LATENCY" },
			{ PM_QOS_NETWORK_THROUGHPUT,	"NETWORK_THROUGHPUT" }),
		  __entry->value, __entry->timeout_us)
);

DECLARE_EVENT_CLASS(pm_qos_update,

	TP_PROTO(enum pm_qos_req_action action, int prev_value, int curr_value),

	TP_ARGS(action, prev_value, curr_value),

	TP_STRUCT__entry(
		__field( enum pm_qos_req_action, action         )
		__field( int,                    prev_value     )
		__field( int,                    curr_value     )
	),

	TP_fast_assign(
		__entry->action = action;
		__entry->prev_value = prev_value;
		__entry->curr_value = curr_value;
	),

	TP_printk("action=%s prev_value=%d curr_value=%d",
		  __print_symbolic(__entry->action,
			{ PM_QOS_ADD_REQ,	"ADD_REQ" },
			{ PM_QOS_UPDATE_REQ,	"UPDATE_REQ" },
			{ PM_QOS_REMOVE_REQ,	"REMOVE_REQ" }),
		  __entry->prev_value, __entry->curr_value)
);

DEFINE_EVENT(pm_qos_update, pm_qos_update_target,

	TP_PROTO(enum pm_qos_req_action action, int prev_value, int curr_value),

	TP_ARGS(action, prev_value, curr_value)
);

DEFINE_EVENT_PRINT(pm_qos_update, pm_qos_update_flags,

	TP_PROTO(enum pm_qos_req_action action, int prev_value, int curr_value),

	TP_ARGS(action, prev_value, curr_value),

	TP_printk("action=%s prev_value=0x%x curr_value=0x%x",
		  __print_symbolic(__entry->action,
			{ PM_QOS_ADD_REQ,	"ADD_REQ" },
			{ PM_QOS_UPDATE_REQ,	"UPDATE_REQ" },
			{ PM_QOS_REMOVE_REQ,	"REMOVE_REQ" }),
		  __entry->prev_value, __entry->curr_value)
);

DECLARE_EVENT_CLASS(dev_pm_qos_request,

	TP_PROTO(const char *name, enum dev_pm_qos_req_type type,
		 s32 new_value),

	TP_ARGS(name, type, new_value),

	TP_STRUCT__entry(
		__string( name,                    name         )
		__field( enum dev_pm_qos_req_type, type         )
		__field( s32,                      new_value    )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->type = type;
		__entry->new_value = new_value;
	),

	TP_printk("device=%s type=%s new_value=%d",
		  __get_str(name),
		  __print_symbolic(__entry->type,
			{ DEV_PM_QOS_RESUME_LATENCY, "DEV_PM_QOS_RESUME_LATENCY" },
			{ DEV_PM_QOS_FLAGS, "DEV_PM_QOS_FLAGS" }),
		  __entry->new_value)
);

DEFINE_EVENT(dev_pm_qos_request, dev_pm_qos_add_request,

	TP_PROTO(const char *name, enum dev_pm_qos_req_type type,
		 s32 new_value),

	TP_ARGS(name, type, new_value)
);

DEFINE_EVENT(dev_pm_qos_request, dev_pm_qos_update_request,

	TP_PROTO(const char *name, enum dev_pm_qos_req_type type,
		 s32 new_value),

	TP_ARGS(name, type, new_value)
);

DEFINE_EVENT(dev_pm_qos_request, dev_pm_qos_remove_request,

	TP_PROTO(const char *name, enum dev_pm_qos_req_type type,
		 s32 new_value),

	TP_ARGS(name, type, new_value)
);

TRACE_EVENT(sugov_util_update,
	    TP_PROTO(int cpu,
		     unsigned long util, unsigned long avg_cap,
		     unsigned long max_cap, unsigned long nl, unsigned long pl,
		     unsigned int rtgb, unsigned int flags),
	    TP_ARGS(cpu, util, avg_cap, max_cap, nl, pl, rtgb, flags),
	    TP_STRUCT__entry(
		    __field(int, cpu)
		    __field(unsigned long, util)
		    __field(unsigned long, avg_cap)
		    __field(unsigned long, max_cap)
		    __field(unsigned long, nl)
		    __field(unsigned long, pl)
		    __field(unsigned int, rtgb)
		    __field(unsigned int, flags)
	    ),
	    TP_fast_assign(
		    __entry->cpu = cpu;
		    __entry->util = util;
		    __entry->avg_cap = avg_cap;
		    __entry->max_cap = max_cap;
		    __entry->nl = nl;
		    __entry->pl = pl;
		    __entry->rtgb = rtgb;
		    __entry->flags = flags;
	    ),
	    TP_printk("cpu=%d util=%lu avg_cap=%lu max_cap=%lu nl=%lu pl=%lu rtgb=%u flags=0x%x",
		      __entry->cpu, __entry->util, __entry->avg_cap,
		      __entry->max_cap, __entry->nl,
		      __entry->pl, __entry->rtgb, __entry->flags)
);

TRACE_EVENT(sugov_next_freq,
	    TP_PROTO(unsigned int cpu, unsigned long util, unsigned long max,
		     unsigned int freq),
	    TP_ARGS(cpu, util, max, freq),
	    TP_STRUCT__entry(
		    __field(unsigned int, cpu)
		    __field(unsigned long, util)
		    __field(unsigned long, max)
		    __field(unsigned int, freq)
	    ),
	    TP_fast_assign(
		    __entry->cpu = cpu;
		    __entry->util = util;
		    __entry->max = max;
		    __entry->freq = freq;
	    ),
	    TP_printk("cpu=%u util=%lu max=%lu freq=%u",
		      __entry->cpu,
		      __entry->util,
		      __entry->max,
		      __entry->freq)
);

TRACE_EVENT(bw_hwmon_meas,

	TP_PROTO(const char *name, unsigned long mbps,
		 unsigned long us, int wake),

	TP_ARGS(name, mbps, us, wake),

	TP_STRUCT__entry(
		__string(name,			name)
		__field(unsigned long,		mbps)
		__field(unsigned long,		us)
		__field(int,			wake)
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->mbps = mbps;
		__entry->us = us;
		__entry->wake = wake;
	),

	TP_printk("dev: %s, mbps = %lu, us = %lu, wake = %d",
		__get_str(name),
		__entry->mbps,
		__entry->us,
		__entry->wake)
);

TRACE_EVENT(bw_hwmon_update,

	TP_PROTO(const char *name, unsigned long mbps, unsigned long freq,
		 unsigned long up_thres, unsigned long down_thres),

	TP_ARGS(name, mbps, freq, up_thres, down_thres),

	TP_STRUCT__entry(
		__string(name,			name)
		__field(unsigned long,		mbps)
		__field(unsigned long,		freq)
		__field(unsigned long,		up_thres)
		__field(unsigned long,		down_thres)
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->mbps = mbps;
		__entry->freq = freq;
		__entry->up_thres = up_thres;
		__entry->down_thres = down_thres;
	),

	TP_printk("dev: %s, mbps = %lu, freq = %lu, up = %lu, down = %lu",
		__get_str(name),
		__entry->mbps,
		__entry->freq,
		__entry->up_thres,
		__entry->down_thres)
);

TRACE_EVENT(cache_hwmon_meas,
	TP_PROTO(const char *name, unsigned long high_mrps,
		 unsigned long med_mrps, unsigned long low_mrps,
		 unsigned int busy_percent, unsigned int us),
	TP_ARGS(name, high_mrps, med_mrps, low_mrps, busy_percent, us),
	TP_STRUCT__entry(
		__string(name, name)
		__field(unsigned long, high_mrps)
		__field(unsigned long, med_mrps)
		__field(unsigned long, low_mrps)
		__field(unsigned long, total_mrps)
		__field(unsigned int, busy_percent)
		__field(unsigned int, us)
	),
	TP_fast_assign(
		__assign_str(name, name);
		__entry->high_mrps = high_mrps;
		__entry->med_mrps = med_mrps;
		__entry->low_mrps = low_mrps;
		__entry->total_mrps = high_mrps + med_mrps + low_mrps;
		__entry->busy_percent = busy_percent;
		__entry->us = us;
	),
	TP_printk("dev=%s H=%lu M=%lu L=%lu T=%lu busy_pct=%u period=%u",
		  __get_str(name), __entry->high_mrps, __entry->med_mrps,
		  __entry->low_mrps, __entry->total_mrps,
		  __entry->busy_percent, __entry->us)
);

TRACE_EVENT(cache_hwmon_update,
	TP_PROTO(const char *name, unsigned long freq_mhz),
	TP_ARGS(name, freq_mhz),
	TP_STRUCT__entry(
		__string(name, name)
		__field(unsigned long, freq)
	),
	TP_fast_assign(
		__assign_str(name, name);
		__entry->freq = freq_mhz;
	),
	TP_printk("dev=%s freq=%lu", __get_str(name), __entry->freq)
);

TRACE_EVENT(memlat_dev_meas,
	TP_PROTO(const char *name, unsigned int dev_id, unsigned long inst,
		 unsigned long mem, unsigned long freq, unsigned int stall,
		 unsigned int wb, unsigned int ratio),

	TP_ARGS(name, dev_id, inst, mem, freq, stall, wb, ratio),

	TP_STRUCT__entry(
		__string(name, name)
		__field(unsigned int, dev_id)
		__field(unsigned long, inst)
		__field(unsigned long, mem)
		__field(unsigned long, freq)
		__field(unsigned int, stall)
		__field(unsigned int, wb)
		__field(unsigned int, ratio)
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->dev_id = dev_id;
		__entry->inst = inst;
		__entry->mem = mem;
		__entry->freq = freq;
		__entry->stall = stall;
		__entry->wb = wb;
		__entry->ratio = ratio;
	),

	TP_printk("dev: %s, id=%u, inst=%lu, mem=%lu, freq=%lu, stall=%u, wb=%u, ratio=%u",
		__get_str(name),
		__entry->dev_id,
		__entry->inst,
		__entry->mem,
		__entry->freq,
		__entry->stall,
		__entry->wb,
		__entry->ratio)
);

TRACE_EVENT(memlat_dev_update,

	TP_PROTO(const char *name, unsigned int dev_id, unsigned long inst,
		 unsigned long mem, unsigned long freq, unsigned long vote),

	TP_ARGS(name, dev_id, inst, mem, freq, vote),

	TP_STRUCT__entry(
		__string(name, name)
		__field(unsigned int, dev_id)
		__field(unsigned long, inst)
		__field(unsigned long, mem)
		__field(unsigned long, freq)
		__field(unsigned long, vote)
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->dev_id = dev_id;
		__entry->inst = inst;
		__entry->mem = mem;
		__entry->freq = freq;
		__entry->vote = vote;
	),

	TP_printk("dev: %s, id=%u, inst=%lu, mem=%lu, freq=%lu, vote=%lu",
		__get_str(name),
		__entry->dev_id,
		__entry->inst,
		__entry->mem,
		__entry->freq,
		__entry->vote)
);

#endif 


#include <trace/define_trace.h>
