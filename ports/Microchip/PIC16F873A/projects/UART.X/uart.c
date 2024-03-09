


// Projects for the PIC16F873A

#include "../../api/builtin.c.v"
#include "../../api/adc/adc.c.v"
#include "../../api/adc/setup.c.v"
#include "../../api/adc/read.c.v"
#include "../../api/adc/reading.c.v"
#include "../../api/uart/uart.c.v"
#include "../../api/uart/setup.c.v"
#include "../../api/uart/read.c.v"
#include "../../api/uart/print.c.v"
#include "../../api/uart/input.c.v"
#include "../../api/time/sleep_ms.c.v"


unsigned int adc;     // Variable para almacenar el valor del ADC
char caracteres[];  // Variable para alamacenar la cadena de caracteres que se va imprimir

void main(void) {
    
    adc__setup();
    uart__setup();
    
    while(1){
        
        adc__read(0);
              
        adc = adc__reading();
         
        sprintf(caracteres, "ADC CH0: %u\r\n", adc); // Almacena la cadena de caracteres en la variable caracteres
        print(caracteres);
        time__sleep_ms(200);
    
    }
    
    
}
