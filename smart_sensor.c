//Main lib file

#include "smart_sensor.h"

/*
 * Podemos adicionar coisas para melhorar por exemplo o protocolo de comunicação
 * Não esquecer de utilizar o github e o doxygen
 * */

// Criar função para ler os valores de ascci e passar os mesmos para inteiros

uint16_t send_char(unsigned char c) {
	//COLOCAR AQUI VERIFICACAO SE E DE FACTO UMA LETRA; NUMERO OU SINAL;
	printf("%c",c);
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

	//Generate values for all sensores
	//Sends values by order (temperature, humidity, CO2)

	return SUCCESS;
}



//EOF
