################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/arduino/libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000_Server.cpp \
E:/arduino/libraries/Adafruit_CC3000_Library-master/ccspi.cpp 

CPP_DEPS += \
./Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000_Server.cpp.d \
./Libraries/Adafruit_CC3000_Library-master/ccspi.cpp.d 

LINK_OBJ += \
./Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000_Server.cpp.o \
./Libraries/Adafruit_CC3000_Library-master/ccspi.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000_Server.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/Adafruit_CC3000_Server.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000_Library-master/ccspi.cpp.o: E:/arduino/libraries/Adafruit_CC3000_Library-master/ccspi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\cores\arduino" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\variants\standard" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master" -I"E:\arduino\libraries\Adafruit_CC3000_Library-master\utility" -I"E:\arduino\libraries\cc3000_PubSubClient" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\SPI" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire" -I"E:\arduino\arduino-1.5.6-r2\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

