import port
import uart
import pin 

port.setup(b, 0b00000000)
port.write(b, 0b00000000)
pin.setup(c7, pin.input)

uart.setup()

for {
	port.read(b) = uart.read()
}