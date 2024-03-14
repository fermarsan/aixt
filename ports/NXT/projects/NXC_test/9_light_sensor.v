// move forward until the light sensor overpass a limit

const limit = 40

sensor.set_light(i1)
motor.forward(ab, 60)

for {
	if sensor(in_1) > limit {
		motor.off(ab)
	}
}
