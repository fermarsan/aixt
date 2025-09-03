import motor_fn as motor
import time

fn turn_right(s i8, t u16) {
	motor.write(motor.a, s)
	motor.write(motor.b, -s)
	time.sleep_ms(t)
}

fn turn_left(s i8, t u16) {
	motor.write(motor.a, -s)
	motor.write(motor.b, s)
	time.sleep_ms(t)
}

fn forwards(s i8, t u16) {
	motor.write(motor.ab, s)
	time.sleep_ms(t)
}

fn backwards(s i8, t u16) {
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