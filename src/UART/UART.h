/** 
 * @file UART.h
 * @brief UART declarations.
 *
 * This file contains declarations for simulating UART (Universal Asynchronous Receiver-Transmitter) functionality.
 * It includes structures, function prototypes, and descriptions of their functionalities.
 *
 * @author Diogo Lapa
 *
 * @date 28-03-2024
 * @bug No bugs to report for now
 *
 * @note This file is a simulation of UART functionality and does not interact with real hardware.
 */

#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>

#include "../sensors/temperature.h"
#include "../sensors/humidity.h"
#include "../sensors/co2_levels.h"

#define CHECKSUM_MATCH 0
#define SUCCESS 0
#define VALID_COMMAND 0
#define BYTE_ADDED_TO_BUFFER 0
#define FULL_COMMAND_SENT 0
#define FULL_COMMAND_RECEIVED 0
#define INVALID_COMMAND 1
#define CHECKSUM_MISMATCH 2
#define REGEX_COMPILE_FAIL 3
#define REGEX_MATCH_FAIL 4
#define UNKNOWN_SENSOR 5
#define BUFFER_SIZE 512
#define SOF_SYM '#'	        /* Start of Frame Symbol */
#define EOF_SYM '!'         /* End of Frame Symbol */

/**
 * @brief Receive Byte
 *
 * A byte of data (unsigned char) is added to the rx buffer and performs some processing.
 *
 * @param[in] input The byte of data being added to the buffer.
 * 
 * @return Indicates the result of processing the byte.
 *         FULL_COMMAND_RECEIVED - the added character completes a valid command.
 *         BYTE_ADDED_TO_BUFFER - bytes is added to the buffer successfully.
 *         INVALID_COMMAND - the added character creates an invalid command.
 *
 * @note This function is a placeholder for receiving data in a simulated environment.
 *       The actual implementation may vary depending on the application and hardware.
 *       It's expected to be replaced or customized to suit specific requirements.
 */
uint16_t receive_byte(unsigned char input);

/**
 * @brief Send Byte
 *
 * A byte of data (unsigned char) is added to the tx buffer and performs some processing.
 *
 * @param[in] input The byte of data being added to the buffer.
 * 
 * @return Indicates the result of processing the byte.
 *         FULL_COMMAND_RECEIVED - the added character completes a valid command.
 *         BYTE_ADDED_TO_BUFFER - bytes is added to the buffer successfully.
 *         INVALID_COMMAND - the added character creates an invalid command.
 *
 * @note This function is a placeholder for sending data in a simulated environment.
 *       The actual implementation may vary depending on the application and hardware.
 *       It's expected to be replaced or customized to suit specific requirements.
 */
//uint16_t send_byte(unsigned char input);

/**
 * @brief Validate Command
 *
 * Validates whether the given command is valid or not.
 * This function checks if the command is recognized and conforms to the expected format.
 *
 * @param command String representing the command to be validated.
 *
 * @return Indicates the result of the command validation.
 *         REGEX_COMPILE_FAIL - fails to compile the regex pattern.
 *         VALID_COMMAND - the command is valid.
 *         INVALID_COMMAND - the command is invalid.
 *         REGEX_MATCH_FAIL - fails the matching process.
 *
 * @note This function verifies the validity of a command based on predefined criteria.
 *       It's expected to be customized according to the specific command set and requirements of the application.
 *       The implementation may involve parsing the command string, comparing it against a list of valid commands,
 *       and checking if the command parameters meet certain conditions.
 */
uint16_t validate_command(char *command);

/**
 * @brief Validate Checksum
 *
 * Validates the checksum of the given command to ensure data integrity.
 * This function computes the checksum of the command and compares it with the provided checksum value.
 *
 * @param command String representing the command with its checksum.
 *
 * @return Indicates the result of the checksum validation.
 *         CHECKSUM_MATCH - the checksum provided matches.
 *         CHECKSUM_MISMATCH - the checksum provided does not match.  
 * 
 * @note This function is responsible for verifying the integrity of the command data by validating its checksum.
 *       The implementation typically involves computing the checksum of the command (excluding the checksum itself)
 *       and comparing it with the checksum value provided within the command string.
 *       It's essential to ensure that the checksum algorithm and validation logic align with the protocol requirements
 *       and the specific checksum calculation method used by the sender.
 */
uint16_t validate_checksum(char *command, uint16_t rx_occupied_bytes);

/**
 * @brief Clear Receive Buffer
 *
 * Clears the receive buffer.
 * This function resets the number of occupied bytes.
 * 
 * @note This function is used to clear the receive buffer, typically in scenarios where the received data
 *       is no longer needed or when it's necessary to start afresh with an empty buffer.
 *       It's important to note that clearing the buffer will result in the loss of any unread data.
 *       Care should be taken to ensure that clearing the buffer at the right time does not lead to data loss
 *       or interfere with the intended operation of the application.
 */
void clear_rx_buffer();

/**
 * @brief Clear Sending Buffer
 *
 * Clears the sending buffer.
 * This function resets the number of occupied bytes.
 * 
 * @note This function is used to clear the sending buffer, typically in scenarios where the sending data
 *       is no longer needed or when it's necessary to start afresh with an empty buffer.
 *       It's important to note that clearing the buffer will result in the loss of any unread data.
 *       Care should be taken to ensure that clearing the buffer at the right time does not lead to data loss
 *       or interfere with the intended operation of the application.
 */
//void clear_tx_buffer();

uint16_t calculate_checksum();
uint16_t send_byte(unsigned char input);
void clear_tx_buffer();
void PrintTxBuffer();
unsigned char *returnTxBuffer();

//debug
void PrintRxBuffer();
unsigned char *returnRxBuffer();
uint16_t send_number(uint16_t number);

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
 * @brief Sends the history of the last 20 temperature values.
 *
 * This function sends the last 20 values, if they exist, otherwise it returns a error.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, and NOT_TWENTY_ENTRIES(2) if 
 * there are not 20 entries
 *
 */
uint16_t send_last_20_temps();

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
 * @brief Sends a CO2 levels value.
 *
 * This function defines how we send the value, in this case it is important because the
 * value could be negative.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, although the function should never fail.
 *
 */
uint16_t send_co2(uint16_t value_co2);

/**
 * @brief Sends the history of the last 20 CO2 levels values.
 *
 * This function sends the last 20 values, if they exist, otherwise it returns a error.
 * 
 * @return Returns a uint16_t that is 0 in case of SUCESS, and NOT_TWENTY_ENTRIES(2) if 
 * there are not 20 entries
 *
 */
uint16_t send_last_20_co2levels();


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
