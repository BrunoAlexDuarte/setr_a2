
#include "co2levels.h"

uint16_t co2levels[SENSOR_CACHE_SIZE];
uint16_t co2levels_last = 0;
uint16_t more_20_co2s = 0;

uint16_t send_last_20_co2levels() {
	if (!more_20_co2s) {
		return NOT_TWENTY_ENTRIES;
	}
	for (uint16_t i = 0; i < 20; i++) {
		send_co2(co2levels[i]);
		send_char('|');
	}
	return SUCCESS;
}

uint16_t read_sensor_co2() {
	uint16_t value_co2 = generate_co2();
	send_co2(value_co2);
	return SUCCESS;
}

uint16_t send_co2(uint16_t value_co2) {
	send_char('+');
	send_number(value_co2);
	return SUCCESS;
}

uint16_t generate_co2() {
	uint16_t value = 4000;
	co2levels[co2levels_last++] = value;
	co2levels_last %= SENSOR_CACHE_SIZE;
	if (co2levels_last > 20) more_20_co2s = 1;
	return value;
}

uint16_t check_co2levels() { 
	return more_20_co2s;
}

uint16_t reset_co2levels() {
	co2levels_last = 0;
	more_20_co2s = 0;
	return SUCCESS;	
}

uint16_t show_co2levels() {
	return SUCCESS;
}

