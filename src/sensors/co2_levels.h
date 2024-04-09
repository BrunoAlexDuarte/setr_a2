/** 
 * @file CO2 levels.h
 * @brief This file contains the functions relative to the CO2 levels sensor
 * all the responses will be in ascii.
 *
 * @author bruno duarte
 *
 * @date 02-03-2024
 * @bug no bugs to report for now
 *
 */
#ifndef __CO2LEVELS_H__
#define __CO2LEVELS_H__

#include "common_funcs.h"

/**
 * @brief Generates a CO2 levels value
 *
 * This function generates the value to simluate the reading of the sensor.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t generate_co2();

/**
 * @brief Simulates the reading of a CO2 levels value
 *
 * This function calls the function to generate the value and then adds it to the 
 * history of the last 20 readings.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t read_sensor_co2();


/**
 * @brief Cheks if there are more than 20 entries in the CO2 levels sensor history
 *
 * This function sees if there are more than 20 entries in the history
 * 
 * @return Returns a uint16_t that is 1 if there are more than 20 entries and 0 otherwise
 *
 */
uint16_t check_co2levels();

/**
 * @brief Resets the saved CO2 levels in the history.
 *
 * This function resets the history of saved CO2 levels.
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, nothing should fail.
 *
 */
uint16_t reset_co2levels();
uint16_t show_co2levels();
uint16_t get_temperature_history(uint16_t index, uint16_t *value);

#endif
