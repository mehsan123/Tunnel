@echo off
setlocal
cd %~dp0
set SCRIPTDIR=%~dp0
call %SCRIPTDIR%SetParams\DefaultData.bat
call %SCRIPTDIR%TunnelScripts\RebuildTunnel.bat

endlocal
