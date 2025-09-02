import motor
import sensor
import time


const black = 40
const can_near = 8

sensor.as_light(sensor.s1, true)
sensor.as_ultrasonic(sensor.s2)


time.sleep(1)
motor_ab.write(60)

for {
	if sensor.read(sensor.s1) > black {	// over white floor
		motor_ab.off()
		time.sleep_ms(100)
		if sensor.read_us(sensor.s2) <= can_near {
			motor_ab.off()
			motor_c.write(50)	// pick the can
			time.sleep_ms(1000)
			motor_c.off()

			motor_ab.write(60)
			for sensor.read(sensor.s1) > black {} 	// wait for the black line

			motor_ab.off()
			motor_c.write(-50)	// release the can
			time.sleep_ms(1000)
			motor_c.off()
		}
	} else {
		motor_ab.off()
		motor_ab.write(-60)	// reverse
		time.sleep_ms(1000)
		motor_a.write(60)	// spin
		time.sleep_ms(1000)
		motor_b.write(60)	// forward
		time.sleep_ms(100)
	}
}
