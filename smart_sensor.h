#ifndef __SMART_SENSOR_H__
#define __SMART_SENSOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SUCCESS 0

/*
 * As mensagens começam por # e acabam em !
 * Depois temos um byte para o comando CMD
 * Depois temos todos os dados necessários para executar os comandos DATA
 * Por fim temos um byte checksum, tem o tamanho de todos os bytes entre
 * o CMD e DATA
 * */


/*
 * Também temos de criar as respostas
 * 
 * */

/* # A CS ! */
    //- Dados de todos os sensores
uint16_t read_value_sensor_all(); //Command A 
				  //
/* # P S CS ! */ // S - indica o sensor que queremos ler
    //- Dados de somente um sensor
uint16_t read_value_sensor(uint16_t sensor); //Command P 
					     //
/* # L CS ! */ //
    //- Dados de todos os sensores, últimos 20
uint16_t show_samples(); //Command L
			 //
/* # R CS ! */
    //- Reseta o histórico
uint16_t reset_history(); //Comand R

uint16_t read_value_sensor_all();
uint16_t generate_temp();
uint16_t generate_humidity();
uint16_t generate_co2();
uint16_t send_sensor_temp();
uint16_t send_sensor_humidity();
uint16_t send_sensor_co2();


#endif

