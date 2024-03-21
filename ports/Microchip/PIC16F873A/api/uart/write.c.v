// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F873A port)

module uart

fn write(data u8){
    TXREG=data
}

/*
#define print(menssage)      \
    {                         \
        char caracter \
        for (int i = 0; (caracter = (menssage)[i]); ++i) { /* Revisa que no haya un caracter nulo y lo va almacenando */ \ 
            while (!TXIF)  /* Pausa la ejecución del programa hasta que el UART este listo */ \
            TXREG = caracter \
        }                       \
    }
*/