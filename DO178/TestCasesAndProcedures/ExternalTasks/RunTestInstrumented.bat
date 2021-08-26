@echo off
setlocal

echo "STARTING INSTRUMENTED TEST RUN"

set SCRIPTDIR=%~dp0
set INSTRUMENTED=1
call %SCRIPTDIR%RunTest.bat %*

exit /B %ERRORLEVEL%

endlocal
