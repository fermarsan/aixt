
// Projects for adc the PIC16F676

#include "../../api/builtin.c.v"
#include "../../api/adc/adc.c.v"
#include "../../api/adc/setup.c.v"
#include "../../api/adc/read.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/read.c.v"
#include "../../api/pin/write.c.v"

unsigned int adc_result;

void main(void) {
    
    pin__setup(c0, out);
    pin__setup(c1, out);
    pin__setup(c2, out);
    pin__setup(c3, out);
    pin__setup(c4, out);
    pin__setup(c5, out);
    
    pin__write(c0, 0);
    pin__write(c1, 0);
    pin__write(c2, 0);
    pin__write(c3, 0);
    pin__write(c4, 0);
    pin__write(c5, 0);
    
    adc__setup();
    
    while(1){
                
        adc_result = adc__read(2);
        
        if ( adc_result >= 1020 ){
            
            pin__high(c0);
            pin__high(c1);
            pin__high(c2);
            pin__high(c3);
            pin__high(c4);
            pin__high(c5);            
        }
        
        else if ( adc_result >= 820 ){
            
            pin__high(c0);
            pin__high(c1);
            pin__high(c2);
            pin__high(c3);
            pin__high(c4);
            pin__low(c5);       
        }
        
        else if ( adc_result >= 620 ){
            
            pin__high(c0);
            pin__high(c1);
            pin__high(c2);
            pin__high(c3);
            pin__low(c4);
            pin__low(c5);     
        }
        
        else if ( adc_result >= 420 ){
            
            pin__high(c0);
            pin__high(c1);
            pin__high(c2);
            pin__low(c3);
            pin__low(c4);
            pin__low(c5);       
        }
        
        else if ( adc_result >= 220 ){
            
            pin__high(c0);
            pin__high(c1);
            pin__low(c2);
            pin__low(c3);
            pin__low(c4);
            pin__low(c5);      
        }
        
        else if ( adc_result >= 120 ){
            
            pin__high(c0);
            pin__low(c1);
            pin__low(c2);
            pin__low(c3);
            pin__low(c4);
            pin__low(c5);        
        }
        
        else {
            
            pin__low(c0);
            pin__low(c1);
            pin__low(c2);
            pin__low(c3);
            pin__low(c4);
            pin__low(c5);       
        }
    
    }
}

