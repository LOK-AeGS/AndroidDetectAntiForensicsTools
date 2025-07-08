/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
#ifndef __BATTERYDATA_LIB_H__
#define __BATTERYDATA_LIB_H__

#include <linux/ioctl.h>


struct battery_params {
	int soc;
	int ocv_uv;
	int rbatt_sf;
	int batt_temp;
	int slope;
	int fcc_mah;
};


#define BPIOCXSOC	_IOWR('B', 0x01, struct battery_params) 
#define BPIOCXRBATT	_IOWR('B', 0x02, struct battery_params) 
#define BPIOCXSLOPE	_IOWR('B', 0x03, struct battery_params) 
#define BPIOCXFCC	_IOWR('B', 0x04, struct battery_params) 

#endif
