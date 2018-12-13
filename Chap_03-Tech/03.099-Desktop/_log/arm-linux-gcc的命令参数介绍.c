(gcc-arm-none-eabi就是其中的编译器的功能，更专业的，在嵌入式开发中我们一般将它叫做工具链。
（工具链：一般由编译器、连接器、解释器和调试器组成）)

交叉编译工具链的命名规则为：arch [-vendor] [-os] [-(gnu)eabi]
    arch - 体系架构，如ARM，MIPS
    verdor - 工具链提供商
    os - 目标操作系统
    eabi - 嵌入式应用二进制接口

根据对操作系统的支持与否，ARM GCC可分为支持和不支持操作系统，如
    arm-none-eabi：这个是没有操作系统的，自然不可能支持那些跟操作系统关系密切的函数，比如fork(2)。
	他使用的是newlib这个专用于嵌入式系统的C库。

    arm-none-linux-eabi：用于Linux的，使用Glibc
	
/*** compiler tool:
实例:
1、arm-none-eabi-gcc
（ARM architecture，no vendor，not target an operating system，complies with the ARM EABI）
用于编译 ARM 架构的裸机系统（包括 ARM Linux 的 boot、kernel，不适用编译 Linux 应用 Application），
一般适合 ARM7、Cortex-M 和 Cortex-R 内核的芯片使用，所以不支持那些跟操作系统关系密切的函数，
比如fork(2)，他使用的是 newlib 这个专用于嵌入式系统的C库。

2、arm-none-linux-gnueabi-gcc
(ARM architecture, no vendor, creates binaries that run on the Linux operating system, and uses the GNU EABI)
主要用于基于ARM架构的Linux系统，可用于编译 ARM 架构的 u-boot、Linux内核、linux应用等。
arm-none-linux-gnueabi基于GCC，使用Glibc库，经过 Codesourcery 公司优化过推出的编译器。
arm-none-linux-gnueabi-xxx 交叉编译工具的浮点运算非常优秀。一般ARM9、ARM11、Cortex-A 内
核，带有 Linux 操作系统的会用到。

3、arm-eabi-gcc
Android ARM 编译器。

4、armcc
ARM 公司推出的编译工具，功能和 arm-none-eabi 类似，可以编译裸机程序（u-boot、kernel），
但是不能编译 Linux 应用程序。armcc一般和ARM开发工具一起，Keil MDK、ADS、RVDS和DS-5中
的编译器都是armcc，所以 armcc 编译器都是收费的（爱国版除外，呵呵~~）。

5、arm-none-uclinuxeabi-gcc 和 arm-none-symbianelf-gcc
arm-none-uclinuxeabi 用于uCLinux，使用Glibc。
arm-none-symbianelf 用于symbian，没用过，不知道C库是什么 。

Codesourcery:
Codesourcery推出的产品叫Sourcery G++ Lite Edition，其中基于command-line的编译器是免费的，在官网上可以下载，
而其中包含的IDE和debug 工具是收费的，当然也有30天试用版本的。
目前CodeSourcery已经由明导国际(Mentor Graphics)收购，所以原本的网站风格已经全部变为 Mentor 样式，但是
Sourcery G++ Lite Edition 同样可以注册后免费下载。
Codesourcery一直是在做ARM目标 GCC 的开发和优化，它的ARM GCC在目前在市场上非常优秀，很多 patch 可能还没被gcc接受，所以还是应该直
接用它的（而且他提供Windows下[mingw交叉编译的]和Linux下的二进制版本，比较方便；如果不是很有时间和兴趣，不建议下载 src 源码包自己编
译，很麻烦，Codesourcery给的shell脚本很多时候根本没办法直接用，得自行提取关键的部分手工执行，又费精力又费时间，如果想知道细节，其
实不用自己编译一遍，看看他是用什么步骤构建的即可，如果你对交叉编译器感兴趣的话。

ABI 和 EABI:
ABI：二进制应用程序接口(Application Binary Interface (ABI) for the ARM Architecture)。在计算机中，应用二进制接口描述了应用程序（或者其他类
型）和操作系统之间或其他应用程序的低级接口。
EABI：嵌入式ABI。嵌入式应用二进制接口指定了文件格式、数据类型、寄存器使用、堆积组织优化和在一个嵌入式软件中的参数的标准约定。开发
者使用自己的汇编语言也可以使用 EABI 作为与兼容的编译器生成的汇编语言的接口。
两者主要区别是，ABI是计算机上的，EABI是嵌入式平台上（如ARM，MIPS等）。

arm-linux-gnueabi-gcc 和 arm-linux-gnueabihf-gcc:
两个交叉编译器分别适用于 armel 和 armhf 两个不同的架构，armel 和 armhf 这两种架构在对待浮点运算采取了不同的策略
（有 fpu 的 arm 才能支持这两种浮点运算策略）。
其实这两个交叉编译器只不过是 gcc 的选项 -mfloat-abi 的默认值不同。gcc 的选项 -mfloat-abi 有三种值 soft、softfp、hard（其中后两者都要求
arm 里有 fpu 浮点运算单元，soft 与后两者是兼容的，但 softfp 和 hard 两种模式互不兼容）：
soft： 不用fpu进行浮点计算，即使有fpu浮点运算单元也不用，而是使用软件模式。
softfp： armel架构（对应的编译器为 arm-linux-gnueabi-gcc ）采用的默认值，用fpu计算，但是传参数用普通寄存器传，这样中断的时候，只需要
保存普通寄存器，中断负荷小，但是参数需要转换成浮点的再计算。
hard： armhf架构（对应的编译器 arm-linux-gnueabihf-gcc ）采用的默认值，用fpu计算，传参数也用fpu中的浮点寄存器传，省去了转换，性能最
好，但是中断负荷高。

***/
	
我们需要编译出运行在ARM平台上的代码，所使用的交叉编译器为 arm-linux-gcc。
下面将arm-linux-gcc编译工具的一些常用命令参数介绍给大家。
在此之前首先介绍下编译器的工作过程，在使用GCC编译程序时，编译过程分为四个阶段：
1. 预处理（Pre-Processing）
2. 编译（Compiling）
3. 汇编（Assembling）
4. 链接（Linking）

Linux程序员可以根据自己的需要让 GCC在编译的任何阶段结束，以便检查或使用编译器在该阶段的输出信息，或者对最后生成的二进制文件进行控制，以便通过加入不同数量和种类的调试代码来为 今后的调试做好准备。和其它常用的编译器一样，GCC也提供了灵活而强大的代码优化功能，利用它可以生成执行效率更高的代码。
以文件example.c为例说明它的用法

