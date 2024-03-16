import motor

const (
	move_time = 1000
	turn_time = 500
)

total_time := 0

for total_time < 20000 {

	move_time = random(1000)
	turn_time = random(1000)

	motor.forward(ac, 75)
	sleep_ms(move_time)

	motor.reverse(c, 75)
	sleep_ms(turn_time)

	total_time += move_time
	total_time += turn_time
 }

motor.off(ac)


