//adc leer voltaje potenciometro con capsense_ADC

#include "project.h"
#include <stdio.h>

int main(void)
{
    CyGlobalIntEnable;

    capsense_ADC_Start();  // Inicia el ADC
    uart_Start();          // Inicia UART

    for(;;)
    {
        // Leer canal 0
        uint16 valorADC = capsense_ADC_AdcReadResult_mVolts(0); // Valor de 0 a 4095 (12-bit)
        
        // Convertir a texto
        char buffer[32];
        sprintf(buffer, "Voltage (mV): %u\r\n", valorADC);

        // Enviar por UART
        uart_UartPutString(buffer);

        // Espera
        CyDelay(500);
    }
}




//Prender leds con capsenses y sliders con funcion capsense_ADC



//#include "project.h"
//
//int main(void)
//{
//    CyGlobalIntEnable;
//
//    // Iniciar CapSense_ADC
//    capsense_ADC_Start();
//
//    // Iniciar escaneo del primer ciclo
//    capsense_ADC_ScanAllWidgets();
//
//    for(;;)
//    {
//        // Esperar a que termine el escaneo
//        if (!capsense_ADC_IsBusy())
//        {
//            // Procesar widgets
//            capsense_ADC_ProcessAllWidgets();
//
//            // Verificar si el botón está activo
//            if (capsense_ADC_IsWidgetActive(capsense_ADC_BTN2_WDGT_ID))
//            {
//                led11_Write(1);  // Enciende LED
//            }
//            else
//            {
//                led11_Write(0);  // Apaga LED
//            }
//            
//            //PARA EL CAPSENSE BTN1
//            if (capsense_ADC_IsWidgetActive(capsense_ADC_BTN1_WDGT_ID))
//            {
//                led10_Write(1);  // Enciende LED
//            }
//            else
//            {
//                led10_Write(0);  // Apaga LED
//            }
//            
//            
//            //PARA EL CAPSENSE BTN0
//            if (capsense_ADC_IsWidgetActive(capsense_ADC_BTN0_WDGT_ID))
//            {
//                led9_Write(1);  // Enciende LED
//            }
//            else
//            {
//                led9_Write(0);  // Apaga LED
//            }
//            
//            //PARA LOS SLIDERS
//            
//            if (capsense_ADC_IsWidgetActive(capsense_ADC_LINEARSLIDER0_WDGT_ID))
//            {
//                led4_Write(1);  // Enciende LED
//            }
//            else
//            {
//                led4_Write(0);  // Apaga LED
//            }
//            
//           
//            
//
//            // Iniciar nuevo escaneo
//            capsense_ADC_ScanAllWidgets();
//        }
//    }
//}
//