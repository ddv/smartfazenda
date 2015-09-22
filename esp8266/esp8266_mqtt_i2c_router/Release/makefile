################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/spiffs/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/pubsubclient/src/subdir.mk
-include Libraries/Wire/subdir.mk
-include Libraries/ESP8266WiFi/src/subdir.mk
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
esp8266_mqtt_i2c_router.bin \


# All Target
all: esp8266_mqtt_i2c_router

# Tool invocations
esp8266_mqtt_i2c_router: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-size" -A "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/esp8266_mqtt_i2c_router.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-ar" cru  "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-gcc" -g -Os -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static "-L/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//lib" "-L/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//ld" "-Teagle.flash.512k.ld" -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy  -o "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/esp8266_mqtt_i2c_router.elf" -Wl,--start-group   $(LINK_OBJ) $(AR)  "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/arduino.ar" -lm -lgcc -lhal -lphy -lnet80211 -llwip -lwpa -lmain -lpp -lsmartconfig -lwps -lcrypto -Wl,--end-group  "-L/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release"
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

esp8266_mqtt_i2c_router.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/ddv/.arduino15/packages/esp8266/tools/esptool/0.4.5/esptool" -eo "/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/bootloaders/eboot/eboot.elf" -bo "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/esp8266_mqtt_i2c_router.bin" -bm qio -bf 40 -bz 512K -bs .text -bp 4096 -ec -eo "/home/ddv/workspace.luna/esp8266_mqtt_i2c_router/Release/esp8266_mqtt_i2c_router.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) esp8266_mqtt_i2c_router
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
