
// Projects for adc the PIC16F676

#include "../../api_c/builtin.c"
#include "../../api_c/machine/adc.c"
#include "../../api_c/machine/pin.c"

unsigned int adc_result;

void main(void) {
    
    pin__setup(c0, out);
    pin__setup(c1, out);
    pin__setup(c2, out);
    pin__setup(c3, out);
    pin__setup(c4, out);
    pin__setup(c5, out);
    
    pin_write(c0, 0);
    pin_write(c1, 0);
    pin_write(c2, 0);
    pin_write(c3, 0);
    pin_write(c4, 0);
    pin_write(c5, 0);
    
    adc_setup();
    
    while(1){
                
        adc_result = adc_read(2);
        
        if ( adc_result >= 1020 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_high(c5);            
        }
        
        else if ( adc_result >= 820 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_high(c4);
            pin_low(c5);       
        }
        
        else if ( adc_result >= 620 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_high(c3);
            pin_low(c4);
            pin_low(c5);     
        }
        
        else if ( adc_result >= 420 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_high(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);       
        }
        
        else if ( adc_result >= 220 ){
            
            pin_high(c0);
            pin_high(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);      
        }
        
        else if ( adc_result >= 120 ){
            
            pin_high(c0);
            pin_low(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);        
        }
        
        else {
            
            pin_low(c0);
            pin_low(c1);
            pin_low(c2);
            pin_low(c3);
            pin_low(c4);
            pin_low(c5);       
        }
    
    }
}

