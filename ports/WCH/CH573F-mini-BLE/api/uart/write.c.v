// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: UART functions (WCH-CH573F)

module uart

#define uart__write(TX) UART0_SendString(Tx, sizeof(Tx));

fn write() {
	//UART0_SendString(TxBuff, sizeof(TxBuff));
}
