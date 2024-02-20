const (
	move_time 
	turn_time
)

 for {
	move_time = random(600)
	turn_time = random(400)
	forward(motors_ac, 75)
	sleep(move_time)
	reverse(motor_a, 75)
	sleep(turn_time)
 }