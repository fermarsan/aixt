// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
//              (CY8CKIT-049-42XX)

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
