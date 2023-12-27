@echo off
pushd .

if not exist build (
	echo "helloTest not exists!"
	popd
	exit(1)
)

cd build/tests

helloTest.exe

popd
