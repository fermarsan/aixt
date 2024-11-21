REM this is a batch file to automate the installing of V and Aixt transpilers on Windows
REM copy "v.zip" and "aixt.zip" in the same folder of this file after executing as administrator

@echo off

REM Unzip v.zip to C:\v
echo Unzipping v.zip to C:\v...
powershell -command "Expand-Archive -Path '.\v.zip' -DestinationPath 'C:\v'"

REM Unzip aixt.zip to C:\aixt
echo Unzipping aixt.zip to C:\aixt...
powershell -command "Expand-Archive -Path '.\aixt.zip' -DestinationPath 'C:\aixt'"

REM Change to the C:\v directory and run make.bat
cd C:\v
echo Compiling the V programming language...
call make.bat

REM Execute v.exe symlink
echo Creating V symlink...
v.exe symlink

REM Change to the C:\aixt directory and run make.bat
cd C:\aixt
echo Compiling the Aixt microcontrollers framework...
call make.bat

REM Execute aixt.exe symlink
echo Creating Aixt symlink...
aixt.exe symlink

echo Process completed.
pause