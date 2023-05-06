// array declaration and using

a := [1,3,4,5,7]		// regular array
b := [3]f32				// empty array
c := [5]rune{init: `x`}	// array initialized with the same value
x, i := 0, 2

a[0] = 25
b[i] = 10.5
x = a[3]
c[2] = `y`