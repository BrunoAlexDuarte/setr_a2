
#include "humidity.h"

uint16_t humidities[SENSOR_CACHE_SIZE];
uint16_t humidity_last = 0;
uint16_t more_20_humidities = 0;

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
	uint16_t value = 5;
	humidities[humidity_last++] = value;
	humidity_last %= SENSOR_CACHE_SIZE;
	if (humidity_last > 20) more_20_humidities = 1;
	return value;
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

