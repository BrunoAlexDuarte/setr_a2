//Main lib file

#include "smart_sensor.h"

/*
 * Podemos adicionar coisas para melhorar por exemplo o protocolo de comunicação
 * Não esquecer de utilizar o github e o doxygen
 * */

// Criar função para ler os valores de ascci e passar os mesmos para inteiros

static uint16_t temps[SENSOR_CACHE_SIZE];
static uint16_t temp_last = 0;
static uint16_t more_20_temps = 0;

static uint16_t humidities[SENSOR_CACHE_SIZE];
static uint16_t humidity_last = 0;
static uint16_t more_20_humidities = 0;

static uint16_t co2levels[SENSOR_CACHE_SIZE];
static uint16_t co2levels_last = 0;
static uint16_t more_20_co2s = 0;

uint16_t send_char(unsigned char c) {
	//COLOCAR AQUI VERIFICACAO SE E DE FACTO UMA LETRA; NUMERO OU SINAL;
	putchar(c);
	return SUCCESS;
}


uint16_t send_number(uint16_t number) {
	
	if (!number) { //Verificar se o número não é zero
		send_char('0');
		return SUCCESS;
	}

	uint16_t i = 10000; //Para a div_int o máximo que precisaremos é 10k

	while (number / i == 0) i /= 10; //Caso 10k seka muito grande, adequamos
	do {
		send_char((unsigned char) (number / i) + '0');
		number %= i;
	} while(i=i/10) ;  //Fazemos até chegarmos à casa das unidades

	return SUCCESS;
}


uint16_t read_value_sensor_all() {

	send_char('#');
	send_char('A');
	send_char('R');
	//Sends values by order (temperature, humidity, CO2)
	send_sensor_temp();
	send_sensor_humidity();
	send_sensor_co2();
	send_char('!');

	return SUCCESS;
}

uint16_t read_value_sensor(unsigned char sensor) {
	
	if (sensor == 'T') {
		send_sensor_temp();
		return SUCCESS;
	}
	if (sensor == 'H') {
		send_sensor_humidity();
		return SUCCESS;
	}
	if (sensor == 'C') {
		send_sensor_co2();
		return SUCCESS;
	}
	return NO_SENSOR;
}

uint16_t send_last_20_samples(unsigned char sensor) {



	return NO_SENSOR;
}

uint16_t send_sensor_temp() {
	uint16_t value_temp = generate_temp();
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

uint16_t send_sensor_humidity() {
	uint16_t value_humidity = generate_humidity();
	send_char('+');
	send_number(value_humidity);
	return SUCCESS;
}

uint16_t send_sensor_co2() {
	uint16_t value_co2 = generate_co2();
	send_char('+');
	send_number(value_co2);
	return SUCCESS;
}

uint16_t generate_temp() {
	uint16_t value = 70;
	temps[temp_last++] = value;
	temp_last %= SENSOR_CACHE_SIZE;
	if (temp_last > 20) more_20_temps = 1;
	return value;
}
uint16_t generate_humidity() {
	uint16_t value = 5;
	humidities[humidity_last++] = value;
	humidity_last %= SENSOR_CACHE_SIZE;
	if (humidity_last > 20) more_20_humidities = 1;
	return value;
}
uint16_t generate_co2() {
	uint16_t value = 4000;
	co2levels[co2levels_last++] = value;
	co2levels_last %= SENSOR_CACHE_SIZE;
	if (co2levels_last > 20) more_20_co2s = 1;
	return value;
}

uint16_t show_temps() {
	printf("Temps[0]:%d, [1]:%d\n", temps[0], temps[1]);
	return SUCCESS;
}

uint16_t show_humidities() {
	return SUCCESS;
}

uint16_t show_co2levels() {
	return SUCCESS;
}
//EOF
