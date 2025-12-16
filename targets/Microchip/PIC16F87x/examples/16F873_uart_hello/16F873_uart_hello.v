import pin
import uart
import time

pin.setup(pin.c6, pin.output) // RC6 = TX

uart.setup(115200) // Initialize serial communication to 115200 bps

for {
	uart.print('Hello ')
	uart.println('world...!')
	time.sleep_ms(500)
}
