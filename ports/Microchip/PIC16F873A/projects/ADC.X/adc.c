

// Projects for the PIC16F873A

#include "../../api/builtin.c.v"
#include "../../api/adc/adc.c.v"
#include "../../api/adc/setup.c.v"
#include "../../api/adc/read.c.v"
#include "../../api/adc/reading.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/read.c.v"
#include "../../api/pin/write.c.v"

unsigned int adc_result;  // Variable para almacenar el valor del ADC

void main(void) {
        
    pin__setup(b0, out);
    pin__setup(b1, out);
    pin__setup(b2, out);
    pin__setup(b3, out);
    pin__setup(b4, out);
    pin__setup(b5, out);
    pin__setup(b6, out);
    pin__setup(b7, out);
    
    pin__write(b0, 0);
    pin__write(b1, 0);
    pin__write(b2, 0);
    pin__write(b3, 0);
    pin__write(b4, 0);
    pin__write(b5, 0);
    pin__write(b6, 0);
    pin__write(b7, 0);
    
    adc__setup();
    
    while(1){
        
        adc__read(2);   // Lee el canal con el cual se va a trabajar 
        
        adc_result = adc__reading();  // Almacena el valor del ADC
        
        if ( adc_result >= 1020 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__high(b3);
            pin__high(b4);
            pin__high(b5);
            pin__high(b6); 
            pin__high(b7); 
        }
        
        else if ( adc_result >= 875 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__high(b3);
            pin__high(b4);
            pin__high(b5);
            pin__high(b6); 
            pin__low(b7);       
        }
        
        else if ( adc_result >= 730 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__high(b3);
            pin__high(b4);
            pin__high(b5);
            pin__low(b6); 
            pin__low(b7);     
        }
        
        else if ( adc_result >= 585 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__high(b3);
            pin__high(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);       
        }
        
        else if ( adc_result >= 440 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__high(b3);
            pin__low(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);      
        }
        
        else if ( adc_result >= 295 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__high(b2);
            pin__low(b3);
            pin__low(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);        
        }
        
        else if ( adc_result >= 150 ){
            
            pin__high(b0);
            pin__high(b1);
            pin__low(b2);
            pin__low(b3);
            pin__low(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);       
        }
        
        else if ( adc_result >= 20 ){
            
            pin__high(b0);
            pin__low(b1);
            pin__low(b2);
            pin__low(b3);
            pin__low(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);       
        }
   
        else {
            
            pin__low(b0);
            pin__low(b1);
            pin__low(b2);
            pin__low(b3);
            pin__low(b4);
            pin__low(b5);
            pin__low(b6); 
            pin__low(b7);       
        }
    }
 
   
}
