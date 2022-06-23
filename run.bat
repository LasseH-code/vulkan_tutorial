@echo off

pushd bin
pushd debug
start cmd.exe /k "call ..\..\run_in_cmd.bat"
popd
popd