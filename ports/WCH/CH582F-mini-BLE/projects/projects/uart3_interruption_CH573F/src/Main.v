import uart3
import irq

__global input = ` ` 

@[irq_uart3_rx]
fn uart3_eco(){
	input = uart3.read()	// read byte
	uart3.write(u8(input)+1)		// re-transmit it
}

uart3.setup(115200)

irq.uart3_rx_enable()

for{}