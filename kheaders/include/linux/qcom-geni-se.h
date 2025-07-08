/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */


#ifndef _LINUX_QCOM_GENI_SE
#define _LINUX_QCOM_GENI_SE
#include <linux/clk.h>
#include <linux/dma-direction.h>
#include <linux/io.h>
#include <linux/list.h>
#include <linux/msm-bus.h>
#include <linux/msm-bus-board.h>


enum se_xfer_mode {
	INVALID,
	FIFO_MODE,
	GSI_DMA,
	SE_DMA,
};


enum se_protocol_types {
	NONE,
	SPI,
	UART,
	I2C,
	I3C
};


struct se_geni_rsc {
	struct device *ctrl_dev;
	struct device *wrapper_dev;
	struct clk *se_clk;
	struct clk *m_ahb_clk;
	struct clk *s_ahb_clk;
	struct list_head ab_list;
	struct list_head ab_list_noc;
	unsigned long ab;
	unsigned long ab_noc;
	struct list_head ib_list;
	struct list_head ib_list_noc;
	unsigned long ib;
	unsigned long ib_noc;
	struct pinctrl *geni_pinctrl;
	struct pinctrl_state *geni_gpio_active;
	struct pinctrl_state *geni_gpio_sleep;
	int	clk_freq_out;
	unsigned int num_clk_levels;
	unsigned long *clk_perf_tbl;
};

#define PINCTRL_DEFAULT	"default"
#define PINCTRL_ACTIVE	"active"
#define PINCTRL_SLEEP	"sleep"

#define KHz(freq) (1000 * (freq))


#define GENI_INIT_CFG_REVISION		(0x0)
#define GENI_S_INIT_CFG_REVISION	(0x4)
#define GENI_FORCE_DEFAULT_REG		(0x20)
#define GENI_OUTPUT_CTRL		(0x24)
#define GENI_CGC_CTRL			(0x28)
#define SE_GENI_STATUS			(0x40)
#define GENI_SER_M_CLK_CFG		(0x48)
#define GENI_SER_S_CLK_CFG		(0x4C)
#define GENI_CLK_CTRL_RO		(0x60)
#define GENI_IF_FIFO_DISABLE_RO		(0x64)
#define GENI_FW_REVISION_RO		(0x68)
#define GENI_FW_S_REVISION_RO		(0x6C)
#define SE_GENI_CLK_SEL			(0x7C)
#define SE_GENI_BYTE_GRAN		(0x254)
#define SE_GENI_DMA_MODE_EN		(0x258)
#define SE_GENI_TX_PACKING_CFG0		(0x260)
#define SE_GENI_TX_PACKING_CFG1		(0x264)
#define SE_GENI_RX_PACKING_CFG0		(0x284)
#define SE_GENI_RX_PACKING_CFG1		(0x288)
#define SE_GENI_M_CMD0			(0x600)
#define SE_GENI_M_CMD_CTRL_REG		(0x604)
#define SE_GENI_M_IRQ_STATUS		(0x610)
#define SE_GENI_M_IRQ_EN		(0x614)
#define SE_GENI_M_IRQ_CLEAR		(0x618)
#define SE_GENI_S_CMD0			(0x630)
#define SE_GENI_S_CMD_CTRL_REG		(0x634)
#define SE_GENI_S_IRQ_STATUS		(0x640)
#define SE_GENI_S_IRQ_EN		(0x644)
#define SE_GENI_S_IRQ_CLEAR		(0x648)
#define SE_GENI_TX_FIFOn		(0x700)
#define SE_GENI_RX_FIFOn		(0x780)
#define SE_GENI_TX_FIFO_STATUS		(0x800)
#define SE_GENI_RX_FIFO_STATUS		(0x804)
#define SE_GENI_TX_WATERMARK_REG	(0x80C)
#define SE_GENI_RX_WATERMARK_REG	(0x810)
#define SE_GENI_RX_RFR_WATERMARK_REG	(0x814)
#define SE_GENI_IOS			(0x908)
#define SE_GENI_M_GP_LENGTH		(0x910)
#define SE_GENI_S_GP_LENGTH		(0x914)
#define SE_GSI_EVENT_EN			(0xE18)
#define SE_IRQ_EN			(0xE1C)
#define SE_HW_PARAM_0			(0xE24)
#define SE_HW_PARAM_1			(0xE28)
#define SE_DMA_GENERAL_CFG		(0xE30)
#define SE_DMA_DEBUG_REG0		(0xE40)
#define QUPV3_HW_VER			(0x4)


