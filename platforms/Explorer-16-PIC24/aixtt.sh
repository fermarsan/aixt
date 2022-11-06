target=$1
#Transpiler
aixtt="python3 ../../base/aixtt.py"
c_source=${target:0:(-2)}".c"
#Compiler
cc=/opt/microchip/xc16/v2.00/bin/xc16-gcc
cflags=-mcpu=24fj128ga010
cflags+=" -I ./"
cflags+=" -o "${target:0:(-2)}".hex"


echo "Transpiling"$target

$aixtt $target

$cc $cflags $c_source

echo "Transpiling finished"