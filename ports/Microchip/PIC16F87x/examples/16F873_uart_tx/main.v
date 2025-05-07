import pin
import uart
import time

pin.setup(pin.c6, pin.output) // RC6 = TX

uart.setup(115200) // Initialize serial comunication to 115200 bps

for {
	uart.write(0x33)
	time.sleep_ms(500)
	uart.write(0x99)
	time.sleep_ms(500)
}
