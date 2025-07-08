/* SPDX-License-Identifier: GPL-2.0-only */




struct msm_spi_platform_data {
	u32 max_clock_speed;
	u32  master_id;
	u32 bus_width;
	int (*gpio_config)(void);
	void (*gpio_release)(void);
	int (*dma_config)(void);
	const char *rsl_id;
	u32  pm_lat;
	u32  infinite_mode;
	bool ver_reg_exists;
	bool use_bam;
	u32  bam_consumer_pipe_index;
	u32  bam_producer_pipe_index;
	bool rt_priority;
	bool use_pinctrl;
	bool is_shared;
	bool shared_ee;
};
