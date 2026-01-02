// constants definition
const pi = 3.141592			// block of constants
const e  = f32(2.718281)

const r = 1.76
const msg = 'message 1'

const list = [1, 3, 7, 21]

@[as_macro] const repetitions = 10		// constant as C macro

mut x := 0.0

for _ in 0..repetitions {
	x += (e*r) + (pi/2)
}