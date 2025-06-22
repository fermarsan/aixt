// Project name: UART TX
// Author: Fernando M. Santa
// Date: 2025
// PIC16F628A fosc = 20Mhz
import pin
import uart
import time

pin.setup(pin.b2, pin.output) // RB2 = TX

uart.setup(115200) // Initialize serial communication to 115200 bps

for {
	for i in 0 .. 10 {
		uart.write(u8(i) + 48) // numbers as characters
	}
	uart.write(`\n`) // new line
	time.sleep_ms(500)
}
