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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    PWM_Start();
    
    for(;;)
    {
       PWM_WriteCompare(10000);
       CyDelay(1000);
    
     PWM_WriteCompare(8000);
       CyDelay(1000);
    
     PWM_WriteCompare(6000);
       CyDelay(1000);
    
     PWM_WriteCompare(4000);
       CyDelay(1000);
    
     PWM_WriteCompare(2000);
       CyDelay(1000);
   
  
       PWM_WriteCompare(0);
       CyDelay(1000);
       
       /* Place your application code here. */
    }
}

/* [] END OF FILE */
