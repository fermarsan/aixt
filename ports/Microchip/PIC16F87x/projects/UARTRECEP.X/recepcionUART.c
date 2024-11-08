

// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"
#include "../../api_c/machine/uart.c"

char datos;

void main(void) {
    
    ADCON1bits.PCFG = 0;   // Declara todos los pines como digitales 
    
    pin.setup(pin.b0,out);
    pin.setup(pin.b1,out);
    
    pin.write(pin.b0,0);
    pin.write(pin.b1,0);
    
    uart.setup();

    while(1){
        
        if(uart.input ()> 0){
                       
            datos = uart.read();
        
        }
        
        switch (datos){
            
            case 'a':
                
                pin.high(pin.b0);
                print("led1: Encendido\r\n");
                break;  
                
            case 'b':
                
                pin.low(pin.b0);
                print("led1: Apagado\r\n");
                break;
                
            case 'q':
                
                pin.high(pin.b1);
                print("led2: Encendido\r\n");
                break;  
                
            case 'w':
                
                pin.low(pin.b1);
                print("led2: Apagado\r\n");
                break;
        }
    
    }
}
