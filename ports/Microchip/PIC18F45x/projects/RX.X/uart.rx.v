import port
import uart
import pin

port.setup(port.b, pin.port.output)
port.write(port.b, 0b00000000)
pin.setup(pin.c7, pin.input)

uart.setup()

for {
	port.read(port.b) = uart.read()
}