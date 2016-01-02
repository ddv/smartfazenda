################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/opt/arduino/lib/Adafruit_CC3000/Adafruit_CC3000.cpp \
/opt/arduino/lib/Adafruit_CC3000/Adafruit_CC3000_Server.cpp \
/opt/arduino/lib/Adafruit_CC3000/ccspi.cpp 

CPP_DEPS += \
./Libraries/Adafruit_CC3000/Adafruit_CC3000.cpp.d \
./Libraries/Adafruit_CC3000/Adafruit_CC3000_Server.cpp.d \
./Libraries/Adafruit_CC3000/ccspi.cpp.d 

LINK_OBJ += \
./Libraries/Adafruit_CC3000/Adafruit_CC3000.cpp.o \
./Libraries/Adafruit_CC3000/Adafruit_CC3000_Server.cpp.o \
./Libraries/Adafruit_CC3000/ccspi.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Adafruit_CC3000/Adafruit_CC3000.cpp.o: /opt/arduino/lib/Adafruit_CC3000/Adafruit_CC3000.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/Adafruit_CC3000_Server.cpp.o: /opt/arduino/lib/Adafruit_CC3000/Adafruit_CC3000_Server.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Libraries/Adafruit_CC3000/ccspi.cpp.o: /opt/arduino/lib/Adafruit_CC3000/ccspi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


