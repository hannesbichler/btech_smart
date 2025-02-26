# CMake instructions to make the shared lib
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)

project(btech_smart C)

# Set the C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files to the project
set(SOURCE_FILES
   src/btech_iec_program.c
)

# Add the header files to the project
set(HEADER_FILES
  src/btech_iec_global.h
)

include_directories(
	include
	../btech_iec_runtime/include
	../btech_hardware/include
	../btech_ur20_modbus/include
)

ADD_LIBRARY( btech_smart SHARED ${HEADER_FILES} ${SOURCE_FILES})