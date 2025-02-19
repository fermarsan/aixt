import time
import pwm

pwm.write(pwm.ch1, 100)

for i in 1..51 {
    time.sleep_ms(500)
    pwm.write(pwm.ch0, i)
    pwm.write(pwm.ch1, 100-i)
}