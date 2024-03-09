import motor

const (
	move_time = 1000
	turn_time = 360
)

motor.forward(ac, 75)
sleep(move_time)
motor.reverse(c, 75)
sleep(turn_time)
motor.off(ac)