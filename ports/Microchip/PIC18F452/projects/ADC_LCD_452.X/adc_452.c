#include "adc_452.h"

void ADC_Init(unsigned char p_ang)
{
    ADCON1 = p_ang;
    ADCON0 = 0x00;
}

unsigned int ADC_Read(unsigned char ch)
{
    if(ch > 7){
        return 0;
    }else{
        ADCON0 = 0x00;
        unsigned char sma = 24;
        unsigned char valor = sma + ch; 
        ADCON0 = (valor << 3);
        ADCON0bits.ADON = 1;
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE == 1);
        return ADRES;
    }
}