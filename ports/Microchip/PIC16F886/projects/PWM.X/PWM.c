
// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000
#include <xc.h>

#include "../../api/builtin.c"
#include "../../api/machine/adc.c"
#include "../../api/machine/pwm.c"

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
