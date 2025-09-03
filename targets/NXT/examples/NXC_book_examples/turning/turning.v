import motor_fn as motor
import time

motor.write(motor.ac, 75)
time.sleep_ms(800)
motor.write(motor.c, -75)
time.sleep_ms(360)
motor.off(motor.ac)
