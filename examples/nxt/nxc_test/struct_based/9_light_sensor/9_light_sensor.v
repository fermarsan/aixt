// move forward until the light sensor overpass a limit
import motor
import sensor { Sensor }
import time


const limit = 40

mut light_s := Sensor.new(sensor.s1)
light_s.setup(sensor.light, true)
motor_ab.write(60)

for {
	if light_s.read() > limit {
		motor_ab.off()
	}
}