# CMake instructions to make the shared lib
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)

project(ur20_modbus C)

# Add the source files to the project
set(SOURCE_FILES
  src/btech_ur20_modbus_device.c
  src/btech_ur20_modules.c
)

# Add the header files to the project
set(HEADER_FILES
  include/btech_ur20_modbus_device.h
  include/btech_ur20_modules.h
)

include_directories(
	include
	../btech_iec_runtime/include
	../btech_hardware/include
)

ADD_LIBRARY( ur20_modbus SHARED ${HEADER_FILES} ${SOURCE_FILES})