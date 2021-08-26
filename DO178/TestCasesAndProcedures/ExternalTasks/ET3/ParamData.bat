call %SCRIPTDIR%SetParams\%SETNAME%.bat
set BATCHTEST=%SCRIPTDIR%Utils\RunFindTextCheck.bat
rem for each incorrect param it should reprompt
set TESTPARAM=Enter photometer input in range 4-20mA: Enter photometer input in range 4-20mA: Enter photometer input in range 4-20mA: Enter photometer input in range 4-20mA: Enter photometer input in range 4-20mA:
set RUNTESTCMD="%BATCHTEST%" "%OUTPUTDATA%" "%TESTPARAM%"

