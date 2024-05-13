// move forward until the light sensor overpass a limit
import motor
import sensor

const limit = 40

sensor.set_light(i1)
motor.forward(ab, 60)

for {
	if sensor.read(i1) > limit {
		motor.off(ab)
	}
}
