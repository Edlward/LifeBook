
//================================
1007-mbsSdk:
{
sdk:
32bit eclipse, 32bit cygwin in 64 machine. 1388.

c:\mbs\SwingDoorPlatform\mbsSdk>git checkout a3cecd9b7dd1453b60bd5cd831892f8b9d5b0d8a
Previous HEAD position was d126530f Updates to make SwingDoorPlatform build
HEAD is now at a3cecd9b RDP-632: Enable helloFreeRTOS on RCUIO hw

02. Jenkins editor.
03. C:\mbs\work\mbsSdk\tools\python\mbsConsole\mbsConsole.py --port=COM4

04. help-install-software:
	CDT Kepler - http://download.eclipse.org/tools/cdt/releases/kepler
	https://www.cnblogs.com/xuch7n/p/5176922.html

	Debug Configurations => C/C++ Unit => new, SwingDoorPlatform adcInputTest, 
	C:\mbs\SwingDoorPlatform\components\application\aaesGeneric\adcInput\unitTest\_output\win_test_runner.exe

05. eclipse.	
	Build Configuration: adcInputTest.
	eclipse安装目录下\configuration\.settings\org.eclipse.ui.ide.prefs，将SHOW_WORKSPACE_SELECTION_DIALOG设置为true即可。
	
	make -j doc ABS=1
	
06. Eclipse，依次点击 Windows -> Preference
	==General标签，选中Editors选项，再选中 Test Editors
	选项：Appearance color options, 
	==C/C++标签 ，展开 Editor标签，点击Syntax Coloring 标签
	==编码字体：General->Appearance>Colors and Fonts>Basic.
	==文档字体：C/C++  ->Editor    >Syntax Coloring.
	//红-蓝-绿，黑-橙-紫；  6.
	//粗细，深浅，正斜。	6.

}