//arm-none-eabi- tab tab
//arm-none-eabi-gcc --help
/*** command list:
$ arm-none-eabi-
/arm-none-eabi-addr2line.exe  arm-none-eabi-g++.exe         /arm-none-eabi-gdb.exe        /arm-none-eabi-objdump.exe
arm-none-eabi-ar.exe          arm-none-eabi-gcc.exe         arm-none-eabi-gdb-py.exe      arm-none-eabi-ranlib.exe
/arm-none-eabi-as.exe         arm-none-eabi-gcc-4.9.3.exe   arm-none-eabi-gprof.exe       arm-none-eabi-readelf.exe
arm-none-eabi-c++.exe         arm-none-eabi-gcc-ar.exe      arm-none-eabi-ld.bfd.exe      arm-none-eabi-size.exe
arm-none-eabi-c++filt.exe     arm-none-eabi-gcc-nm.exe      /arm-none-eabi-ld.exe         arm-none-eabi-strings.exe
arm-none-eabi-cpp.exe         arm-none-eabi-gcc-ranlib.exe  /arm-none-eabi-nm.exe         arm-none-eabi-strip.exe
arm-none-eabi-elfedit.exe     arm-none-eabi-gcov.exe        /arm-none-eabi-objcopy.exe

***/

01. arm-none-eabi-gcc 
编译程序。
/*** gcc example:
0. arm-linux-gcc -o example example.c
   不加-c、-S、-E参数，编译器将执行预处理、编译、汇编、连接操作直接生成可执行代码。
    -o参数用于指定输出的文件，输出文件名为example,如果不指定输出文件，则默认输出a.out
1. arm-linux-gcc -c -o example.o example.c
   -c参数将对源程序example.c进行预处理、编译、汇编操作，生成example.o文件 //compile.
   去掉指定输出选项"-o example.o"自动输出为example.o,所以说在这里-o加不加都可以
2. arm-linux-gcc -S -o example.s example.c
   -S参数将对源程序example.c进行预处理、编译，生成example.s文件           //asm.
   -o选项同上
3. arm-linux-gcc -E -o example.i example.c
   -E参数将对源程序example.c进行预处理，生成example.i文件（不同版本不一样，有的将预处理后的内容打印到屏幕上）
   就是将#include，#define等进行文件插入及宏扩展等操作。                  //pre-process.
4. arm-linux-gcc -v -o example example.c
加上-v参数，显示编译时的详细信息，编译器的版本，编译过程等。              //version.
5. arm-linux-gcc -g -o example example.c
-g选项，加入GDB能够使用的调试信息,使用GDB调试时比较方便。                 //gdb.
6. arm-linux-gcc -Wall -o example example.c                                //warning.
-Wall选项打开了所有需要注意的警告信息，像在声明之前就使用的函数，声明后却没有使用的变量等。
7. arm-linux-gcc -Ox -o example example.c
-Ox使用优化选项，X的值为空、0、1、2、3                                    //optimize
0为不优化，优化的目的是减少代码空间和提高执行效率等，但相应的编译过程时间将较长并占用较大的内存空间。
8. arm-linux-gcc   -I /home/include -o example example.c                   //include.
-Idirname: 将dirname所指出的目录加入到程序头文件目录列表中。如果在预设系统及当前目录中没有找到需要的文件，就到指定的dirname目录中去寻找。
9. arm-linux-gcc   -L /home/lib -o example example.c                       //link.
-Ldirname：将dirname所指出的目录加入到库文件的目录列表中。在默认状态下，连接程序ld在系统的预设路径中(如/usr/lib)寻找所需要的库文件，这个选项告诉连接程序，首先到-L指定的目录中去寻找，然后再到系统预设路径中寻找。
10. arm-linux-gcc –static -o libexample.a example.c                        //static.
静态链接库文件
***/

/*** gcc option:
	gcc在命令行上经常使用的几个选项是：
	-c   只预处理、编译和汇编源程序，不进行连接。编译器对每一个源程序产生一个目标文件。

	-o file  确定输出文件为file。如果没有用-o选项，缺省的可执行文件的输出是a.out，目标文件和汇编文件的输出对source.suffix分别是source.o和source.s，预处理的C源程序的输出是标准输出stdout。

	-Dmacro 或-Dmacro=defn   其作用类似于源程序里的#define。例如：% gcc -c -DHAVE_GDBM -DHELP_FILE=\"help\" cdict.c其中第一个- D选项定义宏HAVE_GDBM，在程序里可以用#ifdef去检查它是否被设置。第二个-D选项将宏HELP_FILE定义为字符串“help”（由于 反斜线的作用，引号实际上已成为该宏定义的一部分），这对于控制程序打开哪个文件是很有用的。

	-Umacro   某些宏是被编译程序自动定义的。这些宏通常可以指定在其中进行编译的计算机系统类型的符号，用户可以在编译某程序时加上 -v选项以查看gcc缺省定义了哪些宏。如果用户想取消其中某个宏定义，用-Umacro选项，这相当于把#undef macro放在要编译的源文件的开头。

	-Idir   将dir目录加到搜寻头文件的目录列表中去，并优先于在gcc缺省的搜索目录。在有多个-I选项的情况下，按命令行上-I选项的前后顺序搜索。dir可使用相对路径，如-I../inc等。

	-O   对程序编译进行优化，编译程序试图减少被编译程序的长度和执行时间，但其编译速度比不做优化慢，而且要求较多的内存。

	-O2   允许比-O更好的优化，编译速度较慢，但结果程序的执行速度较快。

	-g   产生一张用于调试和排错的扩展符号表。-g选项使程序可以用GNU的调试程序GDB进行调试。优化和调试通常不兼容，同时使用-g和-O（-O2）选项经常会使程序产生奇怪的运行结果。所以不要同时使用-g和-O（-O2）选项。

	-fpic或-fPIC   产生位置无关的目标代码，可用于构造共享函数库。

	以 上是gcc的编译选项。gcc的命令行上还可以使用连接选项。事实上，gcc将所有不能识别的选项传递给连接程序ld。连接程序ld将几个目标文件和库程 序组合成一个可执行文件，它要解决对外部变量、外部过程、库程序等的引用。但我们永远不必要显式地调用ld。利用gcc命令去连接各个文件是很简单的，即 使在命令行里没有列出库程序，gcc也能保证某些库程序以正确的次序出现。

	gcc的常用连接选项有下列几个：
	-Ldir   将dir目录加到搜寻-l选项指定的函数库文件的目录列表中去，并优先于gcc缺省的搜索目录。在有多个-L选项的情况下，按命令行上-L选项的前后顺序搜索。dir可使用相对路径。如-L../lib等。

	-lname   在连接时使用函数库libname.a，连接程序在-Ldir选项指定的目录下和/lib，/usr/lib目录下寻找该库文件。在没有使用-static选项时，如果发现共享函数库libname.so，则使用libname.so进行动态连接。

	-static   禁止与共享函数库连接。

	-shared   尽量与共享函数库连接
**********************************************************/

