import motor_fn as motor
import time
import rand


const move_time = 500
const turn_time = 360


for {
	motor.write(motor.ac, 75)
	time.sleep_ms(move_time)
	if rand.rand() >= 0 {
		motor.write(motor.c, -75)
	} else {
		motor.write(motor.a, -75)
	}
	time.sleep_ms(turn_time)
}
