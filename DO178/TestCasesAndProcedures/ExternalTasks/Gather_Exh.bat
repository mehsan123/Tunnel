@echo off
setlocal EnableDelayedExpansion
set SCRIPTDIR=%~dp0
cd %SCRIPTDIR%
set TBEDDIR=%~1
set SETNAME=%~2
set CURDIR=%CD%


for /D %%a in (*) do (

for %%f in (%%a\*.exh) do (
call :exhgather %%f

)



)

%TBEDDIR%\contestbed %SETNAME% /32 /force_exhdir=%CD%\


exit /B %ERRORLEVEL%

:exhgather
type %1 >> %~xn1
del %1

exit /B 0

endlocal
