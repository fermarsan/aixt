import motor

@[inline]
fn turn_around() {
	motor.reverse(c, 75)
	sleep_ms(900)
	motor.forward(ac, 75)
}

motor.forward(ac, 75)
sleep_ms(1000)
turn_around()
sleep_ms(2000)
turn_around()
sleep_ms(1000)
turn_around()
motor.off(ac)
