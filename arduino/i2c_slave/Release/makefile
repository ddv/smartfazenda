################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
i2c_slave.elf \

EEP += \
i2c_slave.eep \

FLASH_IMAGE += \
i2c_slave.hex \


# All Target
all: i2c_slave

# Tool invocations
i2c_slave: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-size" -A "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-ar" rcs  "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

i2c_slave.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.elf"   $(LINK_OBJ) $(AR)  "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/arduino.ar" "-L/home/ddv/git/smartfazenda/arduino/i2c_slave/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

i2c_slave.eep: $(ELF)
	@echo 'Create eeprom image'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.elf" "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.eep"
	@echo 'Finished building: $@'
	@echo ' '

i2c_slave.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.elf" "/home/ddv/git/smartfazenda/arduino/i2c_slave/Release/i2c_slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) i2c_slave
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
