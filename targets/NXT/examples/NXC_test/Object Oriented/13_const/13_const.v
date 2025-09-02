import motor
import time

const t_on = 1000
const t_off = 500

motor_ab.write(70)
time.sleep_ms(t_on)

motor_ab.off()
time.sleep_ms(t_off)

motor_ab.write(70)
time.sleep_ms(t_on)

motor_ab.off()