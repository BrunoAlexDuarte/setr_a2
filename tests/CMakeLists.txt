# Set the source files that make up the library
set(TESTS_SRCS
   uart_tests.c
)

# Set the library type (can be static or dynamic)
SET (LIB_TYPE STATIC)

# Create the library
add_library (TestsLib ${LIB_TYPE} ${TESTS_SRCS})

list(APPEND EXTRA_LIBS3 SensorsLib)
target_link_libraries(TestsLib PRIVATE ${EXTRA_LIBS1})

list(APPEND EXTRA_LIBS3 UARTLib)
target_link_libraries(TestsLib PRIVATE ${EXTRA_LIBS1})