/*** gcc --help:
$ arm-none-eabi-gcc --help
Usage: arm-none-eabi-gcc.exe [options] file...
Options:
  -pass-exit-codes         Exit with highest error code from a phase
  --help                   Display this information
  --target-help            Display target specific command line options
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...]
                           Display specific types of command line options
  (Use '-v --help' to display command line options of sub-processes)
  --version                Display compiler version information
  -dumpspecs               Display all of the built in spec strings
  -dumpversion             Display the version of the compiler
  -dumpmachine             Display the compiler's target processor
  -print-search-dirs       Display the directories in the compiler's search path
  -print-libgcc-file-name  Display the name of the compiler's companion library
  -print-file-name=<lib>   Display the full path to library <lib>
  -print-prog-name=<prog>  Display the full path to compiler component <prog>
  -print-multiarch         Display the target's normalized GNU triplet, used as
                           a component in the library path
  -print-multi-directory   Display the root directory for versions of libgcc
  -print-multi-lib         Display the mapping between command line options and
                           multiple library search directories
  -print-multi-os-directory Display the relative path to OS libraries
  -print-sysroot           Display the target libraries directory
  -print-sysroot-headers-suffix Display the sysroot suffix used to find headers
  -Wa,<options>            Pass comma-separated <options> on to the assembler
  -Wp,<options>            Pass comma-separated <options> on to the preprocessor
  -Wl,<options>            Pass comma-separated <options> on to the linker
  -Xassembler <arg>        Pass <arg> on to the assembler
  -Xpreprocessor <arg>     Pass <arg> on to the preprocessor
  -Xlinker <arg>           Pass <arg> on to the linker
  -save-temps              Do not delete intermediate files
  -save-temps=<arg>        Do not delete intermediate files
  -no-canonical-prefixes   Do not canonicalize paths when building relative
                           prefixes to other gcc components
  -pipe                    Use pipes rather than intermediate files
  -time                    Time the execution of each subprocess
  -specs=<file>            Override built-in specs with the contents of <file>
  -std=<standard>          Assume that the input sources are for <standard>
  --sysroot=<directory>    Use <directory> as the root directory for headers
                           and libraries
  -B <directory>           Add <directory> to the compiler's search paths
  -v                       Display the programs invoked by the compiler
  -###                     Like -v but options quoted and commands not executed
  -E                       Preprocess only; do not compile, assemble or link
  -S                       Compile only; do not assemble or link
  -c                       Compile and assemble, but do not link
  -o <file>                Place the output into <file>
  -pie                     Create a position independent executable
  -shared                  Create a shared library
  -x <language>            Specify the language of the following input files
                           Permissible languages include: c c++ assembler none
                           'none' means revert to the default behavior of
                           guessing the language based on the file's extension

Options starting with -g, -f, -m, -O, -W, or --param are automatically
 passed on to the various sub-processes invoked by arm-none-eabi-gcc.exe.  In order to pass
 other options on to these processes the -W<letter> options must be used.

For bug reporting instructions, please see:
<http://gcc.gnu.org/bugs.html>.

***/

02. arm-none-eabi-gdb 
/*** gdb process:
使用流程：
查看文件-》设置断点-》查看断点情况-》运行代码-》查看变量值-》单步运行-》恢复程序运行

一：GDB中源代码查看命令
list  /l  行号或函数名            //查看指定位置代码
list <linenum>   //显示程序第linenum行的周围的源程序
list <function>  //显示函数名为function的函数的源程序
list    //  显示当前行后面的源程序
list <filename:funtion>   //显示哪个文件中的哪个函数的源程序
    eg: list  src/fun1.c:fun1
list <filename:linenum>   //哪个文件的哪一行周围的源程序
    eg：list  src/fun1.c:1  

二：运行代码
gdb -help
gdb program
help
info
set
show
run  /r
start 
restart

kill
delete

cd
pwd
tty

ctrl+d //quit./q

三：设置断点与恢复命令
info b 
break  /b    行号或函数名<条件表达式>
delete  断点号
disable  断点号
enable  断点号
step  /s  单步调试(进入子函数)
next  /n  单步调试（不进入子函数）
continue  /c  继续执行函数，知道函数结束或遇到新的断点

四：查看运行数据命令
print  /p  表达式或变量      //查看程序运行时对应表达式或变量的值

五：修改运行参数命令
set  variable  变量名=设定值

--------------------- 
作者：GiveUping 
来源：CSDN 
原文：https://blog.csdn.net/Ammon_Zhang/article/details/52294803 
版权声明：本文为博主原创文章，转载请附上博文链接！

start //开始调试 
n //一条一条执行 
step/s //执行下一条，如果函数进入函数 
backtrace/bt //查看函数调用栈帧 
info/i locals //查看当前栈帧局部变量 
frame/f //选择栈帧，再查看局部变量 
print/p //打印变量的值 
finish //运行到当前函数返回 
set var sum=0 //修改变量值 
list/l 行号或函数名 //列出源码 
display/undisplay sum //每次停下显示变量的值/取消跟踪 
break/b 行号或函数名 //设置断点 
continue/c //连续运行 
info/i breakpoints //查看已经设置的断点 
delete breakpoints 2 //删除某个断点 
disable/enable breakpoints 3 //禁用/启用某个断点 
break 9 if sum != 0 //满足条件才激活断点 
run/r //重新从程序开头连续执行 
watch input[4] //设置观察点 
info/i watchpoints //查看设置的观察点 
x/7b input //打印存储器内容，
b--每个字节一组，7--7组 
disassemble //反汇编当前函数或指定函数 
si // 一条指令一条指令调试 而 s 是一行一行代码 
info registers // 显示所有寄存器的当前值 
x/20 $esp //查看内存中开始的20个数
--------------------- 
作者：一名路过的小码农 
来源：CSDN 
原文：https://blog.csdn.net/liangguangchuan/article/details/79398604 
版权声明：本文为博主原创文章，转载请附上博文链接！

(gdb) help
List of classes of commands: //命令分类: '尚不是命令'

aliases -- Aliases of other commands
breakpoints -- Making program stop at certain points
data -- Examining data
files -- Specifying and examining files
internals -- Maintenance commands
obscure -- Obscure features
running -- Running the program
stack -- Examining the stack
status -- Status inquiries
support -- Support facilities
tracepoints -- Tracing of program execution without stopping the program
user-defined -- User-defined commands

Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Command name abbreviations are allowed if unambiguous.

***/

