

#ifndef _LINUX_GPIO_EVENT_H
#define _LINUX_GPIO_EVENT_H

#include <linux/input.h>

struct gpio_event_input_devs {
	int count;
	struct input_dev *dev[];
};
enum {
	GPIO_EVENT_FUNC_UNINIT  = 0x0,
	GPIO_EVENT_FUNC_INIT    = 0x1,
	GPIO_EVENT_FUNC_SUSPEND = 0x2,
	GPIO_EVENT_FUNC_RESUME  = 0x3,
};
struct gpio_event_info {
	int (*func)(struct gpio_event_input_devs *input_devs,
		    struct gpio_event_info *info,
		    void **data, int func);
	int (*event)(struct gpio_event_input_devs *input_devs,
		     struct gpio_event_info *info,
		     void **data, unsigned int dev, unsigned int type,
		     unsigned int code, int value); 
	bool no_suspend;
};

struct gpio_event_platform_data {
	const char *name;
	struct gpio_event_info **info;
	size_t info_count;
	int (*power)(const struct gpio_event_platform_data *pdata, bool on);
	const char *names[]; 
			     
};

#define GPIO_EVENT_DEV_NAME "gpio-event"



enum gpio_event_matrix_flags {
	
	GPIOKPF_ACTIVE_HIGH              = 1U << 0,
	GPIOKPF_DEBOUNCE                 = 1U << 1,
	GPIOKPF_REMOVE_SOME_PHANTOM_KEYS = 1U << 2,
	GPIOKPF_REMOVE_PHANTOM_KEYS      = GPIOKPF_REMOVE_SOME_PHANTOM_KEYS |
					   GPIOKPF_DEBOUNCE,
	GPIOKPF_DRIVE_INACTIVE           = 1U << 3,
	GPIOKPF_LEVEL_TRIGGERED_IRQ      = 1U << 4,
	GPIOKPF_PRINT_UNMAPPED_KEYS      = 1U << 16,
	GPIOKPF_PRINT_MAPPED_KEYS        = 1U << 17,
	GPIOKPF_PRINT_PHANTOM_KEYS       = 1U << 18,
};

#define MATRIX_CODE_BITS (10)
#define MATRIX_KEY_MASK ((1U << MATRIX_CODE_BITS) - 1)
#define MATRIX_KEY(dev, code) \
	(((dev) << MATRIX_CODE_BITS) | (code & MATRIX_KEY_MASK))

extern int gpio_event_matrix_func(struct gpio_event_input_devs *input_devs,
			struct gpio_event_info *info, void **data, int func);
struct gpio_event_matrix_info {
	
	struct gpio_event_info info;
	
	const unsigned short *keymap;
	unsigned int *input_gpios;
	unsigned int *output_gpios;
	unsigned int ninputs;
	unsigned int noutputs;
	
	ktime_t settle_time;
	
	ktime_t debounce_delay;
	ktime_t poll_time;
	unsigned flags;
};



enum gpio_event_direct_flags {
	GPIOEDF_ACTIVE_HIGH         = 1U << 0,


	GPIOEDF_PRINT_KEYS          = 1U << 8,
	GPIOEDF_PRINT_KEY_DEBOUNCE  = 1U << 9,
	GPIOEDF_PRINT_KEY_UNSTABLE  = 1U << 10,
};

struct gpio_event_direct_entry {
	uint32_t gpio:16;
	uint32_t code:10;
	uint32_t dev:6;
};


extern int gpio_event_input_func(struct gpio_event_input_devs *input_devs,
			struct gpio_event_info *info, void **data, int func);
struct gpio_event_input_info {
	
	struct gpio_event_info info;
	ktime_t debounce_time;
	ktime_t poll_time;
	uint16_t flags;
	uint16_t type;
	const struct gpio_event_direct_entry *keymap;
	size_t keymap_size;
};


extern int gpio_event_output_func(struct gpio_event_input_devs *input_devs,
			struct gpio_event_info *info, void **data, int func);
extern int gpio_event_output_event(struct gpio_event_input_devs *input_devs,
			struct gpio_event_info *info, void **data,
			unsigned int dev, unsigned int type,
			unsigned int code, int value);
struct gpio_event_output_info {
	
	struct gpio_event_info info;
	uint16_t flags;
	uint16_t type;
	const struct gpio_event_direct_entry *keymap;
	size_t keymap_size;
};




enum gpio_event_axis_flags {
	GPIOEAF_PRINT_UNKNOWN_DIRECTION  = 1U << 16,
	GPIOEAF_PRINT_RAW                = 1U << 17,
	GPIOEAF_PRINT_EVENT              = 1U << 18,
};

extern int gpio_event_axis_func(struct gpio_event_input_devs *input_devs,
			struct gpio_event_info *info, void **data, int func);
struct gpio_event_axis_info {
	
	struct gpio_event_info info;
	uint8_t  count; 
	uint8_t  dev; 
	uint8_t  type; 
	uint16_t code;
	uint16_t decoded_size;
	uint16_t (*map)(struct gpio_event_axis_info *info, uint16_t in);
	uint32_t *gpio;
	uint32_t flags;
};
#define gpio_axis_2bit_gray_map gpio_axis_4bit_gray_map
#define gpio_axis_3bit_gray_map gpio_axis_4bit_gray_map
uint16_t gpio_axis_4bit_gray_map(
			struct gpio_event_axis_info *info, uint16_t in);
uint16_t gpio_axis_5bit_singletrack_map(
			struct gpio_event_axis_info *info, uint16_t in);

#endif
