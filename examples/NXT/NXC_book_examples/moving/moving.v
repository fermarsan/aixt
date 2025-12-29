import motor_fn as motor
import time

const turn_time = 360

mut move_time := 200

for _ in 1..50 {
	motor_ac.write(75)
	time.sleep_ms(move_time)
	motor_c.write(-75)
	time.sleep_ms(turn_time)
    move_time += 200
}

motor_ac.off()
