import uart

$if linux && gcc_tcc ? {
	uart.println('Aixt on Linux (GCC)')
} $else {
	uart.println('Aixt on Windows (TCC)')
}

msg := $if flag_1 ? {
	'Custom flag'
} $else {
	'Not custom flag'
}

uart.println(msg)