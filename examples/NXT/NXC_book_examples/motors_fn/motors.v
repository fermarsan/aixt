import motor_fn as motor
import time

motor.write(motor.ac, 75)
time.sleep_ms(500)
motor.off(motor.ac)
time.sleep_ms(1000)
motor.write(motor.ac, 75)
time.sleep_ms(500)
motor.float(motor.ac)