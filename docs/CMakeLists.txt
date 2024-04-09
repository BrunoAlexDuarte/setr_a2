set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(LibsDoc
    "${PROJECT_SOURCE_DIR}/src/sensors"
    "${PROJECT_SOURCE_DIR}/src/UART")
