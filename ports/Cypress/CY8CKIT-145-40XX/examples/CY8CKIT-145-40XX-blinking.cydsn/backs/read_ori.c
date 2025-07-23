#include "project.h"

int main(void)
{
    CyGlobalIntEnable; // Habilita interrupciones globales

    for(;;)
    {
        // Lee el estado del botón
        uint8_t boton = sw2_Read();

        // Si el botón está presionado (normalmente 0)
        if(boton == 1)
        {
            // Enciende el LED
            led1_Write(1);
        }
        else
        {
            // Apaga el LED
            led1_Write(0);
        }
    }
}