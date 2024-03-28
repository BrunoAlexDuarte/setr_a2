# Set the source files that make up the library
set(SENSORS_SRCS
   common_funcs.h common_funcs.c
   co2levels.h co2_levels.c
   humidity.h humidities.c
   temperature.h temperatures.c
   smart_sensor.h smart_sensor.c
)

# Set the library type (can be static or dynamic)
SET (LIB_TYPE STATIC)

# Create the library
add_library (SensorsLib ${LIB_TYPE} ${SENSORS_SRCS})
