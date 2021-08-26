@echo off
setlocal ENABLEDELAYEDEXPANSION
set ExeName=%1
set InputFile=%2
set OutputFile=%3
set StartDir=%4
echo Current Directory %CD%
if not "" == "%StartDir%" (

echo "Changing directory to %StartDir%"
cd /D %StartDir%
echo Current Diectory now %CD%
) else (

echo "Not Changing directory"

)
rem these need to be already quoted when passed in
echo %ExeName% %InputFile% %OutputFile%
%ExeName% < %InputFile% > %OutputFile%

exit /B %ERRORLEVEL%

endlocal