#define DEFAULT_IO_OUTPUT_CTRL_MSK	(GENMASK(6, 0))


#define FORCE_DEFAULT	(BIT(0))


#define CFG_AHB_CLK_CGC_ON		(BIT(0))
#define CFG_AHB_WR_ACLK_CGC_ON		(BIT(1))
#define DATA_AHB_CLK_CGC_ON		(BIT(2))
#define SCLK_CGC_ON			(BIT(3))
#define TX_CLK_CGC_ON			(BIT(4))
#define RX_CLK_CGC_ON			(BIT(5))
#define EXT_CLK_CGC_ON			(BIT(6))
#define PROG_RAM_HCLK_OFF		(BIT(8))
#define PROG_RAM_SCLK_OFF		(BIT(9))
#define DEFAULT_CGC_EN			(GENMASK(6, 0))


#define M_GENI_CMD_ACTIVE		(BIT(0))
#define S_GENI_CMD_ACTIVE		(BIT(12))


#define SER_CLK_EN			(BIT(0))
#define CLK_DIV_MSK			(GENMASK(15, 4))
#define CLK_DIV_SHFT			(4)




#define FIFO_IF_DISABLE			(BIT(0))


#define FW_REV_PROTOCOL_MSK	(GENMASK(15, 8))
#define FW_REV_PROTOCOL_SHFT	(8)
#define FW_REV_VERSION_MSK	(GENMASK(7, 0))


#define CLK_SEL_MSK		(GENMASK(2, 0))


#define GENI_DMA_MODE_EN	(BIT(0))


#define M_OPCODE_MSK		(GENMASK(31, 27))
#define M_OPCODE_SHFT		(27)
#define M_PARAMS_MSK		(GENMASK(26, 0))


#define M_GENI_CMD_CANCEL	BIT(2)
#define M_GENI_CMD_ABORT	BIT(1)
#define M_GENI_DISABLE		BIT(0)


#define S_OPCODE_MSK		(GENMASK(31, 27))
#define S_OPCODE_SHFT		(27)
#define S_PARAMS_MSK		(GENMASK(26, 0))


#define S_GENI_CMD_CANCEL	(BIT(2))
#define S_GENI_CMD_ABORT	(BIT(1))
#define S_GENI_DISABLE		(BIT(0))


#define M_CMD_DONE_EN		(BIT(0))
#define M_CMD_OVERRUN_EN	(BIT(1))
#define M_ILLEGAL_CMD_EN	(BIT(2))
#define M_CMD_FAILURE_EN	(BIT(3))
#define M_CMD_CANCEL_EN		(BIT(4))
#define M_CMD_ABORT_EN		(BIT(5))
#define M_TIMESTAMP_EN		(BIT(6))
#define M_RX_IRQ_EN		(BIT(7))
#define M_GP_SYNC_IRQ_0_EN	(BIT(8))
#define M_GP_IRQ_0_EN		(BIT(9))
#define M_GP_IRQ_1_EN		(BIT(10))
#define M_GP_IRQ_2_EN		(BIT(11))
#define M_GP_IRQ_3_EN		(BIT(12))
#define M_GP_IRQ_4_EN		(BIT(13))
#define M_GP_IRQ_5_EN		(BIT(14))
#define M_IO_DATA_DEASSERT_EN	(BIT(22))
#define M_IO_DATA_ASSERT_EN	(BIT(23))
#define M_RX_FIFO_RD_ERR_EN	(BIT(24))
#define M_RX_FIFO_WR_ERR_EN	(BIT(25))
#define M_RX_FIFO_WATERMARK_EN	(BIT(26))
#define M_RX_FIFO_LAST_EN	(BIT(27))
#define M_TX_FIFO_RD_ERR_EN	(BIT(28))
#define M_TX_FIFO_WR_ERR_EN	(BIT(29))
#define M_TX_FIFO_WATERMARK_EN	(BIT(30))
#define M_SEC_IRQ_EN		(BIT(31))
#define M_COMMON_GENI_M_IRQ_EN	(GENMASK(6, 1) | \
				M_IO_DATA_DEASSERT_EN | \
				M_IO_DATA_ASSERT_EN | M_RX_FIFO_RD_ERR_EN | \
				M_RX_FIFO_WR_ERR_EN | M_TX_FIFO_RD_ERR_EN | \
				M_TX_FIFO_WR_ERR_EN)


