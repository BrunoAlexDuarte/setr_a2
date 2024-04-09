#ifndef __UART_COMMON_H_
#define __UART_COMMON_H_

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
#define UNKNOWN_SENSOR 5
#define BUFFER_SIZE 20
#define SOF_SYM '#'	        /* Start of Frame Symbol */
#define EOF_SYM '!'         /* End of Frame Symbol */

#endif