

#ifndef ____LINUX_PLATFORM_DATA_SPI_MTK_H
#define ____LINUX_PLATFORM_DATA_SPI_MTK_H


struct mtk_chip_config {
	u32 tx_mlsb;
	u32 rx_mlsb;
	u32 cs_pol;
	u32 sample_sel;
};
#endif
