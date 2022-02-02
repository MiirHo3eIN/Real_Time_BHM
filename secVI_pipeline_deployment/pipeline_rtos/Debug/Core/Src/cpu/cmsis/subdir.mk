################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/cpu/cmsis/arm_fill_f32.c \
../Core/Src/cpu/cmsis/arm_mat_init_f32.c \
../Core/Src/cpu/cmsis/arm_mat_mult_f32.c \
../Core/Src/cpu/cmsis/arm_mat_scale_f32.c \
../Core/Src/cpu/cmsis/arm_mat_sub_f32.c \
../Core/Src/cpu/cmsis/arm_mat_trans_f32.c \
../Core/Src/cpu/cmsis/arm_mean_f32.c \
../Core/Src/cpu/cmsis/arm_power_f32.c \
../Core/Src/cpu/cmsis/arm_std_f32.c 

OBJS += \
./Core/Src/cpu/cmsis/arm_fill_f32.o \
./Core/Src/cpu/cmsis/arm_mat_init_f32.o \
./Core/Src/cpu/cmsis/arm_mat_mult_f32.o \
./Core/Src/cpu/cmsis/arm_mat_scale_f32.o \
./Core/Src/cpu/cmsis/arm_mat_sub_f32.o \
./Core/Src/cpu/cmsis/arm_mat_trans_f32.o \
./Core/Src/cpu/cmsis/arm_mean_f32.o \
./Core/Src/cpu/cmsis/arm_power_f32.o \
./Core/Src/cpu/cmsis/arm_std_f32.o 

C_DEPS += \
./Core/Src/cpu/cmsis/arm_fill_f32.d \
./Core/Src/cpu/cmsis/arm_mat_init_f32.d \
./Core/Src/cpu/cmsis/arm_mat_mult_f32.d \
./Core/Src/cpu/cmsis/arm_mat_scale_f32.d \
./Core/Src/cpu/cmsis/arm_mat_sub_f32.d \
./Core/Src/cpu/cmsis/arm_mat_trans_f32.d \
./Core/Src/cpu/cmsis/arm_mean_f32.d \
./Core/Src/cpu/cmsis/arm_power_f32.d \
./Core/Src/cpu/cmsis/arm_std_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/cpu/cmsis/arm_fill_f32.o: ../Core/Src/cpu/cmsis/arm_fill_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_fill_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mat_init_f32.o: ../Core/Src/cpu/cmsis/arm_mat_init_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mat_init_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mat_mult_f32.o: ../Core/Src/cpu/cmsis/arm_mat_mult_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mat_mult_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mat_scale_f32.o: ../Core/Src/cpu/cmsis/arm_mat_scale_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mat_scale_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mat_sub_f32.o: ../Core/Src/cpu/cmsis/arm_mat_sub_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mat_sub_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mat_trans_f32.o: ../Core/Src/cpu/cmsis/arm_mat_trans_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mat_trans_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_mean_f32.o: ../Core/Src/cpu/cmsis/arm_mean_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_mean_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_power_f32.o: ../Core/Src/cpu/cmsis/arm_power_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_power_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/cpu/cmsis/arm_std_f32.o: ../Core/Src/cpu/cmsis/arm_std_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -D__FPU_PRESENT -DSTM32L476xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Core/Inc/pca_hpca -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Include -I../Core/Inc -I../Core/Inc/FreeRTOS -I../Core/Inc/cmsis -I../Core/Inc/peripherals -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/cpu/cmsis/arm_std_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

