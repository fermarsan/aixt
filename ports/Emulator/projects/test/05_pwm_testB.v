import time { sleep_ms }
import pwm

pwm.duty(1, 100)

for i in 1..100 {
    sleep_ms(500)
    pwm.duty(0, i)
    pwm.duty(1, 100-i)
}
