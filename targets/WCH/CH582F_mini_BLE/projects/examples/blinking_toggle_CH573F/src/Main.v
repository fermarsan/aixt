import time { sleep_ms }
import pin 

pin.setup(pin.a8, pin.output)

for {
    pin.toggle(pin.a8)    //blinking toggle port A bit 8
    sleep_ms(150)
}
