
#include "../unity_src/unity.h"
#include "../src/UART/UART.h"

void test_total_get_20_and_reset_temps(void) {
	int res = 0;
	res = receive_byte('#');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('L');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('1');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('0');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('!');
	TEST_ASSERT_EQUAL_HEX8(2, res);
	for (int i = 0; i < 20; i++) {
		res = receive_byte('#');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('P');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('T');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('1');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('6');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('4');
		TEST_ASSERT_EQUAL_HEX8(0, res);
		res = receive_byte('!');
		TEST_ASSERT_EQUAL_HEX8(0, res);
	}
	res = receive_byte('#');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('L');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('1');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('0');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('!');
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = receive_byte('#');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('R');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('1');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('!');
	TEST_ASSERT_EQUAL_HEX8(0, res);

	res = receive_byte('#');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('L');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('1');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('0');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('!');
	TEST_ASSERT_EQUAL_HEX8(2, res);
}

void test_temps(void) {
	int res = 0;
	res = receive_byte('#');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('P');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('T');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('1');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('6');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('4');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	res = receive_byte('!');
	TEST_ASSERT_EQUAL_HEX8(0, res);
	TEST_ASSERT_EQUAL_STRING("#PT+35|231!", returnTxBuffer());
}
