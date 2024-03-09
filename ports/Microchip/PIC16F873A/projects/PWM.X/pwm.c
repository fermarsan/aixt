

// Projects for the PIC16F873A

#include "../../api/builtin.c.v"
#include "../../api/adc/adc.c.v"
#include "../../api/adc/setup.c.v"
#include "../../api/adc/read.c.v"
#include "../../api/adc/reading.c.v"
#include "../../api/pwm/pwm.c.v"
#include "../../api/pwm/setup.c.v"
#include "../../api/pwm/write.c.v"


unsigned int adc;  // Variable necesaria para almacenar el valor del ADC

void main(void) {
    
    adc__setup();    // Inicia el ADC y lo configura
    pwm__setup(2,1); // Inicia el PWM y lo configura con CCP2 y el pin de salida RC1
    
    while(1){
    
        adc__read(2);  // Escoge el canal analogico AN2
        adc = adc__reading();  // Almacena el valor del ADC
        
        pwm__write(adc,2);  // Realiza el calculo del Duty y lo guarda en CCP2
        
    }
}
