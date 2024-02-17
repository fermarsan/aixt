#define	move_time 500
#define	turn_time 360

for {
	forward(motor_ac, 75)
	sleep(move_time)
	if random() >= 0 {
		reverse(motor_c, 75)
	} else {
		reverse(motor_a, 75)
	}
	sleep(turn_time)
}