// on motors A and B forward

import motor
import time

const t_on = 1000

motor.write(motor.ab, 50)	// using the most similar version
time.sleep_ms(t_on)			// to NXC functions
motor.off(motor.ab)