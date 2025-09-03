import motor
import sensor_fn as sensor
import time

sensor.as_touch(sensor.s1)
motor_ac.write(75)

for {
	if sensor.read(sensor.s1) == 1 {
		motor_ac.write(-75)
		time.sleep_ms(300)

		motor_a.write(75)
		time.sleep_ms(300)

		motor_ac.write(75)
	}
}