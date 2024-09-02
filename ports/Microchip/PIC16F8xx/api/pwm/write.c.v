// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
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
#define pwm__write(duty, pin) \
    { \
        unsigned int pwm \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0) /* Calculando el ciclo de trabajo */ \
        CCPR2L = (pwm >> 2) /* Alamacena el valor del PWM */ \   
    }
*/