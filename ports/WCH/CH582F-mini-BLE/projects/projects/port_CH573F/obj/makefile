################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include StdPeriphDriver/subdir.mk
-include Startup/subdir.mk
-include RVMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
port_CH573F.hex \

SECONDARY_LIST += \
port_CH573F.lst \

SECONDARY_SIZE += \
port_CH573F.siz \


# All Target
all: port_CH573F.elf secondary-outputs

# Tool invocations
port_CH573F.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused  -g -T "C:\Users\USER\repos\aixt_ccgg\ports\WCH\CH573F-mini-BLE\projects\port_CH573F\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"C:\Users\USER\repos\aixt_ccgg\ports\WCH\CH573F-mini-BLE\projects\port_CH573F\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"port_CH573F.map" --specs=nano.specs --specs=nosys.specs -o "port_CH573F.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
port_CH573F.hex: port_CH573F.elf
	@	riscv-none-embed-objcopy -O ihex "port_CH573F.elf"  "port_CH573F.hex"
	@	@
port_CH573F.lst: port_CH573F.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "port_CH573F.elf" > "port_CH573F.lst"
	@	@
port_CH573F.siz: port_CH573F.elf
	@	riscv-none-embed-size --format=berkeley "port_CH573F.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) port_CH573F.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
