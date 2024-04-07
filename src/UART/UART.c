#include "UART.h"

static unsigned char RxBuffer[BUFFER_SIZE];
static uint16_t rx_occupied_bytes = 0;

static regex_t regex;
static char* command_pattern = "^#[APLR].*(2[0-5][0-9]|[0-1][0-9]{2})!$";

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
	    printf("O comando :%s\n", command);
	    int res = validate_checksum(command);
	    printf("O resultado e:%d\n", res);
	    validate_checksum2(command);
            if(validate_command(command)==0 && validate_checksum(command)==0) {
                switch(command[1]) {
                    case 'A':
			            read_value_sensor_all();
                        break;
                    case 'P':
                        if(!check_sensor_identifier(command[2])) {
                            return UNKNOWN_SENSOR;
                        }
			            read_value_sensor(command[2]);
                        break;
                    case 'L':
                        if(!check_sensor_identifier(command[2])) send_last_20_samples_all();
                        else send_last_20_samples(command[2]);
                        break;
                    case 'R':
                        if(!check_sensor_identifier(command[2])) reset_history(command[2]);
                        else reset_history_all();
                        break;
                    default:
                        return INVALID_COMMAND;
                }
                clear_rx_buffer();
                return FULL_COMMAND_RECEIVED;
            }
            clear_rx_buffer();
	    printf("invalido\n");
	    printf("invalido:%d\n", validate_checksum(command));
	    printf("invalido:%d\n", validate_command(command));
            return INVALID_COMMAND;
        }
        return BYTE_ADDED_TO_BUFFER;
    }
    clear_rx_buffer();
    receive_byte(input);
    return BYTE_ADDED_TO_BUFFER;
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


uint16_t validate_checksum2(char *command) {
	uint16_t last = rx_occupied_bytes - 2; //onde está o último digito
	uint16_t checksum_num = 0;
	uint16_t checksum = 0;
	uint16_t multiplier = 1;
	uint16_t i = last;

	for (; i > 0; i--) {
		if (!(command[i] <= '9' && command[i] >= '0')) break;
		checksum_num = checksum_num + multiplier * (command[i]-'0');	
		multiplier *= 10;
	}
	for(; i > 0; i--) {
		checksum += command[i];
	}
	return checksum == checksum_num;
}

uint16_t validate_checksum(char *command) {
    
    uint16_t start_commandsum = 1;
    uint16_t end_commandsum = rx_occupied_bytes - 5;
    uint16_t start_checksum = rx_occupied_bytes - 4;
    uint16_t end_checksum = rx_occupied_bytes - 2;

    uint16_t checksum = 0;
    uint16_t i = start_checksum;
    while(i <= end_checksum) {
        checksum = checksum * 10 + (command[i] - '0');
	//checksum = (checksum + command[i]) % 256;
        i++;
    }

    uint16_t commandsum = 0;
    for(i = start_commandsum; i <= end_commandsum; i++) {
	printf("Adiciona:%d\n", command[i]);
	printf("ola\n");
        commandsum += command[i];
        commandsum %= 256; // volta a 0 aos 255
    }
    printf("Checksum:%d\n", checksum);
    printf("Commandsum:%d\n", commandsum);

    if(commandsum == checksum) {
        return CHECKSUM_MATCH;
    }
    return CHECKSUM_MISMATCH;

}

void clear_rx_buffer() {
    rx_occupied_bytes = 0;
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
