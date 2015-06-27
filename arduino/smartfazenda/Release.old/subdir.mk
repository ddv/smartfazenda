################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../smartfazenda.cpp 

CPP_DEPS += \
./smartfazenda.cpp.d 

LINK_OBJ += \
./smartfazenda.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
smartfazenda.cpp.o: ../smartfazenda.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"E:/arduino/arduino-1.5.6-r2/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=156-r2 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/E:/arduino/arduino-1.5.6-r2/hardware/arduino/avr/cores/arduino" -I"/E:/arduino/arduino-1.5.6-r2/hardware/arduino/avr/variants/standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


