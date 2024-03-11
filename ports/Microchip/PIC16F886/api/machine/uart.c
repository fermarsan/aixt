// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F886 port)

#define uart_setup() \
    SPBRG = 51; /* 51 para 9600 baudios */ \  
    TXSTAbits.SYNC = 0; /* Modo asíncrono*/ \
    TXSTAbits.BRGH = 1; /* Baja velocidad de baudios*/ \
    RCSTAbits.SPEN = 1; /* Habilitar la UART*/ \
    TXSTAbits.TXEN = 1; /* Habilitar transmisor*/ \
    RCSTAbits.CREN = 1; /* Habilitar receptor*/ \
    TXSTAbits.TX9 = 0;    // 8 BITS


#define print(menssage)      \
    {                         \
        char caracter; \
        for (int i = 0; (caracter = (menssage)[i]); ++i) { /* Revisa que no haya un caracter nulo y lo va almacenando */ \ 
            while (!TXIF);  /* Pausa la ejecución del programa hasta que el UART este listo */ \
            TXREG = caracter; \
        }                       \
    }


#define uart_input() (PIR1bits.RCIF ? 1 : 0)  // Valida si hay datos recibidos retorna un 1 si no hay datos recibidos un 0


char uart_read()     // Almacena los datos recibidos que envia el otro dispositivo
{
    while(PIR1bits.RCIF == 0);  // Pregunta si hay datos recibidos  
    if(RCSTAbits.OERR == 1)     // Verifica que no haya errores de desbordamiento
    {
        RCSTAbits.CREN = 0;     // Deshabilita la recepcion
        RCSTAbits.CREN = 1;     // Habilita la recepcion 
    }
    PIR1bits.RCIF = 0;    // Reinicia para que no hayan errores
    return RCREG;         // Retorna los caracteres recibidos 
}
    