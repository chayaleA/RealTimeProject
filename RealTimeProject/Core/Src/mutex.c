/*
 * mutex.c
 *
 *  Created on: Jun 19, 2024
 *      Author: hitmachut
 */

#include "mutex.h"

void init_mutex()
{
	tmprMutex = xSemaphoreCreateMutex();
	distMutex = xSemaphoreCreateMutex();
	ledMutex = xSemaphoreCreateMutex();
}
void lock_tmpr_mutex()
{
	xSemaphoreTake(tmprMutex, MAX_DELAY);
}
void unlock_tmpr_mutex()
{
	xSemaphoreGive(tmprMutex);
}
void lock_dist_mutex()
{
	xSemaphoreTake(distMutex, MAX_DELAY);
}
void unlock_dist_mutex()
{
	xSemaphoreGive(distMutex);
}
void lock_led_mutex()
{
	xSemaphoreTake(ledMutex, MAX_DELAY);
}
void unlock_led_mutex()
{
	xSemaphoreGive(ledMutex);
}

