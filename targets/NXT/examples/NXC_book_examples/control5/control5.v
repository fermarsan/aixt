import motor_fn as motor
import sensor_fn as sensor
import time

const threshold = 40

sensor.as_sound(sensor.s2, true)

for {
	for sensor.read(sensor.s2) <= threshold {}
	motor.write(motor.ac, 75)
	time.sleep_ms(300)
	for sensor.read(sensor.s2) <= threshold {}
	motor.off(motor.ac)
	time.sleep_ms(300)
}