#define S_CMD_DONE_EN		(BIT(0))
#define S_CMD_OVERRUN_EN	(BIT(1))
#define S_ILLEGAL_CMD_EN	(BIT(2))
#define S_CMD_FAILURE_EN	(BIT(3))
#define S_CMD_CANCEL_EN		(BIT(4))
#define S_CMD_ABORT_EN		(BIT(5))
#define S_GP_SYNC_IRQ_0_EN	(BIT(8))
#define S_GP_IRQ_0_EN		(BIT(9))
#define S_GP_IRQ_1_EN		(BIT(10))
#define S_GP_IRQ_2_EN		(BIT(11))
#define S_GP_IRQ_3_EN		(BIT(12))
#define S_GP_IRQ_4_EN		(BIT(13))
#define S_GP_IRQ_5_EN		(BIT(14))
#define S_IO_DATA_DEASSERT_EN	(BIT(22))
#define S_IO_DATA_ASSERT_EN	(BIT(23))
#define S_RX_FIFO_RD_ERR_EN	(BIT(24))
#define S_RX_FIFO_WR_ERR_EN	(BIT(25))
#define S_RX_FIFO_WATERMARK_EN	(BIT(26))
#define S_RX_FIFO_LAST_EN	(BIT(27))
#define S_COMMON_GENI_S_IRQ_EN	(GENMASK(5, 1) | GENMASK(13, 9) | \
				 S_RX_FIFO_RD_ERR_EN | S_RX_FIFO_WR_ERR_EN)


#define WATERMARK_MSK		(GENMASK(5, 0))


#define TX_FIFO_WC		(GENMASK(27, 0))


#define RX_LAST			(BIT(31))
#define RX_LAST_BYTE_VALID_MSK	(GENMASK(30, 28))
#define RX_LAST_BYTE_VALID_SHFT	(28)
#define RX_FIFO_WC_MSK		(GENMASK(24, 0))


#define DMA_RX_EVENT_EN		(BIT(0))
#define DMA_TX_EVENT_EN		(BIT(1))
#define GENI_M_EVENT_EN		(BIT(2))
#define GENI_S_EVENT_EN		(BIT(3))


#define IO2_DATA_IN		(BIT(1))
#define RX_DATA_IN		(BIT(0))


#define DMA_RX_IRQ_EN		(BIT(0))
#define DMA_TX_IRQ_EN		(BIT(1))
#define GENI_M_IRQ_EN		(BIT(2))
#define GENI_S_IRQ_EN		(BIT(3))


#define TX_FIFO_WIDTH_MSK	(GENMASK(29, 24))
#define TX_FIFO_WIDTH_SHFT	(24)
#define TX_FIFO_DEPTH_MSK	(GENMASK(21, 16))
#define TX_FIFO_DEPTH_SHFT	(16)
#define GEN_I3C_IBI_CTRL	(BIT(7))


#define RX_FIFO_WIDTH_MSK	(GENMASK(29, 24))
#define RX_FIFO_WIDTH_SHFT	(24)
#define RX_FIFO_DEPTH_MSK	(GENMASK(21, 16))
#define RX_FIFO_DEPTH_SHFT	(16)


