import motor_fn as motor
import sensor_fn as sensor
import time { sleep_ms }
import task

__global move_mutex = Mutex(0)		// mutex variable

@[task]
fn move_square() {
	for {
		task.mutex_lock(move_mutex)
		motor.write(motor.ac, 75)
		sleep_ms(1000)
		motor.write(motor.c, -75)	// reverse
		sleep_ms(500)
		task.mutex_unlock(move_mutex)
	}
}

@[task]
fn check_sensors() {
	for {
		if sensor.read(sensor.s1) == 1 {
			task.mutex_lock(move_mutex)
			motor.write(motor.ac, -75)	// reverse
			sleep_ms(500)
			motor.write(motor.a, 75)
			sleep_ms(500)
			task.mutex_unlock(move_mutex)
		}
	}
}

@[task]
fn main() {
	sensor.as_touch(sensor.s1)
	task.inv_priority(move_square, check_sensors)
}
