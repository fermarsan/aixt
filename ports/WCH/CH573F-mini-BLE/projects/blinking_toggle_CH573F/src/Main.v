import time { sleep_ms }
import pin 

pin.setup(a8, output)

for {
    pin.toggle(a8)    //blinking toggle port A bit 8
    sleep_ms(150)
}
