// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC18F2550 port)

module pwm 

fn write(duty int) { 
        pwm := ((duty - 0) * (50 - 0) / (1023 - 0) + 0)  // Calculando el ciclo de trabajo
        CCPR1L = pwm >> 2                                // Alamacena el valor del PWM     
    }