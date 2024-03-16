// on motors A and B forward

import motor

const t_on = 1000

motor.forward(ab, 50)	// using the most similar version
sleep_ms(t_on)			// to NXC functions
motor.off(ab)