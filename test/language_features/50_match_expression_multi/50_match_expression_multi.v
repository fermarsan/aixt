import uart

a := 1

match a {
	2, 4, 8 {
		uart.print('2')
	}
	3, 6 {
		uart.println('3')
	}
	else {
		uart.println('another')
	}
}