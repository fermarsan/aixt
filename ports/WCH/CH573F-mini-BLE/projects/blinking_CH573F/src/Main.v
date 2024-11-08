import time { sleep_ms }
import pin 

pin.setup(pin.a8, pin.output)

for {
    pin.high(pin.a8)    //blinking port A bit 8
    sleep_ms(150)
    pin.low(pin.a8)
    sleep_ms(150)
}