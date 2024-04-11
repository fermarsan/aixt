import motor
import rand

const(
	move_time = 500
	turn_time = 360
)

for {
	motor.forward(ac, 75)
	sleep_ms(move_time)
	if rand.rand() >= 0 {
		motor.reverse(c, 75)
	} else {
		motor.reverse(a, 75)
	}
	sleep_ms(turn_time)
}