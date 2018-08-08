Have you missed functions like tab completion and command history as in a 
normal shell, e.g. bash, while working with the MBS console using a 
terminal program like putty? 

I have put together a python program that adds these features.  It uses the 
command 'help' to determine what commands are available and can then help 
out the user while typing.

The program needs a third-party python module for serial ports (pyserial), 
which is actually included in the SDK.

On Windows - using shortcut:
- Install Python XY (native, not cygwin) from http://www.python.org/getit/
- Create/modify windows environment variable PYTHONPATH by adding the path to c:\path-to-your-mbssdk\tools\python\thirdParty
- Create a shortcut on desktop to c:\path-to-your-mbssdk\tools\python\mbsConsole\mbsConsole.py
- Right-click and edit properties of the shortcut to modify the ‘Target:’ field
  - Add c:\python27\python.exe in front of the script. 
  - Add com port name at the end as a parameter.
  - Ex: C:\Python27\python.exe C:\work\path-to-your-mbssdk\tools\python\mbsConsole\mbsConsole.py COM1

On Linux:
- sudo apt-get install python python-tk
- cd path-to-your-mbssdk/tools/python/mbsConsole
- export PYTHONPATH=$PYTHONPATH:/path-to-your-mbssdk/tools/python/mbsConsole
- python mbsConsole.py /dev/ttyS0


