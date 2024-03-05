@[task] fn move_square() {
    for {
        acquire(move_mutex)
        forward(motors_ac, 75); wait(1000)
        reverse(motor_c, 75); wait(500)
        release(move_mutex)
    }
}

@[task] fn check_sensors() {
    for {
        if sensor_1 == 1 {
            acquire(move_mutex)
            reverse(motors_ac, 75); wait(500)
            forward(motor_a, 75); wait(500)
            release(move_mutex)
        }
    }
}

fn main() {
	move_mutex := mutex('') //initialization value is necesary but will be ingnored 

	precedes(move_square, check_sensors)
	set_sensor_touch(in_1)
}