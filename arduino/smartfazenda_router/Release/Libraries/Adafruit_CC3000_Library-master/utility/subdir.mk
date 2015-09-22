################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/cc3000_common.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/debug.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/evnt_handler.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/hci.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/netapp.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/nvmem.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/security.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/socket.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/wlan.cpp 

CPP_DEPS += \
./Libraries/Adafruit_CC3000_Library-master/utility/cc3000_common.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/debug.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/evnt_handler.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/hci.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/netapp.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/nvmem.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/security.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/socket.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/utility/wlan.cpp.d 

LINK_OBJ += \
./Libraries/Adafruit_CC3000_Library-master/utility/cc3000_common.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/debug.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/evnt_handler.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/hci.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/netapp.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/nvmem.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/security.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/socket.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/utility/wlan.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Adafruit_CC3000_Library-master/utility/cc3000_common.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/cc3000_common.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/debug.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/debug.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/evnt_handler.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/evnt_handler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/hci.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/hci.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/netapp.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/netapp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/nvmem.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/nvmem.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/security.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/security.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/socket.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/socket.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/utility/wlan.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/utility/wlan.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


