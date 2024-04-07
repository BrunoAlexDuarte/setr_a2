
#include "unity/src/unity.h"
#include "../src/UART/UART.h"


void setUp(void) {}

void tearDown(void) {}

void test_unity1(void) {

	TEST_ASSERT_EQUAL_HEX8(10, 10);

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
	receive_byte('8');
	receive_byte('0');
	res = receive_byte('!');
	printf("res: %d\n", res);
	char *bytes = returnRxBuffer();
	printf("buffer:%s\n", bytes);
}


int main(void) {

	printf("Hello mom!\n");

	UNITY_BEGIN();
	RUN_TEST(test_unity1);
	RUN_TEST(test_receive_message);


	return 0;
}

