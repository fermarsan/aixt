import motor_fn as motor
import time

const t_fwd	 = 1000
const t_turn = 500

for {
	motor.write(motor.ab, 50)
	time.sleep_ms(t_fwd)
	motor.off(motor.a)
	time.sleep_ms(t_turn)
}

