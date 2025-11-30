// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F88x port)
module pwm

// PWM channels
@[as_macro] pub const ch1	= 1
@[as_macro] pub const ch2	= 2


// PWM frecuency
// PWM1 frequencies (fosc=20Mhz)
@[as_macro] pub const f_6250hz_20mhz	1
@[as_macro] pub const f_1562hz_20mhz	2

// PWM1 frequencies (fosc=16Mhz)
@[as_macro] pub const f_20khz_16mhz		0
@[as_macro] pub const f_5khz_16mhz		1
@[as_macro] pub const f_1250hz_16mhz	2

// PWM1 frequencies (fosc=12Mhz)
@[as_macro] pub const f_15khz_12mhz		0
@[as_macro] pub const f_3125hz_12mhz	1
@[as_macro] pub const f_781hz_12mhz		2

// PWM1 frequencies (fosc=10Mhz)
@[as_macro] pub const f_12500hz_10mhz	0
@[as_macro] pub const f_3125hz_10mhz	1
@[as_macro] pub const f_781hz_10mhz		2

// PWM1 frequencies (fosc=8Mhz)
@[as_macro] pub const f_10khz_8mhz		0
@[as_macro] pub const f_2500hz_8mhz		1
@[as_macro] pub const f_625hz_8mhz		2

// PWM1 frequencies (fosc=4Mhz)
@[as_macro] pub const f_5khz_4mhz		0
@[as_macro] pub const f_1250hz_4mhz		1
@[as_macro] pub const f_312hz_4mhz		2


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

// Función para el ciclo de trabajo
@[as_macro]
fn write(duty u16) {
    pwm := ((duty - 0) * (60 - 0) / (256 - 0) + 0) 
    C.CCPR2L = (pwm >> 2)  
}

/*
@[inline]
pub fn write(duty, pin) {
	C.\
}
    { \
        unsigned int pwm; \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0); /* Calculando el ciclo de trabajo */ \
        CCPR##pin##L = (pwm >> 2); /* Alamacena el valor del PWM */ \   
    }
*/