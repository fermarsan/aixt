// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM WRITE
//              (PIC18F452)
module pwm
fn write(duty int)    
    { 
        pwm := ((duty - 0) * (50 - 0) / (1023 - 0) + 0) /* Calculando el ciclo de trabajo */ 
        CCPR1L = pwm >> 2 /* Almacena el valor del PWM */ 
    }