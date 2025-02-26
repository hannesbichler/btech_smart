# CMake instructions to make the shared lib
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)

project(btech_hardware C)

# Add the source files to the project
set(SOURCE_FILES
   src/btech_hardware.c
)

# Add the header files to the project
set(HEADER_FILES
	include/btech_hardware.h
)

include_directories(
	include
	../btech_iec_runtime/include
	../btech_hardware/include
	../btech_ur20_modbus/include
)

ADD_LIBRARY( btech_hardware SHARED ${HEADER_FILES} ${SOURCE_FILES})
# CMake instructions to test using the static lib
#SET( APP_EXE StaticTest )...