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
    uart_Start();
    pwm0_Start();
    pwm1_Start();
    pwm2_Start();
    pwm3_Start();
    clock0_Start();
    clock1_Start();
    clock2_Start();
    clock3_Start();
    adc_Start();
    amux_Start();
    
    
    for(;;)
    {
        
    }
}

/* [] END OF FILE */