/*** gdb --help:
$ arm-none-eabi-gdb --help
This is the GNU debugger.  Usage:

    gdb [options] [executable-file [core-file or process-id]]
    gdb [options] --args executable-file [inferior-arguments ...]

Selection of debuggee and its files:

  --args             Arguments after executable-file are passed to inferior
  --core=COREFILE    Analyze the core dump COREFILE.
  --exec=EXECFILE    Use EXECFILE as the executable.
  --pid=PID          Attach to running process PID.
  --directory=DIR    Search for source files in DIR.
  --se=FILE          Use FILE as symbol file and executable file.
  --symbols=SYMFILE  Read symbols from SYMFILE.
  --readnow          Fully read symbol files on first access.
  --write            Set writing into executable and core files.

Initial commands and command files:

  --command=FILE, -x Execute GDB commands from FILE.
  --init-command=FILE, -ix
                     Like -x but execute commands before loading inferior.
  --eval-command=COMMAND, -ex
                     Execute a single GDB command.
                     May be used multiple times and in conjunction
                     with --command.
  --init-eval-command=COMMAND, -iex
                     Like -ex but before loading inferior.
  --nh               Do not read ~/.gdbinit.
  --nx               Do not read any .gdbinit files in any directory.

Output and user interface control:

  --fullname         Output information used by emacs-GDB interface.
  --interpreter=INTERP
                     Select a specific interpreter / user interface
  --tty=TTY          Use TTY for input/output by the program being debugged.
  -w                 Use the GUI interface.
  --nw               Do not use the GUI interface.
  --dbx              DBX compatibility mode.
  --xdb              XDB compatibility mode.
  -q, --quiet, --silent
                     Do not print version number on startup.

Operating modes:

  --batch            Exit after processing options.
  --batch-silent     Like --batch, but suppress all gdb stdout output.
  --return-child-result
                     GDB exit code will be the child's exit code.
  --configuration    Print details about GDB configuration and then exit.
  --help             Print this message and then exit.
  --version          Print version information and then exit.

Remote debugging options:

  -b BAUDRATE        Set serial port baud rate used for remote debugging.
  -l TIMEOUT         Set timeout in seconds for remote debugging.

Other options:

  --cd=DIR           Change current directory to DIR.
  --data-directory=DIR, -D
                     Set GDB's data-directory to DIR.

***/

11. arm-none-eabi-ld 
直接指定代码段，数据段，BSS段的起始地址
-Ttext startAddr
-Tdata startAddr
-Tbss startAddr

arm-none-eabi-ld -Ttext 0x00000000 -g led.o -o led_elf

arm-none-eabi-ld -Ttimer.lds -o timer.elf $^  //timer.lds is link script.

