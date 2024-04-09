
import time { sleep_ms }
import pin 

pin.setup(a8, pin.output)

for {
    pin.high(a8)    //blinking port A bit 8
    sleep_ms(150)
    pin.low(a8)
    sleep_ms(150)
}
