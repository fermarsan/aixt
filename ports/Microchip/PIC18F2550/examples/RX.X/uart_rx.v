import port
import uart
import pin

port.setup(b, port.out)
port.write(b, 0b00000000)
pin.setup(c7, pin.in)

uart.setup()

for {
	val := rx.read()
	port.write (b, val)
}