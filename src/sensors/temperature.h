/** 
 * @file temperature.h
 * @brief This file contains the functions relative to the temperature sensor
 * All the responses will be in ASCII.
 *
 * @author Bruno Duarte
 *
 * @date 02-03-2024
 * @bug No bugs to report for now
 *
 */

ifndef __TEMPERATURE_H__
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
 * @brief Sends a temperature value.
 *
 * This function defines how we send the value, in this case it is important because the
 * value could be negative.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t send_temp(uint16_t value_temp);

/**
 * @brief Sends the history of the lat 20 temperature values.
 *
 * This function sends the last 20 values, if they exist, otherwise it returns a error.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, and NOT_TWENTY_ENTRIES(2) if 
 * there are not 20 entries
 *
 */
uint16_t send_last_20_temps();
uint16_t check_temps();
uint16_t reset_temps();
uint16_t show_temps();

#endif
