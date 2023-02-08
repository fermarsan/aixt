[inline] 
fn forward_AB(power int, time int) {
	on_fwd(out_ab, power)
	wait(time)
}


[task] fn main() {
	a := 3
	a += 36
	forward_AB(75,1000)
}

