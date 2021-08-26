@echo off
setlocal ENABLEDELAYEDEXPANSION
set OUTPUTFILE=%1
set COMPAREFILE=%2

if not exist %COMPAREFILE% (
  if not exist %OUTPUTFILE% (
    exit /B 0
  ) else (
    exit /B 1
  )
) else (
  if not exist %OUTPUTFILE% (
    exit /B 1
  )
)

echo FC %OUTPUTFILE% %COMPAREFILE%
FC %OUTPUTFILE% %COMPAREFILE%

rem if the files are not the same
exit /B %ERRORLEVEL%

endlocal