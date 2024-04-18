@REM set TARGET=aixt.exe

@REM set VC=v

@REM set VFLAGS=-o

@REM set SOURCE=src

@REM %VC% %SOURCE% %VFLAGS% %TARGET%

if %1 == "clean" (
    rm aixt.exe
) else (
    v src -o aixt.exe
)