/*** ld --help:
$ arm-none-eabi-ld --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-ld.exe [options] file...
Options:
  -a KEYWORD                  Shared library control for HP/UX compatibility
  -A ARCH, --architecture ARCH
                              Set architecture
  -b TARGET, --format TARGET  Specify target for following input files
  -c FILE, --mri-script FILE  Read MRI format linker script
  -d, -dc, -dp                Force common symbols to be defined
  -e ADDRESS, --entry ADDRESS Set start address
  -E, --export-dynamic        Export all dynamic symbols
  --no-export-dynamic         Undo the effect of --export-dynamic
  -EB                         Link big-endian objects
  -EL                         Link little-endian objects
  -f SHLIB, --auxiliary SHLIB Auxiliary filter for shared object symbol table
  -F SHLIB, --filter SHLIB    Filter for shared object symbol table
  -g                          Ignored
  -G SIZE, --gpsize SIZE      Small data size (if no size, same as --shared)
  -h FILENAME, -soname FILENAME
                              Set internal name of shared library
  -I PROGRAM, --dynamic-linker PROGRAM
                              Set PROGRAM as the dynamic linker to use
  -l LIBNAME, --library LIBNAME
                              Search for library LIBNAME
  -L DIRECTORY, --library-path DIRECTORY
                              Add DIRECTORY to library search path
  --sysroot=<DIRECTORY>       Override the default sysroot location
  -m EMULATION                Set emulation
  -M, --print-map             Print map file on standard output
  -n, --nmagic                Do not page align data
  -N, --omagic                Do not page align data, do not make text readonly
  --no-omagic                 Page align data, make text readonly
  -o FILE, --output FILE      Set output file name
  -O                          Optimize output file
  -plugin PLUGIN              Load named plugin
  -plugin-opt ARG             Send arg to last-loaded plugin
  -flto                       Ignored for GCC LTO option compatibility
  -flto-partition=            Ignored for GCC LTO option compatibility
  -fuse-ld=                   Ignored for GCC linker option compatibility
  -Qy                         Ignored for SVR4 compatibility
  -q, --emit-relocs           Generate relocations in final output
  -r, -i, --relocatable       Generate relocatable output
  -R FILE, --just-symbols FILE
                              Just link symbols (if directory, same as --rpath)
  -s, --strip-all             Strip all symbols
  -S, --strip-debug           Strip debugging symbols
  --strip-discarded           Strip symbols in discarded sections
  --no-strip-discarded        Do not strip symbols in discarded sections
  -t, --trace                 Trace file opens
  -T FILE, --script FILE      Read linker script
  --default-script FILE, -dT  Read default linker script
  -u SYMBOL, --undefined SYMBOL
                              Start with undefined reference to SYMBOL
  --unique [=SECTION]         Don't merge input [SECTION | orphan] sections
  -Ur                         Build global constructor/destructor tables
  -v, --version               Print version information
  -V                          Print version and emulation information
  -x, --discard-all           Discard all local symbols
  -X, --discard-locals        Discard temporary local symbols (default)
  --discard-none              Don't discard any local symbols
  -y SYMBOL, --trace-symbol SYMBOL
                              Trace mentions of SYMBOL
  -Y PATH                     Default search path for Solaris compatibility
  -(, --start-group           Start a group
  -), --end-group             End a group
  --accept-unknown-input-arch Accept input files whose architecture cannot be determined
  --no-accept-unknown-input-arch
                              Reject input files whose architecture is unknown
  --as-needed                 Only set DT_NEEDED for following dynamic libs if used
  --no-as-needed              Always set DT_NEEDED for dynamic libraries mentioned on
                                the command line
  -assert KEYWORD             Ignored for SunOS compatibility
  -Bdynamic, -dy, -call_shared
                              Link against shared libraries
  -Bstatic, -dn, -non_shared, -static
                              Do not link against shared libraries
  -Bsymbolic                  Bind global references locally
  -Bsymbolic-functions        Bind global function references locally
  --check-sections            Check section addresses for overlaps (default)
  --no-check-sections         Do not check section addresses for overlaps
  --copy-dt-needed-entries    Copy DT_NEEDED links mentioned inside DSOs that follow
  --no-copy-dt-needed-entries Do not copy DT_NEEDED links mentioned inside DSOs that follow
  --cref                      Output cross reference table
  --defsym SYMBOL=EXPRESSION  Define a symbol
  --demangle [=STYLE]         Demangle symbol names [using STYLE]
  --embedded-relocs           Generate embedded relocs
  --fatal-warnings            Treat warnings as errors
  --no-fatal-warnings         Do not treat warnings as errors (default)
  -fini SYMBOL                Call SYMBOL at unload-time
  --force-exe-suffix          Force generation of file with .exe suffix
  --gc-sections               Remove unused sections (on some targets)
  --no-gc-sections            Don't remove unused sections (default)
  --print-gc-sections         List removed unused sections on stderr
  --no-print-gc-sections      Do not list removed unused sections
  --hash-size=<NUMBER>        Set default hash table size close to <NUMBER>
  --help                      Print option help
  -init SYMBOL                Call SYMBOL at load-time
  -Map FILE                   Write a map file
  --no-define-common          Do not define Common storage
  --no-demangle               Do not demangle symbol names
  --no-keep-memory            Use less memory and more disk I/O
  --no-undefined              Do not allow unresolved references in object files
  --allow-shlib-undefined     Allow unresolved references in shared libraries
  --no-allow-shlib-undefined  Do not allow unresolved references in shared libs
  --allow-multiple-definition Allow multiple definitions
  --no-undefined-version      Disallow undefined version
  --default-symver            Create default symbol version
  --default-imported-symver   Create default symbol version for imported symbols
  --no-warn-mismatch          Don't warn about mismatched input files
  --no-warn-search-mismatch   Don't warn on finding an incompatible library
  --no-whole-archive          Turn off --whole-archive
  --noinhibit-exec            Create an output file even if errors occur
  -nostdlib                   Only use library directories specified on
                                the command line
  --oformat TARGET            Specify target of output file
  --print-output-format       Print default output format
  -qmagic                     Ignored for Linux compatibility
  --reduce-memory-overheads   Reduce memory overheads, possibly taking much longer
  --relax                     Reduce code size by using target specific optimizations
  --no-relax                  Do not use relaxation techniques to reduce code size
  --retain-symbols-file FILE  Keep only symbols listed in FILE
  -rpath PATH                 Set runtime shared library search path
  -rpath-link PATH            Set link time shared library search path
  -shared, -Bshareable        Create a shared library
  -pie, --pic-executable      Create a position independent executable
  --sort-common [=ascending|descending]
                              Sort common symbols by alignment [in specified order]
  --sort-section name|alignment
                              Sort sections by name or maximum alignment
  --spare-dynamic-tags COUNT  How many tags to reserve in .dynamic section
  --split-by-file [=SIZE]     Split output sections every SIZE octets
  --split-by-reloc [=COUNT]   Split output sections every COUNT relocs
  --stats                     Print memory usage statistics
  --target-help               Display target specific options
  --task-link SYMBOL          Do task level linking
  --traditional-format        Use same format as native linker
  --section-start SECTION=ADDRESS
                              Set address of named section
  -Tbss ADDRESS               Set address of .bss section
  -Tdata ADDRESS              Set address of .data section
  -Ttext ADDRESS              Set address of .text section
  -Ttext-segment ADDRESS      Set address of text segment
  -Trodata-segment ADDRESS    Set address of rodata segment
  -Tldata-segment ADDRESS     Set address of ldata segment
  --unresolved-symbols=<method>
                              How to handle unresolved symbols.  <method> is:
                                ignore-all, report-all, ignore-in-object-files,
                                ignore-in-shared-libs
  --verbose [=NUMBER]         Output lots of information during link
  --version-script FILE       Read version information script
  --version-exports-section SYMBOL
                              Take export symbols list from .exports, using
                                SYMBOL as the version.
  --dynamic-list-data         Add data symbols to dynamic list
  --dynamic-list-cpp-new      Use C++ operator new/delete dynamic list
  --dynamic-list-cpp-typeinfo Use C++ typeinfo dynamic list
  --dynamic-list FILE         Read dynamic list
  --warn-common               Warn about duplicate common symbols
  --warn-constructors         Warn if global constructors/destructors are seen
  --warn-multiple-gp          Warn if the multiple GP values are used
  --warn-once                 Warn only once per undefined symbol
  --warn-section-align        Warn if start of section changes due to alignment
  --warn-shared-textrel       Warn if shared object has DT_TEXTREL
  --warn-alternate-em         Warn if an object has alternate ELF machine code
  --warn-unresolved-symbols   Report unresolved symbols as warnings
  --error-unresolved-symbols  Report unresolved symbols as errors
  --whole-archive             Include all objects from following archives
  --wrap SYMBOL               Use wrapper functions for SYMBOL
  --ignore-unresolved-symbol SYMBOL
                              Unresolved SYMBOL will not cause an error or warning
  @FILE                       Read options from FILE
C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-ld.exe: supported targets: elf32-littlearm elf32-bigarm elf32-littl              e elf32-big plugin srec symbolsrec verilog tekhex binary ihex
C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-ld.exe: supported emulations: armelf
C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-ld.exe: emulation specific options:
armelf:
  --audit=AUDITLIB            Specify a library to use for auditing
  -Bgroup                     Selects group name lookup rules for DSO
  --build-id[=STYLE]          Generate build ID note
  -P AUDITLIB, --depaudit=AUDITLIB
                              Specify a library to use for auditing dependencies
  --disable-new-dtags         Disable new dynamic tags
  --enable-new-dtags          Enable new dynamic tags
  --eh-frame-hdr              Create .eh_frame_hdr section
  --exclude-libs=LIBS         Make all symbols in LIBS hidden
  --hash-style=STYLE          Set hash style to sysv, gnu or both
  -z combreloc                Merge dynamic relocs into one section and sort
  -z common-page-size=SIZE    Set common page size to SIZE
  -z defs                     Report unresolved symbols in object files.
  -z execstack                Mark executable as requiring executable stack
  -z global                   Make symbols in DSO available for subsequently
                               loaded objects
  -z initfirst                Mark DSO to be initialized first at runtime
  -z interpose                Mark object to interpose all DSOs but executable
  -z lazy                     Mark object lazy runtime binding (default)
  -z loadfltr                 Mark object requiring immediate process
  -z max-page-size=SIZE       Set maximum page size to SIZE
  -z muldefs                  Allow multiple definitions
  -z nocombreloc              Don't merge dynamic relocs into one section
  -z nocopyreloc              Don't create copy relocs
  -z nodefaultlib             Mark object not to use default search paths
  -z nodelete                 Mark DSO non-deletable at runtime
  -z nodlopen                 Mark DSO not available to dlopen
  -z nodump                   Mark DSO not available to dldump
  -z noexecstack              Mark executable as not requiring executable stack
  -z norelro                  Don't create RELRO program header
  -z now                      Mark object non-lazy runtime binding
  -z origin                   Mark object requiring immediate $ORIGIN
                                processing at runtime
  -z relro                    Create RELRO program header
  -z stacksize=SIZE           Set size of stack segment
  --thumb-entry=<sym>         Set the entry point to be Thumb symbol <sym>
  --be8                       Output BE8 format image
  --target1-rel               Interpret R_ARM_TARGET1 as R_ARM_REL32
  --target1-abs               Interpret R_ARM_TARGET1 as R_ARM_ABS32
  --target2=<type>            Specify definition of R_ARM_TARGET2
  --fix-v4bx                  Rewrite BX rn as MOV pc, rn for ARMv4
  --fix-v4bx-interworking     Rewrite BX rn branch to ARMv4 interworking veneer
  --use-blx                   Enable use of BLX instructions
  --vfp11-denorm-fix          Specify how to fix VFP11 denorm erratum
  --no-enum-size-warning      Don't warn about objects with incompatible
                                enum sizes
  --no-wchar-size-warning     Don't warn about objects with incompatible
                                wchar_t sizes
  --pic-veneer                Always generate PIC interworking veneers
  --stub-group-size=N         Maximum size of a group of input sections that
                               can be handled by one stub section.  A negative
                               value locates all stubs after their branches
                               (with a group size of -N), while a positive
                               value allows two groups of input sections, one
                               before, and one after each stub section.
                               Values of +/-1 indicate the linker should
                               choose suitable defaults.
  --[no-]fix-cortex-a8        Disable/enable Cortex-A8 Thumb-2 branch erratum fix
  --no-merge-exidx-entries    Disable merging exidx entries
  --[no-]fix-arm1176          Disable/enable ARM1176 BLX immediate erratum fix

***/

