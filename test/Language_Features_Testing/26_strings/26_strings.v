import uart

mut msg1 := 'red'
mut msg2 := 'green'
msg3 := 'blue'

msg1 = msg3
uart.println(msg1)

msg2 += ' '
msg2 += msg3
uart.println(msg2)

msg2 = msg1 + msg3
uart.println(msg2)

if msg1 == msg2 {
	uart.println('true')
} else {
	uart.println('false')
}

msg2 += ' ' + msg3
uart.println(msg2)

if msg3 == 'blue' {
	uart.println('true')
} else {
	uart.println('false')
}
