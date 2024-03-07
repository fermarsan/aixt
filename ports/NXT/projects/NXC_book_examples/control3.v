import sys
import motor
import sensor

// const threshold = 40
// #define		threshold	40

sensor.set_light(in_3)
motor.forward(ac, 75)

for {
	if sensor(in_3) > 40 {//threshold {
		motor.reverse(c, 75)
		sleep_ms(100)
		for sensor(in_3) > 40 {}//threshold) {}
		motor.forward(ac, 75)
	} 
}