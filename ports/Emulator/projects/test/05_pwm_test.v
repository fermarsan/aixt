import time { sleep }
import pwm

pwm.duty(pwm_1, 100)

for i in 1..100 {
    sleep(1)
    pwm.duty(pwm_0, i)
    pwm.duty(pwm_1, 100-i)
}
