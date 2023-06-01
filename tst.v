a, b := 3, 6.7
c := 4.6
if a > b {
	a = 0
	c += 5
	if a > 10 {
		b, c = 14_398, 5
	} 
	else {
		a = 2
	}
}