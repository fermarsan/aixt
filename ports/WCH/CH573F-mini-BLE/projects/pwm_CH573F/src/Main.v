import time { sleep_ms }
import pin { setup }                         
import pwm                           

pin.setup(a12, pin.output) 

value := 0

for {
    pwm.write(4, value, High_Level, ENABLE)
    sleep_ms(300)
    value=value+50
    if value>250 {
        value=0        
    }
}