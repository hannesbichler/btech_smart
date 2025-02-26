# CMake instructions to make the shared lib
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)

project(btech_iec_runtime C)

# Set the C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set (CMAKE_C_STANDARD 90)


# Add the source files to the project
set(SOURCE_FILES
  src/btech_iec_datapoints.c
  src/btech_iec_function_library.c
  src/btech_iec_logger.c
  src/btech_iec_memory_mapper.c
  src/btech_iec_program.c
  src/btech_iec_runtime.c
  src/btech_system_call.c
)

# Add the header files to the project
set(HEADER_FILES
  include/btech_iec_constants.h
  include/btech_iec_datapoints.h
  include/btech_iec_function_library.h
  include/btech_iec_logger.h
  include/btech_iec_memory_mapper.h
  include/btech_iec_program.h
  include/btech_iec_runtime.h
)

include_directories(include)

ADD_LIBRARY( btech_iec_runtime SHARED ${HEADER_FILES} ${SOURCE_FILES})
# CMake instructions to test using the static lib
#SET( APP_EXE StaticTest )...