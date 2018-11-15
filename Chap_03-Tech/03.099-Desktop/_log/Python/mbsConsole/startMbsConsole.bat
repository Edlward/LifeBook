
set MBS_SDK_ROOT=%~dp0..\..\..

:: User config
set MBS_PYTHON_INSTALLATION_ROOT=C:\Python27

:: Add python paths
set PYTHONPATH=%PYTHONPATH%;%MBS_SDK_ROOT%\tools\python\thirdParty
set PYTHONPATH=%PYTHONPATH%;%MBS_SDK_ROOT%\tools\python\mbsTestLibrary


%MBS_PYTHON_INSTALLATION_ROOT%\python %MBS_SDK_ROOT%\tools\python\mbsConsole\mbsConsole.py %1
