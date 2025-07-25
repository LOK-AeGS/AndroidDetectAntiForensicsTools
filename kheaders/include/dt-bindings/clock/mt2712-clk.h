

#ifndef _DT_BINDINGS_CLK_MT2712_H
#define _DT_BINDINGS_CLK_MT2712_H



#define CLK_APMIXED_MAINPLL		0
#define CLK_APMIXED_UNIVPLL		1
#define CLK_APMIXED_VCODECPLL		2
#define CLK_APMIXED_VENCPLL		3
#define CLK_APMIXED_APLL1		4
#define CLK_APMIXED_APLL2		5
#define CLK_APMIXED_LVDSPLL		6
#define CLK_APMIXED_LVDSPLL2		7
#define CLK_APMIXED_MSDCPLL		8
#define CLK_APMIXED_MSDCPLL2		9
#define CLK_APMIXED_TVDPLL		10
#define CLK_APMIXED_MMPLL		11
#define CLK_APMIXED_ARMCA35PLL		12
#define CLK_APMIXED_ARMCA72PLL		13
#define CLK_APMIXED_ETHERPLL		14
#define CLK_APMIXED_NR_CLK		15



#define CLK_TOP_ARMCA35PLL		0
#define CLK_TOP_ARMCA35PLL_600M		1
#define CLK_TOP_ARMCA35PLL_400M		2
#define CLK_TOP_ARMCA72PLL		3
#define CLK_TOP_SYSPLL			4
#define CLK_TOP_SYSPLL_D2		5
#define CLK_TOP_SYSPLL1_D2		6
#define CLK_TOP_SYSPLL1_D4		7
#define CLK_TOP_SYSPLL1_D8		8
#define CLK_TOP_SYSPLL1_D16		9
#define CLK_TOP_SYSPLL_D3		10
#define CLK_TOP_SYSPLL2_D2		11
#define CLK_TOP_SYSPLL2_D4		12
#define CLK_TOP_SYSPLL_D5		13
#define CLK_TOP_SYSPLL3_D2		14
#define CLK_TOP_SYSPLL3_D4		15
#define CLK_TOP_SYSPLL_D7		16
#define CLK_TOP_SYSPLL4_D2		17
#define CLK_TOP_SYSPLL4_D4		18
#define CLK_TOP_UNIVPLL			19
#define CLK_TOP_UNIVPLL_D7		20
#define CLK_TOP_UNIVPLL_D26		21
#define CLK_TOP_UNIVPLL_D52		22
#define CLK_TOP_UNIVPLL_D104		23
#define CLK_TOP_UNIVPLL_D208		24
#define CLK_TOP_UNIVPLL_D2		25
#define CLK_TOP_UNIVPLL1_D2		26
#define CLK_TOP_UNIVPLL1_D4		27
#define CLK_TOP_UNIVPLL1_D8		28
#define CLK_TOP_UNIVPLL_D3		29
#define CLK_TOP_UNIVPLL2_D2		30
#define CLK_TOP_UNIVPLL2_D4		31
#define CLK_TOP_UNIVPLL2_D8		32
#define CLK_TOP_UNIVPLL_D5		33
#define CLK_TOP_UNIVPLL3_D2		34
#define CLK_TOP_UNIVPLL3_D4		35
#define CLK_TOP_UNIVPLL3_D8		36
#define CLK_TOP_F_MP0_PLL1		37
#define CLK_TOP_F_MP0_PLL2		38
#define CLK_TOP_F_BIG_PLL1		39
#define CLK_TOP_F_BIG_PLL2		40
#define CLK_TOP_F_BUS_PLL1		41
#define CLK_TOP_F_BUS_PLL2		42
#define CLK_TOP_APLL1			43
#define CLK_TOP_APLL1_D2		44
#define CLK_TOP_APLL1_D4		45
#define CLK_TOP_APLL1_D8		46
#define CLK_TOP_APLL1_D16		47
#define CLK_TOP_APLL2			48
#define CLK_TOP_APLL2_D2		49
#define CLK_TOP_APLL2_D4		50
#define CLK_TOP_APLL2_D8		51
#define CLK_TOP_APLL2_D16		52
#define CLK_TOP_LVDSPLL			53
#define CLK_TOP_LVDSPLL_D2		54
#define CLK_TOP_LVDSPLL_D4		55
#define CLK_TOP_LVDSPLL_D8		56
#define CLK_TOP_LVDSPLL2		57
#define CLK_TOP_LVDSPLL2_D2		58
#define CLK_TOP_LVDSPLL2_D4		59
#define CLK_TOP_LVDSPLL2_D8		60
#define CLK_TOP_ETHERPLL_125M		61
#define CLK_TOP_ETHERPLL_50M		62
#define CLK_TOP_CVBS			63
#define CLK_TOP_CVBS_D2			64
#define CLK_TOP_SYS_26M			65
#define CLK_TOP_MMPLL			66
#define CLK_TOP_MMPLL_D2		67
#define CLK_TOP_VENCPLL			68
#define CLK_TOP_VENCPLL_D2		69
#define CLK_TOP_VCODECPLL		70
#define CLK_TOP_VCODECPLL_D2		71
#define CLK_TOP_TVDPLL			72
#define CLK_TOP_TVDPLL_D2		73
#define CLK_TOP_TVDPLL_D4		74
#define CLK_TOP_TVDPLL_D8		75
#define CLK_TOP_TVDPLL_429M		76
#define CLK_TOP_TVDPLL_429M_D2		77
#define CLK_TOP_TVDPLL_429M_D4		78
#define CLK_TOP_MSDCPLL			79
#define CLK_TOP_MSDCPLL_D2		80
#define CLK_TOP_MSDCPLL_D4		81
#define CLK_TOP_MSDCPLL2		82
#define CLK_TOP_MSDCPLL2_D2		83
#define CLK_TOP_MSDCPLL2_D4		84
#define CLK_TOP_CLK26M_D2		85
#define CLK_TOP_D2A_ULCLK_6P5M		86
#define CLK_TOP_VPLL3_DPIX		87
#define CLK_TOP_VPLL_DPIX		88
#define CLK_TOP_LTEPLL_FS26M		89
#define CLK_TOP_DMPLL			90
#define CLK_TOP_DSI0_LNTC		91
#define CLK_TOP_DSI1_LNTC		92
#define CLK_TOP_LVDSTX3_CLKDIG_CTS	93
#define CLK_TOP_LVDSTX_CLKDIG_CTS	94
#define CLK_TOP_CLKRTC_EXT		95
#define CLK_TOP_CLKRTC_INT		96
#define CLK_TOP_CSI0			97
#define CLK_TOP_CVBSPLL			98
#define CLK_TOP_AXI_SEL			99
#define CLK_TOP_MEM_SEL			100
#define CLK_TOP_MM_SEL			101
#define CLK_TOP_PWM_SEL			102
#define CLK_TOP_VDEC_SEL		103
#define CLK_TOP_VENC_SEL		104
#define CLK_TOP_MFG_SEL			105
#define CLK_TOP_CAMTG_SEL		106
#define CLK_TOP_UART_SEL		107
#define CLK_TOP_SPI_SEL			108
#define CLK_TOP_USB20_SEL		109
#define CLK_TOP_USB30_SEL		110
#define CLK_TOP_MSDC50_0_HCLK_SEL	111
#define CLK_TOP_MSDC50_0_SEL		112
#define CLK_TOP_MSDC30_1_SEL		113
#define CLK_TOP_MSDC30_2_SEL		114
#define CLK_TOP_MSDC30_3_SEL		115
#define CLK_TOP_AUDIO_SEL		116
#define CLK_TOP_AUD_INTBUS_SEL		117
#define CLK_TOP_PMICSPI_SEL		118
#define CLK_TOP_DPILVDS1_SEL		119
#define CLK_TOP_ATB_SEL			120
#define CLK_TOP_NR_SEL			121
#define CLK_TOP_NFI2X_SEL		122
#define CLK_TOP_IRDA_SEL		123
#define CLK_TOP_CCI400_SEL		124
#define CLK_TOP_AUD_1_SEL		125
#define CLK_TOP_AUD_2_SEL		126
#define CLK_TOP_MEM_MFG_IN_AS_SEL	127
#define CLK_TOP_AXI_MFG_IN_AS_SEL	128
#define CLK_TOP_SCAM_SEL		129
#define CLK_TOP_NFIECC_SEL		130
#define CLK_TOP_PE2_MAC_P0_SEL		131
#define CLK_TOP_PE2_MAC_P1_SEL		132
#define CLK_TOP_DPILVDS_SEL		133
#define CLK_TOP_MSDC50_3_HCLK_SEL	134
#define CLK_TOP_HDCP_SEL		135
#define CLK_TOP_HDCP_24M_SEL		136
#define CLK_TOP_RTC_SEL			137
#define CLK_TOP_SPINOR_SEL		138
#define CLK_TOP_APLL_SEL		139
#define CLK_TOP_APLL2_SEL		140
#define CLK_TOP_A1SYS_HP_SEL		141
#define CLK_TOP_A2SYS_HP_SEL		142
#define CLK_TOP_ASM_L_SEL		143
#define CLK_TOP_ASM_M_SEL		144
#define CLK_TOP_ASM_H_SEL		145
#define CLK_TOP_I2SO1_SEL		146
#define CLK_TOP_I2SO2_SEL		147
#define CLK_TOP_I2SO3_SEL		148
#define CLK_TOP_TDMO0_SEL		149
#define CLK_TOP_TDMO1_SEL		150
#define CLK_TOP_I2SI1_SEL		151
#define CLK_TOP_I2SI2_SEL		152
#define CLK_TOP_I2SI3_SEL		153
#define CLK_TOP_ETHER_125M_SEL		154
#define CLK_TOP_ETHER_50M_SEL		155
#define CLK_TOP_JPGDEC_SEL		156
#define CLK_TOP_SPISLV_SEL		157
#define CLK_TOP_ETHER_50M_RMII_SEL	158
#define CLK_TOP_CAM2TG_SEL		159
#define CLK_TOP_DI_SEL			160
#define CLK_TOP_TVD_SEL			161
#define CLK_TOP_I2C_SEL			162
#define CLK_TOP_PWM_INFRA_SEL		163
#define CLK_TOP_MSDC0P_AES_SEL		164
#define CLK_TOP_CMSYS_SEL		165
#define CLK_TOP_GCPU_SEL		166
#define CLK_TOP_AUD_APLL1_SEL		167
#define CLK_TOP_AUD_APLL2_SEL		168
#define CLK_TOP_DA_AUDULL_VTX_6P5M_SEL	169
#define CLK_TOP_APLL_DIV0		170
#define CLK_TOP_APLL_DIV1		171
#define CLK_TOP_APLL_DIV2		172
#define CLK_TOP_APLL_DIV3		173
#define CLK_TOP_APLL_DIV4		174
#define CLK_TOP_APLL_DIV5		175
#define CLK_TOP_APLL_DIV6		176
#define CLK_TOP_APLL_DIV7		177
#define CLK_TOP_APLL_DIV_PDN0		178
#define CLK_TOP_APLL_DIV_PDN1		179
#define CLK_TOP_APLL_DIV_PDN2		180
#define CLK_TOP_APLL_DIV_PDN3		181
#define CLK_TOP_APLL_DIV_PDN4		182
#define CLK_TOP_APLL_DIV_PDN5		183
#define CLK_TOP_APLL_DIV_PDN6		184
#define CLK_TOP_APLL_DIV_PDN7		185
#define CLK_TOP_APLL1_D3		186
#define CLK_TOP_APLL1_REF_SEL		187
#define CLK_TOP_APLL2_REF_SEL		188
#define CLK_TOP_NFI2X_EN		189
#define CLK_TOP_NFIECC_EN		190
#define CLK_TOP_NFI1X_CK_EN		191
#define CLK_TOP_NR_CLK			192



