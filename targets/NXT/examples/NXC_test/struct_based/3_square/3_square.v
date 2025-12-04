// "Drawing" an square with a differential platform (motors A and B)

import motor
import time


const t_forward = 3000
const t_turn = 500

for {
	motor_a.write(50)
	motor_b.write(-50)	// reverse
	time.sleep_ms(t_forward)
	motor_a.write(-50)	// reverse
	time.sleep_ms(t_turn)
}