################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := btech_smart
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: btech_smart

# Tool invocations
btech_smart: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-linux-gnueabihf-gcc -L/usr/arm-linux-gnueabihf/lib -L"C:\BTech\cpp\btech_smart\btech_iec_runtime\Debug" -L"C:\BTech\cpp\btech_smart\btech_hardware\Debug" -L"C:\BTech\cpp\btech_smart\btech_ur20_modbus\Debug" -o "btech_smart" $(OBJS) $(USER_OBJS) $(LIBS) -lpthread -lbtech_iec_runtime -lbtech_hardware -lbtech_iec_client -lbtech_ur20_modbus
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) btech_smart
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
