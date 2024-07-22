import uart

$if on_linux {
	uart.println('Aixt on Linux')
} $else {
	uart.println('Aixt on Windows')
}
