################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_cache.c \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_check.c \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_gc.c \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_hydrogen.c \
/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_nucleus.c 

C_DEPS += \
./arduino/spiffs_cache.c.d \
./arduino/spiffs_check.c.d \
./arduino/spiffs_gc.c.d \
./arduino/spiffs_hydrogen.c.d \
./arduino/spiffs_nucleus.c.d 

AR_OBJ += \
./arduino/spiffs_cache.c.o \
./arduino/spiffs_check.c.o \
./arduino/spiffs_gc.c.o \
./arduino/spiffs_hydrogen.c.o \
./arduino/spiffs_nucleus.c.o 


# Each subdirectory must supply rules for building sources it contributes
arduino/spiffs_cache.c.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_cache.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_check.c.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_check.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_gc.c.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_gc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_hydrogen.c.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_hydrogen.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/spiffs_nucleus.c.o: /home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266/spiffs/spiffs_nucleus.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/cores/esp8266" -I"/home/ddv/.arduino15/packages/esp8266/hardware/esp8266/2.0.0/variants/generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