12 arm-linux-objcopy 
复制一个目标文件的内容，到另一个目标文件中。
可用于不同目标文件之间的格式转换。
arm-linux-objcopy -O binary -S elf_file bin_file
/*** objcopy option:
    option:
       1. input-file, out-file.
	   2. -I bfdname, --input-target=bfdname.
	   3. -O bfdname, --output-target-bfdname.
	   4. -F bfdname 将源文件和输出文件的格式设置为bfdname. //format.
	   5. -R sectionname 将输出文件中所有名为sectionname段  //remove.
	   6. -S 不从源文件中复制‘重定位信息’和‘符号信息’到目标文件中.
	   7. -g 不从源文件中复制‘调试信息’到目标文件中.
***/

/*** objcopy --help:
$ arm-none-eabi-objcopy --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-objcopy.exe [option(s)] in-file [out-file]
 Copies a binary file, possibly transforming it in the process
 The options are:
  -I --input-target <bfdname>      Assume input file is in format <bfdname>
  -O --output-target <bfdname>     Create an output file in format <bfdname>
  -B --binary-architecture <arch>  Set output arch, when input is arch-less
  -F --target <bfdname>            Set both input and output format to <bfdname>
     --debugging                   Convert debugging information, if possible
  -p --preserve-dates              Copy modified/access timestamps to the output
  -D --enable-deterministic-archives
                                   Produce deterministic output when stripping archives
  -U --disable-deterministic-archives
                                   Disable -D behavior (default)
  -j --only-section <name>         Only copy section <name> into the output
     --add-gnu-debuglink=<file>    Add section .gnu_debuglink linking to <file>
  -R --remove-section <name>       Remove section <name> from the output
  -S --strip-all                   Remove all symbol and relocation information
  -g --strip-debug                 Remove all debugging symbols & sections
     --strip-dwo                   Remove all DWO sections
     --strip-unneeded              Remove all symbols not needed by relocations
  -N --strip-symbol <name>         Do not copy symbol <name>
     --strip-unneeded-symbol <name>
                                   Do not copy symbol <name> unless needed by
                                     relocations
     --only-keep-debug             Strip everything but the debug information
     --extract-dwo                 Copy only DWO sections
     --extract-symbol              Remove section contents but keep symbols
  -K --keep-symbol <name>          Do not strip symbol <name>
     --keep-file-symbols           Do not strip file symbol(s)
     --localize-hidden             Turn all ELF hidden symbols into locals
  -L --localize-symbol <name>      Force symbol <name> to be marked as a local
     --globalize-symbol <name>     Force symbol <name> to be marked as a global
  -G --keep-global-symbol <name>   Localize all symbols except <name>
  -W --weaken-symbol <name>        Force symbol <name> to be marked as a weak
     --weaken                      Force all global symbols to be marked as weak
  -w --wildcard                    Permit wildcard in symbol comparison
  -x --discard-all                 Remove all non-global symbols
  -X --discard-locals              Remove any compiler-generated symbols
  -i --interleave [<number>]       Only copy N out of every <number> bytes
     --interleave-width <number>   Set N for --interleave
  -b --byte <num>                  Select byte <num> in every interleaved block
     --gap-fill <val>              Fill gaps between sections with <val>
     --pad-to <addr>               Pad the last section up to address <addr>
     --set-start <addr>            Set the start address to <addr>
    {--change-start|--adjust-start} <incr>
                                   Add <incr> to the start address
    {--change-addresses|--adjust-vma} <incr>
                                   Add <incr> to LMA, VMA and start addresses
    {--change-section-address|--adjust-section-vma} <name>{=|+|-}<val>
                                   Change LMA and VMA of section <name> by <val>
     --change-section-lma <name>{=|+|-}<val>
                                   Change the LMA of section <name> by <val>
     --change-section-vma <name>{=|+|-}<val>
                                   Change the VMA of section <name> by <val>
    {--[no-]change-warnings|--[no-]adjust-warnings}
                                   Warn if a named section does not exist
     --set-section-flags <name>=<flags>
                                   Set section <name>'s properties to <flags>
     --add-section <name>=<file>   Add section <name> found in <file> to output
     --rename-section <old>=<new>[,<flags>] Rename section <old> to <new>
     --long-section-names {enable|disable|keep}
                                   Handle long section names in Coff objects.
     --change-leading-char         Force output format's leading character style
     --remove-leading-char         Remove leading character from global symbols
     --reverse-bytes=<num>         Reverse <num> bytes at a time, in output sections with content
     --redefine-sym <old>=<new>    Redefine symbol name <old> to <new>
     --redefine-syms <file>        --redefine-sym for all symbol pairs
                                     listed in <file>
     --srec-len <number>           Restrict the length of generated Srecords
     --srec-forceS3                Restrict the type of generated Srecords to S3
     --strip-symbols <file>        -N for all symbols listed in <file>
     --strip-unneeded-symbols <file>
                                   --strip-unneeded-symbol for all symbols listed
                                     in <file>
     --keep-symbols <file>         -K for all symbols listed in <file>
     --localize-symbols <file>     -L for all symbols listed in <file>
     --globalize-symbols <file>    --globalize-symbol for all in <file>
     --keep-global-symbols <file>  -G for all symbols listed in <file>
     --weaken-symbols <file>       -W for all symbols listed in <file>
     --alt-machine-code <index>    Use the target's <index>'th alternative machine
     --writable-text               Mark the output text as writable
     --readonly-text               Make the output text write protected
     --pure                        Mark the output file as demand paged
     --impure                      Mark the output file as impure
     --prefix-symbols <prefix>     Add <prefix> to start of every symbol name
     --prefix-sections <prefix>    Add <prefix> to start of every section name
     --prefix-alloc-sections <prefix>
                                   Add <prefix> to start of every allocatable
                                     section name
     --file-alignment <num>        Set PE file alignment to <num>
     --heap <reserve>[,<commit>]   Set PE reserve/commit heap to <reserve>/
                                   <commit>
     --image-base <address>        Set PE image base to <address>
     --section-alignment <num>     Set PE section alignment to <num>
     --stack <reserve>[,<commit>]  Set PE reserve/commit stack to <reserve>/
                                   <commit>
     --subsystem <name>[:<version>]
                                   Set PE subsystem to <name> [& <version>]
     --compress-debug-sections     Compress DWARF debug sections using zlib
     --decompress-debug-sections   Decompress DWARF debug sections using zlib
  -v --verbose                     List all object files modified
  @<file>                          Read options from <file>
  -V --version                     Display this program's version number
  -h --help                        Display this output
     --info                        List object formats & architectures supported
C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-objcopy.exe: supported targets: elf32-littlearm elf32-bigarm elf32-little elf32-big plugin srec symbolsrec verilog tekhex binary ihex

***/

