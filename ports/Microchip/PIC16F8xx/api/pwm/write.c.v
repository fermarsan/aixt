// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pwm management functions
//              (PIC16F873A port)

module pwm

// Función para el ciclo de trabajo
fn write(duty u16) {
        pwm := ((duty - 0) * (60 - 0) / (256 - 0) + 0) 
        CCPR2L = (pwm >> 2)  
}



/*
// Función para el ciclo de trabajo
@[inline]
pub fn pwm.write(duty, pin) {
	C.\
}
    { \
        unsigned int pwm \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0) /* Calculando el ciclo de trabajo */ \
        CCPR2L = (pwm >> 2) /* Alamacena el valor del PWM */ \   
    }
*/