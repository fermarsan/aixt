// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

#define uart_setup() \
    SPBRG = 51; /* 51 para 9600 baudios */ \  
    TXSTAbits.SYNC = 0; /* Modo asíncrono*/ \
    TXSTAbits.BRGH = 1; /* Baja velocidad de baudios*/ \
    RCSTAbits.SPEN = 1; /* Habilitar la UART*/ \
    TXSTAbits.TXEN = 1; /* Habilitar transmisor*/ \
    RCSTAbits.CREN = 1; /* Habilitar receptor*/ 


#define print(menssage)      \
    {                         \
        char caracter; \
        for (int i = 0; (caracter = (menssage)[i]); ++i) { /* Revisa que no haya un caracter nulo y lo va almacenando */ \ 
            while (!TXIF);  /* Pausa la ejecución del programa hasta que el UART este listo */ \
            TXREG = caracter; \
        }                       \
    }