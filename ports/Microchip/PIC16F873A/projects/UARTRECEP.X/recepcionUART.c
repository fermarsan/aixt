

// Projects for the PIC16F873A

#include "../../api/builtin.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/write.c.v"
#include "../../api/uart/input.c.v"
#include "../../api/uart/setup.c.v"
#include "../../api/uart/read.c.v"
#include "../../api/uart/print.c.v"


char datos;

void main(void) {
    
    ADCON1bits.PCFG = 0;   // Declara todos los pines como digitales 
    
    pin__setup(b0,out);
    pin__setup(b1,out);
    
    pin__write(b0,0);
    pin__write(b1,0);
    
    uart__setup();

    while(1){
        
        if(uart__input ()> 0){
                       
            datos = uart__read();
        
        }
        
        switch (datos){
            
            case 'a':
                
                pin__high(b0);
                print("led1: Encendido\r\n");
                break;  
                
            case 'b':
                
                pin__low(b0);
                print("led1: Apagado\r\n");
                break;
                
            case 'q':
                
                pin__high(b1);
                print("led2: Encendido\r\n");
                break;  
                
            case 'w':
                
                pin__low(b1);
                print("led2: Apagado\r\n");
                break;
        }
    
    }
}
