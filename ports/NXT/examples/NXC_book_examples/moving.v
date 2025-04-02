import motor
import time

const turn_time = 360

mut move_time := 200

for _ in 1..50 {
	motor.write(motor.ac, 75)
	time.sleep_ms(move_time)
	motor.write(motor.c, -75)
	time.sleep_ms(turn_time)
    move_time += 200
}

motor.off(motor.ac)