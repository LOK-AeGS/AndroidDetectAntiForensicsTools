/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __ASM_ARCH_MSM_SERIAL_HS_H
#define __ASM_ARCH_MSM_SERIAL_HS_H

#include <linux/serial_core.h>


struct msm_serial_hs_platform_data {
	int wakeup_irq;  
	bool inject_rx_on_wakeup;
	u8 rx_to_inject;
	int (*gpio_config)(int gpio_config);
	int userid;

	int uart_tx_gpio;
	int uart_rx_gpio;
	int uart_cts_gpio;
	int uart_rfr_gpio;
	unsigned int bam_tx_ep_pipe_index;
	unsigned int bam_rx_ep_pipe_index;
	bool no_suspend_delay;
	bool obs;
};


unsigned int msm_hs_tx_empty(struct uart_port *uport);
int msm_hs_request_clock_off(struct uart_port *uport);
int msm_hs_request_clock_on(struct uart_port *uport);
struct uart_port *msm_hs_get_uart_port(int port_index);
void msm_hs_set_mctrl(struct uart_port *uport,
				    unsigned int mctrl);
#endif
