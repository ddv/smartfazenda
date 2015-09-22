################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/ESP8266WiFi.cpp \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiClient.cpp \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiServer.cpp \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiUdp.cpp 

LINK_OBJ += \
./Libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.o \
./Libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.o \
./Libraries/ESP8266WiFi/src/WiFiClient.cpp.o \
./Libraries/ESP8266WiFi/src/WiFiServer.cpp.o \
./Libraries/ESP8266WiFi/src/WiFiUdp.cpp.o 

CPP_DEPS += \
./Libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.d \
./Libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.d \
./Libraries/ESP8266WiFi/src/WiFiClient.cpp.d \
./Libraries/ESP8266WiFi/src/WiFiServer.cpp.d \
./Libraries/ESP8266WiFi/src/WiFiUdp.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/ESP8266WiFi/src/ESP8266WiFi.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/ESP8266WiFi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/ESP8266WiFiMulti.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/ESP8266WiFi/src/WiFiClient.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiClient.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/ESP8266WiFi/src/WiFiServer.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiServer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/ESP8266WiFi/src/WiFiUdp.cpp.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src/WiFiUdp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/ddv/.arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=10605 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266  -DESP8266   -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/variants/generic" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/ESP8266WiFi/src" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/1.6.5-947-g39819f0/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient" -I"/opt/arduino/arduino-1.6.5-r5/libraries/pubsubclient/src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


