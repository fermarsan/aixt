import time { sleep_ms }
import pwm { write }

write(pwm.out_1, 100)

for i in 1..100 {
    sleep_ms(250)
    write(pwm.out_0, i)
    write(pwm.out_1, 100-i)
}
