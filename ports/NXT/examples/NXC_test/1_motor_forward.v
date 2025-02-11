// on motors A and B forward

import motor
import time

const t_on = 1000

motor.write(motor.ab, 50)
time.sleep_ms(t_on)	
motor.off(motor.ab)