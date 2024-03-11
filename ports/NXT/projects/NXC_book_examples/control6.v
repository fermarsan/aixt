import motor
import sensor

const near = 15

sensor.set_lowspeed(i4)

for {
	motor.forward(ac, 50)
	for sensor.read_us(i4) > near {}
	motor.off(ac)
	motor.reverse(c, 100)
	sleep_ms(800)
}