import motor
import sensor
import time

sensor.as_touch(sensor.s1)
motor.write(motor.ac, 75)

for {
	if sensor.read(sensor.s1) == 1 {
		motor.write(motor.ac, -75)
		time.sleep_ms(300)

		motor.write(motor.a, 75)
		time.sleep_ms(300)

		motor.write(motor.ac, 75)
	}
}
