
// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F88x port)
module pwm1

// Función para configurar el PWM
@[as_macro]
fn setup(channel u8, freq u8, mode u8) {
    C.PR2 = 199
    C.CCPR2L = 0  
    C.TRISCbits.TRISC1 = 0
    C.T2CON = 0b00000011  
    C.CCP2CON = 0b00001100  
    C.TMR2 = 0  
    C.T2CONbits.TMR2ON = 1             
} 




/*
@[inline]
pub fn setup(pin1, pin2) {
	C.\
}
    PR2 = 0x3E;                        /* Valor del período del PWM */ \
    CCPR##pin1##L = 0;                 /* Inicializa el registro CCP en 0 dependiendo el CCP que configure el usuario*/ \
    TRISCbits.TRISC##pin2 = 0;         /* Configura el Pin correspondiente como salida dependiendo el pin que configure el usuario */ \
    T2CON = 0b00000011;                /* Configuración del Timer 2 */ \
    CCP##pin1##CON = 0b00001100;       /* Configura el registro CCP en modo PWM dependiendo el CCP que configure el usuario*/ \
    TMR2 = 0;                          /* Inicializa el Timer 2 en 0 */ \
    T2CONbits.TMR2ON = 1;              /* Enciende el Timer 2 */
*/