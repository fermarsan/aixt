


// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/adc.c.v"
#include "../../api_c/machine/uart.c"
#include "../../api_c/time/sleep_ms.c"


unsigned int adc;     // Variable para almacenar el valor del ADC
char caracteres[];  // Variable para alamacenar la cadena de caracteres que se va imprimir

void main(void) {
    
    adc_setup();
    uart_setup();
    
    while(1){
        
        adc_read(0);
              
        adc = adc_reading();
         
        sprintf(caracteres, "ADC CH0: %u\r\n", adc); // Almacena la cadena de caracteres en la variable caracteres
        print(caracteres);
        sleep_ms(200);
    
    }
    
    
}
