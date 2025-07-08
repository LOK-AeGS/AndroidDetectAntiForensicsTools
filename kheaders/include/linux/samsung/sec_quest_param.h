

#ifndef SEC_QUEST_PARAM_H
#define SEC_QUEST_PARAM_H

void quest_print_param_quest_data(void);
void quest_load_param_quest_data(void);
void quest_sync_param_quest_data(void);
void quest_clear_param_quest_data(void);
void quest_initialize_curr_step(void);
void quest_load_param_quest_ddr_result_data(void);
void quest_sync_param_quest_ddr_result_data(void);
void quest_load_param_api_gpio_test(void);
void quest_sync_param_api_gpio_test(void);
void quest_load_param_api_gpio_test_result(void);
void quest_sync_param_api_gpio_test_result(void);
#ifdef CONFIG_SEC_QUEST_BPS_CLASSIFIER
void quest_load_param_quest_bps_data(void);
void quest_sync_param_quest_bps_data(void);
#endif

#endif
