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
 
            
    for(;;)
    {
        //led1_Write(0);
        //CyDelay(500);/* Place your application code here. */
        //led1_Write(1);
        //CyDelay(500);

        pwm1_WriteCompare(10000);
        CyDelay(2000);
    
       pwm1_WriteCompare(5000);
        CyDelay(2000);
   
        pwm1_WriteCompare(00);
        CyDelay(2000);
        
      
        
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
