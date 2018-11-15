/****************************************************************************/
/*   volume.cmd - Sample linker command file for F28xx devices              */
/*                                                                          */
/*   Description: This file is a sample F28xx linker command file that can  */
/*                be used for linking programs built with the TMS320C2000   */
/*                C Compiler. Use it as a guideline; you may want to change */
/*                the allocation scheme according to the size of your       */
/*                program and the memory layout of your target system.      */
/****************************************************************************/
-stack 400

-heap 400
MEMORY
{
   PAGE 0 : PROG(R)     : origin = 0x3E8000, length = 0x10000
   PAGE 0 : BOOT(R)     : origin = 0x3FF000, length = 0xFC0   
   PAGE 0 : RESET(R)    : origin = 0x3FFFC0, length = 0x2
   PAGE 0 : VECTORS(R)  : origin = 0x3FFFC2, length = 0x3E

   PAGE 1 : M0RAM(RW)   : origin = 0x000000, length = 0x400
   PAGE 1 : M1RAM(RW)   : origin = 0x000400, length = 0x400
   PAGE 1 : L0L1RAM(RW) : origin = 0x008000, length = 0x2000
   PAGE 1 : H0RAM(RW)   : origin = 0x3F8000, length = 0x2000
}
 
SECTIONS
{
   /* 22-bit program sections */
   .reset   : > RESET,   PAGE = 0
   .vectors : > VECTORS, PAGE = 0
   .pinit   : > PROG,    PAGE = 0
   .cinit   : > PROG,    PAGE = 0
   .text    : > PROG,    PAGE = 0

   /* 16-Bit data sections */
   .const   : > L0L1RAM, PAGE = 1
   .bss     : > L0L1RAM, PAGE = 1
   .stack   : > M1RAM, PAGE = 1
   .sysmem  : > M0RAM, PAGE = 1
   .cio     : > M0RAM, PAGE = 1

   /* 32-bit data sections */
   .ebss    : > H0RAM, PAGE = 1
   .econst  : > H0RAM, PAGE = 1
   .esysmem : > H0RAM, PAGE = 1
}
