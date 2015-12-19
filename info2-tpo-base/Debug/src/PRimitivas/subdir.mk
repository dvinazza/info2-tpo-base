################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PRimitivas/PR_Display7Seg.c \
../src/PRimitivas/PR_MaquinaTimers.c \
../src/PRimitivas/PR_Teclado.c 

OBJS += \
./src/PRimitivas/PR_Display7Seg.o \
./src/PRimitivas/PR_MaquinaTimers.o \
./src/PRimitivas/PR_Teclado.o 

C_DEPS += \
./src/PRimitivas/PR_Display7Seg.d \
./src/PRimitivas/PR_MaquinaTimers.d \
./src/PRimitivas/PR_Teclado.d 


# Each subdirectory must supply rules for building sources it contributes
src/PRimitivas/%.o: ../src/PRimitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Facultad\Info II\TPO\TPO\src\FW_Drivers" -I"C:\Facultad\Info II\TPO\TPO\src\Aplicacion" -I"C:\Facultad\Info II\TPO\TPO\src\Headers" -I"C:\Facultad\Info II\TPO\TPO\src\FW_Inicializaciones" -I"C:\Facultad\Info II\TPO\TPO\src\PRimitivas" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


