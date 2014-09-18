


#ifndef  APP_SAMPLE128_TASK_H_
#define  APP_SAMPLE128_TASK_H_

#include "rwble_config.h"

#if (BLE_SAMPLE128)
#include "sample128_task.h"

int sample128_create_db_cfm_handler(ke_msg_id_t const msgid,
	                                     struct sample128_create_db_cfm const *param,
																			 ke_task_id_t const dest_id,
																			 ke_task_id_t const src_id);
																						 
int sample128_disable_ind_handler(ke_msg_id_t const msgid,
                                    struct sample128_disable_ind const *param,
                                    ke_task_id_t const dest_id,
                                    ke_task_id_t const src_id);	

int sample128_val_ind_handler(ke_msg_id_t const msgid,
	                               struct sample128_val_ind const *param,
																 ke_task_id_t const dest_id,
																 ke_task_id_t const src_id);		
															 
#endif  //BLE_SAMPLE128

#endif  //APP_SAMPLE128_TASK_H_
