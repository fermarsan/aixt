// function definition and calling

// average_8b computes que average value between 2-bit signed integers
fn average_8b(x i8, y i8) i8 {
	n := 2
	return i8((x + y) / n)
}

a, b, c := i8(4), i8(7), i8(0) 

c = average_8b(a, a+b)