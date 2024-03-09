import motor

move_time := 0
turn_time := 0

for {
	move_time = random(600)
	turn_time = random(400)
	motor.forward(ac, 75)
	sleep_ms(move_time)
	motor.reverse(a, 75)
	sleep_ms(turn_time)
}
