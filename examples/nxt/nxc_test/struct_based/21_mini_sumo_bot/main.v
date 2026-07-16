// Project name:
// Author:
//
// _Date:_
// NXT Intelligent Brick

import time
import motor
import sensor { Sensor }

const threshold = 40

fn main() {

	mut light_s := Sensor.new(sensor.s3)
	light_s.as_light(true)

	time.sleep_ms(2)	// starting pause

	for {
		motor_bc.write(50)
		time.sleep_ms(2)
		motor_ab.off()
	}
}

fn escape() {
	motor_b.write(100)
	motor_c.write(-100)
	time.sleep_ms(500)
	motor_bc.write(100)
	time.sleep_ms(500)
}

fn navigate() {
	for {
		motor_bc.write(70)
		for light_s.read() < threshold {
			time.sleep_ms(100)
		}
		motor_bc.off()
		time.sleep_ms(500)
		motor_bc.write(-75)
		time.sleep_ms(500)
		escape()
	}
}