
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
	eclipse��װĿ¼��\configuration\.settings\org.eclipse.ui.ide.prefs����SHOW_WORKSPACE_SELECTION_DIALOG����Ϊtrue���ɡ�
	
	make -j doc ABS=1
	
06. Eclipse�����ε�� Windows -> Preference
	==General��ǩ��ѡ��Editorsѡ���ѡ�� Test Editors
	ѡ�Appearance color options, 
	==C/C++��ǩ ��չ�� Editor��ǩ�����Syntax Coloring ��ǩ
	==�������壺General->Appearance>Colors and Fonts>Basic.
	==�ĵ����壺C/C++  ->Editor    >Syntax Coloring.
	//��-��-�̣���-��-�ϣ�  6.
	//��ϸ����ǳ����б��	6.

}

