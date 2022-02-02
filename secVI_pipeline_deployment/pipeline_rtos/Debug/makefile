################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/peripherals/subdir.mk
-include Core/Src/pca_hpca/subdir.mk
-include Core/Src/cpu/sys_management/subdir.mk
-include Core/Src/cpu/interrupt/subdir.mk
-include Core/Src/cpu/cmsis/subdir.mk
-include Core/Src/cpu/HAL_lib/subdir.mk
-include Core/Src/FreeRTOS/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PCA_HPCA.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PCA_HPCA.list \

OBJCOPY_BIN += \
PCA_HPCA.bin \


# All Target
all: PCA_HPCA.elf secondary-outputs

# Tool invocations
PCA_HPCA.elf: $(OBJS) $(USER_OBJS) C:\Users\amirh\CubeIDE\workspace13_1\PCA_HPCA\STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "PCA_HPCA.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\amirh\CubeIDE\workspace13_1\PCA_HPCA\STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PCA_HPCA.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PCA_HPCA.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PCA_HPCA.list"
	@echo 'Finished building: $@'
	@echo ' '

PCA_HPCA.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PCA_HPCA.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
