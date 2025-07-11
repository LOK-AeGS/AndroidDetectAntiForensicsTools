/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __LINUX_BIO_CRYPT_CTX_H
#define __LINUX_BIO_CRYPT_CTX_H

#include <linux/string.h>

enum blk_crypto_mode_num {
	BLK_ENCRYPTION_MODE_INVALID,
	BLK_ENCRYPTION_MODE_AES_256_XTS,
	BLK_ENCRYPTION_MODE_AES_128_CBC_ESSIV,
	BLK_ENCRYPTION_MODE_ADIANTUM,
	BLK_ENCRYPTION_MODE_MAX,
};

#ifdef CONFIG_BLOCK
#include <linux/blk_types.h>

#ifdef CONFIG_BLK_INLINE_ENCRYPTION

#define BLK_CRYPTO_MAX_KEY_SIZE		64
#define BLK_CRYPTO_MAX_WRAPPED_KEY_SIZE		128


struct blk_crypto_key {
	enum blk_crypto_mode_num crypto_mode;
	unsigned int data_unit_size;
	unsigned int data_unit_size_bits;
	unsigned int size;

	
#define BLK_CRYPTO_KEY_HASH_MASK		0xffffff
#define BLK_CRYPTO_KEY_DUN_BYTES_SHIFT		24
	unsigned int hash;

	bool is_hw_wrapped;
	u8 raw[BLK_CRYPTO_MAX_WRAPPED_KEY_SIZE];
};

#define BLK_CRYPTO_MAX_IV_SIZE		32
#define BLK_CRYPTO_DUN_ARRAY_SIZE	(BLK_CRYPTO_MAX_IV_SIZE/sizeof(u64))

static inline void
blk_crypto_key_set_hash_and_dun_bytes(struct blk_crypto_key *key,
				      u32 hash, unsigned int dun_bytes)
{
	key->hash = (dun_bytes << BLK_CRYPTO_KEY_DUN_BYTES_SHIFT) |
		    (hash & BLK_CRYPTO_KEY_HASH_MASK);
}

static inline u32
blk_crypto_key_hash(const struct blk_crypto_key *key)
{
	return key->hash & BLK_CRYPTO_KEY_HASH_MASK;
}

static inline unsigned int
blk_crypto_key_dun_bytes(const struct blk_crypto_key *key)
{
	return key->hash >> BLK_CRYPTO_KEY_DUN_BYTES_SHIFT;
}


struct bio_crypt_ctx {
	const struct blk_crypto_key	*bc_key;
	int				bc_keyslot;

	
	u64				bc_dun[BLK_CRYPTO_DUN_ARRAY_SIZE];

	
	struct keyslot_manager		*bc_ksm;
	bool is_ext4;
};

int bio_crypt_ctx_init(void);

struct bio_crypt_ctx *bio_crypt_alloc_ctx(gfp_t gfp_mask);

void bio_crypt_free_ctx(struct bio *bio);

static inline bool bio_has_crypt_ctx(struct bio *bio)
{
	return bio->bi_crypt_context;
}

void bio_crypt_clone(struct bio *dst, struct bio *src, gfp_t gfp_mask);

static inline void bio_crypt_set_ctx(struct bio *bio,
				     const struct blk_crypto_key *key,
				     u64 dun[BLK_CRYPTO_DUN_ARRAY_SIZE],
				     gfp_t gfp_mask)
{
	struct bio_crypt_ctx *bc = bio_crypt_alloc_ctx(gfp_mask);

	bc->bc_key = key;
	memcpy(bc->bc_dun, dun, sizeof(bc->bc_dun));
	bc->bc_ksm = NULL;
	bc->bc_keyslot = -1;
	bc->is_ext4 = false;

	bio->bi_crypt_context = bc;
}

void bio_crypt_ctx_release_keyslot(struct bio_crypt_ctx *bc);

int bio_crypt_ctx_acquire_keyslot(struct bio_crypt_ctx *bc,
				  struct keyslot_manager *ksm);

struct request;
bool bio_crypt_should_process(struct request *rq);

static inline bool bio_crypt_dun_is_contiguous(const struct bio_crypt_ctx *bc,
					       unsigned int bytes,
					u64 next_dun[BLK_CRYPTO_DUN_ARRAY_SIZE])
{
	int i = 0;
	unsigned int inc = bytes >> bc->bc_key->data_unit_size_bits;

	while (i < BLK_CRYPTO_DUN_ARRAY_SIZE) {
		if (bc->bc_dun[i] + inc != next_dun[i])
			return false;
		inc = ((bc->bc_dun[i] + inc)  < inc);
		i++;
	}

	return true;
}


static inline void bio_crypt_dun_increment(u64 dun[BLK_CRYPTO_DUN_ARRAY_SIZE],
					   unsigned int inc)
{
	int i = 0;

	while (inc && i < BLK_CRYPTO_DUN_ARRAY_SIZE) {
		dun[i] += inc;
		inc = (dun[i] < inc);
		i++;
	}
}

static inline void bio_crypt_advance(struct bio *bio, unsigned int bytes)
{
	struct bio_crypt_ctx *bc = bio->bi_crypt_context;

	if (!bc)
		return;

	bio_crypt_dun_increment(bc->bc_dun,
				bytes >> bc->bc_key->data_unit_size_bits);
}

bool bio_crypt_ctx_compatible(struct bio *b_1, struct bio *b_2);

bool bio_crypt_ctx_mergeable(struct bio *b_1, unsigned int b1_bytes,
			     struct bio *b_2);

#else 
static inline int bio_crypt_ctx_init(void)
{
	return 0;
}

static inline bool bio_has_crypt_ctx(struct bio *bio)
{
	return false;
}

static inline void bio_crypt_clone(struct bio *dst, struct bio *src,
				   gfp_t gfp_mask) { }

static inline void bio_crypt_free_ctx(struct bio *bio) { }

static inline void bio_crypt_advance(struct bio *bio, unsigned int bytes) { }

static inline bool bio_crypt_ctx_compatible(struct bio *b_1, struct bio *b_2)
{
	return true;
}

static inline bool bio_crypt_ctx_mergeable(struct bio *b_1,
					   unsigned int b1_bytes,
					   struct bio *b_2)
{
	return true;
}

#endif 

#if IS_ENABLED(CONFIG_DM_DEFAULT_KEY)
static inline void bio_set_skip_dm_default_key(struct bio *bio)
{
	bio->bi_skip_dm_default_key = true;
}

static inline bool bio_should_skip_dm_default_key(const struct bio *bio)
{
	return bio->bi_skip_dm_default_key;
}

static inline void bio_clone_skip_dm_default_key(struct bio *dst,
						 const struct bio *src)
{
	dst->bi_skip_dm_default_key = src->bi_skip_dm_default_key;
}
#else 
static inline void bio_set_skip_dm_default_key(struct bio *bio)
{
}

static inline bool bio_should_skip_dm_default_key(const struct bio *bio)
{
	return false;
}

static inline void bio_clone_skip_dm_default_key(struct bio *dst,
						 const struct bio *src)
{
}
#endif 

#endif 

#endif 
