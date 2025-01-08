import motor
import sensor
import time
import task


@[mutex]
__global move_mutex = 0		// initialization value is necessary but will be ignored

@[task]
fn move_square() {
	for {
		task.acquire(move_mutex)
		motor.write(motor.ac, 75)
		time.sleep_ms(1000)
		motor.write(motor.c, -75)	// reverse
		time.sleep_ms(500)
		task.release(move_mutex)
	}
}

@[task]
fn check_sensors() {
	for {
		if sensor.read(sensor.s1) == 1 {
			task.acquire(move_mutex)
			motor.write(motor.ac, -75)	// reverse
			time.sleep_ms(500)
			motor.write(motor.a, 75)
			time.sleep_ms(500)
			task.release(move_mutex)
		}
	}
}


sensor.as_touch(sensor.s1)
task.precedes(move_square, check_sensors)
