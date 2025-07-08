

#ifndef SEC_QUEST_BPS_CLASSIFIER_H
#define SEC_QUEST_BPS_CLASSIFIER_H

#define QUEST_BPS_MAX_QUICKBUILD_LEN	10
#define QUEST_BPS_INIT_MAGIC1				0xABCDABCD
#define QUEST_BPS_CLASSIFIER_MAGIC2		0xDCBADCBA


struct upload_info {
	int sp;
	int wp;
	int dp;
	int kp;
	int mp;
	int tp;
	int cp;
};

struct bps_info {
	
	unsigned int magic[2];

	
	struct upload_info up_cnt;

	
	int pc_lr_cnt;
	int pc_lr_last_idx;
	int tzerr_cnt;
	int klg_cnt;

	
	int dn_cnt;
	char build_id[QUEST_BPS_MAX_QUICKBUILD_LEN];
	int rbps_magic;
	int rbpsp;
	int rbpsf;
	int n1bps;
	int n2bps;
	int n3bps;
	int n4bps;
	
	int fac_info;

	
	struct upload_info semi_asm_up_cnt;
	int semi_asm_pc_lr_cnt;
	int semi_asm_pc_lr_last_idx;

	
	struct upload_info asm_up_cnt;
	int asm_pc_lr_cnt;
	int asm_pc_lr_last_idx;
};

static bool sec_quest_bps_env_initialized;
#endif
