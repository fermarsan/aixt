import uart

for _ in 0..5 {
	uart.print('Hello ')		// "Hello " to UART 0
	uart.println('world!')	// "world!" to UART 1
}