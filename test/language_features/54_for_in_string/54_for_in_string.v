import uart

str := 'Hello strings'

for ch in str {
	uart.println('${ch}')
}
