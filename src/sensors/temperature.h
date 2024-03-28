#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include "common_funcs.h"

uint16_t generate_temp();
uint16_t read_sensor_temp();
uint16_t send_temp(uint16_t value_temp);
uint16_t send_last_20_temps();
uint16_t check_temps();
uint16_t reset_temps();
uint16_t show_temps();

#endif
