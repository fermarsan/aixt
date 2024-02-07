import time
import pin

for {   //blinking the emulated pin x
    pin.high(x)
    time.sleep_ms(500)
    pin.low(x)
    time.sleep_ms(500)
}