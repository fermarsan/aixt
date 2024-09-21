// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//	- Javier Leon
//	- Camilo Lucas
//	- Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
//              (CY8CKIT-145-40XX)

void input() {
    char str1=UART_UartGetChar();
}

void print(char mensaje[]){
    UART_UartPutString(mensaje);
}

void println(char mensaje[]){
    UART_UartPutString(mensaje);
    UART_UartPutString("\n\r");
}
