import uart

$if linux {
	uart.println('Aixt on Linux')
} $else {
	uart.println('Aixt on Windows')
}

msg := $if flag_1 ? {
	'Custom flag'
} $else {
	'Not custom flag'
}

uart.println(msg)