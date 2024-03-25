#ifndef __HUMIDITY_H__
#define __HUMIDITY_H__

#include "common_funcs.h"

uint16_t read_sensor_humidity();
uint16_t generate_humidity();
uint16_t send_humidity(uint16_t value_humidity);
uint16_t send_last_20_humidities();
uint16_t check_humidities();
uint16_t reset_humidities();
uint16_t show_humidities();

#endif
