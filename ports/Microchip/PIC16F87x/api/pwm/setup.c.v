// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pwm management functions
//              (PIC16F87x port)

module pwm

// Función para configurar el PWM
@[inline]
pub fn setup() {
    C.PR2 = 0x3E
    C.CCPR2L = 0  
    C.TRISCbits.TRISC1 = 0
    C.T2CON = 0b00000011  
    C.CCP2CON = 0b00001100  
    C.TMR2 = 0  
    C.T2CONbits.TMR2ON = 1             
} 
  



/*
// Función para configurar el PWM
@[inline]
pub fn setup(pin1, pin2) {
	C.\
}
    PR2 = 0x3E                        /* Valor del período del PWM */ \
    CCPR2L = 0                 /* Inicializa el registro CCP en 0 dependiendo el CCP que configure el usuario*/ \
    TRISCbits.TRISC1 = 0         /* Configura el Pin correspondiente como salida dependiendo el pin que configure el usuario */ \
    T2CON = 0b00000011                /* Configuración del Timer 2 */ \
    CCP2CON = 0b00001100       /* Configura el registro CCP en modo PWM dependiendo el CCP que configure el usuario*/ \
    TMR2 = 0                          /* Inicializa el Timer 2 en 0 */ \
    T2CONbits.TMR2ON = 1              /* Enciende el Timer 2 */
*/