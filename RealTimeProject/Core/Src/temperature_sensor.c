/*
 * temperature_sensor.c
 *
 *  Created on: May 29, 2024
 *      Author: hitmachut
 */

#include "temperature_sensor.h"
#include "mutex.h"

uint16_t adc_value=0;


Status_t init_temperature_sensor(ADC_HandleTypeDef *adc)
{
	HAL_ADC_Start(adc);
	return xSUCCESS;
}

float read_temperature(ADC_HandleTypeDef *adc)
{
	int x = HAL_ADC_PollForConversion(adc, 1000);
	adc_value = HAL_ADC_GetValue(adc);
	return adc_value*(VOLT_SUPPLY/ANALOG_RANGE)/MILIVOLT_PER_DEGREE;
}

void task_measure_temperature(void *adc)
{
	ADC_HandleTypeDef *pADC = (ADC_HandleTypeDef*)adc;
	while(1)
	{
		unlock_tmpr_mutex();
		Temperature = read_temperature(pADC);
		unlock_tmpr_mutex();
		vTaskDelay(1000);
	}
}

