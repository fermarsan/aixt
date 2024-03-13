import motor
import sensor

sensor.set_touch(i1)
motor.forward(ac, 75)

for {
	if sensor.read(i1) == 1 {
		motor.reverse(ac, 75)
		sleep_ms(300)

		motor.forward(a, 75)
		sleep_ms(300)

		motor.forward(ac, 75)
	}
}
