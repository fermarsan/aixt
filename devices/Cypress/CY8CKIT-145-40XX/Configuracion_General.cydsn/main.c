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
#include "capsense.h"

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    uart_Start();    /* Configuracion General*/
    pwm1_Start();
    clock1_Start();
    pwm2_Start();
    clock2_Start();
    pwm3_Start();
    clock3_Start();
    capsense_Start();
    capsense_InitializeAllBaselines();
    capsense_ScanAllWidgets();
    
    for(;;)
    {
        led1_Write(0);
        CyDelay(300);
        led1_Write(1);
        CyDelay(300);    
    }
}

/* [] END OF FILE */
