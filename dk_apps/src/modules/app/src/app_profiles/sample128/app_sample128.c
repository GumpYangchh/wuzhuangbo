

#include "rwip_config.h"     // SW configuration

#if (BLE_SAMPLE128)
#include "app_sample128.h"
#include "sample128_task.h"
#include "app.h"
#include "periph_setup.h"

app_sample128_leds_state leds_state __attribute__((section("retention_mem_area0"),zero_init)); //@RETENTION MEMORY

void app_sample128_init(void)
{
    return;
}


void app_sample128_create_db(void)
{
    // Add sample128 in the database
    struct sample128_create_db_req *req = KE_MSG_ALLOC(SAMPLE128_CREATE_DB_REQ,
                                                  TASK_SAMPLE128, TASK_APP,
                                                  sample128_create_db_req);
    req->features = 1;
    

    // Send the message
    ke_msg_send(req);
}
void app_sample128_enable(GPIO_PORT led3_port,GPIO_PIN led3_pin,GPIO_PORT led4_port,GPIO_PIN led4_pin)
//void app_sample128_enable(void)
{
	  leds_state.port_led3 = led3_port; 
	  leds_state.pin_led3 = led3_pin;
	
	  leds_state.port_led4 = led4_port; 
	  leds_state.pin_led4 = led4_pin;
	
	  leds_state.flag = 0;
	
	  // Allocate the message
    struct sample128_enable_req * req = KE_MSG_ALLOC(SAMPLE128_ENABLE_REQ, TASK_SAMPLE128, TASK_APP,
                                                 sample128_enable_req);
		req->conhdl = app_env.conhdl;
		req->sec_lvl = PERM(SVC, ENABLE);
		
		/// characteristic 1 value
    req->sample128_1_val = 0;
    
    /// characteristic 2 value
    req->sample128_2_val = 0;
    
    /// char 2 Ntf property status
    req->feature = 0;

		
		// Send the message
    ke_msg_send(req);
}

void app_sample128_start_leds(void)
{
		if(1 == leds_state.flag)
		{
        //GPIO_SetActive( leds_state.port_led3, leds_state.pin_led3);
			  GPIO_SetActive(leds_state.port_led4, leds_state.pin_led4);
			  //GPIO_SetInactive(leds_state.port_led4, leds_state.pin_led4);
			  GPIO_SetInactive( leds_state.port_led3, leds_state.pin_led3);
			  //GPIO_ConfigurePin( GPIO_LED3_PORT, GPIO_LED3_PIN, OUTPUT, PID_GPIO, true );
			  
    }
	  else if(0 == leds_state.flag)
		{
        GPIO_SetInactive(leds_state.port_led4, leds_state.pin_led4);
			  //GPIO_SetInactive( leds_state.port_led3, leds_state.pin_led3);
			  GPIO_SetActive( leds_state.port_led3, leds_state.pin_led3);
			  //GPIO_ConfigurePin( GPIO_LED3_PORT, GPIO_LED3_PIN, OUTPUT, PID_GPIO, false );
			  //GPIO_ConfigurePin( GPIO_LED3_PORT, GPIO_LED3_PIN, OUTPUT, PID_GPIO, false );
	      //GPIO_ConfigurePin( GPIO_LED4_PORT, GPIO_LED4_PIN, OUTPUT, PID_GPIO, false );
			
			  
	  }
}

#endif  //BLE_SAMPLE128
