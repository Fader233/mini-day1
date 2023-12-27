@echo off
pushd .

call script/clean.bat
call script/build.bat

popd
exit /B %errorlevel%