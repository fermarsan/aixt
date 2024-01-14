// PIC16F873A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000

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
