
fn spin(left_m i16, right_m i16, power i16) {
	on_forward(left_m, power)
	on_reverse(right_m, power)
}

spin(out_a, out_b, 75)
sleep(1000)
off(out_ab)