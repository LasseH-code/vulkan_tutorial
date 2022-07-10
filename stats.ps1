cd src
Get-ChildItem . -Include *.cpp, *.c, *.hpp, *.h -Recurse | Get-Content | Measure-Object -Character -Word -Line 
cd ..