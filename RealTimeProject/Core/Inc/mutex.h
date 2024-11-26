/*
 * mutex.h
 *
 *  Created on: Jun 19, 2024
 *      Author: hitmachut
 */

#ifndef INC_MUTEX_H_
#define INC_MUTEX_H_

#include "FreeRTOS.h"
#include "semphr.h"

#define MAX_DELAY 100

static SemaphoreHandle_t tmprMutex;
static SemaphoreHandle_t distMutex;
static SemaphoreHandle_t ledMutex;

void init_mutex();
void lock_tmpr_mutex();
void unlock_tmpr_mutex();
void lock_dist_mutex();
void unlock_dist_mutex();
void lock_led_mutex();
void unlock_led_mutex();


#endif /* INC_MUTEX_H_ */
