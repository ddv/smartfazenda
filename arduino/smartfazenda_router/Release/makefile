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
-include Libraries/cc3000_PubSubClient/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include Libraries/SPI/subdir.mk
-include Libraries/Adafruit_CC3000_Library-master/utility/subdir.mk
-include Libraries/Adafruit_CC3000_Library-master/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/arduino.ar \

ELF += \
smartfazenda_router.elf \

EEP += \
smartfazenda_router.eep \

FLASH_IMAGE += \
smartfazenda_router.hex \


# All Target
all: smartfazenda_router

# Tool invocations
smartfazenda_router: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-size" -A "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-ar" rcs "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_router.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.elf"   $(LINK_OBJ) $(AR)  "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/arduino.ar" "-LC:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_router.eep: $(ELF)
	@echo 'Create eeprom image'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.elf" "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.eep"
	@echo 'Finished building: $@'
	@echo ' '

smartfazenda_router.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.elf" "C:/Users/derenok_dv/git/smartfazenda/arduino/smartfazenda_router/Release/smartfazenda_router.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ELF)$(ASM_DEPS)$(CC_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) smartfazenda_router
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
