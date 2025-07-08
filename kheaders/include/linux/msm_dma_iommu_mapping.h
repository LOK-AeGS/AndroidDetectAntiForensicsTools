/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef _LINUX_MSM_DMA_IOMMU_MAPPING_H
#define _LINUX_MSM_DMA_IOMMU_MAPPING_H

#include <linux/device.h>
#include <linux/dma-buf.h>
#include <linux/scatterlist.h>
#include <linux/dma-mapping.h>

#ifdef CONFIG_QCOM_LAZY_MAPPING

int msm_dma_map_sg_attrs(struct device *dev, struct scatterlist *sg, int nents,
		   enum dma_data_direction dir, struct dma_buf *dma_buf,
		   unsigned long attrs);


static inline int msm_dma_map_sg_lazy(struct device *dev,
			       struct scatterlist *sg, int nents,
			       enum dma_data_direction dir,
			       struct dma_buf *dma_buf)
{
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dma_buf, 0);
}

static inline int msm_dma_map_sg(struct device *dev, struct scatterlist *sg,
				  int nents, enum dma_data_direction dir,
				  struct dma_buf *dma_buf)
{
	unsigned long attrs;

	attrs = DMA_ATTR_NO_DELAYED_UNMAP;
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dma_buf, attrs);
}

void msm_dma_unmap_sg_attrs(struct device *dev, struct scatterlist *sgl,
			    int nents, enum dma_data_direction dir,
			    struct dma_buf *dma_buf, unsigned long attrs);

int msm_dma_unmap_all_for_dev(struct device *dev);


void msm_dma_buf_freed(void *buffer);

#else 

static inline int msm_dma_map_sg_attrs(struct device *dev,
			struct scatterlist *sg, int nents,
			enum dma_data_direction dir, struct dma_buf *dma_buf,
			unsigned long attrs)
{
	return -EINVAL;
}

static inline void
msm_dma_unmap_sg_attrs(struct device *dev, struct scatterlist *sgl,
		       int nents, enum dma_data_direction dir,
		       struct dma_buf *dma_buf, unsigned long attrs)
{
}

static inline int msm_dma_map_sg_lazy(struct device *dev,
			       struct scatterlist *sg, int nents,
			       enum dma_data_direction dir,
			       struct dma_buf *dma_buf)
{
	return -EINVAL;
}

static inline int msm_dma_map_sg(struct device *dev, struct scatterlist *sg,
				  int nents, enum dma_data_direction dir,
				  struct dma_buf *dma_buf)
{
	return -EINVAL;
}

static inline int msm_dma_unmap_all_for_dev(struct device *dev)
{
	return 0;
}

static inline void msm_dma_buf_freed(void *buffer) {}
#endif 

#endif
