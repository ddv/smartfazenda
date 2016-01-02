################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../i2c_slave.cpp 

LINK_OBJ += \
./i2c_slave.cpp.o 

CPP_DEPS += \
./i2c_slave.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
i2c_slave.cpp.o: ../i2c_slave.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire/utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


