import time
import pin

for _ in 0..5 {   //blinking the emulated pin x, 5 times
    pin.high(pin.x)
    time.sleep(1)
    pin.low(pin.x)
    time.sleep(1)
}