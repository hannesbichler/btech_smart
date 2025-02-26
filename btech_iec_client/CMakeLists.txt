# CMake instructions to make the shared lib
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)

project(btech_iec_client C)

# Add the source files to the project
set(SOURCE_FILES
  src/btech_iec_client.c
  src/btech_iec_client_connections.c
)

# Add the header files to the project
set(HEADER_FILES
  include/btech_iec_client.h
  include/btech_iec_client_connections.h
)

include_directories(include
	../btech_iec_runtime/include
	C:/MinGW/include
)

ADD_LIBRARY( btech_iec_client SHARED ${HEADER_FILES} ${SOURCE_FILES})
# CMake instructions to test using the static lib
#SET( APP_EXE StaticTest )...