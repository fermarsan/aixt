import motor
import time { sleep_ms }

const move_time = 1000
const turn_time = 500

for _ in 1..10 {
	for _ in 1..4 {
		motor_ac.write(75)
		sleep_ms(move_time)
		motor_c.write(-75)
		sleep_ms(turn_time)
	}
}

motor_ac.off()
