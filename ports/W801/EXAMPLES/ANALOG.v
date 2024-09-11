import pin

pin.setup(a1, input)
pin.setup(a5, output)
pin.setup(a6, output)  

pin.low(a5)
pin.low(a6)



for{

if 250 >= adc.read(a1){
pin.high(a5)
pin.low(a6)
}
else {
pin.low(a5)
pin.high(a6)
}

}