#define DMA_RX_CLK_CGC_ON	(BIT(0))
#define DMA_TX_CLK_CGC_ON	(BIT(1))
#define DMA_AHB_SLV_CFG_ON	(BIT(2))
#define AHB_SEC_SLV_CLK_CGC_ON	(BIT(3))
#define DUMMY_RX_NON_BUFFERABLE	(BIT(4))
#define RX_DMA_ZERO_PADDING_EN	(BIT(5))
#define RX_DMA_IRQ_DELAY_MSK	(GENMASK(8, 6))
#define RX_DMA_IRQ_DELAY_SHFT	(6)

#define SE_DMA_TX_PTR_L		(0xC30)
#define SE_DMA_TX_PTR_H		(0xC34)
#define SE_DMA_TX_ATTR		(0xC38)
#define SE_DMA_TX_LEN		(0xC3C)
#define SE_DMA_TX_IRQ_STAT	(0xC40)
#define SE_DMA_TX_IRQ_CLR	(0xC44)
#define SE_DMA_TX_IRQ_EN	(0xC48)
#define SE_DMA_TX_IRQ_EN_SET	(0xC4C)
#define SE_DMA_TX_IRQ_EN_CLR	(0xC50)
#define SE_DMA_TX_LEN_IN	(0xC54)
#define SE_DMA_TX_FSM_RST	(0xC58)
#define SE_DMA_TX_MAX_BURST	(0xC5C)

#define SE_DMA_RX_PTR_L		(0xD30)
#define SE_DMA_RX_PTR_H		(0xD34)
#define SE_DMA_RX_ATTR		(0xD38)
#define SE_DMA_RX_LEN		(0xD3C)
#define SE_DMA_RX_IRQ_STAT	(0xD40)
#define SE_DMA_RX_IRQ_CLR	(0xD44)
#define SE_DMA_RX_IRQ_EN	(0xD48)
#define SE_DMA_RX_IRQ_EN_SET	(0xD4C)
#define SE_DMA_RX_IRQ_EN_CLR	(0xD50)
#define SE_DMA_RX_LEN_IN	(0xD54)
#define SE_DMA_RX_FSM_RST	(0xD58)
#define SE_DMA_RX_MAX_BURST	(0xD5C)
#define SE_DMA_RX_FLUSH		(0xD60)


#define TX_DMA_DONE		(BIT(0))
#define TX_EOT			(BIT(1))
#define TX_SBE			(BIT(2))
#define TX_RESET_DONE		(BIT(3))
#define TX_GENI_CANCEL_IRQ	(BIT(14))


#define RX_DMA_DONE		(BIT(0))
#define RX_EOT			(BIT(1))
#define RX_SBE			(BIT(2))
#define RX_RESET_DONE		(BIT(3))
#define RX_FLUSH_DONE		(BIT(4))
#define RX_GENI_GP_IRQ		(GENMASK(10, 5))
#define RX_GENI_CANCEL_IRQ	(BIT(14))
#define RX_GENI_GP_IRQ_EXT	(GENMASK(13, 12))


#define DMA_TX_ACTIVE		(BIT(0))
#define DMA_RX_ACTIVE		(BIT(1))
#define DMA_TX_STATE		(GENMASK(7, 4))
#define DMA_RX_STATE		(GENMASK(11, 8))

#define DEFAULT_BUS_WIDTH	(4)
#define DEFAULT_SE_CLK		(19200000)



#define GSI_TX_PACK_EN          (BIT(0))
#define GSI_RX_PACK_EN          (BIT(1))
#define GSI_PRESERVE_PACK       (BIT(2))

#define GENI_SE_ERR(log_ctx, print, dev, x...) do { \
if (log_ctx) \
	ipc_log_string(log_ctx, x); \
if (print) { \
	if (dev) \
		dev_err((dev), x); \
	else \
		pr_err(x); \
} \
} while (0)

#define GENI_SE_DBG(log_ctx, print, dev, x...) do { \
if (log_ctx) \
	ipc_log_string(log_ctx, x); \
if (print) { \
	if (dev) \
		dev_dbg((dev), x); \
	else \
		pr_debug(x); \
} \
} while (0)


#ifdef CONFIG_QCOM_GENI_SE

unsigned int geni_read_reg_nolog(void __iomem *base, int offset);


void geni_write_reg_nolog(unsigned int value, void __iomem *base, int offset);


