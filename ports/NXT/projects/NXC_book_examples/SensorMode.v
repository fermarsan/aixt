set_sensor_type(in_1, sensor_type_touch)
SetSensorMode(in_1, sensor_type_pulse)

for {
	clear_sensor(in_1)
	for !(sensor_1 > 0) {}
	wait(500)
	if sensor_1 == 1 {off(motor_ac)}
	if sensor_1 == 2 {forward(motor_ac, 75)}
}