import motor
import sensor

sensor.set_type(i1, type_touch)
sensor.set_mode(i1, type_pulse)

for {
	sensor.clear(i1)
	for sensor.read(i1) <= 0 {}
	sleep_ms(500)
	if sensor.read(i1) == 1 {
		motor.off(ac)
	}
	if sensor.read(i1) == 2 {
		motor.forward(ac, 75)
	}
}
