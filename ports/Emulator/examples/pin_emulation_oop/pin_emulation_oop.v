import pin_oop //as pin
import time 


fn main() {
    mut led_1 := pin_oop.Pin{ pin_oop.a }
    pin_oop.update()
    time.sleep_ms(2000)
    led_1.high()
    // pin_oop.write(pin_oop.b, 1)
    // time.sleep(2)   
    // pin_oop.low(pin_oop.a)
    // time.sleep(2)
    // pin_oop.write(pin_oop.b, 0)
}