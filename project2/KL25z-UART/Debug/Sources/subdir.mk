################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/cbuff.c \
../Sources/led.c \
../Sources/logger.c \
../Sources/main.c \
../Sources/rxtestled.c \
../Sources/uart.c 

OBJS += \
./Sources/cbuff.o \
./Sources/led.o \
./Sources/logger.o \
./Sources/main.o \
./Sources/rxtestled.o \
./Sources/uart.o 

C_DEPS += \
./Sources/cbuff.d \
./Sources/led.d \
./Sources/logger.d \
./Sources/main.d \
./Sources/rxtestled.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


