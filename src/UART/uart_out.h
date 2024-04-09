#ifndef __UART_OUT_H__
#define __UART_OUT_H__

#include "uart_common.h"

uint16_t calculate_checksum();
uint16_t send_byte(unsigned char input);
void clear_tx_buffer();
void PrintTxBuffer();
unsigned char *returnTxBuffer();

#endif
