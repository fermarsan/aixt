param ( 
    [Parameter(Mandatory=$True)][string]$target
)
#Transpiler
$aixtt="python ..\..\base\aixtt.py"
$c_source=$target.replace('.v','.c')
#Compiler
$cc="C:\Program files\microchip\xc16\v2.00\bin\xc16-gcc.exe"
$cflags=-mcpu=24fj128ga010
$cflags+=" -I .\"
$cflags+=" -I ../../api/Explorer-16-PIC24"
$cflags+=" -o "$target.replace('.v','.hex')


Write-Host "Transpiling"$target

$aixtt $target

$cc $cflags $c_source

Write-Host "Transpiling finished"