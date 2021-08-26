@echo off
setlocal ENABLEDELAYEDEXPANSION
set OUTPUTFILE=%1
set FILTER=%2

echo FIND /C %Filter% %OutputFile%
FIND /C %Filter% %OutputFile%

rem if the item is not found the error level = 1
exit /B %ERRORLEVEL%

endlocal