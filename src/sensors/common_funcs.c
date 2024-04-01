#include "common_funcs.h"

uint16_t send_char(unsigned char c) {
	//COLOCAR AQUI VERIFICACAO SE E DE FACTO UMA LETRA; NUMERO OU SINAL;
//	putchar(c);
	send_byte(c);
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
