#include "../unity_src/unity.h"
#include "../src/UART/uart_in.h"
#include "../src/UART/uart_out.h"

void test_uart_in_buffer(void) {
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('#'));
    TEST_ASSERT_EQUAL_CHAR('#', returnRxBuffer());
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('A'));
    TEST_ASSERT_EQUAL_CHAR('#A', returnRxBuffer());
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, receive_byte('!'));
    receive_byte('#');
    receive_byte('A');
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('0'));
    TEST_ASSERT_EQUAL_CHAR('#A0', returnRxBuffer());
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('6'));
    TEST_ASSERT_EQUAL_CHAR('#A06', returnRxBuffer());
    TEST_ASSERT_EQUAL_UINT16(BYTE_ADDED_TO_BUFFER, receive_byte('5'));
    TEST_ASSERT_EQUAL_CHAR('#A065', returnRxBuffer());
    TEST_ASSERT_EQUAL_UINT16(SUCCESS, receive_byte('!'));
}

void test_uart_in_valite_cmd(void) {
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
    TEST_ASSERT_EQUAL_UINT16(VALID_COMMAND, validate_command(command));
    strcpy(command, "#LA299");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#AB256!");
    TEST_ASSERT_EQUAL_UINT16(INVALID_COMMAND, validate_command(command));
    strcpy(command, "#PA169!");
    TEST_ASSERT_EQUAL_UINT16(VALID_COMMAND, validate_command(command));
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