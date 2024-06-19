import pin

pin.setup(a1, pin.input)
pin.setup(a5, pin.output)
pin.setup(a6, pin.output)  

pin.low(a5)
pin.low(a6)



for{

if 250 >= adc__read(a1){
pin.high(a5)
pin.low(a6)
}
else {
pin.low(a5)
pin.high(a6)
}

}