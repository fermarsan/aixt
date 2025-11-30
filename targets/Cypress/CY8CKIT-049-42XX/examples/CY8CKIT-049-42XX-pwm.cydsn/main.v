import time {sleep_ms}
import pwm

//pin.setup(17, pin.output)

for {
    pwm.write(pwm.ch0, 10000)
    sleep_ms(500)

    pwm.write(pwm.ch0, 5000)
    sleep_ms(500)

    pwm.write(pwm.ch0, 0)
    sleep_ms(500)
    
 }
