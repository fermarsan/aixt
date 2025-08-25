import pin_oop //as pin
import time 


fn main() {
    mut led_1 := pin_oop.Pin{ pin_oop.a }
    mut led_2 := pin_oop.Pin{ pin_oop.b }
    pin_oop.update()
    time.sleep_ms(2000)
    led_1.high()
    led_2.write(1)
    time.sleep(2)   
    led_1.low()
    time.sleep(2)
    led_2.write(0)
}