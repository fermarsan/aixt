import time
import pin

for i in 0..5 {   //blinking the emulated pin x, 5 times
    pin.high(x)
    time.sleep_us(500*1000)
    pin.low(x)
    time.sleep_us(500*1000)
}