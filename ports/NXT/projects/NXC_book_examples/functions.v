import motor

fn turn_right(s int, t int) {
	motor.forward(a, s)
	motor.reverse(b, s)
	sleep_ms(t)
}

fn turn_left(s int, t int) {
	motor.reverse(a, s)
	motor.forward(b, s)
	sleep_ms(t)
}

fn forwards(s int, t int) {
	motor.forward(ab, s)
	sleep_ms(t)
}

fn backwards(s int, t int) {
	motor.reverse(ab, s)
	sleep_ms(t)
}

backwards(50,10000)
forwards(50,10000)
turn_left(75,750)
forwards(75,1000)
backwards(75,2000)
forwards(75,1000)
turn_right(75,750)
forwards(30,2000)
motor.off(ab)
