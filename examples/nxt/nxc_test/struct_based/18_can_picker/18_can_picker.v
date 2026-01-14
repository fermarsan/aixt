import motor { Motor }
import sensor { Sensor }
import time { sleep_ms }
import rand

const black		=  40
const can_near	=  8

mut line_sensor := Sensor.new(sensor.s1)
line_sensor.as_light(true)

mut echo_sensor := Sensor.new(sensor.s2)
echo_sensor.as_ultrasonic()

mut left := Motor.new(motor.a)
mut right := Motor.new(motor.b)
mut both_sides := Motor.new(motor.ab)
mut gripper := Motor.new(motor.c)

sleep_ms(1000)
both_sides.write(60)

for {
	if line_sensor.read() > black {	// over white floor
		both_sides.write(60)
		sleep_ms(100)
		if echo_sensor.read_us() <= can_near {
			both_sides.off()
			gripper.write(50)	// pick the can
			sleep_ms(600)
			gripper.off()
			both_sides.write(60)
			for sensor.read(sensor.s1) > black {} 	// wait for the black line
			both_sides.off()
			gripper.write(-50)	// release the can
			sleep_ms(500)
			gripper.off()
		}
	} else {
		both_sides.off()
		sleep_ms(500)
		both_sides.write(-60)	// reverse
		sleep_ms(850)
		left.write(60)	// spin
		sleep_ms(400 + rand.random(500))
		right.write(60)	// forward
		sleep_ms(100)
	}
}
