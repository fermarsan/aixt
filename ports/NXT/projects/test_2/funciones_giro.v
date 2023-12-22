
fn spin(left_m i16, right_m i16, power i16) {
	forward(left_m, power)
	reverse(right_m, power)
}

spin(motor_a, motor_b, 75)
sleep(1000)
off(motors_ab)