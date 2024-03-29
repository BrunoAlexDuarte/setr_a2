#include <stdio.h>
#include <stdint.h>
#include "UART/UART.h"

int main() {

	receive_byte('#');
	PrintRxBuffer();
	receive_byte('A');
	PrintRxBuffer();
	receive_byte('A');
	PrintRxBuffer();
	receive_byte('1');
	PrintRxBuffer();
	receive_byte('3');
	PrintRxBuffer();
	receive_byte('0');
	PrintRxBuffer();
	receive_byte('!');
	PrintRxBuffer();

	return 0;
}