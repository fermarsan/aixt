// arithmetic and logical operations

fn main() {
	a := 5
	counter := i16(1)
	delta := i16(1)

	counter = 10
	counter = counter + delta / 2
	counter = delta * 4 - 35
	delta = counter % 3
	delta = counter * (delta + 2)

	state := i8(0)
	condition := i8(0xAA)

	state = state & condition
	state = ~state | condition
	state = state ^ ~condition
	state = state << 6
	state = (condition & state) >> 2

	logic1 := true
	logic2 := false

	logic1 = (logic1 && logic2)
	logic2 = (logic1 || logic2)
}
