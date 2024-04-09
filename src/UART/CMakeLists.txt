# Set the source files that make up the library
set(UART_SRCS
   uart_in.h uart_in.c
   uart_out.h uart_out.c
   uart_common.h
)

# Set the library type (can be static or dynamic)
SET (LIB_TYPE STATIC)

# Create the library
add_library (UARTLib ${LIB_TYPE} ${UART_SRCS})

list(APPEND EXTRA_LIBS1 SensorsLib)
target_link_libraries(UARTLib PRIVATE ${EXTRA_LIBS1})
