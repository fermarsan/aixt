import time
import port

port.setup(port.d, port.all_outputs)

for {
	for i in 0..255 {
		port.write(port.d, u8(i))
		time.sleep_ms(10)
	}
}