/*
 * led.h
 *
 *  Created on: Jun 4, 2024
 *      Author: hitmachut
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

typedef enum Led_Status{
	xOn,
	xOff,
	xBlink
}Led_Status;
static Led_Status led_s;
void init_led(void);
void led_on(void);
void led_off(void);
void led_blink(uint32_t frequency);
void task_alarm();
#endif /* INC_LED_H_ */