#define CLK_INFRA_DBGCLK		0
#define CLK_INFRA_GCE			1
#define CLK_INFRA_M4U			2
#define CLK_INFRA_KP			3
#define CLK_INFRA_AO_SPI0		4
#define CLK_INFRA_AO_SPI1		5
#define CLK_INFRA_AO_UART5		6
#define CLK_INFRA_NR_CLK		7



#define CLK_PERI_NFI			0
#define CLK_PERI_THERM			1
#define CLK_PERI_PWM0			2
#define CLK_PERI_PWM1			3
#define CLK_PERI_PWM2			4
#define CLK_PERI_PWM3			5
#define CLK_PERI_PWM4			6
#define CLK_PERI_PWM5			7
#define CLK_PERI_PWM6			8
#define CLK_PERI_PWM7			9
#define CLK_PERI_PWM			10
#define CLK_PERI_AP_DMA			11
#define CLK_PERI_MSDC30_0		12
#define CLK_PERI_MSDC30_1		13
#define CLK_PERI_MSDC30_2		14
#define CLK_PERI_MSDC30_3		15
#define CLK_PERI_UART0			16
#define CLK_PERI_UART1			17
#define CLK_PERI_UART2			18
#define CLK_PERI_UART3			19
#define CLK_PERI_I2C0			20
#define CLK_PERI_I2C1			21
#define CLK_PERI_I2C2			22
#define CLK_PERI_I2C3			23
#define CLK_PERI_I2C4			24
#define CLK_PERI_AUXADC			25
#define CLK_PERI_SPI0			26
#define CLK_PERI_SPI			27
#define CLK_PERI_I2C5			28
#define CLK_PERI_SPI2			29
#define CLK_PERI_SPI3			30
#define CLK_PERI_SPI5			31
#define CLK_PERI_UART4			32
#define CLK_PERI_SFLASH			33
#define CLK_PERI_GMAC			34
#define CLK_PERI_PCIE0			35
#define CLK_PERI_PCIE1			36
#define CLK_PERI_GMAC_PCLK		37
#define CLK_PERI_MSDC50_0_EN		38
#define CLK_PERI_MSDC30_1_EN		39
#define CLK_PERI_MSDC30_2_EN		40
#define CLK_PERI_MSDC30_3_EN		41
#define CLK_PERI_MSDC50_0_HCLK_EN	42
#define CLK_PERI_MSDC50_3_HCLK_EN	43
#define CLK_PERI_MSDC30_0_QTR_EN	44
#define CLK_PERI_MSDC30_3_QTR_EN	45
#define CLK_PERI_NR_CLK			46



