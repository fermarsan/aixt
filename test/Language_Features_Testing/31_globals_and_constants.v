// example for testing constant and global fields at the same time

__global (
	ga = 10
	gb i8
	gc = 3.4
	gd = f64(4.6)
	ge = 'message'
)

const (
	ca = 10
	cb = i8(25)
	cc = 3.4
	cd = f64(4.6)
	ce = 'message'
)

println('ce')