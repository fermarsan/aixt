import time { sleep_ms }
import pwm { write }

write(pwm1, 100)

for i in 1..100 {
    sleep_ms(250)
    write(pwm0, i)
    write(pwm1, 100-i)
}