unsigned int geni_read_reg(void __iomem *base, int offset);


void geni_write_reg(unsigned int value, void __iomem *base, int offset);


int get_se_proto(void __iomem *base);


int get_se_m_fw(void __iomem *base);


int get_se_s_fw(void __iomem *base);


int geni_se_init(void __iomem *base, unsigned int rx_wm, unsigned int rx_rfr);


int geni_se_select_mode(void __iomem *base, int mode);


void geni_setup_m_cmd(void __iomem *base, u32 cmd, u32 params);


void geni_setup_s_cmd(void __iomem *base, u32 cmd, u32 params);


void geni_cancel_m_cmd(void __iomem *base);


void geni_cancel_s_cmd(void __iomem *base);


void geni_abort_m_cmd(void __iomem *base);


void geni_abort_s_cmd(void __iomem *base);


int get_tx_fifo_depth(void __iomem *base);


int get_tx_fifo_width(void __iomem *base);


int get_rx_fifo_depth(void __iomem *base);


void se_get_packing_config(int bpw, int pack_words, bool msb_to_lsb,
			   unsigned long *cfg0, unsigned long *cfg1);


void se_config_packing(void __iomem *base, int bpw, int pack_words,
		       bool msb_to_lsb);


int se_geni_clks_off(struct se_geni_rsc *rsc);


int se_geni_clks_on(struct se_geni_rsc *rsc);


int se_geni_resources_off(struct se_geni_rsc *rsc);


int se_geni_resources_on(struct se_geni_rsc *rsc);


int geni_se_resources_init(struct se_geni_rsc *rsc,
			   unsigned long ab, unsigned long ib);


int geni_se_clk_tbl_get(struct se_geni_rsc *rsc, unsigned long **tbl);


int geni_se_clk_freq_match(struct se_geni_rsc *rsc, unsigned long req_freq,
			   unsigned int *index, unsigned long *res_freq,
			   bool exact);


int geni_se_tx_dma_prep(struct device *wrapper_dev, void __iomem *base,
			void *tx_buf, int tx_len, dma_addr_t *tx_dma);


void geni_se_rx_dma_start(void __iomem *base, int rx_len, dma_addr_t *rx_dma);


int geni_se_rx_dma_prep(struct device *wrapper_dev, void __iomem *base,
			void *rx_buf, int rx_len, dma_addr_t *rx_dma);


void geni_se_tx_dma_unprep(struct device *wrapper_dev,
			   dma_addr_t tx_dma, int tx_len);


void geni_se_rx_dma_unprep(struct device *wrapper_dev,
			   dma_addr_t rx_dma, int rx_len);


int geni_se_qupv3_hw_version(struct device *wrapper_dev, unsigned int *major,
			     unsigned int *minor, unsigned int *step);


int geni_se_iommu_map_buf(struct device *wrapper_dev, dma_addr_t *iova,
			  void *buf, size_t size, enum dma_data_direction dir);


void *geni_se_iommu_alloc_buf(struct device *wrapper_dev, dma_addr_t *iova,
			      size_t size);


int geni_se_iommu_unmap_buf(struct device *wrapper_dev, dma_addr_t *iova,
			    size_t size, enum dma_data_direction dir);


int geni_se_iommu_free_buf(struct device *wrapper_dev, dma_addr_t *iova,
			   void *buf, size_t size);



void geni_se_dump_dbg_regs(struct se_geni_rsc *rsc, void __iomem *base,
				void *ipc);

#else
static inline unsigned int geni_read_reg_nolog(void __iomem *base, int offset)
{
	return 0;
}

static inline void geni_write_reg_nolog(unsigned int value,
					void __iomem *base, int offset)
{
}

static inline unsigned int geni_read_reg(void __iomem *base, int offset)
{
	return 0;
}

static inline void geni_write_reg(unsigned int value, void __iomem *base,
				int offset)
{
}

static inline int get_se_proto(void __iomem *base)
{
	return -ENXIO;
}

static inline int geni_se_init(void __iomem *base,
		unsigned int rx_wm, unsigned int rx_rfr)
{
	return -ENXIO;
}

