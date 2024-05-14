// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH573F)

module uart


fn setup() {
	UART0_DefInit();
    UART0_ByteTrigCfg(UART_7BYTE_TRIG);
    UART0_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT);
    PFIC_EnableIRQ(UART0_IRQn);
}
//#define port__setup_(PORT, BITS, MODE) GPIO##PORT##_ModeCfg(BITS, MODE)

//#define port__setup(PORT, BITS, MODE)  port__setup_(PORT, BITS, MODE)

	