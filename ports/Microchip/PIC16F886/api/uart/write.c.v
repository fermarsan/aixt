// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart print.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F886 port)

module uart

fn write(data u8){
    TXREG=data
}





/*
#define print(menssage)      \
    {                         \
        char caracter; \
        for (int i = 0; (caracter = (menssage)[i]); ++i) { /* Revisa que no haya un caracter nulo y lo va almacenando */ \ 
            while (!TXIF);  /* Pausa la ejecución del programa hasta que el UART este listo */ \
            TXREG = caracter; \
        }                       \
    }   
*/
