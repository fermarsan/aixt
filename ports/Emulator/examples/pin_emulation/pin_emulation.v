import pin
import time

fn main() {
    pin.update()
    time.sleep_ms(2000)
    pin.high(pin.a)
    pin.write(pin.b, 1)
    time.sleep(2)   
    pin.low(pin.a)
    time.sleep(2)
    pin.write(pin.b, 0)
}