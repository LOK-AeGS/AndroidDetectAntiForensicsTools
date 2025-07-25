/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef PFK_H_
#define PFK_H_

#include <linux/bio.h>
#include <crypto/ice.h>

struct ice_crypto_setting;

#ifdef CONFIG_PFK


#define BLK_ENCRYPTION_KEY_SIZE_AES_256_XTS 64

struct blk_encryption_key {
	u8 raw[BLK_ENCRYPTION_KEY_SIZE_AES_256_XTS];
};

int pfk_load_key_start(const struct bio *bio, struct ice_device *ice_dev,
			struct ice_crypto_setting *ice_setting,
				bool *is_pfe, bool async);
int pfk_load_key_end(const struct bio *bio, struct ice_device *ice_dev,
			bool *is_pfe);
int pfk_fbe_clear_key(const unsigned char *key, size_t key_size,
		const unsigned char *salt, size_t salt_size);
bool pfk_allow_merge_bio(const struct bio *bio1, const struct bio *bio2);
void pfk_clear_on_reset(struct ice_device *ice_dev);
int pfk_initialize_key_table(struct ice_device *ice_dev);
int pfk_remove(struct ice_device *ice_dev);

#else
static inline int pfk_load_key_start(const struct bio *bio,
	struct ice_crypto_setting *ice_setting, bool *is_pfe, bool async)
{
	return -ENODEV;
}

static inline int pfk_load_key_end(const struct bio *bio, bool *is_pfe)
{
	return -ENODEV;
}

static inline bool pfk_allow_merge_bio(const struct bio *bio1,
		const struct bio *bio2)
{
	return true;
}

static inline int pfk_fbe_clear_key(const unsigned char *key, size_t key_size,
			const unsigned char *salt, size_t salt_size)
{
	return -ENODEV;
}

static inline void pfk_clear_on_reset(void)
{}

static inline int pfk_initialize_key_table(struct ice_device *ice_dev)
{
	return -ENODEV;
}
static inline int pfk_remove(struct ice_device *ice_dev)
{
	return -ENODEV;
}

#endif 

#endif 
