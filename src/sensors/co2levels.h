#ifndef __CO2LEVELS_H__
#define __CO2LEVELS_H__

#include "common_funcs.h"

uint16_t generate_co2();
uint16_t read_sensor_co2();
uint16_t send_co2(uint16_t value_co2);
uint16_t send_last_20_co2levels();
uint16_t check_co2levels();
uint16_t reset_co2levels();
uint16_t show_co2levels();

#endif
