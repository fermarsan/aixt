// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000
#include <xc.h>

#include "../../api/builtin.c"
#include "../../api/machine/adc.c"
#include "../../api/machine/pin.c"

unsigned int adc_result;  // Variable para almacenar el valor del ADC

void main(void) {
    
    while (1)
    {
        pin_setup(c0_s,0);
        pin_setup(c1_s,0);
        pin_setup(c2_s,0);
        pin_setup(c3_s,0);
        pin_setup(c4_s,0);
        pin_setup(c5_s,0);
        pin_setup(c6_s,0);
        pin_setup(c7_s,0);
        
        pin_write(c0,0);
        pin_write(c1,0);
        pin_write(c2,0);
        pin_write(c3,0);
        pin_write(c4,0);
        pin_write(c5,0);
        pin_write(c6,0);
        pin_write(c7,0);
        
        adc_setup();
        
        while(1){
        
        adc_read(2);   // Lee el canal con el cual se va a trabajar 
        
        adc_result = adc_reading();  // Almacena el valor del ADC
        
        if ( adc_result >= 1020 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_high(c5);
            pin_high(c6); 
            pin_high(c7); 
        }
        
        else if ( adc_result >= 875 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_high(c5);
            pin_high(c6); 
            pin_low(c7);       
        }
        
        else if ( adc_result >= 730 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_high(c5);
            pin_low(c6); 
            pin_low(c7);     
        }
        
        else if ( adc_result >= 585 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);       
        }
        
        else if ( adc_result >= 440 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_low(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);      
        }
        
        else if ( adc_result >= 295 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);        
        }
        
        else if ( adc_result >= 150 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);       
        }
        
        else if ( adc_result >= 20 ){
            
            pin_high(c0);
            pin_low(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);       
        }
   
        else {
            
            pin_low(c0);
            pin_low(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);
            pin_low(c6); 
            pin_low(c7);       
        }
    }
        
    }
    
    
}
