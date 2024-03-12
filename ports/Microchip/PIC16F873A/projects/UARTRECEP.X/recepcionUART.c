

// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"
#include "../../api_c/machine/uart.c"

char datos;

void main(void) {
    
    ADCON1bits.PCFG = 0;   // Declara todos los pines como digitales 
    
    pin_setup(b0,out);
    pin_setup(b1,out);
    
    pin_write(b0,0);
    pin_write(b1,0);
    
    uart_setup();

    while(1){
        
        if(uart_input ()> 0){
                       
            datos = uart_read();
        
        }
        
        switch (datos){
            
            case 'a':
                
                pin_high(b0);
                print("led1: Encendido\r\n");
                break;  
                
            case 'b':
                
                pin_low(b0);
                print("led1: Apagado\r\n");
                break;
                
            case 'q':
                
                pin_high(b1);
                print("led2: Encendido\r\n");
                break;  
                
            case 'w':
                
                pin_low(b1);
                print("led2: Apagado\r\n");
                break;
        }
    
    }
}
