/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __HWKM_H_
#define __HWKM_H_

#include <stdbool.h>
#include <stddef.h>


#define HWKM_MAX_KEY_SIZE 32

#define HWKM_MAX_CTX_SIZE 64

#define HWKM_MAX_BLOB_SIZE 68



enum hwkm_op {
	
	NIST_KEYGEN = 0,
	
	SYSTEM_KDF,
	
	QFPROM_KEY_RDWR,
	
	KEY_WRAP_EXPORT,
	
	KEY_UNWRAP_IMPORT,
	
	KEY_SLOT_CLEAR,
	
	KEY_SLOT_RDWR,
	
	SET_TPKEY,


	HWKM_MAX_OP,
	HWKM_UNDEF_OP = 0xFF
};


enum hwkm_alg {
	AES128_ECB = 0,
	AES256_ECB = 1,
	DES_ECB = 2,
	TDES_ECB = 3,
	AES128_CBC = 4,
	AES256_CBC = 5,
	DES_CBC = 6,
	TDES_CBC = 7,
	AES128_CCM_TC = 8,
	AES128_CCM_NTC = 9,
	AES256_CCM_TC = 10,
	AES256_CCM_NTC = 11,
	AES256_SIV = 12,
	AES128_CTR = 13,
	AES256_CTR = 14,
	AES128_XTS = 15,
	AES256_XTS = 16,
	SHA1_HMAC = 17,
	SHA256_HMAC = 18,
	AES128_CMAC = 19,
	AES256_CMAC = 20,
	SHA384_HMAC = 21,
	SHA512_HMAC = 22,
	AES128_GCM = 23,
	AES256_GCM = 24,
	KASUMI = 25,
	SNOW3G = 26,
	ZUC = 27,
	PRINCE = 28,
	SIPHASH = 29,
	QARMA64 = 30,
	QARMA128 = 31,

	HWKM_ALG_MAX,

	HWKM_UNDEF_ALG = 0xFF
};


enum hwkm_type {
	KEY_DERIVATION_KEY = 0,
	KEY_WRAPPING_KEY = 1,
	KEY_SWAPPING_KEY = 2,
	TRANSPORT_KEY = 3,
	GENERIC_KEY = 4,

	HWKM_TYPE_MAX,

	HWKM_UNDEF_KEY_TYPE = 0xFF
};


enum hwkm_destination {
	KM_MASTER = 0,
	GPCE_SLAVE = 1,
	MCE_SLAVE = 2,
	PIMEM_SLAVE = 3,
	ICE0_SLAVE = 4,
	ICE1_SLAVE = 5,
	ICE2_SLAVE = 6,
	ICE3_SLAVE = 7,
	DP0_HDCP_SLAVE = 8,
	DP1_HDCP_SLAVE = 9,
	ICEMEM_SLAVE = 10,

	HWKM_DESTINATION_MAX,

	HWKM_UNDEF_DESTINATION = 0xFF
};


enum hwkm_security_level {
	
	SW_KEY = 0,
	
	MANAGED_KEY = 1,
	
	HW_KEY = 2,

	HWKM_SECURITY_LEVEL_MAX,

	HWKM_UNDEF_SECURITY_LEVEL = 0xFF
};

struct hwkm_key_policy {
	bool km_by_spu_allowed;
	bool km_by_modem_allowed;
	bool km_by_nsec_allowed;
	bool km_by_tz_allowed;

	enum hwkm_alg alg_allowed;

	bool enc_allowed;
	bool dec_allowed;

	enum hwkm_type key_type;
	u8 kdf_depth;

	bool wrap_export_allowed;
	bool swap_export_allowed;

	enum hwkm_security_level security_lvl;

	enum hwkm_destination hw_destination;

	bool wrap_with_tpk_allowed;
};

struct hwkm_bsve {
	bool enabled;
	bool km_key_policy_ver_en;
	bool km_apps_secure_en;
	bool km_msa_secure_en;
	bool km_lcm_fuse_en;
	bool km_boot_stage_otp_en;
	bool km_swc_en;
	bool km_child_key_policy_en;
	bool km_mks_en;
	u64 km_fuse_region_sha_digest_en;
};

struct hwkm_keygen_cmd {
	u8 dks;					
	struct hwkm_key_policy policy;		
};

struct hwkm_rdwr_cmd {
	uint8_t slot;			
	bool is_write;			
	struct hwkm_key_policy policy;	
	uint8_t key[HWKM_MAX_KEY_SIZE];	
	size_t sz;			
};

struct hwkm_kdf_cmd {
	uint8_t dks;			
	uint8_t kdk;			
	uint8_t mks;			
	struct hwkm_key_policy policy;	
	struct hwkm_bsve bsve;		
	uint8_t ctx[HWKM_MAX_CTX_SIZE];	
	size_t sz;			
};

struct hwkm_set_tpkey_cmd {
	uint8_t sks;			
};

struct hwkm_unwrap_cmd {
	uint8_t dks;			
	uint8_t kwk;			
	uint8_t wkb[HWKM_MAX_BLOB_SIZE];
	uint8_t sz;			
};

struct hwkm_wrap_cmd {
	uint8_t sks;			
	uint8_t kwk;			
	struct hwkm_bsve bsve;		
};

struct hwkm_clear_cmd {
	uint8_t dks;			
	bool is_double_key;		
};


struct hwkm_cmd {
	enum hwkm_op op;		
	union 
	{
		struct hwkm_keygen_cmd keygen;
		struct hwkm_rdwr_cmd rdwr;
		struct hwkm_kdf_cmd kdf;
		struct hwkm_set_tpkey_cmd set_tpkey;
		struct hwkm_unwrap_cmd unwrap;
		struct hwkm_wrap_cmd wrap;
		struct hwkm_clear_cmd clear;
	};
};

struct hwkm_rdwr_rsp {
	struct hwkm_key_policy policy;	
	uint8_t key[HWKM_MAX_KEY_SIZE];	
	size_t sz;			
};

struct hwkm_wrap_rsp {
	uint8_t wkb[HWKM_MAX_BLOB_SIZE];	
	size_t sz;				
};

struct hwkm_rsp {
	u32 status;
	union 
	{
		struct hwkm_rdwr_rsp rdwr;
		struct hwkm_wrap_rsp wrap;
	};
};

enum hwkm_master_key_slots {
	
	NKDK_L1 = 0,
	PKDK_L1 = 1,
	SKDK_L1 = 2,
	UKDK_L1 = 3,

	
	TZ_NKDK_L2 = 4,
	TZ_PKDK_L2 = 5,
	TZ_SKDK_L2 = 6,
	MODEM_PKDK_L2 = 7,
	MODEM_SKDK_L2 = 8,
	TZ_UKDK_L2 = 9,

	
	TPKEY_EVEN_SLOT = 10,
	TPKEY_KEY_ODD_SLOT = 11,

	
	MASTER_GENERIC_SLOTS_START,

	UNDEF_SLOT = 0xFF
};

#if IS_ENABLED(CONFIG_QTI_HW_KEY_MANAGER)
int qti_hwkm_handle_cmd(struct hwkm_cmd *cmd, struct hwkm_rsp *rsp);
int qti_hwkm_clocks(bool on);
int qti_hwkm_init(void);
#else
static inline int qti_hwkm_add_req(struct hwkm_cmd *cmd,
				   struct hwkm_rsp *rsp)
{
	return -EOPNOTSUPP;
}
static inline int qti_hwkm_clocks(bool on)
{
	return -EOPNOTSUPP;
}
static inline int qti_hwkm_init(void)
{
	return -EOPNOTSUPP;
}
#endif 
#endif 
