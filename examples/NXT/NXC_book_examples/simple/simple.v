import motor_fn as motor
import time

motor.write(motor.a, 75)
motor.write(motor.b, 50)
time.sleep_ms(4000)
motor.write(motor.ab, -75)
time.sleep_ms(4000)
motor.off(motor.ab)
