import time { sleep }
import pwm { duty }

duty(pwm_1, 100)

for i in 1..100 {
    sleep(1)
    duty(pwm_0, i)
    duty(pwm_1, 100-i)
}
