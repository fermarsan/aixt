// function attributes

@[inline]
fn average(x int, y int) int {
	return (x + y) / 2
}

a, b, c := 23, 67, 0

c = average(a, b)