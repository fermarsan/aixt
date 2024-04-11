

// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"
#include "../../api_c/machine/adc.c"

unsigned int adc_result;  // Variable para almacenar el valor del ADC

void main(void) {
        
    pin_setup(c0, out);
    pin_setup(c1, out);
    pin_setup(c2, out);
    pin_setup(c3, out);
    pin_setup(c4, out);
    pin_setup(c5, out);
    pin_setup(c6, out);
    pin_setup(c7, out);
    
    pin_write(c0, 0);
    pin_write(c1, 0);
    pin_write(c2, 0);
    pin_write(c3, 0);
    pin_write(c4, 0);
    pin_write(c5, 0);
    pin_write(c6, 0);
    pin_write(c7, 0);
    
    adc_setup();
    
    while(1){
        
        //adc_read(2);   // Lee el canal con el cual se va a trabajar 
        
        adc_result = adc_read(2);  // Almacena el valor del ADC
        
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
