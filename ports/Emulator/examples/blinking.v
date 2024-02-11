import time
import pin

for i in 0..10 {   //blinking the emulated pin x, 10 times
    pin.high(x)
    time.sleep_ms(500)
    pin.low(x)
    time.sleep_ms(500)
}