@echo off
setlocal

set BACKUPEXE=%1
set BACKUPTARGET=%BACKUPEXE%_ldra_backup_qq.bak

if exist %BACKUPTARGET% (
echo "Backup Failed - backup already exists with same backup name"
exit /B 1
) else (
rename %BACKUPEXE% %BACKUPTARGET%
)

endlocal
