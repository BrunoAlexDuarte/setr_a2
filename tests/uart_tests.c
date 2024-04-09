#include "../unity_src/unity.h"
#include "../src/UART/UART.h"

void test_uart_in_buffer(void) {
    unsigned char buffer[BUFFER_SIZE+1];
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('#'));
    TEST_ASSERT_EQUAL_CHAR('#', returnRxBuffer(buffer)[0]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('A'));
    TEST_ASSERT_EQUAL_CHAR('A', returnRxBuffer(buffer)[1]);
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, receive_byte('!'));
    receive_byte('#');
    receive_byte('A');
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('0'));
    TEST_ASSERT_EQUAL_CHAR('0', returnRxBuffer(buffer)[2]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('6'));
    TEST_ASSERT_EQUAL_CHAR('6', returnRxBuffer(buffer)[3]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('5'));
    TEST_ASSERT_EQUAL_CHAR('5', returnRxBuffer(buffer)[4]);
    TEST_ASSERT_EQUAL_UINT16(SUCCESS, receive_byte('!'));
}

void test_uart_in_validate_cmd(void) {
    char command[BUFFER_SIZE];
    strcpy(command, "#A123!");
    TEST_ASSERT_EQUAL_UINT16(VALID_COMMAND, validate_command(command));
    strcpy(command, "#Z123!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#1!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "A123");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#PA20099!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#LA299");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#AB256!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#PA169!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
}

void test_uart_in_validate_checksum(void) {
    char command[BUFFER_SIZE];
    strcpy(command, "#A065!");
    TEST_ASSERT_EQUAL_UINT16(CHECKSUM_MATCH, validate_checksum(command, 6));
    strcpy(command, "#A123!");
    TEST_ASSERT_EQUAL_UINT16(CHECKSUM_MISMATCH, validate_checksum(command, 6));
    strcpy(command, "#LA141!");
    TEST_ASSERT_EQUAL_UINT16(CHECKSUM_MATCH, validate_checksum(command, 7));
    strcpy(command, "#LAA130!");
    TEST_ASSERT_EQUAL_UINT16(CHECKSUM_MISMATCH, validate_checksum(command, 8));
    strcpy(command, "#LAA206!");
    TEST_ASSERT_EQUAL_UINT16(CHECKSUM_MATCH, validate_checksum(command, 8));
}

void test_uart_out_buffer(void) {
    unsigned char buffer[BUFFER_SIZE+1];
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('#'));
    TEST_ASSERT_EQUAL_CHAR('#', returnTxBuffer(buffer)[0]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('P'));
    TEST_ASSERT_EQUAL_CHAR('P', returnTxBuffer(buffer)[1]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('T'));
    TEST_ASSERT_EQUAL_CHAR('T', returnTxBuffer(buffer)[2]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('1'));
    TEST_ASSERT_EQUAL_CHAR('1', returnTxBuffer(buffer)[3]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('5'));
    TEST_ASSERT_EQUAL_CHAR('5', returnTxBuffer(buffer)[4]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('|'));
    TEST_ASSERT_EQUAL_CHAR('|', returnTxBuffer(buffer)[5]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('0'));
    TEST_ASSERT_EQUAL_CHAR('0', returnTxBuffer(buffer)[6]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('1'));
    TEST_ASSERT_EQUAL_CHAR('1', returnTxBuffer(buffer)[7]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('0'));
    TEST_ASSERT_EQUAL_CHAR('0', returnTxBuffer(buffer)[8]);
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, send_byte('!'));
    TEST_ASSERT_EQUAL_CHAR('!', returnTxBuffer(buffer)[9]);
}

void test_uart_out_calculate_checksum(void) {
    clear_tx_buffer();
    send_byte('#'); send_byte('P');
    TEST_ASSERT_EQUAL_UINT16(80, calculate_checksum());
    send_byte('T'); send_byte('1');
    TEST_ASSERT_EQUAL_UINT16(213, calculate_checksum());
    send_byte('5');
    TEST_ASSERT_EQUAL_UINT16(10, calculate_checksum());
}
