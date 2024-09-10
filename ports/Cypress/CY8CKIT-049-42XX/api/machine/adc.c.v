// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Javier Leon, Camilo Lucas and Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
//              (CY8CKIT-049-42XX)

void adc.read(int channel) {
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
    adc_StartConvert();
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    uint16 conv=adc_GetResult16(0);
    adc_StopConvert();
}
