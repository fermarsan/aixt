import uart

arr := [2,4,5,7,9]

if 5 in arr {
	uart.println('5 is in arr')
} else {
	uart.println('5 is not in arr')
}

if 9 !in arr {
	uart.println('9 is not in arr')
} else {
	uart.println('9 is in arr')
}