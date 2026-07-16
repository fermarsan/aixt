// Project name: Mini Sumo Bot (nxtprograms.com)
// Author: Fernando Martínez Santa
//
// _Date:_2026
// NXT Intelligent Brick

import time
import motor_fn as motor
import sensor_fn as sensor
import rand

const threshold = 40

fn main() {

	sensor.as_light(sensor.s3, true)

	time.sleep_ms(2)	// starting pause

	for {
		algorithm := rand.random(4)
		match algorithm {
			1 { navigate() }
			2 { escape(); navigate() }
			3 {	aiki_move() }
			else { navigate() }
		}
	}
}

fn rand_time(ms int) int {
	return ms + rand.random(ms)
}

fn escape() {
	motor.write(motor.b, 100)
	motor.write(motor.c, -100)
	time.sleep_ms(rand_time(500))
	motor.write(motor.bc, 100)
	time.sleep_ms(rand_time(500))
}

fn navigate() {
	for {
		motor.write(motor.bc, 70)
		for sensor.read(sensor.s3) < threshold {
			time.sleep_ms(100)
		}
		motor.off(motor.bc)
		time.sleep_ms(rand_time(500))
		motor.write(motor.bc, -70)
		time.sleep_ms(rand_time(500))
		escape()
	}
}

fn aiki_move() {
	motor.write(motor.bc, 70)
	time.sleep_ms(1000)
	motor.write(motor.b, -20)
	motor.write(motor.c, -80)
	time.sleep_ms(1000)
	navigate()
}