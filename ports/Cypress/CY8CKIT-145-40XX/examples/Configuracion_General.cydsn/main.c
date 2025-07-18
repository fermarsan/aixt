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


#define STEP_SIZE (capsense_LINEARSLIDER_X_RESOLUTION/capsense_LINEARSLIDER_NUM_SENSORS)



int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    uart_Start();    /* Configuracion General*/
    pwm1_Start();
    pwm2_Start();
    pwm0_Start();
    clock_Start();
    capsense_Start();
    capsense_InitializeAllBaselines();
    capsense_ScanAllWidgets();
   
     //codigo para prender led(1.6) con capsense(BTN2)        
    for(;;)
    {
        if(!capsense_IsBusy())
        {
            capsense_ProcessAllWidgets();
            
            if(capsense_IsWidgetActive(capsense_BTN2_WDGT_ID))
            {
                led11_Write(0);  // Enciende el LED
            }
            else
            {
                led11_Write(1);  // Apaga el LED
            }

            capsense_ScanAllWidgets();
        }
    }
   // {
        
         // Lee el estado del pin del botón
        //if (sw2_Read() == 1)
        //{
            // Si está presionado (valor lógico 1), enciende el LED
          //  led1_Write(1);
        //}
       // else
        //{
            // Si no está presionado (valor lógico 0), apaga el LED
          //  led1_Write(0);
        //}
        
        
        
        
        //pin.high(led1);
        //sleep_ms(1000);
        //pin.low(led1);
        //sleep_ms(1000);
        
        //pwm_duty(1, 0);
        //sleep_ms(2000);
        //pwm_duty(1, 10);
        //sleep_ms(2000);
        //pwm_duty(1, 20);
        //sleep_ms(2000);
        //pwm_duty(1, 30);
        //sleep_ms(2000);
        //pwm_duty(1, 40);
        //sleep_ms(2000);
        //pwm_duty(1, 50);
        //sleep_ms(2000);
        //pwm_duty(1, 60);
        //sleep_ms(2000);
        //pwm_duty(1, 70);
        //sleep_ms(2000);
        //pwm_duty(1, 80);
        //sleep_ms(2000);
        //pwm_duty(1, 90);
        //sleep_ms(2000);
        //pwm_duty(1, 100);
        //sleep_ms(2000);
    }

    


/* [] END OF FILE */
