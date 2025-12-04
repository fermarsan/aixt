#include "project.h"

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    for(;;)
    {
        led1_Write(0);
        CyDelay(2000);/* Place your application code here. */
        led1_Write(1);
        CyDelay(2000);
        
    }
    }