// constants definition and using

const (
	pi = 3.141592			// block of constants
	e  = f32(2.718281)
)

const repetitions = 10		// single constant
const r = 1.76

x := 0.0

for i in 0..repetitions {
	x += (e*r) + (pi/2)
}