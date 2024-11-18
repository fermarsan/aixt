import uart

for _ in 0..5 {
	uart.print('Hello ')
	uart.println('world!')	// "Hello world!" to UART
}