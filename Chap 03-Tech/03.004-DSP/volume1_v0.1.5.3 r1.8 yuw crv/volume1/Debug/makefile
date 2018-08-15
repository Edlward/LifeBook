################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv5/tools/compiler/c2000_6.1.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"E:/_workroom/0101-SIMU/volume1_v0.1.5.3 r1.8 yuw crv/CMD/volume.cmd" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/simu_crv.obj" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/drv_load.obj" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/cpu_vectors.obj" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/calc_cpid.obj" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/appl_volume.obj" \
"E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug/appl_main.obj" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include SOURCE/subdir_vars.mk
-include CMD/subdir_vars.mk
-include subdir_rules.mk
-include SOURCE/subdir_rules.mk
-include CMD/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: E:/_workroom/0101-SIMU/volume1_v0.1.5.3\ r1.8\ yuw\ crv/volume1/../Debug/volume1.out

# Tool invocations
E:/_workroom/0101-SIMU/volume1_v0.1.5.3\ r1.8\ yuw\ crv/volume1/../Debug/volume1.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --display_error_number --obj_directory="E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug" -z -m"volume1.map" --heap_size=0x200 --warn_sections -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/lib" -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/include" -i"E:/_workroom/0101-SIMU/volume1_v0.1.5.3 r1.8 yuw crv/volume1" -i"E:/_workroom/0101-SIMU/volume1_v0.1.5.3 r1.8 yuw crv" --reread_libs --display_error_number --rom_model -o "E:/_workroom/0101-SIMU/volume1_v0.1.5.3 r1.8 yuw crv/volume1/../Debug/volume1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "E:\_workroom\0101-SIMU\volume1_v0.1.5.3 r1.8 yuw crv\Debug\volume1.out"
	-$(RM) "SOURCE\appl_main.pp" "SOURCE\appl_volume.pp" "SOURCE\calc_cpid.pp" "SOURCE\simu_crv.pp" 
	-$(RM) "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\appl_main.obj" "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\appl_volume.obj" "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\calc_cpid.obj" "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\cpu_vectors.obj" "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\drv_load.obj" "E:\huamg\_prgm\volume1_v0.1.5.2 cpid rang50\Debug\simu_crv.obj" 
	-$(RM) "SOURCE\cpu_vectors.pp" "SOURCE\drv_load.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
