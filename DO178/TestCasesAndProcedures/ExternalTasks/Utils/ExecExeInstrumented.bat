@echo off
setlocal


set SCRIPTDIR=%~dp0

if "%TESTNUM%" == "" (

set SETNAME=%1
set EXENAME=%2
set TBEDDIR=%3
shift
shift
shift
set BATCHCMD=%*
) else (
call %SCRIPTDIR%ET%TESTNUM%\ParamData.bat
)

rem should there be quotes here?
if exist %EXENAME% (
set RESTORELATER=1
call %SCRIPTDIR%Utils\backup_file.bat %EXENAME%
) else (
set RESTORELATER=0
)
rem make sure main static and complexity analysis have been run at least
rem instrument and build

%TBEDDIR%\contestbed %SETNAME% /1120212q

rem should exact semantic analysis be enabled?
rem with exact semantic analysis /11202132q
rem note - exact semantic analysis '3' should come before build '2'
if exist %EXENAME% (
call %BATCHCMD%
) else (
exit /B 1
)
set RETURNVAL=%ERRORLEVEL%

rem what if restore fails - should the test fail? In this scenario it seems no
if "%TESTID%"=="" (
%TBEDDIR%\contestbed %SETNAME% /32q

) else (
%TBEDDIR%\contestbed %SETNAME% -dataset=%TESTID% /32q

)

del %EXENAME%

if RESTORELATER == 1 (
  call %SCRIPTDIR%Utils\restore_file.bat %EXENAME%

)

exit /B %RETURNVAL%

endlocal