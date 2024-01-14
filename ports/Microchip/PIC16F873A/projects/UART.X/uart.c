// PIC16F873A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 8000000

#include "../../api/machine/adc.c"
#include "../../api/machine/uart.c"

unsigned int adc;     // Variable para almacenar el valor del ADC
char caracteres[];  // Variable para alamacenar la cadena de caracteres que se va imprimir

void main(void) {
    
    adc_setup();
    uart_setup();
    
    while(1){
        
        adc_read(0);
              
        adc = adc_reading();
         
        sprintf(caracteres, "ADC CH0: %u\r\n", adc); // Almacena la cadena de caracteres en la variable caracteres
        print(caracteres);
        __delay_ms(200);
    
    }
    
    
}
