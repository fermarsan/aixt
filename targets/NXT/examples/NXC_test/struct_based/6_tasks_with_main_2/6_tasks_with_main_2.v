import motor { Motor }
import sensor { Sensor }
import time { sleep_ms }
import task

__global (
	move_mutex	= Mutex(0)		// mutex variable
	touch_s		= Sensor.new(sensor.s1)	// sensor variable
	left_m		= Motor.new(motor.a)	// motor variables
	right_m		= Motor.new(motor.c)
	both_m		= Motor.new(motor.ac)
)

@[task]
fn move_square() {
	for {
		task.mutex_lock(move_mutex)
		both_m.write(75)
		sleep_ms(1000)
		right_m.write(-75)	// reverse
		sleep_ms(500)
		task.mutex_unlock(move_mutex)
	}
}

@[task]
fn check_sensors() {
	for {
		if touch_s.read() == 1 {
			task.mutex_lock(move_mutex)
			both_m.write(-75)	// reverse
			sleep_ms(500)
			left_m.write(75)
			sleep_ms(500)
			task.mutex_unlock(move_mutex)
		}
	}
}


@[task]
fn main() {
	touch_s.setup(sensor.touch)	// configure the sensor as touch
	task.priority(move_square, check_sensors)
}