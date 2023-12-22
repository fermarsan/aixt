const (
	move_time = 1000
	turn_time = 500
)

for n in 1..4 {
	forward(motors_ac, 75)
	sleep(move_time)
	reverse(motor_c, 75)
	sleep(turn_time)
}

off(motors_ac)