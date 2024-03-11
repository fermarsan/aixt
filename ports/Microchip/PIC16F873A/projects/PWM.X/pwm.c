

// Projects for the PIC16F873A

#include "../../api_c/builtin.c"
#include "../../api_c/machine/adc.c"
#include "../../api_c/machine/pwm.c"


unsigned int adc;  // Variable necesaria para almacenar el valor del ADC

void main(void) {
    
    adc_setup();    // Inicia el ADC y lo configura
    pwm_setup(2,1); // Inicia el PWM y lo configura con CCP2 y el pin de salida RC1
    
    while(1){
    
        adc_read(2);  // Escoge el canal analogico AN2
        adc = adc_reading();  // Almacena el valor del ADC
        
        pwm_write(adc,2);  // Realiza el calculo del Duty y lo guarda en CCP2
        
    }
}
