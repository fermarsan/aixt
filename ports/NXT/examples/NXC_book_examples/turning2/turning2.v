import motor
import time

const move_time = 1000
const turn_time = 360


motor.write(motor.ac, 75)
time.sleep(move_time)
motor.write(motor.c, -75)
time.sleep(turn_time)
motor.off(motor.ac)