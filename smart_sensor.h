#ifndef __SMART_SENSOR_H__
#define __SMART_SENSOR_H__

#include <stdio.h>
#include <stdlib.h>

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
lont int read_value_sensor_all(); //Command A 
				  //
/* # P S CS ! */ // S - indica o sensor que queremos ler
    //- Dados de somente um sensor
long int read_value_sensor(long int sensor); //Command P 
					     //
/* # L CS ! */ //
    //- Dados de todos os sensores, últimos 20
long int show_samples(); //Command L
			 //
/* # R CS ! */
    //- Reseta o histórico
long int reset_history(); //Comand R

#endif

