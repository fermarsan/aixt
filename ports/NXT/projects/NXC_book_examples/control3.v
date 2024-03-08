import motor
import sensor

const threshold = 40

sensor.set_light(i3)
motor.forward(ac, 75)

for {
	if sensor.read(i3) > threshold {
		motor.reverse(c, 75)
		sleep_ms(100)
		for sensor.read(i3) > threshold {}
		motor.forward(ac, 75)
	} 
}