import motor
import time

const t_fwd	 = 1000
const t_turn = 500

for {
	motor_ab.write(50)
	time.sleep_ms(t_fwd)
	motor_a.off()
	time.sleep_ms(t_turn)
}