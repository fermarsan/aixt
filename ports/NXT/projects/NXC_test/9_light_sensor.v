// move forward until the light sensor overpass a limit

const limit = 40

set_sensor_light(in_1);
forward(motors_ab, 60)

for {
	if sensor(in_1) > limit {
		off(motors_ab)
	}
}
