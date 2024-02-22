import uart
import adc

uart.setup(1, 9600)
uart.setup(2, 19200)

adc.read(1)
adc.read(5)



