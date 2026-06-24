// "if" and "if-else" statements 

mut a, mut b := 10, 1 
mut l := true

if a <= b {
    l = true
    a += 1
} 

if a > b {
    a = 0
    b = 0
} else {
    a = -1
	b--
}

if a < b {
	a++
} else if a > b {
	a--
} else {
	b++
}

if a < b {
	a++
} else if a > b {
	a--
}