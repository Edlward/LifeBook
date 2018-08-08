
//================================
1003-install list:
{
00. _1__mbs, (Eclipse, Python, Cygwin, ST-lib, FreeRTOS.) Upgrade of the mbsSdk, 
	_2_PC-lint,
	_3_Git,  {(MinGW, manual-web, gitlab account: Jerry.Hua@assaabloy.com )
			git clone git@gitlab-group.st.assaabloy.net:mbs/mbsSdk.git 
			 .gitignore _output/ .d/}
	_4_StarTeam,
	_5_IAR,
	
	//Eclipse, 
	Jenkins,  //add path...unit-test, make clean, make runWindowsJenkins.
	//cygwin32, //C:\mbs\programs\cygwin\.  ===idcproxy, 8080. http://cygwin.mirror.constant.com. 
			  //Eclipse -> C/C++Build -> Environment -> PATH + 
			  //C:\mbs\programs\bin\.  this####.
	//MinGW, 
	
	PC-lint, 
	Doxgen, 	(html.7z)
	//Python;
	
	
01. //st-link driver:  // C:\Users\jerhua\_huamg_assa_\02.002-proj\ST link
		//C:\mbs\SwingDoorPlatform\mbsSdk\tools\debug\openocd\scripts_mbs\mcu\stm32f1.cfg
	
02. //everything;
03. vs2005.
04. //printer. \\cnsuzsfp01   setting-printer-DocuCentre-IV2060.
	//		   \\cnshisfp01
05. //Cygwin 32bit
	C:\mbs\programs\bin\mintty.exe -i /Cygwin-Terminal.ico -
	C:\Users\jerhua\cygwin64\bin\mintty.exe -i /Cygwin.ico -
	cd /c/Users/jerhua/cygwin64/bin

	apt-cyg: //lynx -source rawgit.com/transcode-open/apt-cyg/master/apt-cyg > apt-cyg
		 //install apt-cyg /bin

	'./.bashrc' -> '/home/jerhua//.bashrc'
	'./.bash_profile' -> '/home/jerhua//.bash_profile'
	'./.inputrc' -> '/home/jerhua//.inputrc'
	'./.profile' -> '/home/jerhua//.profile'


06. //Console set: mbsConsole.py shortcut: 
	//C:\mbs\work\mbsSdk\tools\python\mbsConsole\mbsConsole.py --port=COM4
	
07. //ie: idcproxy, 8080
	
08. //https://pip.pypa.io/en/stable/installing/
09. //gcovr-3.3 in cygwin32.
10. //Python. 	//run in git bash, not python shell.
	//c:\python27\lib\site-packages (3.4)
	//C:\Python27\Scripts\pip.exe
	//c:\users\jerhua\appdata\local\temp\pip-req-build-swfq5e
	//lockfile 0.10.2.post7 requires pbr!=0.7,<1.0,>=0.6, which is not installed.
	//pip install ./downloads/SomeProject-1.0.4.tar.gz
	//$ pip install 'pbr!=0.7,<1.0,>=0.6'

	 
11. //---//diffMerge.
12. VirtualBox.

14. //Gradle.  This PC (or Computer) icon, then click Properties -> 
	//Advanced System Settings -> Environmental Variables.
	//$ export PATH=$PATH:/c/gradle/gradle-4.7/bin
	//$ export PATH=$PATH:/c/meld186/meld
	// http://download.eclipse.org/release/oxygen
15. //meld.
	//download *.zip, extract in Your-path, 
	//$ export PATH=$PATH:/c/mbs/programs/cygwin/bin
	//git config --global diff.tool meld
	//git config --global diff.meld.path "C:\Program Files (x86)\Meld\Meld.exe"
	//git config --global merge.tool meld
	//git config --global mergetool.meld.path "you-path\Meld\Meld.exe"
	//then can use, to check file one by one.
	//diff folder, use 'diff-all.sh'. //http://www.cnblogs.com/xiezhaohai/archive/2017/05/04/6805654.html
	//add : cd /c/mbs/SwingDoorPlatform, pwd.
	//put 'diff-all.sh' in folder '/c/mbs/'.

16. //notepad++ 
	//view -> Show symbol -> show all char.
	//edid -> EOL conversion.
		
}

