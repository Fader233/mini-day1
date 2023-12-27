@echo off
pushd .

call script/clean.bat
call script/build.bat
if %errorlevel% NEQ 0 (
     popd 
     exit /B 1
)

call script/run.bat

popd
exit /B %errorlevel%