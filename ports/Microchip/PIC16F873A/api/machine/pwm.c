// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

// Función para configurar el PWM
#define pwm_setup(set_value1, set_value2) \
    PR2 = 0x3E;                                /* Valor del período del PWM */ \
    CCPR##set_value1##L = 0;                   /* Inicializa el registro CCP en 0 dependiendo el CCP que configure el usuario*/ \
    TRISCbits.TRISC##set_value2 = 0;           /* Configura el Pin correspondiente como salida dependiendo el pin que configure el usuario */ \
    T2CON = 0b00000011;                        /* Configuración del Timer 2 */ \
    CCP##set_value1##CON = 0b00001100;         /* Configura el registro CCP en modo PWM dependiendo el CCP que configure el usuario*/ \
    TMR2 = 0;                                  /* Inicializa el Timer 2 en 0 */ \
    T2CONbits.TMR2ON = 1;                      /* Enciende el Timer 2 */

// Función para el ciclo de trabajo
#define pwm_write(duty, set_value1) \
    { \
        unsigned int pwm; \
        pwm = ((duty - 0) * (60 - 0) / (256 - 0) + 0); /* Calculando el ciclo de trabajo */ \
        CCPR##set_value1##L = (pwm >> 2); /* Alamacena el valor del PWM */ \   
    }