#define CLK_MCU_MP0_SEL			0
#define CLK_MCU_MP2_SEL			1
#define CLK_MCU_BUS_SEL			2
#define CLK_MCU_NR_CLK			3



#define CLK_MFG_BG3D			0
#define CLK_MFG_NR_CLK			1



#define CLK_MM_SMI_COMMON		0
#define CLK_MM_SMI_LARB0		1
#define CLK_MM_CAM_MDP			2
#define CLK_MM_MDP_RDMA0		3
#define CLK_MM_MDP_RDMA1		4
#define CLK_MM_MDP_RSZ0			5
#define CLK_MM_MDP_RSZ1			6
#define CLK_MM_MDP_RSZ2			7
#define CLK_MM_MDP_TDSHP0		8
#define CLK_MM_MDP_TDSHP1		9
#define CLK_MM_MDP_CROP			10
#define CLK_MM_MDP_WDMA			11
#define CLK_MM_MDP_WROT0		12
#define CLK_MM_MDP_WROT1		13
#define CLK_MM_FAKE_ENG			14
#define CLK_MM_MUTEX_32K		15
#define CLK_MM_DISP_OVL0		16
#define CLK_MM_DISP_OVL1		17
#define CLK_MM_DISP_RDMA0		18
#define CLK_MM_DISP_RDMA1		19
#define CLK_MM_DISP_RDMA2		20
#define CLK_MM_DISP_WDMA0		21
#define CLK_MM_DISP_WDMA1		22
#define CLK_MM_DISP_COLOR0		23
#define CLK_MM_DISP_COLOR1		24
#define CLK_MM_DISP_AAL			25
#define CLK_MM_DISP_GAMMA		26
#define CLK_MM_DISP_UFOE		27
#define CLK_MM_DISP_SPLIT0		28
#define CLK_MM_DISP_OD			29
#define CLK_MM_DISP_PWM0_MM		30
#define CLK_MM_DISP_PWM0_26M		31
#define CLK_MM_DISP_PWM1_MM		32
#define CLK_MM_DISP_PWM1_26M		33
#define CLK_MM_DSI0_ENGINE		34
#define CLK_MM_DSI0_DIGITAL		35
#define CLK_MM_DSI1_ENGINE		36
#define CLK_MM_DSI1_DIGITAL		37
#define CLK_MM_DPI_PIXEL		38
#define CLK_MM_DPI_ENGINE		39
#define CLK_MM_DPI1_PIXEL		40
#define CLK_MM_DPI1_ENGINE		41
#define CLK_MM_LVDS_PIXEL		42
#define CLK_MM_LVDS_CTS			43
#define CLK_MM_SMI_LARB4		44
#define CLK_MM_SMI_COMMON1		45
#define CLK_MM_SMI_LARB5		46
#define CLK_MM_MDP_RDMA2		47
#define CLK_MM_MDP_TDSHP2		48
#define CLK_MM_DISP_OVL2		49
#define CLK_MM_DISP_WDMA2		50
#define CLK_MM_DISP_COLOR2		51
#define CLK_MM_DISP_AAL1		52
#define CLK_MM_DISP_OD1			53
#define CLK_MM_LVDS1_PIXEL		54
#define CLK_MM_LVDS1_CTS		55
#define CLK_MM_SMI_LARB7		56
#define CLK_MM_MDP_RDMA3		57
#define CLK_MM_MDP_WROT2		58
#define CLK_MM_DSI2			59
#define CLK_MM_DSI2_DIGITAL		60
#define CLK_MM_DSI3			61
#define CLK_MM_DSI3_DIGITAL		62
#define CLK_MM_NR_CLK			63



