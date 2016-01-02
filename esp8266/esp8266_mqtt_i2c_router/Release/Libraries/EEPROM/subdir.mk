################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/EEPROM/EEPROM.cpp 

LINK_OBJ += \
./Libraries/EEPROM/EEPROM.cpp.o 

CPP_DEPS += \
./Libraries/EEPROM/EEPROM.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/EEPROM/EEPROM.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/EEPROM/EEPROM.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/tools/sdk/include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/EEPROM" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/libraries/Wire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


