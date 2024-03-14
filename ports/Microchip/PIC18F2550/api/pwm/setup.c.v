// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC18F2550 port)

module pwm 

fn setup() { 
    PR2 = 0x0C                   // Valor del período del PWM 
    CCPR1L = 0                   // Inicializa el registro CCP en 0 dependiendo el CCP que configure el usuario
    TRISCbits.TRISC2 = 0         // Configura el Pin correspondiente como salida dependiendo el pin que configure el usuario 
    T2CON = 0x03                 // Configuración del Timer 2
    CCP1CON = 0x0C               // Configura el registro CCP en modo PWM dependiendo el CCP que configure el usuario
    TMR2 = 0                     // Inicializa el Timer 2 en 0 
    T2CONbits.TMR2ON = 1         // Enciende el Timer 2 
}