#define CLK_IMG_SMI_LARB2		0
#define CLK_IMG_SENINF_SCAM_EN		1
#define CLK_IMG_SENINF_CAM_EN		2
#define CLK_IMG_CAM_SV_EN		3
#define CLK_IMG_CAM_SV1_EN		4
#define CLK_IMG_CAM_SV2_EN		5
#define CLK_IMG_NR_CLK			6



#define CLK_BDP_BRIDGE_B		0
#define CLK_BDP_BRIDGE_DRAM		1
#define CLK_BDP_LARB_DRAM		2
#define CLK_BDP_WR_CHANNEL_VDI_PXL	3
#define CLK_BDP_WR_CHANNEL_VDI_DRAM	4
#define CLK_BDP_WR_CHANNEL_VDI_B	5
#define CLK_BDP_MT_B			6
#define CLK_BDP_DISPFMT_27M		7
#define CLK_BDP_DISPFMT_27M_VDOUT	8
#define CLK_BDP_DISPFMT_27_74_74	9
#define CLK_BDP_DISPFMT_2FS		10
#define CLK_BDP_DISPFMT_2FS_2FS74_148	11
#define CLK_BDP_DISPFMT_B		12
#define CLK_BDP_VDO_DRAM		13
#define CLK_BDP_VDO_2FS			14
#define CLK_BDP_VDO_B			15
#define CLK_BDP_WR_CHANNEL_DI_PXL	16
#define CLK_BDP_WR_CHANNEL_DI_DRAM	17
#define CLK_BDP_WR_CHANNEL_DI_B		18
#define CLK_BDP_NR_AGENT		19
#define CLK_BDP_NR_DRAM			20
#define CLK_BDP_NR_B			21
#define CLK_BDP_BRIDGE_RT_B		22
#define CLK_BDP_BRIDGE_RT_DRAM		23
#define CLK_BDP_LARB_RT_DRAM		24
#define CLK_BDP_TVD_TDC			25
#define CLK_BDP_TVD_54			26
#define CLK_BDP_TVD_CBUS		27
#define CLK_BDP_NR_CLK			28



#define CLK_VDEC_CKEN			0
#define CLK_VDEC_LARB1_CKEN		1
#define CLK_VDEC_IMGRZ_CKEN		2
#define CLK_VDEC_NR_CLK			3



#define CLK_VENC_SMI_COMMON_CON		0
#define CLK_VENC_VENC			1
#define CLK_VENC_SMI_LARB6		2
#define CLK_VENC_NR_CLK			3



#define CLK_JPGDEC_JPGDEC1		0
#define CLK_JPGDEC_JPGDEC		1
#define CLK_JPGDEC_NR_CLK		2

#endif 
