import motor
import time

@[inline]
fn turn_around(pwr int, turntime int) {
	motor_c.write(-pwr)
	time.sleep_ms(turntime)
	motor_ac.write(pwr)
}

motor_ac.write(75)
time.sleep_ms(1000)
turn_around(75, 2000)
time.sleep_ms(2000)
turn_around(75, 500)
time.sleep_ms(1000)
turn_around(75, 3000)
motor_ac.off()