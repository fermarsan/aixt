set_sensor_touch(in_1)
 forward(motor_ac, 75)
 for {
 if sensor_1 == 1 {
	reverse(motor_ac, 75) sleep(300)
	forward(motor_a, 75) sleep(300)
	forward(motor_ac, 75)
 }
 }