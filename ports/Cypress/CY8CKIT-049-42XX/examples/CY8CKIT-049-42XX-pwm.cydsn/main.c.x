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
    pwm0_Start();
    clock_Start();
    adc_Start();
    amux_Start();
    
        
    for(;;)
    {
         pwm0_WriteCompare(10000);
        CyDelay(2000);
    
       pwm0_WriteCompare(5000);
        CyDelay(2000);
   
        pwm0_WriteCompare(00);
        CyDelay(2000);//sleep_ms(300);
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
