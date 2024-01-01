// Aixt supports any C preprocessor directive



import time { sleep }

// #include "xxx.c"

mut a := 0

for {
	sleep(1000)
	println(a)
	a++
}