/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _MSM_KGSL_H
#define _MSM_KGSL_H

#define KGSL_DEVICE_3D0 0


void *kgsl_pwr_limits_add(u32 id);
void kgsl_pwr_limits_del(void *limit);
int kgsl_pwr_limits_set_freq(void *limit, unsigned int freq);
int kgsl_pwr_limits_set_gpu_fmax(void *limit, unsigned int freq);
void kgsl_pwr_limits_set_default(void *limit);
unsigned int kgsl_pwr_limits_get_freq(u32 id);

#endif 
