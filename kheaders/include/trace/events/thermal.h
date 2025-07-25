/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM thermal

#if !defined(_TRACE_THERMAL_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_THERMAL_H

#include <linux/devfreq.h>
#include <linux/thermal.h>
#include <linux/tracepoint.h>

TRACE_DEFINE_ENUM(THERMAL_TRIP_CRITICAL);
TRACE_DEFINE_ENUM(THERMAL_TRIP_HOT);
TRACE_DEFINE_ENUM(THERMAL_TRIP_PASSIVE);
TRACE_DEFINE_ENUM(THERMAL_TRIP_ACTIVE);

#define show_tzt_type(type)					\
	__print_symbolic(type,					\
			 { THERMAL_TRIP_CRITICAL, "CRITICAL"},	\
			 { THERMAL_TRIP_HOT,      "HOT"},	\
			 { THERMAL_TRIP_PASSIVE,  "PASSIVE"},	\
			 { THERMAL_TRIP_ACTIVE,   "ACTIVE"})

TRACE_EVENT(thermal_query_temp,

	TP_PROTO(struct thermal_zone_device *tz, int temp),

	TP_ARGS(tz, temp),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, temp)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->temp = temp;
	),

	TP_printk("thermal_zone=%s id=%d temp=%d",
		__get_str(thermal_zone), __entry->id,
		__entry->temp)
);

TRACE_EVENT(thermal_temperature,

	TP_PROTO(struct thermal_zone_device *tz),

	TP_ARGS(tz),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, temp_prev)
		__field(int, temp)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->temp_prev = tz->last_temperature;
		__entry->temp = tz->temperature;
	),

	TP_printk("thermal_zone=%s id=%d temp_prev=%d temp=%d",
		__get_str(thermal_zone), __entry->id, __entry->temp_prev,
		__entry->temp)
);

TRACE_EVENT(cdev_update_start,

	TP_PROTO(struct thermal_cooling_device *cdev),

	TP_ARGS(cdev),

	TP_STRUCT__entry(
		__string(type, cdev->type)
	),

	TP_fast_assign(
		__assign_str(type, cdev->type);
	),

	TP_printk("type=%s update start", __get_str(type))
);

TRACE_EVENT(cdev_update,

	TP_PROTO(struct thermal_cooling_device *cdev, unsigned long target,
		 unsigned long min_target),

	TP_ARGS(cdev, target, min_target),

	TP_STRUCT__entry(
		__string(type, cdev->type)
		__field(unsigned long, target)
		__field(unsigned long, min_target)
	),

	TP_fast_assign(
		__assign_str(type, cdev->type);
		__entry->target = target;
		__entry->min_target = min_target;
	),

	TP_printk("type=%s target=%lu min_target=%lu", __get_str(type),
				__entry->target, __entry->min_target)
);

TRACE_EVENT(thermal_zone_trip,

	TP_PROTO(struct thermal_zone_device *tz, int trip,
		enum thermal_trip_type trip_type, bool is_trip),

	TP_ARGS(tz, trip, trip_type, is_trip),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, trip)
		__field(enum thermal_trip_type, trip_type)
		__field(bool, is_trip)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->trip = trip;
		__entry->trip_type = trip_type;
		__entry->is_trip = is_trip;
	),

	TP_printk("thermal_zone=%s id=%d %s=%d trip_type=%s",
		__get_str(thermal_zone), __entry->id,
		(__entry->is_trip) ? "trip" : "hyst",
		__entry->trip,
		show_tzt_type(__entry->trip_type))
);

TRACE_EVENT(thermal_handle_trip,

	TP_PROTO(struct thermal_zone_device *tz, int trip),

	TP_ARGS(tz, trip),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, trip)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->trip = trip;
	),

	TP_printk("thermal_zone=%s id=%d handle trip=%d",
		__get_str(thermal_zone), __entry->id, __entry->trip)
);

TRACE_EVENT(thermal_device_update,

	TP_PROTO(struct thermal_zone_device *tz, int event),

	TP_ARGS(tz, event),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, event)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->event = event;
	),

	TP_printk("thermal_zone=%s id=%d received event:%d",
		__get_str(thermal_zone), __entry->id, __entry->event)
);

