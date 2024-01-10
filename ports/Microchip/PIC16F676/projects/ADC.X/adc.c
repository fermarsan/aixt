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
#include "../../api/builtin.c"
#include "../../api/machine/pin.c"

unsigned int adc_result;

void main(void) {
    
    pin_setup(c0_s, out);
    pin_setup(c1_s, out);
    pin_setup(c2_s, out);
    pin_setup(c3_s, out);
    pin_setup(c4_s, out);
    pin_setup(c5_s, out);
    
    pin_write(c0, 0);
    pin_write(c1, 0);
    pin_write(c2, 0);
    pin_write(c3, 0);
    pin_write(c4, 0);
    pin_write(c5, 0);
    
    adc_setup();
    
    while(1){
                
        adc_result = adc_read(0);
        
        if ( adc_result >= 1020 ){
            
            c0 = 1;
            c1 = 1;
            c2 = 1;
            c3 = 1;
            c4 = 1;
            c5 = 1;            
        }
        
        else if ( adc_result >= 820 ){
            
            c0 = 1;
            c1 = 1;
            c2 = 1;
            c3 = 1;
            c4 = 1;
            c5 = 0;        
        }
        
        else if ( adc_result >= 620 ){
            
            c0 = 1;
            c1 = 1;
            c2 = 1;
            c3 = 1;
            c4 = 0;
            c5 = 0;     
        }
        
        else if ( adc_result >= 420 ){
            
            c0 = 1;
            c1 = 1;
            c2 = 1;
            c3 = 0;
            c4 = 0;
            c5 = 0;       
        }
        
        else if ( adc_result >= 220 ){
            
            c0 = 1;
            c1 = 1;
            c2 = 0;
            c3 = 0;
            c4 = 0;
            c5 = 0;      
        }
        
        else if ( adc_result >= 120 ){
            
            c0 = 1;
            c1 = 0;
            c2 = 0;
            c3 = 0;
            c4 = 0;
            c5 = 0;        
        }
        
        else {
            
            c0 = 0;
            c1 = 0;
            c2 = 0;
            c3 = 0;
            c4 = 0;
            c5 = 0;       
        }
    
    }
}
