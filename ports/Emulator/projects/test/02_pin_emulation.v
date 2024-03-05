import pin
import time

fn main() {
    pin.update()
    time.sleep_ms(2000)
    pin.high(a)
    pin.write(b, 1)
    time.sleep_us(2000000)
    pin.low(a)
    time.sleep(2)
    pin.write(b, 0)
}