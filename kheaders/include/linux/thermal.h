/* SPDX-License-Identifier: GPL-2.0 */


#ifndef __THERMAL_H__
#define __THERMAL_H__

#include <linux/of.h>
#include <linux/idr.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/workqueue.h>
#include <uapi/linux/thermal.h>

#define THERMAL_TRIPS_NONE	-1
#define THERMAL_MAX_TRIPS	12


#define THERMAL_CSTATE_INVALID -1UL


#define THERMAL_NO_LIMIT	((u32)~0)


#define THERMAL_MAX_LIMIT	(THERMAL_NO_LIMIT - 1)


#define THERMAL_WEIGHT_DEFAULT 0


#define THERMAL_MAX_VIRT_SENSORS 10


#define THERMAL_TEMP_INVALID	-274000


#define THERMAL_TEMP_INVALID_LOW 274000


#define DECI_KELVIN_TO_CELSIUS(t)	({			\
	long _t = (t);						\
	((_t-2732 >= 0) ? (_t-2732+5)/10 : (_t-2732-5)/10);	\
})
#define CELSIUS_TO_DECI_KELVIN(t)	((t)*10+2732)
#define DECI_KELVIN_TO_MILLICELSIUS_WITH_OFFSET(t, off) (((t) - (off)) * 100)
#define DECI_KELVIN_TO_MILLICELSIUS(t) DECI_KELVIN_TO_MILLICELSIUS_WITH_OFFSET(t, 2732)
#define MILLICELSIUS_TO_DECI_KELVIN_WITH_OFFSET(t, off) (((t) / 100) + (off))
#define MILLICELSIUS_TO_DECI_KELVIN(t) MILLICELSIUS_TO_DECI_KELVIN_WITH_OFFSET(t, 2732)


#if defined(CONFIG_THERMAL_DEFAULT_GOV_STEP_WISE)
#define DEFAULT_THERMAL_GOVERNOR       "step_wise"
#elif defined(CONFIG_THERMAL_DEFAULT_GOV_FAIR_SHARE)
#define DEFAULT_THERMAL_GOVERNOR       "fair_share"
#elif defined(CONFIG_THERMAL_DEFAULT_GOV_USER_SPACE)
#define DEFAULT_THERMAL_GOVERNOR       "user_space"
#elif defined(CONFIG_THERMAL_DEFAULT_GOV_POWER_ALLOCATOR)
#define DEFAULT_THERMAL_GOVERNOR       "power_allocator"
#endif

struct thermal_zone_device;
struct thermal_cooling_device;
struct thermal_instance;

enum thermal_device_mode {
	THERMAL_DEVICE_DISABLED = 0,
	THERMAL_DEVICE_ENABLED,
};

enum thermal_trip_type {
	THERMAL_TRIP_ACTIVE = 0,
	THERMAL_TRIP_PASSIVE,
	THERMAL_TRIP_HOT,
	THERMAL_TRIP_CRITICAL,
	THERMAL_TRIP_CONFIGURABLE_HI,
	THERMAL_TRIP_CONFIGURABLE_LOW,
	THERMAL_TRIP_CRITICAL_LOW,
};

enum thermal_trend {
	THERMAL_TREND_STABLE, 
	THERMAL_TREND_RAISING, 
	THERMAL_TREND_DROPPING, 
	THERMAL_TREND_RAISE_FULL, 
	THERMAL_TREND_DROP_FULL, 
};


enum thermal_notify_event {
	THERMAL_EVENT_UNSPECIFIED, 
	THERMAL_EVENT_TEMP_SAMPLE, 
	THERMAL_TRIP_VIOLATED, 
	THERMAL_TRIP_CHANGED, 
	THERMAL_DEVICE_DOWN, 
	THERMAL_DEVICE_UP, 
	THERMAL_DEVICE_POWER_CAPABILITY_CHANGED, 
	THERMAL_TABLE_CHANGED, 
};

