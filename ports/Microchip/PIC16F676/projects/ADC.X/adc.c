// PIC16F676 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA3/MCLR pin function select (RA3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000
#include "..\..\api\machine\adc.c"

unsigned int adc_result;

void main(void) {
    
    TRISC = 0b000000;
    PORTC = 0b000000;
    
    adc_setup();
    
    while(1){
                
        adc_result = adc_read(0);
        
        if ( adc_result >= 1020 ){
            
            PORTC = 0b111111;        
        }
        
        else if ( adc_result >= 820 ){
            
            PORTC = 0b011111;        
        }
        
        else if ( adc_result >= 620 ){
            
            PORTC = 0b001111;        
        }
        
        else if ( adc_result >= 420 ){
            
            PORTC = 0b000111;        
        }
        
        else if ( adc_result >= 220 ){
            
            PORTC = 0b000011;        
        }
        
        else if ( adc_result >= 120 ){
            
            PORTC = 0b000001;        
        }
        
        else {
            
            PORTC = 0b000000;        
        }
    
    }
}
