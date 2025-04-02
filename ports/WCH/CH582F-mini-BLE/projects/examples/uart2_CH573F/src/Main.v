import uart1

input := ` ` 
uart1.setup(115200)

for {
	if uart1.any() {
		input = uart1.read()	// read byte
		uart1.write(u8(input)+1)		// re-transmit it
	}
}


