

#include "rwip_config.h"

#if (BLE_APP_PRESENT)

#if (BLE_SAMPLE128)
#include "app_sample128_task.h"
#include "app_api.h"
#include "periph_setup.h"


int sample128_create_db_cfm_handler(ke_msg_id_t const msgid,
	                                     struct sample128_create_db_cfm const *param,
																			 ke_task_id_t const dest_id,
																			 ke_task_id_t const src_id)
{
    // Inform the Application Manager
    struct app_module_init_cmp_evt *cfm = KE_MSG_ALLOC(APP_MODULE_INIT_CMP_EVT,
                                                           TASK_APP, TASK_APP,
                                                           app_module_init_cmp_evt);
		cfm->status = param->status;

    ke_msg_send(cfm);

    return (KE_MSG_CONSUMED);
}


int sample128_disable_ind_handler(ke_msg_id_t const msgid,
                                    struct sample128_disable_ind const *param,
                                    ke_task_id_t const dest_id,
                                    ke_task_id_t const src_id)
{
		return (KE_MSG_CONSUMED);																
}


int sample128_val_ind_handler(ke_msg_id_t const msgid,
	                               struct sample128_val_ind const *param,
																 ke_task_id_t const dest_id,
																 ke_task_id_t const src_id)
{
		//leds_state.flag = param->val;
    app_sample128_start_leds();
			
    return (KE_MSG_CONSUMED);
}

																		
#endif //(BLE_BATT_SERVER)

#endif //(BLE_APP_PRESENT)
