(gcc-arm-none-eabi�������еı������Ĺ��ܣ���רҵ�ģ���Ƕ��ʽ����������һ�㽫��������������
����������һ���ɱ����������������������͵�������ɣ�)

������빤��������������Ϊ��arch [-vendor] [-os] [-(gnu)eabi]
    arch - ��ϵ�ܹ�����ARM��MIPS
    verdor - �������ṩ��
    os - Ŀ�����ϵͳ
    eabi - Ƕ��ʽӦ�ö����ƽӿ�

���ݶԲ���ϵͳ��֧�����ARM GCC�ɷ�Ϊ֧�ֺͲ�֧�ֲ���ϵͳ����
    arm-none-eabi�������û�в���ϵͳ�ģ���Ȼ������֧����Щ������ϵͳ��ϵ���еĺ���������fork(2)��
	��ʹ�õ���newlib���ר����Ƕ��ʽϵͳ��C�⡣

    arm-none-linux-eabi������Linux�ģ�ʹ��Glibc
	
/*** compiler tool:
ʵ��:
1��arm-none-eabi-gcc
��ARM architecture��no vendor��not target an operating system��complies with the ARM EABI��
���ڱ��� ARM �ܹ������ϵͳ������ ARM Linux �� boot��kernel�������ñ��� Linux Ӧ�� Application����
һ���ʺ� ARM7��Cortex-M �� Cortex-R �ں˵�оƬʹ�ã����Բ�֧����Щ������ϵͳ��ϵ���еĺ�����
����fork(2)����ʹ�õ��� newlib ���ר����Ƕ��ʽϵͳ��C�⡣

2��arm-none-linux-gnueabi-gcc
(ARM architecture, no vendor, creates binaries that run on the Linux operating system, and uses the GNU EABI)
��Ҫ���ڻ���ARM�ܹ���Linuxϵͳ�������ڱ��� ARM �ܹ��� u-boot��Linux�ںˡ�linuxӦ�õȡ�
arm-none-linux-gnueabi����GCC��ʹ��Glibc�⣬���� Codesourcery ��˾�Ż����Ƴ��ı�������
arm-none-linux-gnueabi-xxx ������빤�ߵĸ�������ǳ����㡣һ��ARM9��ARM11��Cortex-A ��
�ˣ����� Linux ����ϵͳ�Ļ��õ���

3��arm-eabi-gcc
Android ARM ��������

4��armcc
ARM ��˾�Ƴ��ı��빤�ߣ����ܺ� arm-none-eabi ���ƣ����Ա����������u-boot��kernel����
���ǲ��ܱ��� Linux Ӧ�ó���armccһ���ARM��������һ��Keil MDK��ADS��RVDS��DS-5��
�ı���������armcc������ armcc �����������շѵģ���������⣬�Ǻ�~~����

5��arm-none-uclinuxeabi-gcc �� arm-none-symbianelf-gcc
arm-none-uclinuxeabi ����uCLinux��ʹ��Glibc��
arm-none-symbianelf ����symbian��û�ù�����֪��C����ʲô ��

Codesourcery:
Codesourcery�Ƴ��Ĳ�Ʒ��Sourcery G++ Lite Edition�����л���command-line�ı���������ѵģ��ڹ����Ͽ������أ�
�����а�����IDE��debug �������շѵģ���ȻҲ��30�����ð汾�ġ�
ĿǰCodeSourcery�Ѿ�����������(Mentor Graphics)�չ�������ԭ������վ����Ѿ�ȫ����Ϊ Mentor ��ʽ������
Sourcery G++ Lite Edition ͬ������ע���������ء�
Codesourceryһֱ������ARMĿ�� GCC �Ŀ������Ż�������ARM GCC��Ŀǰ���г��Ϸǳ����㣬�ܶ� patch ���ܻ�û��gcc���ܣ����Ի���Ӧ��ֱ
�������ģ��������ṩWindows��[mingw��������]��Linux�µĶ����ư汾���ȽϷ��㣻������Ǻ���ʱ�����Ȥ������������ src Դ����Լ���
�룬���鷳��Codesourcery����shell�ű��ܶ�ʱ�����û�취ֱ���ã���������ȡ�ؼ��Ĳ����ֹ�ִ�У��ַѾ����ַ�ʱ�䣬�����֪��ϸ�ڣ���
ʵ�����Լ�����һ�飬����������ʲô���蹹���ļ��ɣ������Խ������������Ȥ�Ļ���

ABI �� EABI:
ABI��������Ӧ�ó���ӿ�(Application Binary Interface (ABI) for the ARM Architecture)���ڼ�����У�Ӧ�ö����ƽӿ�������Ӧ�ó��򣨻���������
�ͣ��Ͳ���ϵͳ֮�������Ӧ�ó���ĵͼ��ӿڡ�
EABI��Ƕ��ʽABI��Ƕ��ʽӦ�ö����ƽӿ�ָ�����ļ���ʽ���������͡��Ĵ���ʹ�á��ѻ���֯�Ż�����һ��Ƕ��ʽ����еĲ����ı�׼Լ��������
��ʹ���Լ��Ļ������Ҳ����ʹ�� EABI ��Ϊ����ݵı��������ɵĻ�����ԵĽӿڡ�
������Ҫ�����ǣ�ABI�Ǽ�����ϵģ�EABI��Ƕ��ʽƽ̨�ϣ���ARM��MIPS�ȣ���

arm-linux-gnueabi-gcc �� arm-linux-gnueabihf-gcc:
��������������ֱ������� armel �� armhf ������ͬ�ļܹ���armel �� armhf �����ּܹ��ڶԴ����������ȡ�˲�ͬ�Ĳ���
���� fpu �� arm ����֧�������ָ���������ԣ���
��ʵ���������������ֻ������ gcc ��ѡ�� -mfloat-abi ��Ĭ��ֵ��ͬ��gcc ��ѡ�� -mfloat-abi ������ֵ soft��softfp��hard�����к����߶�Ҫ��
arm ���� fpu �������㵥Ԫ��soft ��������Ǽ��ݵģ��� softfp �� hard ����ģʽ�������ݣ���
soft�� ����fpu���и�����㣬��ʹ��fpu�������㵥ԪҲ���ã�����ʹ�����ģʽ��
softfp�� armel�ܹ�����Ӧ�ı�����Ϊ arm-linux-gnueabi-gcc �����õ�Ĭ��ֵ����fpu���㣬���Ǵ���������ͨ�Ĵ������������жϵ�ʱ��ֻ��Ҫ
������ͨ�Ĵ������жϸ���С�����ǲ�����Ҫת���ɸ�����ټ��㡣
hard�� armhf�ܹ�����Ӧ�ı����� arm-linux-gnueabihf-gcc �����õ�Ĭ��ֵ����fpu���㣬������Ҳ��fpu�еĸ���Ĵ�������ʡȥ��ת����������
�ã������жϸ��ɸߡ�

***/
	
