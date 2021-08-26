@echo off
setlocal

set TBEDDIR=%~1
set SETNAME=%~2
set CURDIR=%CD%
%TBEDDIR%\contestbed %SETNAME% /212q

endlocal