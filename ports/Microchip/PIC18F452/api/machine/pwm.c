// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC18F452 port)

// Función para configurar el PWM
#include <xc.h>
#define pwm_setup(pin1, pin2) \
    PR2 = 0x0C;                             /* Valor del periodo */  \
    CCPR##pin1##L = 0;                             /* Inicia el CCP1 en 0 */  \
    TRISCbits.TRISC##pin2## = 0;                   /* Pin C2 como salida */  \
    T2CON = 0x03;                           /* Configuracion del timer 2 */  \
    CCP##pin1##CON = 0x0C;                         /* Configura el CCP1 en modo PWM */ \
    TMR2 = 0;                               /* Timer 2 en 0 */  \
    T2CONbits.TMR2ON = 1                  /* Timer 2 ON */

// Función para el ciclo de trabajo
#define pwm_write(duty, pin) \      //PIN = PIN1 
    { \
        unsigned int pwm; \
        pwm = ((duty - 0) * (50 - 0) / (1023 - 0) + 0); /* Calculando el ciclo de trabajo */ \
        CCPR##pin##L = (pwm >> 2); /* Almacena el valor del PWM */ \   
    }