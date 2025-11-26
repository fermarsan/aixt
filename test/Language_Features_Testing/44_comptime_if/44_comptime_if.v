import uart

$if Emulator ?{
	uart.println('Aixt on Linux (Emulator target)')
} $else {
	uart.println('Aixt on Windows')
}

msg := $if flag_1 ? {
	'Custom flag'
} $else {
	'Not custom flag'
}

uart.println(msg)