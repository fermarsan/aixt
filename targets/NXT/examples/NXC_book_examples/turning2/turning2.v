import motor
import time

const move_time = 1000
const turn_time = 360


motor_ac.write(75)
time.sleep(move_time)
motor_c.write(-75)
time.sleep(turn_time)
motor_ac.off()
