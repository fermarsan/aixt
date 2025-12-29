///* ========================================
// *
// * Copyright YOUR COMPANY, THE YEAR
// * All Rights Reserved
// * UNPUBLISHED, LICENSED SOFTWARE.
// *
// * CONFIDENTIAL AND PROPRIETARY INFORMATION
// * WHICH IS THE PROPERTY OF your company.
// *
// * ========================================
//*/
//#include "project.h"
//#include <stdio.h>
//
//
//
//int main(void)
//{
//    CyGlobalIntEnable; /* Enable global interrupts. */
//    uart_Start();
//    pwm1_Start();
//    pwm2_Start();
//    pwm3_Start();
//    pwm4_Start();
//    clock_Start();
//    adc_Start();
//    amux_Start();
//    
//    uart_UartPutString("UART inicialiada\n\r");
//        
//    for(;;)
//    {
//        if (uart_SpiUartGetRxBufferSize() > 0)
//        {
//            char c = uart_UartGetChar(); // Leer un carácter
//            uart_UartPutChar(c); // Eco: reenviar el mismo carácter
//        }
//    }//sleep_ms(300);
//        //pin_low(led1);
//        //sleep_ms(300);
//        
//        //pwm_duty(4, 10);
//        //sleep_ms(2000);
//        //pwm_duty(4, 20);
//        //sleep_ms(2000);
//        //pwm_duty(4, 30);
//        //sleep_ms(2000);
//        //pwm_duty(4, 40);
//        //sleep_ms(2000);
//        //pwm_duty(4, 50);
//        //sleep_ms(2000);
//        //pwm_duty(4, 60);
//        //sleep_ms(2000);
//        //pwm_duty(4, 70);
//        //sleep_ms(2000);
//        //pwm_duty(4, 80);
//        //sleep_ms(2000);
//        //pwm_duty(4, 90);
//        //sleep_ms(2000);
//        //pwm_duty(4, 100);
//        //sleep_ms(2000);
//        
//        //adc_read(1);  
//    
//}
//
//
///* [] END OF FILE */
#include "project.h"

int main(void)
{
    CyGlobalIntEnable;
    uart_Start();
    uart_UartPutString ("\r\n");

    for(;;)
    {
        uart_UartPutString("Enviando por UART...\r\n");
        CyDelay(1000);
    }
}