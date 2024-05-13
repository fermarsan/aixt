import port
import time {sleep_ms}

port.setup(a, 0x00000800, port.output)
port.setup(b, 0xFFFFFFFF, port.output)
for{
	port.write(a,0x00000800)
	sleep_ms(1000)
	port.write(b,0x00000800)
	sleep_ms(1000)
}
