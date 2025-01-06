// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: IRQ3 functions (WCH-CH573F)

module irq

#define	irq__uart3_rx_enable()	UART3_ByteTrigCfg(UART_7BYTE_TRIG);  UART3_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT);  PFIC_EnableIRQ(UART3_IRQn)
#define irq_uart3_rx(FN_NAME)	void isr_uart3_rx(void)

fn C.global_isr()