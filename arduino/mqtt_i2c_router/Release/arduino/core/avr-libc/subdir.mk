################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/malloc.c \
/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/realloc.c 

C_DEPS += \
./arduino/malloc.c.d \
./arduino/realloc.c.d 

AR_OBJ += \
./arduino/malloc.c.o \
./arduino/realloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
arduino/malloc.c.o: /opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

arduino/realloc.c.o: /opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino/avr-libc/realloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-gcc" -c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -I"/opt/arduino/lib/Adafruit_CC3000" -I"/opt/arduino/lib/Adafruit_CC3000/utility" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/SPI" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire" -I"/opt/arduino/arduino-1.5.6-r2/hardware/arduino/avr/libraries/Wire/utility" -I"/opt/arduino/lib/cc3000_PubSubClient" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


