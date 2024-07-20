mut a := 10.1
mut b, c := 20.0, 30

// b = c + a

a = if b > c { b } else { c }

if a > c { 
	b = a 
} else { 
	a = c 
}