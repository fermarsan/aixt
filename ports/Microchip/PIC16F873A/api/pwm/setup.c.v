// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pwm management functions
//              (PIC16F873A port)

module pwm

// Función para configurar el PWM
fn setup() {

    PR2 = 0x3E
    CCPR2L = 0  
    TRISCbits.TRISC1 = 0
    T2CON = 0b00000011  
    CCP2CON = 0b00001100  
    TMR2 = 0  
    T2CONbits.TMR2ON = 1             
} 
  



/*
// Función para configurar el PWM
#define pwm__setup(pin1, pin2) \
    PR2 = 0x3E                        /* Valor del período del PWM */ \
    CCPR2L = 0                 /* Inicializa el registro CCP en 0 dependiendo el CCP que configure el usuario*/ \
    TRISCbits.TRISC1 = 0         /* Configura el Pin correspondiente como salida dependiendo el pin que configure el usuario */ \
    T2CON = 0b00000011                /* Configuración del Timer 2 */ \
    CCP2CON = 0b00001100       /* Configura el registro CCP en modo PWM dependiendo el CCP que configure el usuario*/ \
    TMR2 = 0                          /* Inicializa el Timer 2 en 0 */ \
    T2CONbits.TMR2ON = 1              /* Enciende el Timer 2 */
*/