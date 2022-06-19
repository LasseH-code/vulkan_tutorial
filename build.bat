@echo off
if not exist build mkdir build
pushd build
cmake ..
MSBuild Tutorial.sln
popd 

