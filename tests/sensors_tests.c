
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
	unsigned char buffer[BUFFER_SIZE+1];
	res = read_value_sensor('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PT+35|055!", returnTxBuffer(buffer));

	res = read_value_sensor('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PT-29|060!", returnTxBuffer(buffer));
}

void test_generate_2_humidities(void) {

	int res = 0;
	unsigned char buffer[BUFFER_SIZE+1];

	res = read_value_sensor('H');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PH+64|045!", returnTxBuffer(buffer));

	res = read_value_sensor('H');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PH+78|050!", returnTxBuffer(buffer));
}

void test_generate_2_co2levels(void) {

	int res = 0;
	unsigned char buffer[BUFFER_SIZE+1];

	res = read_value_sensor('C');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PC+7524|144!", returnTxBuffer(buffer));

	res = read_value_sensor('C');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PC+6942|147!", returnTxBuffer(buffer));
}

void test_send_number(void) {
	
	int res = 0;
	res =  send_number(85);
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(9);
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(1002);
	TEST_ASSERT_EQUAL_HEX8(0, res);
	clear_tx_buffer();

	res =  send_number(22902);
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

	for (int i = 0; i < 220; i++) {
		generate_temp();
	}
	res = send_last_20_temps();
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = reset_temps();
	TEST_ASSERT_EQUAL_HEX8(0, res);

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

	for (int i = 0; i < 220; i++) {
		generate_humidity();
	}
	res = send_last_20_humidities();
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = reset_humidities();
	TEST_ASSERT_EQUAL_HEX8(0, res);
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

	for (int i = 0; i < 220; i++) {
		generate_co2();
	}
	res = send_last_20_co2levels();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	
	res = reset_co2levels();
	TEST_ASSERT_EQUAL_HEX8(0, res);
}

