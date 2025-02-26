################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/btech_ur20_modbus_device.c \
../src/btech_ur20_modules.c 

C_DEPS += \
./src/btech_ur20_modbus_device.d \
./src/btech_ur20_modules.d 

OBJS += \
./src/btech_ur20_modbus_device.o \
./src/btech_ur20_modules.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"C:\BTech\cpp\btech_smart\btech_ur20_modbus\include" -I"C:\BTech\cpp\btech_smart\btech_hardware\include" -I"C:\BTech\cpp\btech_smart\btech_iec_runtime\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/btech_ur20_modbus_device.d ./src/btech_ur20_modbus_device.o ./src/btech_ur20_modules.d ./src/btech_ur20_modules.o

.PHONY: clean-src

