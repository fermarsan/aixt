// "Draw" an square with a differential platform (motors A and B)

import motor

const t_forward = 3000
const t_turn = 500

for {
	motor.forward(ab, 50)
	sleep_ms(t_forward)
	motor.reverse(a, 50)
	sleep_ms(t_turn)
}
