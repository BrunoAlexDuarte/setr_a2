#include "../unity_src/unity.h"
#include "uart_tests.c"

void setUp(void)
{
    clear_rx_buffer();
    clear_tx_buffer();
	return;
}
void tearDown(void)
{
	return;
}

int main(void) {

    UNITY_BEGIN();

    RUN_TEST(test_uart_in_buffer);
    RUN_TEST(test_uart_in_validate_cmd);
    RUN_TEST(test_uart_in_validate_checksum);
    RUN_TEST(test_uart_out_buffer);

    UNITY_END();

    return 0;
}