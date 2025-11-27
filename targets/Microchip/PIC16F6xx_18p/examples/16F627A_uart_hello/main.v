// Project name: Hello world by UART
// Author: Fernando M. Santa
// Date: 2025
// PIC16F627A fosc = 20Mhz

import pin
import uart
import time

pin.setup(pin.b2, pin.output) // RB2 = TX

uart.setup(115200) // Initialize serial communication to 115200 bps

for {
	uart.print('Hello ')
	uart.println('world...!')
	time.sleep_ms(500)
}
