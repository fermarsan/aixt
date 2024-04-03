import time { sleep_ms }
import pin { high, low }

pin.setup(a8, pin.output)

for {
    high(a8)    //blinking port A bit 8
    sleep_ms(1500)
    low(a8)
    sleep_ms(1500)
}