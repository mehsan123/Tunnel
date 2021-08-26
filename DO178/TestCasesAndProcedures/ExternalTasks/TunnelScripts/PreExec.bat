
if not exist %EXENAME% (
  echo %EXENAME% does not exist
  %SCRIPTDIR%TunnelScripts\RebuildTunnel.bat
  if exist %EXENAME% (
    echo Build successful
  ) else (
    echo Build failed
  )
) else (
  echo %EXENAME% exists
)