������Ҫ�����������ARMƽ̨�ϵĴ��룬��ʹ�õĽ��������Ϊ arm-linux-gcc��
���潫arm-linux-gcc���빤�ߵ�һЩ��������������ܸ���ҡ�
�ڴ�֮ǰ���Ƚ����±������Ĺ������̣���ʹ��GCC�������ʱ��������̷�Ϊ�ĸ��׶Σ�
1. Ԥ����Pre-Processing��
2. ���루Compiling��
3. ��ࣨAssembling��
4. ���ӣ�Linking��

Linux����Ա���Ը����Լ�����Ҫ�� GCC�ڱ�����κν׶ν������Ա����ʹ�ñ������ڸý׶ε������Ϣ�����߶�������ɵĶ������ļ����п��ƣ��Ա�ͨ�����벻ͬ����������ĵ��Դ�����Ϊ ���ĵ�������׼�������������õı�����һ����GCCҲ�ṩ������ǿ��Ĵ����Ż����ܣ���������������ִ��Ч�ʸ��ߵĴ��롣
���ļ�example.cΪ��˵�������÷�

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
�������
/*** gcc example:
0. arm-linux-gcc -o example example.c
   ����-c��-S��-E��������������ִ��Ԥ�������롢��ࡢ���Ӳ���ֱ�����ɿ�ִ�д��롣
    -o��������ָ��������ļ�������ļ���Ϊexample,�����ָ������ļ�����Ĭ�����a.out
1. arm-linux-gcc -c -o example.o example.c
   -c��������Դ����example.c����Ԥ�������롢������������example.o�ļ� //compile.
   ȥ��ָ�����ѡ��"-o example.o"�Զ����Ϊexample.o,����˵������-o�Ӳ��Ӷ�����
2. arm-linux-gcc -S -o example.s example.c
   -S��������Դ����example.c����Ԥ�������룬����example.s�ļ�           //asm.
   -oѡ��ͬ��
3. arm-linux-gcc -E -o example.i example.c
   -E��������Դ����example.c����Ԥ��������example.i�ļ�����ͬ�汾��һ�����еĽ�Ԥ���������ݴ�ӡ����Ļ�ϣ�
   ���ǽ�#include��#define�Ƚ����ļ����뼰����չ�Ȳ�����                  //pre-process.
4. arm-linux-gcc -v -o example example.c
����-v��������ʾ����ʱ����ϸ��Ϣ���������İ汾��������̵ȡ�              //version.
5. arm-linux-gcc -g -o example example.c
-gѡ�����GDB�ܹ�ʹ�õĵ�����Ϣ,ʹ��GDB����ʱ�ȽϷ��㡣                 //gdb.
6. arm-linux-gcc -Wall -o example example.c                                //warning.
-Wallѡ�����������Ҫע��ľ�����Ϣ����������֮ǰ��ʹ�õĺ�����������ȴû��ʹ�õı����ȡ�
7. arm-linux-gcc -Ox -o example example.c
-Oxʹ���Ż�ѡ�X��ֵΪ�ա�0��1��2��3                                    //optimize
0Ϊ���Ż����Ż���Ŀ���Ǽ��ٴ���ռ�����ִ��Ч�ʵȣ�����Ӧ�ı������ʱ�佫�ϳ���ռ�ýϴ���ڴ�ռ䡣
8. arm-linux-gcc   -I /home/include -o example example.c                   //include.
-Idirname: ��dirname��ָ����Ŀ¼���뵽����ͷ�ļ�Ŀ¼�б��С������Ԥ��ϵͳ����ǰĿ¼��û���ҵ���Ҫ���ļ����͵�ָ����dirnameĿ¼��ȥѰ�ҡ�
9. arm-linux-gcc   -L /home/lib -o example example.c                       //link.
-Ldirname����dirname��ָ����Ŀ¼���뵽���ļ���Ŀ¼�б��С���Ĭ��״̬�£����ӳ���ld��ϵͳ��Ԥ��·����(��/usr/lib)Ѱ������Ҫ�Ŀ��ļ������ѡ��������ӳ������ȵ�-Lָ����Ŀ¼��ȥѰ�ң�Ȼ���ٵ�ϵͳԤ��·����Ѱ�ҡ�
10. arm-linux-gcc �Cstatic -o libexample.a example.c                        //static.
��̬���ӿ��ļ�
***/

