# CMakeLists.txt: example for developing modular SW
# Paulo Pedreiras, 2024/Apr

# Set CMAKE minimum required version 
cmake_minimum_required(VERSION 3.10)

# set the project name
project(SmartSensor
        VERSION 1.0
        DESCRIPTION "Processes commands received via UART, one character at a time."
        LANGUAGES C)

# Ask if the user wants to generate documentation
option(GENERATE_DOC "Generate Doxygen documentation for the project?")

# Ask for treating warnings as errors and for additional warnings. Default value is off
option(WARN_GENERATE_ERR "Extra warnings and warnings generate errors?" ON)

if(GENERATE_DOC)
	# Generate documentation if Doxygen is found
	find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)
	if(Doxygen_FOUND)
		message(STATUS "Doxygen was found, will build docs")
		add_subdirectory(docs)
	else()
		message(STATUS "Doxygen not found, not building docs")
	endif()
endif()


# CMake will look for a CMakeLists.txt in that folder and will process it
add_subdirectory(src/sensors)
add_subdirectory(src/UART)

# Generate executable "libdemo" from source file "main.c"
add_executable(libdemo src/main.c)

# Generate variables with set of libs and include folders
# Dependencies for libraries files are automatically set 

list(APPEND EXTRA_LIBS SensorsLib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/sensors")

list(APPEND EXTRA_LIBS UARTLib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/UART")

# Specify libraries or flags to use when linking a given target 
# and/or its dependents
target_link_libraries(libdemo PUBLIC ${EXTRA_LIBS})

# Specifies include directories to use when compiling a given target
target_include_directories(libdemo PUBLIC ${EXTRA_INCLUDES})

# Set compiler options for module
if(WARN_GENERATE_ERR)
	message("-- Extra warnings and warnings treated as errors active")
	target_compile_options(libdemo
		PRIVATE
		-Wall -Werror
	)
endif()
