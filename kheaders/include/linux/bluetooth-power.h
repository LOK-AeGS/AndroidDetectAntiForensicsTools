/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __LINUX_BLUETOOTH_POWER_H
#define __LINUX_BLUETOOTH_POWER_H


struct bt_power_vreg_data {
	
	struct regulator *reg;
	
	const char *name;
	
	unsigned int low_vol_level;
	unsigned int high_vol_level;
	
	unsigned int load_uA;
	
	bool set_voltage_sup;
	
	bool is_enabled;
};

struct bt_power_clk_data {
	
	struct clk *clk;
	
	const char *name;
	
	bool is_enabled;
};


struct bluetooth_power_platform_data {
	
	int bt_gpio_sys_rst;
	
	int bt_gpio_sw_ctrl;
	
	int wl_gpio_sys_rst;
	
	int bt_gpio_debug;
	struct device *slim_dev;
	
	struct bt_power_vreg_data *bt_vdd_io;
	
	struct bt_power_vreg_data *bt_vdd_pa;
	
	struct bt_power_vreg_data *bt_vdd_ldo;
	
	struct bt_power_vreg_data *bt_vdd_xtal;
	
	struct bt_power_vreg_data *bt_vdd_core;
	
	struct bt_power_vreg_data *bt_vdd_aon;
	
	struct bt_power_vreg_data *bt_vdd_dig;
	
	struct bt_power_vreg_data *bt_vdd_rfa1;
	
	struct bt_power_vreg_data *bt_vdd_rfa2;
	
	struct bt_power_vreg_data *bt_vdd_asd;
	
	struct bt_power_vreg_data *bt_chip_pwd;
	
	struct bt_power_clk_data *bt_chip_clk;
	
	int (*bt_power_setup)(int id);
};

int bt_register_slimdev(struct device *dev);
int get_chipset_version(void);

#define BT_CMD_SLIM_TEST            0xbfac
#define BT_CMD_PWR_CTRL             0xbfad
#define BT_CMD_CHIPSET_VERS         0xbfae

#define BT_CMD_CHECK_SW_CTRL        0xbfb0
#define BT_CMD_GETVAL_POWER_SRCS    0xbfb1



#define BT_POWER_SRC_SIZE           28

#endif 