static inline int geni_se_select_mode(void __iomem *base, int mode)
{
	return -ENXIO;
}

static inline void geni_setup_m_cmd(void __iomem *base, u32 cmd,
								u32 params)
{
}

static inline void geni_setup_s_cmd(void __iomem *base, u32 cmd,
								u32 params)
{
}

static inline void geni_cancel_m_cmd(void __iomem *base)
{
}

static inline void geni_cancel_s_cmd(void __iomem *base)
{
}

static inline void geni_abort_m_cmd(void __iomem *base)
{
}

static inline void geni_abort_s_cmd(void __iomem *base)
{
}

static inline int get_tx_fifo_depth(void __iomem *base)
{
	return -ENXIO;
}

static inline int get_tx_fifo_width(void __iomem *base)
{
	return -ENXIO;
}

static inline int get_rx_fifo_depth(void __iomem *base)
{
	return -ENXIO;
}

static inline void se_get_packing_config(int bpw, int pack_words,
					bool msb_to_lsb, unsigned long *cfg0,
					unsigned long *cfg1)
{
}

static inline void se_config_packing(void __iomem *base, int bpw,
				int pack_words, bool msb_to_lsb)
{
}

static inline int se_geni_clks_on(struct se_geni_rsc *rsc)
{
	return -ENXIO;
}

static inline int se_geni_clks_off(struct se_geni_rsc *rsc)
{
	return -ENXIO;
}

static inline int se_geni_resources_on(struct se_geni_rsc *rsc)
{
	return -ENXIO;
}

static inline int se_geni_resources_off(struct se_geni_rsc *rsc)
{
	return -ENXIO;
}

static inline int geni_se_resources_init(struct se_geni_rsc *rsc,
					 unsigned long ab, unsigned long ib)
{
	return -ENXIO;
}

static inline int geni_se_clk_tbl_get(struct se_geni_rsc *rsc,
					unsigned long **tbl)
{
	return -ENXIO;
}

static inline int geni_se_clk_freq_match(struct se_geni_rsc *rsc,
			unsigned long req_freq, unsigned int *index,
			unsigned long *res_freq, bool exact)
{
	return -ENXIO;
}

static inline int geni_se_tx_dma_prep(struct device *wrapper_dev,
	void __iomem *base, void *tx_buf, int tx_len, dma_addr_t *tx_dma)
{
	return -ENXIO;
}

static inline int geni_se_rx_dma_prep(struct device *wrapper_dev,
	void __iomem *base, void *rx_buf, int rx_len, dma_addr_t *rx_dma)
{
	return -ENXIO;
}

static inline void geni_se_tx_dma_unprep(struct device *wrapper_dev,
					dma_addr_t tx_dma, int tx_len)
{
}

static inline void geni_se_rx_dma_unprep(struct device *wrapper_dev,
					dma_addr_t rx_dma, int rx_len)
{
}

static inline int geni_se_qupv3_hw_version(struct device *wrapper_dev,
		unsigned int *major, unsigned int *minor, unsigned int *step)
{
	return -ENXIO;
}

static inline int geni_se_iommu_map_buf(struct device *wrapper_dev,
	dma_addr_t *iova, void *buf, size_t size, enum dma_data_direction dir)
{
	return -ENXIO;
}

static inline void *geni_se_iommu_alloc_buf(struct device *wrapper_dev,
					dma_addr_t *iova, size_t size)
{
	return NULL;
}

static inline int geni_se_iommu_unmap_buf(struct device *wrapper_dev,
		dma_addr_t *iova, size_t size, enum dma_data_direction dir)
{
	return -ENXIO;

}

static inline int geni_se_iommu_free_buf(struct device *wrapper_dev,
				dma_addr_t *iova, void *buf, size_t size)
{
	return -ENXIO;
}

static void geni_se_dump_dbg_regs(struct se_geni_rsc *rsc, void __iomem *base,
				void *ipc)
{
}

static void geni_se_rx_dma_start(void __iomem *base, int rx_len,
						dma_addr_t *rx_dma)
{
}

#endif
#endif
