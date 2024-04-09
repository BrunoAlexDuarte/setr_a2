
#include "uart_out.h"

static unsigned char TxBuffer[BUFFER_SIZE];
static uint16_t tx_occupied_bytes = 0;

uint16_t calculate_checksum() {
	uint16_t sum = 0;
	for(uint16_t i = 2; i < tx_occupied_bytes; i++) {
		sum = (sum + TxBuffer[i]) % 256;
	}
	return sum;
}

uint16_t send_byte(unsigned char input) {

    if(tx_occupied_bytes < BUFFER_SIZE) {

        if(input == SOF_SYM) {
            clear_tx_buffer();
        }
        TxBuffer[tx_occupied_bytes] = input;
        tx_occupied_bytes++;
        if(input == EOF_SYM) {
            //get command in buffer
            char command[tx_occupied_bytes+1];
            strncpy(command, TxBuffer, tx_occupied_bytes);
            command[tx_occupied_bytes] = '\0'; //null-terminate the string;
            /*if(validate_command(command)==0) { // talvez nao seja preciso fazer o checksum (?)
                switch(command[1]) {
                    case 'X':
                        printf("TO DO\n");
                        break;
                    default:
                        return INVALID_COMMAND;
                }
                clear_tx_buffer();
        	return FULL_COMMAND_RECEIVED;
            }*/
            /*clear_tx_buffer();
            return INVALID_COMMAND;*/
        }
        return BYTE_ADDED_TO_BUFFER;
    }
    clear_tx_buffer();
    return send_byte(input);
}

void clear_tx_buffer() {
    tx_occupied_bytes = 0;
    return;
}

//debug
void PrintTxBuffer() {
	printf("Occupied_bytes:%d\n", tx_occupied_bytes);
    printf("TxBuffer:");
    for(uint16_t i = 0; i < tx_occupied_bytes; i++) {
        printf("%c,", TxBuffer[i]);
    }
    printf("\n");
}

unsigned char *returnTxBuffer() {
	return TxBuffer;
}

