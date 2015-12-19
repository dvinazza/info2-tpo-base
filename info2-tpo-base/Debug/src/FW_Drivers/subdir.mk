################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Drivers/DR_Display.c \
../src/FW_Drivers/DR_Teclado.c \
../src/FW_Drivers/DR_UART.c \
../src/FW_Drivers/FW_GPIO.c \
../src/FW_Drivers/FW_Systick.c \
../src/FW_Drivers/FW_UART.c 

OBJS += \
./src/FW_Drivers/DR_Display.o \
./src/FW_Drivers/DR_Teclado.o \
./src/FW_Drivers/DR_UART.o \
./src/FW_Drivers/FW_GPIO.o \
./src/FW_Drivers/FW_Systick.o \
./src/FW_Drivers/FW_UART.o 

C_DEPS += \
./src/FW_Drivers/DR_Display.d \
./src/FW_Drivers/DR_Teclado.d \
./src/FW_Drivers/DR_UART.d \
./src/FW_Drivers/FW_GPIO.d \
./src/FW_Drivers/FW_Systick.d \
./src/FW_Drivers/FW_UART.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Drivers/%.o: ../src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Facultad\Info II\TPO\TPO\src\FW_Drivers" -I"C:\Facultad\Info II\TPO\TPO\src\Aplicacion" -I"C:\Facultad\Info II\TPO\TPO\src\Headers" -I"C:\Facultad\Info II\TPO\TPO\src\FW_Inicializaciones" -I"C:\Facultad\Info II\TPO\TPO\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


