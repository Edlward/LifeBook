################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
LIB/rts2800_ml.exe: E:/_workroom/0101-SIMU/0101-SIMU/volume1_v0.1.5.3\ r1.7\ yuww/LIB/rts2800_ml.lib $(GEN_CMDS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --display_error_number --obj_directory="E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug" -z -m"volume1.map" --heap_size=0x200 --warn_sections -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/lib" -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.0/include" -i"E:/_workroom/0101-SIMU/0101-SIMU/volume1_v0.1.5.3 r1.7 yuww/volume1" -i"E:/_workroom/0101-SIMU/0101-SIMU/volume1_v0.1.5.3 r1.7 yuww" --reread_libs --display_error_number --rom_model -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


