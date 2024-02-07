import time { sleep }
import pwm

pwm.duty(1, 100)

for i in 1..100 {
    sleep(1)
    pwm.duty(0, i)
    pwm.duty(1, 100-i)
}
