import motor_fn as motor
import time

const t_on = 1000
const t_off = 500


motor.write(motor.ab, 70)
time.sleep_ms(t_on)

motor.off(motor.ab)
time.sleep_ms(t_off)

motor.write(motor.ab, 70)
time.sleep_ms(t_on)

motor.off(motor.ab)
