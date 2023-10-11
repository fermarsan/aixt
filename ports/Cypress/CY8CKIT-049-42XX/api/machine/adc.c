// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
//              (CY8CKIT-049-42XX)

void adc_read(int channel) {
    if (channel==1){
        amux_FastSelect(0);
    }
    else if (channel==2){
        amux_FastSelect(1);
    }
    else if (channel==3){
        amux_FastSelect(2);
    }
    else if (channel==4){
        amux_FastSelect(3);
    }
    //uint16 conv;
    adc_StartConvert();
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    uint16 conv=adc_GetResult16(0);
    adc_StopConvert();
    
    //Codigo de prueba
        if (conv>30000) {led1_Write(1);
        }
        else
        {led1_Write(0);
        }
}