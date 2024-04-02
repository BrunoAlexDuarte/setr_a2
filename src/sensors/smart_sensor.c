//Main lib file

#include "smart_sensor.h"

/*
 * Podemos adicionar coisas para melhorar por exemplo o protocolo de comunicação
 * Não esquecer de utilizar o github e o doxygen
 * */

uint16_t read_value_sensor_all() {

	send_byte('#');
	send_byte('A');
	send_byte('R');
	//Sends values by order (temperature, humidity, CO2)
	read_sensor_temp();
	send_byte('>');
	read_sensor_humidity();
	send_byte('>');
	read_sensor_co2();
	send_byte('!');

	return SUCCESS;
}

uint16_t read_value_sensor(unsigned char sensor) {
	
	if (sensor == 'T') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		read_sensor_temp();
		send_byte('!');
		return SUCCESS;
	}
	if (sensor == 'H') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		read_sensor_humidity();
		send_byte('!');
		return SUCCESS;
	}
	if (sensor == 'C') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		read_sensor_co2();
		send_byte('!');
		return SUCCESS;
	}
	return NO_SENSOR;
}

uint16_t send_last_20_samples(unsigned char sensor) {
	
	uint16_t *samples;
	uint16_t more_20 = 0;
	if (sensor == 'T') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		send_last_20_temps();
		send_byte('!');
	} else if (sensor == 'H') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		send_last_20_humidities();
		send_byte('!');
	} else if (sensor == 'C') {
		send_byte('#');
		send_byte('P');
		send_byte('R');
		send_last_20_co2levels();
		send_byte('!');
	} else return NO_SENSOR;
	
	return SUCCESS;
}

uint16_t send_last_20_samples_all() {

	if (check_temps() && check_humidities() && check_co2levels()) {
		send_byte('#');
		send_byte('L');
		send_byte('R');
		send_last_20_temps();
		send_byte('>');
		send_last_20_humidities();
		send_byte('>');
		send_last_20_co2levels();
		send_byte('!');
		return SUCCESS;
	}
	printf("FAILURE: %d %d %d\n", check_temps(), check_humidities(), check_co2levels());
	return NOT_TWENTY_ENTRIES;
}

uint16_t reset_history(unsigned char sensor) {
	if (sensor == 'T') {
		reset_temps();
	} else if (sensor == 'H') {
		reset_humidities();
	} else if (sensor == 'C') {
		reset_co2levels();
	} else return NO_SENSOR;
	return SUCCESS;
}


uint16_t reset_history_all() {
	reset_temps();
	reset_humidities();
	reset_co2levels();
	return SUCCESS;
}


//EOF
