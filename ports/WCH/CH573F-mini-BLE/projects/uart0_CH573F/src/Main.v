import uart

input := ` `
uart.setup(115200)

for {
	if uart.any() {
		input = uart.read()	// read byte
		uart.write(u8(input)+1)		// re-transmit it
	}
}