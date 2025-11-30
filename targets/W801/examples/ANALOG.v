import pin
import adc
pin.setup(pin.a1, pin.input)
pin.setup(pin.a5, pin.output)
pin.setup(pin.a6, pin.output)  

pin.low(pin.a5)
pin.low(pin.a6)



for{

if 250 >= adc.read(a1){
pin.high(pin.a5)
pin.low(pin.a6)
}
else {
pin.low(pin.a5)
pin.high(pin.a6)
}

}