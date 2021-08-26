set PRJ_NAME=Cpp_tunnel_lighting_system

rem remove any existing Set_test.bat file
rem =====================================
if exist SET_TEST.BAT (del /F SET_TEST.BAT)

rem use tbiniflags to search for C/C++ Ini entries
rem ==============================================
tbiniflags.exe /L"C/C++" /FTBED /FWORKAREA_BASEDIR

rem exit if TBINIFLAGS has not run correctly
rem ========================================
if not exist SET_TEST.BAT exit
if %ERRORLEVEL% == 12 exit

rem configure TBED and WORKAREA_BASEDIR
rem ===================================
call SET_TEST.BAT

set WORK_DIR=%WORKAREA_BASEDIR%\%PRJ_NAME%_tbwrkfls


rem Delete the work directory, otherwise we will end up with duplicated sequences
rem =============================================================================
start /wait %TBED%\contestbed /delete_set=%PRJ_NAME%
if exist %WORK_DIR% rmdir /s /q %WORK_DIR%
