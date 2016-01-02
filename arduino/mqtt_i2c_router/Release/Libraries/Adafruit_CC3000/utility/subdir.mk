################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/opt/arduino/lib/Adafruit_CC3000/utility/cc3000_common.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/debug.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/evnt_handler.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/hci.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/netapp.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/nvmem.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/security.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/sntp.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/socket.cpp \
/opt/arduino/lib/Adafruit_CC3000/utility/wlan.cpp 

CPP_DEPS += \
./Libraries/Adafruit_CC3000/utility/cc3000_common.cpp.d \
./Libraries/Adafruit_CC3000/utility/debug.cpp.d \
./Libraries/Adafruit_CC3000/utility/evnt_handler.cpp.d \
./Libraries/Adafruit_CC3000/utility/hci.cpp.d \
./Libraries/Adafruit_CC3000/utility/netapp.cpp.d \
./Libraries/Adafruit_CC3000/utility/nvmem.cpp.d \
./Libraries/Adafruit_CC3000/utility/security.cpp.d \
./Libraries/Adafruit_CC3000/utility/sntp.cpp.d \
./Libraries/Adafruit_CC3000/utility/socket.cpp.d \
./Libraries/Adafruit_CC3000/utility/wlan.cpp.d 

LINK_OBJ += \
./Libraries/Adafruit_CC3000/utility/cc3000_common.cpp.o \
./Libraries/Adafruit_CC3000/utility/debug.cpp.o \
./Libraries/Adafruit_CC3000/utility/evnt_handler.cpp.o \
./Libraries/Adafruit_CC3000/utility/hci.cpp.o \
./Libraries/Adafruit_CC3000/utility/netapp.cpp.o \
./Libraries/Adafruit_CC3000/utility/nvmem.cpp.o \
./Libraries/Adafruit_CC3000/utility/security.cpp.o \
./Libraries/Adafruit_CC3000/utility/sntp.cpp.o \
./Libraries/Adafruit_CC3000/utility/socket.cpp.o \
./Libraries/Adafruit_CC3000/utility/wlan.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Adafruit_CC3000/utility/cc3000_common.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/cc3000_common.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/debug.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/debug.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/evnt_handler.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/evnt_handler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/hci.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/hci.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/netapp.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/netapp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/nvmem.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/nvmem.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/security.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/security.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/sntp.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/sntp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/socket.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/socket.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/utility/wlan.cpp.o: /opt/arduino/lib/Adafruit_CC3000/utility/wlan.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


