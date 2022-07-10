@echo off

pushd bin
pushd debug
start cmd /k "call ..\..\run_in_cmd.bat %~dp0"
popd
popd