
@echo off
if not exist build mkdir build
pushd build
echo -------------cmake-------------
cmake ..
echo.
echo ------------MSBuild------------
MSBuild Tutorial.sln
popd 

 