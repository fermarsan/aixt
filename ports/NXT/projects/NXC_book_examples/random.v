import motor
import rand

move_time := 0
turn_time := 0

for {
	move_time = rand.random(600)
	turn_time = rand.random(400)
	motor.forward(ac, 75)
	sleep_ms(move_time)
	motor.reverse(a, 75)
	sleep_ms(turn_time)
}
