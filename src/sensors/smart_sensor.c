//Main lib file

#include "smart_sensor.h"

/*
 * Podemos adicionar coisas para melhorar por exemplo o protocolo de comunicação
 * Não esquecer de utilizar o github e o doxygen
 * */

uint16_t read_value_sensor_all() {

	send_char('#');
	send_char('A');
	send_char('R');
	//Sends values by order (temperature, humidity, CO2)
	read_sensor_temp();
	send_char('>');
	read_sensor_humidity();
	send_char('>');
	read_sensor_co2();
	send_char('!');

	return SUCCESS;
}

uint16_t read_value_sensor(unsigned char sensor) {
	
	if (sensor == 'T') {
		send_char('#');
		send_char('P');
		send_char('R');
		read_sensor_temp();
		send_char('!');
		return SUCCESS;
	}
	if (sensor == 'H') {
		send_char('#');
		send_char('P');
		send_char('R');
		read_sensor_humidity();
		send_char('!');
		return SUCCESS;
	}
	if (sensor == 'C') {
		send_char('#');
		send_char('P');
		send_char('R');
		read_sensor_co2();
		send_char('!');
		return SUCCESS;
	}
	return NO_SENSOR;
}

uint16_t send_last_20_samples(unsigned char sensor) {
	
	uint16_t *samples;
	uint16_t more_20 = 0;
	if (sensor == 'T') {
		send_char('#');
		send_char('P');
		send_char('R');
		send_last_20_temps();
		send_char('!');
	} else if (sensor == 'H') {
		send_char('#');
		send_char('P');
		send_char('R');
		send_last_20_humidities();
		send_char('!');
	} else if (sensor == 'C') {
		send_char('#');
		send_char('P');
		send_char('R');
		send_last_20_co2levels();
		send_char('!');
	} else return NO_SENSOR;
	
	return SUCCESS;
}

uint16_t send_last_20_samples_all() {

	if (check_temps() && check_humidities() && check_co2levels()) {
		send_char('#');
		send_char('L');
		send_char('R');
		send_last_20_temps();
		send_char('>');
		send_last_20_humidities();
		send_char('>');
		send_last_20_co2levels();
		send_char('!');
		return SUCCESS;
	}
	printf("FAILURE: %d %d %d\n", check_temps(), check_humidities(), check_co2levels());
	return NOT_TWENTY_ENTRIES;
}

uint16_t reset_history_sensor(unsigned char sensor) {
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
