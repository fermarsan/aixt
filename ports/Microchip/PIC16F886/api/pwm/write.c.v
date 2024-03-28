// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm write.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pwm

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