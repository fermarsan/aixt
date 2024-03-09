import motor
import sensor

const threshold = 40

sensor.set_sound(i2)

for {
	for sensor(s2) <= threshold {}
	motor.forward(ac, 75)
	sleep_ms(300)
	for sensor(s2) <= threshold {}
	motor.off(ac)
	sleep_ms(300)
}