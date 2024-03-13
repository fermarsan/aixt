import motor

@[inline]
fn turn_around(pwr int, turntime int) {
	motor.reverse(c, pwr)
	sleep_ms(turntime)
	motor.forward(ac, pwr)
}

motor.forward(ac, 75)
sleep_ms(1000)
turn_around(75, 2000)
sleep_ms(2000)
turn_around(75, 500)
sleep_ms(1000)
turn_around(75, 3000)
motor.off(ac)
