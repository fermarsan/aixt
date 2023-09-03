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
#include "CapSense.h"

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();    /* Configuracion General*/
    PWM1_Start();
    Clock1_Start();
    PWM2_Start();
    Clock2_Start();
    PWM3_Start();
    Clock3_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanAllWidgets();
    
    for(;;)
    {
          
    }
}

/* [] END OF FILE */
