REM The new command only used to create the actual package folder with initial files and content
REM choco new --force tree
copy ..\build\Release\*.exe .\tree\tools
cd tree
choco pack
copy .\*.nupkg ..\..\deploy\chocolatey
del .\*.nupkg
cd ..
del .\tree\tools\*.exe
PAUSE