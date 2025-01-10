// array declaration and using

mut a := [1,3,4,5,6]!	// fixed size

a[0] = 2

mut b := 3

a[b] = 10

b = a[4]

// a = [3,5]

mut c := [10]u16{}	// fixed size
mut d := []u16{len: 10}
mut e := [5]u16{init: 0}	// fixed size
mut f := []int{len: 5, init: 1}
mut g := []int{len: 5, cap: 10, init: 2}