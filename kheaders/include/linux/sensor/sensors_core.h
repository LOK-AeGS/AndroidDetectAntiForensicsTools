

#ifndef _SENSORS_CORE_H_
#define _SENSORS_CORE_H_

#define TAG ""

#define SENSOR_ERR(fmt, ...) pr_err("[SENSOR]%s %s: "fmt, TAG, __func__, ##__VA_ARGS__)
#define SENSOR_INFO(fmt, ...) pr_info("[SENSOR]%s %s: "fmt, TAG, __func__, ##__VA_ARGS__)
#define SENSOR_WARN(fmt, ...) pr_warn("[SENSOR]%s %s: "fmt, TAG, __func__, ##__VA_ARGS__)

int sensors_create_symlink(struct kobject *, const char *);
void sensors_remove_symlink(struct kobject *, const char *);
int sensors_register(struct device **, void *,
	struct device_attribute *[], char *);
void sensors_unregister(struct device *, struct device_attribute *[]);
void destroy_sensor_class(void);
void remap_sensor_data(s16 *, u32);
void remap_sensor_data_32(int *, u32);

#define TIME_LO_MASK 0x00000000FFFFFFFF
#define TIME_HI_MASK 0xFFFFFFFF00000000
#define TIME_HI_SHIFT 32
#include <linux/alarmtimer.h>

extern int sensordump_notifier_register(struct notifier_block *nb);
extern int sensordump_notifier_unregister(struct notifier_block *nb);
extern int sensordump_notifier_call_chain(unsigned long val, void *v);
#if IS_ENABLED(CONFIG_SUPPORT_SENSOR_FOLD)
extern int sensorfold_notifier_register(struct notifier_block *nb);
extern int sensorfold_notifier_unregister(struct notifier_block *nb);
extern int sensorfold_notifier_notify(unsigned long fold_state);
#endif
#endif
