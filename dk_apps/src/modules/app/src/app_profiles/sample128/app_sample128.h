


#ifndef  APP_SAMPLE128_H_
#define  APP_SAMPLE128_H_

#include "rwip_config.h"     // SW Configuration
#if  (BLE_SAMPLE128)
#include "stdint.h"          // Standard Integer Definition
#include "gpio.h"


typedef struct
{
		bool   flag;
	
	  GPIO_PORT port_led3; //P1_2
		GPIO_PIN  pin_led3;  //P1_2
	
	  GPIO_PORT port_led4; //P1_3
		GPIO_PIN  pin_led4;  //P1_3
}app_sample128_leds_state;


void app_sample128_init(void);


void app_sample128_create_db(void);

//void app_sample128_enable(void);
void app_sample128_enable(GPIO_PORT led3_port,GPIO_PIN led3_pin,GPIO_PORT led4_port,GPIO_PIN led4_pin);

void app_sample128_start_leds(void);

extern app_sample128_leds_state leds_state;



#endif  //BLE_SAMPLE128

#endif  //APP_SAMPLE128_H_
