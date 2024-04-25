#include <xc.h>

// Configuración del PIC
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & CP_OFF);

#define _XTAL_FREQ 20000000 // Frecuencia de cristal de 20MHz

void main() {
    TRISB = 0b00000000; // Configura todos los pines del puerto B como salidas

    while(1) {
        PORTB = 0b10000000; // Enciende el LED conectado al pin RB0
        __delay_ms(500); // Espera 500ms

        PORTB = 0b00000000; // Apaga el LED
        __delay_ms(500); // Espera 500ms
    }
}