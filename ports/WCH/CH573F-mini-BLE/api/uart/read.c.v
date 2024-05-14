// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH573F)

module uart

fn read() {
	__attribute__((interrupt("WCH-Interrupt-fast")))
	__attribute__((section(".highcode")))
	void UART0_IRQHandler(void){
		volatile uint8_t i;
		if(UART_II_RECV_TOUT)
				i = UART0_RecvString(RxBuff);
				UART0_SendString(RxBuff, i);
		}
}

