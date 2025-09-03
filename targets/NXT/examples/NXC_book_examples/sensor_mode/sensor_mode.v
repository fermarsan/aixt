import motor_fn as motor
import sensor_fn as sensor
import time

sensor.write_type(sensor.s1, sensor.type_touch)
sensor.write_mode(sensor.s1, sensor.mode_pulse)

for {
	sensor.clear(sensor.s1)
	for sensor.read(sensor.s1) <= 0 {}
	time.sleep_ms(500)
	if sensor.read(sensor.s1) == 1 {
		motor.off(motor.ac)
	}
	if sensor.read(sensor.s1) == 2 {
		motor.write(motor.ac, 75)
	}
}