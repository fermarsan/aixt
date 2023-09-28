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

void pin_high(void),pin_low(void),pin_write(void);

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
    
    pin_high();
    pin_low();
    pin_write();
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

void pin_high()
{
    int __pin_name;
    __pin_name=1;
    
    switch(__pin_name) {
    case 1: led1_Write(1);
    break;
    case 2: ;
    break;
    case 3: do0_Write(1);
    break;
    case 4: do1_Write(1);
    break;
    case 5: do2_Write(1);
    break;
    case 6: do3_Write(1);
    break;
    case 7: do4_Write(1);
    break;
    case 8: do5_Write(1);
    break;
    case 9: do6_Write(1);
    break;
    case 10: do7_Write(1);
    break;
    case 11: do8_Write(1);
    break;
    case 12: do9_Write(1);
    break;
    case 13: do10_Write(1);
    break;
    }   
}

void pin_low()
{
    int __pin_name;
    __pin_name=3;
    
    switch(__pin_name) {
    case 1: led1_Write(0);
    break;
    case 2: ;
    break;
    case 3: do0_Write(0);
    break;
    case 4: do1_Write(0);
    break;
    case 5: do2_Write(0);
    break;
    case 6: do3_Write(0);
    break;
    case 7: do4_Write(0);
    break;
    case 8: do5_Write(0);
    break;
    case 9: do6_Write(0);
    break;
    case 10: do7_Write(0);
    break;
    case 11: do8_Write(0);
    break;
    case 12: do9_Write(0);
    break;
    case 13: do10_Write(0);
    break;
    }
}

void pin_write()
{
    int __pin_name, __value;
    __pin_name=4;
    __value=1;
    
    switch(__pin_name) {
    case 1: led1_Write(__value);
    break;
    case 2: ;
    break;
    case 3: do0_Write(__value);
    break;
    case 4: do1_Write(__value);
    break;
    case 5: do2_Write(__value);
    break;
    case 6: do3_Write(__value);
    break;
    case 7: do4_Write(__value);
    break;
    case 8: do5_Write(__value);
    break;
    case 9: do6_Write(__value);
    break;
    case 10: do7_Write(__value);
    break;
    case 11: do8_Write(__value);
    break;
    case 12: do9_Write(__value);
    break;
    case 13: do10_Write(__value);
    break;
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
