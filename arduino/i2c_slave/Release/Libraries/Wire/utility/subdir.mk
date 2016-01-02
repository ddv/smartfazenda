################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire/utility/twi.c 

C_DEPS += \
./Libraries/Wire/utility/twi.c.d 

LINK_OBJ += \
./Libraries/Wire/utility/twi.c.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Wire/utility/twi.c.o: /opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire/utility/twi.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/arduino/arduino-1.6.5-r5/hardware/tools/avr/bin/avr-gcc" -c -g -Os -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/variants/eightanaloginputs" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.6.5-r5/hardware/arduino/avr/libraries/Wire/utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


