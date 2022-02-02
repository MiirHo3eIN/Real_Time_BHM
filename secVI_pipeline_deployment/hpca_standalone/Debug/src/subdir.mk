################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Function_qr.c \
../src/main.c \
../src/pca.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/Function_qr.o \
./src/main.o \
./src/pca.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/Function_qr.d \
./src/main.d \
./src/pca.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F4DISCOVERY -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -I"C:/Users/aless/Desktop/workspace/Floating_HPCA/Utilities" -I"C:/Users/aless/Desktop/workspace/Floating_HPCA/StdPeriph_Driver/inc" -I"C:/Users/aless/Desktop/workspace/Floating_HPCA/inc" -I"C:/Users/aless/Desktop/workspace/Floating_HPCA/CMSIS/device" -I"C:/Users/aless/Desktop/workspace/Floating_HPCA/CMSIS/core" -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


