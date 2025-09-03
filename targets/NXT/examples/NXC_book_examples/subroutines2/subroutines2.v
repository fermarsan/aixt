import motor_fn as motor
import time

@[inline]
fn turn_around() {
	motor.write(motor.c, -75)
	time.sleep_ms(900)
	motor.write(motor.ac, 75)
}

motor.write(motor.ac, 75)
time.sleep_ms(1000)
turn_around()
time.sleep_ms(2000)
turn_around()
time.sleep_ms(1000)
turn_around()
motor.off(motor.ac)