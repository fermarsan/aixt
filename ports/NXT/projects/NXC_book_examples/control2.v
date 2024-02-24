const (
	move_time = 1000
	turn_time = 500
)

total_time := 0

for total_time < 20000 {

	move_time = random(1000)
	turn_time = random(1000)

	forward(motors_ac, 75)
	sleep(move_time)

	reverse(motor_c, 75)
	sleep(turn_time)

	total_time += move_time
	total_time += turn_time
 }

off(motors_ac)


