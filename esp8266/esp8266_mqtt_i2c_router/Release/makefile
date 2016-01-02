################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/spiffs/subdir.mk
-include arduino/core/subdir.mk
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
esp8266_mqtt_i2c_router.elf \

EEP += \
esp8266_mqtt_i2c_router.eep \

FLASH_IMAGE += \
esp8266_mqtt_i2c_router.hex \


# All Target
all: esp8266_mqtt_i2c_router

# Tool invocations
esp8266_mqtt_i2c_router: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	${JANTJE.SIZE.SWITCH}
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	$(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	$(LINK_OBJ) $(AR)
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) esp8266_mqtt_i2c_router
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
