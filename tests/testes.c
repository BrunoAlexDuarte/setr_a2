
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
	TEST_ASSERT_EQUAL_HEX8(res, 0);
}

void test_generate_2_temps(void) {

	int res = 0;
	res = read_value_sensor('T');
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);

}

void test_generate_2_humidities(void) {

	int res = 0;

	res = read_value_sensor('H');
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
}

void test_generate_2_co2levels(void) {

	int res = 0;

	res = read_value_sensor('C');
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
}

void test_send_number(void) {
	
	int res = 0;
	res =  send_number(85);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
	clear_tx_buffer();

	res =  send_number(9);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
	clear_tx_buffer();

	res =  send_number(1002);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
	clear_tx_buffer();

	res =  send_number(22902);
	PrintTxBuffer();
	TEST_ASSERT_EQUAL_HEX8(res, 0);
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
	receive_byte('6');
	receive_byte('5');
	res = receive_byte('!');
	printf("res: %d\n", res);
	unsigned char *bytes = returnRxBuffer();
	printf("buffer:%s\n", bytes);
}



int main(void) {

	printf("Hello mom!\n");

	UNITY_BEGIN();
	//RUN_TEST(test_unity1);
	//RUN_TEST(test_receive_message);
	//RUN_TEST(test_receive_message2);
	//RUN_TEST(test_generate_all);
	RUN_TEST(test_generate_2_temps);
	RUN_TEST(test_generate_2_humidities);
	RUN_TEST(test_generate_2_co2levels);
	unsigned char *buffer = returnTxBuffer();
	printf("BUFFER FINAL:%s\n", buffer);
	//RUN_TEST(test_send_number);


	return 0;
}

