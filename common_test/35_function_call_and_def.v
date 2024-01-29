// function calling before defining

fn main() {
	a, b, c := i8(4), i8(7), i8(0) 

	c = average_8b(a, a+b)
}

fn average_8b(x i8, y i8) i8 {
	n := 2
	return i8((x + y) / n)
}