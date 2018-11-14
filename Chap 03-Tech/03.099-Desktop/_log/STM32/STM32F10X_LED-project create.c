STM32F10X_LED project setting, for openOCD, on-chip-debug.
//stm32f10x_hd_256k_48k_flash.ld
//MBS_CC_TOOLCHAIN is [gcc-arm-none-eabi-4_9-2015q3]

1)  File -> New -> C++ Project.
2)  Project Name: STM32F10X_LED.
	Project Type: STM32F10x C/C++ Project. 
	Toolchains  : Cross ARM GCC. //NOT 'CYGWIN GCC'.				!!!
3)  Target processor settings:
	Medium Density,
	Flash,
	ram,
	External clock (Hz)	: 16000000.
	Content				: Blinky a led. !!!
	Use system calls	: Freestanding. 
		(POSIX是可移植操作系统接口（Portable Operating System Interface）)
		(Semihosting (POSIX system calls via host.))
	Trace output		: no trace ouput.
		(Semihosting DEBUG.)
4)  Folder settings: ...
5)  Select Configuratinos: ...
6)  Toolchain name: //GNU Tools for ARM Embedded Processors (arm-none-eabi-gcc)
	Toolchain path: //C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin
7)  Finish.	

11) Project Properties:
	C/C++ Build:
		Environment: PATH += TOOLCHAIN PATH; + MAKE.EXE PATH.
		//C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\; 	!!!
		//C:\mbs\programs\cygwin\bin;								!!!
	Settings:
		Cross ARM Assembler    : //HSE_VALUE=16000000.
		Cross ARM C   Compiler : //HSE_VALUE=16000000.
		Cross ARM C++ Compiler : //HSE_VALUE=16000000.
		Build Steps: post-build steps: command: 
		//arm-none-eabi-objcopy -S -O binary "${ProjName}.hex" "${ProjName}.bin"
		
12) Debug cofiguration:
	C/C++ Application: xxx.elf.  !!!
13) C/C++ general => Paths and Symbols => HSE_VALUE 16000000.