################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI/SPI.cpp 

CPP_DEPS += \
./Libraries/SPI/SPI.cpp.d 

LINK_OBJ += \
./Libraries/SPI/SPI.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/SPI/SPI.cpp.o: /opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI/SPI.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


