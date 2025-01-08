import motor
import time

fn turn_right(s int, t int) {
	motor.write(motor.a, s)
	motor.write(motor.b, -s)
	time.sleep_ms(t)
}

fn turn_left(s int, t int) {
	motor.write(motor.a, -s)
	motor.write(motor.b, s)
	time.sleep_ms(t)
}

fn forwards(s int, t int) {
	motor.write(motor.ab, s)
	time.sleep_ms(t)
}

fn backwards(s int, t int) {
	motor.write(motor.ab, -s)
	time.sleep_ms(t)
}

backwards(50,10000)
forwards(50,10000)
turn_left(75,750)
forwards(75,1000)
backwards(75,2000)
forwards(75,1000)
turn_right(75,750)
forwards(30,2000)
motor.off(motor.ab)
