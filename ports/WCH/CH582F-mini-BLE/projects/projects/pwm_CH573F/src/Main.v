import time { sleep_ms }
import pin { setup }                         
import pwm                           

pin.setup(pin.a12, pin.output) 

value := 50

for {
    pwm.write(4, value)
    value = value + 50
    sleep_ms(300)
    if value > 250 {
        pwm.off(4)  
        sleep_ms(300)
        value = 50 
    }
}