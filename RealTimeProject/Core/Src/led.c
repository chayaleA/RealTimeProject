/*
 * led.c
 *
 *  Created on: Jun 4, 2024
 *      Author: hitmachut
 */
#include "led.h"
#include "distance_sensor.h"
#include "temperature_sensor.h"
#include "FreeRTOS.h"
#include "task.h"
#include "mutex.h"

Led_Status led;
void init_led()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
}
void led_on()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
}
void led_off()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
}
void led_blink(uint32_t frequency)
{
	int i=0;
	while(i<5)
	{
		led_on();
		HAL_Delay(frequency);
		led_off();
		HAL_Delay(frequency);
	}
}
void task_alarm()
{
	while(1)
	{
		if(Distance<10&&Temperature>20)
				led=xOn;
			else if(Distance>20&&Temperature<20)
				led=xOff;
			else if(1)//Distance>10&&Temperature>30)
				led=xBlink;
		lock_led_mutex();
		led_s=led;
		unlock_led_mutex();
		vTaskDelay(100);
	}
}

