#ifndef __COMMON_FUNCS_H__
#define __COMMON_FUNCS_H__

#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>
#include "../UART/UART.h"

#define SUCCESS 0
#define NO_SENSOR 1
#define NOT_TWENTY_ENTRIES 2

#define SENSOR_CACHE_SIZE 20
uint16_t send_char(unsigned char c);
uint16_t send_number(uint16_t number);

#endif
