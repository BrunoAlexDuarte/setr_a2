/** 
 * @file smart_sensor.h
 * @brief This file contains the functions to interact with the smart sensor.
 * All the responses will be in ASCII.
 *
 * @author Bruno Duarte
 *
 * @date 02-03-2024
 * @bug No bugs to report for now
 *
 */

#ifndef __SMART_SENSOR_H__
#define __SMART_SENSOR_H__

#include "temperature.h"
#include "humidity.h"
#include "co2_levels.h"


/*
 * As mensagens começam por # e acabam em !
 * Depois temos um byte para o comando CMD
 * Depois temos todos os dados necessários para executar os comandos DATA
 * Por fim temos um byte checksum, tem o tamanho de todos os bytes entre
 * o CMD e DATA
 * */


/**
 * @brief Reads a value from all the sensors
 *
 * This functions reads a value from the temperature, humidity and CO2 sensors 
 * and sends it. As we don't have a real sensor, this funcion also calls a function to 
 * generate a value to each sensor.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 *
 */
uint16_t read_value_sensor_all(); //Command A 

/**
 * @brief Reads a value from a specific sensor
 *
 * This functions reads a value from the temperature, humidity or CO2 sensors, depending 
 * on wich one we want, and sends it. As we don't have a real sensor, this funcion also calls a function to 
 * generate a value to each sensor.
 * @param[in] sensor A char to identify which sensor we want. It is "T" for temperature, 
 * "H" for humidity and "C" for CO2
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, and NO_SENSOR(1) if we
 * inputed a char that does not refer to any sensor.
 *
 *
 */
uint16_t read_value_sensor(unsigned char sensor); //Command P 

/**
 * @brief List the last 20 values from a sensor
 *
 * This function sends the last 20 values that we read(generated truly) from a sensor.
 * 
 * @param[in] sensor A char to identify which sensor we want. It is "T" for temperature, 
 * "H" for humidity and "C" for CO2
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, and NO_SENSOR(1) if we
 * inputed a char that does not refer to any sensor, and NOT_TWENTY_ENTRIES(2) if we didn't
 * have at least twenty entries in the history.
 *
 *
 */
uint16_t send_last_20_samples(unsigned char sensor);

/**
 * @brief List the last 20 values from all sensors
 *
 * This function sends the last 20 values that we read(generated truly) from all sensors.
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails and 
 * NOT_TWENTY_ENTRIES(2) if we didn't have at least twenty entries in the history of 
 * at least one sensor.
 *
 *
 */
uint16_t send_last_20_samples_all();

/**
 * @brief Resets the history for all the sensors
 *
 * This function resets the history of values for all the sensors
 * 
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, although the function
 * should never fail
 *
 *
 */
uint16_t reset_history_all(); //Comand R

/**
 * @brief Resets the history for a specific sensor
 *
 * This function resets the history of values for a specific sensor.
 * 
 * @param[in] sensor A char to identify which sensor we want. It is "T" for temperature, 
 * "H" for humidity and "C" for CO2
 *
 * @return Returns a uint16_t that is SUCESS(0) if nothing fails, and NO_SENSOR(1) if we
 * inputed a char that does not refer to any sensor.
 *
 *
 */
uint16_t reset_history(unsigned char sensor); //Comand R





#endif

