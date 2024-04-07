import time { sleep_ms }
import pwm { write }

write(pwm_1, 100)

for i in 1..100 {
    sleep_ms(250)
    write(pwm_0, i)
    write(pwm_1, 100-i)
}
