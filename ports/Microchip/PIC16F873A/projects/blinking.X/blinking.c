

// Porjects for the PIC16F83A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"
#include "../../api_c/time/sleep_ms.c"
#include "../../api_c/time/sleep_us.c"

void main(void) {
    
    ADCON1bits.PCFG = 0b00000110;  // Se defien todos los pines como I/O digitales
    
    pin__setup(b4, out);
    
    pin_write(b4, 0);
    
    while(1){
    
        pin_high(b4);
        sleep_ms(200);
        pin_low(b4);
        sleep_ms(200);
                               
    }
}
