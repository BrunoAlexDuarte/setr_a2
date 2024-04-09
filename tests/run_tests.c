#include "../unity_src/unity.h"
#include "uart_tests.c"
#include "sensors_tests.c"
#include "total_tests.c"

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
    RUN_TEST(test_uart_out_calculate_checksum);

    RUN_TEST(test_generate_2_temps);
	RUN_TEST(test_generate_2_humidities);
	RUN_TEST(test_generate_2_co2levels);
	RUN_TEST(test_generate_all);
	RUN_TEST(test_get_20_temps);
	RUN_TEST(test_get_20_humidities);
	RUN_TEST(test_get_20_co2);

    RUN_TEST(test_temps);
	RUN_TEST(test_total_get_20_and_reset_temps);

    UNITY_END();

    return 0;
}