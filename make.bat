@echo off

@REM set OUTPUT_FOLDER=.\build

@REM set TARGET=%OUTPUT_FOLDER%\aixt.exe

@REM set VC=v

@REM set VFLAGS=-o

@REM set SOURCE=src

@REM %VC% %SOURCE% %VFLAGS% %TARGET%

if "%~1"=="clean" (
    @REM del .\build\aixt.exe
    rmdir .\build
    echo The Aixt executable was deleted
) else (
    mkdir .\build
    v src -o .\build\aixt.exe
    echo The Aixt executable was created at /build folder
)
