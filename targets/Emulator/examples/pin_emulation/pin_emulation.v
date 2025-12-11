import pin { Pin }
import time 

fn main() {
    mut green_led := Pin { pin.a }
    mut red_led := Pin.new(pin.w)
    time.sleep_ms(1000)
    green_led.high()
    red_led.write(1)
    time.sleep(1)   
    green_led.low()
    time.sleep(1)
    red_led.write(0)
}