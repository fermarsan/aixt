
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
#define XTAL_FREQ 8000000

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/machine/uart.c"

char datos;

void main(void) {
    
    ADCON1bits.PCFG = 0;   // Declara todos los pines como digitales 
    
    pin_setup(b0_s,out);
    pin_setup(b1_s,out);
    
    pin_write(b0,0);
    pin_write(b1,0);
    
    uart_setup();

    while(1){
        
        if(uart_input ()> 0){
                       
            datos = uart_read();
        
        }
        
        switch (datos){
            
            case 'a':
                
                pin_high(b0);
                print("led1: Encendido\r\n");
                break;  
                
            case 'b':
                
                pin_low(b0);
                print("led1: Apagado\r\n");
                break;
                
            case 'q':
                
                pin_high(b1);
                print("led1: Encendido\r\n");
                break;  
                
            case 'w':
                
                pin_low(b1);
                print("led1: Apagado\r\n");
                break;
        }
    
    }
}
