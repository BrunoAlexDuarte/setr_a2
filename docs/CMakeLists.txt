set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(SensorsLibDoc
    "${PROJECT_SOURCE_DIR}/src/sensors")

doxygen_add_docs(UARTLibDoc
    "${PROJECT_SOURCE_DIR}/src/UART")
