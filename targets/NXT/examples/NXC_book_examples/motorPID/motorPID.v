import motor_fn as motor
import time

const p = 50
const i = 50
const d = 50

motor.rotate_pid(motor.a, 100, 180, p, i, d)
time.sleep_ms(3000)