13. arm-linux-objdump
查看目标文件(.o)和库文件(.a)信息。
arm-linux-objdump -D -m arm led_elf > led.dis
/*** objdump option:
    option:
       1. -D display all disassemble infomation.
	   2. -m machine.
	   3. -O bfdname, --output-target-bfdname.
	   4. -F bfdname 将源文件和输出文件的格式设置为bfdname. //format.
	   5. -R sectionname 将输出文件中所有名为sectionname段  //remove.
	   6. -S 不从源文件中复制‘重定位信息’和‘符号信息’到目标文件中.
	   7. -g 不从源文件中复制‘调试信息’到目标文件中.
***/

/*** objdump --help:
$ arm-none-eabi-objdump --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-objdump.exe <option(s)> <file(s)>
 Display information from object <file(s)>.
 At least one of the following switches must be given:
  -a, --archive-headers    Display archive header information
  -f, --file-headers       Display the contents of the overall file header
  -p, --private-headers    Display object format specific file header contents
  -P, --private=OPT,OPT... Display object format specific contents
  -h, --[section-]headers  Display the contents of the section headers
  -x, --all-headers        Display the contents of all headers
  -d, --disassemble        Display assembler contents of executable sections
  -D, --disassemble-all    Display assembler contents of all sections
  -S, --source             Intermix source code with disassembly
  -s, --full-contents      Display the full contents of all sections requested
  -g, --debugging          Display debug information in object file
  -e, --debugging-tags     Display debug information using ctags style
  -G, --stabs              Display (in raw form) any STABS info in the file
  -W[lLiaprmfFsoRt] or
  --dwarf[=rawline,=decodedline,=info,=abbrev,=pubnames,=aranges,=macro,=frames,
          =frames-interp,=str,=loc,=Ranges,=pubtypes,
          =gdb_index,=trace_info,=trace_abbrev,=trace_aranges,
          =addr,=cu_index]
                           Display DWARF info in the file
  -t, --syms               Display the contents of the symbol table(s)
  -T, --dynamic-syms       Display the contents of the dynamic symbol table
  -r, --reloc              Display the relocation entries in the file
  -R, --dynamic-reloc      Display the dynamic relocation entries in the file
  @<file>                  Read options from <file>
  -v, --version            Display this program's version number
  -i, --info               List object formats and architectures supported
  -H, --help               Display this information

 The following switches are optional:
  -b, --target=BFDNAME           Specify the target object format as BFDNAME
  -m, --architecture=MACHINE     Specify the target architecture as MACHINE
  -j, --section=NAME             Only display information for section NAME
  -M, --disassembler-options=OPT Pass text OPT on to the disassembler
  -EB --endian=big               Assume big endian format when disassembling
  -EL --endian=little            Assume little endian format when disassembling
      --file-start-context       Include context from start of file (with -S)
  -I, --include=DIR              Add DIR to search list for source files
  -l, --line-numbers             Include line numbers and filenames in output
  -F, --file-offsets             Include file offsets when displaying information
  -C, --demangle[=STYLE]         Decode mangled/processed symbol names
                                  The STYLE, if specified, can be `auto', `gnu',
                                  `lucid', `arm', `hp', `edg', `gnu-v3', `java'
                                  or `gnat'
  -w, --wide                     Format output for more than 80 columns
  -z, --disassemble-zeroes       Do not skip blocks of zeroes when disassembling
      --start-address=ADDR       Only process data whose address is >= ADDR
      --stop-address=ADDR        Only process data whose address is <= ADDR
      --prefix-addresses         Print complete address alongside disassembly
      --[no-]show-raw-insn       Display hex alongside symbolic disassembly
      --insn-width=WIDTH         Display WIDTH bytes on a single line for -d
      --adjust-vma=OFFSET        Add OFFSET to all displayed section addresses
      --special-syms             Include special symbols in symbol dumps
      --prefix=PREFIX            Add PREFIX to absolute paths for -S
      --prefix-strip=LEVEL       Strip initial directory names for -S
      --dwarf-depth=N        Do not display DIEs at depth N or greater
      --dwarf-start=N        Display DIEs starting with N, at the same depth
                             or deeper
      --dwarf-check          Make additional dwarf internal consistency checks.

C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-objdump.exe: supported targets: elf32-littlearm elf32-bigarm elf32-little elf32-big plugin srec symbolsrec verilog tekhex binary ihex
C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-objdump.exe: supported architectures: arm armv2 armv2a armv3 armv3m armv4 armv4t armv5 armv5t armv5te xscale ep9312 iwmmxt iwmmxt2 plugin

The following ARM specific disassembler options are supported for use with
the -M switch:
  reg-names-special-atpcs  Select special register names used in the ATPCS
  reg-names-atpcs          Select register names used in the ATPCS
  reg-names-apcs           Select register names used in the APCS
  reg-names-std            Select register names used in ARM's ISA documentation
  reg-names-gcc            Select register names used by GCC
  reg-names-raw            Select raw register names
  force-thumb              Assume all insns are Thumb insns
  no-force-thumb           Examine preceding label to determine an insn's type

***/

