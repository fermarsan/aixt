// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: IRQ functions (WCH-CH573F)

module irq

// irq_uart_rx
#define	irq__uart_rx_enable()	UART0_ByteTrigCfg(UART_7BYTE_TRIG);  UART0_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT);  PFIC_EnableIRQ(UART0_IRQn)
#define irq_uart_rx(FN_NAME)	void isr_uart_rx(void)

fn C.global_isr()