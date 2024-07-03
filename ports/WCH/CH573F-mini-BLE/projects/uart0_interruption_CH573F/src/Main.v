import uart
import irq

__global input = ` `

@[irq_uart_rx]
fn uart_eco(){
	input = uart.read()	// read byte
	uart.write(u8(input)+1)		// re-transmit it
}

uart.setup(115200)

irq.uart_rx_enable()

for{}