import port
import time {sleep_ms}

port.setup(port.a, pin.0x00000800, port.output)
port.setup(port.b, pin.0xFFFFFFFF, port.output)
for{
	port.write(port.a,0x00000800)
	time.sleep_ms(1000)
	port.write(port.b,0x00000800)
	time.sleep_ms(1000)
}
