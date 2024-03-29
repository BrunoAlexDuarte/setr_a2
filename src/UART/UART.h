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

#define CHECKSUM_MATCH 0
#define VALID_COMMAND 0
#define BYTE_ADDED_TO_BUFFER 0
#define FULL_COMMAND_RECEIVED 0
#define INVALID_COMMAND 1
#define CHECKSUM_MISMATCH 2
#define REGEX_COMPILE_FAIL 3
#define REGEX_MATCH_FAIL 4
#define BUFFER_SIZE 20
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
uint16_t send_byte(unsigned char input);

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
uint16_t validate_checksum(char *command);

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
void clear_tx_buffer();

//debug
void PrintRxBuffer();


#endif