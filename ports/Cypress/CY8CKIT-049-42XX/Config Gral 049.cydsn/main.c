/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

//void PWM0(void),PWM1(void),PWM2(void),PWM3(void);
//void ADC0(void),ADC1(void),ADC2(void),ADC3(void);

uint16 valor3,conv3;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    uart_Start();
    pwm0_Start();
    pwm1_Start();
    pwm2_Start();
    pwm3_Start();
    clock_Start();
    adc_Start();
    amux_Start();
    
    //PWM0();
    //PWM1();
    //PWM2();
    //PWM3();
        
    for(;;)
    {
        //ADC0();
        //ADC1();
        //ADC2();
        //ADC3();  
    }
}

void PWM0()
    {
        uint16 ciclo_util0=20;    //Definicion por el usuario ciclo util en [%]
        pwm0_WriteCompare(ciclo_util0*655);
    }

void PWM1()
    {
        uint16 ciclo_util1=40;    //Definicion por el usuario ciclo util en [%]
        pwm1_WriteCompare(ciclo_util1*655);
    }
    
void PWM2()
    {
        uint16 ciclo_util2=60;    //Definicion por el usuario ciclo util en [%]
        pwm2_WriteCompare(ciclo_util2*655);
    }
    
void PWM3()
    {
        uint16 ciclo_util3=80;    //Definicion por el usuario ciclo util en [%]
        pwm3_WriteCompare(ciclo_util3*655);
    }
    
void ADC0()
    {
        uint16 conv0;
        amux_FastSelect(0);
        adc_StartConvert();
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        conv0=adc_GetResult16(0);
        adc_StopConvert();        
    }
    
void ADC1()
    {
        uint16 conv1;
        amux_FastSelect(1);
        adc_StartConvert();
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        conv1=adc_GetResult16(0);
        adc_StopConvert();
    }
    
void ADC2()
    {
        uint16 conv2;
        amux_FastSelect(2);
        adc_StartConvert();
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        conv2=adc_GetResult16(0);
        adc_StopConvert();      
    }
    
void ADC3()
    {           
        amux_FastSelect(3);
        adc_StartConvert();
        adc_IsEndConversion(adc_WAIT_FOR_RESULT);
        conv3=adc_GetResult16(0);
        adc_StopConvert();
        valor3=adc_CountsTo_mVolts(0,conv3);
        
        //Codigo de usuario
        if (valor3>2000) {led1_Write(1);
        }
        else
        {led1_Write(0);
        }
    }


/* [] END OF FILE */
