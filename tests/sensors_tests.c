
#include "../unity_src/unity.h"
#include "../src/UART/UART.h"

void test_generate_all(void) {
	int res = 0;
	res = read_value_sensor_all();
	//PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	//char *bytes = returnTxBuffer();
	//printf("buffer:%s\n", bytes);
}

void test_generate_2_temps(void) {

	int res = 0;
	res = read_value_sensor('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	printf("CHEGOU\n");
	TEST_ASSERT_EQUAL_STRING("#PT+35|231!", returnTxBuffer());

	res = read_value_sensor('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PT-29|236!", returnTxBuffer());
}

void test_generate_2_humidities(void) {

	int res = 0;

	res = read_value_sensor('H');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PH+64|221!", returnTxBuffer());

	res = read_value_sensor('H');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PH+78|226!", returnTxBuffer());
}

void test_generate_2_co2levels(void) {

	int res = 0;

	res = read_value_sensor('C');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PC+7524|64!", returnTxBuffer());

	res = read_value_sensor('C');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PC+6942|67!", returnTxBuffer());
}

void test_send_number(void) {
	
	int res = 0;
	res =  send_number(85);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(9);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(1002);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(22902);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

}

void test_get_20_temps(void) {
	int res = send_last_20_temps();
	TEST_ASSERT_EQUAL_HEX8(2, res);

	for (int i = 0; i < 20; i++) {
		generate_temp();
	}
	res = send_last_20_temps();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	
	res = check_temps();
	TEST_ASSERT_EQUAL_HEX8(1, res);
	
	res = reset_temps();
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = send_last_20_temps();
	TEST_ASSERT_EQUAL_HEX8(2, res);
}

void test_get_20_humidities(void) {
	int res = send_last_20_humidities();
	TEST_ASSERT_EQUAL_HEX8(2, res);

	for (int i = 0; i < 20; i++) {
		generate_humidity();
	}
	res = send_last_20_humidities();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	
	res = check_humidities();
	TEST_ASSERT_EQUAL_HEX8(1, res);
	
	res = reset_humidities();
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = send_last_20_humidities();
	TEST_ASSERT_EQUAL_HEX8(2, res);
}

void test_get_20_co2(void) {
	int res = send_last_20_co2levels();
	TEST_ASSERT_EQUAL_HEX8(2, res);

	for (int i = 0; i < 20; i++) {
		generate_co2();
	}
	res = send_last_20_co2levels();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	
	res = check_co2levels();
	TEST_ASSERT_EQUAL_HEX8(1, res);
	
	res = reset_co2levels();
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = send_last_20_co2levels();
	TEST_ASSERT_EQUAL_HEX8(2, res);
}

