
// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F886 port)
module pwm1

// Función para configurar el PWM
fn setup(channel u8, freq u8, mode u8) 
{
    PR2 = 199;
    CCPR2L = 0;  
    TRISCbits.TRISC1 = 0;
    T2CON = 0b00000011;  
    CCP2CON = 0b00001100;  
    TMR2 = 0;  
    T2CONbits.TMR2ON = 1;             
} 




/*
@[inline]
pub fn pwm.setup(pin1, pin2) {
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