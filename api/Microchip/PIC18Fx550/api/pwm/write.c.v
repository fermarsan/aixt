// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// PWM management functions (PIC18F2550 port)

module pwm 

fn write(duty int) { 
        pwm := ((duty - 0) * (50 - 0) / (1023 - 0) + 0)  // Calculando el ciclo de trabajo
        CCPR1L = pwm >> 2                                // Alamacena el valor del PWM     
    }