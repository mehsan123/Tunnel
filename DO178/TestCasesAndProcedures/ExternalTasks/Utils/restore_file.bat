@echo off
setlocal

set BACKUPEXE=%1
set BACKUPTARGET=%BACKUPEXE%_ldra_backup_qq.bak


rename %BACKUPTARGET% %BACKUPEXE%



endlocal
