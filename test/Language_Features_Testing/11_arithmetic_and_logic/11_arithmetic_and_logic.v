// arithmetic and logical operations

fn main() {
	a := 5
	mut counter := i16(1)
	mut delta := i16(1)

	counter = 10
	counter = counter + delta / 2
	counter = delta * 4 - 35
	delta = counter % 3
	delta = counter * (delta + 2)

	mut state := i8(0)
	condition := i8(0xAA)

	state = state & condition
	state = ~state | condition
	state = state ^ ~condition
	state = state << 6
	state = (condition & state) >> 2

	mut logic1 := true
	mut logic2 := false

	logic1 = (logic1 && logic2)
	logic2 = (logic1 || logic2)
}
