// function definition and calling

// average_8b computes que average value between 2-bit signed integers
fn average_8b(x i8, y i8) i8 {
	n := i8(2)
	return i8((x + y) / n)
}

d:= average_8b(5, 78)