// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC18F2550 port)

module pwm 

fn write(duty int) { 
        pwm := ((duty - 0) * (50 - 0) / (1023 - 0) + 0)  // Calculando el ciclo de trabajo
        CCPR1L = pwm >> 2                                // Alamacena el valor del PWM     
    }