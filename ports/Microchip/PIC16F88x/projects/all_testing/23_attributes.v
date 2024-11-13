// function attributes

@['static inline']
fn average(xx int, yy int) int {
	return (xx + yy) / 2
}

aa, bb, cc := 23, 67, 0

cc = average(aa, bb)