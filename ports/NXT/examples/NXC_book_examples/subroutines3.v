import motor
import time

@[inline]
fn turn_around(pwr int, turntime int) {
	motor.write(motor.c, -pwr)
	time.sleep_ms(turntime)
	motor.write(motor.ac, pwr)
}

motor.write(motor.ac, 75)
time.sleep_ms(1000)
turn_around(75, 2000)
time.sleep_ms(2000)
turn_around(75, 500)
time.sleep_ms(1000)
turn_around(75, 3000)
motor.off(motor.ac)
