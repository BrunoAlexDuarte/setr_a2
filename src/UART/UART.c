#include "UART.h"

static unsigned char RxBuffer[BUFFER_SIZE];
static uint16_t rx_occupied_bytes = 0;
static unsigned char TxBuffer[BUFFER_SIZE];
static uint16_t tx_occupied_bytes = 0;
static regex_t regex;
static char* command_pattern = "^#(A|P[THC]|L|L[THC]|R|R[THC])(2[5][0-5]|2[0-4][0-9]|[0-1][0-9]{2})!$";

uint16_t check_sensor_identifier(unsigned char c) {
	return c == 'T' || c == 'H' || c == 'C';
}

uint16_t receive_byte(unsigned char input) {

    if(rx_occupied_bytes < BUFFER_SIZE) {

        if(input == SOF_SYM) {
            clear_rx_buffer();
        }
        RxBuffer[rx_occupied_bytes] = input;
        rx_occupied_bytes++;

        if(input == EOF_SYM) {
            //get command in buffer
            char command[rx_occupied_bytes+1];
            strncpy(command, RxBuffer, rx_occupied_bytes);
            command[rx_occupied_bytes] = '\0'; //null-terminate the string;
            if(validate_command(command)==0 && validate_checksum(command, rx_occupied_bytes)==0) {
                switch(command[1]) {
                    case 'A':
			            return read_value_sensor_all();
                        break;
                    case 'P':
                        if(!check_sensor_identifier(command[2])) {
                            return UNKNOWN_SENSOR;
                        }
			            return read_value_sensor(command[2]);
                        break;
                    case 'L':
                        if(!check_sensor_identifier(command[2])) return send_last_20_samples_all();
                        else return send_last_20_samples(command[2]);
                        break;
                    case 'R':
                        if(!check_sensor_identifier(command[2])) return reset_history(command[2]);
                        else return reset_history_all();
                        break;
                    default:
                        return INVALID_COMMAND;
                }
                clear_rx_buffer();
                return FULL_COMMAND_RECEIVED;
            }
            clear_rx_buffer();
            return INVALID_COMMAND;
        }
        return BYTE_ADDED_TO_BUFFER;
    }
    clear_rx_buffer();
    return receive_byte(input);
}


uint16_t validate_command(char *command) {
    
    uint16_t ret = regcomp(&regex, command_pattern, REG_EXTENDED);
    if(ret != 0) {
        return REGEX_COMPILE_FAIL;
    }

    ret = regexec(&regex, command, 0, NULL, 0);
    if(ret == 0) {
        return VALID_COMMAND;
    } else if(ret == REG_NOMATCH) {
        return INVALID_COMMAND;
    } 
    return REGEX_MATCH_FAIL;

}

uint16_t validate_checksum(char *command, uint16_t rx_occupied_bytes) {
    
    uint16_t start_commandsum = 1;
    uint16_t end_commandsum = rx_occupied_bytes - 5;
    uint16_t start_checksum = rx_occupied_bytes - 4;
    uint16_t end_checksum = rx_occupied_bytes - 2;

    uint16_t checksum = 0;
    uint16_t i = start_checksum;
    uint16_t multiplier = 100;
    
    while(i <= end_checksum) {
        checksum = checksum + multiplier * (command[i] - '0');
        i++;
        multiplier /= 10;
    }
    
    uint16_t commandsum = 0;
    for(i = start_commandsum; i <= end_commandsum; i++) {
        commandsum += command[i];
        commandsum %= 256; // volta a 0 aos 255
    }

    if(commandsum == checksum) {
        return CHECKSUM_MATCH;
    }
    return CHECKSUM_MISMATCH;

}

uint16_t calculate_checksum() {
	uint16_t sum = 0;
	for(uint16_t i = 1; i < tx_occupied_bytes; i++) {
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
            printf("Full command sent: %s\n", command);
            return FULL_COMMAND_SENT;
        }
        return BYTE_ADDED_TO_BUFFER;
    }
    clear_tx_buffer();
    return send_byte(input);
}

void clear_rx_buffer() {
    rx_occupied_bytes = 0;
    return;
}

void clear_tx_buffer() {
    tx_occupied_bytes = 0;
    return;
}

//debug
void PrintRxBuffer() {
    printf("RxBuffer:");
    for(uint16_t i = 0; i < rx_occupied_bytes; i++) {
        printf("%c,", RxBuffer[i]);
    }
    printf("\n");
}

unsigned char *returnRxBuffer() {
	return RxBuffer;
}

void PrintTxBuffer() {
    printf("TxBuffer:");
    for(uint16_t i = 0; i < tx_occupied_bytes; i++) {
        printf("%c,", TxBuffer[i]);
    }
    printf("\n");
}

unsigned char *returnTxBuffer() {
	return TxBuffer;
}
