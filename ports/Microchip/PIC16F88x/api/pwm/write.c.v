// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F88x port)

module pwm1

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