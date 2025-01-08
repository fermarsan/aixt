import motor
import rand
import time

move_time := 0
turn_time := 0

for {
	move_time = rand.random(600)
	turn_time = rand.random(400)
	motor.write(motor.ac, 75)
	time.sleep_ms(move_time)
	motor.write(motor.a, -75)
	time.sleep_ms(turn_time)
}
