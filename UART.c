#include "UART.h"

static unsigned char RxBuffer[BUFFER_SIZE];
static uint16_t rx_occupied_bytes = 0;
static unsigned char TxBuffer[BUFFER_SIZE];
static uint16_t tx_occupied_bytes = 0;
static regex_t regex;
static char* command_pattern = "^#[APLR].*(2[0-5][0-9]|[0-1][0-9]{2})!$";

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
            if(validate_command(command) && validate_checksum(command)) {
                // ------ usar o comando
                // switch bla bla bla
                clear_rx_buffer();
                return FULL_COMMAND_RECEIVED;
            }
            clear_rx_buffer();
            return INVALID_COMMAND;
        }

        return BYTE_ADDED_TO_BUFFER;
    }

    clear_rx_buffer();
    return BUFFER_FULLY_OCCUPIED;
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
            strncpy(command, RxBuffer, tx_occupied_bytes);
            command[tx_occupied_bytes] = '\0'; //null-terminate the string;
            if(validate_command(command)) { // talvez nao seja preciso fazer o checksum (?)
                // ------ usar o comando
                // switch bla bla bla
                clear_tx_buffer();
                return FULL_COMMAND_RECEIVED;
            }
            clear_tx_buffer();
            return INVALID_COMMAND;
        }

        return BYTE_ADDED_TO_BUFFER;
    }

    clear_tx_buffer();
    return BUFFER_FULLY_OCCUPIED;
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

uint16_t validate_checksum(char *command) {
    
    uint16_t start_commandsum = 1;
    uint16_t end_commandsum = rx_occupied_bytes - 5;
    uint16_t start_checksum = rx_occupied_bytes - 4;
    uint16_t end_checksum = rx_occupied_bytes - 2;

    uint16_t checksum = 0;
    uint16_t i = start_checksum;
    while(i <= end_checksum) {
        checksum = checksum * 10 + (command[i] - '0');
        i++;
    }

    uint16_t commandsum = 0;
    for(i = start_commandsum; i <= end_commandsum; i++) {
        commandsum += command[i];
        commandsum %= 256; // volta a 0 aos 255
    }

    if(commandsum == checksum) {
        return CHECKSUM_MATCH;
    }
    return CHECKSUM_MISSMATCH;

}

void clear_rx_buffer() {
    rx_occupied_bytes = 0;
}

void clear_tx_buffer() {
    tx_occupied_bytes = 0;
}