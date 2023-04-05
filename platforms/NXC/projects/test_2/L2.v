set_sensor_touch(in_1)

a := 0
for {
	on_forward(out_ab, 30)
	sleep(1000)
	
	a = sensor(s1)
	if a == 0 {
		off(out_ab)
		sleep(500)
	}
}
