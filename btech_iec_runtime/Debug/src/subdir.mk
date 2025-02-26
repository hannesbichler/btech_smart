################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/btech_iec_datapoints.c \
../src/btech_iec_function_library.c \
../src/btech_iec_logger.c \
../src/btech_iec_memory_mapper.c \
../src/btech_iec_program.c \
../src/btech_iec_runtime.c \
../src/btech_system_call.c 

C_DEPS += \
./src/btech_iec_datapoints.d \
./src/btech_iec_function_library.d \
./src/btech_iec_logger.d \
./src/btech_iec_memory_mapper.d \
./src/btech_iec_program.d \
./src/btech_iec_runtime.d \
./src/btech_system_call.d 

OBJS += \
./src/btech_iec_datapoints.o \
./src/btech_iec_function_library.o \
./src/btech_iec_logger.o \
./src/btech_iec_memory_mapper.o \
./src/btech_iec_program.o \
./src/btech_iec_runtime.o \
./src/btech_system_call.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"C:\BTech\cpp\btech_smart\btech_iec_runtime\include" -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/btech_iec_datapoints.d ./src/btech_iec_datapoints.o ./src/btech_iec_function_library.d ./src/btech_iec_function_library.o ./src/btech_iec_logger.d ./src/btech_iec_logger.o ./src/btech_iec_memory_mapper.d ./src/btech_iec_memory_mapper.o ./src/btech_iec_program.d ./src/btech_iec_program.o ./src/btech_iec_runtime.d ./src/btech_iec_runtime.o ./src/btech_system_call.d ./src/btech_system_call.o

.PHONY: clean-src

