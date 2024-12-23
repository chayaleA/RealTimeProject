/*
 * task_manager.c
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */
#include "task_manager.h"
#include "led.h"

static TaskHandle_t * ReadDistanceTask;
static TaskHandle_t * MeasureTempTask;

void create_tasks(TIM_HandleTypeDef *timer, ADC_HandleTypeDef *adc)
{
	create_read_distance_task(timer);
	create_measure_temperature_task(adc);
	create_alarm_task();
	create_led_operate();
}
void create_read_distance_task(TIM_HandleTypeDef *timer)
{
	xTaskCreate(task_periodic_measure_distance, "Read Distance", MIN_QUEUE_DEPTH, timer, READ_DISTANCE_TASK_PRIORITY, ReadDistanceTask);
}
void create_measure_temperature_task(ADC_HandleTypeDef *adc)
{
	xTaskCreate(task_measure_temperature, "Read Temp", MIN_QUEUE_DEPTH,	adc, MEASURE_TEMP_TASK_PRIORITY, MeasureTempTask);
}
void create_alarm_task()
{
	xTaskCreate(task_alarm,"Alarm Task",MIN_QUEUE_DEPTH,NULL,ALARM_TASK_PRIORITY,NULL);
}
void task_led_operate()
{
	while(1)
	{
//		switch(led_s)
//			{
//				case xOn:led_on();break;
//				case xOff:led_off();break;
//				case xBlink:led_blink(FREQUENCY);break;
//			}
		if(led_s==xOn)
			led_on();
		else if(led_s==xOff)
			led_off();
		else
			led_blink(FREQUENCY);
		vTaskDelay(50);

	}
}
void create_led_operate()
{
	xTaskCreate(task_led_operate,"Led Operate",MIN_QUEUE_DEPTH,NULL,LED_OPERATE_PRIORITY,NULL);
}

