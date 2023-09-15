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

//#define STEP_SIZE (capsense_LINEARSLIDER_X_RESOLUTION/capsense_LINEARSLIDER_NUM_SENSORS)

//void PWM0(void),PWM1(void),PWM2(void);
//void CAPSENSE0(void),CAPSENSE1(void);

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    uart_Start();    /* Configuracion General*/
    pwm0_Start();
    pwm1_Start();
    pwm2_Start();
    clock_Start();
    capsense_Start();
    capsense_InitializeAllBaselines();
    capsense_ScanAllWidgets();
      
    //PWM0();
    //PWM1();
    //PWM2();
    
    for(;;)
    {
        //CAPSENSE0();
      
        // Codigo del usuario
               
        //CAPSENSE1();
    }
}

void PWM0()
    {
        uint16 ciclo_util0=20;    //Definicion por el usuario ciclo util en [%]
        pwm0_WriteCompare(65535-ciclo_util0*655);
    }

void PWM1()
    {
        uint16 ciclo_util1=40;    //Definicion por el usuario ciclo util en [%]
        pwm1_WriteCompare(65535-ciclo_util1*655);
    }
    
void PWM2()
    {
        uint16 ciclo_util2=60;    //Definicion por el usuario ciclo util en [%]
        pwm2_WriteCompare(65535-ciclo_util2*655);
    }
    
void CAPSENSE0()
    {
        for(;;)
        {
            if (!capsense_IsBusy())
            {capsense_ProcessAllWidgets();
            break;}
        }
    }
    
void CAPSENSE1()
    {
        capsense_UpdateAllBaselines();
        capsense_ScanAllWidgets();
    }

/* [] END OF FILE */