struct thermal_zone_device_ops {
	int (*bind) (struct thermal_zone_device *,
		     struct thermal_cooling_device *);
	int (*unbind) (struct thermal_zone_device *,
		       struct thermal_cooling_device *);
	int (*get_temp) (struct thermal_zone_device *, int *);
	int (*set_trips) (struct thermal_zone_device *, int, int);
	int (*get_mode) (struct thermal_zone_device *,
			 enum thermal_device_mode *);
	int (*set_mode) (struct thermal_zone_device *,
		enum thermal_device_mode);
	int (*get_trip_type) (struct thermal_zone_device *, int,
		enum thermal_trip_type *);
	int (*get_trip_temp) (struct thermal_zone_device *, int, int *);
	int (*set_trip_temp) (struct thermal_zone_device *, int, int);
	int (*get_trip_hyst) (struct thermal_zone_device *, int, int *);
	int (*set_trip_hyst) (struct thermal_zone_device *, int, int);
	int (*get_crit_temp) (struct thermal_zone_device *, int *);
	int (*set_emul_temp) (struct thermal_zone_device *, int);
	int (*get_trend) (struct thermal_zone_device *, int,
			  enum thermal_trend *);
	int (*notify) (struct thermal_zone_device *, int,
		       enum thermal_trip_type);
	bool (*is_wakeable)(struct thermal_zone_device *);
	int (*set_polling_delay)(struct thermal_zone_device *, int);
	int (*set_passive_delay)(struct thermal_zone_device *, int);
};

struct thermal_cooling_device_ops {
	int (*get_max_state) (struct thermal_cooling_device *, unsigned long *);
	int (*get_cur_state) (struct thermal_cooling_device *, unsigned long *);
	int (*set_cur_state) (struct thermal_cooling_device *, unsigned long);
	int (*set_min_state)(struct thermal_cooling_device *cdev,
				unsigned long target);
	int (*get_min_state)(struct thermal_cooling_device *cdev,
				unsigned long *target);
	int (*get_requested_power)(struct thermal_cooling_device *,
				   struct thermal_zone_device *, u32 *);
	int (*state2power)(struct thermal_cooling_device *,
			   struct thermal_zone_device *, unsigned long, u32 *);
	int (*power2state)(struct thermal_cooling_device *,
			   struct thermal_zone_device *, u32, unsigned long *);
};

struct thermal_cooling_device {
	int id;
	char type[THERMAL_NAME_LENGTH];
	struct device device;
	struct device_node *np;
	void *devdata;
	void *stats;
	const struct thermal_cooling_device_ops *ops;
	bool updated; 
	struct mutex lock; 
	struct list_head thermal_instances;
	struct list_head node;
	unsigned long sysfs_cur_state_req;
	unsigned long sysfs_min_state_req;
};

struct thermal_attr {
	struct device_attribute attr;
	char name[THERMAL_NAME_LENGTH];
};


struct thermal_zone_device {
	int id;
	char type[THERMAL_NAME_LENGTH];
	struct device device;
	struct attribute_group trips_attribute_group;
	struct thermal_attr *trip_temp_attrs;
	struct thermal_attr *trip_type_attrs;
	struct thermal_attr *trip_hyst_attrs;
	void *devdata;
	int trips;
	unsigned long trips_disabled;	
	int passive_delay;
	int polling_delay;
	int temperature;
	int last_temperature;
	int emul_temperature;
	int passive;
	int prev_low_trip;
	int prev_high_trip;
	unsigned int forced_passive;
	atomic_t need_update;
	struct thermal_zone_device_ops *ops;
	struct thermal_zone_params *tzp;
	struct thermal_governor *governor;
	void *governor_data;
	struct list_head thermal_instances;
	struct ida ida;
	struct mutex lock;
	struct list_head node;
	struct delayed_work poll_queue;
	enum thermal_notify_event notify_event;
};


struct thermal_governor {
	char name[THERMAL_NAME_LENGTH];
	int (*bind_to_tz)(struct thermal_zone_device *tz);
	void (*unbind_from_tz)(struct thermal_zone_device *tz);
	int (*throttle)(struct thermal_zone_device *tz, int trip);
	struct list_head	governor_list;
	int min_state_throttle;
};


struct thermal_bind_params {
	struct thermal_cooling_device *cdev;

	
	int weight;

	
	int trip_mask;

	
	unsigned long *binding_limits;
	int (*match) (struct thermal_zone_device *tz,
			struct thermal_cooling_device *cdev);
};


struct thermal_zone_params {
	char governor_name[THERMAL_NAME_LENGTH];

	
	bool no_hwmon;

	int num_tbps;	
	struct thermal_bind_params *tbp;

	
	u32 sustainable_power;

	
	s32 k_po;

	
	s32 k_pu;

	
	s32 k_i;

	
	s32 k_d;

	
	s32 integral_cutoff;

	
	int slope;
	
	int offset;

	
	bool tracks_low;
};

struct thermal_genl_event {
	u32 orig;
	enum events event;
};


