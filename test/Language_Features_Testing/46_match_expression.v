import uart

a := 1

match a {
	2 {
		uart.print('2')
	}
	3 {
		uart.println('3')
	}
	else {
		uart.println('another')
	}
}