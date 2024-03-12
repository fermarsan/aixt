import time
import pin

for i in 0..5 {   //blinking the emulated pin x, 5 times
    pin.high(x)
    time.sleep(1)
    pin.low(x)
    time.sleep(1)
}