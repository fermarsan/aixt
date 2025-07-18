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
    pwm1_Start();
    pwm2_Start();
    pwm3_Start();
    pwm4_Start();
    clock_Start();
    adc_Start();
    amux_Start();
    
        
    for(;;)
    {
        led1_Write(0);
        CyDelay(5000);//pin_high(led1);
        led1_Write(1);
        CyDelay(5000);//sleep_ms(300);
        //pin_low(led1);
        //sleep_ms(300);
        
        //pwm_duty(4, 10);
        //sleep_ms(2000);
        //pwm_duty(4, 20);
        //sleep_ms(2000);
        //pwm_duty(4, 30);
        //sleep_ms(2000);
        //pwm_duty(4, 40);
        //sleep_ms(2000);
        //pwm_duty(4, 50);
        //sleep_ms(2000);
        //pwm_duty(4, 60);
        //sleep_ms(2000);
        //pwm_duty(4, 70);
        //sleep_ms(2000);
        //pwm_duty(4, 80);
        //sleep_ms(2000);
        //pwm_duty(4, 90);
        //sleep_ms(2000);
        //pwm_duty(4, 100);
        //sleep_ms(2000);
        
        //adc_read(1);  
    }
}


/* [] END OF FILE */
