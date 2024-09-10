// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pwm1

// Función para el ciclo de trabajo
fn write(duty u16) {
        pwm := ((duty - 0) * (60 - 0) / (256 - 0) + 0) 
        CCPR2L = (pwm >> 2)  
}





/*
#define pwm__write(duty, pin) \
    { \
        unsigned int pwm; \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0); /* Calculando el ciclo de trabajo */ \
        CCPR##pin##L = (pwm >> 2); /* Alamacena el valor del PWM */ \   
    }
*/