################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CMD/volume.exe: C:/mbs/zs_github/LifeBook/Chap\ 03-Tech/03.004-DSP/volume1_v0.1.5.3\ r1.8\ yuw\ crv/CMD/volume.cmd $(GEN_CMDS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Linker'
	"C:/TI/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/bin/cl2000" -v28 -ml -mt -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --display_error_number --obj_directory="E:/huamg/_prgm/volume1_v0.1.5.2 cpid rang50/Debug" -z -m"volume1.map" --heap_size=0x200 --warn_sections -i"C:/TI/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/lib" -i"C:/TI/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" -i"C:/mbs/zs_github/LifeBook/Chap 03-Tech/03.004-DSP/volume1_v0.1.5.3 r1.8 yuw crv/volume1" -i"C:/mbs/zs_github/LifeBook/Chap 03-Tech/03.004-DSP/volume1_v0.1.5.3 r1.8 yuw crv" --reread_libs --display_error_number --xml_link_info="C:/mbs/zs_github/LifeBook/Chap 03-Tech/03.004-DSP/volume1_v0.1.5.3 r1.8 yuw crv/Debug/volume1_linkInfo.xml" --rom_model -o "$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


