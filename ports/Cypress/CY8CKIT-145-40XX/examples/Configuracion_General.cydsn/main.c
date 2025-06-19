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
    pwm3_Start();
    clock_Start();
    capsense_Start();
    capsense_InitializeAllBaselines();
    capsense_ScanAllWidgets();
 
            
    for(;;)
    {
        
        pwm1_WriteCompare(10000);
       CyDelay(1000);
    
     pwm1_WriteCompare(8000);
       CyDelay(1000);
    
     pwm1_WriteCompare(6000);
       CyDelay(1000);
    
     pwm1_WriteCompare(4000);
       CyDelay(1000);
    
     pwm1_WriteCompare(2000);
       CyDelay(1000);
   
  
       pwm1_WriteCompare(0);
       CyDelay(2000);
     //pin.high(led1);
      // sleep_ms(1000);
       // pin.low(led1);
       // sleep_ms(1000);
        
       // pwm_duty(1, 0);
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
       // sleep_ms(2000);
        //pwm_duty(1, 90);
        //sleep_ms(2000);
        //pwm_duty(1, 100);
        //sleep_ms(2000);
    }
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
