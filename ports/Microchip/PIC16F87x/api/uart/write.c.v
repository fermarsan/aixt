// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F87x port)

module uart

@[inline]
pub fn write(data u8){
    C.TXREG=data
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