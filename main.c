//Main file
#include <stdio.h>
#include <stdlib.h>
#include "smart_sensor.h"

int main(int argc, char *argv[]) {
	read_value_sensor_all();
	puts("");
	read_value_sensor_all();
	puts("");
	show_temps();

	return 0;
}


//EOF
