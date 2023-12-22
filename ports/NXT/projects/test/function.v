const (
	t1 = 1000
	t2 = 2000
)

[inline]
fn add(x i16, y i16) i16 {
	a := 10
	return x + y
}

forward(motors_ab, 50)
sleep(add(t1, t2))
off(motors_ab)
