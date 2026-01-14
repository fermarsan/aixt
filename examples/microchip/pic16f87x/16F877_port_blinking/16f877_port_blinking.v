// Project name: Port echo
// Author: Fernando M. Santa
// Date: 2024-2025
// Blinking PORTB
// PIC16F877 fosc = 20Mhz
import port
import time

port.setup(port.b, 0b00000000)

for{
	port.write(port.b,0b01010101)
	time.sleep_ms(500)
	port.write(port.b,0b10101010)
	time.sleep_ms(500)
}
