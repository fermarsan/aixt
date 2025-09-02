import motor_fn as motor
import sensor_fn as sensor
import time { sleep_ms }
import rand

const black		=  40
const can_near	=  8

sensor.as_light(sensor.s1, true)
sensor.as_ultrasonic(sensor.s2)

sleep_ms(1000)
motor_ab.write(60)

for {
	if sensor.read(sensor.s1) > black {	// over white floor
		motor_ab.write(60)
		sleep_ms(100)
		if sensor.read_us(sensor.s2) <= can_near {
			motor_ab.off()
			motor_c.write(50)	// pick the can
			sleep_ms(600)
			motor_c.off()
			motor_ab.write(60)
			for sensor.read(sensor.s1) > black {} 	// wait for the black line
			motor_ab.off()
			motor_c.write(-50)	// release the can
			sleep_ms(500)
			motor_c.off()
		}
	} else {
		motor_ab.off()
		sleep_ms(500)
		motor_ab.write(-60)	// reverse
		sleep_ms(850)
		motor_a.write(60)	// spin
		sleep_ms(400 + rand.random(500))
		motor_b.write(60)	// forward
		sleep_ms(100)
	}
}
