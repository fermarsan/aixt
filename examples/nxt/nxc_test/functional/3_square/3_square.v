// "Drawing" an square with a differential platform (motors A and B)

import motor_fn as motor
import time


const t_forward = 3000
const t_turn = 500

for {
	motor.write(motor.a, 50)
	motor.write(motor.b, -50)	// reverse
	time.sleep_ms(t_forward)
	motor.write(motor.a, -50)	// reverse
	time.sleep_ms(t_turn)
}
