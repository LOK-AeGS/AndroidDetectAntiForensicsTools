

#ifndef __LINUX_MFD_SEC_CORE_H
#define __LINUX_MFD_SEC_CORE_H


#define MIN_3000_MV		3000000
#define MIN_2500_MV		2500000
#define MIN_2000_MV		2000000
#define MIN_1800_MV		1800000
#define MIN_1500_MV		1500000
#define MIN_1400_MV		1400000
#define MIN_1000_MV		1000000

#define MIN_900_MV		900000
#define MIN_850_MV		850000
#define MIN_800_MV		800000
#define MIN_750_MV		750000
#define MIN_600_MV		600000
#define MIN_500_MV		500000


#define RAMP_DELAY_12_MVUS	12000


#define STEP_50_MV		50000
#define STEP_25_MV		25000
#define STEP_12_5_MV		12500
#define STEP_6_25_MV		6250

struct gpio_desc;

enum sec_device_type {
	S5M8751X,
	S5M8763X,
	S5M8767X,
	S2MPA01,
	S2MPS11X,
	S2MPS13X,
	S2MPS14X,
	S2MPS15X,
	S2MPU02,
};


struct sec_pmic_dev {
	struct device *dev;
	struct sec_platform_data *pdata;
	struct regmap *regmap_pmic;
	struct i2c_client *i2c;

	unsigned long device_type;
	int irq_base;
	int irq;
	struct regmap_irq_chip_data *irq_data;

	bool wakeup;
};

int sec_irq_init(struct sec_pmic_dev *sec_pmic);
void sec_irq_exit(struct sec_pmic_dev *sec_pmic);
int sec_irq_resume(struct sec_pmic_dev *sec_pmic);

struct sec_platform_data {
	struct sec_regulator_data	*regulators;
	struct sec_opmode_data		*opmode;
	int				device_type;
	int				num_regulators;

	int				irq_base;
	int				(*cfg_pmic_irq)(void);

	bool				wakeup;
	bool				buck_voltage_lock;

	int				buck_gpios[3];
	int				buck_ds[3];
	unsigned int			buck2_voltage[8];
	bool				buck2_gpiodvs;
	unsigned int			buck3_voltage[8];
	bool				buck3_gpiodvs;
	unsigned int			buck4_voltage[8];
	bool				buck4_gpiodvs;

	int				buck_set1;
	int				buck_set2;
	int				buck_set3;
	int				buck2_enable;
	int				buck3_enable;
	int				buck4_enable;
	int				buck_default_idx;
	int				buck2_default_idx;
	int				buck3_default_idx;
	int				buck4_default_idx;

	int				buck_ramp_delay;

	int				buck2_ramp_delay;
	int				buck34_ramp_delay;
	int				buck5_ramp_delay;
	int				buck16_ramp_delay;
	int				buck7810_ramp_delay;
	int				buck9_ramp_delay;
	int				buck24_ramp_delay;
	int				buck3_ramp_delay;
	int				buck7_ramp_delay;
	int				buck8910_ramp_delay;

	bool				buck1_ramp_enable;
	bool				buck2_ramp_enable;
	bool				buck3_ramp_enable;
	bool				buck4_ramp_enable;
	bool				buck6_ramp_enable;

	int				buck2_init;
	int				buck3_init;
	int				buck4_init;
	
	bool				manual_poweroff;
	
	bool				disable_wrstbi;
};


struct sec_regulator_data {
	int				id;
	struct regulator_init_data	*initdata;
	struct device_node		*reg_node;
	struct gpio_desc		*ext_control_gpiod;
};


struct sec_opmode_data {
	int id;
	unsigned int mode;
};



enum sec_opmode {
	SEC_OPMODE_OFF,
	SEC_OPMODE_ON,
	SEC_OPMODE_LOWPOWER,
	SEC_OPMODE_SUSPEND,
};

#endif 