14. arm-none-eabi-nm.exe 
/***nm --help:
$ arm-none-eabi-nm --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-nm.exe [option(s)] [file(s)]
 List symbols in [file(s)] (a.out by default).
 The options are:
  -a, --debug-syms       Display debugger-only symbols
  -A, --print-file-name  Print name of the input file before every symbol
  -B                     Same as --format=bsd
  -C, --demangle[=STYLE] Decode low-level symbol names into user-level names
                          The STYLE, if specified, can be `auto' (the default),
                          `gnu', `lucid', `arm', `hp', `edg', `gnu-v3', `java'
                          or `gnat'
      --no-demangle      Do not demangle low-level symbol names
  -D, --dynamic          Display dynamic symbols instead of normal symbols
      --defined-only     Display only defined symbols
  -e                     (ignored)
  -f, --format=FORMAT    Use the output format FORMAT.  FORMAT can be `bsd',
                           `sysv' or `posix'.  The default is `bsd'
  -g, --extern-only      Display only external symbols
  -l, --line-numbers     Use debugging information to find a filename and
                           line number for each symbol
  -n, --numeric-sort     Sort symbols numerically by address
  -o                     Same as -A
  -p, --no-sort          Do not sort the symbols
  -P, --portability      Same as --format=posix
  -r, --reverse-sort     Reverse the sense of the sort
      --plugin NAME      Load the specified plugin
  -S, --print-size       Print size of defined symbols
  -s, --print-armap      Include index for symbols from archive members
      --size-sort        Sort symbols by size
      --special-syms     Include special symbols in the output
      --synthetic        Display synthetic symbols as well
  -t, --radix=RADIX      Use RADIX for printing symbol values
      --target=BFDNAME   Specify the target object format as BFDNAME
  -u, --undefined-only   Display only undefined symbols
  -X 32_64               (ignored)
  @FILE                  Read options from FILE
  -h, --help             Display this information
  -V, --version          Display this program's version number

C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-nm.exe: supported targets: elf32-littlearm elf32-bigarm elf32-little elf32-big pl ugin srec symbolsrec verilog tekhex binary ihex
Report bugs to <http://www.sourceware.org/bugzilla/>.

***/

14. arm-none-eabi-gcc-nm.exe 
/***gcc-nm --help:
$ arm-none-eabi-gcc-nm --help
Usage: c:\mbs\mbstoolchains\gcc-arm-none-eabi-4_9-2015q3\bin\../lib/gcc/arm-none-eabi/4.9.3/../../../../arm-none-eabi/bin/nm.exe [option(s)] [file(s)]
 List symbols in [file(s)] (a.out by default).

***/

15. arm-none-eabi-ar.exe //archive.
16. arm-none-eabi-as.exe //assemble.
/***-as --help:
$ arm-none-eabi-as --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-as.exe [option...] [asmfile...]
Options:
  -a[sub-option...]       turn on listings
                          Sub-options [default hls]:
                          c      omit false conditionals
                          d      omit debugging directives
                          g      include general info
                          h      include high-level source
                          l      include assembly
                          m      include macro expansions
                          n      omit forms processing
                          s      include symbols
                          =FILE  list to FILE (must be last sub-option)
  --alternate             initially turn on alternate macro syntax
  --compress-debug-sections
                          compress DWARF debug sections using zlib
  --nocompress-debug-sections
                          don't compress DWARF debug sections
  -D                      produce assembler debugging messages
  --debug-prefix-map OLD=NEW
                          map OLD to NEW in debug information
  --defsym SYM=VAL        define symbol SYM to given value
  --execstack             require executable stack for this object
  --noexecstack           don't require executable stack for this object
  --size-check=[error|warning]
                          ELF .size directive check (default --size-check=error)
  -f                      skip whitespace and comment preprocessing
  -g --gen-debug          generate debugging information
  --gstabs                generate STABS debugging information
  --gstabs+               generate STABS debug info with GNU extensions
  --gdwarf-2              generate DWARF2 debugging information
  --gdwarf-sections       generate per-function section names for DWARF line information
  --hash-size=<value>     set the hash table size close to <value>
  --help                  show this message and exit
  --target-help           show target specific options
  -I DIR                  add DIR to search list for .include directives
  -J                      don't warn about signed overflow
  -K                      warn when differences altered for long displacements
  -L,--keep-locals        keep local symbols (e.g. starting with `L')
  -M,--mri                assemble in MRI compatibility mode
  --MD FILE               write dependency information in FILE (default none)
  -nocpp                  ignored
  -o OBJFILE              name the object-file output OBJFILE (default a.out)
  -R                      fold data section into text section
  --reduce-memory-overheads
                          prefer smaller memory use at the cost of longer
                          assembly times
  --statistics            print various measured statistics from execution
  --strip-local-absolute  strip local absolute symbols
  --traditional-format    Use same format as native assembler when possible
  --version               print assembler version number and exit
  -W  --no-warn           suppress warnings
  --warn                  don't suppress warnings
  --fatal-warnings        treat warnings as errors
  -w                      ignored
  -X                      ignored
  -Z                      generate object file even after errors
  --listing-lhs-width     set the width in words of the output data column of
                          the listing
  --listing-lhs-width2    set the width in words of the continuation lines
                          of the output data column; ignored if smaller than
                          the width of the first line
  --listing-rhs-width     set the max width in characters of the lines from
                          the source file
  --listing-cont-lines    set the maximum number of continuation lines used
                          for the output data column of the listing
  @FILE                   read options from FILE
 ARM-specific assembler options:
  -k                      generate PIC code
  -mthumb                 assemble Thumb code
  -mthumb-interwork       support ARM/Thumb interworking
  -mapcs-32               code uses 32-bit program counter
  -mapcs-26               code uses 26-bit program counter
  -mapcs-float            floating point args are in fp regs
  -mapcs-reentrant        re-entrant code
  -matpcs                 code is ATPCS conformant
  -mbig-endian            assemble for big-endian
  -mlittle-endian         assemble for little-endian
  -mapcs-frame            use frame pointer
  -mapcs-stack-check      use stack size checking
  -mno-warn-deprecated    do not warn on use of deprecated feature
  -mcpu=<cpu name>        assemble for CPU <cpu name>
  -march=<arch name>      assemble for architecture <arch name>
  -mfpu=<fpu name>        assemble for FPU architecture <fpu name>
  -mfloat-abi=<abi>       assemble for floating point ABI <abi>
  -meabi=<ver>            assemble for eabi version <ver>
  -mimplicit-it=<mode>    controls implicit insertion of IT instructions
  -EB                     assemble code for a big-endian cpu
  -EL                     assemble code for a little-endian cpu
  --fix-v4bx              Allow BX in ARMv4 code

Report bugs to <http://www.sourceware.org/bugzilla/>

***/

17. arm-none-eabi-addr2line.exe
$ /c/mbs/programs/bin/addr2line -e products-quasarMotor.elf 0x801d03f
/***addr2line --help:
$ arm-none-eabi-addr2line --help
Usage: C:\mbs\mbsToolchains\gcc-arm-none-eabi-4_9-2015q3\bin\arm-none-eabi-addr2line.exe [option(s)] [addr(s)]
 Convert addresses into line number/file name pairs.
 If no addresses are specified on the command line, they will be read from stdin
 The options are:
  @<file>                Read options from <file>
  -a --addresses         Show addresses
  -b --target=<bfdname>  Set the binary file format
  -e --exe=<executable>  Set the input file name (default is a.out)
  -i --inlines           Unwind inlined functions
  -j --section=<name>    Read section-relative offsets instead of addresses
  -p --pretty-print      Make the output easier to read for humans
  -s --basenames         Strip directory names
  -f --functions         Show function names
  -C --demangle[=style]  Demangle function names
  -h --help              Display this information
  -v --version           Display the program's version

***/

18. readelf -a ***.elf |less  //export /././programs/bin  > .bach_profile.

