import motor
import sensor
import time

const near = 15

sensor.as_lowspeed(sensor.s4)

for {
	motor.write(motor.ac, 50)
	for sensor.read_us(sensor.s4) > near {}
	motor.off(motor.ac)
	motor.write(motor.c, -100)
	time.sleep_ms(800)
}