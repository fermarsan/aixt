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
#define _XTAL_FREQ 8000000

#include "../../api/builtin.c"
#include "../../api/machine/adc.c"
#include "../../api/machine/pin.c"

unsigned int adc_result;  // Variable para almacenar el valor del ADC

void main(void) {
        
    pin_setup(b0_s, out);
    pin_setup(b1_s, out);
    pin_setup(b2_s, out);
    pin_setup(b3_s, out);
    pin_setup(b4_s, out);
    pin_setup(b5_s, out);
    pin_setup(b6_s, out);
    pin_setup(b7_s, out);
    
    pin_write(b0, 0);
    pin_write(b1, 0);
    pin_write(b2, 0);
    pin_write(b3, 0);
    pin_write(b4, 0);
    pin_write(b5, 0);
    pin_write(b6, 0);
    pin_write(b7, 0);
    
    adc_setup();
    
    while(1){
        
        adc_read(2);   // Lee el canal con el cual se va a trabajar 
        
        adc_result = adc_reading();  // Almacena el valor del ADC
        
        if ( adc_result >= 1020 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_high(b3);
            pin_high(b4);
            pin_high(b5);
            pin_high(b6); 
            pin_high(b7); 
        }
        
        else if ( adc_result >= 875 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_high(b3);
            pin_high(b4);
            pin_high(b5);
            pin_high(b6); 
            pin_low(b7);       
        }
        
        else if ( adc_result >= 730 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_high(b3);
            pin_high(b4);
            pin_high(b5);
            pin_low(b6); 
            pin_low(b7);     
        }
        
        else if ( adc_result >= 585 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_high(b3);
            pin_high(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);       
        }
        
        else if ( adc_result >= 440 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_high(b3);
            pin_low(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);      
        }
        
        else if ( adc_result >= 295 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_high(b2);
            pin_low(b3);
            pin_low(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);        
        }
        
        else if ( adc_result >= 150 ){
            
            pin_high(b0);
            pin_high(b1);
            pin_low(b2);
            pin_low(b3);
            pin_low(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);       
        }
        
        else if ( adc_result >= 20 ){
            
            pin_high(b0);
            pin_low(b1);
            pin_low(b2);
            pin_low(b3);
            pin_low(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);       
        }
   
        else {
            
            pin_low(b0);
            pin_low(b1);
            pin_low(b2);
            pin_low(b3);
            pin_low(b4);
            pin_low(b5);
            pin_low(b6); 
            pin_low(b7);       
        }
    }
 
   
}
