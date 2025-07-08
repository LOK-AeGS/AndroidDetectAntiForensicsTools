/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __WCD_SPI_H__
#define __WCD_SPI_H__

struct wcd_spi_msg {
	
	void *data;

	
	size_t len;

	
	u32 remote_addr;

	
	u32 flags;
};

struct wcd_spi_ops {
	struct spi_device *spi_dev;
	int (*read_dev)(struct spi_device *spi, struct wcd_spi_msg *msg);
	int (*write_dev)(struct spi_device *spi, struct wcd_spi_msg *msg);
};

#endif 
