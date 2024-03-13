import motor

const t_fwd	 = 1000
const t_turn = 500

for {
	motor.forward(ab, 50)
	sleep_ms(t_fwd)
	motor.off(a)
	sleep_ms(t_turn)
}

