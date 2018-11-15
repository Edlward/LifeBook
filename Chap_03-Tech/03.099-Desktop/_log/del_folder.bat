@echo off
set "spath=C:\mbs\SwingDoorPlatform"		%需要处理的目标路径%
set "find=_output" 							%需要删除的文件夹%
if %spath:~-1%==\ set spath=%spath:~0,-1%
for /f "delims=" %%1 in ('dir/s/b/ad "%spath%"')do (
	if %%~n1==%find% (
		echo %%1 							%显示删除结果%
		rem rd /q/s "%%1" 					%删除的话把rem三个字去掉,这里是防误删%
		rd /q/s "%%1"
	)
)
pause
