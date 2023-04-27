// move forward until the light sensor overpass a limit

const limit = 40

set_sensor_light(in_1);
on_forward(out_ab, 60)

for {
	if sensor(in_1) > limit {
		off(out_ab)
	}
}
