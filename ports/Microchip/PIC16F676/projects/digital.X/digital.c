
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

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"

void main(void) {
    
    ANSEL = 0b00000000; // Todas los pin son I/O digitales
    
    pin_setup(c2_s, in);
    pin_setup(c4_s, in);
    pin_setup(c1_s, out);
    pin_setup(c0_s, out);
 
    pin_write(c0, 0);   // Inicia la salida C0 en cero
    pin_write(c1, 0);   // Inicia la salida C1 en cero
    
    
    
    
    while(1){
        
        if(c2 == 1){
            
            pin_high(c1);
            pin_high(c0);
        }
        
        else if(c4 == 1){
            
            pin_low(c1);
            pin_low(c0);
        }
    
    
    }
        
}