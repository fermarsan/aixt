// on motors A and B forward

import motor
import time

const t_on = 1000
const both = motor.ab

motor.write(both, 50)
time.sleep_ms(t_on)	
motor.off(both)