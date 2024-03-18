// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PWM SETUP
//              (PIC18F452)
module pwm
fn setup() {
    PR2 = 0x0C                             /* Valor del periodo */  
    CCPR1L = 0                             /* Inicia el CCP1 en 0 */  
    TRISCbits.TRISC2 = 0                   /* Pin C2 como salida */  
    T2CON = 0x03                           /* Configuracion del timer 2 */  
    CCP1CON = 0x0C                         /* Configura el CCP1 en modo PWM */ 
    TMR2 = 0                               /* Timer 2 en 0 */  
    T2CONbits.TMR2ON = 1                   /* Timer 2 ON */
}                           