/*** gcc option:
	gcc���������Ͼ���ʹ�õļ���ѡ���ǣ�
	-c   ֻԤ��������ͻ��Դ���򣬲��������ӡ���������ÿһ��Դ�������һ��Ŀ���ļ���

	-o file  ȷ������ļ�Ϊfile�����û����-oѡ�ȱʡ�Ŀ�ִ���ļ��������a.out��Ŀ���ļ��ͻ���ļ��������source.suffix�ֱ���source.o��source.s��Ԥ�����CԴ���������Ǳ�׼���stdout��

	-Dmacro ��-Dmacro=defn   ������������Դ�������#define�����磺% gcc -c -DHAVE_GDBM -DHELP_FILE=\"help\" cdict.c���е�һ��- Dѡ����HAVE_GDBM���ڳ����������#ifdefȥ������Ƿ����á��ڶ���-Dѡ���HELP_FILE����Ϊ�ַ�����help�������� ��б�ߵ����ã�����ʵ�����ѳ�Ϊ�ú궨���һ���֣�������ڿ��Ƴ�����ĸ��ļ��Ǻ����õġ�

	-Umacro   ĳЩ���Ǳ���������Զ�����ġ���Щ��ͨ������ָ�������н��б���ļ����ϵͳ���͵ķ��ţ��û������ڱ���ĳ����ʱ���� -vѡ���Բ鿴gccȱʡ��������Щ�ꡣ����û���ȡ������ĳ���궨�壬��-Umacroѡ����൱�ڰ�#undef macro����Ҫ�����Դ�ļ��Ŀ�ͷ��

	-Idir   ��dirĿ¼�ӵ���Ѱͷ�ļ���Ŀ¼�б���ȥ������������gccȱʡ������Ŀ¼�����ж��-Iѡ�������£�����������-Iѡ���ǰ��˳��������dir��ʹ�����·������-I../inc�ȡ�

	-O   �Գ����������Ż������������ͼ���ٱ��������ĳ��Ⱥ�ִ��ʱ�䣬��������ٶȱȲ����Ż���������Ҫ��϶���ڴ档

	-O2   �����-O���õ��Ż��������ٶȽ���������������ִ���ٶȽϿ졣

	-g   ����һ�����ڵ��Ժ��Ŵ����չ���ű�-gѡ��ʹ���������GNU�ĵ��Գ���GDB���е��ԡ��Ż��͵���ͨ�������ݣ�ͬʱʹ��-g��-O��-O2��ѡ�����ʹ���������ֵ����н�������Բ�Ҫͬʱʹ��-g��-O��-O2��ѡ�

	-fpic��-fPIC   ����λ���޹ص�Ŀ����룬�����ڹ��칲�����⡣

	�� ����gcc�ı���ѡ�gcc���������ϻ�����ʹ������ѡ���ʵ�ϣ�gcc�����в���ʶ���ѡ��ݸ����ӳ���ld�����ӳ���ld������Ŀ���ļ��Ϳ�� ����ϳ�һ����ִ���ļ�����Ҫ������ⲿ�������ⲿ���̡������ȵ����á���������Զ����Ҫ��ʽ�ص���ld������gcc����ȥ���Ӹ����ļ��Ǻܼ򵥵ģ��� ʹ����������û���г������gccҲ�ܱ�֤ĳЩ���������ȷ�Ĵ�����֡�

	gcc�ĳ�������ѡ�������м�����
	-Ldir   ��dirĿ¼�ӵ���Ѱ-lѡ��ָ���ĺ������ļ���Ŀ¼�б���ȥ����������gccȱʡ������Ŀ¼�����ж��-Lѡ�������£�����������-Lѡ���ǰ��˳��������dir��ʹ�����·������-L../lib�ȡ�

	-lname   ������ʱʹ�ú�����libname.a�����ӳ�����-Ldirѡ��ָ����Ŀ¼�º�/lib��/usr/libĿ¼��Ѱ�Ҹÿ��ļ�����û��ʹ��-staticѡ��ʱ��������ֹ�������libname.so����ʹ��libname.so���ж�̬���ӡ�

	-static   ��ֹ�빲���������ӡ�

	-shared   �����빲����������
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
ʹ�����̣�
�鿴�ļ�-�����öϵ�-���鿴�ϵ����-�����д���-���鿴����ֵ-����������-���ָ���������

һ��GDB��Դ����鿴����
list  /l  �кŻ�����            //�鿴ָ��λ�ô���
list <linenum>   //��ʾ�����linenum�е���Χ��Դ����
list <function>  //��ʾ������Ϊfunction�ĺ�����Դ����
list    //  ��ʾ��ǰ�к����Դ����
list <filename:funtion>   //��ʾ�ĸ��ļ��е��ĸ�������Դ����
    eg: list  src/fun1.c:fun1
list <filename:linenum>   //�ĸ��ļ�����һ����Χ��Դ����
    eg��list  src/fun1.c:1  

�������д���
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

�������öϵ���ָ�����
info b 
break  /b    �кŻ�����<�������ʽ>
delete  �ϵ��
disable  �ϵ��
enable  �ϵ��
step  /s  ��������(�����Ӻ���)
next  /n  �������ԣ��������Ӻ�����
continue  /c  ����ִ�к�����֪�����������������µĶϵ�

�ģ��鿴������������
print  /p  ���ʽ�����      //�鿴��������ʱ��Ӧ���ʽ�������ֵ

�壺�޸����в�������
set  variable  ������=�趨ֵ

--------------------- 
���ߣ�GiveUping 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/Ammon_Zhang/article/details/52294803 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

start //��ʼ���� 
n //һ��һ��ִ�� 
step/s //ִ����һ��������������뺯�� 
backtrace/bt //�鿴��������ջ֡ 
info/i locals //�鿴��ǰջ֡�ֲ����� 
frame/f //ѡ��ջ֡���ٲ鿴�ֲ����� 
print/p //��ӡ������ֵ 
finish //���е���ǰ�������� 
set var sum=0 //�޸ı���ֵ 
list/l �кŻ����� //�г�Դ�� 
display/undisplay sum //ÿ��ͣ����ʾ������ֵ/ȡ������ 
break/b �кŻ����� //���öϵ� 
continue/c //�������� 
info/i breakpoints //�鿴�Ѿ����õĶϵ� 
delete breakpoints 2 //ɾ��ĳ���ϵ� 
disable/enable breakpoints 3 //����/����ĳ���ϵ� 
break 9 if sum != 0 //���������ż���ϵ� 
run/r //���´ӳ���ͷ����ִ�� 
watch input[4] //���ù۲�� 
info/i watchpoints //�鿴���õĹ۲�� 
x/7b input //��ӡ�洢�����ݣ�
b--ÿ���ֽ�һ�飬7--7�� 
disassemble //����൱ǰ������ָ������ 
si // һ��ָ��һ��ָ����� �� s ��һ��һ�д��� 
info registers // ��ʾ���мĴ����ĵ�ǰֵ 
x/20 $esp //�鿴�ڴ��п�ʼ��20����
--------------------- 
���ߣ�һ��·����С��ũ 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/liangguangchuan/article/details/79398604 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

(gdb) help
List of classes of commands: //�������: '�в�������'

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
ֱ��ָ������Σ����ݶΣ�BSS�ε���ʼ��ַ
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
����һ��Ŀ���ļ������ݣ�����һ��Ŀ���ļ��С�
�����ڲ�ͬĿ���ļ�֮��ĸ�ʽת����
arm-linux-objcopy -O binary -S elf_file bin_file
/*** objcopy option:
    option:
       1. input-file, out-file.
	   2. -I bfdname, --input-target=bfdname.
	   3. -O bfdname, --output-target-bfdname.
	   4. -F bfdname ��Դ�ļ�������ļ��ĸ�ʽ����Ϊbfdname. //format.
	   5. -R sectionname ������ļ���������Ϊsectionname��  //remove.
	   6. -S ����Դ�ļ��и��ơ��ض�λ��Ϣ���͡�������Ϣ����Ŀ���ļ���.
	   7. -g ����Դ�ļ��и��ơ�������Ϣ����Ŀ���ļ���.
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
�鿴Ŀ���ļ�(.o)�Ϳ��ļ�(.a)��Ϣ��
arm-linux-objdump -D -m arm led_elf > led.dis
/*** objdump option:
    option:
       1. -D display all disassemble infomation.
	   2. -m machine.
	   3. -O bfdname, --output-target-bfdname.
	   4. -F bfdname ��Դ�ļ�������ļ��ĸ�ʽ����Ϊbfdname. //format.
	   5. -R sectionname ������ļ���������Ϊsectionname��  //remove.
	   6. -S ����Դ�ļ��и��ơ��ض�λ��Ϣ���͡�������Ϣ����Ŀ���ļ���.
	   7. -g ����Դ�ļ��и��ơ�������Ϣ����Ŀ���ļ���.
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

