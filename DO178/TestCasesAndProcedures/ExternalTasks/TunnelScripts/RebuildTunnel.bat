setlocal

cd /D %SOURCEDIR%
set PATH=C:\MinGW\BIN;%PATH%
set INCLUDE=C:\MinGW\INCLUDE;%INCLUDE%
set C_INCLUDE_PATH=C:\MinGW\INCLUDE;%C_INCLUDE_PATH%
set LIB=C:\MinGW\LIB;%LIB%
set LIBRARY_PATH=C:\MinGW\LIB;%LIBRARY_PATH%
set GCC_EXEC_PREFIX=

g++ -DCppOnly "%SOURCEDIR%Cell.cpp" "%SOURCEDIR%Tunnel.cpp" "%SOURCEDIR%Systemdata.cpp" "%SOURCEDIR%Mountings.cpp" "%SOURCEDIR%Main.cpp" "%SOURCEDIR%Lamptype.cpp" "%SOURCEDIR%Lampmodel.cpp" "%SOURCEDIR%Lamp.cpp" "%SOURCEDIR%Datain.cpp" "%SOURCEDIR%Zone.cpp" -o "%SOURCEDIR%Cpp_tunnel_lighting_system.exe"


endlocal
