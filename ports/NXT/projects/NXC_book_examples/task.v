move_mutex := mutex()

@[task]
fn move_square() {
	for {
		acquire(move_mutex)
		motor.forward(motors_ac, 75)
		sleep_ms(1000)
		motor.reverse(motor_c, 75)
		sleep_ms(500)
		release(move_mutex)
	}
}

@[task]
fn check_sensors() {
	for {
		if sensor.read(i1) == 1 {
			acquire(move_mutex)
			motor.reverse(motors_ac, 75)
			sleep_ms(500)
			motor.forward(motor_a, 75)
			sleep_ms(500)
			release(move_mutex)
		}
	}
}

@[task]
fn main() {
	precedes(move_square, check_sensors)
	sensor.set_touch(i1)
}
