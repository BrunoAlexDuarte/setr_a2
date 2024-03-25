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
#define CHECKSUM_MISSMATCH 2
#define REGEX_COMPILE_FAIL 3
#define REGEX_MATCH_FAIL 4
#define BUFFER_FULLY_OCCUPIED 5
#define BUFFER_SIZE 15

uint16_t receive_byte(unsigned char input);

#endif