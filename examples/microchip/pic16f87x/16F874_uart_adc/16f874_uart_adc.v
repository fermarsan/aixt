import uart
import time
import adc

uart.setup(115200) // Initialize serial communication to 115200 bps
adc.setup(adc.in0, adc.bits_10) // only one input and 10-bit resolution

for {
  analog := adc.read(adc.ch0) // conversion on channel 0
	uart.println('ADC channel 0: ${analog}') // new line
	time.sleep_ms(500)
}
