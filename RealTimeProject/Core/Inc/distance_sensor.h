/*
 * distance_sensor.h
 *
 * Module for handling reading the distance from HC-SR04 sensor
 *
 */

 #ifndef INC_DISTANCE_SENSOR_H_
 #define INC_DISTANCE_SENSOR_H_

 #include "main.h"
 //#include "task_manager.h"

 #define TRIG_PIN GPIO_PIN_8
 #define TRIG_PORT GPIOA
 #define ECHO_PIN GPIO_PIN_9
 #define ECHO_PORT GPIOA
 #define TIMER_GAP 10
 #define SPEED_OF_SOUND 0.0343

 static float Distance;

 Status_t init_distance_sensor(TIM_HandleTypeDef *timer);

 float read_distance(TIM_HandleTypeDef *sensorTimer);

 void task_periodic_measure_distance(void *timer);

 #endif
