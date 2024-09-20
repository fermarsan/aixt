import time
import pwm

pwm.write(1, 100)

for i in 1..51 {
    time.sleep_ms(500)
    pwm.write(0, i)
    pwm.write(1, 100-i)
}