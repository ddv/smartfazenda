################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/arduino.ar \

ELF += \
smartfazenda_well.elf \

EEP += \
smartfazenda_well.eep \

FLASH_IMAGE += \
smartfazenda_well.hex \


# All Target
all: smartfazenda_well

# Tool invocations
smartfazenda_well: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-size" -A "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-ar" rcs "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_well.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.elf"   $(LINK_OBJ) $(AR)  "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/arduino.ar" "-L/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_well.eep: $(ELF)
	@echo 'Create eeprom image'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.elf" "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.eep"
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_well.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.elf" "/home/ddv/git/smartfazenda/arduino/smartfazenda_well/Release/smartfazenda_well.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(C++_DEPS)$(ELF)$(CC_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) smartfazenda_well
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
