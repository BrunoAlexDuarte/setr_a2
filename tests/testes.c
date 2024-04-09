
#include "../unity_src/unity.h"
#include "../src/UART/uart_in.h"
#include "../src/UART/uart_out.h"
#include "../src/sensors/smart_sensor.h"

void setUp(void) {}

void tearDown(void) {}

void test_unity1(void) {

	TEST_ASSERT_EQUAL_HEX8(10, 10);

}


void test_generate_all(void) {
	int res = 0;
	res = read_value_sensor_all();
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(0, res);
	char *bytes = returnTxBuffer();
	printf("buffer:%s\n", bytes);
}

void test_generate_2_temps(void) {

	int res = 0;
	res = read_value_sensor('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
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

void test_receive_message(void) {
	/*
	 * Teste para confirmarmos que no caso nromal recebemos bem a mensagem
	 *
	 * */
	int res = 0;
	
	res = receive_byte('#');
	printf("res: %d\n", res);
	res = receive_byte('P');
	printf("res: %d\n", res);
	res = receive_byte('C');
	printf("res: %d\n", res);
	receive_byte('1');
	receive_byte('4');
	receive_byte('7');
	res = receive_byte('!');
	printf("res: %d\n", res);
	unsigned char *bytes = returnRxBuffer();
	printf("buffer:%s\n", bytes);
}

void test_receive_message2(void) {
	/*
	 * Teste para confirmarmos que no caso nromal recebemos bem a mensagem
	 *
	 * */
	int res = 0;
	
	res = receive_byte('#');
	printf("res: %d\n", res);
	res = receive_byte('A');
	printf("res: %d\n", res);
	receive_byte('0');
	receive_byte('6');
	receive_byte('5');
	res = receive_byte('!');
	printf("res: %d\n", res);
	char *bytes = returnTxBuffer();
	printf("buffer:%s\n", bytes);
}



int main(void) {

	printf("Beign tests");

	UNITY_BEGIN();
	//RUN_TEST(test_unity1);
	RUN_TEST(test_receive_message);
	RUN_TEST(test_receive_message2);
	RUN_TEST(test_generate_all);
	//RUN_TEST(test_generate_2_temps);
	//RUN_TEST(test_generate_2_humidities);
	//RUN_TEST(test_generate_2_co2levels);
	//RUN_TEST(test_send_number);


	return 0;
}

