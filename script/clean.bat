@echo off
pushd .

if not exist build (
    md build
)

cd build
mingw32-make.exe clean > NULL 2>&1

popd
