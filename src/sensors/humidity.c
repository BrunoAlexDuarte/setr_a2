
#include "humidity.h"

uint16_t humidities[SENSOR_CACHE_SIZE];
uint16_t humidity_last = 0;
uint16_t more_20_humidities = 0;
uint16_t all_humidities[NUM_SAMPLES] = { 64, 78, 50, 87, 62, 91, 23, 98, 41, 33, 40, 52,
	27, 77, 68, 70, 67, 36, 18, 4, 30, 72, 76, 66, 61, 32, 71, 49, 24, 86, 34,
	26, 1, 81, 97, 83, 82, 75, 94, 58};
uint16_t humitidty_sample = 0;

uint16_t send_last_20_humidities() {
	if (!more_20_humidities) {
		return NOT_TWENTY_ENTRIES;
	}
	for (uint16_t i = 0; i < 20; i++) {
		send_humidity(humidities[i]);
		send_char('|');
	}
	return SUCCESS;
}

uint16_t read_sensor_humidity() {
	uint16_t value_humidity = generate_humidity();
	send_humidity(value_humidity);
	return SUCCESS;
}

uint16_t send_humidity(uint16_t value_humidity) {
	send_char('+');
	send_number(value_humidity);
	return SUCCESS;
}

uint16_t generate_humidity() {
	humidities[humidity_last++] = all_humidities[humitidty_sample++];
	humitidty_sample %= NUM_SAMPLES;
	humidity_last %= SENSOR_CACHE_SIZE;
	if (humidity_last == SENSOR_CACHE_SIZE-1) more_20_humidities = 1;
	return SUCCESS;
}

uint16_t check_humidities() {
	return more_20_humidities;
}

uint16_t reset_humidities() {
	humidity_last = 0;
	more_20_humidities = 0;
	return SUCCESS;
}

uint16_t show_humidities() {
	return SUCCESS;
}

