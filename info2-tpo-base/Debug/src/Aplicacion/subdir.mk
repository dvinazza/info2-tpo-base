################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Aplicacion/Funciones_APP.c \
../src/Aplicacion/TmrEvent.c \
../src/Aplicacion/Trama.c \
../src/Aplicacion/main.c \
../src/Aplicacion/maquina.c 

OBJS += \
./src/Aplicacion/Funciones_APP.o \
./src/Aplicacion/TmrEvent.o \
./src/Aplicacion/Trama.o \
./src/Aplicacion/main.o \
./src/Aplicacion/maquina.o 

C_DEPS += \
./src/Aplicacion/Funciones_APP.d \
./src/Aplicacion/TmrEvent.d \
./src/Aplicacion/Trama.d \
./src/Aplicacion/main.d \
./src/Aplicacion/maquina.d 


# Each subdirectory must supply rules for building sources it contributes
src/Aplicacion/%.o: ../src/Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Facultad\Info II\TPO\TPO\src\FW_Drivers" -I"C:\Facultad\Info II\TPO\TPO\src\Aplicacion" -I"C:\Facultad\Info II\TPO\TPO\src\Headers" -I"C:\Facultad\Info II\TPO\TPO\src\FW_Inicializaciones" -I"C:\Facultad\Info II\TPO\TPO\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


