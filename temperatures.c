
#include "temperature.h"

uint16_t temps[SENSOR_CACHE_SIZE];
uint16_t temp_last = 0;
uint16_t more_20_temps = 0;

uint16_t send_last_20_temps() {
	if (!more_20_temps) {
		return NOT_TWENTY_ENTRIES;
	}
	for (uint16_t i = 0; i < 20; i++) {
		send_temp(temps[i]);
		send_char('|');
	}
	return SUCCESS;
}

uint16_t read_sensor_temp() {
	uint16_t value_temp = generate_temp();
	send_temp(value_temp);
	return SUCCESS;
}

uint16_t send_temp(uint16_t value_temp) {
	if (value_temp <= 50) {
		send_char('-');
		value_temp = 50 - value_temp;
		send_number(value_temp);
	} else {
		send_char('+');
		value_temp = value_temp - 50;
		send_number(value_temp);
	}
	return SUCCESS;
}

uint16_t generate_temp() {
	uint16_t value = 30;
	temps[temp_last++] = value;
	temp_last %= SENSOR_CACHE_SIZE;
	if (temp_last == SENSOR_CACHE_SIZE - 1) more_20_temps = 1;
	return value;
}
uint16_t check_temps() {
	return more_20_temps;
}

uint16_t reset_temps() {
	temp_last = 0;
	more_20_temps = 0;
	return SUCCESS;
}

uint16_t show_temps() {
	printf("Temps[0]:%d, [1]:%d\n", temps[0], temps[1]);
	return SUCCESS;
}

