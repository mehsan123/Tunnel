@echo off
setlocal

echo "STARTING NEW TEST RUN"
cd %~dp0
set SCRIPTDIR=%~dp0
set TESTNUM=%1
set TBEDDIR=%2
set SETNAME=%3

if "%TESTNUM%" == "" (
  set TESTNUM=1
)

echo TEST NUMBER %TESTNUM%
if exist %SCRIPTDIR%ET%TESTNUM%\ParamData.bat (
  call %SCRIPTDIR%ET%TESTNUM%\ParamData.bat
) else (
  if exist %SCRIPTDIR%SetParams\%SETNAME%.bat (
    echo RUNNING STANDARD TEST
    call %SCRIPTDIR%SetParams\%SETNAME%.bat
  ) else (
    if exist %SCRIPTDIR%SetParams\DefaultData.bat (
      call %SCRIPTDIR%SetParams\DefaultData.bat
    ) else (
      echo No Test Params
      exit /B 1
    )
  )
)
set > %SCRIPTDIR%test_data.txt
if exist %STARTIN% (
cd %STARTIN%

)

echo LOADED PARAMETER DATA

if not exist %TESTDIR% (
  mkdir %TESTDIR%
)

echo "--------------------" >> %TESTDIR%batch_log.log 2>&1
echo STARTING TEST RUN AT %DATE% %TIME% >> %TESTDIR%batch_log.log 2>&1
echo TEST NUMBER %TESTNUM% >> %TESTDIR%batch_log.log 2>&1

echo FOUND TEST DIRECTORY
echo FOUND TEST DIRECTORY >> %TESTDIR%batch_log.log 2>&1

if exist %PREEXECBATCH% (
  echo CALLING PRE EXEC
  echo CALLING PRE EXEC >> %TESTDIR%batch_log.log 2>&1
  call %PREEXECCMD% >> %TESTDIR%batch_log.log 2>&1
)

echo CALLED PRE EXEC COMMAND IF ANY
echo CALLED PRE EXEC COMMAND IF ANY >> %TESTDIR%batch_log.log 2>&1

if exist %STARTIN% (
cd %STARTIN%

)

echo Starting Time: %TIME% >> %TESTDIR%batch_log.log 2>&1

echo Using Command %BATCHCMD%
echo Using Command %BATCHCMD% >> %TESTDIR%batch_log.log 2>&1
echo %BATCHCMD% >> %TESTDIR%batch_log.log 2>&1
if exist %BATCHNAME% (
  if "%INSTRUMENTED%" == "" (
    call %BATCHCMD% >> %TESTDIR%batch_log.log 2>&1
    echo CALLED UNINSTRUMENTED >> %TESTDIR%batch_log.log 2>&1
  ) else (
    call %RUNINSTRCMD% >> %TESTDIR%batch_log.log 2>&1
    echo CALL INSTRUMENTED >> %TESTDIR%batch_log.log 2>&1
  )
  echo RETURN CODE OF EXECUTION %ERRORLEVEL% >> %TESTDIR%batch_log.log 2>&1
) else (
  echo Could not find execution batch script >>  %TESTDIR%batch_log.log 2>&1
)


echo Ending Time: %TIME% >>  %TESTDIR%batch_log.log 2>&1

echo FINISHED EXECUTION
echo FINISHED EXECUTION >> %TESTDIR%batch_log.log 2>&1

if exist %STARTIN% (
cd %STARTIN%

)

if "%BATCHTEST%" == "" (
echo NO TEST - JUST CHECKING RETURN CODE
) else (
  rem only run test if execution was successful prevents bad data being read
  if exist "%BATCHTEST%" (
    if %ERRORLEVEL% == 0 (
      set TESTFINISHED=1
      echo CALLING TESTDATA TEST
      echo CALLING TESTDATA TEST >> %TESTDIR%batch_log.log 2>&1
      call %RUNTESTCMD% >> %TESTDIR%batch_log.log 2>&1
      echo FINISH CALLING TESTDATA TEST
      echo FINISH CALLING TESTDATA TEST >> %TESTDIR%batch_log.log 2>&1
    ) else (
      echo TEST FAILED TO FINISH SUCCESSFULLY
      echo TEST FAILED TO FINISH SUCCESSFULLY >> %TESTDIR%batch_log.log 2>&1
      set TESTFINISHED=0
    )
  ) else (
    echo Could not find test script >> %TESTDIR%batch_log.log 2>&1
    exit /B 1
  )
)


if exist %POSTEXECBATCH% (
  echo CALLING POST EXEC
  echo CALLING POST EXEC >> %TESTDIR%batch_log.log 2>&1
  call %POSTEXECCMD% >> %TESTDIR%batch_log.log 2>&1
  echo FINISH CALLING POST EXEC
  echo FINISH CALLING POST EXEC >> %TESTDIR%batch_log.log 2>&1
)


if %ERRORLEVEL% == 0 (
  echo "SUCCESS" >> %TESTDIR%batch_log.log 2>&1
  echo "SUCCESS"
) else (
  echo "FAILURE" >> %TESTDIR%batch_log.log 2>&1
  echo "FAILURE"
)
echo "--------------------" >> %TESTDIR%batch_log.log 2>&1

echo "DONE"
echo "DONE" >> %TESTDIR%batch_log.log 2>&1
set ECODE=%ERRORLEVEL%

if exist *.exh (
  move /Y *.exh %TESTDIR%
)

exit /B %ECODE%

endlocal
