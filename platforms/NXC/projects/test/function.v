const (
	t1 = 1000
	t2 = 2000
)

fn add(x i16, y i16) i16 {
	a := 10
	return x + y
}

on_fwd(out_ab, 50)
wait(add(t1, t2))
off(out_ab)