TRACE_EVENT(thermal_set_trip,

	TP_PROTO(struct thermal_zone_device *tz),

	TP_ARGS(tz),

	TP_STRUCT__entry(
		__string(thermal_zone, tz->type)
		__field(int, id)
		__field(int, low)
		__field(int, high)
	),

	TP_fast_assign(
		__assign_str(thermal_zone, tz->type);
		__entry->id = tz->id;
		__entry->low = tz->prev_low_trip;
		__entry->high = tz->prev_high_trip;
	),

	TP_printk("thermal_zone=%s id=%d low trip=%d high trip=%d",
		__get_str(thermal_zone), __entry->id, __entry->low,
		__entry->high)
);

#ifdef CONFIG_CPU_THERMAL
TRACE_EVENT(thermal_power_cpu_get_power,
	TP_PROTO(const struct cpumask *cpus, unsigned long freq, u32 *load,
		size_t load_len, u32 dynamic_power),

	TP_ARGS(cpus, freq, load, load_len, dynamic_power),

	TP_STRUCT__entry(
		__bitmask(cpumask, num_possible_cpus())
		__field(unsigned long, freq          )
		__dynamic_array(u32,   load, load_len)
		__field(size_t,        load_len      )
		__field(u32,           dynamic_power )
	),

	TP_fast_assign(
		__assign_bitmask(cpumask, cpumask_bits(cpus),
				num_possible_cpus());
		__entry->freq = freq;
		memcpy(__get_dynamic_array(load), load,
			load_len * sizeof(*load));
		__entry->load_len = load_len;
		__entry->dynamic_power = dynamic_power;
	),

	TP_printk("cpus=%s freq=%lu load={%s} dynamic_power=%d",
		__get_bitmask(cpumask), __entry->freq,
		__print_array(__get_dynamic_array(load), __entry->load_len, 4),
		__entry->dynamic_power)
);

TRACE_EVENT(thermal_power_cpu_limit,
	TP_PROTO(const struct cpumask *cpus, unsigned int freq,
		unsigned long cdev_state, u32 power),

	TP_ARGS(cpus, freq, cdev_state, power),

	TP_STRUCT__entry(
		__bitmask(cpumask, num_possible_cpus())
		__field(unsigned int,  freq      )
		__field(unsigned long, cdev_state)
		__field(u32,           power     )
	),

	TP_fast_assign(
		__assign_bitmask(cpumask, cpumask_bits(cpus),
				num_possible_cpus());
		__entry->freq = freq;
		__entry->cdev_state = cdev_state;
		__entry->power = power;
	),

	TP_printk("cpus=%s freq=%u cdev_state=%lu power=%u",
		__get_bitmask(cpumask), __entry->freq, __entry->cdev_state,
		__entry->power)
);
#endif 

#ifdef CONFIG_DEVFREQ_THERMAL
TRACE_EVENT(thermal_power_devfreq_get_power,
	TP_PROTO(struct thermal_cooling_device *cdev,
		 struct devfreq_dev_status *status, unsigned long freq,
		u32 dynamic_power, u32 static_power, u32 power),

	TP_ARGS(cdev, status,  freq, dynamic_power, static_power, power),

	TP_STRUCT__entry(
		__string(type,         cdev->type    )
		__field(unsigned long, freq          )
		__field(u32,           load          )
		__field(u32,           dynamic_power )
		__field(u32,           static_power  )
		__field(u32,           power)
	),

	TP_fast_assign(
		__assign_str(type, cdev->type);
		__entry->freq = freq;
		__entry->load = (100 * status->busy_time) / status->total_time;
		__entry->dynamic_power = dynamic_power;
		__entry->static_power = static_power;
		__entry->power = power;
	),

	TP_printk("type=%s freq=%lu load=%u dynamic_power=%u static_power=%u power=%u",
		__get_str(type), __entry->freq,
		__entry->load, __entry->dynamic_power, __entry->static_power,
		__entry->power)
);

TRACE_EVENT(thermal_power_devfreq_limit,
	TP_PROTO(struct thermal_cooling_device *cdev, unsigned long freq,
		unsigned long cdev_state, u32 power),

	TP_ARGS(cdev, freq, cdev_state, power),

	TP_STRUCT__entry(
		__string(type,         cdev->type)
		__field(unsigned int,  freq      )
		__field(unsigned long, cdev_state)
		__field(u32,           power     )
	),

	TP_fast_assign(
		__assign_str(type, cdev->type);
		__entry->freq = freq;
		__entry->cdev_state = cdev_state;
		__entry->power = power;
	),

	TP_printk("type=%s freq=%u cdev_state=%lu power=%u",
		__get_str(type), __entry->freq, __entry->cdev_state,
		__entry->power)
);
#endif 
#endif 


#include <trace/define_trace.h>
