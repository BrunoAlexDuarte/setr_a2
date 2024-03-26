#include <stdio.h>
#include <stdint.h>
#include "smart_sensor.h"

//int main() {
//    unsigned char values[] = {100, 200, 150, 10}; 
//    uint16_t sum = 0;
//
//    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
//        sum += values[i];
//        sum %= 256;
//    }
//
//    printf("Sum: %d\n", sum);
//
//    return 0;
//}
int main(int argc, char *argv[]) {
	for(int i = 0; i < 30; i++) {
		generate_temp();
		generate_humidity();
		generate_co2();
	}
	read_value_sensor_all();
	puts("");
	read_value_sensor_all();
	puts("");
	show_temps();
	send_last_20_samples_all();
	return 0;
}
