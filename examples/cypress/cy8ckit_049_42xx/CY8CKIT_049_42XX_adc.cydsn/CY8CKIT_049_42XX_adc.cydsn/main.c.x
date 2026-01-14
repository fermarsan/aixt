#include "project.h"
#include <stdio.h>

#define VDDA_mV 5000  // Tensión de referencia del ADC en mV

int main(void)
{
    CyGlobalIntEnable;

    adc_Start();           // Inicia ADC
    
    uart_Start();          // Inicia UART
    amux_Start();          // Inicia el multiplexor analógico

    for(;;)
    {
        amux_FastSelect(0);   // Selecciona canal 0 (único canal usado)
        CyDelay(5);           // Breve estabilización
        adc_StartConvert();    // Comienza conversiones continuas

        if (adc_IsEndConversion(adc_RETURN_STATUS))
        {
            uint16 adcResult = adc_GetResult16(0);                    // Lee ADC
            uint32 mV = ((uint32)adcResult * VDDA_mV) / 4095;        // Convierte a milivoltios

            char buffer[32];
            sprintf(buffer, "Voltaje cana 0: %lu mV\r\n", mV);
            uart_UartPutString(buffer);

            CyDelay(500); // Espera medio segundo
        }
    }
}