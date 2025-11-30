import pin_oop as pin { Pin }
import time 
// import pwm


fn main() {
    mut green_led := pin.Pin { 
        id: pin.a
    }
    mut red_led := Pin.new(pin.w)
    pin.update()
    time.sleep_ms(2000)
    green_led.high()
    red_led.write(1)
    time.sleep(2)   
    green_led.low()
    time.sleep(2)
    red_led.write(0)
}