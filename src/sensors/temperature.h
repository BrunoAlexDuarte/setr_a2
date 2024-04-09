/** 
 * @file temperature.h
 * @brief This file contains the functions relative to the temperature sensor
 * all the responses will be in ascii.
 *
 * @author bruno duarte
 *
 * @date 02-03-2024
 * @bug no bugs to report for now
 *
 */

#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include "common_funcs.h"

/**
 * @brief Generates a temperature value
 *
 * This function generates the value to simluate the reading of the sensor.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t generate_temp();

/**
 * @brief Simulates the reading of a temperature value
 *
 * This function calls the function to generate the value and then adds it to the 
 * history of the last 20 readings.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t read_sensor_temp();

/**
 * @brief Cheks if there are more than 20 entries in the temperature sensor history
 *
 * This function sees if there are more than 20 entries in the history
 * 
 * @return Returns a uint16_t that is 1 if there are more than 20 entries and 0 otherwise
 *
 */
uint16_t check_temps();

/**
 * @brief Resets the saved temperatures in the history.
 *
 * This function resets the history of saved temperatures.
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, nothing should fail.
 *
 */
uint16_t reset_temps();
uint16_t show_temps();
uint16_t get_co2_history(uint16_t index, uint16_t *value);

#endif
