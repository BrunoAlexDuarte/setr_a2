/** 
 * @file humidity.h
 * @brief This file contains the functions relative to the humidity sensor
 * All the responses will be in ASCII.
 *
 * @author Bruno Duarte
 *
 * @date 02-03-2024
 * @bug No bugs to report for now
 *
 */#ifndef __HUMIDITY_H__
#define __HUMIDITY_H__

#include "common_funcs.h"
/**
 * @brief Generates a humidity value
 *
 * This function generates the value to simluate the reading of the sensor.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t generate_humidity(

/**
 * @brief Simulates the reading of a humidity value
 *
 * This function calls the function to generate the value and then adds it to the 
 * history of the last 20 readings.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */);
uint16_t read_sensor_humidity();

/**
 * @brief Sends a humidity value.
 *
 * This function defines how we send the value, in this case it is important because the
 * value could be negative.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t send_humidity(uint16_t value_humidity);

/**
 * @brief Sends the history of the last 20 humidity values.
 *
 * This function sends the last 20 values, if they exist, otherwise it returns a error.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, and NOT_TWENTY_ENTRIES(2) if 
 * there are not 20 entries
 *
 */
uint16_t send_last_20_humidities();

/**
 * @brief Cheks if there are more than 20 entries in the humidity sensor history
 *
 * This function sees if there are more than 20 entries in the history
 * 
 * @return Returns a uint16_t that is 1 if there are more than 20 entries and 0 otherwise
 *
 */
uint16_t check_humidities();

/**
 * @brief Resets the saved humidities in the history.
 *
 * This function resets the history of saved humidities.
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, nothing should fail.
 *
 */
uint16_t reset_humidities();
uint16_t show_humidities();

#endif
