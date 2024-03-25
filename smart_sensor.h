#ifndef __SMART_SENSOR_H__
#define __SMART_SENSOR_H__

#include "temperature.h"
#include "humidity.h"
#include "co2levels.h"


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
uint16_t read_value_sensor(unsigned char sensor); //Command P 
					     //
/* # L CS ! */ //
    //- Dados de todos os sensores, últimos 20
uint16_t show_samples(); //Command L
			 //
/* # R CS ! */
    //- Reseta o histórico
uint16_t reset_history_all(); //Comand R
uint16_t reset_history(unsigned char sensor); //Comand R

uint16_t read_value_sensor_all();



uint16_t send_last_20_samples(unsigned char sensor);
uint16_t send_last_20_samples_all();



#endif

