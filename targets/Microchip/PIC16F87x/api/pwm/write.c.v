// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pwm management functions
//              (PIC16F87x port)

module pwm

// Función para el ciclo de trabajo
pub fn write(duty u16) {
    pwm := ((duty - 0) * (60 - 0) / (256 - 0) + 0) 
    C.CCPR2L = (pwm >> 2)  
}



/*
// Función para el ciclo de trabajo
@[inline]
pub fn write(duty, pin) {
	C.\
}
    { \
        unsigned int pwm \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0) /* Calculando el ciclo de trabajo */ \
        CCPR2L = (pwm >> 2) /* Alamacena el valor del PWM */ \   
    }
*/