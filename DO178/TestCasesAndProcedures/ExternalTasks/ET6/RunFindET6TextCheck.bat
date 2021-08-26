@echo off
setlocal ENABLEDELAYEDEXPANSION
set OUTPUTFILE=%1
set FILTER=%2

FIND /C "Power: Live" %OutputFile%

if %ERRORLEVEL% == 0 (
  FIND /C "Power: Failed" %OutputFile%
  if %ERRORLEVEL% == 0 (
    exit /B 0
  ) else (
    exit /B 1
  )
) else (
exit /B 1
)

endlocal