@echo off
pushd .

if not exist build (
     md build
)

cd build
cmake -G"MinGW Makefiles" ..
if %errorlevel% NEQ 0 (
     popd 
     echo "please delete build directory and retry!"
     exit /B 1
)

mingw32-make.exe
if %errorlevel% NEQ 0 (
     popd 
     exit /B 1
)

popd
exit /B 0