import motor

const (
	move_time = 1000
	turn_time = 500
)

for n in 1..10 {
	for n in 1..4 {
		motor.forward(ac, 75)
		sleep_ms(move_time)
		motor.reverse(c, 75)
		sleep_ms(turn_time)
	}
}

motor.off(ac)