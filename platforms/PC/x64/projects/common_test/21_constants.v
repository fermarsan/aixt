// constants definition and using

const (
	pi = 3.141592			// block of constants
	e  = 2.718281
)

const repetitions = 10		// single constant

x := 0

for i in 0..repetitions {
	x += (e*e) + (pi/2)
}