struct thermal_zone_of_device_ops {
	int (*get_temp)(void *, int *);
	int (*get_trend)(void *, int, enum thermal_trend *);
	int (*set_trips)(void *, int, int);
	int (*set_emul_temp)(void *, int);
	int (*set_trip_temp)(void *data, int trip, int temp);
	int (*get_trip_temp)(void *data, int trip, int *temp);
};



struct thermal_trip {
	struct device_node *np;
	int temperature;
	int hysteresis;
	enum thermal_trip_type type;
};


enum aggregation_logic {
	VIRT_WEIGHTED_AVG,
	VIRT_MAXIMUM,
	VIRT_MINIMUM,
	VIRT_AGGREGATION_NR,
};


struct virtual_sensor_data {
	int                    num_sensors;
	char                   virt_zone_name[THERMAL_NAME_LENGTH];
	char                   *sensor_names[THERMAL_MAX_VIRT_SENSORS];
	enum aggregation_logic logic;
	int                    coefficients[THERMAL_MAX_VIRT_SENSORS];
	int                    coefficient_ct;
	int                    avg_offset;
	int                    avg_denominator;
};


#ifdef CONFIG_THERMAL_OF
struct thermal_zone_device *
thermal_zone_of_sensor_register(struct device *dev, int id, void *data,
				const struct thermal_zone_of_device_ops *ops);
void thermal_zone_of_sensor_unregister(struct device *dev,
				       struct thermal_zone_device *tz);
struct thermal_zone_device *devm_thermal_zone_of_sensor_register(
		struct device *dev, int id, void *data,
		const struct thermal_zone_of_device_ops *ops);
void devm_thermal_zone_of_sensor_unregister(struct device *dev,
					    struct thermal_zone_device *tz);
struct thermal_zone_device *devm_thermal_of_virtual_sensor_register(
		struct device *dev,
		const struct virtual_sensor_data *sensor_data);
#else
static inline struct thermal_zone_device *
thermal_zone_of_sensor_register(struct device *dev, int id, void *data,
				const struct thermal_zone_of_device_ops *ops)
{
	return ERR_PTR(-ENODEV);
}

static inline
void thermal_zone_of_sensor_unregister(struct device *dev,
				       struct thermal_zone_device *tz)
{
}

static inline struct thermal_zone_device *devm_thermal_zone_of_sensor_register(
		struct device *dev, int id, void *data,
		const struct thermal_zone_of_device_ops *ops)
{
	return ERR_PTR(-ENODEV);
}

static inline
void devm_thermal_zone_of_sensor_unregister(struct device *dev,
					    struct thermal_zone_device *tz)
{
}

static inline
struct thermal_zone_device *devm_thermal_of_virtual_sensor_register(
		struct device *dev,
		const struct virtual_sensor_data *sensor_data)
{
	return ERR_PTR(-ENODEV);
}

#endif

#if IS_ENABLED(CONFIG_THERMAL)
static inline bool cdev_is_power_actor(struct thermal_cooling_device *cdev)
{
	return cdev->ops->get_requested_power && cdev->ops->state2power &&
		cdev->ops->power2state;
}

int power_actor_get_max_power(struct thermal_cooling_device *,
			      struct thermal_zone_device *tz, u32 *max_power);
int power_actor_get_min_power(struct thermal_cooling_device *,
			      struct thermal_zone_device *tz, u32 *min_power);
int power_actor_set_power(struct thermal_cooling_device *,
			  struct thermal_instance *, u32);
struct thermal_zone_device *thermal_zone_device_register(const char *, int, int,
		void *, struct thermal_zone_device_ops *,
		struct thermal_zone_params *, int, int);
void thermal_zone_device_unregister(struct thermal_zone_device *);

int thermal_zone_bind_cooling_device(struct thermal_zone_device *, int,
				     struct thermal_cooling_device *,
				     unsigned long, unsigned long,
				     unsigned int);
int thermal_zone_unbind_cooling_device(struct thermal_zone_device *, int,
				       struct thermal_cooling_device *);
void thermal_zone_device_update(struct thermal_zone_device *,
				enum thermal_notify_event);
void thermal_zone_device_update_temp(struct thermal_zone_device *tz,
				enum thermal_notify_event event, int temp);
void thermal_zone_set_trips(struct thermal_zone_device *);

struct thermal_cooling_device *thermal_cooling_device_register(const char *,
		void *, const struct thermal_cooling_device_ops *);
struct thermal_cooling_device *
thermal_of_cooling_device_register(struct device_node *np, const char *, void *,
				   const struct thermal_cooling_device_ops *);
