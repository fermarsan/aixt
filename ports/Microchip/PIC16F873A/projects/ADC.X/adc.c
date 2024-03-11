

// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_/machine/adc.c/"
#include "../../api/machine/pin.c"

unsigned int adc_result;  // Variable para almacenar el valor del ADC

void main(void) {
        
    pin_setup(b0, out);
    pin_setup(b1, out);
    pin_setup(b2, out);
    pin_setup(b3, out);
    pin_setup(b4, out);
    pin_setup(b5, out);
    pin_setup(b6, out);
    pin_setup(b7, out);
    
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
