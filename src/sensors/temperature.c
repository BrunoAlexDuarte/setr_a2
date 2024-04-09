
#include "temperature.h"

uint16_t temps[SENSOR_CACHE_SIZE+1];
uint16_t temp_last = 0;
uint16_t more_20_temps = 0;
uint16_t all_temperatures[NUM_SAMPLES] = { 85, 21, 48, 104, 81, 82, 8, 35, 74, 59, 73,
	40, 50, 64, 32, 23, 57, 10, 86, 7, 72, 95, 27, 105, 29, 61, 62, 38, 96, 25, 88,
	33, 15, 18, 46, 51, 26, 45, 3, 5} ;
uint16_t temperature_sample = 0;

uint16_t send_last_20_temps() {
	if (!more_20_temps) {
		return NOT_TWENTY_ENTRIES;
	}
	for (uint16_t i = 0; i < 20; i++) {
		send_temp(temps[i]);
		//send_byte('|');
	}
	return SUCCESS;
}

uint16_t read_sensor_temp() {
	generate_temp();
	uint16_t value_temp = temps[temp_last];
	send_temp(value_temp);
	return SUCCESS;
}

uint16_t send_temp(uint16_t value_temp) {
	if (value_temp <= 50) {
		send_byte('-');
		value_temp = 50 - value_temp;
		send_number(value_temp);
	} else {
		send_byte('+');
		value_temp = value_temp - 50;
		send_number(value_temp);
	}
	return SUCCESS;
}

uint16_t generate_temp() {
	temps[++temp_last] = all_temperatures[temperature_sample++];
	temperature_sample %= NUM_SAMPLES;
	temp_last %= SENSOR_CACHE_SIZE;
	if (temp_last == SENSOR_CACHE_SIZE - 1) more_20_temps = 1;
	return SUCCESS;
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

