import motor_fn as motor
import time

const move_time = 1000
const turn_time = 500

for _ in 1..4 {
	motor.write(motor.ac, 75)
	time.sleep_ms(move_time)
	motor.write(motor.c, -75)
	time.sleep_ms(turn_time)
}

motor.off(motor.ac)