void thermal_cooling_device_unregister(struct thermal_cooling_device *);
struct thermal_zone_device *thermal_zone_get_zone_by_name(const char *name);
struct thermal_cooling_device *thermal_zone_get_cdev_by_name(const char *name);
int thermal_zone_get_temp(struct thermal_zone_device *tz, int *temp);
int thermal_zone_get_slope(struct thermal_zone_device *tz);
int thermal_zone_get_offset(struct thermal_zone_device *tz);

int get_tz_trend(struct thermal_zone_device *, int);
struct thermal_instance *get_thermal_instance(struct thermal_zone_device *,
		struct thermal_cooling_device *, int);
void thermal_cdev_update(struct thermal_cooling_device *);
void thermal_notify_framework(struct thermal_zone_device *, int);
#else
static inline bool cdev_is_power_actor(struct thermal_cooling_device *cdev)
{ return false; }
static inline int power_actor_get_max_power(struct thermal_cooling_device *cdev,
			      struct thermal_zone_device *tz, u32 *max_power)
{ return 0; }
static inline int power_actor_get_min_power(struct thermal_cooling_device *cdev,
					    struct thermal_zone_device *tz,
					    u32 *min_power)
{ return -ENODEV; }
static inline int power_actor_set_power(struct thermal_cooling_device *cdev,
			  struct thermal_instance *tz, u32 power)
{ return 0; }
static inline struct thermal_zone_device *thermal_zone_device_register(
	const char *type, int trips, int mask, void *devdata,
	struct thermal_zone_device_ops *ops,
	struct thermal_zone_params *tzp,
	int passive_delay, int polling_delay)
{ return ERR_PTR(-ENODEV); }
static inline void thermal_zone_device_unregister(
	struct thermal_zone_device *tz)
{ }
static inline int thermal_zone_bind_cooling_device(
	struct thermal_zone_device *tz, int trip,
	struct thermal_cooling_device *cdev,
	unsigned long upper, unsigned long lower,
	unsigned int weight)
{ return -ENODEV; }
static inline int thermal_zone_unbind_cooling_device(
	struct thermal_zone_device *tz, int trip,
	struct thermal_cooling_device *cdev)
{ return -ENODEV; }
static inline void thermal_zone_device_update(struct thermal_zone_device *tz,
					      enum thermal_notify_event event)
{ }
static inline void thermal_zone_device_update_temp(
		struct thermal_zone_device *tz, enum thermal_notify_event event,
		int temp)
{ }
static inline void thermal_zone_set_trips(struct thermal_zone_device *tz)
{ }
static inline struct thermal_cooling_device *
thermal_cooling_device_register(char *type, void *devdata,
	const struct thermal_cooling_device_ops *ops)
{ return ERR_PTR(-ENODEV); }
static inline struct thermal_cooling_device *
thermal_of_cooling_device_register(struct device_node *np,
	char *type, void *devdata, const struct thermal_cooling_device_ops *ops)
{ return ERR_PTR(-ENODEV); }
static inline void thermal_cooling_device_unregister(
	struct thermal_cooling_device *cdev)
{ }
static inline struct thermal_zone_device *thermal_zone_get_zone_by_name(
		const char *name)
{ return ERR_PTR(-ENODEV); }
static inline struct thermal_cooling_device *thermal_zone_get_cdev_by_name(
		const char *name)
{ return ERR_PTR(-ENODEV); }
static inline int thermal_zone_get_temp(
		struct thermal_zone_device *tz, int *temp)
{ return -ENODEV; }
static inline int thermal_zone_get_slope(
		struct thermal_zone_device *tz)
{ return -ENODEV; }
static inline int thermal_zone_get_offset(
		struct thermal_zone_device *tz)
{ return -ENODEV; }
static inline int get_tz_trend(struct thermal_zone_device *tz, int trip)
{ return -ENODEV; }
static inline struct thermal_instance *
get_thermal_instance(struct thermal_zone_device *tz,
	struct thermal_cooling_device *cdev, int trip)
{ return ERR_PTR(-ENODEV); }
static inline void thermal_cdev_update(struct thermal_cooling_device *cdev)
{ }
static inline void thermal_notify_framework(struct thermal_zone_device *tz,
	int trip)
{ }
#endif 

#if defined(CONFIG_NET) && IS_ENABLED(CONFIG_THERMAL)
extern int thermal_generate_netlink_event(struct thermal_zone_device *tz,
						enum events event);
#else
static inline int thermal_generate_netlink_event(struct thermal_zone_device *tz,
						enum events event)
{
	return 0;
}
#endif

#endif 
