################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../esp8266_mqtt_i2c_router.cpp 

LINK_OBJ += \
./esp8266_mqtt_i2c_router.cpp.o 

CPP_DEPS += \
./esp8266_mqtt_i2c_router.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
esp8266_mqtt_i2c_router.cpp.o: ../esp8266_mqtt_i2c_router.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


