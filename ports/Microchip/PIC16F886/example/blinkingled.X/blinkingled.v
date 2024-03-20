import time {sleep_ms}
import pin

pin.setup(a0, pin.out)
pin.setup(a1, pin.out)
pin.setup(a2, pin.out)

for {
    pin.high(a0)
    sleep_ms(200)

    pin.high(a1)
    sleep_ms(200)
    
    pin.high(a2)
    sleep_ms(200)

    pin.low(a0)
    pin.low(a1)
    pin.low(a2)
    sleep_ms(200)
}