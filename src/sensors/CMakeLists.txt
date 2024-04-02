# Set the source files that make up the library
set(SENSORS_SRCS
   common_funcs.h common_funcs.c
   co2_levels.h co2_levels.c
   humidity.h humidity.c
   temperature.h temperature.c
   smart_sensor.h smart_sensor.c
)

# Set the library type (can be static or dynamic)
SET (LIB_TYPE STATIC)

# Create the library
add_library (SensorsLib ${LIB_TYPE} ${SENSORS_SRCS})

list(APPEND EXTRA_LIBS2 UARTLib)
target_link_libraries(SensorsLib PRIVATE ${EXTRA_LIBS2})