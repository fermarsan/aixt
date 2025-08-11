import motor
import sensor
import time


const black = 40
const can_near = 2

sensor.as_light(sensor.s1, true)
sensor.as_ultrasonic(sensor.s2)


time.sleep(1)
motor.write(motor.ab, 60)

for {
	if sensor.read(sensor.s1) > black {	// over white floor
		motor.off(motor.ab)
		time.sleep_ms(100)
		if sensor.read_us(sensor.s2) < can_near {
			motor.off(motor.ab)
			motor.write(motor.c, 50)	// pick the can
			time.sleep_ms(1000)
			motor.off(motor.c)

			motor.write(motor.ab, 60)
			for sensor.read(sensor.s1) > black {} 	// wait for the black line

			motor.off(motor.ab)
			motor.write(motor.c, -50)	// release the can
			time.sleep_ms(1000)
			motor.off(motor.c)
		}
	} else {
		motor.off(motor.ab)
		motor.write(motor.ab, -60)	// reverse
		time.sleep_ms(1000)
		motor.write(motor.a, 60)	// spin
		time.sleep_ms(1000)
		motor.write(motor.b, 60)	// forward
		time.sleep_ms(100)
	}
}