import motor_fn as motor
import sensor_fn as sensor
import time

const threshold = 40

sensor.as_light(sensor.s3)
motor.write(motor.ac, 75)

for {
	if sensor.read(sensor.s3) > threshold {
		motor.write(motor.c, -75)
		time.sleep_ms(100)
		for sensor.read(sensor.s3) > threshold {}
		motor.write(motor.ac, 75)
	} 
}
