import pin_oop2 as pin
import time 
// import pwm


fn main() {
    pin.update()
    time.sleep_ms(2000)
    pin.a.high()
    pin.b.write(1)
    time.sleep(2)   
    pin.a.low()
    time.sleep(2)
    pin.b.write(0)
}