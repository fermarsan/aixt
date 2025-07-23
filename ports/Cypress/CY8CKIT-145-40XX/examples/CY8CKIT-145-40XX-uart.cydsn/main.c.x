#include "project.h"

int main(void)
{
    CyGlobalIntEnable;
    uart_Start();
    uart_UartPutString("\r\n");

    for(;;)
    {
        uart_UartPutString("Enviando por UART...\r\n");
        CyDelay(1000);
    }
}